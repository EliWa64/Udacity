/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Hw_Regs.h"
#include "Port_Cfg.h"
#include "Dio.h"
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define GPIO_LOCK_KEY                           0x4C4F434B
#define MAX_NUMBER_OF_CHANNELS_IN_PORT          8
#define MAX_NUMBER_OF_GPIO_PORTS                8
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const uint32_t GpioApbBaseAddress[MAX_NUMBER_OF_GPIO_PORTS] = 
{
    GPIO_APB_BASE_ADDRESS_A,
    GPIO_APB_BASE_ADDRESS_B,
    GPIO_APB_BASE_ADDRESS_C,
    GPIO_APB_BASE_ADDRESS_D,
    GPIO_APB_BASE_ADDRESS_E,
    GPIO_APB_BASE_ADDRESS_F
};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void Port_Init(const Port_Config_st* p_config)
{
    uint32_t loc_baseAddr;
    uint8_t loc_pinId, loc_pinMode, loc_pinDir, loc_pinLevel, loc_pinInternalAttach, loc_pinOutputCurrent,
        loc_pinExtInt;
    uint8_t loc_bitNumber, loc_regNumber, i;

    for(i=0; i<MAX_NUMBER_OF_CONFIGS; i++)
    {
        loc_pinId = p_config[i].pinId;
        loc_pinMode = p_config[i].PinMode;
        loc_pinDir = p_config[i].pinDir;
        loc_pinLevel = p_config[i].pinLevel;
        loc_pinInternalAttach = p_config[i].pinInternalAttach;
        loc_pinOutputCurrent = p_config[i].pinOutputCurrent;
        loc_pinExtInt = p_config[i].pinExtInt;

        loc_regNumber = loc_pinId / MAX_NUMBER_OF_CHANNELS_IN_PORT;
        loc_bitNumber = loc_pinId % MAX_NUMBER_OF_CHANNELS_IN_PORT;
        loc_baseAddr = GpioApbBaseAddress[loc_regNumber];


        if(loc_pinDir == PORT_PIN_IN)
        {
            GPIOPDIR(loc_baseAddr) &= ~(1 << loc_bitNumber);
        } //if
        else if(loc_pinDir == PORT_PIN_OUT)
        {
            GPIOPDIR(loc_baseAddr) |= 1 << loc_bitNumber;
        } //else if

        /*Unlock the GPIOCR by writing the lock key "0x4C4F434B" to GPIOLOCK reg.*/
        GPIOLOCK(loc_baseAddr) = GPIO_LOCK_KEY;

        /*Commit the values in GPIOAFSEL, GPIOPUR, GPIOPDR, and GPIODEN by writing 0x1 to the corresponding bits.*/
        GPIOCR(loc_baseAddr) |= 1 << loc_bitNumber;
        

        if((loc_pinMode != PORT_PIN_MODE_X_ANALOG) && (loc_pinMode != PORT_PIN_MODE_X_DIO))
        {
            GPIOAFSEL(loc_baseAddr) |= 1 << loc_bitNumber;

            GPIOPCTRL(loc_baseAddr) |= loc_pinMode << (loc_bitNumber*4);
        } //if
        else
        {
            GPIOAFSEL(loc_baseAddr) &= ~(1 << loc_bitNumber);
        } //else


        /*Setting wanted current.*/
        if(loc_pinOutputCurrent == PORT_CURRENT_2_MILLIAMPERE)
        {
            GPIODR2R(loc_baseAddr) |= 1 << loc_bitNumber;
        } //if
        else if(loc_pinOutputCurrent == PORT_CURRENT_4_MILLIAMPERE)
        {
            GPIODR4R(loc_baseAddr) |= 1 << loc_bitNumber;
        } //else if
        else if(loc_pinOutputCurrent == PORT_CURRENT_8_MILLIAMPERE)
        {
            GPIODR8R(loc_baseAddr) |= 1 << loc_bitNumber;

            /*TODO: SLEW RATE if needed.*/
        } //else if


        if(loc_pinInternalAttach == PORT_ATTACH_INTERNAL_PULL_DOWN)
        {
            GPIOPDR(loc_baseAddr) |= 1 << loc_bitNumber;
        } //if
        else if(loc_pinInternalAttach == PORT_ATTACH_INTERNAL_PULL_UP)
        {
            GPIOPUR(loc_baseAddr) |= 1 << loc_bitNumber;
        } //else if
        else if(loc_pinInternalAttach == PORT_ATTACH_OPEN_DRAIN )
        {
            GPIOODR(loc_baseAddr) |= 1 << loc_bitNumber;
        } //else if
            

        if(loc_pinMode == PORT_PIN_MODE_X_ANALOG)
        {
            GPIOAMSEL(loc_baseAddr) |= 1 << loc_bitNumber;
        } //if
        else
        {
            GPIODEN(loc_baseAddr) |= 1 << loc_bitNumber;
        } //else

        //GPIOCR(loc_baseAddr) &= ~(1 << loc_bitNumber);

        /*Lock the GPIOCR by writing any value to GPIOLOCK reg.*/
        GPIOLOCK(loc_baseAddr) = 0;

        if(loc_pinLevel == PORT_PIN_LOW)
        {
            Dio_WriteChannel(loc_pinId, LOW);
        } //if
        else if(PORT_PIN_HIGH)
        {
            Dio_WriteChannel(loc_pinId, HIGH);
        } //else if

        /*Init External Interrupt*/
        if(loc_pinExtInt == PORT_EXT_INT_RISING_EDGE)
        {
            GPIOIM(loc_baseAddr) &= ~(1 << loc_bitNumber); //Mask the interrupt.
            GPIOIS(loc_baseAddr) &= ~(1 << loc_bitNumber); //Edge sensitive.
            GPIOIBE(loc_baseAddr) &= ~(1 << loc_bitNumber); //Clear both edges enable.
            GPIOIEV(loc_baseAddr) |= (1 << loc_bitNumber); //Set for Rising Edge.
            GPIOICR(loc_baseAddr) |= (1 << loc_bitNumber); //Clearing GPIORIS by writing '1' to GPIOICR.
            GPIOIM(loc_baseAddr) |= (1 << loc_bitNumber); //Unmask the interrupt.
        } //if
        else if(loc_pinExtInt == PORT_EXT_INT_FALLING_EDGE)
        {
            GPIOIM(loc_baseAddr) &= ~(1 << loc_bitNumber); //Mask the interrupt.
            GPIOIS(loc_baseAddr) &= ~(1 << loc_bitNumber); //Edge sensitive.
            GPIOIBE(loc_baseAddr) &= ~(1 << loc_bitNumber); //Clear both edges enable.
            GPIOIEV(loc_baseAddr) &= ~(1 << loc_bitNumber); //Clear for Falling Edge.
            GPIOICR(loc_baseAddr) |= (1 << loc_bitNumber); //Clearing GPIORIS by writing '1' to GPIOICR.
            GPIOIM(loc_baseAddr) |= (1 << loc_bitNumber); //Unmask the interrupt.
        } //else if
        else if(loc_pinExtInt == PORT_EXT_INT_BOTH_EDGES)
        {
            GPIOIM(loc_baseAddr) &= ~(1 << loc_bitNumber); //Mask the interrupt.
            GPIOIS(loc_baseAddr) &= ~(1 << loc_bitNumber); //Edge sensitive.
            GPIOIBE(loc_baseAddr) |= (1 << loc_bitNumber); //Set both edges enable.
            GPIOICR(loc_baseAddr) |= (1 << loc_bitNumber); //Clearing GPIORIS by writing '1' to GPIOICR.
            GPIOIM(loc_baseAddr) |= (1 << loc_bitNumber); //Unmask the interrupt.
        } //else if
        else if(loc_pinExtInt == PORT_EXT_INT_LOW_EVENT)
        {
            GPIOIM(loc_baseAddr) &= ~(1 << loc_bitNumber); //Mask the interrupt.
            GPIOIS(loc_baseAddr) |= (1 << loc_bitNumber); //Event sensitive.
            GPIOIEV(loc_baseAddr) &= ~(1 << loc_bitNumber); //Clear for Low Event.
            GPIOICR(loc_baseAddr) |= (1 << loc_bitNumber); //Clearing GPIORIS by writing '1' to GPIOICR.
            GPIOIM(loc_baseAddr) |= (1 << loc_bitNumber); //Unmask the interrupt.
        } //else if
        else if(loc_pinExtInt == PORT_EXT_INT_HIGH_EVENT)
        {
            GPIOIM(loc_baseAddr) &= ~(1 << loc_bitNumber); //Mask the interrupt.
            GPIOIS(loc_baseAddr) |= (1 << loc_bitNumber); //Event sensitive.
            GPIOIEV(loc_baseAddr) &= ~(1 << loc_bitNumber); //Set for High Event.
            GPIOICR(loc_baseAddr) |= (1 << loc_bitNumber); //Clearing GPIORIS by writing '1' to GPIOICR.
            GPIOIM(loc_baseAddr) |= (1 << loc_bitNumber); //Unmask the interrupt.

        } //else if
        else
        {
            GPIOIM(loc_baseAddr) &= ~(1 << loc_bitNumber); //Mask the interrupt.
        } //else
    } //for
} /*Port_Init*/
/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifndef TRUE
   #define TRUE            1u
#endif

#ifndef FALSE
   #define FALSE           0u
#endif

#define ENABLE             1u
#define DISABLE            0u

#define LOGIC_HIGH         1u
#define LOGIC_LOW          0u

#define NULL_PTR           ((void*)0)
#define NULL               0



typedef enum
{
	OK,
	NOK
}Std_ErrorState_et;



typedef unsigned char         boolean;

typedef signed char           sint8_t;
typedef unsigned char         uint8_t;
typedef signed short          sint16_t;
typedef unsigned short        uint16_t;
typedef signed long           sint32_t;
typedef unsigned long         uint32_t;

typedef float                 float32_t;
typedef double                float64_t;

#endif /* STD_TYPES_H */
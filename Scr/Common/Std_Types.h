#ifndef STD_TYPES_H
#define STD_TYPES_H

#define E_OK                0u
#define E_NOT_OK            1u

#ifndef TRUE
   #define TRUE             1u
#endif

#ifndef FALSE
   #define FALSE            0u
#endif

#define ENABLE              1u
#define DISABLE             0u




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
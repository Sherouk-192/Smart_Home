#ifndef BIT_MATH
#define BIT_MATH
#define SET_BIT(x,b)(x)|=(1<<(b))
#define CLR_BIT(x,b)(x) &=~(1<<(b))
#define TOGGLE_BIT(x,b)(x)^=(1<<(b))
#define GET_BIT(x,b)((x)>>(b)&1)
#endif 

#ifndef STD_LIB_C_STDARG
#define STD_LIB_C_STDARG

typedef unsigned int* va_list;

#define va_start(list,argbefore) list = (void*)&(argbefore)
#define va_arg(list,type) (*(type*)(++(list)))
#define va_end(list)

#endif
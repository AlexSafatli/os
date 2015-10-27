#ifndef _STDARG_H
#define _STDARG_H

typedef unsigned int* va_list;

#define va_start(list,argbefore) list = (void*)&(argbefore)
#define va_arg(list,type) (*(type*)(++(list)))
#define va_end(list)

#endif
#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

#include "linked_list.h"

extern int func(int, int); // Defined in func.s

linked_list generate_fibonacci(int count);

#endif /* __FIBONACCI_H__ */
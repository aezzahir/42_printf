#include <stdio.h>
#include "ft_printf.h"


int main()
{
    ft_printf("Hello, world! %s\n", "This is a test");
    ft_printf("A: Integer: %d, Unsigned: %u, Hex: %x\n", -42, 42, 42);
	printf("C: Integer: %d, Unsigned: %u, Hex: %x\n", -42, 42, 42);
    ft_printf("A: Pointer: %p\n", main);
	printf("C: Pointer: %p\n", main);
    ft_printf("A: Percent Sign: %%\n");
	printf("C: Percent Sign: %%\n");
    return 0;
}

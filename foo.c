#include <stdio.h>
#include <stdint.h>


typedef struct MyStruct
{
    uint8_t foo;
    uint8_t bar;
} MyStruct;

MyStruct mystruct = {0x55, 0xAA};


void main(void)
{
    MyStruct *p  = &mystruct;
    p = (MyStruct*)(((char*)p) + 1);
    //ptr = (((char*)ptr) + 16);
    printf("baz: 0x%02x\n", *p);
    printf("foo: 0x%02x\n", mystruct.foo);
    printf("bar: 0x%02x\n", mystruct.bar);
    printf("\n\r");
}

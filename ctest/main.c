#include <stdio.h>
#include <stdint.h>



//unsigned char hexmap[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
unsigned char hexmap[] = 
    { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46 };
#define MAX 0xFFFFFFF
void int2hextest(void)
{
    for(uint32_t i=0; i<MAX; i++)
    {
        unsigned char mapped[9]; // handle 32-bit word + NULL
        mapped[8] = 0x0;
        for(uint8_t j=0; j<8; j++)
        {
            mapped[7-j] = (unsigned char) hexmap[ (unsigned char) (i >> (j*4) & 0xF) ];
        }

        //unsigned char mapped[2] = { hexmap[i], 0x0};
        printf("0x%s \r", mapped);
    }
    printf("\n\r");
    //
}






typedef struct MyStruct
{
    uint8_t foo;
    uint8_t bar;
} MyStruct;

MyStruct mystruct = {0x55, 0xAA};


void structTest(void)
{
    MyStruct *p  = &mystruct;
    p = (MyStruct*)(((char*)p) + 1);
    //ptr = (((char*)ptr) + 16);
    printf("baz: 0x%02x\n", *p);
    printf("foo: 0x%02x\n", mystruct.foo);
    printf("bar: 0x%02x\n", mystruct.bar);
    printf("\n\r");
}

void main(void)
{
    int2hextest();
}

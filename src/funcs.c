void int2hex(uint8_t val, char *txt)
{    
    unsigned char _s4='0';
    char i=4;
    //intnumber=0xffff;

    do {
        i--;
        _s4 = (unsigned char)  ((intnumber >> i*4 ) & 0x000f);
        if(_s4<10)
            _s4=_s4+48;
        else
            _s4=_s4+55;

        *txt++= _s4;    
    } while(i);     
}
...
char text [5]={0,0,0,0,0};
...

intToHex(65534,text);
USART_Write_Text(text);
....

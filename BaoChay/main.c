#include <main.h>
#include<LCD.c>
float nhietdo;
int x,dat=0;
unsigned char ma7doan[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void hienthi(int num)
{
 output_d(ma7doan[num/10]);output_high(pin_d3);delay_ms(1);output_low(pin_d3);
 output_d(ma7doan[num%10]);output_high(pin_d2);delay_ms(1);output_low(pin_d2);
}
void khoitao_ADC0()
{
   setup_adc_ports(AN0);//thiet lap
   setup_adc(ADC_CLOCK_DIV_2);
   set_adc_channel(0); //chon kenh 0 
   delay_us(100);//on dinh
}
void main()
{
   TRISE0 = 0;
   lcd_init();
   while(TRUE)
   {
      //TODO: User Code
      khoitao_ADC0();
      nut_nhan();
      nhietdo = read_adc()/2.046;
      x = nhietdo;
      hienthi(x);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"LM35: %f",nhietdo);
      do{
      lcd_gotoxy(1,2);
      printf(lcd_putc"Chay Nha");
      RE0 = 1;                /* Buzzer ON                         */
      }while(x>=35);       
      }
}

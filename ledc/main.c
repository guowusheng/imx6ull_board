#include "main.h"

//将所有时钟全部使能
void clk_enable(void)
{
  CCM_CCGR0 = 0xFFFFFFFF;
  CCM_CCGR1 = 0xFFFFFFFF;
  CCM_CCGR2 = 0xFFFFFFFF;
  CCM_CCGR3 = 0xFFFFFFFF;
  CCM_CCGR4 = 0xFFFFFFFF;
  CCM_CCGR5 = 0xFFFFFFFF;
  CCM_CCGR6 = 0xFFFFFFFF;
}

//
void led_init(void)
{
  SW_MUX_GPIO1_IO03 = 0x5;
  // GPIO1_IO03 的IO属性配置
  /*
  bit16: 0 hys迟滞关闭
  bit[15:14]: 00默认下拉
  bit[13]:0 keeper功能
  bit[12]:1 pull/keeper使能
  bit[11]:0 关闭开路输出
  bit[7:6]:10速度１００Mhz
  bit[5:3]: 100 R0/6驱动能力
  bit[0]: 0低转速率
  */
 SW_PAD_GPIO1_IO03 = 0x10B0;

  //设置输出
 GPIO1_GDIR = 0X0000008;
 //默认低电平
 GPIO1_DR = 0x0;
}

//低电平　亮
void led_on(void)
{
  GPIO1_DR &= ~(1<<3);
}

void led_off(void)
{
  GPIO1_DR |= (1<<3);
}

void delay_short(volatile unsigned int n)
{
  while(n--){}
}

void delay(volatile unsigned int n)
{
  while(n--)
  {
    delay_short(0x7ff);
  }
}

int main(void)
{
  clk_enable();
  led_init();

  while(1)
  {
    led_on();
    delay(500);

    led_off();
    delay(500);
  }
  return 0;
}
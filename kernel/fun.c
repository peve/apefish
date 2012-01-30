
void
do_fun_stuff(void)
{
  /* turn on wlan led! */
  /* this is just an arch dependent test, should go away */
  #define BASE        0xB1000000
  #define GPIO_DO     (BASE + 0x0090)
  #define GPIO_CR     (BASE + 0x0098)

  volatile uint32_t* gpio_cr = (volatile uint32_t*) GPIO_CR;
  volatile uint32_t* gpio_do = (volatile uint32_t*) GPIO_DO;

  *gpio_cr = 36; /* set wlan + reset pins to out */
  *gpio_do = 36; /* set wlan + reset pins high */
}

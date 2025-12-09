#include "msp430.h"
#include "timerA_HAL_23.h"

#define PMW_PIN_BIT BIT2
#define PWM_PORT_DIR P1DIR
#define PWM_PORT_SEL P1SEL

void main(void) {
  
  WDTCTL = WDTPW | WDTHOLD; 
  
  TimerA_Config_t myTimerConfig;
  
  myTimerConfig.clockSource     = TIMER_A_CLOCK_SMCLK; 
  myTimerConfig.clockDivider    = TIMER_A_DIV_8;
  myTimerConfig.mode            = TIMER_A_UP_MODE;
  myTImerConfig.period          = 50000;
  
  TimerA_Init(&myTimerConfig);
  
  TimerA_Start();
  
  volatile unsigned int i;
  
  for(i=0; i<20000; i++);
  
  unsigned int currentValue = TimerA_ReadCounter();
  
  TimerA_Stop();
  TimerA_ResetCounter();
  
  PWM_PORT_DIR |= PWM_PIN_BIT;
  PWM_PORT_SEL |= PWM_PIN_BIT;
  
  TimerA_PWM_Init(2000, 250);
  
  while(1) {
    
  }
}       
#include "msp430.h"
#include "timerA_Hal_23.h"


static TimerA_Mode_t g_timerMode = TIMER_A_STOP ; 


void TimerA_Init(const TimerA_Config *config) {
  
  // Clears the Mode Controll bits in TACTL register
  TACTL &= ~(MC0 | MC1);
  
  // Sets TACLR bit, reset TAR to 0 
  TACTL |= TACLR;
  
  // Clears bits 8-9
  TACTL &= ~(TASSEL0 | TASSEL1); 
  
  // Sets the bits according to user's choice
  TACTL |= config->clockSource; 
  
  // Clears bits 6-7
  TACTL &= ~(ID0 | ID1); 
  
  // Sets the bits according to user's choice 
  TACTL |= config->clockDivider; 
  
  // Defines up to where the timer counts before rolling over
  TACCR0 = config->period; 
  
  // Don't start the timer yet
  g_timerMode = config->mode; 
  
}


void TimerA_Start(void) {
  
  TACTL &= ~(MC0 | MC1);         // Make sure it is stopped
  TACTL |= g_timerMode;          // Apply the mode
  
}


void TimerA_Stop(void) {
  
  TACTL &= ~(MC0 | MC1);        // Set the mode controll bits to 0
  
}


unsigned int TimerA_ReadCounter(void) {

  return TAR;                  // Holds the current count of Timer A
  
}

void TimerA_ResetCounter(void) {
  
  TACTL |= TACLR;             // Clears the TAR register to 0
  
}

void TimerA_PWM_Init(unsigned int period, unsigned int dutyCycle) {
  
  TACTL = TACLR;                                   // Clear the timer for startup 
  
  TACTL |= (TASSEL_2 | MC_1 | ID_0);               // Use SMCLK, UP-MODE and divider /1
  
  TACCR0 = period;                                 // Timer counts from 0 up to this value
  
  TACCR1 = dutyCycle;                              // While the timer is less than this value, output stays HIGH
  
  TACCTL1 = OUTMOD_7;                              // Output goes HIGH when timer resets to 0, output goes LOW when timer reaches TACCR1 value
  
}



/* 
 * File:   main.h
 * Author: Chris Hajduk
 *
 * Created on March 3, 2013, 12:42 AM
 */

extern short MSEC;
//#define MSEC 3125                                               //3125 = 1 ms

extern short UPPER_PWM;
extern short LOWER_PWM;
extern short MIDDLE_PWM;

//Defined registers for output compare
#define motor1 OC1RS
#define motor2 OC2RS
#define motor3 OC3RS
#define motor4 OC4RS



/*****************************************************************************
 * Function: init_oc1
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 * 
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc1(void);

/*****************************************************************************
 * Function: init_oc2
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc2(void);

/*****************************************************************************
 * Function: init_oc3
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc3(void);

/*****************************************************************************
 * Function: init_oc4
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc4(void);

/*****************************************************************************
 * Function: init_oc5
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc5(void);

/*****************************************************************************
 * Function: init_oc6
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc6(void);

/*****************************************************************************
 * Function: init_oc7
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc7(void);

/*****************************************************************************
 * Function: init_oc8
 *
 * Preconditions: None.
 *
 * Overview: Initializes the output compare registers with default pwm of 1.5ms
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc8(void);

/*****************************************************************************
 * Function: init
 *
 * Preconditions: None.
 *
 * Overview: Initializes all the output compare pins and timers
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void init_oc(void);

/*****************************************************************************
 * Function: init
 *
 * Preconditions: None.
 *
 * Overview: Initializes all the output compare pins and timers
 *
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void initOC(void);

/*****************************************************************************
 * Function: setPWM
 *
 * Preconditions: None.
 *
 * Overview: Changes or sets the PWM of a given OC pin from a percentage.
 *
 *
 * Input: int ocPin - pin to make the change to.
 *        int percent - percent of the total (2ms) pulse to output.
 *
 * Output: None.
 *
 *****************************************************************************/

void setPWM(int ocPin, int percent);

/*****************************************************************************
 * Function: setPeriod
 *
 * Preconditions: None.
 *
 * Overview: Changes or sets the period of timer 2, to alter ALL output
 * compare frequencies
 *
 *
 * Input: double time - time in milliseconds for the output compare *
 *
 * Output: None.
 *
 *****************************************************************************/

void setPeriod(double time);
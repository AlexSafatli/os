/* timer.h 
* Author: Alex Safatli
* Defines an interface for PIT-related function and its associated interval.
*/

#ifndef TIMER_H
#define TIMER_H

#include "interrupts.h"
#include "idt.h"

#define PIT_DATA_PORT1  0x40
#define PIT_DATA_PORT2  0x42
#define PIT_CMD_PORT    0x43
#define PIT_REPEAT      0x36
#define PIT_CLOCK_SPEED 1193180 /* Hz */

void timer_init(unsigned int);

#endif
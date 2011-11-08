#ifndef _STATEMACHINE_HH_
#define _STATEMACHINE_HH_ CAN_HAS

#include "State.hh"

extern State * ansi_next_state;

void ansi_state_process( char c );
void ansi_state_init();
void ansi_state_flip();

#endif


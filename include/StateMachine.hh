#ifndef _STATEMACHINE_HH_
#define _STATEMACHINE_HH_ CAN_HAS

#include "State.hh"

extern State * csi_next_state;

void csi_state_process( char c );
void csi_state_init();
void csi_state_flip();

#endif


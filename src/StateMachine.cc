#include "StateMachine.hh"
#include "Exception.hh"
#include "State.hh"

State * csi_next_state;
State * csi_internal_state;

void csi_state_process( char c ) {
	try {
		csi_next_state->feed( c );
	} catch ( CIAIncompleteParse & e ) {
		csi_state_flip();
		csi_state_process( c );
	}
}

void csi_state_init() {
	csi_state_flip();
}

void csi_state_flip() {
	csi_internal_state = csi_next_state;
}

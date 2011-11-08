#include "InvalidState.hh"
#include "StateMachine.hh"

void InvalidState::feed( char c ) {
	if ( c != 0x1B ) {
		csi_next_state = &csi_invalid_state;
	} else {
		// csi_next_state = &csi_invalid_state;
	}
}

void InvalidState::enter() {

}

void InvalidState::exit() {

}

InvalidState csi_invalid_state;

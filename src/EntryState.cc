#include "StateMachine.hh"
#include "InvalidState.hh"
#include "EntryState.hh"

void EntryState::feed( char c ) {
	if ( c != 0x1B ) {
		csi_next_state = &csi_invalid_state;
	} else {
		// csi_next_state = ;
	}
}

void EntryState::enter() {

}

void EntryState::exit() {

}

EntryState csi_entry_state;

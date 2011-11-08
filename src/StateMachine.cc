#include "StateMachine.hh"
#include "Exception.hh"
#include "State.hh"

State * ansi_next_state;
State * ansi_internal_state;

void ansi_state_process( char c ) {
	try {
		ansi_next_state->feed( c );
	} catch ( IncompleteParse & e ) {
		ansi_state_flip();
		ansi_state_process( c );
	}
}

void ansi_state_init() {
	ansi_state_flip();
}

void ansi_state_flip() {
	ansi_internal_state = ansi_next_state;
}

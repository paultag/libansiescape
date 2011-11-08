#include "StateMachine.hh"
#include "Exception.hh"
#include "State.hh"

State * ansi_next_state;
State * ansi_internal_state;

void ansi_state_process( char c ) {
	bool incomplete = false;
	try {
		ansi_next_state->feed( c );
	} catch ( IncompleteParse * e ) {
		incomplete = true;
	}

	if ( ansi_next_state != ansi_internal_state ) {
		ansi_state_flip();
	}

	if ( incomplete ) {
		ansi_state_process(c);
	}

}

void ansi_state_init() {
	ansi_internal_state = ansi_next_state;
	ansi_internal_state->enter();
}

void ansi_state_flip() {
	ansi_internal_state->exit();
	ansi_internal_state = ansi_next_state;
	ansi_internal_state->enter();
}

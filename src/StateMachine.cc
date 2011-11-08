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
		/* The state at hand doesn't know how to
		   deal with the current char, and it should
		   be passed to the next state. */
		incomplete = true;
	}

	if ( ansi_next_state != ansi_internal_state ) {
		/* One of the states has requested a state change.
		   Let's action it on their behalf */
		ansi_state_flip();
	}

	if ( incomplete ) {
		/* Right now, recursion is the best way to do this
		   without keeping a char queue. Perhaps I should turn
		   it into a queue / stack later on. */
		ansi_state_process(c);
	}

}

void ansi_state_init() {
	/* Remember: internal_state is uninit'd */
	ansi_internal_state = ansi_next_state;
	ansi_internal_state->enter();
}

void ansi_state_flip() {
	ansi_internal_state->exit();
	ansi_internal_state = ansi_next_state;
	ansi_internal_state->enter();
}

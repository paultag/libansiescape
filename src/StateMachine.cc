/*
 * Copyright (c) 2011 Paul Tagliamonte <tag@pault.ag>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "ansiescape/StateMachine.hh"
#include "ansiescape/Exception.hh"
#include "ansiescape/Parser.hh"
#include "ansiescape/State.hh"

#include <cstddef>

State * ansi_next_state     = NULL;
State * ansi_internal_state = NULL;

void ansi_state_process( char c ) {
	bool incomplete = false;

	try {
		ansi_next_state->feed( c );
	} catch ( IncompleteParse * e ) {
		/* The state at hand doesn't know how to
		   deal with the current char, and it should
		   be passed to the next state. */
		delete e;
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

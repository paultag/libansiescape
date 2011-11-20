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
#include "ansiescape/CSIPrivateModephrase.hh"
#include "ansiescape/CSIValue.hh"
#include "ansiescape/Exception.hh"

#include <stdio.h> // XXX: Fix when not null

void CSIPrivateModephrase::feed( char c ) {
	if ( 
		c == '?' ||
		c == '#' ||
		c == '>' ||
		c == '!'
	) {
		/* We can parse DEC stuff as normal. */
		ansi_state_CSIPrivateModephrase_parsed_private = c;
		ansi_next_state = &ansi_state_CSIValue;
	} else {
		ansi_next_state = &ansi_state_CSIValue;
		throw new IncompleteParse();
	}
}

void CSIPrivateModephrase::enter() {
	ansi_state_CSIPrivateModephrase_parsed_private = 0;
}

void CSIPrivateModephrase::exit() {}

CSIPrivateModephrase ansi_state_CSIPrivateModephrase;
char  ansi_state_CSIPrivateModephrase_parsed_private;

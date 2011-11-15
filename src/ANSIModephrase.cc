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

#include "ansiescape/ANSIModephrase.hh"
#include "ansiescape/StateMachine.hh"
#include "ansiescape/InvalidState.hh"
#include "ansiescape/Exception.hh"
#include "ansiescape/CSIPrivateModephrase.hh"

/* A bit of Wikipedia background:
 * Escape sequences start with the character ESC (ASCII decimal 27/hex
 * 0x1B/octal 033). For two character sequences the second character is in
 * the range ASCII 64 to 95 (@ to _). Most of the sequences are however more
 * than two characters, and start with the characters ESC and [ (left bracket).
 * This sequence is called CSI for Control Sequence Introducer (or Control
 * Sequence Initiator). The final character of these sequences is in the range
 * ASCII 64 to 126 (@ to ~).
 */

void ANSIModephrase::feed( char c ) {
	/* OK. We're escaped. Let's find out if we could have
	   a CSI entry, or a private-mode ANSI escape sequence */
	if ( c == '[' ) {
		/* OK. We've hit a CSI escape sequence. */
		ansi_next_state = &ansi_state_CSIPrivateModephrase;
	} else if ( c >= 64 && c <= 95 ) {
		/* We've hit a private-mode escape sequence */
		/* XXX: Implement the private-mode parsing */
		ansi_next_state = &ansi_state_InvalidState;
		throw new InvalidSequence();
	} else {
		/* We've hit garbage. */
		ansi_next_state = &ansi_state_InvalidState;
		throw new InvalidSequence();
	}
}

void ANSIModephrase::enter() {}
void ANSIModephrase::exit()  {}

ANSIModephrase ansi_state_ANSIModephrase;

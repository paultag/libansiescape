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

#include "ansiescape.hh"

#include "ansiescape/StateMachine.hh"
#include "ansiescape/ANSIEntry.hh"
#include "ansiescape/InvalidState.hh"
#include "ansiescape/Exception.hh"
#include "ansiescape/Parser.hh"

#include <string.h>
#include <malloc.h>
#include <iostream>

ANSI_ESCAPE_PARSE_T ansi_escape_parser_feed( char c ) {
	try {
		ansi_state_process( c );
		if ( ansi_next_state == &ansi_state_ANSIEntry ) {
			return ANSI_ESCAPE_PARSE_OK;
		}
		return ANSI_ESCAPE_PARSE_INCOMPLETE;
	} catch ( InvalidSequence * seq ) {
		delete seq;
		return ANSI_ESCAPE_PARSE_BAD;
	}
}

ansi_sequence * ansi_escape_get_last_sequence() {
	return ansi_parser_last_parsed;
}

void ansi_escape_parser_reset() {
	ansi_next_state = &ansi_state_ANSIEntry;
	ansi_state_init();
}

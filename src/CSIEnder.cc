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

#include <iostream>

#include "ansiescape/StateMachine.hh"
#include "ansiescape/Exception.hh"
#include "ansiescape/InvalidState.hh"
#include "ansiescape/CSIPrivateModephrase.hh"
#include "ansiescape/CSIEnder.hh"
#include "ansiescape/CSIValue.hh"
#include "ansiescape/ANSIEntry.hh"
#include "ansiescape/Parser.hh"

char ansi_state_CSIEnder_parsed_mode;

/* Some wikipedia background:
 * The final byte is technically any character in the range 64 to 126
 * (hex 0x40 to 0x7e, ASCII @ to ~), and may be modified extended with leading
 * intermediate bytes in the range 32 to 47 (hex 0x20 to 0x2f). */

void CSIEnder::feed( char c ) {
	/* XXX: Implement leading bytes correctly */
	if ( c >= 64 && c <= 126 ) {
		/* We've parsed well */
		ansi_state_CSIEnder_parsed_mode = c;
		ansi_next_state = &ansi_state_ANSIEntry;
	} else {
		ansi_next_state = &ansi_state_InvalidState;
		throw new InvalidSequence();
	}
}

void CSIEnder::enter() {}
void CSIEnder::exit()  {
	if ( ansi_parser_last_parsed != NULL )
		delete ansi_parser_last_parsed;
	
	ansi_parser_last_parsed = new ansi_sequence();
	ansi_parser_last_parsed->mode = ansi_state_CSIEnder_parsed_mode;
	ansi_parser_last_parsed->priv = 
		ansi_state_CSIPrivateModephrase_parsed_private;
	ansi_parser_last_parsed->values = 
		new std::vector<int>(ansi_state_CSIValue_parsed_ints);
}

CSIEnder ansi_state_CSIEnder;

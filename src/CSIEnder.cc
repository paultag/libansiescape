/**
 * @file    CSIEnder.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:20:09 UTC 2011
 */

#include <iostream>

#include "StateMachine.hh"
#include "Exception.hh"
#include "InvalidState.hh"
#include "CSIEnder.hh"
#include "CSIValue.hh"
#include "ANSIEntry.hh"
#include "Parser.hh"

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
	ansi_parser_last_parsed = new ansi_sequence();
	ansi_parser_last_parsed->mode = ansi_state_CSIEnder_parsed_mode;
	ansi_parser_last_parsed->values = 
		new std::vector<int>(ansi_state_CSIValue_parsed_ints);
}

CSIEnder ansi_state_CSIEnder;

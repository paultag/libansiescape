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

/* Some wikipedia background:
 * The final byte is technically any character in the range 64 to 126
 * (hex 0x40 to 0x7e, ASCII @ to ~), and may be modified extended with leading
 * intermediate bytes in the range 32 to 47 (hex 0x20 to 0x2f). */

void CSIEnder::feed( char c ) {
	/* XXX: Implement leading bytes correctly */
	if ( c >= 64 && c <= 126 ) {
		/* We've parsed well */
		ansi_next_state = &ansi_state_ANSIEntry;
	} else {
		ansi_next_state = &ansi_state_InvalidState;
		throw new InvalidSequence();
	}
}

void CSIEnder::enter() {}
void CSIEnder::exit()  {}

CSIEnder ansi_state_CSIEnder;

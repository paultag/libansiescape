/**
 * @file    ANSIEntry.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:14:25 UTC 2011
 */

#include "StateMachine.hh"
#include "ANSIEntry.hh"
#include "ANSIModephrase.hh"
#include "InvalidState.hh"
#include "Exception.hh"

void ANSIEntry::feed( char c ) {
	/* This is the start of the sequence.
	   If this is not an ESC char, we must
	   end now, and throw an error. */

	if ( c == 0x1B ) {
		/* Hex 1B is ESC */
		ansi_next_state = &ansi_state_ANSIModephrase;
	} else {
		ansi_next_state = &ansi_state_InvalidState;
		throw new InvalidSequence();
	}
}

void ANSIEntry::enter() {}
void ANSIEntry::exit()  {}

ANSIEntry ansi_state_ANSIEntry;

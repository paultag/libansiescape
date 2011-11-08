/**
 * @file    ANSIModephrase.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:19:15 UTC 2011
 */

#include "StateMachine.hh"
#include "ANSIModephrase.hh"
#include "Exception.hh"
#include "InvalidState.hh"

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
	} else if ( c >= '@' && c <= '_' ) {
		/* We've hit a private-mode escape sequence */
	} else {
		/* We've hit garbage. */
		ansi_next_state = &ansi_state_InvalidState;
		throw new InvalidSequence();
	}
}

void ANSIModephrase::enter() {}
void ANSIModephrase::exit()  {}

ANSIModephrase ansi_state_ANSIModephrase;

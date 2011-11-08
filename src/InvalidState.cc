/**
 * @file    InvalidState.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:26:55 UTC 2011
 */

#include "InvalidState.hh"

void InvalidState::feed( char c ) {
	/* Also known as the "Hotel California" State. */
}

void InvalidState::enter() {}
void InvalidState::exit()  {}

InvalidState ansi_state_InvalidState;

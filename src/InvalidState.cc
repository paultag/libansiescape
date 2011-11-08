#include "InvalidState.hh"
#include "Exception.hh"

void InvalidState::feed( char c ) {
	throw new CIAException;
}

void InvalidState::enter() {

}

void InvalidState::exit() {

}

InvalidState csi_invalid_state;

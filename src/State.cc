#include "State.hh"
#include "Exception.hh"

void State::feed( char c ) {
	throw new ANSIException;
}

void State::enter() {
	throw new ANSIException;
}

void State::exit() {
	throw new ANSIException;
}

/**
 * @file    InvalidState.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:26:55 UTC 2011
 */

#ifndef __INVALIDSTATE_HH
#define __INVALIDSTATE_HH I_CAN_HAS

#include "State.hh"

class InvalidState : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern InvalidState ansi_state_InvalidState;

#endif

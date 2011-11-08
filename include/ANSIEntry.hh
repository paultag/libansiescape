/**
 * @file    ANSIEntry.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:14:25 UTC 2011
 */

#ifndef __ANSIENTRY_HH
#define __ANSIENTRY_HH I_CAN_HAS

#include "State.hh"

class ANSIEntry : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern ANSIEntry ansi_state_ANSIEntry;

#endif

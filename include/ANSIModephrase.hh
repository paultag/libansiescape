/**
 * @file    ANSIModephrase.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:19:15 UTC 2011
 */

#ifndef __ANSIMODEPHRASE_HH
#define __ANSIMODEPHRASE_HH I_CAN_HAS

#include "State.hh"

class ANSIModephrase : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern ANSIModephrase ansi_state_ANSIModephrase;

#endif

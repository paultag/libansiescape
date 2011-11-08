/**
 * @file    .FILENAME.
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created .DATE.
 */

#ifndef .DEFNAME.
#define .DEFNAME. I_CAN_HAS

#include "State.hh"

class .CLASSNAME. : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern .CLASSNAME. ansi_state_.CLASSNAME.;

#endif

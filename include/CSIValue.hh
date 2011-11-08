/**
 * @file    CSIValue.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:19:55 UTC 2011
 */

#ifndef __CSIVALUE_HH
#define __CSIVALUE_HH I_CAN_HAS

#include "State.hh"

class CSIValue : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern CSIValue ansi_state_CSIValue;

#endif

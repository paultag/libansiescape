/**
 * @file    CSIEnder.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:20:09 UTC 2011
 */

#ifndef __CSIENDER_HH
#define __CSIENDER_HH I_CAN_HAS

#include "State.hh"

class CSIEnder : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern CSIEnder ansi_state_CSIEnder;

#endif

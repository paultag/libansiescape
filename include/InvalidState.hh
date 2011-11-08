#ifndef _INVALIDSTATE_HH_
#define _INVALIDSTATE_HH_ CAN_HAS

#include "State.hh"

class InvalidState : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern InvalidState csi_invalid_state;

#endif


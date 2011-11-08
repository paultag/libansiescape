#ifndef _ENTRYSTATE_HH_
#define _ENTRYSTATE_HH_ CAN_HAS

#include "State.hh"

class EntryState : public State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

extern EntryState csi_entry_state;

#endif


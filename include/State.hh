#ifndef _STATE_HH_
#define _STATE_HH_ CAN_HAS

class State {
	public:
		virtual void feed ( char c );
		virtual void enter();
		virtual void exit();
};

#endif


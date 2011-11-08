#include <iostream>
#include <string.h>

#include "StateMachine.hh"
#include "EntryState.hh"


using namespace std;

int main ( int argc, char ** argv ) {
	csi_next_state = &csi_entry_state;
	csi_state_init();
	
	char msg1[] = { 0x1B, '[', '2', 'J', '\0' };
	char msg2[] = { 0x1B, '[', 'H',      '\0' };
	
	for ( unsigned int i = 0; i < strlen( msg1 ); ++i )
		csi_state_process( msg1[i] );


	for ( unsigned int i = 0; i < strlen( msg2 ); ++i )
		csi_state_process( msg2[i] );
}

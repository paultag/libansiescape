#include <iostream>
#include <string.h>

#include "StateMachine.hh"
#include "ANSIEntry.hh"


using namespace std;

int main ( int argc, char ** argv ) {
	ansi_next_state = &ansi_state_ANSIEntry;
	ansi_state_init();
	
	char msg1[] = { 0x1B, '[', '2', ';', '3', 'm', '\0' };
	char msg2[] = { 0x1B, '[', 'H',      '\0' };
	
	for ( unsigned int i = 0; i < strlen( msg1 ); ++i )
		ansi_state_process( msg1[i] );


	for ( unsigned int i = 0; i < strlen( msg2 ); ++i )
		ansi_state_process( msg2[i] );
}

#include <string.h>

#include "Parser.hh"
#include "ANSIEntry.hh"
#include "StateMachine.hh"

ansi_sequence * ansi_parser_last_parsed;

ansi_sequence::ansi_sequence() {
	this->values = new std::vector<int>();
	this->mode   = 0x00;
}

ansi_sequence::~ansi_sequence() {
	delete this->values;
}

ansi_sequence * ansi_parse( char * sequence ) {
	ansi_next_state = &ansi_state_ANSIEntry;
	ansi_state_init();

	for ( unsigned int i = 0; i < strlen( sequence ); ++i )
		ansi_state_process( sequence[i] );

	ansi_sequence * ret = ansi_parser_last_parsed;
	return ret;
}

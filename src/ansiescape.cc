#include "ansiescape.hh"
#include "StateMachine.hh"
#include "ANSIEntry.hh"
#include "InvalidState.hh"
#include "Exception.hh"

#include <string.h>
#include <malloc.h>

ANSI_ESCAPE_PARSE_T ansi_escape_parser_feed( char c ) {
	try {
		ansi_state_process( c );
		if ( ansi_next_state == &ansi_state_ANSIEntry ) {
			return ANSI_ESCAPE_PARSE_OK;
		}
		return ANSI_ESCAPE_PARSE_INCOMPLETE;
	} catch ( InvalidSequence * seq ) {
		return ANSI_ESCAPE_PARSE_BAD;
	}
}

ansi_sequence * ansi_escape_get_last_sequence() {
	return ansi_parser_last_parsed;
}

void ansi_escape_parser_reset() {
	ansi_next_state = &ansi_state_ANSIEntry;
	ansi_state_init();
}

void ansi_escape_parse_string( std::string  s ) {
	ansi_escape_parse_string( s.c_str() );
}

void ansi_escape_parse_string( char * c ) {

}

void ansi_escape_parse_string( const char * c ) {
	char * to_parse = (char *)malloc(sizeof(char) * ( strlen(c) + 1));
	strcpy( to_parse, c );


	free(to_parse);
}


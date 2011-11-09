#include "ansiescape.hh"
#include "StateMachine.hh"
#include "ANSIEntry.hh"
#include "InvalidState.hh"
#include "Exception.hh"

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

}

void ansi_escape_parse_string( char * c ) {

}

void ansi_escape_parse_string( const char * c ) {

}


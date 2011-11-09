#include <ansi/Parser.hh>
#include <ansi/ANSIEntry.hh>
#include <ansi/StateMachine.hh>
#include <ansi/Exception.hh>

#include <string.h>
#include <iostream>

#define PARSE_OK         1
#define PARSE_NO         2
#define PARSE_INCOMPLETE 3

void reset_parser() {
	ansi_next_state = &ansi_state_ANSIEntry;
	ansi_state_init();
}

int feed( char c ) {
	try {
		ansi_state_process( c );
		if ( ansi_next_state == &ansi_state_ANSIEntry ) {
			return PARSE_OK;
		}
		return PARSE_INCOMPLETE;

	} catch ( InvalidSequence * seq ) {
		return PARSE_NO;
	}
}

void output( ansi_sequence * holder ) {
	for ( unsigned int i = 0; i < holder->values->size(); ++i ) {
		std::cout << holder->values->at(i) << ", ";
	}
	std::cout << "Major: " << holder->mode;
	std::cout << std::endl;
}

int main ( int argc, char ** argv ) {
	reset_parser();
	ansi_sequence * holder;

	char sequence[] = { 'h', 'e', 0x1B, '[', 'J', 'l', 'l', 'o', '\0' };

	for ( unsigned int i = 0; i < strlen( sequence ); ++i ) {
		int ret = feed( sequence[i] );
		switch ( ret ) {
			case PARSE_OK:
				holder = ansi_parser_last_parsed;
				output( holder );
				break;
			case PARSE_NO:
				reset_parser();
				break;
			case PARSE_INCOMPLETE:
				/* No action */
				break;
		}
	}
}

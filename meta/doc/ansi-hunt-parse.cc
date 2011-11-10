#include <ansiescape.hh>

#include <string.h>
#include <iostream>

void output( ansi_sequence * holder ) {
	for ( unsigned int i = 0; i < holder->values->size(); ++i ) {
		std::cout << holder->values->at(i) << ", ";
	}
	std::cout << "Major: " << holder->mode;
	std::cout << std::endl;
}

int main ( int argc, char ** argv ) {
	ansi_escape_parser_reset();
	ansi_sequence * holder = NULL;

	char sequence[] = { 'h', 'e', 0x1B, '[', 'J', 'l', 'l', 'o', '\0' };

	for ( unsigned int i = 0; i < strlen( sequence ); ++i ) {
		int ret = ansi_escape_parser_feed( sequence[i] );
		switch ( ret ) {
			case ANSI_ESCAPE_PARSE_OK:
				holder = ansi_parser_last_parsed;
				output( holder );
				break;
			case ANSI_ESCAPE_PARSE_BAD:
				ansi_escape_parser_reset();
				break;
			case ANSI_ESCAPE_PARSE_INCOMPLETE:
				/* No action */
				break;
		}
	}
}

#ifndef _PARSER_HH_
#define _PARSER_HH_ I_CAN_HAS

#include <vector>

class ansi_sequence {
	public:
		ansi_sequence();
		~ansi_sequence();
		char               mode;
		std::vector<int> * values;
};

void ansi_validate( char * sequence );
ansi_sequence * ansi_parse( char * sequence );

extern ansi_sequence * ansi_parser_last_parsed;

#endif

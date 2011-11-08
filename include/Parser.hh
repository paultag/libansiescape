#ifndef _PARSER_HH_
#define _PARSER_HH_ I_CAN_HAS

#include <vector>

typedef struct _ansi_sequence {
	char             mode;
	std::vector<int> values; // XXX: Technically wrong
} ansi_sequence;

void ansi_validate( char * sequence );

#endif

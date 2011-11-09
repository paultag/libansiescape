#ifndef _ANSIESCAPE_HH_
#define _ANSIESCAPE_HH_

/* This header is to give folks a clean and simple facade to interface with
 * the ansi library. Hopefully we can keep this stable and maintainable. */

#define ANSI_ESCAPE_PARSE_OK         1
#define ANSI_ESCAPE_PARSE_BAD        2
#define ANSI_ESCAPE_PARSE_INCOMPLETE 3
#define ANSI_ESCAPE_PARSE_T          int

ANSI_ESCAPE_PARSE_T ansi_escape_parser_feed( char c );

void ansi_escape_parse_string( std::string  s );
void ansi_escape_parse_string( char *       c );
void ansi_escape_parse_string( const char * c

#endif

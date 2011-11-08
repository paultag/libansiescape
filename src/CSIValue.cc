/**
 * @file    CSIValue.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:19:54 UTC 2011
 */

#include "StateMachine.hh"
#include "CSIValue.hh"

#include "Settings.hh"

/* The reason this is a CSIValue rather then an ANSIEscapeValue is because
 * ANSI private-mode values can be free-form, whereas the CSI values must be
 * in a well-formed semi-col delim'd list. */

std::vector<int> ansi_state_CSIValue_parsed_ints;

void CSIValue::feed( char c ) {
	/* OK. C must be one of the following:
	 *   0-9, ;
	 *   ^    ^
	 *    \    \
	 *     \    +---- Delim  - push back chars we've got
	 *      +-------- Number - push into parsed holder, str to int on delim
	 *  If the holder is empty and we hit a delim, we push back -1, since
	 *  -1 is technically invalid. We could also use null, so we'll make
	 *  this compile-time conf-able.
	 *
	 *  Setting is in: Settings.hh/CSI_EMPTY_VALUE
	 * 
	 */
}

void CSIValue::enter() {
	ansi_state_CSIValue_parsed_ints.clear();
}

void CSIValue::exit() {
	/* before we go (since it won't end on a ';') we must call
	   the parse int routines one last time, and append. */
}

CSIValue ansi_state_CSIValue;

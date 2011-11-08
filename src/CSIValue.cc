/**
 * @file    CSIValue.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:19:54 UTC 2011
 */

#include "StateMachine.hh"
#include "CSIValue.hh"

#include "Settings.hh"

void CSIValue::feed( char c ) {
	/* OK. C must be one of the following:
	 *   0-9, ;
	 *   ^    ^
	 *    \    \
	 *     \    +---- Delim  - push back chars we've got
	 *      +-------- Number - push into parsed holder, str to int on delim
	 *  If the holder is empty and we hit a delim, we push back -1, since
	 *  -1 is technically invalid. We could also use null, so we'll make this
	 *  compile-time conf-able.
	 *
	 *  Setting is in: Settings.hh/CSI_EMPTY_VALUE
	 * 
	 */

}

void CSIValue::enter() {

}

void CSIValue::exit() {

}

CSIValue ansi_state_CSIValue;

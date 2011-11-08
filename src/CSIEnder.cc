/**
 * @file    CSIEnder.hh
 * @author  Paul Tagliamonte <tag@pault.ag>
 * @license MIT
 * @created Tue Nov  8 14:20:09 UTC 2011
 */

#include <iostream>

#include "StateMachine.hh"
#include "CSIEnder.hh"
#include "CSIValue.hh"

void CSIEnder::feed( char c ) {

}

void CSIEnder::enter() {
	for (
		unsigned int i = 0;
		i < ansi_state_CSIValue_parsed_ints.size();
		++i
	) {
		std::cout << ansi_state_CSIValue_parsed_ints.at(i) << ", " << std::endl;
	}
}

void CSIEnder::exit() {

}

CSIEnder ansi_state_CSIEnder;

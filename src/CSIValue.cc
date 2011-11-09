/*
 * Copyright (c) 2011 Paul Tagliamonte <tag@pault.ag>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "ansiescape/StateMachine.hh"
#include "ansiescape/Exception.hh"
#include "ansiescape/CSIEnder.hh"
#include "ansiescape/CSIValue.hh"

#include "ansiescape/Settings.hh"

/* The reason this is a CSIValue rather then an ANSIEscapeValue is because
 * ANSI private-mode values can be free-form, whereas the CSI values must be
 * in a well-formed semi-col delim'd list. */

std::vector<int> ansi_state_CSIValue_parsed_ints;

int csivalue_int;

void insert_parsed_int() {
	ansi_state_CSIValue_parsed_ints.insert(
		ansi_state_CSIValue_parsed_ints.end(),
		csivalue_int
	);
	csivalue_int = CSI_EMPTY_VALUE;
}

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
	if ( c == ';' ) {
		insert_parsed_int();
	} else if ( c >= '0' && c <= '9' ) {
		int pv = c - '0';

		if ( csivalue_int == CSI_EMPTY_VALUE )  {
			csivalue_int = pv;
		} else {
			csivalue_int = (csivalue_int * 10);
			csivalue_int += pv;
		}
	} else {
		/* Something that we don't know about. Pass it to the ender */
		ansi_next_state = &ansi_state_CSIEnder;
		throw new IncompleteParse();
	}
}

void CSIValue::enter() {
	ansi_state_CSIValue_parsed_ints.clear();
	csivalue_int = CSI_EMPTY_VALUE;
}

void CSIValue::exit() {
	/* before we go (since it won't end on a ';') we must call
	   the parse int routines one last time, and append. */
	insert_parsed_int();
}

CSIValue ansi_state_CSIValue;

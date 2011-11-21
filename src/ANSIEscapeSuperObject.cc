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

#include "ansiescape/ANSIEscapeSuperObject.hh"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

unsigned int ansi_escape_object_sequence = 1;
#define CLOG std::clog

ANSIEscapeSuperObject::ANSIEscapeSuperObject() {
#ifdef ANSIESCAPE_DEBUG
	this->_ansi_escape_obj_id = ansi_escape_object_sequence;
	ansi_escape_object_sequence++;

	CLOG << "[alloc] " << this->_ansi_escape_obj_id << " C (OBJ)" << std::endl;
#endif
}

ANSIEscapeSuperObject::~ANSIEscapeSuperObject() {
#ifdef ANSIESCAPE_DEBUG
	CLOG << "[alloc] " << this->_ansi_escape_obj_id << " D (OBJ)" << std::endl;
#endif
}

void ANSIEscapeSuperObject::log( std::string s ) {
#ifdef ANSIESCAPE_DEBUG
	CLOG << "[debug] " << s << std::endl;
#endif
}

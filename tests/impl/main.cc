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

#include <iostream>
#include <string.h>
#include <malloc.h>

#include <ansiescape.hh>
#include <ansiescape/Exception.hh>

using namespace std;

int main ( int argc, char ** argv ) {
	std::string line;

	while ( getline (cin,line) ) {
		ansi_escape_parser_reset();

		try {
			ansi_escape_parse_string( line );
			ansi_sequence * seq1 = ansi_escape_get_last_sequence();

			for (
				unsigned int i = 0;
				i < seq1->values->size();
				++i
			) {
				cout << seq1->values->at(i) << ", ";
			}

			cout << "Major mode: " << seq1->mode;
			if ( seq1->priv )
				cout << " Private char: " << seq1->priv;
			cout << endl;

			delete seq1;
		} catch ( ANSIException * e ) {
			std::cout << e->what() << std::endl;
		}
	}
}

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

#ifndef _ANSIESCAPE_HH_
#define _ANSIESCAPE_HH_ foo

#include <string>
#include <ansiescape/Parser.hh>

/* This header is to give folks a clean and simple facade to interface with
 * the ansi library. Hopefully we can keep this stable and maintainable. */

#define ANSI_ESCAPE_PARSE_OK         1
#define ANSI_ESCAPE_PARSE_BAD        2
#define ANSI_ESCAPE_PARSE_INCOMPLETE 3
#define ANSI_ESCAPE_PARSE_T          int

/* OK. All this jazz is all set. Let's declare the facade */

/**
 * process a char out of a stream
 * 
 * Feed a char into the parser. This function can be used to to interpret an
 * input stream as it comes in, rather then buffering input and parsing.
 * 
 * ANSI_ESCAPE_PARSE_OK           We've parsed a sequence and it's in the buffer
 * ANSI_ESCAPE_PARSE_BAD          We've hit an invalid state. Reset when reached
 * ANSI_ESCAPE_PARSE_INCOMPLETE   We're in an OK state, but not finished.
 * 
 * @param    c Input char to feed into the parser
 * @return   One of the following: ANSI_ESCAPE_PARSE_[OK|BAD|INCOMPLETE]
 */
ANSI_ESCAPE_PARSE_T ansi_escape_parser_feed( char c );

/**
 * Get the last parsed sequence from the buffer
 * 
 * This will return the last ansi_sequence that has been parsed, with undefined
 * behavior if accessed before a successful parse.
 * 
 * There's no need to delete this object, the state-machine will handle it
 * for you.
 * 
 * @return a pointer to the last parsed ansi_sequence
 */
ansi_sequence   *   ansi_escape_get_last_sequence();

/**
 * Reset the state-machine to it's default state, and prepare for a new stream.
 * 
 * This (internally) resets the current state, and re-runs the ansi_state_init()
 * function. It may not touch the last parsed sequence, and is perfectly fine to
 * run more then once, right after eachother.
 * 
 * This should be run after an ANSI_ESCAPE_PARSE_BAD, in a perfect world.
 */
void ansi_escape_parser_reset();

#endif

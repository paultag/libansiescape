#include "Exception.hh"

const char * ANSIException::what() const throw() {
	return "Generic CIA Exception";
}

const char * IncompleteParse::what() const throw() {
	return "Incomplete Parsing";
}

const char * InvalidSequence::what() const throw() {
	return "Invalid ANSI Sequence";
}

#include "Exception.hh"

const char * CIAException::what() const throw() {
	return "Generic CIA Exception";
}

const char * CIAIncompleteParse::what() const throw() {
	return "Incomplete Parsing";
}

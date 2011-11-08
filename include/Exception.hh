#ifndef _EXCEPTION_HH_
#define _EXCEPTION_HH_ CAN_HAS

#include <exception>

class ANSIException : public std::exception {
	virtual const char * what() const throw();
};

class IncompleteParse : public ANSIException {
	virtual const char * what() const throw();
};

class InvalidSequence : public ANSIException {
	virtual const char * what() const throw();
};

#endif


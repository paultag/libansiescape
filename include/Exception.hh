#ifndef _EXCEPTION_HH_
#define _EXCEPTION_HH_ CAN_HAS

#include <exception>

class CIAException : public std::exception {
	virtual const char * what() const throw();
};

class CIAIncompleteParse : public CIAException {
	virtual const char * what() const throw();
};

#endif


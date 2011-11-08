#ifndef _EXCEPTION_HH_
#define _EXCEPTION_HH_ CAN_HAS

#include <exception>

class ANSIException : public std::exception {
	public:
		virtual const char * what() const throw();
};

class IncompleteParse : public ANSIException {
	public:
		virtual const char * what() const throw();
};

class InvalidSequence : public ANSIException {
	public:
		virtual const char * what() const throw();
};

#endif


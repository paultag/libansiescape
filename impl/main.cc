#include <iostream>
#include <string.h>
#include <malloc.h>

#include <Parser.hh>
#include <Exception.hh>

using namespace std;

int main ( int argc, char ** argv ) {
	std::string line;

	while ( getline (cin,line) ) {

		char * result = (char *)
			malloc( sizeof(char) * line.length() +1 );

		strcpy( result, line.c_str() );

		try {
			ansi_sequence * seq1 = ansi_parse( result );

			for (
				unsigned int i = 0;
				i < seq1->values->size();
				++i
			) {
				cout << seq1->values->at(i) << ", ";
			}

			cout << "Major mode: " << seq1->mode;
			cout << endl;

			delete seq1;
		} catch ( ANSIException * e ) {
			std::cout << e->what() << std::endl;
		}

		free(result);
	}
}

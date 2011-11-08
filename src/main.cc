#include <iostream>
#include <string.h>

#include <Parser.hh>

using namespace std;

int main ( int argc, char ** argv ) {
	char msg1[] = { 0x1B, '[', '2', ';', '3', 'm', '\0' };
	// char msg2[] = { 0x1B, '[', 'H',      '\0' };

	char * msg = msg1;

	ansi_sequence * seq1 = ansi_parse( msg );

	for ( unsigned int i = 0; i < seq1->values->size(); ++i ) {
		cout << seq1->values->at(i) << ", ";
	}
	cout << endl;

	delete seq1;
}

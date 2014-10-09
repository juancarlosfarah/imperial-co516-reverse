/* ====================================================
 * File: reverse.cpp                                  #
 * This program reverses its source code recursively. #
 * Author: @juancarlosfarah                           #
 * ====================================================
 */

#include <iostream>
#include <fstream>

using namespace std;

/* Function: ReversePrint
 * ======================
 * This function takes in a ifstream and a char
 * and reverse prints the contents of the ifstream.
 */
char ReversePrint(ifstream& ifs, char next) {
	if (ifs.eof()) {
		return next;
	}

	ifs.get(next);
	cout.put(ReversePrint(ifs, next));
	return next;
}

/* Function: Main
 * ==============
 */
int main() {

	ifstream ifs;

	ifs.open("reverse.cpp");

	if (ifs.fail()) {
		cerr << "Opening of input file failed!" << endl;
		exit(1);
	}

	cout.put(ReversePrint(ifs, static_cast<char>(NULL)));
	
	/* add space after output */
	cout << "\n\n" << endl;
	
	ifs.close();
	
	return 0;
}

/*
* DAMAGE REPORT:
* File reading is not crashing anymore.
* Couple temporary fixes for splitting strings should be replaced.
* Not counting up words correctly.
* Not counting times talked correctly.
* Wrong gender stats being printed.
*/

#include <fstream>
#include <iostream>
#include <string>
#include "Character.h"
#include "Script.h"
#include "ScriptSurfer.h"

int main() {

	ScriptSurfer* mySurfer = new ScriptSurfer();
	mySurfer->displayIntro();
	mySurfer->runMainMenuOptions();
	
	std::string fileName = mySurfer->promptFileName();
	std::string myText;

	//// Read from the text file
	std::ifstream MyReadFile(fileName);

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		std::cout << myText;
	}


	return 0;
}
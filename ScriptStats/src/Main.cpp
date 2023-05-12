/*
* DAMAGE REPORT:
* Translated everything into c++.
* Compiling fine.
* Main menu not detecting ints correctly.
*/

#include <iostream>
#include <string>
#include "Character.h"
#include "Script.h"
#include "ScriptSurfer.h"

int main() {

	ScriptSurfer* mySurfer = new ScriptSurfer();
	mySurfer->displayIntro();
	mySurfer->runMainMenuOptions();
	
	//Example of getting rid of long syntax references
	//using namespace std;

	////Basic input ouput example
	//std::string input;
	//cin >> input;
	//std::cout << input;

	////Example creating an object
	//Character myDude;
	//myDude.setAge(24);
	//myDude.setGender(Male);
	//myDude.setName("Ben");
	//myDude.setRace(White);

	////Example printing out object fields
	//std::cout << std::endl;
	//std::cout << "Age: " << myDude.getAge() << std::endl;
	//std::cout << "Name: " << myDude.getName() << "\n";
	//std::cout << "Race: " << myDude.displayRace[myDude.getRace()] << "\n";
	//std::cout << "Gender: " << myDude.displayGender[myDude.getGender()] << "\n";

	return 0;
}
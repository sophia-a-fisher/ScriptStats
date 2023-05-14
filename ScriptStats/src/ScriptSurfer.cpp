
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "Character.h"
#include <cstring>
#include "Script.h"
#include "ScriptSurfer.h"
#include <direct.h>

/**
     * Displays text introducing the program.
     */
void  ScriptSurfer::displayIntro() {
    std::cout << "\nWelcome to Script Runner, a program designed to give you useful " +
        std::string("data on your script.\nFunctionality includes calculating character word counts, ") +
        std::string("gender balance statistics, and more.\n");
}

/**
 * Asks user to input name of .txt file (excluding extension).
 * Name of file is returned.
 * @param keyboard Scanner connected to keyboard
 * @return fileName
 */
std::string ScriptSurfer::promptFileName() {
    std::cout << "Enter script file name (no extension): ";
    std::string fileName = "";
    //if (keyboard.hasNext()) {
    std::cin >> fileName;
        fileName += ".txt";
    //}
    //getting the current working directory and appending to front
        char buff[FILENAME_MAX];
        char* curDir = _getcwd(buff, FILENAME_MAX);
        std::string dir(curDir);
        fileName = dir + std::string("\\") + fileName;
    return fileName;
}

/* Create a Scanner and return connected to a File with the given name.
 * pre: fileName != null
 * post: Return a Scanner connected to the file or null
 * if the File does not exist in the current directory.
 */
std::ifstream& ScriptSurfer::getFileScannerForNames(std::string fileName) {
    std::string myText;
    std::ifstream myReadStream(fileName);
    //std::ifstream* sc = &myReadStream;
    // Use a while loop together with the getline() function to read the file line by line
    getline(myReadStream, myText);

    try {
        //sc->open(fileName, std::ios::in);
    }
    //TODO put this back in
    catch (std::exception& e) {
        std::cout << "\n***** ERROR IN READING FILE ***** ";
        std::cout << "Can't find this file "
            + fileName + " in the current directory.";
        //std::cout << ("Error: " + std::to_string(e));
        //std::string currentDir = System.getProperty("user.dir");
        //System.out.println("Be sure " + fileName + " is in this directory: ");
        //System.out.println(currentDir);
        std::cout << ("\nReturning null from method.");
        //sc = nullptr;
    }
    return myReadStream;
}

/**
 * Asks user to enter a menu choice. If the menu choice is
 * valid that number is returned. Else a message is displayed
 * and the user is asked to enter a choice again.
 * @param keyboard Scanner connected to user keyboard
 * @return user menu choice
 */
int ScriptSurfer::getChoice() {
    // Note, no way to check if keyboard actually connected to System.in
    // so we simply assume it is.
    /*if (keyboard == null) {
        throw new IllegalArgumentException("The parameter keyboard cannot be null");
    }*/
    int choice = getInt("Enter choice: ");
    std::cout << std::endl;
    // Add one due to zero based indexing of enums, but 1 based indexing of menu.
    int MAX_CHOICE = SM_QUIT + 1;
    while (choice < 1 || choice > MAX_CHOICE) {
        std::cout << std::endl;
        std::cout << (choice + " is not a valid choice");
        choice = getInt("Enter choice: ");
        std::cout << std::endl;
    }
    return choice;
}

/* Ensure an int is entered from the keyboard.
 * pre: s != null and is connected to System.in
 * post: return the int typed in by the user.
 */
int ScriptSurfer::getInt(std::string prompt) {
    // Note, no way to check if keyboard actually connected to System.in
    // so we simply assume it is.
   /* if (s == null) {
        throw new IllegalArgumentException("The parameter s cannot be null");
    }*/
    std::cout << (prompt);
    bool hasInt = false;
    std::string nextInt;
    std::cin >> nextInt;
    hasInt = isNumber(nextInt);
    while (!hasInt) {
        std::cout << ("That was not an int.\n\n");
        std::cout << (prompt);
        std::cin >> nextInt;
    }
    return stoi(nextInt);
}

bool ScriptSurfer::isNumber(const std::string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

/**
 * Calls the method associated with user's start-up menu choice.
 */
void ScriptSurfer::runMainMenuOptions() {
  
    //MainMenuChoices[] menuChoices = MainMenuChoices.values();
    //MainMenuChoices menuChoice;
    int userChoice;
    do {
        showMainMenu();
        userChoice = getChoice() - 1;
        //menuChoice = menuChoices[userChoice];
        if (userChoice == EXPLORE_DATABASE) {
            runDatabaseOptions();
        }
        else if (userChoice == INPUT_SCRIPT) {
            //std::ifstream& fileScanner = getFileScannerForNames(promptFileName());
            std::ifstream fileScanner;
            std::string fileName = promptFileName();
            Script* script = new Script(fileScanner, fileName);
            //fileScanner.close(); //TODO figure out how to close
            runScriptOptions(script);
        }
    } while (userChoice != MM_QUIT);
}

/**
 * Calls the method associated with database menu choice.
 */
void ScriptSurfer::runDatabaseOptions() {
    //DatabaseChoices menuChoices[] = DatabaseChoices.values();
    //DatabaseChoices menuChoice;
    int userChoice;
    do {
        showDatabaseMenu();
        userChoice = getChoice() - 1;
        //menuChoice = menuChoices[userChoice];
        if (userChoice == DISNEY) {
            runSpecDatabaseOptions();
        }
    } while (userChoice != D_QUIT);
}

void ScriptSurfer::printDisneyOptions() {
    std::cout << std::string("\n101 Dalmations | Aladdin | Alice in Wonderland\n") +
        std::string("Aristocats | Atlantis | Bambi | Beauty and the Beast \n") +
        std::string("Black Cauldron | Bolt | Cinderella | Emperor's New Groove\n") +
        std::string("Encanto | Fantasia | Fantasia 2000 | Fox and the Hound\n") +
        std::string("Frozen | Frozen II | Hercules | Hunchback of Notre Dame\n") +
        std::string("Jungle Book | Lady and the Tramp | Raya and the Last Dragon\n") +
        std::string("Lilo and Stitch | Lion King | Little Mermaid | Moana\n") +
        std::string("Mulan | Peter Pan | Pinocchio | Pocahontas | Rescuers\n") +
        std::string("Robin Hood | Sleeping Beauty | Snow White | Tangled\n") +
        std::string("Tarzan | Zootopia\n\n");
}

/**
 * Calls the method associated with user's menu choice.
 */
void ScriptSurfer::runSpecDatabaseOptions() {
    printDisneyOptions();
    //TODO below line is not fetching the fstream correctly, not returning the object or closing or something
    //std::ifstream& fileScanner = getFileScannerForNames(promptFileName());
    //std::string temp;
    //fileScanner.open(promptFileName());
    //getline(fileScanner, temp);
    std::ifstream fileScanner;
    std::string fileName = promptFileName();
    Script* script = new Script(fileScanner, fileName);
    (fileScanner).close();
    runScriptOptions(script);
}

/**
 * Calls the method associated with user's menu choice.
 * @param script the script in question
 */
void ScriptSurfer::runScriptOptions(Script* script) {
    //Scanner keyboard = new Scanner(System.in);
    //ScriptMenuChoices[] menuChoices = ScriptMenuChoices.values();
    //ScriptMenuChoices menuChoice;
    int userChoice;
    do {
        showScriptMenu();
        userChoice = getChoice() - 1;
        //menuChoice = menuChoices[userChoice];
        if (userChoice == DISPLAY_CHARACTERS) {
            displayChar(script);
        }
        else if (userChoice == DISPLAY_MUTED) {
            displayMuted(script);
        }
        else if (userChoice == ASSIGN_GENDER) {
            assignGen(script);
        }
        else if (userChoice == ASSIGN_ALL_GENDERS) {
            assignAllGen(script);
        }
        else if (userChoice == DISPLAY_GENDERS) {
            displayGen(script);
        }
        else if (userChoice == MUTE) {
            mute(script);
        }
        else if (userChoice == UNMUTE) {
            unmute(script);
        }
    } while (userChoice != SM_QUIT);
    //keyboard.close();
}

/**
 * Prints string of non-muted characters names with their
 * gender, wordCounts, speechCounts, and averageWords per speech.
 * @param script the Script in question
 */
void ScriptSurfer::displayChar(Script* script) {
    std::cout << (script->toString());
}

/**
 * Prints string of muted characters names with their
 * gender, wordCounts, speechCounts, and averageWords per speech.
 * @param script the Script in question
 */
void ScriptSurfer::displayMuted(Script* script) {
    std::cout << (script->displayMuted());
}

/**
 * Prompts user to enter character name to be muted.
 * Mutes Character with input name. Muted characters will no longer
 * be displayed in character display or used in calculations
 * of gender balance.
 * @param script the Script in question
 * @param key Scanner connected to the keyboard
 */
void ScriptSurfer::mute(Script* script) {
    std::cout << ("Name: ");

    std::string name;
    std::string restOfName;
    std::cin >> name;
    getline(std::cin, restOfName);
    name.append(restOfName);
    script->mute(name);
   
    std::cout << (name + " successfully muted.\n");
}

/**
 * Prompts user to enter character name to be unmuted.
 * Un-mutes Character with input name. Non-muted characters will
 * be displayed in character display and used in calculations
 * of gender balance.
 * @param script the Script in question
 * @param key Scanner connected to the keyboard
 */
void ScriptSurfer::unmute(Script* script) {
    std::cout << ("Name: ");

    std::string name;
    std::string restOfName;
    std::cin >> name;
    getline(std::cin, restOfName);
    name.append(restOfName);

    script->unmute(name);
    std::cout << (name + " successfully unmuted.\n");
}

/**
* Prints totalWordCounts, averageSpeechCount,
* and averageWords per speech for all non-muted character genders.
* @param script the Script in question
*/
void ScriptSurfer::displayGen(Script* script) {
    std::cout << (script->displayGenders());
}

/**
 * Prompts user to assign genders for each
 * individual character in the Script.
 * @param script the Script in question
 * @param key Scanner connected to the keyboard
 */
void ScriptSurfer::assignAllGen(Script* script) {
    std::vector<std::string> names = script->getNames();
    for (std::string n : names) {
        std::cout << ("Gender of " + n + ": ");
        //if (key.hasNext()) {
        std::string gen;
        std::cin >> gen;
            script->assignGender(n, gen);
        //}
    }
}

/**
 * Prompts user to assign gender for one
 * character in the Script.
 * @param script the Script in question
 * @param key Scanner connected to the keyboard
 */
void ScriptSurfer::assignGen(Script* script) {
    // prompting user to enter name
    std::cout << ("Name: ");
    
    // retrieving name
    std::string name;
    std::string restOfName;
    std::cin >> name;
    getline(std::cin, restOfName);
    name.append(restOfName);
   
    // prompting user to enter gender
    std::cout << ("Gender: ");
        
    // retrieving gender
    std::string gen;
    std::string restOfGen;
    std::cin >> gen;
    getline(std::cin, restOfGen);
    gen.append(restOfGen);

    script->assignGender(name, gen);
}

/**
 * Shows the user menu.
 */
void ScriptSurfer::showScriptMenu() {
    std::cout << std::endl;
    std::cout << ("Script Options:\n");
    std::cout << ("Enter 1 | display character details.\n");
    std::cout << ("Enter 2 | display muted characters.\n");
    std::cout << ("Enter 3 | assign a gender.\n");
    std::cout << ("Enter 4 | assign all genders.\n");
    std::cout << ("Enter 5 | display gender balance.\n");
    std::cout << ("Enter 6 | mute a character.\n");
    std::cout << ("Enter 7 | un-mute a character.\n");
    std::cout << ("Enter 8 | quit to menu.\n");
    std::cout << std::endl;
}

/**
 * Shows the start-up menu.
 */
void ScriptSurfer::showMainMenu() {
    std::cout << std::endl;
    std::cout << ("Main Menu Options:\n");
    std::cout << ("Enter 1 | explore script databases.\n");
    std::cout << ("Enter 2 | input custom script.\n");
    std::cout << ("Enter 3 | quit.\n");
    std::cout << std::endl;
}

/**
 * Shows the database menu.
 */
void ScriptSurfer::showDatabaseMenu() {
    std::cout << std::endl;
    std::cout << ("Database Options:\n");
    std::cout << ("Enter 1 | DISNEY.\n");
    std::cout << ("Enter 2 | quit to menu.\n");
    std::cout << std::endl;
}
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Character.h"
#include <cstring>
#include "script.h"

enum ScriptMenuChoices {
    DISPLAY_CHARACTERS, DISPLAY_MUTED, ASSIGN_GENDER, ASSIGN_ALL_GENDERS, DISPLAY_GENDERS, MUTE, UNMUTE, SM_QUIT
};

enum MainMenuChoices {
    EXPLORE_DATABASE, INPUT_SCRIPT, MM_QUIT
};

/**
 * An enumerated type to hold database choices
 */
enum DatabaseChoices {
    DISNEY, D_QUIT
};

class ScriptSurfer {

public:
    void displayIntro();
    std::string promptFileName();
    std::ifstream& getFileScannerForNames(std::string fileName);
     int getChoice();
     int getInt(std::string prompt);
     void runMainMenuOptions();
    void runDatabaseOptions();
    void printDisneyOptions();
     void runSpecDatabaseOptions();
     void runScriptOptions(Script* script);
     void displayChar(Script* script);
     void displayMuted(Script* script);
     void mute(Script* script);
     void unmute(Script* script);
     void displayGen(Script* script);
     void assignAllGen(Script* script);
     void assignGen(Script* script);
     void showScriptMenu();
     void showMainMenu();
     void showDatabaseMenu();

    std::string displayDatabaseChoices[2];
    std::string displayMainMenuChoices[3];
    std::string displayScriptMenuChoices[8];

private:
    bool isNumber(const std::string& str);

};

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Character.h"
#include <cstring>

class Script
{

private:

    //all characters present in script
    std::vector<Character*> characters;
    //all genders present in script
    std::vector<std::string> genders;
    int numCharacters;
    bool spoken;
    std::string title;

    int getGenderWordCount(std::string g);
    void initializeAverageWordCount();
    bool containsCharacter(std::string name);
    Character* getCharacter(std::string name);
    std::vector<std::string> splitNameFromGender(std::string str, char sep, char sep2);
    std::vector<std::string> split(std::string str, char sep, char sep2);
    bool isNumber(const std::string& str);
    bool containsAlpha(std::string str);
    //void initializeCharacters(Scanner sc);
    void initializeCharacters(std::ifstream& scanner);
    void initializeGenders();
    int countWords(std::string line);
    std::string getGenderSpeechTime(std::string g);
    std::string getWordsPerDialogue(std::string g);

public:

    //Script(Scanner sc); TODO check do we not need a parameter?
    Script(std::ifstream& sc, std::string fileName);
    std::string toString();
    std::string displayMuted();
    std::vector<std::string> getNames();
    int getNumCharacters();
    void assignGender(std::string name, std::string gender);
    std::string displayGenders();
    void mute(std::string name);
    void unmute(std::string name);

};


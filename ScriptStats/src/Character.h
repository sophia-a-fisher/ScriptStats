#pragma once

/*
* Abstraction of a character in the script.
*/

#include <iostream>
#include <string>

//enum Gender { Female, Male };
//enum Race { White, Asian, Black };

class Character
{

private:
	/*int age;
	std::string name;
	Race race;
	Gender gender;*/

    std::string name;
    int wordCount;
    std::string gender;
    bool mute;
    int timesSpoke;
    double averageWordsSpoke;

public:

	//String arrays associated with enums
	//std::string displayGender[2];
	//std::string displayRace[3];

	Character(std::string name, std::string gender);
    Character(std::string name, std::string gender, bool muted);

    void calcAverageWordsSpoke();
    double getAverageWordsSpoke();
    int getWordCount();
    void setMute(bool mute);
    bool getMute();
    std::string getName();
    void addWords(int words);
    void setGender(std::string gender);
    std::string getGender();
    void incrementTimesSpoke();
    int getTimesSpoke();

	/*int getAge();
	std::string getName();
	Race getRace();
	Gender getGender();
	void setAge(int _age);
	void setName(std::string _name);
	void setRace(Race _race);
	void setGender(Gender _gender);*/


};

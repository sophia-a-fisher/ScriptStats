#include "Character.h"



//Character::Character()
//{
    //	//Better way to do this
    //	displayGender[0] = "Female";
    //	displayGender[1] = "Male";
    //	displayRace[0] = "White";
    //	displayRace[1] = "Asian";
    //	displayRace[2] = "Black";
    //}
    //
    //int Character::getAge()
    //{
    //	return age;
    //}
    //
    //std::string Character::getName()
    //{
    //	return name;
    //}
    //
    //Race Character::getRace()
    //{
    //	return race;
    //}
    //
    //Gender Character::getGender()
    //{
    //	return gender;
    //}
    //
    //void Character::setAge(int _age)
    //{
    //	age = _age;
    //}
    //
    //void Character::setName(std::string _name)
    //{
    //	name = _name;
    //}
    //
    //void Character::setRace(Race _race)
    //{
    //	race = _race;
    //}
    //
    //void Character::setGender(Gender _gender)
    //{
    //	gender = _gender;
    //}

        /**
         * Initializing character instance variables.
         * @param name character name
         * @param gender character gender
         */
    Character::Character(std::string name, std::string gender) : Character::Character(name, gender, false) {
        //TODO confirm this is working
     
    }

    /**
     * Initializing character instance variables.
     * @param name character name
     * @param gender character gender
     * @param muted true if character shows muted in display
     */
    Character::Character(std::string name, std::string gender, bool muted) {
        this->name = name;
        this->gender = gender;
        mute = muted;
        timesSpoke = 0;
        wordCount = 0;
        averageWordsSpoke = 0;
    }

    /**
     * Calculates average numWords Character spoke per uninterrupted speech.
     */
    void Character::calcAverageWordsSpoke() { averageWordsSpoke = ((double)wordCount / timesSpoke); }

    /**
     * Returns average numWords Character spoke per uninterrupted speech.
     * @return averageWordsSpoke
     */
    double Character::getAverageWordsSpoke() { return averageWordsSpoke; }

    /**
     * Returns total numWords attributed to Character.
     * @return wordCount
     */
    int Character::getWordCount() {
        return wordCount;
    }

    /**
     * Sets character mute setting to mute.
     * @param mute true to mute,
     *             false to un-mute
     */
    void Character::setMute(bool mute) {
        this->mute = mute;
    }

    /**
     * Returns mute setting for Character.
     * @return true if Character is muted
     */
    bool Character::getMute() {
        return mute;
    }

    /**
     * Returns Character name.
     * @return name
     */
    std::string Character::getName() {
        return name;
    }

    /**
     * Adds words to total Character wordCount.
     * @param words numWords to add to total
     */
    void Character::addWords(int words) {
        wordCount += words;
    }

    /**
     * Assigns gender to Character.
     * @param gender gender to be assigned
     */
    void Character::setGender(std::string gender) {
        this->gender = gender;
    }

    /**
     * Returns Character gender.
     * @return gender
     */
    std::string Character::getGender() {
        return gender;
    }

    /**
     * Increments numTimes Character spoke uninterrupted by one.
     */
    void Character::incrementTimesSpoke() { timesSpoke++; }

    /**
     * Returns numTimes Character spoke uninterrupted.
     * @return timesSpoke
     */
    int Character::getTimesSpoke() { return timesSpoke; };



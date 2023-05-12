#include "Character.h"
#include "Script.h"
#include <cstring>
#include <iomanip>
#include <sstream>
#include <algorithm>


/**
     * Initializing Script Characters, assigning explicit attributes,
     * calculating total wordCounts for each.
     * @param sc Scanner reading script .txt file
     */
//Script::Script() {
//    if (sc.hasNextInt()) {
//        numCharacters = sc.nextInt();
//        initializeCharacters(sc);
//        initializeGenders();
//    }
//    spoken = true;
//    Character currentChar = new Character("", "NA");
//    while (sc.hasNext()) {
//        String line = sc.nextLine();
//        //if dialogue being assigned
//        if (line.contains(":")) {
//            int colonIndex = line.indexOf(":");
//            String tempName = line.substring(0, colonIndex);
//            //if a different character speaking
//            if (!tempName.equalsIgnoreCase(currentChar.getName())) {
//                //if character exists
//                if (containsCharacter(tempName)) {
//                    currentChar = getCharacter(tempName);
//                }
//                //if character is new
//                else {
//                    currentChar = new Character(tempName, "NA");
//                    characters.add(currentChar);
//                }
//                currentChar.incrementTimesSpoke();
//            }
//            //if same character as before
//            if (colonIndex + 1 < line.length()) {
//                currentChar.addWords(countWords(line.substring(colonIndex + 1)));
//            }
//        }
//        else {
//            currentChar.addWords(countWords(line));
//        }
//    }
//    initializeAverageWordCount();
//}

/**
 * Calculates the average numWords per uninterrupted speech
 * for all characters.
 */
void Script::initializeAverageWordCount() {
    for (Character* c : characters) {
        c->calcAverageWordsSpoke();
    }
}

/**
 * Returns true if Script contains Character of name.
 * @param name Character name to search for
 * @return true if script contains character of name
 */
bool Script::containsCharacter(std::string name) {
    for (Character* c : characters) {
        //case insensitive comparison, converting strings to char ptrs
        if (_stricmp(c->getName().c_str(), name.c_str())) {
            return true;
        }
    }
    return false;
}

/**
 * Returns Character with name.
 * @param name Character name searching for
 * @return Character with name
 */
Character* Script::getCharacter(std::string name) {
    for (Character* c : characters) {
        //case insensitive comparison, converting strings to char ptrs
        if (_stricmp(c->getName().c_str(), name.c_str())) {
            return c;
        }
    }
    return nullptr;
}

/**
 * Initializes Characters array to include
 * all explicitly listed characters in .txt file.
 * Assigning name, gender, and muted attributes.
 * @param sc Scanner reading script .txt file
 */
//TODO fix the Scanner implementation
void Script::initializeCharacters() {
    std::cout << std::endl;
    for (int i = 0; i < numCharacters; i++) {
        //if (sc.hasNext()) {
            //splitting name and gender attributes based on ()
        std::string nextLine;
        std::cin >> nextLine;
        //TODO check split is working for the below arguments
            std::vector<std::string> attributes = split(nextLine, '(', ')');
            //(s.find('(') != std::string::npos)
            if (attributes.size() > 2 && (attributes[2].find("*") != std::string::npos)) {
                characters.push_back(new Character(attributes[0], attributes[1], true));
            }
            else {
                characters.push_back(new Character(attributes[0], attributes[1]));
            }

        //}
    }
}

/**
 * Initializes genders array to include
 * all genders specified through character attributes.
 */
void Script::initializeGenders() {
    for (Character* c : characters) {
        bool newGender = true;
        for (std::string g : genders) {
            //case insensitive comparison, converting strings to char ptrs
            if (_stricmp(g.c_str(), c->getGender().c_str())) {
                newGender = false;
                break;
            }
        }
        if (newGender) {
            //adding a gender to the vector list
            genders.push_back(c->getGender());
        }
    }
}

std::vector<std::string> Script::split(std::string str, char sep, char sep2) {

    // variable to store token obtained from the original
    std::string s;

    // constructing stream from the string
    std::stringstream ss(str);

    // declaring vector to store the string after split
    std::vector<std::string> v;

    // using while loop to deliminate
    while (getline(ss, s, sep) or getline(ss, s, sep2)) {
        // store token string in the vector
        v.push_back(s);
    }
    return v;
}

/**
 * Returns number of dialogue words in line.
 * Excludes staging marked with <> or [] or () or {}.
 * @param line Script line in question
 * @return number dialogue words in line
 */
int Script::countWords(std::string line) {
    //splits using whitespace
    std::vector <std::string> text = split(line, ' ', ' ');
    int count = 0;
    //checking each word is valid dialogue
    for (std::string s : text) {
        bool containsOneAlphabet = std::any_of(std::begin(s), std::end(s), ::isalpha);
        if (strcmp(s.c_str(), "")) {
            continue;
        }
        //TODO check this is a valid substitute for contains
        if ((s.find('[') != std::string::npos) || (s.find('(') != std::string::npos) || (s.find('<') != std::string::npos)
            || (s.find('{') != std::string::npos)) {
            spoken = false;
        }
        if (spoken && containsOneAlphabet) {
            count++;
        }
        if ((s.find(']') != std::string::npos) || (s.find(')') != std::string::npos) || (s.find('>') != std::string::npos)
            || (s.find('}') != std::string::npos)) {
            spoken = true;
        }
    }
    return count;
}

/**
 * Returns String of non-muted Characters names with their
 * gender, wordCounts, speechCounts, and averageWords per speech.
 * @return non-muted character information
 */
std::string Script::toString() {
    std::string r = "Script Character Details\n";
    for (Character* c : characters) {
        if (!c->getMute()) {
            //Truncating the precision
            std::string avgWordSpoke; 
            std::stringstream sresult;
            sresult << std::setprecision(2) << c->getAverageWordsSpoke() << std::endl;
            avgWordSpoke = sresult.str();
            r.append(c->getName()).append("(").append(c->getGender())
                .append(")").append(": ").append(std::to_string(c->getWordCount()))
                .append(" words, spoke: ").append(std::to_string(c->getTimesSpoke()))
                .append(" times. ").append(" Avg. ").append(avgWordSpoke)
                .append(" words/dialogue.\n");
        }
    }
    return r;
}

/**
 * Returns String of muted characters names with their
 * gender, wordCounts, speechCounts, and averageWords per speech.
 * @return muted character information
 */
std::string Script::displayMuted() {
    std::string r = "Muted Character Details\n";
    for (Character* c : characters) {
        if (c->getMute()) {
            r.append(c->getName()).append("(").append(c->getGender())
                .append(")").append(": ").append(std::to_string(c->getWordCount()))
                .append(" words, spoke: ").append(std::to_string(c->getTimesSpoke()))
                .append(" times. ").append(" Avg. ").append(std::to_string(c->getAverageWordsSpoke()))
                .append(" words/dialogue.\n");
        }
    }
    return r;
}

/**
 * Returns list of all Character names.
 * @return Character names
 */
std::vector<std::string> Script::getNames() {
    std::vector<std::string> r;
    for (Character* c : characters) {
        r.push_back(c->getName());
    }
    return r;
}

/**
 * Returns numCharacters in Script.
 * @return numCharacters
 */
int Script::getNumCharacters() {
    return numCharacters;
}

/**
 * Assigns Character of name to gender.
 * @param name Character name searching for
 * @param gender gender setting to assign
 */
void Script::assignGender(std::string name, std::string gender) {
    for (Character* c : characters) {
       if(_stricmp(c->getName().c_str(), name.c_str())){
            c->setGender(gender);
            bool newGender = true;
            for (std::string g : genders) {
                if(_stricmp(g.c_str(), gender.c_str())) {
                    newGender = false;
                    break;
                }
            }
            if (newGender) {
                genders.push_back(gender);
            }
        }
    }
}

/**
 * Returns String with totalWordCounts, averageSpeechCounts,
 * and averageWords per speech for all non-muted character genders.
 * @return gender balance information
 */
std::string Script::displayGenders() {
    std::string r = "Script Gender Balance\n" + std::string("Total Words\n");
    for (std::string g : genders) {
        r.append(g).append(": ");
        r.append(std::to_string(getGenderWordCount(g))).append("\n");
    }
    r.append("Average Times Spoke\n");
    for (std::string g : genders) {
        r.append(g).append(": ");
        r.append(getGenderSpeechTime(g)).append("\n");
    }
    r.append("Average Words/Dialogue\n");
    for (std::string g : genders) {
        r.append(g).append(": ");
        r.append(getWordsPerDialogue(g)).append("\n");
    }
    return r;
}

/**
 * Returns String with averageSpeechCount for all
 * Characters of g gender, truncated to two decimals.
 * @param g gender of interest
 * @return averageSpeechCount for gender
 */
std::string Script::getGenderSpeechTime(std::string g) {
    double sum = 0;
    int total = 0;
    for (Character* c : characters) {
        if (_stricmp(c->getGender().c_str(), g.c_str()) && !c->getMute()) {
            sum += c->getTimesSpoke();
            total++;
        }
    }
    //Truncating the result for displaying, TODO make sure this works!
    double result = (sum / total);
    std::stringstream sresult;
    sresult << std::setprecision(2) << result << std::endl;
    return sresult.str();
}

/**
 * Returns String averageWords per speech for all
 * characters of g gender, truncated to two decimals.
 * @param g gender of interest
 * @return averageWords per speech for gender
 */
std::string Script::getWordsPerDialogue(std::string g) {
    double sum = 0;
    int total = 0;
    for (Character* c : characters) {
       if(_stricmp(c->getGender().c_str(), g.c_str()) && !c->getMute()){
            sum += c->getAverageWordsSpoke();
            total++;
        }
    }
    //Truncating the result for displaying, TODO make sure this works!
    double result = (sum / total);
    std::stringstream sresult;
    sresult << std::setprecision(2) << result << std::endl;
    return sresult.str();
}

/**
 * Mutes Character of name.
 * @param name Character name to be muted
 */
void Script::mute(std::string name) {
    for (Character* c : characters) {
        if (_stricmp(c->getName().c_str(), name.c_str())) {
            c->setMute(true);
        }
    }
}

/**
 * Un-mutes Character of name.
 * @param name Character name to be un-muted
 */
void Script::unmute(std::string name) {
    for (Character* c : characters) {
        if (_stricmp(c->getName().c_str(), name.c_str())) {
            c->setMute(false);
        }
    }
}

/**
 * Returns total numWords spoken by
 * Characters of g gender.
 * @param g gender of interest
 * @return total numWords for gender
 */
int Script::getGenderWordCount(std::string g) {
    int sum = 0;
    for (Character* c : characters) {
        if(_stricmp(c->getGender().c_str(), g.c_str()) && !c->getMute()){
            sum += c->getWordCount();
        }
    }
    return sum;
}
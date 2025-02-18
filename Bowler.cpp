#include "Bowler.h"
#include <functional>

// conster definition.
Bowler::Bowler(const std::string& name) {
	this->name = name;
}

// Returns bowler name.
std::string Bowler::getBowler() const {
    return name;
}

// Adds score obj to bowler score
void Bowler::addScore(const Score& score) {
    scores.push_back(score); 
	//just putting this into a vector of scores
}

// rtrn scores
std::vector<Score> Bowler::getScores() const {
    return scores;
}

// Prints bowler info
void Bowler::Print(std::ostream& bowl) const {
    bowl << "Name: " << name << "\n\nScores: ";
    for (const auto& s : scores) {
        bowl << s.getScore() << " ";
    }
    bowl << "\n";
}

// checks if the bowlers are the same
bool Bowler::operator==(const Bowler& other) const {
    return name == other.name;
}



#ifndef BOWLER_H
#define BOWLER_H

#include <string>
#include <vector>
#include <iostream>
#include "Score.h"

class Bowler {
private:
    std::string name;
    std::vector<Score> scores;
public:


    // constr ints names
    Bowler(const std::string& name);

    // gatter name
    std::string getBowler() const;

    // add to score
    void addScore(const Score& score);

    // getter scores
    std::vector<Score> getScores() const;

    // prints name & score
    void Print(std::ostream& os) const;

    // Overload operator== comapres bowlers by their name
    bool operator==(const Bowler& other) const;
};

// Hash functor for Bowler
struct BowlerHash {
    std::size_t operator()(const Bowler& b) const {
        // Use a standard hashing functor for strings
        return std::hash<std::string>{}(b.getBowler());
    }
};
//ima be honest with you idk what this does but it was in the instructions so i put it in

#endif // BOWLER_H

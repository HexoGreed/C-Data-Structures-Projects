
#include <iostream>
#include <unordered_map>
#include <random>
#include <ctime>
#include "Bowler.h"
#include "Score.h"
using namespace std; //I MA NOT FORGETTING STD:: IN FRONT OF UNORDED_MAP AGAIN
//even if allat is unnesecarry ^^ it works, and im afraid to break it again


#include <iostream>
#include <unordered_map>
#include <random>
#include "Bowler.h"
#include "Score.h"

int main()
{
    srand(time(0));
    // Creating Bowler and Score objects
    Bowler bowler1{ "Kidus" };
    for (int i = 0; i < 10; i++) {
        int num = rand() % 301;
        bowler1.addScore(Score{ num });
    }

    Bowler bowler2{ "Jimmy" };
    for (int i = 0; i < 10; i++) {
        int num = rand() % 301;
        bowler2.addScore(Score{ num });
    }

    // Creating an unordered_map
    unordered_map<Bowler, std::vector<Score>, BowlerHash> myDictionary;

    // Inserting key-value pairs
    myDictionary[bowler1] = bowler1.getScores();
    myDictionary[bowler2] = bowler2.getScores();

    // Iterating through the unordered_map
    for (const auto& entry : myDictionary)
    {
        entry.first.Print(cout);
        cout << endl;
    }

    return 0;
}

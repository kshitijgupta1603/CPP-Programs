#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    // Seed random number generator 
    srand(time(0));

    // Game options
    string choices[] = {"Rock", "Paper", "Scissors"};
    int playerChoice, computerChoice;

    // Game introduction
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Enter 0 for Rock, 1 for Paper, and 2 for Scissors: ";

    // Player choice
    cin >> playerChoice;

    // Validate player's input
    if (playerChoice < 0 || playerChoice > 2) {
        cout << "Invalid choice! Exiting game." << endl;
        return 1;
    }

    // Generate computer's random choice
    computerChoice = rand() % 3;

    // Display player's and computer's choices
    cout << "You chose: " << choices[playerChoice] << endl;
    cout << "The computer chose: " << choices[computerChoice] << endl;

    // Determine winner
    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
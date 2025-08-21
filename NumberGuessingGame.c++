// Number Guessing Game in C++

// Description: A simple game where the user guesses a number between 1 and 100

#include <iostream>   // For input and output
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time()

using namespace std;

// This function runs the guessing game
void guessTheNumber() {
    //  Seed the random number generator using current time
    // This ensures a new number every time the program runs
    srand(time(0));

    //  Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;

    //  Initialize variables
    int guess;       // User's guess
    int attempts = 0; // Number of attempts made

    //  Display welcome message
    cout << "--------------------------------------------" << endl;
    cout << " Welcome to the Number Guessing Game! " << endl;
    cout << " I'm thinking of a number between 1 and 100." << endl;
    cout << " Try to guess it!" << endl;
    cout << "--------------------------------------------" << endl;

    //  Start the guessing loop
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        //  Handle invalid input (e.g. letters instead of numbers)
        if (cin.fail()) {
            cin.clear();                 // Clear the error flag
            cin.ignore(10000, '\n');     // Discard the invalid input
            cout << "Invalid input! Please enter a number." << endl;
            continue;                    // Go back to start of loop
        }

        // Count the attempt
        attempts++;

        // Check the guess and give feedback
        if (guess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (guess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            // Correct guess
            cout << "--------------------------------------------" << endl;
            cout << " 🎉 Congratulations! You guessed the number! " << endl;
            cout << " It took you " << attempts << " attempts." << endl;
            cout << "--------------------------------------------" << endl;
            break; 
        }
    }
}

int main() {
    // Call the game function
    guessTheNumber();
    return 0;
}

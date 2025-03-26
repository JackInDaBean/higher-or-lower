#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Global variable definition

int i, IntInputNum, IntRandomNumber, IntPreviousNumber, IntOutcome;
char CharChoice;


// Function definition

void EntryValidation()  {   // Data validation for higher or lower - checks entry for H or L - if neither then loops till entered properly.
    while ((CharChoice != 'H') && (CharChoice != 'L') && (CharChoice != 'S'))  {
        cout << "\nERROR:\nPlease guess if the next number will be higher or lower (H for higher, L for lower and S for the same number):";
        cin >> CharChoice;
    }
}
void RandomNumber()  {      // Random Number Selector (Range of 0-100)
    IntRandomNumber = rand() % 100;
}
void PlayerWinnerCheck()  {       // Checks if the player has won
    if ((CharChoice == 'H') && (IntRandomNumber > IntPreviousNumber))  {
        cout << "\nCorrect! " << IntRandomNumber << " is higher than: " << IntPreviousNumber;
        IntOutcome = 1;
    }
    else if ((CharChoice == 'L') && (IntRandomNumber < IntPreviousNumber))  {
        cout << "\nCorrect! " << IntRandomNumber << " is lower than: " << IntPreviousNumber;
        IntOutcome = 1;
    }
}
void PlayerLossCheck()  {         // Checks if the player has lost
    if ((CharChoice == 'H') && (IntRandomNumber < IntPreviousNumber))  {       // Higher guess loss - results in fail message and program break.
        cout << "\nIncorrect! " << IntRandomNumber << " is lower than: " << IntPreviousNumber;
        cout << "\nGame Over!\nReboot and try again!";
        IntOutcome = 0;
    }
    else if ((CharChoice == 'L') && (IntRandomNumber > IntPreviousNumber))  {       // Lower guess loss - results in fail message and program break.
        cout << "\nIncorrect! " << IntRandomNumber << " is higher than: " << IntPreviousNumber;
        cout << "\nGame Over!\nReboot and try again!";
        IntOutcome = 0;
    }
}
void InputGuess()  {              // Takes the player input for their guess
    cout << "\nPlease guess if the next number will be higher or lower (H for higher and L for lower):\n";
    cin >> CharChoice;
}
void SameNumber()  {
    if ((CharChoice = 'S') && (IntPreviousNumber = IntRandomNumber))  {
        cout << "\nCorrect! " << IntRandomNumber << " is the same as: " << IntPreviousNumber;
        IntOutcome = 1;
    }
}

int main()  {
    srand(time(0));

    bool running = true;

    RandomNumber(); // Generate the random number

    cout << "\nWelcome! In this game you will have to guess whether the next number will be higher or lower than your current number \n(Max Number is 100)";
    cout << "\nYour number is: " << IntRandomNumber;

    while(running)  {                               /*Cycles through the functions defined above, if the player wins then the loop will continue, fail breaks the loop */
        IntPreviousNumber = IntRandomNumber;
        RandomNumber();
        cout << "\n" << IntRandomNumber;
        InputGuess();
        EntryValidation();
        PlayerLossCheck();
        if (IntOutcome = 0)  {
            running = false;
        } 
        PlayerWinnerCheck();
        if (IntOutcome = 1)  {
            running = true;
        }
    }
    
}
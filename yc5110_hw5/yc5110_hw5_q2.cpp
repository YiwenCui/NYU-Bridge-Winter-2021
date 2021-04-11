#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int randGuess;
    int startRange, endRange, guessLeft;
    int myGuess;

    startRange = 1;
    endRange = 100;

    srand(time(0));
    randGuess = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
    for (guessLeft = 5; guessLeft > 0; guessLeft--)
    {

        cout << "Range: [" << startRange << " , " << endRange << "], Number of guesses left: " << guessLeft << endl;
        cout << "Your guess: ";
        cin >> myGuess;
        if (myGuess < randGuess && guessLeft > 1)
        {
            cout << "Wrong! My number is bigger" << endl;
            startRange = myGuess + 1;
            if (guessLeft > 1)
            {
                cout << endl;
            }
        }
        else if (myGuess > randGuess && guessLeft > 1)
        {
            cout << "Wrong! My number is smaller" << endl;
            endRange = myGuess - 1;
            if (guessLeft > 1)
            {
                cout << endl;
            }
        }
        else if (myGuess == randGuess)
        {
            cout << "Congrats! you guessed my number in " << 6 - guessLeft << " guesses." << endl;
            cout << endl;
            break;
        }

        if (guessLeft == 1)
        {
            cout << "Out of guesses! My number is " << randGuess << endl;
        }
    }
    return 0;
}

// This program will play a hangman game
// The words will be taken from a file and displayed as blank spaces on
//	ouput
// As each letter guessed, all of the same letters in the word will appear
// The player loses if all of the limbs are drawn
// The player wins if all of the letter's are guessed
// 
// It will command prompt style so >> will indicate user input and the user
//	will have certain commands including guess, help and so on
#include "hangman.h" 
#include "word.h"

#include <iostream>
#include <random>
using namespace std;

const int filePromptSize = 210;

int main() {
  bool run = true;

  cout << "Welcome to Hangman!" << endl;

  while (run) {
    random_device myEngine;
    uniform_int_distribution<int> distro(1, filePromptSize);

    word newWord(distro(myEngine));
    hangman newHangman;

    char ans;

    bool ansGuessStatus = false;

    // guessing loop
    while (!newHangman.isDead() && !newWord.isDone()) {
      newWord.showPrompt();
      newWord.showGuesses();

      cout << newHangman.getLimbs() << " out of 5" << endl;

      cout << "\n>>";
      cin >> ans;

      ansGuessStatus = newWord.isGuessed(ans);

      if (!newWord.isInPrompt(ans) && !ansGuessStatus) {
        newHangman.addLimbs();
      }
    }

    if (newHangman.isDead()) {
      cout << "You lose." << endl;
    }
    else {
      cout << "You win." << endl;
    }

    newWord.revealWord();

    char userAns;

    cout << "Would you like to continue?" << endl << "Yes or no (y/n): ";
    cin >> userAns;

    if (userAns == 'n' || userAns == 'N') {
      run = false;
    }
  }
}

// this function will handle all user inputs that involve char
char validateCharInput();

// OK now this is epic.
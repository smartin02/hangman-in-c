#include "word.h"

#include <fstream>
#include <string>

using namespace std;

word::word() {
  originPrompt = "";
  displayPrompt = "";
  promptSize = 0;

  for (int i = 0; i < 10; i++) {
    displayPrompt[i] = 0;
  }
}

word::word(int n) {
  // open file
  // go to line n
  // getline
  // copy string onto prompt
  ifstream file(filePromptName);
  string line;
  int i;

  for (i = 0; i < n; i++) {
    getline(file, line);
  }

  promptSize = line.length();

  originPrompt = line;
  displayPrompt = "";

  for (i = 0; i < promptSize; i++) {
    if (originPrompt[i] == ' ') {
      displayPrompt = displayPrompt + ' ';
    }
    else {
      displayPrompt = displayPrompt + '_';
    }
  }

  for (i = 0; i < 26; i++) {
    guessedChars[i] = '\0';
  }
  numGuesses = 0;
}

void word::addToGuesses(char guess) {
  guessedChars[numGuesses] = tolower(guess);
  numGuesses++;
}

void word::findCharPos(char guess) {
  // parse through originPrompt
  //  if the char is the same as guess, save the index into an array
  // if the array is empty, return array {-1}
  for (short i = 0; i < 26; i++) {
    if (tolower(guess) == guessedChars[i]) {
      cout << "\nYou already guessed that!\n";
      return;
    }
  }

  addToGuesses(guess);

  short i, j;

  posSize = 0;
  for (i = 0; i < 10; i++) {
    guessPos[i] = 0;
  }

  for (i = 0, j = 0; i < promptSize; i++) {
    if (tolower(originPrompt[i]) == tolower(guess)) {
      guessPos[j] = i;
      posSize++;
      j++;
    }
  }

  if (j == 0) {
    guessPos[0] = -1;
    j++;
  }
  
  posSize = j;
}

void word::updateDisPrompt(char guess) {
  // change each pos with guessed char
  for (int i = 0; i < posSize; i++) {
    displayPrompt[guessPos[i]] = originPrompt[guessPos[i]];
  }
}

bool word::isInPrompt(char guess) {
  findCharPos(guess);

  if (guessPos[0] == -1) {
    return false;
  }

  updateDisPrompt(guess);
  return true;
}

bool word::isGuessed(char guess) {
  for (short i = 0; i < numGuesses; i++) {
    if (tolower(guess) == guessedChars[i]) {
      return true;
    }
  }
  return false;
}

void word::showGuesses() {
  cout << endl << "Guesses:\n";
  for (int i = 0; i < numGuesses; i++) {
    cout << guessedChars[i] << ", ";
  }
  cout << endl;
}

void word::showPrompt() {
  cout << endl;
  
  for (int i = 0; i < promptSize; i++) {
    cout << displayPrompt[i] << ' ';
  }
  
  cout << endl;
}

void word::revealWord() {
  cout << endl << "The answer is " << originPrompt << endl << endl;
}

bool word::isDone() {
  if (displayPrompt == originPrompt) {
    return true;
  }
  else {
    return false;
  }
}
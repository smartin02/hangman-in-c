#ifndef HANGMAN_HEADER_WORD_H_
#define HANGMAN_HEADER_WORD_H_

// There is a word that at first the player doesn't know
// The word is slowly revealed as the char are guessed
// The word originates from a file
// the word class will also calculate the score and pass it to the userProfile

// MAKE GUESS CLASS INSTEAD OF HAVING IT IN WORD

#include <iostream> 

class word {
private:
  // private variables
  unsigned short promptSize;
  unsigned short posSize;
  std::string originPrompt;       // the original prompt from the file
  std::string displayPrompt;      // what the user sees
  std::string filePromptName = "movies.txt";
  short guessPos[10];             // an array of pos the guess is correct
  char guessedChars[26];          // the guesses that can no longer be guessed
  short numGuesses;

  // private functions
  void findCharPos(char);       // will find the position(s) of a given char
                                //  returns -1 if not found
  void updateDisPrompt(char);   // updates the displayPrompt
  void addToGuesses(char);
  void resetGuesses();

public:
  // constructor
  word();
  word(int);  // get prompt from file
  
  // public variables
  void showGuesses();       // displays the guesses
  void showPrompt();        // displays the displayPrompt
  void revealWord();
  bool isInPrompt(char);    // if the guess is true; will also update prompt
  bool isGuessed(char);     // if the char is in guessedChar
  bool isDone();
};

#endif // HANGMAN_HEADER_WORD_H_
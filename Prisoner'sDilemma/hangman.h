#ifndef HANGMAN_HEADER_HANGMAN_H_
#define HANGMAN_HEADER_HANGMAN_H_

const unsigned short kMaxLimbs = 5;

class hangman {
private:
  // hangman variables
  unsigned short numOfLimbs;
  bool lifeStatus;

  // private funciton
  void checkStatus();

public:
  // hangman constructor
  hangman();

  // hangman functions
  bool isDead();
  unsigned short getLimbs();
  void addLimbs();
};

#endif  // HANGMAN_HEADER_HANGMAN_H_
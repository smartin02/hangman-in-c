#include "hangman.h"

hangman::hangman() {
  numOfLimbs = 0;
  lifeStatus = true;
}

void hangman::addLimbs() {
  numOfLimbs++;
  checkStatus();
}

void hangman::checkStatus() {
  if (numOfLimbs == kMaxLimbs) {
    lifeStatus = false;
  }
}

bool hangman::isDead() {
  return !lifeStatus;
}

unsigned short hangman::getLimbs() {
  return numOfLimbs;
}
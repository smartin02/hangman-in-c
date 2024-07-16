#ifndef HANGMAN_HEADER_COMMAND_H_
#define HANGMAN_HEADER_COMMAND_H_

#include <iostream>

using namespace std;

class command {
private:
  string userIn;

public:
  void runCommand();

};

// the function will take in command
// check for first keyword ignoring spaces before first char
// then for the specific keyboard, check the input as is required
// if all is true execute specific command

// Some keywords I need
// start
// guess
// stop
// 

#endif // HANGMAN_HEADER_COMMAND_H_
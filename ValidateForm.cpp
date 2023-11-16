#ifndef VALIDATE_FORM_CPP
#define VALIDATE_FORM_CPP

#include "ValidateForm.h"
#include <iostream>
#include <string>

using namespace std;

ValidateForm::ValidateForm() { // default constructor
}

bool ValidateForm::checkForm() {

  if (stoi(registrationInfo[2]) < 18) {
    cout << "User is too young to vote. \n"; // min age is 18
    return 0;                                // returns zero to exit code
  }
  if (registrationInfo[4].length() < 9) {
    cout << "SSN is invalid. \n"; // A social security number is 9 digits, so if
                                  // the user types a SSN that is too short,
    return 0;                     // this message is displayed
  }
  if (registrationInfo[5] == "y" || registrationInfo[5] == "Y") {
    cout << "User cannot vote because they are a felon. \n"; // if user answered
                                                             // Y or y to being
                                                             // a felon,
  } // they won't be able to vote
  else {
    cout << "User is eligible to vote. \n"; // if everything passes, they are
                                            // eligible and it returns 1
    return 1;
  }

  return false;
}

#endif

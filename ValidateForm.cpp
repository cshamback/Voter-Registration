#ifndef VALIDATE_FORM_CPP
#define VALIDATE_FORM_CPP

#include "ValidateForm.h"
#include <iostream>
#include <string>

using namespace std;

ValidateForm::ValidateForm() { // default constructor
  formIsValid = false;
}

bool ValidateForm::checkForm(string* form) {

  if (stoi(form[2]) < 18) {
    cout << "User is too young to vote. \n"; // min age is 18
    formIsValid = false;                               // returns zero to exit code
  } else if (form[4].length() < 9 || registrationInfo[4].length() > 9) {
    cout << "SSN is invalid: wrong length. \n"; // A social security number is 9 digits, so if
                                  // the user types a SSN that is too short,
    formIsValid = false;                     // this message is displayed
  } else if (form[5] == "1") {
    cout << "User cannot vote because they are a felon. \n"; // if user answered
                                                             // Y or y to being
                                                             // a felon,
    // they won't be able to vote
  } else {
    cout << "User is eligible to vote. \n"; // if everything passes, they are
                                            // eligible and it returns 1
    formIsValid = true;
  }

  return formIsValid;
}

#endif

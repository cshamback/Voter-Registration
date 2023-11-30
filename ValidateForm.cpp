#ifndef VALIDATE_FORM_CPP
#define VALIDATE_FORM_CPP

#include "ValidateForm.h"
#include <iostream>
#include <string>

using namespace std;

ValidateForm::ValidateForm() { // default constructor
  formIsValid = false;
}

bool ValidateForm::checkForm(string *form) {

  // changed from a series of if stmts to a series of if/else if stmts
  // since only one of these needs to be incorrect to invalidate the entire
  // form, we don't need to look at all of them.
  if (stoi(form[2]) < 18) {
    cout << "User is too young to vote. \n"; // min age is 18
    formIsValid = false;                     // returns zero to exit code
    
  } 
    if (form[4] == "0") {
         formIsValid = true;
      //  cout << "User does not have a SSN. \n"; 
       // return formIsValid;
     }
  else if (form[4].length() < 9 || form[4].length() > 9) {
    cout << "SSN is invalid. \n"; // A social security number is 9 digits, so if
    // the user types a SSN that is too short or too long,
    // this message is displayed
    formIsValid = false;
  } else if (form[5] == "1") {
    cout
        << "User cannot vote because they have committed a felony. \n"; // if
                                                                        // user
                                                                        // answered
                                                                        // Y or
                                                                        // y to
                                                                        // being
                                                                        // a
                                                                        // felon,
    // they won't be able to vote
    formIsValid = false;
  } else {
    cout << "SSN, age, and felony status are valid. \n"; // if everything
                                                         // passes, they are
    // eligible and it returns 1
    formIsValid = true;
  }

  if(!formIsValid) {
    cout << "You will not be issued a voter ID. Your application has been rejected." << endl;
  }

  return formIsValid;
}

#endif

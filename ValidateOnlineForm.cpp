#ifndef VALIDATE_ONLINE_FORM_CPP
#define VALIDATE_ONLINE_FORM_CPP

#include "ValidateOnlineForm.h"
#include <iostream>
#include <string>

using namespace std;

// define methods from class diagram here
// example:
// returnType ClassName::methodName(parameters) { definition }

ValidateOnlineForm::ValidateOnlineForm() { // default constructor
  formIsValid = false;
}

bool ValidateOnlineForm::checkResidency() {
  if (registrationInfo[3].length() < 5 || registrationInfo[3].length() > 5) {
    cout << "Zip code is not the correct length " << endl;
    return false;
  }

  else if (registrationInfo[3].compare(0, 2, "36") == 0) {
    formIsValid = true;
    cout << "Zip code is valid." << endl;
    return true;
  }

  else {
    cout << "Zip code is not from Alabama" << endl;
    return false;
  }
}

#endif

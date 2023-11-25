#ifndef VALIDATE_OVERSEAS_FORM_CPP
#define VALIDATE_OVERSEAS_FORM_CPP

#include "ValidateOverseasForm.h"
#include <iostream>
#include <string>

using namespace std;

// define methods from class diagram here
// example:
// returnType ClassName::methodName(parameters) { definition }

ValidateOverseasForm::ValidateOverseasForm() { // default constructor
  formIsValid = false;
}

bool ValidateOverseasForm::checkMilitary() {
  cout << "Are you overseas and eligible to vote? (Please answer Y/N) " << endl;
  cin >> overseas;

  if (overseas == "y" || overseas == "Y") {
    formIsValid = true;
    return 1;
  } else if (overseas == "n" || overseas == "N") {
    formIsValid = false;
    return 0;
  } else {
    cout << "Invalid answer. Please answer Y/N " << endl;
    return 0;
  }

  return false;
}

#endif

#ifndef VALIDATE_OVERSEAS_FORM_CPP
#define VALIDATE_OVERSEAS_FORM_CPP

#include "ValidateOverseasForm.h"
#include <iostream>
#include <string>

using namespace std;

ValidateOverseasForm::ValidateOverseasForm() { // default constructor
  formIsValid = false;
}

bool ValidateOverseasForm::checkMilitary() {
  while(i <= 0){
  cout << "Are you overseas and eligible to vote? (Please answer Y/N) " << endl;
  cin >> overseas;

  if (overseas == "y" || overseas == "Y") {
    i++;
    formIsValid = true;
  } else if (overseas == "n" || overseas == "N") {
    formIsValid = false;
    cout << "Ineligible to vote." << endl;
    return formIsValid;
  } else {
    cout << "Invalid answer. Please answer Y/N " << endl;
  }
 } 
  return formIsValid;
}

#endif

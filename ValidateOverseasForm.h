#ifndef VALIDATE_OVERSEAS_FORM_H
#define VALIDATE_OVERSEAS_FORM_H

#include "ValidateForm.h"

using namespace std;

class ValidateOverseasForm
    : public ValidateForm { // extends parent class ValidateForm
public:
  // put attributes and method headers here:
  ValidateOverseasForm(); // default constructor
  bool checkMilitary();

  string registrationInfo[6]; // fName, lName, age, residency, ssn, felony
  bool formIsValid;
  string overseas;
  int i; 
};

#endif

#ifndef VALIDATE_ONLINE_FORM_H
#define VALIDATE_ONLINE_FORM_H

#include "ValidateForm.h"

using namespace std;

class ValidateOnlineForm
    : public ValidateForm // inherits from parent class ValidateForm
{
public:
  ValidateOnlineForm(); // default constructor

  string registrationInfo[6]; // fName, lName, age, residency, ssn, felony
  bool formIsValid;
  bool checkResidency(string *formInfo);
};

#endif

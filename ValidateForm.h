#ifndef VALIDATE_FORM_H
#define VALIDATE_FORM_H

/*
Has two child classes, ValidateOnlineForm and ValidateOverseasForm.
These two classes share some attributes and methods. They are the strategies
used to validate the form.
  */

#import <string>

using namespace std;

class ValidateForm {
public:
  ValidateForm(); // default constructor

  string registrationInfo[6]; // fName, lName, age, residency, ssn, felony
  string formType;            // same as registrationInfo[3]\
  bool formIsValid;

  bool checkForm(); // also acts as a getter method
};

#endif

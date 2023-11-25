/*
  main.cpp: DRIVER FILE
  Implement Voter Registration classes to get user input, validate forms,
  and return a result.
*/

#include <iostream>
#include <string>

#include "RegistrationManager.h"
#include "ValidateForm.h"
#include "ValidateOnlineForm.h"
#include "ValidateOverseasForm.h"
#include "ValidationStrategy.h"
#include "VoterForm.h"

using namespace std;

string form[6]; // holds filled out data, can be copied as needed
bool formIsValid;

void setFormData(string *ogForm, string *newForm) {
  // c++ does not allow for direct assignment from one list to another
  // instead, we have to assign one item at a time
  for (int i = 0; i < 6; i++) {
    newForm[i] = ogForm[i];
  }
}

int main() {

  // create and fill out registration form
  VoterForm voterForm;     // Creates a VoterForm object
  voterForm.fillOutForm(); // Opens prompts for user to fill out a form
  setFormData(voterForm.getFormInfo(), form);

  // ValidateForm
  //  get form from voterForm object
  ValidateForm validateForm;
  setFormData(form, validateForm.registrationInfo);
  formIsValid = validateForm.checkForm();

  // ValidationStrategy
  //  choose an algorithm to validate the form
  // ignoring this for now, will add in sprint 3
  
  ValidationStrategy strategy;
  if (voterForm.getFormInfo()[0] == "Online") {
    strategy.chooseOnlineStrategy(new ValidateOnlineForm());
  } else { // overseas
    strategy.chooseOverseasStrategy(new ValidateOverseasForm());
  } 

  // RegistrationManager
  RegistrationManager mgr; // empty constructor/no default values
  if (validateForm.formIsValid) {
    // store ID and form info in registrationDB
    cout << "Your new voter ID: " << mgr.genID() << endl;
    mgr.storeInfo(form, "Online");
  } else {
    cout << "Something went wrong. Your application has been rejected." << endl;
  }

  return 0;
}

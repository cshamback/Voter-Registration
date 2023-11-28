/*
  main.cpp: DRIVER FILE
  Implement Voter Registration classes to get user input, validate forms,
  and return a result.
*/

#include <iostream>
#include <memory> // smart ptrs - should reduce memory usage
#include <string>

#include "RegistrationManager.h"
#include "ValidateForm.h"
#include "ValidateOnlineForm.h"
#include "ValidateOverseasForm.h"
#include "ValidationStrategy.h"
#include "VoterForm.h"

using namespace std;

bool formIsValid;

int main() {

  // create and fill out registration form
  VoterForm voterForm;     // Creates a VoterForm object
  voterForm.fillOutForm(); // Opens prompts for user to fill out a form

  // ValidateForm
  //  get form from voterForm object
  ValidateForm validateForm;
  formIsValid = validateForm.checkForm(voterForm.getFormInfo());

  // ValidationStrategy
  //  choose an algorithm to validate the form

  /*
    Using smart pointers to create Online and Overseas objects - may help reduce
    memory usage
    */

  shared_ptr<ValidationStrategy> strategy = make_unique<ValidationStrategy>();
  bool strategyIsValid =
      false; // checks whether choose____Strategy evaluated to true or false
  if (voterForm.formType == "Online") {
    shared_ptr<ValidateOnlineForm> online = make_unique<ValidateOnlineForm>();

    strategy->chooseOnlineStrategy(online.get(), voterForm.getFormInfo());

    strategyIsValid = online->formIsValid;
  } else { // overseas;
    shared_ptr<ValidateOverseasForm> overseas =
        make_unique<ValidateOverseasForm>();
    strategyIsValid = strategy->chooseOverseasStrategy(overseas.get());
    // cout << "Chose overseas strategy. Evaluation: " << strategyIsValid <<
    // endl;
  }

  // RegistrationManager
  RegistrationManager mgr; // empty constructor/no default values
  if (validateForm.formIsValid && strategyIsValid) {
    // store ID and form info in registrationDB
    cout << "Your new voter ID: " << mgr.genID() << endl;
    mgr.storeInfo(voterForm.getFormInfo(), "Online");
  } else {
    cout << "Something went wrong. Your application has been rejected." << endl;
  }

  return 0;
}

#ifndef VOTER_FORM_CPP
#define VOTER_FORM_CPP

#include "VoterForm.h"
#include <iostream>
#include <string>

using namespace std;

/*
Voter form contents indexes:
0. First name
1. Last name
2. Age
3. Address
4. SSN
5. Felony status
*/

VoterForm::VoterForm() {} // Default constructor

void VoterForm::fillOutForm() {
  string felonyStatus; // Is the user a felon?

  cout << "Which form would you like to fill out? (Overseas, Online, etc.)"
       << endl;
  getline(cin, formType);

  cout << "Enter your first name: " << endl; // Gets the first name of the user
  cin >> formRegistrationInfo[0];
  fNameOutput = "Accepted.";

  cout << "Enter your last name: " << endl; // Gets the last name of the user
  cin >> formRegistrationInfo[1];
  lNameOutput = "Accepted.";

  cout << "Enter your age: " << endl; // Gets the age of the user
  cin >> formRegistrationInfo[2];
  ageOutput = "Accepted.";

  /*
  If the user chooses the overseas form, they should be able to put in a "0"
  for their ZIP code to indicate that they don't have a ZIP code. Otherwise,
  this would be an invalid value.
  */
  cin.ignore();
  cout << "Enter your ZIP code " << endl; // Gets the ZIP code of the user
  getline(cin, formRegistrationInfo[3]);
  zipOutput = "Accepted.";

  cout << "Enter your SSN: " << endl; // Gets the SSN of the user
  cin >> formRegistrationInfo[4];
  ssnOutput = "Accepted.";

  // Asks whether the user is a felon or not
  cout << "Have you committed a felony? (Y/N)" << endl;
  cin >> felonyStatus;
  // Ensures that the value entered is either "Y" or "N" (uppercase or
  // lowercase)
  while (felonyStatus != "Y" && felonyStatus != "N" && felonyStatus != "y" &&
         felonyStatus != "n") {
    cout << "Invalid value." << endl;
    cout << "Have you committed a felony? (Y/N)" << endl;
    cin >> felonyStatus;
  }
  formRegistrationInfo[5] = felonyStatus;
  felonyOutput = "Accepted.";
}

string *VoterForm::getFormInfo() { // returns a pointer to formRegistrationInfo
  return formRegistrationInfo;
}

#endif

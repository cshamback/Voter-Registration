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
   bool validFName = false;
  bool validLName = false;
  int index = 0;

  // makes sure user only enters valid input
  cout << "Which form would you like to fill out? 1) Overseas 2) Online "
          "(Please input a 1 or 2)"
       << endl;
  int temp;
  cin >> temp;
  while (temp != 1 && temp != 2) {
    cout << "That is not a valid input. Please input 1 for Overseas or 2 for "
            "Online. "
         << endl;
    cin >> temp;
  }
  if (temp == 1) {
    formType = "Overseas";
  } else {
    formType = "Online";
  }

  cout << "Enter your first name: " << endl; // Gets the first name of the user
  cin >> formRegistrationInfo[0];
  while (validFName ==
         false) { // Checks if the first name does not contain any numbers
    if (isdigit(formRegistrationInfo[0][index])) {
      cout << "Invalid first name." << endl;
      cout << "Enter your first name: "
           << endl; // Gets the first name of the user
      cin >> formRegistrationInfo[0];
      index = 0;
    } else {
      index++;
      // The index is at the end of the name, so it must not have any numbers
      if (index == formRegistrationInfo[0].length()) {
        validFName = true;
      }
    }
  }
  fNameOutput = "Accepted.";

  cout << "Enter your last name: " << endl; // Gets the last name of the user
  cin >> formRegistrationInfo[1];
  while (validLName ==
         false) { // Checks if the last name does not contain any numbers
    if (isdigit(formRegistrationInfo[1][index])) {
      cout << "Invalid last name." << endl;
      cout << "Enter your last name: "
           << endl; // Gets the first name of the user
      cin >> formRegistrationInfo[1];
      index = 0;
    } else {
      index++;
      // The index is at the end of the name, so it must not have any numbers
      if (index == formRegistrationInfo[1].length()) {
        validLName = true;
      }
    }
  }
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
  cout << "Enter your ZIP code: " << endl; // Gets the ZIP code of the user
  getline(cin, formRegistrationInfo[3]);
  zipOutput = "Accepted.";

  cout << "Enter your SSN as a single number with no spaces or dashes (ex: "
          "123456789): "
       << endl; // Gets the SSN of the user
  cin >> formRegistrationInfo[4];
  ssnOutput = "Accepted.";

  // Asks whether the user is a felon or not
  cout << "Have you committed a felony? (Yes or No)" << endl;
  cin >> felonyStatus;
  // Ensures that the value entered is either "Yes" or "No" (uppercase or
  // lowercase)
  while (felonyStatus != "Yes" && felonyStatus != "No" &&
         felonyStatus != "yes" && felonyStatus != "no") {
    cout << "Invalid value." << endl;
    cout << "Have you committed a felony? (Please enter 1 for Yes or 2 for No.)" << endl;
    cin >> felonyStatus;
  }
  formRegistrationInfo[5] = felonyStatus;
  felonyOutput = "Accepted.";
}

string *VoterForm::getFormInfo() { // returns a pointer to formRegistrationInfo
  return formRegistrationInfo;
}

#endif

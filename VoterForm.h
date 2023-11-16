#ifndef VOTER_FORM_H
#define VOTER_FORM_H

#include <string>

using namespace std;

class VoterForm {
public:
  VoterForm(); // Default constructor
  void fillOutForm(); // gets user input to fill out registration form
  string* getFormInfo(); // returns a pointer to formRegistrationInfo

  // First name, last name, age, residency, SSN, and felony status
  string formRegistrationInfo[6];
  string formType; // Overseas, Online, etc.
};

#endif

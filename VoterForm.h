#ifndef VOTER_FORM_H
#define VOTER_FORM_H

#import <string>

using namespace std;

class VoterForm {
public:
  VoterForm();
  void fillOutForm();

  string formRegistrationInfo[6]; // fName, lName, age, residency, ssn, felony
  string formName;                // Overseas, Online, xxxxx
};

#endif

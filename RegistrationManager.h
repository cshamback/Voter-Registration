#ifndef REGISTRATION_MANAGER_H
#define REGISTRATION_MANAGER_H

#import <string>
using namespace std;

class RegistrationManager {
public:
  RegistrationManager() noexcept;
  
  int genID();
  void storeInfo(string *voterForm, string formType);

  string registrationDB[8];
  int voterID = 0;
};

#endif

#ifndef REGISTRATION_MANAGER_H
#define REGISTRATION_MANAGER_H

#import <string>
using namespace std;

class RegistrationManager {
public:
  RegistrationManager() noexcept;
  
  int genID();
  void storeInfo();
  int returnSuccess();

  string managerRegistrationInfo[6];
  string registrationDB[9];
  int voterID = 0;
  string form;
};

#endif

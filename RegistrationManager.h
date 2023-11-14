#ifndef REGISTRATION_MANAGER_H
#define REGISTRATION_MANAGER_H

#import <string>
using namespace std;

class RegistrationManager {
public:
  // noexcept prevents unexpected termination 
  RegistrationManager() noexcept;

  void genID();
  void storeInfo();
  int returnSuccess();

  string managerRegistrationInfo[6];
  string registrationDB[9];
  int voterID;
  string form;
};

#endif

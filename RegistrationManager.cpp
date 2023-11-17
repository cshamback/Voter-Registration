#ifndef REGISTRATION_MANAGER_CPP
#define REGISTRATION_MANAGER_CPP

#include "RegistrationManager.h"
#include <iostream>
#include <string>

using namespace std;

// should also set form variable - get from VoterForm object
RegistrationManager::RegistrationManager() noexcept { voterID = -1; }

int RegistrationManager::genID() { 
  voterID = voterID +1; 
  return voterID;
}

void RegistrationManager::storeInfo() {
  registrationDB[0] = voterID;
  registrationDB[1] = form; // form type: online or overseas (need to set using constructor)
  for (int i = 2; i < 9; i++) {
    int j = 0;
    registrationDB[i] = managerRegistrationInfo[j];
    j++;
  }
}

int RegistrationManager::returnSuccess() { return voterID; }

#endif

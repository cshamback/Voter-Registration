#ifndef REGISTRATION_MANAGER_CPP
#define REGISTRATION_MANAGER_CPP

#include "RegistrationManager.h"
#include <iostream>
#include <string>

using namespace std;

// should also set form variable - get from VoterForm object
RegistrationManager::RegistrationManager() noexcept { voterID = 0; }

int RegistrationManager::genID() { 
  voterID = voterID +1; 
  return voterID;
}

void RegistrationManager::storeInfo() {
  registrationDB[0] = voterID;
  registrationDB[1] = form; // form type: online or overseas (need to set using constructor)
  for (int i = 2; i < 9; i++) {
        registrationDB[i] = voterForm[i - 2];
    }
}

#endif

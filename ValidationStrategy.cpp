// ValidationStrategy.cpp
#include "ValidationStrategy.h"
#include "ValidateOnlineForm.h"
#include "ValidateOverseasForm.h"

#include <iostream>

using namespace std;

ValidationStrategy::ValidationStrategy() {}

bool ValidationStrategy::chooseOnlineStrategy(ValidateOnlineForm *form,
                                              string *formInfo) {
  form->checkResidency(formInfo);
  return form->formIsValid;
}

bool ValidationStrategy::chooseOverseasStrategy(ValidateOverseasForm *form) {
  form->checkMilitary();
  return form->formIsValid;
}

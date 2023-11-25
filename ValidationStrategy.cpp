// ValidationStrategy.cpp
#include "ValidationStrategy.h"
#include "ValidateOnlineForm.h"
#include "ValidateOverseasForm.h"

ValidationStrategy::ValidationStrategy() {}

bool ValidationStrategy::chooseOnlineStrategy(ValidateOnlineForm *form) {
  return form->checkResidency();
}

bool ValidationStrategy::chooseOverseasStrategy(ValidateOverseasForm *form) {
  return form->checkMilitary();
}

// ValidationStrategy.h
#ifndef VALIDATION_STRATEGY_H
#define VALIDATION_STRATEGY_H

#include "ValidateOnlineForm.h"
#include "ValidateOverseasForm.h"
#include <string>

// base class for validation strategies
class ValidationStrategy {
public:
  ValidationStrategy();

  bool chooseOnlineStrategy(ValidateOnlineForm *form, string *formInfo);
  bool chooseOverseasStrategy(ValidateOverseasForm *form);
};

#endif

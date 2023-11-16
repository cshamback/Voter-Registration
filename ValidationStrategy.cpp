// ValidationStrategy.cpp
#include "ValidationStrategy.h"

//warning I tried to create a getter and setter method but I think we need to rework the address portion in
//validate form since the diagram only has getlocation() for this class
//needs a lot of tweaking so I'll probably scrap this but the code runs


void ValidationStrategy::setLocation(const std::string& loc) {
    location = loc;
}

std::string ValidationStrategy::getLocation() const {
    return location;
}

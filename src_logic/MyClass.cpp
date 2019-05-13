#include "MyClass.h"

MyClass::MyClass(double value){
    this->value_ = value;
}

double MyClass::getValue()
{
  return this->value_;
}
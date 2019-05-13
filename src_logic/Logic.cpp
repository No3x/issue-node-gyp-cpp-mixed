#include "Logic.h"
#include "MyClass.h"

#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

void doWork(const char* name, const char* id, char * buffer) {
    MyClass cls = MyClass(1.3);
    std::ostringstream oss;
    oss << "value: ";
    oss << cls.getValue();
    std::string pw = oss.str();
    sprintf(buffer, "%s", pw.c_str());
}

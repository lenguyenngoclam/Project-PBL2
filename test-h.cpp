#include "test.h"
#include <iostream>

using namespace std;

void Test::foo(){
    cout << "Test foo";
}

void derivedTest::foo(){
    cout << "Derived foo";
}
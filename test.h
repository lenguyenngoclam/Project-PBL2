#include <iostream>

using namespace std;

class Test{
    public :
        virtual void foo();
};

class derivedTest : public Test{
    public :
        void foo() override;
};


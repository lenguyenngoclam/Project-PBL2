#include <iostream>
#include "SetTemplate.cpp"

using namespace std;

int main(){

    Set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    Set<int> s1;
    s1 = s;
    cout << s1 << endl;

    cout << s;    
    return 0;
}
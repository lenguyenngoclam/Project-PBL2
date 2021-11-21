#include <iostream>
#include <initializer_list>
#include "SetTemplate.cpp"

using namespace std;

int main(){

    Set<int> s(4);
    cout << s << endl;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    cout << s << endl;
    s[2] = 5;
    cout << s[2];
    cout << s.findEle(1);

    return 0;
}
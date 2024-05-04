// Abstarction and virtual keywords in the c++ 

#include<bits/stdc++.h>
using namespace std;

 class Base {
public:
// virtual keyword is for overriding the method and dynamic binding i.e access to this fucntion using the base pointer
    virtual void virtualFunction() {
        cout<<"this is the function call in Base class"<<endl;
    }
};

class Derived : public Base {
public:
    void virtualFunction() {
         cout<<"this is the function call in derived class"<<endl;
    }
};



int main() {
    Base* basePointer;

    Base baseObject;
    Derived derivedObject;

    basePointer = &baseObject;
    basePointer->virtualFunction(); // Calls the base class implementation

    basePointer = &derivedObject;
    basePointer->virtualFunction(); // Calls the derived class implementation, not the derived class implementation

    return 0;
}

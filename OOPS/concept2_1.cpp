// Abstarction and without virtual keywords in the c++ 

#include<bits/stdc++.h>
using namespace std;

 class Base {
public:
 
      void virtualFunction() {
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
    Derived* DerivedPointer;

    Base baseObject;
    Derived derivedObject;
    //static binding of the pointer
    DerivedPointer = &derivedObject;
    DerivedPointer->virtualFunction(); // Calls the base class implementation
    // down line throws an error
    // DerivedPointer = &baseObject;
   
    DerivedPointer->virtualFunction(); // Calls the derived class implementation, not the derived class implementation

    return 0;
}

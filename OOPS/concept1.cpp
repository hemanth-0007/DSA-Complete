// Data encapsulation in the c++ 

#include<bits/stdc++.h>
using namespace std;

class Person{
    private:
        int age;
        string name;
        string address;
    public:
        void setName(string str){
            if(str == "") {
                cout<<"error enter proper name";
                return;
            }
            string res = "";
            for(auto ch: str){
                if(ch == ' ')continue;
                res += ch;
            }
            this->name = res;
        }
        string getName(){
            return name;
        }
};



int main()
{
    Person p;
    string name;
    cout<<"Enter your name: \n";
    cin>>name;
    // Here i wil be getting my name in my private variable according to my requirement without 
    //giving any access to them
    p.setName(name);
    cout<<"Your name is : "<<p.getName();

return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
 vector<int> v;
 char ch ;
 int k;

    while (1)
    {
        cin>>ch;
        switch (ch)
        {
        case 'i':
            cin>>k;
            v.push_back(k);
            break;
        case 'p':
            v.pop_back();
            break;
        case 's':
            cout<<v.size()<<endl;
            break;
        case 'm':
            cout<<v.max_size()<<endl;
            break;
        case 'r':
            cin>>k;
            v.resize(k);
            cout<<"The size is :"<<v.size()<<endl<<"The elements are :";
            for(auto itr : v){
                cout<<itr<<" ";
            }
            break;
        case 'f':
            if(v.empty()) 
                cout<<" the vector is empty"<<endl;
            else
                cout<<"vector is not empty"<<endl;
            break;
        case 'u':
            cout<<"The front element is : "<<v.front()<<endl;
            break;
        case 'v':
            cout<<"The last element is : "<<v.back()<<endl;
            break;
        case 'd':
            for (auto it = v.begin(); it != v.end(); it++)
            {
                cout<<*(it)<<" ";
            }
            cout<<endl;
            
            break;
        case 'c':
            v.clear();
            break;
        case 't':
        // Inseerting at the front

            cin>>k;
            v.insert(v.begin(),k);
            break;
        case 'b':
        // Inseerting at the end
            cin>>k;
            v.insert(v.end(),k);
            break;
            

        case 'e':
            return 0;
            break;
        }
    }
    







return 0;

}
#include<bits/stdc++.h>
using namespace std;
int main()
{

vector<int> vec1(5);
for (int i = 0; i < vec1.size(); i++) vec1.at(i) = i;
vector<int> :: iterator it = vec1.begin();
// cout<<*(it + 1)<<endl;
cout<<"Before Reverse"<<endl;
for (int i = 0; i < vec1.size(); i++) cout<<vec1.at(i)<<" ";
cout<<endl;

reverse(vec1.begin(), vec1.begin() + 2);
cout<<"After Reverse"<<endl;
for (int i = 0; i < vec1.size(); i++) cout<<vec1.at(i)<<" ";




return 0;
}
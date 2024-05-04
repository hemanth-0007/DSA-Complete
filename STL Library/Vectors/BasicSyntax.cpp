#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<" ";
    }

}


int main()
{
  vector<int> vec1;// Zero Size vector 

  int size;
//   cin>>size;
  for (int i = 0; i < size; i++)
  {
    vec1.push_back(i);
  }
//   display(vec1);

vector<int> vec2(4);//vector with size 4
 vector<int> :: iterator it = vec2.begin();

for (int i = 0; i < vec2.size(); i++)
{
    vec2.at(i)  = i;
}//Assing the values of the vector

display(vec2);

return 0;
}
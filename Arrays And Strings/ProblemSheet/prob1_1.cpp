// Finding the two non repeating numbers in the array of evenly repeating numbers

// This method can also be applied for the odd occurence of the
// "two" elements in an unsorted array 
#include<bits/stdc++.h>
using namespace std;

// time complexity - O(N) and space complexity - O(1)
vector<int> nonRepeating(int arr[], int n ){
    vector<int> v;
    int Xor = arr[0] ;
    for (int i = 1; i < n; i++)
        Xor ^= arr[i];
    int set_bit_no = Xor & ~(Xor - 1);
    int nrElem1 =0 ;
    int nrElem2 =0 ;

    for (int i = 0; i < n; i++)
    {
        if(arr[i] & set_bit_no){
            nrElem1 ^= arr[i];
        }
        else{
            nrElem2 ^= arr[i];
        }
    }
     v.push_back(nrElem1);
     v.push_back(nrElem2);
     return v;
    
}



int main()
{
int arr[] ={2,3,1,1,1,1,5,5,5,5,6,6};
int n = sizeof(arr)/sizeof(int);
vector<int> v = nonRepeating(arr, n);
for(auto n : v){
    cout<<n<<" ";
}
return 0;
}
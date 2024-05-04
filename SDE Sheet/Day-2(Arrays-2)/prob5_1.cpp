// Sort Two sorted arrays without needing any extra space 
 #include<bits/stdc++.h>
 using namespace std;

void sortTwoArrays(vector<int> &v1,vector<int> &v2){
    // 1, 2, 8, 10

    int n = v1.size();
    int m = v2.size();
    int right = n-1 , left = 0;
    while(left < m && right >= 0){
        if(v1[right] <= v2[left]){
            right--; left++;
        }
        else{
            swap(v1[right], v2[left]);
             right--; left++;
        }

    }

}
void printVec(vector<int> & v){
    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


 int main()
 {
    vector<int> v1 = {1, 2, 8, 10};
    vector<int> v2 = {4, 5, 6};
    sortTwoArrays(v1, v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    printVec(v1);
    printVec(v2);
 return 0;
 }
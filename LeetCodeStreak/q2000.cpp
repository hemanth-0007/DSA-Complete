#include<bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {
    int ind = -1;
    for(int i = 0; i < word.size(); i++) 
        if(word[i] == ch){ 
            ind = i;
            break;
        }
    if(ind == -1) return word;
    for(int i = 0; i <= ind/2; i++){
        swap(word[i], word[ind - i]);
    }
    return word;    
}

int main()
{
   string word = "abcdefd";
   char ch = 'd';
   cout<<reversePrefix(word, ch);

return 0;
}
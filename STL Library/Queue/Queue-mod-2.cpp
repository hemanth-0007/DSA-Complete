#include<iostream>
#include<queue>
using namespace std;


 void Print(pair<int,int> p){
    cout<<p.first<<" "<<p.second;
 }


 void displayQueue(queue <pair<int,int>>  q){
    
        while(!q.empty()){
             Print(q.front()) ;
            q.pop();
        }
        cout<<"\n";
 }

int main()
{
    queue <pair<int,int>> q;
    q.push({1,2});
    q.push({4,9});
    q.push({1,10});
    displayQueue(q);
    while(!q.empty()){
        q.pop();
    }
    Print(q.front());// will be printing garbage values as the queue is empty

    return 0;
}
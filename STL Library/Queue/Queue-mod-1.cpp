#include<iostream>
#include<queue>
using namespace std;

void displayQueue(queue<int> q){

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
      
    }
    cout<<endl;

}

void emptyQueue(queue<int> q){
 
    while (!q.empty())
    {
      q.pop();
    }
  
}

int main()
{
    queue<int> q;
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // cout<<q.size()<<endl;
    
    
    // displayQueue(q);
    char ch;
    int k;
    while (1)
    {
        cin>>ch;
        switch (ch)
        {
        case 'p':
            cin>>k;
            q.push(k);
            break;
        case 'w':
            q.pop();
        break;
        case 'q':
              while (!q.empty())
            {
                q.pop();
            }
  
        break;
        case 'f':
            cout<<q.front()<<endl;
        break;
        case 'b':
            cout<<q.back()<<endl;
        break;
        case 'c':
            cout<<q.empty()<<endl;
        break;
        case 's':
            cout<<q.size()<<endl;
        break;
        case 'd':
            displayQueue(q);
        break;
        case 'e':
            return 0;
        break;

        
         
        }
    }
    
    
return 0;
}
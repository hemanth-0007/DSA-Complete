#include<bits/stdc++.h>
using namespace std;

/*
    Rock paper scissor 
     1    2      3
     3 possibilities
     1 && 2 --> 2 wins
     2 && 3 --> 3 wins
     1 && 3 --> 1 wins


*/

class Player{  
     
     public:
          int score = 0;
          string s;
          void game(Player p2){
               if(p2.s == "Rock"){
                    if(this->s == "Paper"){
                         this->score++;
                    }
                    else if(this->s == "Scissor"){
                         p2.score++;
                    }
               }
               else if(p2.s == "Paper"){
                    if(this->s == "Rock"){
                         
                         p2.score++;
                    }
                    else if(this->s == "Scissor"){
                         this->score++;
                    }
               }
               else if(p2.s == "Scissor"){
                    if(this->s == "Rock"){
                         this->score++;
                    }
                    else if(this->s == "Paper"){
                          p2.score++;
                    }
               }
          }

   


};


int main()
{

     // so we will be having 2 players p1 p2
     // and scores of these players

   Player p1 , p2;
//    p1.s = "Rock";
//    p2.s = "Scissor";
//    p1.game(p2);
//    cout<<"Score of P1 :"<<p1.score<<endl<<"P2 score is : "<<p2.score;

     for (int i = 0; i < 3; i++)
     {
          cout<<"p1 turn: "<<endl;
          cin>>p1.s;
          cout<<"p2 turn: "<<endl;
          cin>>p2.s;
          p1.game(p2);
     }
     
     if(p1.score > p2.score){
          cout<<"P1 is winner"<<endl;
     }
     else if(p1.score < p2.score){
          cout<<"P2 is winner"<<endl;
     }
     else if(p1.score == p2.score){
          cout<<"Draw Game"<<endl;
     }
     cout<<"Score of P1 :"<<p1.score<<endl<<"P2 score is : "<<p2.score;

return 0;
}
#include<bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    struct food{
        string food[10000];
        string cuisine[10000];
        int rating[10000];
    } ;

    int size = 0;
    struct food *fd;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        size = foods.size();
        fd = (struct food*)malloc(sizeof(struct food)*size);
        for(int i = 0 ; i < foods.size() ; i++){
            fd->food[i] = foods[i];
            fd->cuisine[i] = cuisines[i];
            fd->rating[i] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        for(int i = 0 ; i < size ; i++){
            if(fd->food[i] == food){
                fd->rating[i] = newRating;
                break;
            }
        }
    }
    
    string highestRated(string cuisine) {
        int maxRating = 0;
        string highestRatedFood = "";
        for(int i = 0 ; i < size ; i++){
            if(fd->cuisine[i] == cuisine && fd->rating[i] >= maxRating){
                maxRating = fd->rating[i];
                highestRatedFood = fd->food[i];
            }
        }
        return highestRatedFood;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */


int main()
{
    vector<string> foods = {"Pizza", "Burger", "Fries", "Fries", "Pizza"};
    vector<string> cuisines = {"Italian", "American", "Italian", "Italian", "Italian"};
    vector<int> ratings = {5, 3, 2, 4, 1};
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
    obj->changeRating("Pizza", 4);
    string param_2 = obj->highestRated("Italian");
    cout<<param_2<<endl;

return 0;
}
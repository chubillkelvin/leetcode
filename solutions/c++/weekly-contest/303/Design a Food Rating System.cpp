#include <bits/stdc++.h>

using namespace std;

class FoodRatings {
    unordered_map<string, map<int, set<string>>> cuisineToRating;
    unordered_map<string, int> foodToRating;
    unordered_map<string, string> foodToCuisine;
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            auto food = foods[i];
            auto cuisine = cuisines[i];
            auto rating = ratings[i];
            foodToCuisine[food] = cuisine;
            foodToRating[food] = rating;
            cuisineToRating[cuisine][rating].insert(food);
        }
    }

    void changeRating(string food, int newRating) {
        auto cuisine = foodToCuisine[food];
        auto oldRating = foodToRating[food];
        foodToRating[food] = newRating;
        cuisineToRating[cuisine][oldRating].erase(food);
        if (cuisineToRating[cuisine][oldRating].empty()) cuisineToRating[cuisine].erase(oldRating);
        cuisineToRating[cuisine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        auto key = cuisineToRating[cuisine].rbegin();
        return *(*key).second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
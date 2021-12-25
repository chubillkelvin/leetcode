#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    map<string, vector<string>> recipeMap;
    set<string> noSup;
    set<string> sup;

    bool hasIngredient(string ing, set<string> &inList) {
        if (noSup.count(ing) > 0 || inList.count(ing) > 0) return false;
        if (sup.count(ing) > 0) return true;
        if (recipeMap.find(ing) != recipeMap.end()) {
            inList.insert(ing);
            auto rec = recipeMap[ing];
            bool hasIng = true;
            for (auto i: rec) {
                if (!hasIngredient(i, inList)) hasIng = false;
            }
            if (hasIng) {
                sup.insert(ing);
            } else {
                noSup.insert(ing);
            }
            return hasIng;
        }
        return false;
    }

    vector<string>
    findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies) {
        n = recipes.size();
        for (auto s: supplies) sup.insert(s);
        for (int i = 0; i < n; i++) {
            string r = recipes[i];
            auto ing = ingredients[i];
            recipeMap[r] = ing;
        }

        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string r = recipes[i];
            auto ings = ingredients[i];
            bool canMake = true;
            for (auto ing: ings) {
                set<string> inList;
                if (!hasIngredient(ing, inList)) canMake = false;
            }
            if (canMake) {
                sup.insert(r);
                ans.push_back(r);
            }
        }
        return ans;
    }
};
class FoodRatings {
public:
   private:
    unordered_map<string, set<pair<int, string>>> cuis_rat_food;
    unordered_map<string, string> food_cu;
    unordered_map<string, int> food_ra;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            cuis_rat_food[cuisines[i]].insert({-ratings[i], foods[i]});
            
            food_cu[foods[i]] = cuisines[i];
            food_ra[foods[i]] = ratings[i];
        }        
    }
    
    void changeRating(string food, int newRating) {
        cuis_rat_food[food_cu[food]].erase({-food_ra[food], food});

        cuis_rat_food[food_cu[food]].insert({-newRating, food});

        food_ra[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(cuis_rat_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
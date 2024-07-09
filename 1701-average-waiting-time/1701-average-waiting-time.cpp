class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double target = customers[0][0];
        double ans = 0;
        for(int i = 0; i < customers.size(); i++){
            double val;
            if(target >= customers[i][0]){
               val = target + customers[i][1];
               target = val;
            }
            else{
                val = customers[i][0] + customers[i][1];
                target = val;
            }
            ans += val - customers[i][0];    
        }
        return ans/customers.size();
    }
};
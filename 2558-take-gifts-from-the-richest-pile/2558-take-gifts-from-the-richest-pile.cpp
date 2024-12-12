class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
       priority_queue<long long> pq;
       for(int i = 0; i < gifts.size(); i++){
           pq.push(gifts[i]);
       }
       long long sum = 0;
       while(k--){
           int val = pq.top();
           pq.pop();
           int sqrt_val = sqrt(val);
           pq.push(sqrt_val);           
       }
        for(int i = 0; i < gifts.size(); i++){
           sum += pq.top();
           pq.pop();
       }
       return sum; 
    }
};
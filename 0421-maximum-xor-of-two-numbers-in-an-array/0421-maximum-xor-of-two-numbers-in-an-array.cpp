class Node{
    public:
    
     Node * links[2];
     
     bool flag = false;
     
     bool containskey(int bit){
         return links[bit] != NULL;
     }
     
     Node * getkey(int bit){
         return links[bit];
     }
     
     void put(int bit, Node * node){
         links[bit] = node;
     }
     
     void setEnd(){
         flag = true;
     }
     
     bool isEnd(){
         return flag;
     }
     
};
class trie{
    private: Node *root;
    public:
    trie(){
        root = new Node();
    }
    public:
      void insert(int num){
            Node *node = root;
            for(int i=31; i>=0; i--){
                int bit = num>>i & 1;
                if(!node -> containskey(bit)){
                    node -> put(bit,new Node());
                }
                node = node -> getkey(bit);
            }
            node -> setEnd();
        }
    
      int getmax(int num){
         Node *node = root;
         int maxnum=0;
         
         for(int i=31; i>=0; i--){
             int bit = (num>>i) & 1;
             if(node -> containskey(1-bit)){
                 maxnum = maxnum | 1<<i;
                 node = node -> getkey(1-bit);
             }
             else{
               node = node -> getkey(bit);  
            }
         }
          return maxnum;
     }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie t;
        
        for(auto it: nums){
            t.insert(it);
        }
        
        int maxnum = 0;
        for(int i=0; i<nums.size(); i++){
            maxnum = max(maxnum,t.getmax(nums[i]));
        }
        return maxnum;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int X) {
       int N=mat.size();
       int M=mat[0].size();
       int i=0;
	   int j=M-1;
	   while(i<N && j>=0){
	       if(mat[i][j]==X){
	           return 1;
	       }
	       else if(mat[i][j]<X){
	           i++;
	       }
	       else{
	           j--;
	       }
	   }
	   return 0;
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       if (mat.size() == 1) return mat[0];

        int total = mat.size() * mat[0].size();
        vector<int> ret(total);
        ret[0] = mat[0][0];

        if (mat[0].size() == 1) {
            for (int i = 1; i < mat.size(); i++) {
                ret[i] = mat[i][0];
            }
            return ret;
        }

        int count = 1, i = 0, j = 1;
        bool downLeft = true;

        while (count < total) {
            if (downLeft) {
                while (j > 0 && i < mat.size() - 1) {
                    ret[count++] = mat[i][j];
                    i++; j--;
                }
                ret[count++] = mat[i][j];
                if (i < mat.size() - 1) i++;
                else j++;
                downLeft = false;
            } else {
                while (i > 0 && j < mat[0].size() - 1) {
                    ret[count++] = mat[i][j];
                    i--; j++;
                }
                ret[count++] = mat[i][j];
                if (j < mat[0].size() - 1) j++;
                else i++;
                downLeft = true;
            }
        }
        return ret;  
    }
};
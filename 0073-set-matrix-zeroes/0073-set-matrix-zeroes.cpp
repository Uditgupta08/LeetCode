class Solution {
public:
    // Basic Idea:
    /*
        Check if first row or column contains 0 -> Check bools
    */
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        bool lc = false;
        bool tr = false;
        for(int i = 0; i < n; i++){
            if(a[i][0] == 0){
                lc = true;
            }
        }
        for(int i = 0; i < m; i++){
            if(a[0][i] == 0){
                tr = true;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(a[i][j] == 0){
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        for(int j = 1; j < m; j++){
            if(a[0][j] == 0){
                for(int i = 1; i < n; i++){
                    a[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(a[i][0] == 0){
                for(int j = 1; j < m; j++){
                    a[i][j] = 0;
                }
            }
        }
        if(tr){
            for(int i = 0; i < m; i++){
                a[0][i] = 0;
            }
        }
        if(lc){
            for(int j = 0; j < n; j++){
                a[j][0] = 0;
            }
        }
    }
};
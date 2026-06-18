class Solution {
public:
    vector<int> countBits(int n) {        
        vector<int> result(n+1);

        for(int i = 0; i <= n; i++) {
            result[i] = hemming(i);
        }

        return result;
    }

    int hemming(int n){
        int count = 0;

        while(n) {
            n = n&(n-1);
            count++;
        }

        return count;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;

        while(n!=1 && set.count(n) == 0) {
            set.insert(n);
            n = getNext(n);
        }

        return n==1;
        
    }

    int getNext(int n) {
        int sum = 0;

        while(n > 0) {
            int digit = n%10;
            sum += digit*digit;

            n = n/10;
        }

        return sum;
    }
};

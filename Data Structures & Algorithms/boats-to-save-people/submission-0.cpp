class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;

        sort(people.begin(), people.end());

        while(left <= right){
            int weight = people[right] + people[left];
            
            if(weight <= limit) {
                left++;
                right--;
                
            } else {
                right--;
            }
            boats++;
        }
        
        return boats;
    }
};
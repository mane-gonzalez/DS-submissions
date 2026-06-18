class Solution {
public:
    int jump(vector<int>& nums) {
        int coverage = 0;
        int endJump = 0;
        int numJumps = 0;
        int target = nums.size() - 1;
        

        for(int i = 0; i < target; i++ ) {
            coverage = max(coverage, i + nums[i]);

            if(i == endJump){
                numJumps++;
                endJump = coverage;

                if(endJump >= target){
                    break;
                }
            }
        }
        return numJumps;
    }
};

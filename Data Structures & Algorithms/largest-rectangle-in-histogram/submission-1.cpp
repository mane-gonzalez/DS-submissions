class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {
            int currHeight = 0;

            if(i==n) {
                /*do nothing with currHeight*/
            } else {
                currHeight = heights[i];
            }

            while(!stack.empty() && heights[stack.top()] >= currHeight) {
                int height = heights[stack.top()];
                stack.pop();

                int width = 0;

                if(stack.empty()) {
                    width = i;
                } else {
                    width = i - stack.top() - 1;
                }

                maxArea = max(maxArea, height*width);
            }
            stack.push(i);
        }
        return maxArea;
    }
};
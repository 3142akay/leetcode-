class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // Jab tak stack khali nahi aur current height chhoti hai
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        // Har row ke liye
        for (int i = 0; i < rows; i++) {
            // Heights array update karo
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++; // Continuous 1s ki height badhao
                } else {
                    heights[j] = 0; // Agar 0 mila, height reset karo
                }
            }
            // Is row ke histogram ka max area find karo
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
};
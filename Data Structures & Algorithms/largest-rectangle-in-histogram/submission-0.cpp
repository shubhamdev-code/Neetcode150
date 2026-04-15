class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<pair<int, int>> st; 

        for (int i = 0; i < heights.size(); ++i) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();
                ans = max(ans, height * (i - index));
                start = index; 
            }
            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            ans = max(ans, height * ((int)heights.size() - index));
        }

        return ans;
    }
};

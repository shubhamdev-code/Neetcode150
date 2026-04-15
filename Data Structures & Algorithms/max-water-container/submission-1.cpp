class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 , r = height.size()-1; 
        int min_height = min(height[l],height[r]) , max_area = min_height*(r-l); 
        while(l < r){
            if(min_height == height[l]) l++; 
            else r--;  
            min_height = min(height[l],height[r]); 
            max_area = max(max_area,min_height * (r-l)); 
        }
        return max_area; 

    }
};

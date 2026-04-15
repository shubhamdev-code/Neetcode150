class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1 , right = *max_element(piles.begin(),piles.end());
        while(left <= right){
            int mid = left + (right - left) / 2 , hours = 0; 
            for(int i = 0; i<piles.size(); i++){
                hours += piles[i]/mid;
                if(piles[i] % mid != 0) hours++; 
            }
            if(hours <= h) right = mid-1; 
            else left = mid + 1; 
        }
        return left; 
    }
};

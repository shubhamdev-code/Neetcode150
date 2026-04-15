class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1); 

        int required = (nums1.size() + nums2.size() + 1)/2; 
        int lo = 0 , hi = nums1.size(); 
        while(lo <= hi){
            int mid1 = lo + (hi-lo)/2; 
            int mid2 = required - mid1; 
            int l1 = INT32_MIN , l2 = INT32_MIN; 
            int r1 = INT32_MAX , r2 =INT32_MAX; 
            if(mid1 < nums1.size()) r1 = nums1[mid1]; 
            if(mid2 < nums2.size()) r2 = nums2[mid2]; 
            if(mid1 - 1 >= 0) l1 = nums1[mid1-1]; 
            if(mid2- 1 >= 0) l2 = nums2[mid2-1];

            if(l1 <= r2 && l2  <= r1){
                if((nums1.size() + nums2.size()) % 2  == 0) 
                    return (double)(max(l1,l2) + min(r1,r2))/2; 
                else 
                    return (double)(max(l1,l2));
            } else if(l1 > r2) hi = mid1-1; 
            else lo = mid1+1; 
        }
        return 0;
    }
};


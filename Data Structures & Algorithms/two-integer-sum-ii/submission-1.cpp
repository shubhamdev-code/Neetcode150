class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0 , j = i+1; 
        while(i < j && j < numbers.size() ){
            while(j < numbers.size() && numbers[i] + numbers[j] < target) j++; 
            if(numbers[i] + numbers[j] == target) return {i+1,j+1}; 
            i++; j= i+1; 
        }
        return {};
    }
};

class MinStack {
public:
    map<int,int> mn_tn; 
    vector<int> nums; int ind = -1 ; 
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push_back(val); 
        ind++; 
        if(ind != 0) mn_tn[ind] = min(mn_tn[ind-1], val);
        else mn_tn[ind] = val;  
    }
    
    void pop() {
        nums.pop_back(); 
        ind--; 
    }
    
    int top() {
        return nums[ind]; 
    }
    
    int getMin() {
        return mn_tn[ind]; 
    }
};

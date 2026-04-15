class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> frq; 
        for(int i = 0; i < tasks.size(); i++){
            frq[tasks[i]]++; 
        }

        priority_queue<int> max_heap; 
        for(auto i : frq){
            max_heap.push(i.second); 
        }


        int time = 0, tasks_done = 0 ; 
        while(tasks_done != tasks.size() && !max_heap.empty()){
            vector<int> tmp; 

            int i = 0; 
            while(i < n+1 && tasks_done != tasks.size()){
                
                if(!max_heap.empty()){
                    tasks_done++; 
                    time++; 
                    int mx = max_heap.top(); 
                    max_heap.pop(); 
                    if(mx > 1) tmp.push_back(mx-1);
                } else{
                    time++; 
                }
                
                i++; 
            }

            for(int i = 0; i < tmp.size(); i++){
                max_heap.push(tmp[i]); 
            }
        }
        return time; 
    }
};
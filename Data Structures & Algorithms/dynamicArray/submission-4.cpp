class DynamicArray {
public:
    vector<int> arr; 
    int num = 0 ; 
    
    DynamicArray(int capacity) {
        arr.resize(capacity); 
    }

    int get(int i) {
        return arr[i]; 
    }

    void set(int i, int n) {
        arr[i] = n; 
    }

    void pushback(int n) {
        if (num == arr.size()) {
            resize();
        }
        arr[num] = n;
        num++;
    }

    int popback() {
        int x = arr[num-1]; 
        num--; 
        return x; 
    }

    void resize() {
        int x = getCapacity(); 
        arr.resize(x*2); 
    }

    int getSize() {
        return num; 
    }

    int getCapacity() {
        return arr.size(); 
    }
};

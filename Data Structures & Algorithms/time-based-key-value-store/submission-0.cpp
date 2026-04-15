class TimeMap {
public:
    TimeMap() {
    }
    unordered_map<string,vector<pair<int,string>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()){
        const auto &v=mp[key];
        int lo=0,hi=v.size()-1;
        while(lo<=hi){
            int mid=(hi-lo)/2+lo;
            if(v[mid].first==timestamp) return v[mid].second;
            else if(v[mid].first<timestamp) lo=mid+1;
            else if(v[mid].first>timestamp) hi=mid-1;
        }
       if(hi!=-1)
        return v[hi].second;
       else return "";
        }
        return "";
    }
};
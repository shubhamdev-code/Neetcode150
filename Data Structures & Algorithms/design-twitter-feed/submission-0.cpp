class Twitter {
public:
    int time = 0;
    map<int, vector<pair<int, int>>> posts;
    map<int, vector<pair<int, bool>>> following;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        for (auto &p : posts[userId]) {
            pq.push(p);
        }

        for (auto &f : following[userId]) {
            if (f.second) {
                for (auto &p : posts[f.first]) {
                    pq.push(p);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;

        for (auto &f : following[followerId]) {
            if (f.first == followeeId) {
                f.second = true;
                return;
            }
        }

        following[followerId].push_back({followeeId, true});
    }

    void unfollow(int followerId, int followeeId) {
        for (auto &f : following[followerId]) {
            if (f.first == followeeId) {
                f.second = false;
                return;
            }
        }
    }
};

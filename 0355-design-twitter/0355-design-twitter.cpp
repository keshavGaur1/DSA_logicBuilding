class Twitter {
    struct Tweet {
        int time;
        int tweetId;
        Tweet(int t, int id) : time(t), tweetId(id) {}
    };
    
    unordered_map<int, unordered_set<int>> followers;  // user -> followees
    unordered_map<int, vector<Tweet>> tweets;           // user -> their tweets
    int timestamp;
    

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        
        // Min-heap (priority_queue) stores: {time, tweetId, userId, indexInUserTweets}
        auto cmp = [](const tuple<int,int,int,int>& a, const tuple<int,int,int,int>& b) {
            return get<0>(a) < get<0>(b);  // max heap by time
        };
        priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, decltype(cmp)> pq(cmp);
        
        // Include self
        followers[userId].insert(userId);
        
        // Initialize heap with latest tweet from each followee
        for(auto& followee : followers[userId]) {
            auto& tws = tweets[followee];
            if(!tws.empty()) {
                int lastIdx = tws.size() - 1;
                pq.emplace(tws[lastIdx].time, tws[lastIdx].tweetId, followee, lastIdx);
            }
        }
        
        // Extract top 10 tweets by timestamp
        while(!pq.empty() && feed.size() < 10) {
            auto [time, tweetId, user, idx] = pq.top();
            pq.pop();
            feed.push_back(tweetId);
            
            // Push next recent tweet from same user, if any
            if(idx > 0) {
                auto& tws = tweets[user];
                int nextIdx = idx - 1;
                pq.emplace(tws[nextIdx].time, tws[nextIdx].tweetId, user, nextIdx);
            }
        }
        
        // Cleanup: remove self from followers to keep data clean
        followers[userId].erase(userId);
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
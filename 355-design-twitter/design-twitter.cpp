class Twitter {
public:
unordered_map<int, unordered_set<int>> follows;
unordered_map<int, vector<pair<int, int>>> tweets;
int timer = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

// User's own tweets
for (auto &t : tweets[userId])
    pq.push(t);

// Followees' tweets
for (int f : follows[userId]) {
    for (auto &t : tweets[f])
        pq.push(t);
}

vector<int> ans;

while (!pq.empty() && ans.size() < 10) {
    ans.push_back(pq.top().second);
    pq.pop();
}

return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
    follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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
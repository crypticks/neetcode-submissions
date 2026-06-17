class Twitter {
private:
    struct User 
    {
        vector<bool> following = vector<bool> (101);
        vector<pair<int, int>> posts;
    };
    unordered_map<int, User> usermap;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        User* data = &usermap[userId];
        data->posts.push_back({tweetId, time++});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](pair<int, int> a, pair<int,int> b) { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> maxheap(cmp);
        for(auto p : usermap[userId].posts)
        {
            maxheap.push(p);
        }
        for(int i = 1; i < 101; i++)
        {
            if(usermap[userId].following[i])
            {
                for(auto p : usermap[i].posts)
                {
                    maxheap.push(p);
                }

            }
        }

        vector<int> res;
        int k = 10;
        while(!maxheap.empty() && k--)
        {
            res.push_back(maxheap.top().first);
            maxheap.pop();
        }
        return res;
        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        usermap[followerId].following[followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        usermap[followerId].following[followeeId] = false;
    }
};

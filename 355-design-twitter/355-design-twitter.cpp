class Twitter {
    
private:
    list<pair<int, int>> posts; 
    unordered_map<int, unordered_set<int>> relation;
    
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId){
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId){
        vector<int> news;
        for(auto it = posts.rbegin(); it != posts.rend(); it++){
            if(news.size() == 10)
                break;
            if(it->first == userId || relation[userId].count(it->first) == 1)
                news.push_back(it->second);
        }
        return news;
    }
    
    void follow(int followerId, int followeeId){
        relation[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId){
        relation[followerId].erase(followeeId);
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
struct Tweet{
    int ID;
    int userID;
    Tweet(int ID, int userID){
        this->ID = ID;
        this->userID = userID;
    }
};

class Twitter {
private:
    vector<Tweet *> feed;
    unordered_map<int, unordered_set<int>> followList;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet * temp = new Tweet(tweetId, userId);
        feed.push_back(temp);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> userFeed;
        auto it = followList.find(userId);
        if (it == followList.end()){
            follow(userId,userId);
        }
        it = followList.find(userId);
        int count = 10;
        int index = feed.size()-1;
        while (count > 0 && index >=0){
            int postedBy = feed[index]->userID;
            if ((it->second).find(postedBy) != (it->second).end()){
                userFeed.push_back(feed[index]->ID);
                count--;
            }
            index--;
        }
        return userFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto it = followList.find(followerId);
        if (it == followList.end()){
            unordered_set<int> temp;
            temp.insert(followeeId);
            temp.insert(followerId);
            followList.insert(pair<int, unordered_set<int>>(followerId, temp));
        }
        else{
            (it->second).insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        auto it = followList.find(followerId);
        if (it != followList.end()){
            (it->second).erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

// 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
// postTweet(userId, tweetId): 创建一条新的推文
// getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
// follow(followerId, followeeId): 关注一个用户
// unfollow(followerId, followeeId): 取消关注一个用户
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdlib>
#include <list>
using namespace std;

class Twitter 
{
public:
    /** Initialize your data structure here. */
    Twitter()
    {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        auto iter = _users_map.find(userId);
        if(iter != _users_map.end())
        {
            iter->second._text.push_front(tweetId);
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    //将其和关注的用户的推特id进行归并或者 
    vector<int> getNewsFeed(int userId) 
    {
        auto iter = _users_map.find(userId);
        vector<int> ret;
        if(iter != _users_map.end()) //查找到
        {
            int count = 10;
            int total_user_count = iter->second._follow.size() + 1;
            vector<int> v_idx(total_user_count, 0);
            priority_queue<int> q;
            while(q.size() < count)
            {
               //
            }
        };

        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {

    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {

    };

private:
    class Comparator
    {
        public:
        bool operator()(const pair<uint64_t,int>& p1, const pair<uint64_t,int>& p2)
        {
            return p1.first > p2.first ? true : false;
        }
    };
    struct UserInfo
    {
        list<int> _text; //推送内容id,时间标记采用链表顺序标记
        vector<int> _follow; //关注的用户id
    };
    unordered_map<int, UserInfo> _users_map; //所有用户
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// https://neetcode.io/problems/design-twitter-feed
#include <chrono>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

inline int64_t getEpochTimestamp()
{
    return std::chrono::high_resolution_clock::now().time_since_epoch().count();
}

struct comp
{
    bool operator()(const int a, const int b) const
    {
        return a > b;
    }
};

struct User
{
    User() : id(-1)
    {
    }
    User(int _id) : id(_id)
    {
    }

    void addTweet(const int tweetId)
    {
        const auto tpair = std::make_pair(getEpochTimestamp(), tweetId);
        updateNewsFeed({tpair});
        users_tweets.push_back(tpair);
    }

    void addFollowing(const int userId)
    {
        following.insert(userId);
    }

    void removeFollowing(const int userId)
    {
        following.erase(userId);
    }

    std::unordered_set<int> &getFollowing()
    {
        return following;
    }

    void rebuildNewsFeed(const std::vector<std::pair<int64_t, int>> &other_items)
    {
        newsfeed.clear();
        updateNewsFeed(users_tweets);
        updateNewsFeed(other_items);
    }

    void updateNewsFeed(const std::vector<std::pair<int64_t, int>> &items)
    {
        for (const auto &itm : items)
        {
            const auto &[timestamp, content] = itm;
            newsfeed[timestamp] = content;
        }
    }

    int id;
    std::map<int64_t, int, comp> newsfeed;
    std::unordered_set<int> following;
    std::vector<std::pair<int64_t, int>> users_tweets;
};

class Twitter
{
  public:
    Twitter() = default;

    Twitter(const Twitter &) = delete;
    Twitter(Twitter &&) = delete;
    Twitter &operator=(const Twitter &) = delete;
    Twitter &operator=(Twitter &&) = delete;

    void postTweet(int userId, int tweetId)
    {
        if (!hasUser(userId))
        {
            usermap[userId] = User(userId);
            users.insert(userId);
        }
        usermap[userId].addTweet(tweetId);
    }

    std::vector<int> getNewsFeed(int userId)
    {
        if (!hasUser(userId))
        {
            usermap[userId] = User(userId);
            users.insert(userId);
            return {};
        }

        std::vector<int> ufeed;
        auto &un_feed = usermap[userId].newsfeed;
        int ctr = 0;
        for (auto it = un_feed.begin(); it != un_feed.end(); ++it)
        {
            if (ctr >= 10)
                break;

            auto cpair = *it;
            const auto [stamp, content] = cpair;
            ufeed.push_back(content);
            ++ctr;
        }

        return ufeed;
    }

    void follow(int followerId, int followeeId)
    {
        if (!hasUser(followerId))
        {
            usermap[followerId] = User(followerId);
            users.insert(followerId);
        }
        if (!hasUser(followeeId))
        {
            usermap[followeeId] = User(followeeId);
            users.insert(followeeId);
        }

        usermap[followerId].addFollowing(followeeId);

        for (const auto &followr : usermap[followerId].getFollowing())
        {
            std::vector<std::pair<int64_t, int>> feedvec;
            for (const auto &tweet_pair : usermap[followr].users_tweets)
            {
                feedvec.push_back(tweet_pair);
            }
            usermap[followerId].updateNewsFeed(std::move(feedvec));
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        if (!hasUser(followerId))
        {
            usermap[followerId] = User(followerId);
            users.insert(followerId);
        }
        if (!hasUser(followeeId))
        {
            usermap[followeeId] = User(followeeId);
            users.insert(followeeId);
        }

        usermap[followerId].removeFollowing(followeeId);

        if (usermap[followerId].following.empty())
        {
            usermap[followerId].rebuildNewsFeed({});
            return;
        }

        for (const auto &still_following : usermap[followerId].following)
        {
            usermap[followerId].rebuildNewsFeed(usermap[still_following].users_tweets);
            std::cout << "rebuilt '" << followerId << "'s feed with '" << still_following
                      << "'s items.\n";
        }
    }

  protected:
    bool hasUser(const int id)
    {
        return users.find(id) != users.end();
    }

  private:
    std::unordered_set<int> users;
    std::unordered_map<int, User> usermap;
};

inline void print_feed(Twitter &twitter_obj, const int userId)
{
    std::cout << userId << "'s feed:\n";
    for (const auto &itm : twitter_obj.getNewsFeed(userId))
    {
        std::cout << itm << " ";
    }
    puts("");
}

int main()
{
    Twitter twitter;
    twitter.postTweet(1, 10);
    twitter.postTweet(2, 20);

    print_feed(twitter, 1);
    print_feed(twitter, 2);

    twitter.follow(1, 2);

    print_feed(twitter, 1);

    twitter.unfollow(1, 2);

    print_feed(twitter, 1);

    return 0;
}

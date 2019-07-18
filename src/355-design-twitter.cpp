// 355. Design Twitter


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {
		global_time_stamp = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		if (users.find(userId) == users.end())
			users[userId] = User(userId);
		users[userId].post_a_tweet(new Tweet(tweetId, global_time_stamp++));
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<Tweet*> tweets_heap;
		unordered_set<int> visible_users = users[userId].get_followings();
		visible_users.insert(userId);
		for (auto it = visible_users.begin(); it != visible_users.end(); ++it) {
			Tweet* tweet_head = users[*it].get_tweets_list_head();
			if (tweet_head != nullptr)
				tweets_heap.push_back(tweet_head);
		}
		make_heap(tweets_heap.begin(), tweets_heap.end(),
			[](Tweet* a, Tweet* b) { return a->get_time_stamp() < b->get_time_stamp(); }
		);
		
		vector<int> recent_tweets;
		for (int i = 0; i < 10; ++i) {
			if (tweets_heap.empty() || tweets_heap.front() == nullptr)
				break;
			Tweet* temp = tweets_heap.front();
			recent_tweets.push_back(temp->get_id());
			pop_heap(tweets_heap.begin(), tweets_heap.end());
			tweets_heap.pop_back();
			if (temp->get_pre() != nullptr) {
				tweets_heap.push_back(temp->get_pre());
				push_heap(tweets_heap.begin(), tweets_heap.end());
			}
		}
		return recent_tweets;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (users.find(followerId) == users.end())
			users[followerId] = User(followerId);
		if (users.find(followeeId) == users.end())
			users[followeeId] = User(followeeId);
		users[followerId].follow_a_user(followeeId);
		users[followeeId].followed_by_a_user(followerId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (users.find(followerId) == users.end())
			users[followerId] = User(followerId);
		if (users.find(followeeId) == users.end())
			users[followeeId] = User(followeeId);
		users[followerId].unfollow_a_user(followeeId);
		users[followeeId].unfollowed_by_a_user(followerId);
	}
private:

	class Tweet {
	public:
		Tweet(int _id, int _time_stamp) : id(_id), time_stamp(_time_stamp) {}
		~Tweet() {}
		int get_id() { return id; }
		int get_time_stamp() { return time_stamp; }
		void set_pre(Tweet* _pre) { pre = _pre; }
		Tweet* get_pre() { return pre; }
	private:
		int id;
		int time_stamp;
		Tweet* pre;
	};

	class User {
	public :
		User() : id(-1), tweets_list_head(nullptr) { }
		User(int _id) : id(_id), tweets_list_head(nullptr) {}
		~User() {}
		Tweet* get_tweets_list_head() { return tweets_list_head; }
		unordered_set<int> get_followings() { return followings; }

		void post_a_tweet(Tweet* new_tweet) {
			new_tweet->set_pre(tweets_list_head);
			tweets_list_head = new_tweet;
		}
		void follow_a_user(int user_id) { followings.insert(user_id); }
		void followed_by_a_user(int user_id) { followers.insert(user_id); }
		void unfollow_a_user(int user_id) { followings.erase(user_id); }
		void unfollowed_by_a_user(int user_id) { followers.erase(user_id); }
	private:
		int id;
		Tweet* tweets_list_head;
		unordered_set<int> followers;
		unordered_set<int> followings;
	};

	unordered_map<int, User> users;

	int global_time_stamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

//void print(vector<int>& feed) {
//	cout << "[ ";
//	for (int t : feed)
//		cout << t << " ";
//	cout << "]" << endl;
//}
//
//int main() {
//	Twitter twitter;
//
//	vector<int> feed;
//
//	twitter.postTweet(1, 5);
//	twitter.follow(1, 2);
//	twitter.follow(2, 1);
//
//	feed = twitter.getNewsFeed(2);
//	print(feed);
//
//	twitter.postTweet(2, 6);
//
//	feed = twitter.getNewsFeed(1);
//	print(feed);
//
//	feed = twitter.getNewsFeed(2);
//	print(feed);
//
//	twitter.unfollow(2, 1);
//
//	feed = twitter.getNewsFeed(1);
//	print(feed);
//
//	feed = twitter.getNewsFeed(2);
//	print(feed);
//
//	twitter.unfollow(1, 2);
//
//	feed = twitter.getNewsFeed(1);
//	print(feed);
//
//	feed = twitter.getNewsFeed(2);
//	print(feed);
//
//	system("pause");
//	return 0;
//}
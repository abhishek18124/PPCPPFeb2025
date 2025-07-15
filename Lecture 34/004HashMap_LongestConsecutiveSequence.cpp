/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		// 1. build the map<> to track which elements can be starting
		// points for sequence of consecutive elements

		map<int, bool> startMap;

		for (int x : nums) { // nlogn since we are using map<> // on avg. O(n) if we use unordered_map<>

			if (startMap.find(x - 1) == startMap.end()) { // you've not seen x-1 so far, so we can make x as a starting at least for now
				startMap[x] = true;
			} else { // you've seen x - 1 previously there we know for sure x can never a starting point
				startMap[x] = false;
			}

			if (startMap.find(x + 1) != startMap.end()) { // you've seen x+1 previously and since at that point of time when you saw x+1 you didn't x, you would've set as a starting point which is no longer the case
				startMap[x + 1] = false;
			}

		}

		// for (auto [key, canStart] : startMap) {
		// 	cout << key << " : " << canStart << endl;
		// }

		// cout << endl;

		int maxSofar = 0; // to track the length of the longest
		// sequence of consecutive elements

		for (pair<int, bool> p : startMap) { // nlogn since we are using map<> // on avg. O(n) if you use unordered_map<>

			int key = p.first;
			bool canStart = p.second;

			if (canStart) {

				// key can serve as the starting point of a
				// sequence of consecutive elements.

				// now, find the length of that sequence

				int cnt = 0;

				while (startMap.find(key) != startMap.end()) {
					cnt++;
					key++;
				}

				maxSofar = max(maxSofar, cnt);

			}

		}

		return maxSofar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {10, 7, 8, 1, 3, 4, 2, 9, 11, 12, 16, 15};

	cout << s.longestConsecutive(nums) << endl;

}

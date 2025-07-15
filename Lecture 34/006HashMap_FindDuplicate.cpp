// https://leetcode.com/problems/find-the-duplicate-number/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {

public:

	int findDuplicate(vector<int>& nums) {

		while (true) {
			int x = nums[0];
			if (nums[x] == x) {
				return x;
			}
			swap(nums[0], nums[x]);
		}

	}

};

int main() {

	vector<int> nums = {1, 2, 3, 4, 4};

	Solution s;
	cout << s.findDuplicate(nums) << endl;

	return 0;

}
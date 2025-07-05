#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to stack<>

vector<int> asteroidCollision(vector<int>& asteroids) {

	stack<int> s;

	for (int ast : asteroids) {

		if (ast < 0 and !s.empty() and s.top() > 0) {

			// collisions will happen

			bool flag = true; // assume ast will survive collisions

			while (!s.empty() and s.top() > 0) {

				if (abs(ast) > s.top()) {
					// s.top() will be destroyed
					s.pop();
				} else if (abs(ast) < s.top()) {
					// ast will be destroyed
					flag = false;
					break;
				} else {
					// abs(ast) is equal to s.top()
					// ast and s.top() both will be destroyed
					flag = false;
					s.pop();
					break;
				}

			}

			if (flag) {
				// ast has survived all the collisions
				s.push(ast);
			}

		} else {

			// collisions won't happend, track ast

			s.push(ast);

		}

	}

	vector<int> ans;

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	vector<int> asteroids = {7, 3, -4, 5, 2, -8, 2, 4, 1, -4};

	vector<int> ans = asteroidCollision(asteroids);
	for (int x : ans) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}
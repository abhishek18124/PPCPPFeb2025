#include<iostream>
#include<vector>

#define int long long // replaces all int in code with long long before compilation

using namespace std;

bool f(int n, const vector<int>& a, int x, int m) {

    // can I make an aq. of height 'm' such
    // that water consumption allowed
    // atmost x units ?

    int sum = 0; // to track total water we'll put in the
    // container when its height is 'm' units

    for (int i = 0; i < a.size(); i++) {

        sum += max(0ll, m - a[i]); // ll suffix is used to treat 0 as long long

    }

    return sum <= x; // if total water put in container
    // of height m <= total water allowed
    // return true else return false

}

int32_t main() { // int32_t is written since int main changes to long long main which isn't allowed

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int s = 1;
        int e = 2e9;

        int ans;

        while (s <= e) { // log(e-s).n where e-s is the size of the search space

            int m = s + (e - s) / 2;
            if (f(n, a, x, m)) {
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }

        }

        cout << ans << endl;

    }

    return 0;
}
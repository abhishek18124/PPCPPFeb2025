/*

Given an infinite stream of non-negative integers, design an algorithm to output the
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

#define pqmin priority_queue<int, vector<int>, greater<int>>

using namespace std;

void printHeap(pqmin minHeap) { // pass minHeap by value only since we don't want changes done to it to reflect in the caller fn i.e. main()
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k = 3;
    pqmin minHeap;

    int x;

    // read 1st k values from the stream and put them
    // in the minHeap

    // minHeap tracks k-largest elements so far

    for (int i = 1; i <= k; i++) {
        cin >> x;
        minHeap.push(x);
    }

    while (true) {

        int x;
        cin >> x;

        if (x == -1) {
            printHeap(minHeap);
        } else {
            if (x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
        }

    }

    return 0;
}
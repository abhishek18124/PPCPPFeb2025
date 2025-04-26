#include<iostream>

using namespace std;

int main() {

    int arr[3][4] = {
        {10, 15, 20, 25},
        {30, 35, 40, 45},
        {50, 55, 60, 65}
    };

    cout << arr[0][0] << " " << arr[0][1] << " " << arr[0][2] << " " << arr[0][3] << endl;
    cout << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << " " << arr[1][3] << endl;
    cout << arr[2][0] << " " << arr[2][1] << " " << arr[2][2] << " " << arr[2][3] << endl << endl;


    int m = 3; // rows

    for (int i = 0; i < m; i++) {
        // print the ith row
        cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << endl;
    }

    cout << endl;

    int n = 4;

    for (int i = 0; i < m; i++) {

        // print the ith row

        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }

        cout << endl;

    }

    cout << endl;

    return 0;
}
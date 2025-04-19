#include<iostream>
#include<cstring>

using namespace std;

// time : O(min(m, n)) where m and n are lengths of s1[] and s2[] resp.

int stringCompare(char s1[], char s2[]) {

	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] > s2[j]) {
			// s1 > s2
			return 1;
		} else if (s1[i] < s2[j]) {
			// s1 < s2
			return -1;
		}

		i++;
		j++;

	}

	if (s1[i] == '\0' and s2[j] == '\0') {
		return 0;
	} else if (s1[i] == '\0') {
		// length of s1 < length of s2 therefore s1 < s2
		return -1;
	} else {
		// length of s1 > length of s2 therefore s1 > s2
		return 1;
	}

} x

int main() {

	char s1[] = "adc";
	char s2[] = "aaa";

	// int ans = stringCompare(s1, s2);
	int ans = strcmp(s1, s2);

	cout << ans << endl;

	if (ans == 0) {
		cout << s1 << " is equal to " << s2 << endl;
	} else if (ans > 0) {
		cout << s1 << " > " << s2 << endl;
	} else {
		// ans < 0
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}
#include<iostream>
#include<cstring>

using namespace std;

void copyString(char s1[], char s2[]) {

	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s2[j] != '\0') {
		s1[i] = s2[j];
		i++;
		j++;
	}

	s1[i] = '\0';

}

int main() {

	// assume length of s1 <= length of s1 i.e. you can always
	// accomodate char of s2 into s1

	char s1[100] = "abcde";
	char s2[] = "xyz";

	cout << s1 << endl; // abcde

	// copyString(s1, s2);
	strcpy(s1, s2);

	cout << s1 << endl; // xyz

	return 0;
}
// https://www.hackerrank.com/challenges/c-tutorial-strings/problem?isFullScreen=true
#include <iostream>
#include <string>
using namespace std;

int main() {
	// Line 1
    string str1, str2;
    char tmp;
    int len1, len2;
    
    cin >> str1 >> str2;
    len1 = str1.length();
    len2 = str2.length();
    cout << len1 << ' ' << len2 << endl;
    cout << str1 + str2 << endl;
    tmp = str1[0];
    str1[0] = str2[0];
    str2[0] = tmp;
    cout << str1 << ' ' << str2;
    return 0;
}
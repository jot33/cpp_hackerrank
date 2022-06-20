// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    vector<int> v;
    char delim;
    int i;
    while (ss) {
        ss >> i;
        v.push_back(i);
        ss >> delim;
    }
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
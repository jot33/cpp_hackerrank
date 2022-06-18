#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parse_tag(string &str, char delim);
void parse_line(unordered_map<string, unordered_map<string, string>> &tags, string &str, char delim);
string query_tag(unordered_map<string, unordered_map<string, string>> &tags, string &str);

int main () {
    int n, q;
    cin >> n;
    cin >> q;
    unordered_map<string, unordered_map<string, string>> tags;
    // unordered_map<string, unordered_map<string, string>>* tagsptr = &tags;
    string readline;
    // loop tags
    for (int i = 0; i < n; i++) {
        getline(cin, readline); // readline
        if (readline[1] == '/') {
            continue;
        }
        parse_line(tags, readline, ' ');
    }
    // loop queries
    for (int i = 0; i < q; i++) {
        getline(cin, readline);
        cout << query_tag(tags, readline);
    }
    return 0;
}

unordered_map<string, string> parse_tag(string &str, char delim) {
    int p1 = str.find(delim);
    int p2, p3;
    string name, val;
    unordered_map<string, string> tag_map;
    while (p1 > -1) {
        name = str.substr(0, p1);
        cout << name << endl;
        // check for space between name and delim
        if (name.find(' ') > -1)
            name = name.substr(0, name.find(' '));
        p2 = str.find('\"');
        str.erase(0, p2 + 1);
        p2 = str.find('\"');
        val = str.substr(0, p2);
        cout << val << endl;
        tag_map[name] = val;
        str.erase(0, p2);
        p2 = str.find(' ');
        str.erase(0, p2 + 1);
        p1 = str.find(delim);
    }
    return tag_map;
}

void parse_line(unordered_map<string, unordered_map<string, string>> &tags, string &str, char delim) {
    string tagname, tagline;
    int pos = tagname.find(delim);
    tagname = str.substr(1, pos);
    tagline = str.substr(pos + 1, str.length());
    tags[tagname] = parse_tag(tagline, '=');
}

string query_tag(unordered_map<string, unordered_map<string, string>> &tags, string &str) {
    int dotCheck = str.find('.');
    int pos;
    string tagname, tagval;

    while (dotCheck > -1) {
        dotCheck = str.find('.');
        str.erase(0, dotCheck + 1);
    }
    pos = str.find('~');
    tagname = str.substr(0, pos);
    tagval = str.substr(pos + 1, str.length());
    if (tags[tagname].find(tagval) != tags[tagname].end()) {
        return tags[tagname][tagval];
    }
    else {
        return "Not Found!";
    }
}
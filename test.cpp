#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

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
    tagname = str.substr(1, pos - 1);
    tagline = str.substr(pos + 1, str.length());
    tags[tagname] = parse_tag(tagline, '=');
}

int main() {
    // unordered_map<string, string> test;
    unordered_map<string, unordered_map<string, string>> test;
    string i;
    i = "<tag3 another=\"another\" final=\"final\">";
    int p = i.find(' ');
    cout << i.substr(1, p - 1) << ".\n";
    cout << i.substr(p + 1, i.length());
    // tagname = i.substr(1, i.find(' '));
    // cout << tagname << endl;
    // i.erase(0,i.find(' ') + 1);
    // cout << i << endl;
    // i = "this is a line";
    // int p = i.find(' ');
    // p = i.find("asdfbdf");
    // while (p >= 0) {
    //     tagname = i.substr(0,p);
    //     cout << tagname;
    //     i.erase(0,p + 1);
    //     p = i.find(' ');
    // }
    // cout << p << endl;
    // tagname = i.substr(1, i.find(' ') - 1);
    // cout << tagname << "." << endl;
    // cout << i.substr(i.find(' ') + 1, i.length());

    // test = parse_tag(i, '=');
    // cout << test["another"] << endl;
    // cout << test["final"] << endl;


}
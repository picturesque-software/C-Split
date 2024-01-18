#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "str_split.hpp"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

void print_vector(const vector<string> &vec);
void do_test(const string &s, const string &delim);

int main() {
    string filename;
    cin >> filename;

    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "file not found: '" << filename << '\'' << endl;
        std::exit(1);
    }

    string line, delim;
    while (getline(fin, line)) {
        // 这边我们确保测试用例的输入是完整的，
        // 即，有一个待分割的字符串和 delimiter
        if (!getline(fin, delim)) {
            cerr << "incomplete pair" << endl;
            std::exit(1);
        }
        do_test(line, delim);
    }
}

void print_vector(const vector<string> &vec) {
    cout << '[';
    for (int i = 0; i < vec.size(); i++) {
        cout << '"' << vec[i] << '"';
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << ']' << endl;
}

void do_test(const string &s, const string &delim) {
    vector<string> ans = split2(s, delim);
    print_vector(ans);
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int del = 0;
bool multipleLineComment = false;

string removeComments(string str) {
    int n = str.length();
    string res = "";
    bool singleLineComment = false;

    for (int i = 0; i < n; i++) {
        // Start of single-line comment
        if (!multipleLineComment && i + 1 < n && str[i] == '/' && str[i + 1] == '/') {
            singleLineComment = true;
            i++; // Skip the second '/'
            continue; 
        }
        // Start of multi-line comment
        else if (!singleLineComment && !multipleLineComment && i + 1 < n && str[i] == '/' && str[i + 1] == '*') {
            multipleLineComment = true;
            i++; 
            continue;
        }
        // End of multi-line comment
        else if (multipleLineComment && i + 1 < n && str[i] == '*' && str[i + 1] == '/') {
            multipleLineComment = false;
            i++; 
            continue;
        }

        // Add character if not in any comment
        if (!singleLineComment && !multipleLineComment) {
            res += str[i];
        }
    }
    return res;
}

int main() {
    // Use ifstream for reading and ofstream for writing
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    string str;
    while (getline(fin, str)) {
        string ss = removeComments(str);

        // Logic: If the original line wasn't empty, but the processed line is, 
        // it means the line was likely just a comment.
        if (!str.empty() && ss.empty()) {
            del++;
        }

        fout << ss << endl;
    }

    cout << "Number of lines deleted: " << del << endl;

    fin.close();
    fout.close();

    return 0;
}
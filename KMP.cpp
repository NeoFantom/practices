#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeTable(const string &word) {
    int len = word.length();
    vector<int> table(len + 1);
    table[0] = -1;
    int pos, cand;
    for (pos = 1, cand = 0; pos < len; ++pos, ++cand) {
        table[pos] = word[pos] == word[cand] ? table[cand] : cand;
        while (cand != -1 && word[cand] != word[pos]) cand = table[cand];
    }
    table[pos] = cand;
    return table;
}

vector<int> match(const string &text, const string &word) {
    auto table = makeTable(word);

    vector<int> matchedPos;
    int it, iw;
    for (it = 0, iw = 0; it < text.length(); ++it, ++iw) {
        // if (text[it] == word[iw] && iw == word.length())
        //     matchedPos.push_back(it);
        while (iw != -1 && text[it] != word[iw]) iw = table[iw];
        if (iw == word.length() - 1) matchedPos.push_back(it - iw);
    }
    return matchedPos;
}

vector<int> matchBrutal(const string &text, const string &word) {
    vector<int> matchedPos;
    int it, iw;
    for (it = 0; it < text.length(); ++it) {
        for (iw = 0; iw < word.length() && text[it] == word[iw]; ++iw);
        if (iw == word.length()) matchedPos.push_back(it - iw);
    }
    return matchedPos;
}

int main(int argc, char const *argv[]) {
    string text, word;
    cin >> text >> word;
    for (int i = 0; i < text.length(); i += 5) cout << text.substr(i, 5) << ' ';
    cout << endl;
    for (int i = 0; i < text.length(); i += 10) cout << setw(12) << left << i;
    cout << endl;
    auto matchedPos = match(text, word);
    for (int i : matchedPos) cout << i << ' ';
    if (matchedPos.empty())
        cout << "No match.";
    else
        cout << endl;
    return 0;
}

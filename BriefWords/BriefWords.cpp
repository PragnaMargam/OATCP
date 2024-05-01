#include <bits/stdc++.h>
using namespace std;


vector<string> generateCombinations(const string& input, const string& current, int index, int length) {
    vector<string> combinations;
    if (length == 0) {
        combinations.push_back(current);
        return combinations;
    }
    if (index >= input.length()) {
        return combinations;
    }

    vector<string> withChar = generateCombinations(input, current + input[index], index + 1, length - 1);
    combinations.insert(combinations.end(), withChar.begin(), withChar.end());

    vector<string> withoutChar = generateCombinations(input, current, index + 1, length);
    combinations.insert(combinations.end(), withoutChar.begin(), withoutChar.end());

    return combinations;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int numStrings;
    cin >> numStrings;

    set<string> uniqueCombinations;
    vector<vector<string>> allCombinations;

    for (int i = 0; i < numStrings; i++) {
        string input;
        cin >> input;

        vector<string> currentCombinations;
        for (int len = 1; len <= 4; len++) {
            vector<string> generated = generateCombinations(input, "", 0, len);

            for (const auto& comb : generated) {
                if (uniqueCombinations.find(comb) == uniqueCombinations.end()) {
                    currentCombinations.push_back(comb);
                    uniqueCombinations.insert(comb);
                }
            }
        }

        allCombinations.push_back(currentCombinations);
    }

    for (const auto& combinationSet : allCombinations) {
        for (const auto& comb : combinationSet) {
            cout << comb << "\n";
        }
        cout << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> findValidArrangement(vector<vector<int>>& pairs) {
        int pairCount = pairs.size();
        unordered_map<int, stack<int>> adjList;
        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;
        adjList.reserve(pairCount);
        inDegree.reserve(pairCount);
        outDegree.reserve(pairCount);

        for (int i = 0; i < pairCount; i++) {
            int start = pairs[i][0];
            int end = pairs[i][1];
            inDegree[end]++;
            outDegree[start]++;
            adjList[start].push(end);
        }

        int source = -1;
        for (const auto& entry : adjList) {
            int node = entry.first;
            if (outDegree[node] - inDegree[node] == 1) {
                source = node;
                break;
            }
        }

        if (source == -1) {
            source = adjList.begin()->first;
        }

        vector<vector<int>> result;
        traverseGraph(adjList, result, source);
        reverse(result.begin(), result.end());

        // If the result size doesn't match the number of pairs, there's no valid arrangement
        if (result.size() != pairCount) {
            return {};  // Return an empty result to indicate failure
        }

        return result;
    }

private:
    void traverseGraph(unordered_map<int, stack<int>>& adjList, vector<vector<int>>& result, int node) {
        stack<int>& neighbors = adjList[node];
        while (!neighbors.empty()) {
            int nextNode = neighbors.top();
            neighbors.pop();
            traverseGraph(adjList, result, nextNode);
            result.push_back({node, nextNode});
        }
    }
};

int main() {
    int numPairs;
    cout << "Enter the number of pairs: ";
    cin >> numPairs;

    vector<vector<int>> pairs(numPairs);

    cout << "Enter the pairs (two integers separated by a space):" << endl;
    for (int i = 0; i < numPairs; i++) {
        int first, second;
        cin >> first >> second;
        pairs[i] = {first, second};
    }

    Solution solution;
    vector<vector<int>> arrangement = solution.findValidArrangement(pairs);

    if (arrangement.empty()) {
        cout << "No arrangements possible." << endl;
    } else {
        cout << "Valid arrangement:" << endl;
        for (const auto& pair : arrangement) {
            cout << pair[0] << " " << pair[1] << endl;
        }
    }

    return 0;
}

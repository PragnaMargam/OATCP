#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 

class LargestNumberFinder {
    static bool compareStrings(string a, string b) {
        if (a + b > b + a) {
            return true;
        } else {
            return false;
        }
    }
public:
    string findLargestNumber(vector<int>& numbers) {
        int size = numbers.size();
        vector<string> numberStrings;
        for (int i = 0; i < size; i++) {
            string temp = to_string(numbers[i]);
            numberStrings.push_back(temp);
        }

        long long sum = 0;
        for (int i = 0; i < size; i++) {
            sum += numbers[i];
        }
        
        if (sum == 0) {
            return "0";
        } else {
            sort(numberStrings.begin(), numberStrings.end(), compareStrings);
            string result = "";
            for (int i = 0; i < size; i++) {
                result += numberStrings[i];
            }
            return result;
        }
    }
};

int main() {
    LargestNumberFinder finder;
    vector<int> numbers;
    int num;
    while (cin >> num) {
        numbers.push_back(num);
    }
    string largestNumber = finder.findLargestNumber(numbers);
    cout<<"output:"<<largestNumber;
    return 0;
}

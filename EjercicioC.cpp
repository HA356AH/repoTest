#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int process_test_case(int n, const vector<string>& bases) {
    int cuts = 0;
    set<char> current_intersection(bases[0].begin(), bases[0].end());

    for (int i = 1; i < n; ++i) {
        set<char> new_set(bases[i].begin(), bases[i].end());
        set<char> temp;

        // Compute intersection
        set_intersection(
            current_intersection.begin(), current_intersection.end(),
            new_set.begin(), new_set.end(),
            inserter(temp, temp.begin())
        );

        if (temp.empty()) {
            cuts++;
            current_intersection = new_set;
        } else {
            current_intersection = temp;
        }
    }

    return cuts;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> bases(n);
        for (int i = 0; i < n; ++i) {
            cin >> bases[i];
        }
        cout << process_test_case(n, bases) << '\n';
    }
    return 0;
}
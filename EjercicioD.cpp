#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Precalcula todos los factoriales menores o iguales a 100000
vector<int> precompute_factorials(int max_n) {
    vector<int> factorials;
    int fact = 1;
    for (int i = 1; fact <= max_n; ++i) {
        fact *= i;
        if (fact > max_n) break;
        factorials.push_back(fact);
    }
    return factorials;
}

int min_factorial_sum_count(int n, const vector<int>& factorials) {
    int count = 0;
    int remaining = n;
    for (int i = factorials.size() - 1; i >= 0 && remaining > 0; --i) {
        while (factorials[i] <= remaining) {
            remaining -= factorials[i];
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> factorials = precompute_factorials(100000);
    
    int n;
    while (cin >> n) {
        cout << min_factorial_sum_count(n, factorials) << "\n";
    }

    return 0;
}

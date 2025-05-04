#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int SHIFT = 40000;
const int MAXN = 80005;

long long plus_sign[2][MAXN];
long long minus_sign[2][MAXN];

void solve(int n, int f, const vector<int>& A) {
    int roll = 0;
    memset(plus_sign, 0, sizeof(plus_sign));
    memset(minus_sign, 0, sizeof(minus_sign));
    
    plus_sign[roll][A[0] + SHIFT] = 1;
    minus_sign[roll][-A[0] + SHIFT] = 1;

    int L = -A[0] + SHIFT;
    int R = A[0] + SHIFT;

    for (int i = 1; i < n; ++i) {
        memset(plus_sign[1 - roll], 0, sizeof(plus_sign[0]));
        memset(minus_sign[1 - roll], 0, sizeof(minus_sign[0]));
        for (int j = L; j <= R; ++j) {
            if (plus_sign[roll][j] || minus_sign[roll][j]) {
                int k = j + A[i];
                plus_sign[1 - roll][k] |= plus_sign[roll][j] | (1LL << i);
                minus_sign[1 - roll][k] |= minus_sign[roll][j];

                k = j - A[i];
                plus_sign[1 - roll][k] |= plus_sign[roll][j];
                minus_sign[1 - roll][k] |= minus_sign[roll][j] | (1LL << i);
            }
        }
        L -= A[i];
        R += A[i];
        roll = 1 - roll;
    }

    long long a = plus_sign[roll][f + SHIFT];
    long long b = minus_sign[roll][f + SHIFT];

    if (a == 0 && b == 0) {
        cout << "*\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        bool used_plus = (a >> i) & 1;
        bool used_minus = (b >> i) & 1;
        if (used_plus && used_minus)
            cout << "?";
        else if (used_plus)
            cout << "+";
        else
            cout << "-";
    }
    cout << "\n";
}

int main() {
    int n, f;
    vector<int> A(50);
    while (cin >> n >> f && n) {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        solve(n, f, A);
    }
    return 0;
}

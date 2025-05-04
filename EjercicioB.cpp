#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N, K;
        cin >> N >> K;
        vector<int> X(N), Y(N);
        for (int i = 0; i < N; ++i) cin >> X[i];
        for (int i = 0; i < N; ++i) cin >> Y[i];

        vector<int> profit(N);
        for (int i = 0; i < N; ++i)
            profit[i] = Y[i] - X[i];

        // Ordenamos ganancias de menor a mayor
        sort(profit.begin(), profit.end());

        long long total = 0;

        // Omitimos los K peores si hay pérdida o poca ganancia
        int start = 0;
        while (K > 0 && start < N && profit[start] < 0) {
            start++;
            K--;
        }

        for (int i = start; i < N; ++i)
            total += profit[i];

        if (total > 0)
            cout << "Case " << tc << ": " << total << '\n';
        else
            cout << "Case " << tc << ": No Profit\n";
    }

    return 0;
}
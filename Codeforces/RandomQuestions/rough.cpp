#include <iostream>
#include <cmath>

const long long MOD = 1000000007;

// long long mod_exp(long long base, long long exp, long long mod) {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return result;
// }

// long long drawingEdge(int n) {
//     long long edges = (n * (n - 1)) / 2;
//     return mod_exp(2, edges, MOD);
// }

int drawingEdge(int n)
{
    long long a = (n * (n - 1)) / 2;
    long long ans = 1;
    long long b = 2;
    while (a > 0)
    {
        if (a % 2 == 1)
        {
            ans = (ans * b) % MOD;
        }
        b = (b * b) % MOD;
        a /= 2;
    }
    return (int)ans;
}

int main()
{
    int n = 100;
    std::cout << drawingEdge(n) << std::endl;
    return 0;
}

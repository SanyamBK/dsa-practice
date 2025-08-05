#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

struct u128 {
    uint64_t low;
    uint64_t high;

    // Constructors
    u128() : low(0), high(0) {}
    u128(uint64_t low, uint64_t high) : low(low), high(high) {}
    u128(uint64_t value) : low(value), high(0) {}

    // Compound assignment operators
    u128& operator/=(const u128& other) {
        *this = *this / other;
        return *this;
    }

    // Comparison operators
    bool operator>=(const u128& other) const {
        return (high > other.high) || (high == other.high && low >= other.low);
    }

    // Multiplication operator
    u128 operator*(const u128& other) const {
        u128 result;
        uint64_t a0 = low & 0xFFFFFFFFULL;
        uint64_t a1 = low >> 32;
        uint64_t b0 = other.low & 0xFFFFFFFFULL;
        uint64_t b1 = other.low >> 32;

        uint64_t prod0 = a0 * b0;
        uint64_t prod1 = a0 * b1 + a1 * b0;
        uint64_t prod2 = a1 * b1;

        result.low = prod0 + (prod1 << 32) + (prod2 << 64);
        result.high = (prod1 >> 32) + (prod2 >> 32);

        result.high += (result.low < prod0) + (result.low < (prod1 << 32));

        result.low += (prod1 << 32);
        result.high += (result.low < (prod1 << 32));

        return result;
    }

    // Modulus operator
    u128 operator%(const u128& other) const {
        return *this - (*this / other) * other;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const u128& x) {
        os << x.high << " " << x.low;
        return os;
    }
};

#define ll u128

void testCase()
{
    int n; ll m;
    cin >> n;
    cin >> m;
    vector<ll> a(n);
    ll product = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        product = (product * a[i]);
    }
    string s;
    cin >> s;

    vector<ll> ans;
    ll rem = product % m;
    ans.push_back(rem);

    int i = 0;
    int k = 0;
    int j = n - 1;
    while (k < n - 1)
    {
        if (s[k] == 'R')
        {
            product /= a[j];
            rem = product % m;
            ans.push_back(rem);
            j--;
        }
        else if (s[k] == 'L')
        {
            product /= a[i];
            rem = product % m;
            ans.push_back(rem);
            i++;
        }
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        testCase();
    }
    return 0;
}

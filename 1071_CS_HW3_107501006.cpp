#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

int power(int x, unsigned int y, int p) {
    /*
        A function returns (x^y)%p
        @param  <int> x
        @param  <unsigned int> y
        @param  <int> p
        @return <int> (x^y)%p
    */
    int res = 1;
    x %= p;

    while (y > 0) {
        if (y % 2) res = (res * x) % p;

        y /= 2;
        x = (x * x) % p;
    }
    return res;
}

bool miillerTest(int d, int n) {
    /*
        This function should be called for all k trials.
        Returns false if n is composite or if n is probably prime.

        @param  <int> d An odd number s.t. d*2^r = n-1 for some r >= 1.
        @param  <int> n
        @return <bool> miillerTest
    */
    int a = 2 + rand() % (n - 4);  // Pick a random number in [2..n-2], n > 4

    int x = power(a, d, n);

    if (x == 1 || x == n - 1) return true;

    // Keep squaring x if one of the following doesn't happen
    // 1. d < n-1
    // 2. (x^2) % n != 1
    // 3. (x^2) % n != n-1
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;

        if (x == 1) return false;
        if (x == n - 1) return true;
    }

    return false;  // composite
}

bool isPrime(int n, int k) {
    /*
        A function judges if an integer may be a prime or not.
        Returns false if n is composite.
        Returns true if n is probably prie.

        @param  <int> n
        @param  <int> k A param which determines accuracy level. The higher the
                        more accuracy.
        @return <bool>
    */
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Find r s.t. n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0) d /= 2;

    for (int i = 0; i < k; i++)
        if (!miillerTest(d, n)) return false;

    return true;
}

template<typename InputIt>
string join(InputIt       begin,
            InputIt       end,
            const string& separator = ", ",  // see 1.
            const string& concluder = "")    // see 1.
{
    ostringstream ss;

    using value_type = typename iterator_traits<InputIt>::value_type;

    copy(begin, end - 1, ostream_iterator<value_type>(ss, separator.c_str()));

    ss << *(end - 1) << concluder;
    return ss.str();
}

int main() {
    int         k = 4;
    vector<int> primes;

    cout << "All primes < 100: " << endl;
    for (int n = 1; n < 100; n++)
        if (isPrime(n, k)) primes.push_back(n);

    cout << join(primes.begin(), primes.end()) << endl;
    return 0;
}
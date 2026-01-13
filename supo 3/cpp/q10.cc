#include <iostream>
using namespace std;

template <unsigned int n, unsigned int d, bool stop = (d*d > n)>
struct checkDivis {
    enum { value = n%d == 0 ? 0 : checkDivis<n, d+1>::value };
};

template <unsigned int n, unsigned int d>
struct checkDivis<n, d, true> {
    enum { value = 1 };
};

template <unsigned int n> struct prime {
    enum { value = checkDivis<n, 2>::value };
};

template <> struct prime<0> {
    enum {value = 0};
};

template <> struct prime<1> {
    enum {value = 0};
};

int main() {
    // Will only work if the value is defined at compile time
    constexpr int prime58603 = prime<58603>::value;
    cout << "58603 prime? " << (prime58603 == 1 ? "Yes" : "No") << "\n";

    cout << "0 prime? " << (prime<0>::value == 1 ? "Yes" : "No") << "\n";
    cout << "1 prime? " << (prime<1>::value == 1 ? "Yes" : "No") << "\n";
    cout << "2 prime? " << (prime<2>::value == 1 ? "Yes" : "No") << "\n";
    cout << "3 prime? " << (prime<3>::value == 1 ? "Yes" : "No") << "\n";
    cout << "4 prime? " << (prime<4>::value == 1 ? "Yes" : "No") << "\n";
    cout << "5 prime? " << (prime<5>::value == 1 ? "Yes" : "No") << "\n";
    cout << "6 prime? " << (prime<6>::value == 1 ? "Yes" : "No") << "\n";
    cout << "7 prime? " << (prime<7>::value == 1 ? "Yes" : "No") << "\n";
    cout << "8 prime? " << (prime<8>::value == 1 ? "Yes" : "No") << "\n";
    cout << "9 prime? " << (prime<9>::value == 1 ? "Yes" : "No") << "\n";
    cout << "10 prime? " << (prime<10>::value == 1 ? "Yes" : "No") << "\n";
    cout << "7919 prime? " << (prime<7919>::value == 1 ? "Yes" : "No") << "\n";
    cout << "31039 prime? " << (prime<31039>::value == 1 ? "Yes" : "No") << "\n";
    cout << "58603 prime? " << (prime<58603>::value == 1 ? "Yes" : "No") << "\n";
    cout << "58607 prime? " << (prime<58607>::value == 1 ? "Yes" : "No") << "\n";

    return 0;
}
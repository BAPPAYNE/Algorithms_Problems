#include <iostream>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <chrono>

using namespace boost::multiprecision;
using namespace std;

int main(int argc, char const *argv[])
{
    using big_float = cpp_bin_float_100;

    big_float a;
    cout << "Enter a number: ";
    cin >> a;

    if (a < 0) {
        cout << "Error: Cannot compute square root of a negative number." << endl;
        return 1;
    }

    uint64_t digits;
    cout << "Digits after point: ";
    cin >> digits;

    auto start = chrono::high_resolution_clock::now();
    
    big_float b = a * boost::multiprecision::pow(big_float(10), digits*2); // Scale the number: multiply by 10^(2*digits) to preserve precision
    big_float i = 0;
    for (i = 1; i * i <= b; ++i);
    big_float n = i - 1;
    n = n / boost::multiprecision::pow(big_float(10), digits); // Divide by 10^(digits) to adjust for decimal places

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Square Root: " << n << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}

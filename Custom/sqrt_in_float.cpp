#include <iostream>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <chrono>
#include <cmath>
using namespace boost::multiprecision;
using namespace std;
int main(int argc, char const *argv[])
{
    cpp_bin_float_double_extended a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "Digits after point : ";
    uint1024_t digits;
    cpp_bin_float_double_extended b = a * pow(10, digits * 2); // Multiply by 10^(2*(digits after point))
    cpp_bin_float_double_extended i = 0;
    for (i = 1; i * i <= b; i++);
    cpp_bin_float_double_extended n = i - 1;
    n = n / pow(10, digits); // Divide by 10^(digits after point)
    std::cout << "Square Root : " << n << std::endl;

    return 0;
}

#include<iostream>
#include<boost/multiprecision/cpp_bin_float.hpp>
#include<chrono>

using namespace boost::multiprecision;
using namespace std;
using big_float = cpp_bin_float_100;

big_float func(big_float x,big_float N){
    return x*x - N ;
}

big_float sqrt_Newton_Raphson(big_float N){

    if (N < 0) {
        // Handle error (e.g., throw exception or return NaN)
        throw std::invalid_argument("Cannot compute square root of negative number");
    }
    if(N == 0 || N == 1){
        return N;
    }
    big_float c;
    c = N - (N/2) + 1/2;

    uint1024_t count = 3;

    while(count){
        c = c - func(c,N)/(2*c) ;
        count--;
    }
    return c;
}

// big_float newton_Raphson(big_float N, int precision_digits = 200) {
//     // Handle edge cases
//     if (N < 0) {
//         // Handle error (e.g., throw exception or return NaN)
//         throw std::invalid_argument("Cannot compute square root of negative number");
//     }
//     if (N == 0 || N == 1) {
//         return N;
//     }

//     // Better initial guess
//     big_float c = N / 2; // Simpler and often closer to sqrt(N)

//     // Convergence threshold (e.g., 10^-precision_digits)
//     big_float epsilon = big_float(1) / pow(10,precision_digits);

//     // Iterate until convergence
//     while (true) {
//         big_float error = func(c, N); // x^2 - N
//         if (abs(error) < epsilon) {
//             break; // Converged
//         }
//         big_float derivative = 2 * c;
//         if (derivative == 0) {
//             throw std::runtime_error("Division by zero in Newton-Raphson");
//         }
//         c = c - error / derivative;
//     }

//     return c;
// }

int main(int argc, char const *argv[])
{
    big_float N;
    printf("Enter number : ");
    cin >> N;
    cout.precision(500);    // set precision for printing max length after point.
    auto T1 = chrono::high_resolution_clock::now() ;
    cout << "Sqrt(" << N << ") = " << sqrt_Newton_Raphson(N) << endl;
    auto diff = chrono::high_resolution_clock::now() - T1;
    cout << "Executing time: "<<chrono::duration_cast<chrono::milliseconds> (diff).count() << " miliseconds" ;
    return 0;
}

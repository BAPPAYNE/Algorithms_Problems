/*
Approximate root of the equation 2x3-2x-5=0 using False Position mehtod is 1.60056
n    x0          f(x0)       x1  f(x1)       x2 f(x2)    Update
-----------------------------------------------------------------
1    1           -5 2        7   1.41667     -2.14699    x0=x2
2    1.41667     -2.14699    2   7 1.55359   -0.60759    x0=x2
3    1.55359     -0.60759    2   7 1.58924   -0.15063    x0=x2
4    1.58924     -0.15063    2   7 1.59789   -0.0361     x0=x2
5    1.59789     -0.0361     2   7 1.59996   -0.00858    x0=x2
6    1.59996     -0.00858    2   7 1.60045   -0.00203    x0=x2
7    1.60045     -0.00203    2   7 1.60056   -0.00048    x0=x2
.       .           .        .      .           .          .
.       .           .        .      .           .          .
.       .           .        .      .           .          .

*/

#include<boost/multiprecision/cpp_bin_float.hpp>
#include<iostream>
#include<chrono>

using namespace std;
using namespace boost::multiprecision;
using big_float  = cpp_bin_float_100;

big_float func(big_float N,big_float x){
    return x*x - N ;
}

big_float regula_Falsi(big_float N){
    if (N == 0 || N == 1){
        return N;
    }
    if(N<0){
        cerr << "\033[0;31mN cannot be negative. \033[0m" << endl ;
        return 0;
    }
    big_float a,b,c;
    if(N > 1){
        b = N;  a = 0;
    }else{
        a = N;  b = 0;
    }

    long long count = 99999;
    while(count){   // count - Looping or iteration variable.
        // c = (a*func(N,b) - b*func(N,a))/(func(N,b)-func(N,a)) ; // 4 function calls
        // Checking bisection method condition and updating $a and $b accordingly.
        c = (b - (func(N,b)*(b-a))/(func(N,b) - func(N,a))) ;   // 3 function calls (more efficient)
        if(func(N,c) > 0){
            a = c ;
        }else{
            b = c ;
        }
        count--;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    big_float N;
    printf("Enter number : ");
    cin >> N;
    cout.precision(500);    // set precision for printing max length after point.
    auto T1 = chrono::high_resolution_clock::now() ;
    cout << "Sqrt(" << N << ") = " << regula_Falsi(N) << endl;
    auto diff = chrono::high_resolution_clock::now() - T1;
    cout << "Executing time: "<<chrono::duration_cast<chrono::milliseconds> (diff).count() << " miliseconds" ;
    return 0;
}

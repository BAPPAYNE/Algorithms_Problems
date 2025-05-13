#include<iostream>
#include<boost/multiprecision/cpp_bin_float.hpp>
#include<chrono>
// #include<conio.h>
// #include<Windows.h>
using namespace boost::multiprecision ;
using namespace std;
using big_float =  cpp_bin_float_100 ;

big_float func(big_float N,big_float x){
    return x*x - N ;
}

int main(int argc, char const *argv[])
{
    big_float N ;
    std::cout << "Enter number : " ;
    std::cin >> N ;
    
    auto T1 = chrono::high_resolution_clock::now() ;

    int8_t ERROR_MSG = 12 ;
    big_float x ;
    big_float a, b, c ;
    cout.precision(500) ;       // set precision for printing max length after point.
    if(N<0){
        cerr << "\033[0;31mN cannot be negative. \033[0m" << endl ;
        auto diff = chrono::high_resolution_clock::now() - T1;
        cout << "Executing time: "<<chrono::duration_cast<chrono::milliseconds> (diff).count() << " miliseconds" ;
        return 0;
    }
    if(N > 1){
        a = 0;  b = N;
    }else{
        a = N;  b = 1;
    }
    long long count = 9999;
    while(count){               // count - Looping or iteration variable.
        c = a + (b-a)/2.0;
        if(func(N,a)*func(N,c) < 0){        // Checking bisection method condition and updating $a and $b accordingly.
            b = c;
        }else{
            a = c ;
        }
        count-- ;
    }
    cout << "Sqrt(" << N << ") = " << c << endl;
    auto diff = chrono::high_resolution_clock::now() - T1;
    cout << "Executing time: "<<chrono::duration_cast<chrono::milliseconds> (diff).count() << " miliseconds" ;
    return 0;
}

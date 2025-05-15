
/*  
        Bisection Method to calculate sqrt.(Binary Search Concept)
n	a	        f(a)	    b	        f(b)	    c=a+b2	    f(c)	    Update
---------------------------------------------------------------------------------------
1	3	        -3	        4	        4	        3.5	        0.25	    b=c
2	3	        -3	        3.5	        0.25	    3.25	    -1.4375	    a=c
3	3.25	    -1.4375	    3.5	        0.25	    3.375	    -0.6094	    a=c
4	3.375	    -0.6094	    3.5	        0.25	    3.4375	    -0.1836	    a=c
5	3.4375	    -0.1836	    3.5	        0.25	    3.4688  	0.0322	    b=c
6	3.4375	    -0.1836	    3.4688	    0.0322	    .4531	    -0.0759	    a=c
7	3.4531	    -0.0759	    3.4688	    0.0322	    3.4609	    -0.0219	    a=c
8	3.4609	    -0.0219	    3.4688	    0.0322	    3.4648  	0.0051	    b=c
9	3.4609	    -0.0219	    3.4648	    0.0051	    3.4629	    -0.0084	    a=c
10	3.4629	    -0.0084	    3.4648	    0.0051	    3.4639	    -0.0016	    a=c
11	3.4639	    -0.0016	    3.4648	    0.0051	    3.4644  	0.0018	    b=c
12	3.4639	    -0.0016	    3.4644	    0.0018	    3.4641  	0.0001	    b=c
.     .             .         .            .          .           .          .
.     .             .         .            .          .           .          .
.     .             .         .            .          .           .          .

*/

#include<iostream>
#include<boost/multiprecision/cpp_bin_float.hpp>
#include<chrono>

using namespace boost::multiprecision ;
using namespace std;
using big_float =  cpp_bin_float_100 ;

big_float func(big_float N,big_float x){
    return x*x - N ;
}

big_float bisection(big_float N){
    if (N == 0 || N == 1){
        return N;
    }
    if(N<0){
        cerr << "\033[0;31mN cannot be negative. \033[0m" << endl ;
        return 0;
    }
    big_float x ;
    big_float a, b, c ;
    cout.precision(500) ;       // set precision for printing max length after point.
    if(N<0){
        cerr << "\033[0;31mN cannot be negative. \033[0m" << endl ;
        return 0;
    }
    if(N > 1){
        a = 0;  b = N;
    }else{
        a = N;  b = 1;
    }
    long long count = 99;
    while(count){               // count - Looping or iteration variable.
        c = a + (b-a)/2.0;
        if(func(N,a)*func(N,c) < 0){        // Checking bisection method condition and updating $a and $b accordingly.
            b = c;
        }else{
            a = c ;
        }
        count-- ;
    }
    return c ;
}

int main(int argc, char const *argv[])
{
    big_float N ;
    std::cout << "Enter number : " ;
    std::cin >> N ;
    
    auto T1 = chrono::high_resolution_clock::now() ;
    
    cout << "Sqrt(" << N << ") = " << bisection(N) << endl;
    auto diff = chrono::high_resolution_clock::now() - T1;
    cout << "Executing time: "<<chrono::duration_cast<chrono::milliseconds> (diff).count() << " miliseconds" ;
    
    /*
    PS D:\BAPPAYNE D\CP\Algorithms_Problems\Custom> .\sqrt_bisection.exe
    Enter number : 52
    Sqrt(52) = 7.2111025509279785862384425349863725619364006117022384656327360641370205485145561397075653076171875
    Executing time: 4 miliseconds
    */
    return 0;
}


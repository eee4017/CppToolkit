#include <bits/stdc++.h>
#include <chrono> 
using namespace std;

// accumulative timer with elt as a double
#define TIMER_START(elt) \
        { \
            auto start = chrono::high_resolution_clock::now();
#define TIMER_END(elt) \
            auto end = chrono::high_resolution_clock::now(); \
            elt += chrono::duration_cast<chrono::nanoseconds>(end - start).count(); \
        }

// speedup of two timers
#define PRINT_SPEEDUP(x, y) \
    cout << setprecision(12) << x << " ns\n"; \
    cout << setprecision(12) << y << " ns\n"; \
    cout << "(1 - "#x" / "#y")\tSpeedup:\t" << (1 - x / y)*100 << " %\n";

// test if two double array are same
#define PRINT_ARRAY_SIZE 100
#define PRINT_ARRAY(a) \
    cout << #a" :"; \
    for(int i= 0;i < PRINT_ARRAY_SIZE;i++) cout << a[0][i] << " \n"[i==PRINT_ARRAY_SIZE-1]; 
#define PRINT_ERROR(TITLE, a, b, size) \
    { \
        double error = 0; \
        for(int i = 0;i < n; i ++) error += ((double *)b)[i] - ((double *)a)[i];\
        cout << TITLE" error :" << error << "\n\n"; \
    }

#include <chrono> 
#include <iostream>
// accumulative timer with elt as a double
// return: ms
#define timerStart(elt) \
        { \
            auto _start_##elt = std::chrono::high_resolution_clock::now(); \
#define timerStop(elt) \
            auto _end_##elt = std::chrono::high_resolution_clock::now(); \
            elt += (std::chrono::duration_cast<std::chrono::nanoseconds>(_end_##elt - _start_##elt).count()) * 1e-6; \
        }

#define cudaTimerStart(elt) \
{ \
    cudaEvent_t _start_##elt, _stop_##elt; \
    cudaEventCreate(&_start_##elt); \
    cudaEventCreate(&_stop_##elt); \
    cudaEventRecord(_start_##elt);

#define cudaTimerStop(elt) \
    cudaEventRecord(_stop_##elt); \
    cudaEventSynchronize(_stop_##elt); \
    float _ms_##elt = 0; \
    cudaEventElapsedTime(&_ms_##elt, _start_##elt, _stop_##elt); \
    elt += _ms_##elt; \
}

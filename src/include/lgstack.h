#ifndef lgstack_h
#define lgstack_h
#include <cassert>

namespace gpu_linearized_stl{
    /*
    Here we use array to implement the stack which can be used on gpu.
    This stack contains the following member functions:
        empty();
        size();
        top();
        push(g);
        pop();
    */
    template<typename T, const int MAX_SIZE = 128>
    struct stack{
        /* T should have copy operator or copy constructor */
        T container[MAX_SIZE];
        int stk_size;
    public:
        __device__ stack(): stk_size(0) {}
        __device__ bool empty(){
            return !stk_size;
        }
        __device__ int size(){
            return stk_size;
        }
        __device__ int max_size(){
            return MAX_SIZE;
        }
        __device__ T top(){
            assert(stk_size);
            return container[stk_size - 1];
        }
        __device__ void push(const T&val){
            assert(stk_size < MAX_SIZE);
            container[stk_size] = val;
            ++stk_size;
        }
        __device__ void pop(){
            assert(stk_size);
            --stk_size;
        }
    };
}

#endif
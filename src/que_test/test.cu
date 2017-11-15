#include <iostream>
#include "../include/gpu_queue.h"
#include <thrust/device_vector.h>
#define def_dvec(t) thrust::device_vector<t>
#define to_ptr(x) thrust::raw_pointer_cast(&x[0])
using namespace std;
const int MAX_QUEUE_SIZE = 50;

__global__ void test(float *output){
    gpu_queue<float, MAX_QUEUE_SIZE> que;
    for(int i=1;i<=MAX_QUEUE_SIZE;++i){
        que.push(1.7*i);
    }
    int idx = 0, k = 0;
    while(!que.empty()){
        que.pop_k(k);
        if(que.empty()) return;
        output[idx] = que.front();
        idx += 1;
        output[idx] = que.back();
        k += 1;
        idx += 1;
    }
}

int main(){
    def_dvec(float) dev_out(40, 0);
    test<<<1, 1>>>(to_ptr(dev_out));
    for(auto k:dev_out) cout<<k<<' ';
    cout<<endl;
    return 0;
}

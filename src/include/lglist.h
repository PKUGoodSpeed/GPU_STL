#ifndef lglist_h
#define lglist_h
#include <cassert>

namespace gpu_linearized_stl{
    /*
    Here we use array to implement linked listed, which can be used on GPU.
    We define a node and iterator within the list struct.
    This list contains the following member functions:
        empty()
        size()
        begin()
        end()
        front()
        back()
        push_front(val)
        push_back(val)
        pop_front()
        pop_back()
        insert(iterator, val)
        find(val)
        erase(iterator)
        reverse()
        clear()
    So far the sort() function and mergeSort() function does not work properly.
    */
    template<typename T, const int MAX_SIZE>
    struct list{
        /* Nodes on the list, we use integers to denote next and prev */
        ListNode{
            T val;
            int prev, next;
            __device__ ListNode(const T&v, int p, int n): val(v), prev(p), next(n) {}
        };
        ListNode container[MAX_SIZE];
    };
}

#endif
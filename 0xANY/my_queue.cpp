/**
 * array based queue
 */
#include<iostream>
#include<vector>

using namespace std;

struct my_queue {
    int size;
    int capacity;
    int head, tail;
    vector<int> data;

    my_queue (int n) {
        data.resize(n);
        size = 0;
        head = tail = -1;
        capacity = n;
    }    
    bool empty() {
        return ( (this->size == 0) ? true : false );
    }

    bool full() {
        return ( (this->size == this->capacity) ? true : false);
    }

    int size() {
        return this->size;
    }

    int enqueue (int x) {
        if (this->full()) {
            return -1;
        }
        if (empty()) {
            head = 0;
        }
        tail = (tail + 1) % this->capacity;
        data[tail] = x;
        size++;
    }

    int dequeue () {
        if (this->empty()) {
            return -1;
        }
        int ret = data[head];
        head = (head+1) % capacity;
        if (head == tail) {
            head = tail = -1;
        }
        size--;
        return ret;
    }
}
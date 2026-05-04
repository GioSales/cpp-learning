//
// Created by Giovanni on 04/13/2026.
//

#ifndef LEARNING_DYNAMICARRAY_H
#define LEARNING_DYNAMICARRAY_H
#include <memory>


class DynamicArray {
    std::unique_ptr<int[]> arr;
    int cap;
    int arrSize;


public:
    DynamicArray(const int capacity) {
        arr = std::make_unique<int[]>(capacity);
        cap = capacity;
        arrSize = 0;
    }

    int get(const int i) const {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (arrSize == cap) {
            resize();
        }

        arr[arrSize] = n;
        arrSize++;
    }

    int popback() {
        const auto val = arr[arrSize - 1];
        arrSize--;
        return val;
    }

    void resize() {
        int newCap = cap * 2;
        auto newArr = std::make_unique<int[]>(newCap);
        for (int i = 0; i < arrSize; i++) {
            newArr[i] = arr[i];
        }
        cap = newCap;
        arr = std::move(newArr);
    }

    int getSize() const {
        return arrSize;
    }

    int getCapacity() const {
        return cap;
    }
};




#endif //LEARNING_DYNAMICARRAY_H

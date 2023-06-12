#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H

struct DynamicArray {
    int *arr;
    int size;
    int capacity;
};

void initialize_dynamic_array(struct DynamicArray *this) {
    this->arr = NULL;
    this->size = 0;
    this->capacity = 0;
}

int size(struct DynamicArray *this) {
    return this->size;
}

int capacity(struct DynamicArray *this) {
    return this->capacity;
}

bool empty(struct DynamicArray *this) {
    return this->size == 0;
}

void reserve(struct DynamicArray *this, int capacity) {
    if (capacity <= this->capacity) {
        return;
    }

    int *tmp = (int *) malloc(capacity * sizeof(int));
    if (tmp == NULL) {
        return;
    }

    for (int i = 0; i < this->size; ++i) {
        tmp[i] = this->arr[i];
    }

    free(this->arr);

    this->arr = tmp;
    this->capacity = capacity;
}

int at(struct DynamicArray *this, int index) {
    if (index < 0 || index >= this->size) {
        printf("Error: index is not valid\n");
        raise(SIGSEGV);
    }

    return this->arr[index];
}


void push_back(struct DynamicArray *this, int elem) {
    if (this->size == this->capacity) {
        if (this->capacity == 0) {
            this->capacity = 1;
        } else {
            this->capacity = this->capacity * 2;
        }

        if (this->arr == NULL) {
            this->arr = (int *) malloc(this->capacity * sizeof(int));
        } else {
            reserve(this, this->capacity);
        }
    }

    this->arr[this->size] = elem;
    ++(this->size);
}

bool insert(struct DynamicArray *this, int pos, int elem) {
    if (pos < 0 || pos > this->size)
        return false;

    if (this->size == this->capacity) {
        this->capacity *= 2;

        int *tmp = (int *) malloc(this->capacity * sizeof(int));
        if (tmp == NULL) {
            return false;
        }

        for (int i = 0; i < pos; ++i) {
            tmp[i] = this->arr[i];
        }

        tmp[pos] = elem;

        for (int i = pos; i < this->size; ++i) {
            tmp[i + 1] = this->arr[i];
        }

        free(this->arr);
        this->arr = tmp;
    } else {
        for (int i = this->size - 1; i >= pos; --i) {
            this->arr[i + 1] = this->arr[i];
        }

        this->arr[pos] = elem;
    }

    ++(this->size);
    return true;
}

#endif //DYNAMICARRAY_DYNAMICARRAY_H

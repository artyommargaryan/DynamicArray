# DynamicArray

DynamicArray is a simple implementation of a dynamic array in C. It allows you to create, manipulate, and resize arrays dynamically.

## Features

- Create an empty dynamic array
- Get the size and capacity of the array
- Check if the array is empty
- Reserve a specific capacity for the array
- Access elements at a given index
- Add an element to the end of the array
- Insert an element at a specified position

## Usage

To use the DynamicArray code, follow these steps:

1. Include the `DynamicArray.h` header file in your C program:

   ```c
   #include "DynamicArray.h"
   ```
   
2. Initialize a `struct DynamicArray` object:
    ```c
    struct DynamicArray array;
    initialize_dynamic_array(&array);
    ```
   
3. Start using the dynamic array functions. For example, you can add elements to the array using `push_back()`:
    ```c
    push_back(&array, 10);
    push_back(&array, 20);
    ```
   You can also insert an element at a specific position using `insert()`:
    ```c
    insert(&array, 1, 15);
    ```
   
4.  To free the memory allocated by the dynamic array when you're done use `deallocate()`:
   ```c
   deallocate(&array);
   ```

5. To reserve memory use `reserve()`:
   ```c
   int capacity = 10;
   reserve(&array, capacity);
   ```

6. To get element at some position use `at()`:
   ```c
   int pos = 0;
   at(&array, pos);
   ```
   
7. To get size, capacity or check if it is empty use `size()`, `capacity()` and `empty()`:
   ```c
   size(&array);
   capacity(&array);
   empty(&array);
   ```
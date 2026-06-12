# Data Structures Overview

A *data structure* is a way of organizing and storing data in memory so that it can be accessed and modified efficiently. Data structures form the foundation of computer science and are essential for writing optimized programs.

## Physical Data Structures

Physical data structures describe how data is actually stored in memory.

1. Arrays
2. Matrices
3. Linked Lists

## Logical Data Structures

Logical data structures define how data is organized and how operations are performed on it.

1. Stack
2. Queue
3. Tree
4. Graph
5. Hashing

## Abstract Data Structures

Abstract data structures focus on the behavior and operations of data rather than their implementation.

1. Set
2. Map
3. Dictionary
4. Hash Table
5. Heap
6. Priority Queue
7. Disjoint Set

---

## C/C++ Useful Concepts for Data Structures

Before learning advanced data structures, it is important to understand the following C/C++ concepts:

1. Arrays
2. Structures
3. Pointers
4. References
5. Parameter Passing
6. Classes and Objects
7. Constructors and Destructors

---

# Arrays

An array is a collection of elements of the same data type stored in contiguous memory locations. Each element can be accessed using its index.

### Syntax

```cpp
data_type array_name[array_size];
```

### Example

```cpp
int nums[5];
```

The above statement declares an array named `nums` that can store 5 integer values.

### Important Notes

* Array indexing starts from `0`.
* The first element is accessed using index `0`.
* The last element is accessed using `array_size - 1`.

### Strings in C

```cpp
char str[20];
```

* This array can store up to 19 characters plus the null terminator (`\0`).
* The null terminator marks the end of the string.

### Memory Allocation

* `malloc()` and `calloc()` allocate memory dynamically on the **heap** at runtime.
* Local variables are stored on the **stack** and exist only during the execution of the function in which they are declared.

---

## Stack Disadvantages

1. Limited size; stack overflow can occur if too much memory is used.
2. Does not support dynamic memory allocation for variable-sized data.
3. Memory is automatically released when the function scope ends.

---

## Heap Disadvantages

1. Memory fragmentation may occur over time.
2. Improper memory management can lead to memory leaks.
3. Accessing heap memory is generally slower than accessing stack memory.

---

## Disadvantages of Arrays

1. Arrays have a fixed size and cannot be resized during runtime.
2. Inserting or deleting elements in the middle requires shifting elements, resulting in **O(n)** time complexity.
3. Arrays do not provide automatic bounds checking.
4. All elements must be of the same data type.
5. Unused allocated space may lead to memory wastage.

---

> Arrays are simple, fast, and memory-efficient for storing fixed-size collections of data. However, their limitations led to the development of more flexible data structures such as linked lists, stacks, queues, trees, and graphs.

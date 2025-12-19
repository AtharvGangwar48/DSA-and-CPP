# Dynamic Memory Allocation in C++

## What is Dynamic Memory Allocation?

Dynamic memory allocation allows programs to request memory during runtime rather than compile time. Unlike static allocation (where memory size is determined at compile time), dynamic allocation provides flexibility to allocate and deallocate memory as needed.

## Key Concepts

### Stack vs Heap Memory
- **Stack**: Fast, automatic management, limited size, local variables
- **Heap**: Slower, manual management, larger size, dynamic allocation

### Memory Allocation Operators
- `new`: Allocates memory and calls constructor
- `delete`: Calls destructor and deallocates memory
- `new[]`: Allocates array of objects
- `delete[]`: Deallocates array of objects

## Files Overview

### 1. `1_basic_new_delete.cpp`
- Basic usage of `new` and `delete`
- Single variable allocation
- Dynamic array allocation
- Proper cleanup practices

### 2. `2_dynamic_2d_array.cpp`
- Two methods for 2D array allocation
- Array of pointers approach
- Single allocation with index calculation
- Memory cleanup for 2D arrays

### 3. `3_memory_leaks_demo.cpp`
- Common memory management mistakes
- Memory leak examples
- Dangling pointer issues
- Best practices for avoiding problems

### 4. `4_dynamic_functions.cpp`
- Functions returning dynamic arrays
- Passing dynamic arrays to functions
- Array resizing techniques
- Function-based memory management

### 5. `5_smart_pointers_intro.cpp`
- Modern C++ approach (C++11+)
- `unique_ptr` for single ownership
- `shared_ptr` for shared ownership
- Automatic memory management
- Smart pointers with arrays

## Best Practices

1. **Always pair `new` with `delete`**
   ```cpp
   int *ptr = new int(42);
   delete ptr;
   ```

2. **Use `delete[]` for arrays**
   ```cpp
   int *arr = new int[10];
   delete[] arr;
   ```

3. **Set pointers to nullptr after deletion**
   ```cpp
   delete ptr;
   ptr = nullptr;
   ```

4. **Prefer smart pointers in modern C++**
   ```cpp
   unique_ptr<int> ptr = make_unique<int>(42);
   ```

5. **Check for allocation failure**
   ```cpp
   int *ptr = new(nothrow) int[1000000];
   if (!ptr) {
       // Handle allocation failure
   }
   ```

## Common Pitfalls

- **Memory Leaks**: Forgetting to call `delete`
- **Double Deletion**: Calling `delete` twice on same pointer
- **Dangling Pointers**: Using pointer after deletion
- **Array/Non-array Mismatch**: Using `delete` instead of `delete[]`

## Compilation Commands

```bash
# Compile individual files
g++ -o basic 1_basic_new_delete.cpp
g++ -o 2d_array 2_dynamic_2d_array.cpp
g++ -o leaks 3_memory_leaks_demo.cpp
g++ -o functions 4_dynamic_functions.cpp

# For smart pointers (requires C++11 or later)
g++ -std=c++11 -o smart 5_smart_pointers_intro.cpp
```

## When to Use Dynamic Allocation

- Array size unknown at compile time
- Large data structures that might exceed stack size
- Objects that need to persist beyond their creation scope
- Implementing data structures like linked lists, trees
- When you need precise control over object lifetime
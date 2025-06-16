# Namespace

- The primary purpose of a namespace in C++ is to **avoid naming conflicts** by organizing code into logical groups.
- There might me 2 different libraries in which there might be same method name with same signatur, which can cause a conflict.
```cpp
namespace LibraryA {
    int print();
    class Logger {};
}

namespace LibraryB {
    int print();
    class Logger {};
}

// not no conflict
LibraryA::Logger a;
LibraryB::Logger b;
```

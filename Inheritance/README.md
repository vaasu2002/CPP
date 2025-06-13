```cpp
class Base {
public:
    ~Base() { cout << "Base destructor\n"; }  // Non-virtual
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor\n"; }
};
```
CASE 1 (ALL GOOD)
```cpp
// stack object, first Derived destructor called then Base destructor called
Derived d;
```

CASE 2 (ALL GOOD)
```cpp
// heap object(but stack pointer)
first Derived destructor called then Base destructor called
Derived* ptr = new Derived();
```

CASE 3 (PROBLEM)
```cpp
Base* ptr = new Derived();  // Polymorphic pointer
delete ptr; // 
// What typically happens:
// Output: "Base destructor" only
// Derived destructor is NOT called!
```


#### Without virtual destructor:
- The compiler looks at the static type of the pointer (Base*)
- Only calls the destructor for that static type (Base::~Base())
- Never calls Derived::~Derived()

#### With virtual destructor:

- Runtime polymorphism kicks in
- Looks at the actual object type (Derived)
- Calls Derived::~Derived() first, then Base::~Base()

```cpp
Somethings(const Somethings& somethings) = delete; // Deleted copy constructor
// No Copying Allowed
```


```cpp

class Base{
public:
    Base() = default;
    Base(const Base& obj){ // receives only the references
        cout<<&obj<<endl;
        cout<<"calling copy constructor..."<<endl;
    }
};

int main(){
    // stack copping
    Base b1;
    Base b2 = b1;

    // heap copying  
    Base* b3 = new Base();
    Base* b4 = new Base(*b3); // takes in full object
    cout<<b3<<" "<<b4<<endl;

    Base* b5 = new Base();
    Base* b6 = b5;
    // b5 is memory in stack point to same b5 object as b5(which is also a memory in stack is pointing to object in heap)
}
// b3 is a pointer pointing to heap
```

#### Copy Constrcutor using shared pointer
```cpp
#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        cout<<"calling default constructor..."<<endl;
    }
    Base(const Base& obj){
        cout<<&obj<<endl;
        cout<<"calling copy constructor..."<<endl;
    }
    ~Base(){
        cout<<"calling destructor..."<<endl;
    }
};


int main(){
    shared_ptr<Base> b1 = make_shared<Base>();
    cout<<b1<<endl; // heap address-> address of object
    cout<<&b1<<endl; // stack address-> address of pointer
    {
        // ❌ DOES NOT call copy constructor
        shared_ptr<Base> b2 = b1; // same address as b2 just another reference
        cout<<b2<<endl;
        // destructor won't be called as there is still one reference left
    }
    {
        shared_ptr<Base> b2 = make_shared<Base>(*b1);
        cout<<b1<<" "<<b2<<endl;
        // both are in different address of heap
        // b2 has one reference
        // b1 also has one reference
        // b2 destrcutor will be called after this scope
    }
}
```

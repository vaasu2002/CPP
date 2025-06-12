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

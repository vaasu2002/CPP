// shallow copy and the problem it causes with dynamic memory
// It copies the value of num.
// It copies the pointer value ptr, not what it points to.
// So both obj and obj2 have ptr pointing to the same heap memory.
// both will call delete[] ptr;, trying to free the same memory twice. This leads to undefined behavior, typically a crash or memory corruption.

#include <iostream>
using namespace std;
class Somethings{
public:
    int num;
    int* ptr;
    explicit Somethings(const int val){
        num=val;
        // new will always return a pointer to heap memory block
        ptr = new int(val);
    }
    ~Somethings(){
        cout<<"calling destructor..."<<endl;
        delete[] ptr;
    }
};
int main(){
    // so here we will be forming a new memory space and just coping
    // variables in object
    Somethings obj(12);
    Somethings obj2 = obj;
    cout<<&obj<<" "<<&obj2<<endl; // both are different memory address
    cout<<obj.num<<" "<<obj2.num<<endl; // value is same
    obj2.num = 20;
    cout<<obj.num<<" "<<obj2.num<<endl; // 12, 20 obj2 only changes

    cout<<obj.ptr<<" "<<obj2.ptr<<endl; // pointer is also copied
    // they both are pointing to same location on heap
    *obj.ptr = 50;
    cout<<*obj.ptr<<" "<<*obj2.ptr<<endl; // 50,50
    // Shallow copy is bit by bit copy things are copied as it is


    // IMP-> When we enable custom destructor and add delete[] ptr;
    // lets say first object get deleted and memory which pointer
    // points to get deleted as well

    // when obj2 is being deleted, the pointer now wants to delete the
    // same memory but its already deleted so its gives error
}

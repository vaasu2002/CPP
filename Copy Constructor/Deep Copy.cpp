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
    Somethings(const Somethings& somethings){
        this->num = somethings.num;
        this->ptr = new int(somethings.num);
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

    cout<<obj.ptr<<" "<<obj2.ptr<<endl; // DEEP COPY So pointer are pointing to different memory address
    cout<<*obj.ptr<<" "<<*obj2.ptr<<endl;  // but the value is still same

    // they both are pointing to same location on heap
    *obj.ptr = 50; // now value wont be same
    cout<<*obj.ptr<<" "<<*obj2.ptr<<endl; // 50,10
}

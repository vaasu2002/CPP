### When we create a std::thread with a member function, you need to provide both the member function and the object instance

```cpp
std::thread executeThread() {
    return std::thread(&Body::func, this); 
}
```

```cpp
class Body{
    int m_Id;
    void func() const{
        for(int i=0;i<10000;i++){
            std::cout<<"Function being executed in object id: "<<m_Id<<std::endl;
        }
    }
public:
    Body(int id):m_Id(id){}
    std::thread executeThread(){
        return std::thread(&Body::func,this);
    }
};

int main(){
    Body obj1(1);
    Body obj2(2);
    std::thread t1 = obj1.executeThread();
    std::thread t2 = obj2.executeThread();
    t1.join();
    t2.join();
}
```

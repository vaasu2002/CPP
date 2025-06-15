```cpp
class String{
public:
    char* m_Data;
    uint32_t m_Size;
    String(const char* str){
        cout<<"Created..."<<endl;
        m_Size = strlen(str)+1; // one extra space for null termination
        m_Data = new char[m_Size];
        memcpy(m_Data,str,m_Size);
    }
    String(const String& str){
        cout<<"Copying..."<<endl;
        // deep copy
        m_Size = str.m_Size+1;
        m_Data = new char[m_Size];
        memcpy(m_Data,str.m_Data,m_Size);
    }
};
class Entity{
    String m_Name;
public:
    Entity(const String& name):m_Name(name){ // m_Name(name) called copy constructor
    };
};
int main(){
    String str2 = "Vaasu"; // Created...
    String str("Vaasu"); // Created...
    Entity e(str);
}
```
If we remove explicit from constrcutor we can use like this as well ---> String str = "Vaasu";
```cpp
// "abc" is a string literal of type const char[4] (includes null terminator)
// str is pointer to a pointer to a constant character array.
// str-> abc | str+1 -> bc | *str = a
void fun(const char* str){
    // const mean we can edit array str2[0] = 'b' not allowed
    cout<<strlen(str)<<endl;
    // *str = 'g'; not allowed with const
}

int main(){
    // str is pointer in stack pointing to 4 sized char array which is in heap
    char* str = new char[4] {'a','b','c','\0'};
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = '\0';
    cout<<&str<<endl;

    const char* str2 = new char[4] {'a','b','c','\0'};
    // const mean we can edit array str2[0] = 'b' not allowed

    delete[] str;
    delete[] str2;
}
```

```

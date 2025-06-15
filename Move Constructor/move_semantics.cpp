class String{
public:
    char* m_Data;
    uint32_t m_Size;
    String(const char* str){
        cout<<"created"<<endl;
        m_Size = strlen(str);
        m_Data = new char[m_Size];
        memcpy(m_Data,str,m_Size);
    }
    String(const String& str){
        cout<<"Copy constructor called...."<<endl;
        // deep copy
        m_Size = str.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data,str.m_Data,m_Size);
    }
    String(String&& other) noexcept{ // takes in rvalue(temporary)
        cout<<"Move constructor called...."<<endl;
        // deep copy
        m_Size = other.m_Size;
        m_Data = other.m_Data; // just changing the pointer
        // new instance of string(m_Name) will just point to existing buffer of String we have
        // not creating a new memory and copying into it

        // here we still have 2 string instances, when old one gets deleted it will take buffer with it as well


        // so we need to take control of other String as well, from where we are stealing data here
        other.m_Size = 0;
        other.m_Data = nullptr;
        // now old Sting is hollow object, so it will be deleting then the nullptr won't affect new instance
    }
    ~String(){
        cout<<"Destructor called...."<<endl;
        delete[] m_Data;
    }
};

class Entity{
public:
    String m_Name;
    explicit Entity(const String& name) : m_Name(name){
        // m_Name = "Bisht";// calls constructor again
        // when I didn't write copy constructor
        // m_Name and str are shallow copy, pointing to same heap char array
    };

    // rvalue constructor (takes in temporary)
    explicit Entity(String&& name) : m_Name(move(name)){ // still copy being called as m_Name(name)
        // we need to explicititly cast String&& or static_cast<String&&>(name) or move
    };
};

int main(){
    // Inefficient as we do twice heap memory location of char array
    // first we are making a String object in scope of main function
    // allocating heap
    // then passing it into Entity constructor
    // then at this line m_Name(name) we need to copy it assign memory in heap again
    // so finally we can have it in here-> m_Name of Entity

    // Why not just allocate in main function and just move it into Entity
    // here we will use move semantics
    Entity e(String("Vaasu"));
    cout<<e.m_Name.m_Data<<endl;
    return 0;
}
// created
// Move constructor called....
// Destructor called....    -> temp object is being destroyed
// Vaasu
// Destructor called....

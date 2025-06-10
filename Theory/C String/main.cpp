// Null-Termination: The string must end with the special null character '\0',
// which tells functions where the string ends.

#include <iostream>
using namespace std;

int main(){
    const string name = "Vaasu";
    cout<<name.length()<<endl;
    // cout<<strlen(name)<<endl; size_t(16bits unisigned) strlen(const char* ch) excepts address to first charater of string
    cout<<strlen(&name[0])<<endl;

    // strlen() counts the number of characters in the string starting from the pointer str,
    // stopping when it encounters the null character '\0'.


    const char* name2 = "Vaasu";
    cout<<strlen(name2)<<endl;

    char name3[] = "Vaasu";
    cout<<strlen(name3)<<endl; // 5

    char name4[10] = {'V','a','a','s','r','r',0}; // null terminnation not counted
    cout<<strlen(name4)<<endl; // 6
    cout<<size(name4)<<endl; // 10
    return 0;
}

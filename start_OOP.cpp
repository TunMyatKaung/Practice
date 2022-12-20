#include <iostream>
using namespace std;

class MyClass{
public:

    string NRC[10]={"Name","NRC no.","City"};

    void setter(string code){
        password = code;
    }
    string getPassword(){
        return password;
    }
    MyClass(){
       cout<<"this is Constructor, same name with Class"<<endl;
    }
private:
    string password;
};

class YourClass : public MyClass{
public:
    int data=100;
};

int main(){
    MyClass obj;
    MyClass obj1;

    cout << "..Example.." << endl;
    for(int i=0; i<3; i++){
        cout << obj.NRC[i]<< endl;
    }

   /* cout << endl;
    for(int i=0; i<3; i++){
        cout << "Enter your NRC Info:" ;
        cin >> obj1.NRC[i];
    }
    for(int i=0; i<3; i++){
        cout << obj1.NRC[i] << endl;
    } */

    cout << endl;
    obj.setter("abc123!@#2022");
    cout << obj.getPassword() << endl;

    YourClass newObj;

    newObj.setter("tmk!@#1999");
    cout << newObj.getPassword() << endl;

    return 0;
}

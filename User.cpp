#include "User.h"

User::User(string name, string address, int u_password, int phone_num){
    this->name = name;
    this->address = address;
    this->u_password = u_password;
    this->phone_num = phone_num;
}
void User::inFile(){
    myfile.open("data.txt" , ios::app);
        myfile << name << "  "
         << u_password <<"  "
         << address <<"  "
         << phone_num <<"  "
         << endl;
    myfile.close();
}
string User::getName(){
    return name;
}
string User::getAddress(){
    return address;
}
int User::getID(){
    return u_password;
}
int User::getPhone(){
    return phone_num;
}
void User::DisplayUserInfo(){
    cout<< "Name: " << name << "/n"
    << "Address: " << address <<"/n"
    << "Password: " << u_password << "/n"
    << "Phone Number: " << phone_num;
}


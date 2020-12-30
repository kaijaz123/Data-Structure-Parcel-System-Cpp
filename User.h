#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
class User{
private:
    string name,address;
    int u_password,phone_num;
    ofstream myfile;


public:
    User(string name, string address, int u_password, int phone_num);
    string getName();
    string getAddress();
    int getID();
    int getPhone();
    void DisplayUserInfo();
    void inFile();
};

#endif // USER_H

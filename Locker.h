#ifndef locker_h
#define locker_h
#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Locker{
private:
    string locker_id , type;
    int password;
public:
    Locker(string locker_id, int password , string type);
    string getID();
    int locker_password();
    string locker_size();
    string locker_type();
    float locker_fee();
    void extra_charge();

};
#endif // locker_h

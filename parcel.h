#ifndef PARCEL_H
#define PARCEL_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "ListP.cpp"
#include <time.h>
#include "Locker.cpp"
using namespace std;
class Parcel{
private:
    string com_name , type ,user_name , new_item2 , item ,parcel_ID;
    int parce_ID;
    string destination[3] = {"MELAKA","KUALA LUMPUR","PULAU PENANG"};
    List stacker;
public:
    Parcel(string user_name, string item);
    void Insert();
    void Modification();
    void Remove();
    void Notification();
    void PreInsert();
    void SizeADT();
    void Track();
    void Check_Destination();
    void displayParcelInfo();
};
#endif // PARCEL_H

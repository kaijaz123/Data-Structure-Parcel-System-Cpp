#include "Locker.h"

Locker::Locker(string locker_id , int password , string type){
    this->locker_id = locker_id;
    this->password = password;
    this->type = type;
}

string Locker::locker_size(){
    if(type == "break"){
        return "BIG";
    }
    else{
        return "Normal";
    }
}

string Locker::locker_type(){
    if(type == "break"){
        return "fragile";
    }else{
        return "normal";
    }
}

float Locker::locker_fee(){
    return 10;
}

string Locker::getID(){
    return locker_id;
}

int Locker::locker_password(){
    return password;
}

void Locker::extra_charge(){
    time_t my_time = time(NULL);
    printf("\t\t\t\t     %s", ctime(&my_time));
    cout << "\tYOU WILL GET CHARGED IF DID NOT GET UR ITEM WITHIN TWO DAYS, PRICE WILL BE CHARGED TO: ";
    cout << locker_fee() + 10 ;
    endl(cout);
}

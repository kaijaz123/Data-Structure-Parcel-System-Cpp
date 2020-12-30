#include <iostream>
#include "User.cpp"
#include <fstream>
#include "parcel.cpp"
#include "Queue.cpp"
#include <cstdlib>
#include "parcel.h"
using namespace std;

string name;
void signup(){
    string address , Line;
    int ID , phone_num , option;
    char choice;
    bool done = false , found = false , match = false , found_password = false;
    while(true){
        fstream file;
        file.open("data.txt");
        cout <<"\t\t\t\t\tName: ";
        getline(cin,name);
        if(!cin){
            endl(cout);
            cout << "\t\t\t\t\tWrong Name format, please key in again " << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
        }
        if(file.is_open()){
            while(getline(file, Line)) {
                if (Line.find(name, 0) != string::npos) {
                        found = true;
                        break;
                    }
                }
        }
        file.close();
        if(found){
            cout << "\t\t\t\t\tSame username found, try again!" << endl;
        }else{
            break;
        }
        found = false;

    }
    endl(cout);
    while(true){
        cout<<"\t\t\t\t\tPassword: ";
        cin>>ID;
        string item = to_string(ID);
        for(int i=0; i< item.length(); i++){
            if(!cin && item[i] == '0'){
                match = true;
                break;
            }
        }
        if(match == true){
            endl(cout);
            cout << "\t\t\t\t\tWrong password format, please key in again " << endl;
            endl(cout);
        }
        else{
            cin.clear();
            cin.ignore(10000,'\n');
            match = false;
            break;
        }
        match = false;
        cin.clear();
        cin.ignore(56,'\n');
    }
    endl(cout);
    cout<<"\t\t\t\t\tAddress: ";
    getline(cin,address);
    endl(cout);
    while(true){
        cout<<"\t\t\t\t\tPhone Number: ";
        cin>>phone_num;
        string item = to_string(phone_num);
        for(int i=0; i< item.length(); i++){
            if(!cin  || isdigit(item[i]) == false){
                match = true;
                break;
            }
        }
        if(match == true){
            endl(cout);
            cout << "\t\t\t\t\tWrong phone number format, please key in again " << endl;
            endl(cout);
        }
        else{
            cin.clear();
            cin.ignore(10000,'\n');
            match = false;
            break;
        }
        match = false;
        cin.clear();
        cin.ignore(10000,'\n');
    }
    endl(cout);
    fstream myfile;
    myfile.open("D:\\codeblocks\\item\\Parcel\\data.txt");
    User user(name,address,ID,phone_num);
        myfile.open("data.txt" , ios::app);
        user.inFile();
        if(myfile.is_open()){
            myfile << endl ;
        }
        myfile.close();
}

int main(){
    string  address , Line;
    int ID , phone_num , option , lines = 0;
    char choice;
    bool done = false , found = false , match = false , found_password = false;
    fstream file;
    ofstream myfile;
    for (int i=0 ; i< 6 ; i++){
        endl(cout);
    }
    while(true){
        cout << "\t\t\t\t\tSign up : Press 1"<<endl;
        cout << "\t\t\t\t\tLog in : Press 2"<<endl;
        cout <<"\t\t\t\t\tOptions: ";
        cin >> option;
        if(option == 1){
            system("cls");
            cin.clear();
            cin.ignore(56,'\n');
            signup();
            break;
        }
        else if(option == 2){
            system("cls");
            cin.clear();
            cin.ignore(56,'\n');
            file.open("D:\\codeblocks\\item\\Parcel\\data.txt");
            while(true){
                cout <<"\t\t\t\t\tName: ";
                getline(cin,name);
                if(file.is_open()){
                    while(getline(file, Line)) {
                        lines++;
                        if (Line.find(name, 0) != string::npos) {
                            break;
                            }
                        }
                }
                break;
            }
            file.close();
            endl(cout);
            while(true){
                cout<<"\t\t\t\t\tPassword: ";
                cin>>ID;
                string item = to_string(ID);
                for(int i=0; i< item.length(); i++){
                    if(!cin ){
                        match = true;
                        break;
                    }
                }
                if(match == true){
                    endl(cout);
                    cout << "\t\t\t\t\tWrong password format, please key in again " << endl;
                    endl(cout);
                    cin.clear();
                    cin.ignore(56, '\n');
                    match = false;
                    continue;
                }

            file.open("D:\\codeblocks\\item\\Parcel\\data.txt");
            string passwordd = to_string(ID);
            string a , b , c , d;
            int count = 0;
            if(file.is_open()){
                while(!file.eof()) {
                        count ++;
                        file >> a >> b >> c >> d;
                        getline(file,Line);
                        if(lines == 1){
                           if(passwordd == b){
                                    found_password = true;
                                    break;
                                }
                        }
                        else if (count == lines ) {
                                if(passwordd == b){
                                    found_password = true;
                                    break;
                                }
                            }

                }
            }
            if(found_password == false){
                cout << "\t\t\t\t\tUsername of password is Wrong!"<<endl;
            }else{
                break;
            }
            file.close();
            endl(cout);
            found_password = false;
            cin.clear();
            cin.ignore(56,'\n');
            }
            break;

        }
        else{
            system("cls");
            cout<<"\t\t\t\t\tWrong option."<<endl <<endl;
            cin.clear();
            cin.ignore(56,'\n');
        }
    }
    system("cls");
    Queue queue1;
    string par;
    string destination[3] = {"MELAKA","KUALA LUMPUR","PULAU PENANG"};
    for(int i=0; i < 3 ; i++){
        queue1.enqueue(destination[i]);
    }
    srand(time(0));
    int randNum = rand()%(2-0 + 1) + 0;
    for(int i=0 ; i <=randNum; i++){
        if(i == randNum){
            par = queue1.getFront();
        }
        queue1.dequeue();
    }
    Parcel parcel(name,par);
    List stacker;
    string in_item , content;

    if(found_password == true){
        cout<<"\t\t\t\t\t   WELCOME BACK *" << name << "*"<<endl;
    }
    ofstream endfile;
    parcel.PreInsert();
    parcel.Check_Destination();
    do{
        cout << endl << endl << endl;
        cout << "          1. Insert Parcel" << endl;
        cout << "          2. Erase a Parcel Record" << endl;
        cout << "          3. Display ALL Parcel" << endl;
        cout << "          4. Modify Parcel" << endl;
        cout << "          5. Track Parcel" << endl;
        cout << "          6. Number of Parcel" << endl;
        cout << "          7. Notification" << endl;
        cout << "          Q. Quit" << endl;
        cout << endl;
        cout << "        => ";
        cin >> choice;
        choice = toupper(choice);
        switch(choice){
            case '1':{
                    parcel.Insert();
                    break;
            }
            case '2':
                    parcel.Remove();
                    break;

            case '3':
                    system("cls");
                    parcel.displayParcelInfo();
                    system("pause");
                    system("cls");
                    break;

            case '4':
                    parcel.Modification();
                    break;

            case '5':
                    parcel.Track();
                    break;

             case '6':
                    parcel.SizeADT();
                    break;

            case '7':
                    parcel.Notification();
                    break;

            case 'Q' :
                    done = true;
                    break;

            default:
                cout << "Invalid choice" << endl;

        }

    }while(!done);


    }

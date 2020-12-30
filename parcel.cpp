#include "parcel.h"
#include <fstream>
#include <vector>
#include <sstream>

Parcel::Parcel(string user_name, string item): com_name("Ship Company"){
    this->user_name = user_name;
    this->item = item;
}

void Parcel::Insert(){
    system("cls");
    int position , curLine = 0;
    string  new_item , Line ,new_item2;
    bool match = false;
    while(true){
        cout<<"Please type in your ID: ";
        cin>>parce_ID;
        string item = to_string(parce_ID);
        for(int i=0; i< item.length(); i++){
            if(!cin && item[i] == '0'){
                match = true;
                break;
            }
        }
        if(match == true){
            endl(cout);
            cout << "Wrong ID format, please key in again " << endl;
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
        while(true){
            cout<< "Please enter type of ITEM: ";
            cin >> type;
            for(int i=0; i< type.length(); i++){
                if(isdigit(type[i]) == true){
                    endl(cout);
                    match = true;
                    break;
                }
            }
            if(match == true){
                endl(cout);
                cout << "Type is wrong, please key in again" << endl;
                endl(cout);
            }
            else{break;}
            match = false;
            cin.clear();
            cin.ignore(10000,'\n');
    }
    position = stacker.getLength()+1;
    endl(cout);
    parcel_ID = to_string(parce_ID) + "_" + type;
    new_item2 = user_name[0] + parcel_ID;
    stacker.insert(position,new_item2);
    ofstream file , myfile2;
    ifstream myfile;
    int line = 0;
    myfile2.open("item.txt" , ios::app);
    if(myfile2.is_open()){
        myfile2 << user_name << "  " << new_item2 << "  "<< endl;
    }
    myfile2.close();
    endl(cout);
    cout <<"Done Adding"<<endl;
    system("pause");
    system("cls");
}

void Parcel::Modification(){
    system("cls");
    displayParcelInfo();
    vector<string> inputLines;
    ifstream file , myfile2;
    ofstream myfile , myfile3;
    string   newest , data ,Line;
    bool match = false;
    int position ;

    while(true){
        cout<<"Please type in new parcel ID: ";
        cin>>parce_ID;
        string item = to_string(parce_ID);
        for(int i=0; i< item.length(); i++){
            if(!cin && item[i] == '0'){
                match = true;
                break;
            }
        }
        bool check = stacker.finditem(item);
        if(match == true){
            endl(cout);
            cout << "Wrong ID format, please key in again " << endl;
            endl(cout);
        }
        else if(check){
            endl(cout);
            cout << "Duplicate ID is found, try again!" << endl;
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
    while(true){
        cout << "Please key in the position to be modified: ";
        cin >> position;
        if(!cin || position >= stacker.getLength()+1 || position < 1){
            endl(cout);
            cout << "Something is wrong, please key in again" << endl;
            endl(cout);
        }
        else{break;}
        cin.clear();
        cin.ignore(10000,'\n');
    }
    endl(cout);
    while(true){
        cout<< "Please enter type of ITEM: ";
        cin >> type;
        for(int i=0; i< type.length(); i++){
            if(isdigit(type[i]) == true){
                endl(cout);
                match = true;
                break;
            }
        }
        if(match == true){
            endl(cout);
            cout << "Type is wrong, please key in again" << endl;
            endl(cout);
        }
        else{break;}
        match = false;
        cin.clear();
        cin.ignore(10000,'\n');
    }
    newest = user_name[0] + to_string(parce_ID) + "_" + type;
    stacker.retrieve(position,data);
    stacker.modification(position,newest);
    myfile2.open("item.txt");
    vector<string>input;
    if(myfile2.is_open()){
        while(getline(myfile2, Line)) {
            if(Line.find(user_name) != string::npos){
                if(Line.find(data) != string::npos){
                    input.push_back(user_name + "  " + newest);
                }else{
                    input.push_back(Line);
                }
            }else{
                input.push_back(Line);
            }
    }
    myfile2.close();

    myfile3.open("item.txt");
    if(myfile3.is_open()){
        for(int i=0; i< input.size(); i++){
            myfile3 << input[i] <<endl;
        }
    }
    myfile3.close();
    cout <<"Done Modification"<<endl;
    myfile.close();
    system("pause");
    system("cls");

}
}

void Parcel::Remove(){
    system("cls");
    string Line , content;
    ifstream file , myfile2;
    ofstream myfile , myfile3;
    system("cls");
    int index , position;
    bool match = false;
    vector<string> Lineinput;
    displayParcelInfo();
    while(true){
        cout<<"Please key in the position of the item to be removed: ";
        cin>>index;
        if(!cin || index > stacker.getLength() || index < 1){
            endl(cout);
            cout << "Something is wrong, please key in again" << endl;
            endl(cout);
        }
        else{break;}
        cin.clear();
        cin.ignore(10000,'\n');
    }
    stacker.retrieve(index,content);
    stacker.remove(index);
    myfile2.open("item.txt");
    vector<string>input;
    string contente;
    for(int i=0; i < content.length(); i++){
        if(isdigit(content[i]))
            contente+=content[i];
    }
    if(myfile2.is_open()){
        while(getline(myfile2,Line)){
        if(Line.find(user_name)!=string::npos){
            if(Line.find(contente) != string::npos){
//                    input.push_back(" ");
                }
                else{
                    input.push_back(Line);
                }
        }else{
            input.push_back(Line);
            }
        }
    }
    myfile2.close();
    myfile3.open("item.txt");
    if(myfile3.is_open()){
        for(int i=0; i < input.size(); i++){
            myfile3 << input[i] << endl;
        }
    }
    myfile3.close();

    cout<<"Item has been removed successfully"<<endl;
    system("pause");
    system("cls");
}

void Parcel::Track(){
    system("cls");
    int ID;
    string Line;
    bool found = false , match = false;
    ifstream file;
    while(true){
        cout<<"Please type in only ID number: ";
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
            cout << "Wrong ID format, please key in again " << endl;
            endl(cout);
            cin.clear();
            cin.ignore(56,'\n');
            match = false;
            continue;
        }
        file.open("item.txt");
        if(file.is_open()){
                while(getline(file,Line)){
                    if(Line.find(user_name)!=string::npos){
                        if(Line.find(user_name[0] + item,0) != string::npos){
                            string get;
                                for(int i=0; i<Line.length(); i++){
                                    if(isdigit(Line[i])){
                                        get += Line[i];
                                        }
                                    }
                                if(item == get){
                                    found = true;
                                }
                        }
                    }
                }
            }
            break;
    }
    file.close();
    if(stacker.getLength() == 0){
        cout<<"Empty slot."<<endl;
    }
    else if(found == true){
            cout<<"Your item is currently on the way to " << destination[2] << "!" << endl;
    }else{
        cout <<"Item not found" <<endl;
    }
    system("pause");
    system("cls");
}

void Parcel::displayParcelInfo(){
    int count = 1;
    if(stacker.getLength() == 0){
        cout << "Its empty" <<endl;
    }
    else{
        cout << "\t\t\t";
        for(int i=0 ; i < 17; i++){
            cout << "*" ;
        }
        endl(cout);
        for(int i=1; i<= stacker.getLength(); ++i){

                string content;
                stacker.retrieve(i,content);
                cout<< "\t\t\t*"<< count<< "."<< content << "\t*" << endl;
                count++;
             }
        cout << "\t\t\t";
        for(int i=0 ; i < 17; i++){
            cout << "*" ;
        }
        endl(cout);
    }
}

void Parcel::PreInsert(){
    ifstream myfile;
    string content , Line;
    int position = 1;
    string retrive = "";
    myfile.open("item.txt");
    if(myfile.is_open()){
        if ( myfile.peek() == std::ifstream::traits_type::eof() )
        {
                //
        }else{
                 while(getline(myfile, Line)) {
                    if(Line.find(user_name,0)!= string::npos){
                            for(int i=user_name.length()+2; i < 20; i++){
                                    if(isspace(Line[i])){
                                        break;
                                    }else{
                                        retrive+=Line[i];
                                    }
                            }
                            stacker.insert(position,retrive);
                            position++;
                            retrive = "";

                        }
            }
        }
    }
        myfile.close();
}

void Parcel::Notification(){
    system("cls");
    ifstream file , myfile2;
    ofstream myfile , myfile3;
    string content , Line;
    int position;
    vector<string>Lineinput;
    bool match = false;
    if(item == "PULAU PENANG" && stacker.getLength() != 0){
        stacker.retrieve(1,content);
        stacker.remove(1);
        myfile2.open("item.txt");
        vector<string>input;
        string contente;
        for(int i=0; i < content.length(); i++){
            if(isdigit(content[i]))
                contente+=content[i];
        }
        if(myfile2.is_open()){
            while(getline(myfile2,Line)){
                if(Line.find(user_name)!=string::npos){
                    if(Line.find(contente) != string::npos){
//                            input.push_back(" ");
                        }
                        else{
                            input.push_back(Line);
                        }
                }else{
                    input.push_back(Line);
                }
            }
        }
        myfile2.close();
        myfile3.open("item.txt");
        if(myfile3.is_open()){
            for(int i=0; i < input.size(); i++){
                myfile3 << input[i] << endl;
            }
        }
        myfile3.close();
        cout << "\t\t\t";
        for(int i=0; i < 60 ; i ++){
            cout << "*" ;
        }
        endl(cout);
        cout <<"\t\t\t*\tYour item " << content << " arrived to destination!\t   *"<<endl;
        srand(time(0));
        int randNum = rand()%(300-10 + 1) + 10;
        int randID = rand()%(100-0 + 1) + 0;
        string newrandID = "A" + to_string(randID);
        Locker lock(newrandID , randNum , type);
        string size = lock.locker_size();
        float fee = lock.locker_fee();
        string tyype = lock.locker_type();
        string ID = lock.getID();
        int password = lock.locker_password();
        cout << "\t\t\t*\tYour locker size: " << size << "\t\t\t   *"<<endl;
        cout << "\t\t\t*\tFee: " << fee << "\t\t\t\t\t\t   *"<< endl;
        cout <<"\t\t\t*\tType: " << tyype << "\t\t\t\t\t   *"<<endl;
        cout << "\t\t\t*\tLocker ID is " << ID << "\t\t\t\t   *"<<endl;
        cout << "\t\t\t*\tLocker password is " << password <<"\t\t\t\t   *"<<endl;
        cout << "\t\t\t";
        for(int i=0; i < 60 ; i ++){
            cout << "*" ;
        }
        endl(cout);
        lock.extra_charge();
    }
    else{ cout <<"No notification yet!";
            endl(cout);}
    system("pause");
    system("cls");
}

void Parcel::Check_Destination(){
    if(item == "PULAU PENANG" && stacker.getLength() != 0){
        cout << "\t\tYOU HAVE ONE PARCEL ARRIVED NOTIFICATION, PLEASE GO AND CHECK AT NOTIFICATION OPTION!";
    }
}

void Parcel::SizeADT(){
    system("cls");
    cout <<"Number of Parcel currently in your stock: " << stacker.getLength()<<endl;
    system("pause");
    system("cls");
}




#include <iostream>
#include <bits/stdc++.h>
#include "Admin.h"
#include "Client.h"
#include "PlantHead.h"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

void admin();
void plantHead();
void client();
void signup();
void vStatus();
void login();

class Admin adm;
class PlantHead pHead;
class Client clnt;
class Structure s;

// struct PlantHead{
//     string name;
//     string pass;
// };


// struct Clientdetails{
//     string id;
//     string name;
//     string loc;
//     string pbusiness;
//     string cno;
//     string pass;
//     string approve;
    
// };

int ID;
list<Clientdetails> l;

int main(){
    l = s.file_to_list();
    srand(time(0));
	fstream read("id.txt");
	if(!read.fail()){
	    read >> ID;
	}
	else{
	    ID = 0;
	}
	read.close();
	int ch = 0;
	while(ch != 4){
		cout <<"\n *******************Order Processing System***************************** \n ";
		cout <<" \n ********************************************************************** \n";
		cout <<"\n Welcome to Home Page \n";
		cout <<"\n 1. Administration\n";
		cout <<"\n 2. Order Processing\n";
		cout <<"\n 3. Client Module \n";
		cout <<"\n 4. Exit \n";
		while(true){
    		cout <<"\n Enter your choice : ";
    		cin >> ch;
    		if(cin.fail()){
    		    cin.clear();
    		    cin.ignore(512,'\n');
    		    cout <<"\nPlease Enter choice from given choices\n";
    		    cout <<"\nChoice should be Integer\n";
    		}
    		else{
    		    break;
    		}
		}
		switch(ch){
		    case 1:
		        admin();
		        break;
		    case 2:
		        plantHead();
		        break;
		    case 3:
		        client();
		        break;
		    case 4:
		        break;
		    default:
		        cout <<" \n Please Enter a Valid Choice \n";
		        continue;
		}
	}
}

void admin(){
    string name = "chetan singh";
    string pass = "12345";
    
    string name1, pass1;
    cout <<"\n Enter your Name : ";
    cin.get();
    getline(cin, name1);
    transform(name1.begin(), name1.end(), name1.begin(), :: tolower);
    while(true){
	    cout <<"\n Enter your Password : ";
	    cin >> pass1;
	    if(pass1.length() > 8){
	    	cout <<"Password length should be less then 9 \n";
	    	continue;
		}
		break;
	}    
    if(name == name1 && pass == pass1){
        cout << "\nYour Login as Administration is Successful \n";
        adm.adminPage(l);
    }
    else{
        cout <<"\n Invalid Username or Password \n" ;
    }
}

void plantHead(){
    fstream read("head.txt");
    if(!read){
        cout <<" \nFile not found \n";
    }
    else{
        string id, name, pass, plantID, id1, pass1;
        // cout <<"\nEnter Your Plant Head ID as username : ";
        // cin >> id1;
        while(true){
            cout <<"Enter Your Plant Head ID as username : ";
            cin >> id1;
            if(!is_valid_num(id1)){
                cout <<"\nPlant Head ID Should be Integer\n";
            }
            else{
                break;
            }
        }
        while(true){
		    cout <<"Enter your Password : ";
		    cin >> pass1;
		    if(pass1.length() > 8){
		    	cout <<"Password length should be less then 9 \n";
		    	continue;
			}
			break;
		}    
        bool message = false;
        while(read >> id >> name >> pass >> plantID){
            if(id == id1 && pass == pass1){
                message = true;
                cout << "\nYour Login as PlantHead is Successful \n";
                pHead.plantheadPage(plantID);
                break;
            }
            //cout<<id<<"\n";
            //cout<<name <<"\n";
            //cout<<pass <<"\n";
            //cout<<plantID<<"\n";
            //cout<<endl;
        }
        if(message == false){
            cout<<"\nPlease Enter Valid ID and Password \n";
        }
    }
    read.close();
}

void client(){
    int ch = 0;
    while(ch != 4){
        cout <<" \n ************Welcome to Client Page*************** \n";
	    cout <<" \n ************************************************* \n";
        cout <<" \n 1. Signup \n";
        cout <<" \n 2. View Registration Status\n";
        cout <<" \n 3. Login \n";
        cout <<" \n 4. Exit \n ";
        while(true){
    		cout <<"\n Enter your choice : ";
    		cin >> ch;
    		if(cin.fail()){
    		    cin.clear();
    		    cin.ignore(512,'\n');
    		    cout <<"\nPlease Enter choice from given choices\n";
    		    cout <<"\nChoice should be Integer\n";
    		}
    		else{
    		    break;
    		}
		}
        switch(ch){
            case 1:
                signup();
                break;
            case 2:
                vStatus();
                break;
            case 3:
                login();
                break;
            case 4:
                break;
            default:
                cout <<"\nPlease Enter Valid Choice \n";
                continue;
        }
    }
}

    
void signup(){    
    Clientdetails c;
    string approve = "0";
    // cout <<"Enter your Name : ";
    // cin.get();
    // getline(cin, c.name);
    while(true){
        cout <<"Enter your Name : ";
        cin.get();
        getline(cin, c.name);
        if(!is_valid_name(c.name)){
            cout <<"\nName Should be string\n";
        }
        else{
            break;
        }
    }
    // cout <<"Enter your Location : ";
    // getline(cin, c.loc);
    while(true){
        cout <<"Enter your Location : ";
        getline(cin, c.loc);
        if(!is_valid_name(c.loc)){
            cout <<"\nLocation Should be string\n";
        }
        else{
            break;
        }
    }
    cout <<c.loc << " \n";
    // cout <<"Enter your Primary Business : ";
    // getline(cin, c.pbusiness);
    while(true){
        cout <<"Enter your Primary Business : ";
        getline(cin, c.pbusiness);
        if(!is_valid_name(c.pbusiness)){
            cout <<"\nPrimary Business Should be string\n";
        }
        else{
            break;
        }
    }
    while(true){
	    cout <<"Enter your Contact Number : ";
	    cin >> c.cno;
	    if(c.cno.length() < 10 || c.cno.length() > 10 ){
	    	cout <<"\nContact Number length should be 10 \n";
	    	continue;
		}
		break;
	}    
    while(true){
	    cout <<"Enter your Password : ";
	    cin >> c.pass;
	    if(c.pass.length() > 8){
	    	cout <<"\nPassword length should be less then 9 \n";
	    	continue;
		}
		break;
	}    
    ID++;
    stringstream ss;
    ss << to_string(ID);
    ss >> c.id;
    c.approve = approve;
    //l.push_back(c);
    ofstream write;
    write.open("client.txt", ios :: app);
    write << c.id << "\n";
    write << c.name << "\n";
    write << c.loc << "\n";
    write << c.pbusiness << "\n";
    write << c.cno <<"\n";
    write << c.pass <<"\n";
    write << c.approve <<"\n";
    cout <<" \nYour ID is : " << ID << "\n";
    write.close();
    write.open("id.txt");
    write << ID <<"\n";
    write.close();
    l = s.file_to_list();
}

void vStatus(){
    string id, cid;
    string pass1;
    string approve;
    // cout<<"\nEnter Your Client ID as username : ";
    // cin >> id;
    while(true){
            cout <<"\nEnter Your Client ID as username : ";
            cin >> id;
            if(!is_valid_num(id)){
                cout <<"\nClient ID Should be string\n";
            }
            else{
                break;
            }
        }
    while(true){
	    cout <<"\nEnter your Password : ";
	    cin >> pass1;
	    if(pass1.length() > 8){
	    	cout <<"\nPassword length should be less then 9 \n";
	    	continue;
		}
		break;
	}    
	bool message = false;
    Clientdetails c;
    ifstream read;
    read.open("client.txt");
    read.ignore();
    getline(read, cid);
	//cout <<cid << "\n";
	getline(read, c.name);
	//cout <<c.name <<"\n";
	getline(read, c.loc);
	//cout <<c.loc <<"\n";
	getline(read, c.pbusiness);
	//cout <<c.pbusiness <<"\n";
	getline(read, c.cno);
	//cout << c.cno << "\n";
	getline(read, c.pass);
	//cout << c.pass <<"\n";
	getline(read, approve);
	//cout << approve << "\n";
    //cout << endl;
    while(!read.eof()){
    	if(cid == id && c.pass == pass1){
    	    message = true;
    		if(approve == "0"){
    			cout <<"\nSorry Your request didn't approve by the Admin side \n";
			}
			else if(approve == "1"){
			    cout <<"\nYour request has been Approved\n";
			}
			else{
			    cout <<"\nYour request has been Denied\n";
			}
		}
	    getline(read, cid);
	    //cout <<cid << "\n";
	    getline(read, c.name);
	    //cout <<c.name <<"\n";
	    getline(read, c.loc);
	    //cout <<c.loc <<"\n";
	    getline(read, c.pbusiness);
	    //cout <<c.pbusiness <<"\n";
	    getline(read, c.cno);
	    //cout << c.cno << "\n";
	    getline(read, c.pass);
	    //cout << c.pass <<"\n";
	    getline(read, approve);
	    //cout << approve << "\n";
	    //cout << endl;
	}
	if(message == false){
	    cout <<"\nPlease Enter Valid ID and Password \n";
	}
	read.close();
}

void login(){
    string id, cid;
    string pass1;
    string approve;
    // cout<<"E\nnter Your Client ID as username : ";
    // cin >> id;
    while(true){
            cout <<"\nEnter Your Client ID as username : ";
            cin >> id;
            if(!is_valid_num(id)){
                cout <<"\nClient ID Should be string\n";
            }
            else{
                break;
            }
        }
    while(true){
	    cout <<"\nEnter your Password : ";
	    cin >> pass1;
	    if(pass1.length() > 8){
	    	cout <<"\nPassword length should be less then 9 \n";
	    	continue;
		}
		break;
	}    
	bool message = false;
    Clientdetails c;
    ifstream read;
    read.open("client.txt");
    read.ignore();
    getline(read, cid);
	//cout <<cid << "\n";
	getline(read, c.name);
	//cout <<c.name <<"\n";
	getline(read, c.loc);
	//cout <<c.loc <<"\n";
	getline(read, c.pbusiness);
	//cout <<c.pbusiness <<"\n";
	getline(read, c.cno);
	//cout << c.cno << "\n";
	getline(read, c.pass);
	//cout << c.pass <<"\n";
	getline(read, approve);
	//cout << approve << "\n";
    //cout << endl;
    while(!read.eof()){
    	if(cid == id && c.pass == pass1){
    	    message = true;
    		if(approve == "0"){
    			cout <<"\nSorry Your request didn't approve by the Admin side \n";
			}
			else if(approve == "1"){
			    clnt.clientPage(cid);
			}
			else{
			    cout <<"\nYour request has been Denied\n";
			}
		}
	    getline(read, cid);
	    //cout <<cid << "\n";
	    getline(read, c.name);
	    //cout <<c.name <<"\n";
	    getline(read, c.loc);
	    //cout <<c.loc <<"\n";
	    getline(read, c.pbusiness);
	    //cout <<c.pbusiness <<"\n";
	    getline(read, c.cno);
	    //cout << c.cno << "\n";
	    getline(read, c.pass);
	    //cout << c.pass <<"\n";
	    getline(read, approve);
	    //cout << approve << "\n";
	    //cout << endl;
	}
	if(message == false){
	    cout <<"\nPlease Enter Valid ID and Password \n";
	}
	read.close();
}
    

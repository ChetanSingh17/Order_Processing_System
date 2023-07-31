#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
#include "Approve.h"
#include "PHDetails.h"
#include "Plant.h"
#include "Order.h"
#include <list>
#include "Validate.h"

using namespace std;

list<phdetal> ph;
list<PlantD> plantlist;

void managePlant();
void managePH();
void assign_updatePH();
void viewPO();


class Approve app;
class PHDetails phd;
class Plant pl;
class Order o;


bool searchPid(string pID){
    list<PlantD> l = pl.file_to_list();
    list<PlantD> ::iterator it;
    for(it = l.begin(); it!=l.end(); it++){
        //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
        if(it->pID == pID){
            return true;
        }
    }
    return false;
}

void AddP(list<PlantD> l){
    PlantD pd;
    while(true){
        // cout <<"\nEnter Plant ID : ";
        // cin >>pd.pID;
        while(true){
            cout <<"\nEnter Your Plant ID : ";
            cin >> pd.pID;
            if(!is_valid_num(pd.pID)){
                cout <<"\nPlant ID Should be Integer\n";
            }
            else{
                break;
            }
        }
        bool flag = false;
        flag = searchPid(pd.pID);
        if(flag == true){
            cout <<"\nPlant ID already Exist \n";
            cout <<"\nPlease Enter Unique Plant ID \n";
            
        }
        else{
            break;
        }
    }
    // cout << "\nEnter Plant Name : ";
    // cin >> pd.name;
    while(true){
        cout <<"Enter your Plant Name : ";
        cin >> pd.name;
        if(!is_valid_name(pd.name)){
            cout <<"\nPlant Name Should be string\n";
        }
        else{
            break;
        }
    }
    // cout <<"\nEnter Location : ";
    // cin >> pd.ploc;
    while(true){
        cout <<"Enter Plant Location : ";
        cin >> pd.ploc;
        if(!is_valid_name(pd.ploc)){
            cout <<"\nPlant Location Should be string\n";
        }
        else{
            break;
        }
    }
    // cout << "\nEnter Laborer Count : ";
    // cin >> pd.lc;
    while(true){
            cout <<"\nEnter Your Laborer Count : ";
            cin >> pd.lc;
            if(!is_valid_num(pd.lc)){
                cout <<"\nLaborer Count Should be Integer\n";
            }
            else{
                break;
            }
        }
    // cout <<"\nEnter Capacity : ";
    // cin >> pd.capacity;
    while(true){
            cout <<"\nEnter Your Capacity: ";
            cin >> pd.capacity;
            if(!is_valid_num(pd.capacity)){
                cout <<"\nCapacity Should be Integer\n";
            }
            else{
                break;
            }
        }
    l.push_back(pd);
    cout <<"\nPlant added successfuly \n";
    pl.list_to_file(l);
}

void UpdateP(list<PlantD> l){
    list<PlantD> :: iterator it;
    string pID;
    // cout <<"\nEnter Plant ID to Update : ";
    // cin >> pID;
    while(true){
            cout <<"\nEnter Your Plant ID : ";
            cin >> pID;
            if(!is_valid_num(pID)){
                cout <<"\nPlant ID Should be Integer\n";
            }
            else{
                break;
            }
        }
    bool message = false;
    for(it = l.begin(); it != l.end(); it++){
        if(it->pID == pID){
            message = true;
            // cout <<"\nEnter new Location : ";
            // cin >>it->ploc;
            while(true){
                cout <<"Enter new Location : ";
                cin >> it->ploc;
                if(!is_valid_name(it->ploc)){
                    cout <<"\nNew Plant Location Should be string\n";
                }
                else{
                    break;
                }
            }
            // cout <<"\nEnter new Laborer Count : ";
            // cin >> it->lc;
            while(true){
                cout <<"\nEnter Your Laborer Count : ";
                cin >> it->lc;
                if(!is_valid_num(it->lc)){
                    cout <<"\nLaborer Count Should be Integer\n";
                }
                else{
                    break;
                }
            }
            // cout <<"\nEnter new Capacity : ";
            // cin >> it->capacity;
            while(true){
                cout <<"\nEnter Your Capacity: ";
                cin >> it->capacity;
                if(!is_valid_num(it->capacity)){
                    cout <<"\nCapacity Should be Integer\n";
                }
                else{
                    break;
                }
            }
        }
    }
    if(message == true){
        cout <<"\nPlant details updated successfuly\n";
        pl.list_to_file(l);
    }
    else{
        cout <<"\n Plant ID doesn't exist\n";
    }
}

void DeleteP(list<PlantD> l){
    list<PlantD> :: iterator it;
    string pID;
    // cout <<"\nEnter Plant ID to Delete : ";
    // cin >> pID;
    while(true){
            cout <<"\nEnter Your Plant ID: ";
            cin >> pID;
            if(!is_valid_num(pID)){
                cout <<"\nPlant ID Should be Integer\n";
            }
            else{
                break;
            }
        }
    bool message = false;
    for(it = l.begin(); it != l.end(); it++){
        if(it->pID == pID){
            message = true;
            l.erase(it);
            break;
        }
    }
    if(message == true){
        cout <<"\nPlant deleted successfuly\n";
        pl.list_to_file(l);
    }
    else{
        cout <<"\n Plant ID doesn't exist\n";
    }
}

void DisplayPlant(list<PlantD> l){
    list<PlantD> :: iterator it;
    cout << "Plant ID\t\tPlant Name\t\tLocation\t\tLaborer Count\t\tCapacity\n";
    for(it = l.begin(); it != l.end(); it++){
        cout << it->pID <<"\t\t\t"<< it->name <<"\t\t\t"<<it->ploc 
        <<"\t\t\t"<< it->lc <<"\t\t\t"<< it->capacity <<"\n";
    }
}

void SearchP(list<PlantD> l){
    list<PlantD> :: iterator it;
    string pID;
    cout <<"\nEnter Plant ID to Search : ";
    cin >> pID;
    bool message = false;
    for(it = l.begin(); it != l.end(); it++){
        if(it->pID == pID){
            message = true;
            cout <<"\nPlant ID : " << it->pID <<"\nPlant Location : " << it->ploc
            <<"\nPlant Laborer Count : " <<  it->lc <<"\nPlant Capacity : " << it->capacity <<"\n";
        }
    }
    if(message == false){
        cout <<"\n Plant ID doesn't exist\n";
    }
}


bool searchPH(list<phdetal>l, string phID){
    list<phdetal> ::iterator it;
    for(it = l.begin(); it!=l.end(); it++){
        //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
        if(it->phID == phID){
            return true;
        }
    }
    return false;
}

bool searchPd(list<phdetal>l, string pID){
    list<phdetal> ::iterator it;
    for(it = l.begin(); it!=l.end(); it++){
        //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
        if(it->pID == pID){
            return true;
        }
    }
    return false;
}


void AddPh(list<phdetal> l){
    phdetal p;
    while(true){
        // cout <<"\nEnter Plant Head ID : ";
        // cin >>p.phID;
        while(true){
            cout <<"\nEnter Your Plant Head ID: ";
            cin >> p.phID;
            if(!is_valid_num(p.phID)){
                cout <<"\nPlant Head ID Should be Integer\n";
            }
            else{
                break;
            }
        }
        bool flag = false;
        flag = searchPH(l, p.phID);
        if(flag == true){
            cout <<"\nPlant Head ID already Exist \n";
            cout <<"\nPlease Enter Unique Plant Head ID \n";
        }
        else{
            break;
        }
    }
    // cout <<"\nEnter Plant Head Name : ";
    // cin >> p.name;
    while(true){
        cout <<"Enter Plant Head Name : ";
        cin >> p.name;
        if(!is_valid_name(p.name)){
            cout <<"\nPlant Head Name Should be string\n";
        }
        else{
            break;
        }
    }
    cout << "\nPlant Head Password is : " << p.pass <<"\n";
    // while(true){
    //     cout <<"\nEnter Plant ID : ";
    //     cin >>p.pID;
    //     bool flag = false;
    //     flag = searchPd(l, p.pID);
    //     if(flag == true){
    //         cout <<"\nPlant ID already Exist \n";
    //         cout <<"\nPlease Enter Unique Plant ID \n";
            
    //     }
    //     else{
    //         break;
    //     }
    // }
    p.pID = "nopID";
    l.push_back(p);
    phd.list_to_file(l);
}

void UpdatePh(list<phdetal> l){
    phdetal p;
    string phid, name, pass, pid;
    // cout <<"\nEnter plant head id you wanna update : ";
    // cin >> phid;
    while(true){
            cout <<"\nEnter Your Plant Head ID: ";
            cin >> phid;
            if(!is_valid_num(phid)){
                cout <<"\nPlant Head ID Should be Integer\n";
            }
            else{
                break;
            }
        }
    list<phdetal> :: iterator it;
    bool message = false;
    for(it = l.begin(); it!=l.end(); it++){
        //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
        if(it->phID == phid){
            message = true;
            while(true){
                // cout <<"\nEnter New Plant Head ID : ";
                // cin >> p.phID;
                while(true){
                    cout <<"\nEnter Your Plant Head ID: ";
                    cin >> p.phID;
                    if(!is_valid_num(p.phID)){
                        cout <<"\nPlant Head ID Should be Integer\n";
                    }
                    else{
                        break;
                    }
                }
                bool flag = false;
                flag = searchPH(l, p.phID);
                if(flag == true){
                    cout <<"\nPlant Head ID already Exist \n";
                    cout <<"\nPlease Enter Unique Plant Head ID \n";
                }
                else{
                    break;
                }
            }
            // cout <<"\nEnter plant head name : ";
            // cin >> name;
            while(true){
                cout <<"Enter Plant Head Name : ";
                cin >> name;
                if(!is_valid_name(name)){
                    cout <<"\nPlant Head Name Should be string\n";
                }
                else{
                    break;
                }
            }
            // while(true){
            //     cout <<"\nEnter Plant ID : ";
            //     cin >>pid;
            //     bool flag = false;
            //     flag = searchPd(l, pid);
            //     if(flag == true){
            //         cout <<"\nPlant ID already Exist \n";
            //         cout <<"\nPlease Enter Unique Plant ID \n";
            //     }
            //     else{
            //         break;
            //     }
            // }
            it->phID = p.phID;
            it->name = name;
            it->pass = p.pass;
            //it->pID;
        }
    }
    if(message == true){
        phd.list_to_file(l);
        cout <<"\nPlant Head details have been updated\n";
    }
    else{
        cout <<"\nPlease Enter valid Plant Head ID\n";
    }
    
}
void DeletePh(list<phdetal> l){
    phdetal p;
    string phid;
    // cout <<"\nEnter plant head id you wanna delete : ";
    // cin >> phid;
    while(true){
            cout <<"\nEnter Your Plant Head ID: ";
            cin >> phid;
            if(!is_valid_num(phid)){
                cout <<"\nPlant Head ID Should be Integer\n";
            }
            else{
                break;
            }
        }
    list<phdetal> :: iterator it;
    bool message = false;
    for(it = l.begin(); it!=l.end(); it++){
        if(it->phID == phid){
            message = true;
            l.erase(it);
            break;
        }
    }
    if(message == true){
        phd.list_to_file(l);
        cout <<"\nPlant Head successfuly deleted\n";
    }
    else{
        cout <<"\nPlant Head ID doesn't Exist\n";
    }
}

void Display(list<phdetal>l){
    list<phdetal> ::iterator it;
    for(it = l.begin(); it!=l.end(); it++){
        cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
        
    }
}


void assignPHtoP(list<phdetal>l){
    phdetal p;
    string phid, pid;
    // cout <<"\nEnter plant head id you wanna assign : ";
    // cin >> phid;
    while(true){
            cout <<"\nEnter Your Plant Head ID: ";
            cin >> phid;
            if(!is_valid_num(phid)){
                cout <<"\nPlant Head ID Should be Integer\n";
            }
            else{
                break;
            }
        }
    list<phdetal> :: iterator it;
    bool message = false;
    for(it = l.begin(); it!=l.end(); it++){
        //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
        if(it->phID == phid){
            message = true;
            if(it->pID == "nopID"){
                while(true){
                    // cout <<"\nEnter Plant ID : ";
                    // cin >>pid;
                    while(true){
                        cout <<"\nEnter Your Plant ID: ";
                        cin >> pid;
                        if(!is_valid_num(pid)){
                            cout <<"\nPlant ID Should be Integer\n";
                        }
                        else{
                            break;
                        }
                    }
                    bool flag = false;
                    flag = searchPid(pid);
                    if(flag == true){
                        it->pID = pid;
                        break;
                    }
                    else{
                        cout <<"\nPlant ID doesn't Exist\n";
                    }
                }
            }
            else{
                cout <<"\nPlant Head already have a Plant ID\n";
            }
        }
    }
    if(message == true){
        phd.list_to_file(l);
    }
    else{
        cout <<"\nPlant Head ID doesn't Exist\n";
    }
}

void updatePHtoP(list<phdetal>l){
    phdetal p;
    string phid, pid;
    // cout <<"\nEnter plant head id you wanna update plant id : ";
    // cin >> phid;
    while(true){
            cout <<"\nEnter Your Plant Head ID: ";
            cin >> phid;
            if(!is_valid_num(phid)){
                cout <<"\nPlant Head ID Should be Integer\n";
            }
            else{
                break;
            }
        }
    list<phdetal> :: iterator it;
    bool message = false;
    for(it = l.begin(); it!=l.end(); it++){
        //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
        if(it->phID == phid){
            message = true;
            while(true){
                // cout <<"\nEnter Plant ID : ";
                // cin >>pid;
                while(true){
                    cout <<"\nEnter Your Plant ID: ";
                    cin >> pid;
                    if(!is_valid_num(pid)){
                        cout <<"\nPlant ID Should be Integer\n";
                    }
                    else{
                        break;
                    }
                }
                bool flag = false;
                flag = searchPid(pid);
                if(flag == true){
                    it->pID = pid;
                    break;
                }
                else{
                    cout <<"\nPlant ID doesn't Exist\n";
                }
            }
        }
    }
    if(message == true){
        phd.list_to_file(l);
    }
    else{
        cout <<"\nPlease Enter valid Plant Head ID\n";
    }
}

class Admin{
	public :
	void adminPage(list<Clientdetails> l){
	    int ch = 0;
	    cout <<" \n ************Welcome to Administration Module*************** \n";
	    cout <<" \n *********************************************************** \n";
	    while(ch != 6){
	        cout <<" \n 1. Manage Plant \n";
	        cout <<" \n 2. Manage Plant Head \n";
	        cout <<" \n 3. Assign/Update Plant Head to a Plant \n";
	        cout <<" \n 4. View Purchase Order \n";
	        cout <<" \n 5. View Client Approval \n";
	        cout <<" \n 6. Logout \n";
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
	                managePlant();
	                break;
	            case 2:
	                managePH();
	                break;
	            case 3:
	                assign_updatePH();
	                break;
	            case 4:
	                viewPO();
	                break;
	            case 5:
	            	app.isApprove(l);
	                break;
	            case 6:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
	}
};

void managePlant(){
	int ch = 0;
	    cout <<" \n ************Manage Plant*************** \n";
	    cout <<" \n *************************************** \n";
	    while(ch != 6){
	        plantlist = pl.file_to_list();
	        cout <<" \n 1. Add Plant \n";
	        cout <<" \n 2. Update Plant \n";
	        cout <<" \n 3. Delete Plant \n";
	        cout <<" \n 4. Search Plant \n";
	        cout <<" \n 5. Display Plants \n";
	        cout <<" \n 6. Exit \n";
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
	                AddP(plantlist);
	                break;
	            case 2:
	                UpdateP(plantlist);
	                break;
	            case 3:
	                DeleteP(plantlist);
	                break;
	            case 4:
	                SearchP(plantlist);
	                break;
	            case 5:
	                DisplayPlant(plantlist);
	                break;
	            case 6:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
}

void managePH(){
    int ch = 0;
	    cout <<" \n ************Manage Plant Head*************** \n";
	    cout <<" \n ******************************************** \n";
	    while(ch != 5){
	        ph = phd.file_to_list();
	        cout <<" \n 1. Add Plant Head \n";
	        cout <<" \n 2. Update Plant Head \n";
	        cout <<" \n 3. Delete Plant Head \n";
	        cout <<" \n 4. Display Plant Head \n";
	        cout <<" \n 5. Exit \n";
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
	                AddPh(ph);
	                break;
	            case 2:
	                UpdatePh(ph);
	                break;
	            case 3:
	                DeletePh(ph);
	                break;
	            case 4:
	                Display(ph);
	                break;
	            case 5:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
	
}

void assign_updatePH(){
        int ch = 0;
	    cout <<" \n ************A ssign and Update Plant Head to a Plant*************** \n";
	    cout <<" \n ******************************************************************* \n";
	    while(ch != 3){
	        ph = phd.file_to_list();
	        cout <<" \n 1. Assign Plant Head to a Plant \n";
	        cout <<" \n 2. Update Plant Head of a Plant\n";
	        cout <<" \n 3. Exit \n";
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
	                assignPHtoP(ph);
	                break;
	            case 2:
	                updatePHtoP(ph);
	                break;
	            case 3:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
}


void viewPO(){
	list<OrderD> od = o.file_to_list();
    list<OrderD> :: iterator it;
    for(it = od.begin(); it!=od.end(); it++){
            cout <<"\nOrder ID : " <<it->oID <<"\nPlant Name : " <<it->pname <<"\nItem Name : " <<it->iName <<"\nRecieved : " <<it->recieved 
            <<"\nProcessed ID : " <<it->processed <<"\nPending : " <<it->pending <<"\nRevenue : " <<it->revenue <<"\nStatus : " <<it->status <<"\n";
    }
}

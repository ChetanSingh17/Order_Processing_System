#include <iostream>
#include <list>
#include <fstream>
#include "Structure.h"
#include <bits/stdc++.h>
using namespace std;

class Structure st;

void approval(list<Clientdetails>l){
	list<Clientdetails> ::iterator it;
	bool message = false;
	for(it = l.begin(); it!=l.end(); it++){
// 		cout << it->id << " " << it->name << " " << it->loc << " "<< it->pbusiness << " "<< it->cno 
// 		<<" " << it->pass << " "<< it->approve <<"\n";
		if(it->approve == "0"){
		    cout <<"/This is new Client Data : \n";
		    cout << "\nID : " <<it->id << "\nName : " << it->name << "\nLocation : " << it->loc << "\nPrimary Business : "<< it->pbusiness << "\nContact No. : "<< it->cno 
		    <<"\nPassword : " << it->pass << "\nApproval Status : "<< it->approve <<"\n";
		    message = true;
		    int ch = 0;
		    cout <<"\n 1. Approve \n";
		    cout <<"\n 2. Decline \n";
		    cout <<"\n 3. Exit \n";
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
		                it->approve = "1";
		                break;
		            case 2:
		                it->approve = "2";
		                break;
		            case 3:
		                break;
		            default :
		                cout <<"\nPlease Enter valid choice \n";
		        }
		}
	}
	if(message == false){
		    cout <<"\nNo Request for Approval \n";
	}
	else{
	    st.list_to_file(l);
	}
}


class Approve{
    public:
    void isApprove(list<Clientdetails> l){
    	int ch = 0;
    	while(ch != 2){
    		cout <<"\n 1. Approve & Decline \n";
    		cout <<"\n 2. Exit \n";
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
    			    approval(l);
    				break;
    			case 2:
    				break;
    			default:
    				cout <<"Enter the valid choice \n";
    				continue;
    		}
    		
    	}
    	
    }
};

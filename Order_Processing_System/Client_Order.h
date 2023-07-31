#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct ClientO{
    string oID;
    string cID;
    string pID;
    string pName;
    string iID;
    string iName;
    string quantity;
    string cost;
    
};


class Client_Order{
    public:
    list<ClientO> file_to_list(){
        list<ClientO> l;
        ClientO c;
        fstream read("clientorder.txt");
        read >> c.oID;
        read >> c.cID;
        read >> c.pID;
        read >> c.pName;
        read >> c.iID;
        read >> c.iName;
        read >> c.quantity;
        read >> c.cost;
        read.ignore();
    	while(!read.eof()){
    	    l.push_back(c);
    	    read >> c.oID;
	        read >> c.cID;
	        read >> c.pID;
	        read >> c.pName;
	        read >> c.iID;
	        read >> c.iName;
	        read >> c.quantity;
	        read >> c.cost;
	        read.ignore();
    	}
        return l;
    }
    void list_to_file(list<ClientO>l){
        fstream write;
        write.open("clientorder.txt", ios :: out);
        list<ClientO>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		    write << it->oID <<"\n";
		    write << it->cID <<"\n";
		    write << it->pID <<"\n";
		    write << it->pName <<"\n";
		    write << it->iID <<"\n";
		    write << it->iName <<"\n";
		    write << it->quantity <<"\n";
		    write << it->cost <<"\n";
		    write << "\n";
	    }
    }
};
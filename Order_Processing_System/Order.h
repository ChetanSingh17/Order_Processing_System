#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct OrderD{
    string pID;
    string oID;
    string pname;
    string iName;
    string recieved;
    string processed;
    string pending;
    string revenue;
    string status;
    
};


class Order{
    public:
    list<OrderD> file_to_list(){
        list<OrderD> l;
        OrderD o;
        fstream read("order.txt");
        read >> o.pID;
        read >> o.oID;
        read >> o.pname;
        read >> o.iName;
        read >> o.recieved;
        read >> o.processed;
        read >> o.pending;
        read >> o.revenue;
        read >> o.status;
        read.ignore();
    	while(!read.eof()){
    	    l.push_back(o);
    	    read >> o.pID;
            read >> o.oID;
            read >> o.pname;
            read >> o.iName;
            read >> o.recieved;
            read >> o.processed;
            read >> o.pending;
            read >> o.revenue;
            read >> o.status;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<OrderD>l){
        fstream write;
        write.open("order.txt", ios :: out);
        list<OrderD>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		    //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
		    write << it->pID << "\n";
            write << it->oID << "\n";
            write << it->pname << "\n";
            write << it->iName << "\n";
            write << it->recieved << "\n";
            write << it->processed<< "\n";
            write << it->pending << "\n";
            write << it->revenue << "\n";
            write << it->status << "\n";
            write << "\n";
	    }
    }
};
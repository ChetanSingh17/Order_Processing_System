#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct phdetal{
    string phID;
    string name;
    string pass;
    string pID;
    
    phdetal(){
        stringstream s;
        s << to_string(rand()%(10000) +100);
        s >> pass;
    }
};


class PHDetails{
    public:
    list<phdetal> file_to_list(){
        list<phdetal> l;
        phdetal p;
        fstream read("head.txt");
        read >> p.phID;
        read >> p.name;
        read >> p.pass;
        read >> p.pID;
        read.ignore();
        //getline(read, ph.phID);
    	//cout <<ph.phID << "\n";
    	//getline(read, ph.name);
    	//cout <<ph.name <<"\n";
    	//getline(read, ph.pass);
    	//cout << ph.pass <<"\n";
    	//getline(read, ph.pID);
    	//cout << ph.pID <<"\n";
    	while(!read.eof()){
    	    l.push_back(p);
    	    read >> p.phID;
            read >> p.name;
            read >> p.pass;
            read >> p.pID;
            read.ignore();
    	    //getline(read, ph.phID);
        	//cout <<ph.phID << "\n";
        	//getline(read, ph.name);
        	//cout <<ph.name <<"\n";
        	//getline(read, ph.pass);
        	//cout << ph.pass <<"\n";
        	//getline(read, ph.pID);
        	//cout << ph.pID <<"\n";
    	}
        return l;
    }
    void list_to_file(list<phdetal>l){
        fstream write;
        write.open("head.txt", ios :: out);
        list<phdetal>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		    //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
		    write << it->phID <<"\n";
		    write << it->name <<"\n";
		    write << it->pass <<"\n";
		    write << it->pID <<"\n";
		    write << "\n";
	    }
    }
};

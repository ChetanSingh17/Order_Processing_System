#include <iostream>
#include <list>
#include <fstream>
using namespace std;

struct ItemD{
    string pID;
    string iID;
    string name;
    string des;
    string rawMaterial;
    string time_req;
    string manLab_Count;
    string man_cost;
    
    ItemD(){
        stringstream ss;
        ss <<  rand()%(200-100+1) +100;
        ss >> iID;
    }
    
};


class Item{
    public:
    list<ItemD> file_to_list(){
        list<ItemD> l;
        ItemD itm;
        fstream read("item.txt");
        read >> itm.pID;
        read >> itm.iID;
        read >> itm.name;
        read >> itm.des;
        read >> itm.rawMaterial;
        read >> itm.time_req;
        read >> itm.manLab_Count;
        read >> itm.man_cost;
        read.ignore();
    	while(!read.eof()){
    	    l.push_back(itm);
    	    read >> itm.pID;
            read >> itm.iID;
            read >> itm.name;
            read >> itm.des;
            read >> itm.rawMaterial;
            read >> itm.time_req;
            read >> itm.manLab_Count;
            read >> itm.man_cost;
            read.ignore();
    	}
        return l;
    }
    void list_to_file(list<ItemD>l){
        fstream write;
        write.open("item.txt", ios :: out);
        list<ItemD>:: iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		    //cout << it->phID << " " << it->name << " " << it->pass << " "<< it->pID <<"\n";
		    write << it->pID << "\n";
            write << it->iID << "\n";
            write << it->name << "\n";
            write << it->des << "\n";
            write << it->rawMaterial << "\n";
            write << it->time_req << "\n";
            write << it->manLab_Count << "\n";
            write << it->man_cost << "\n";
            write << "\n";
	    }
    }
};
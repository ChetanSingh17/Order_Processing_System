#include <iostream>
using namespace std;

struct Clientdetails{
    string id;
    string name;
    string loc;
    string pbusiness;
    string cno;
    string pass;
    string approve;
};


class Structure{
    public:
    list<Clientdetails> file_to_list(){
        list<Clientdetails> l;
        Clientdetails c;
        fstream read("client.txt");
        //read.ignore();
        getline(read, c.id);
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
    	getline(read, c.approve);
    	while(!read.eof()){
    	    l.push_back(c);
    	    getline(read, c.id);
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
        	getline(read, c.approve);
    	}
    	return l;
    }
    void list_to_file(list<Clientdetails>l){
        fstream write;
        write.open("client.txt", ios :: out);
        list<Clientdetails> ::iterator it;
	    for(it = l.begin(); it!=l.end(); it++){
		  //  cout << it->id << " " << it->name << " " << it->loc << " "<< it->pbusiness << " "<< it->cno 
		  //  <<" " << it->pass << " "<< it->approve <<"\n";
		    write << it->id <<"\n";
		    write << it->name <<"\n";
		    write << it->loc <<"\n";
		    write << it->pbusiness <<"\n";
		    write << it->cno <<"\n";
		    write << it->pass <<"\n";
		    write << it->approve <<"\n";
	    }
    }
};
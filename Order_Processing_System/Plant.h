#include<iostream>
#include<fstream>
using namespace std;

struct PlantD{
    string pID;
    string name;
    string ploc;
    string lc;
    string capacity;
};

class Plant{
    public:
        list<PlantD> file_to_list(){
            list<PlantD>l;
            fstream read;
            read.open("plant.txt");
            PlantD pd;
            read >> pd.pID;
            read >> pd.name;
            read >> pd.ploc;
            read >> pd.lc;
            read >> pd.capacity;
            read.ignore();
            while(!read.eof()){
                l.push_back(pd);
                read >> pd.pID;
                read >> pd.name;
                read >> pd.ploc;
                read >> pd.lc;
                read >> pd.capacity;
                read.ignore();
            }
            return l;
        }
        
        void list_to_file(list<PlantD>l){
            fstream write;
            write.open("plant.txt", ios :: out);
            list<PlantD>:: iterator it;
    	    for(it = l.begin(); it!=l.end(); it++){
    	        write << it->pID << "\n";
    	        write << it->name << "\n";
    	        write << it->ploc << "\n";
    	        write << it->lc << "\n";
    	        write << it->capacity << "\n";
    	        write << "\n";
    	    }
        }
};
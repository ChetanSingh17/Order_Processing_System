#include <iostream>
//#include "Order.h"
#include "Client_Order.h"
#include "Item.h"
#include "Validate.h"
using namespace std;

void genSubPO(string cID);
void vPO(string cID);

class Client_Order co;
class Item itd;
class Order od;

int oID;

class Client{
	public:
	void clientPage(string cID){
	    fstream read("oid.txt");
    	if(!read.fail()){
    	    read >> oID;
    	}
    	else{
    	    oID = 1100;
    	}
    	read.close();
	    int ch = 0;
	    while(ch != 3){
	        cout <<" \n ************Welcome to Client Module*************** \n";
	        cout <<" \n *************************************************** \n";
	        cout <<" \n 1. Generate and Submit the Purchase Order \n";
	        cout <<" \n 2. view the purchase order Status \n";
	        cout <<" \n 3. Logout \n";
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
	                genSubPO(cID);
	                break;
	            case 2:
	                vPO(cID);
	                break;
	            case 3:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
	}
};

void genSubPO(string cID){
	list<ClientO> cl = co.file_to_list();
	list<ItemD> itm = itd.file_to_list();
	list<OrderD> ol = od.file_to_list();
	ClientO corder;
	OrderD norder;
	list<ItemD> :: iterator it;
	//stringstream s;
    for(it = itm.begin(); it!=itm.end(); it++){
        cout <<"\nItem ID : " <<it->iID <<"\nitem Name : " <<it->name <<"\nItem Description : " <<it->des 
        <<"\nRaw Material : " <<it->rawMaterial <<"\nTime Required : " <<it->time_req 
        <<"\nManufacturing Laborer Count : " <<it->manLab_Count <<"\nMan Cost : " <<it->man_cost <<"\n";
    }
    string iName;
    // cout <<"\nEnter the Item name to place order : ";
    // cin >> iName;
    while(true){
        cout <<"Enter Item  Name : ";
        cin >> iName;
        if(!is_valid_name(iName)){
            cout <<"\nItem Name Should be string\n";
        }
        else{
            break;
        }
    }
    int minpend = INT_MAX;
    string pID, pName, iID;
    
    int fOrder = 1;
    int oPlaced = 0;
    
    list<OrderD> :: iterator itr;
    for(itr = ol.begin(); itr!=ol.end(); itr++){
        //cout << " no " << itr->iName;
        pName = itr->pname;
        if(itr->iName == iName){
            stringstream s;
        	fOrder = 0;
        	cout <<"yes";
        	int pending;
        	s << itr->pending;
        	s >> pending;
        	if(pending<minpend){
        		minpend = pending;
        		pID = itr->pID;
        		//iID = itr->iID;
        		cout << "\nPlant Name  : " << pName;
			}
		}
    }
    int quantity;
    cout <<"\nEnter quantity : ";
    cin >> quantity;
    if(fOrder){
    	int cost, tCost;
    	for(it = itm.begin(); it!=itm.end(); it++){
    		if(it->name == iName){
    		    stringstream s;
    			pID = it->pID;
    			//cout << "pID " << pID;
    			s << it->man_cost;
    			s >> cost;
    			cout << "cost " <<cost;
    			iID = it->iID;
    			//cout << "iID" <<iID;
    			break;
			}
    	}
    	stringstream s1,s2,s3;
    	s1 << oID;
        s1 >> corder.oID;
        cout <<"\noID " << corder.oID;
    	tCost = cost*quantity;
    	cout <<"\ntcost " << tCost;
    	corder.iID = iID;
    	cout << "\niID " <<corder.iID;
    	corder.cID = cID;
    	corder.iName = iName;
    	cout << "\ncID " <<corder.cID;
    	corder.pName = pName;
    	cout <<"\nItem ID : " <<pName;
    	corder.pID = pID;
    	cout << "\npID " <<corder.pID;
    	s2 << tCost;;
    	s2 >> corder.cost;
    	cout << "\ntcost " <<corder.cost;
    	s3 << quantity;
    	s3 >> corder.quantity;
    	cout <<"\nquantity " << corder.quantity;
    	oPlaced = 1;
		oID++;
		fstream write;
		write.open("oid.txt");
    	write << oID <<"\n";
    	write.close();	
	}
	int cost, tCost=0;
	if(!fOrder){
    	for(it = itm.begin(); it!=itm.end(); it++){
    		if((it->name == iName) && (it->pID == pID)){
    		    stringstream s4;
    			s4 << it->man_cost;
    			iID = it->iID;
    			s4 >> cost;
    			break;
			}
    	}
    	stringstream s1,s2,s3;
    	s1 << oID;
        s1 >> corder.oID;
        cout <<"\noID " << corder.oID;
    	tCost = cost*quantity;
    	cout <<"\ntcost " << tCost;
    	corder.iID = iID;
    	cout << "\niID " <<corder.iID;
    	corder.cID = cID;
    	corder.iName = iName;
    	cout << "\ncID " <<corder.cID;
    	corder.pName = pName;
    	cout <<"\nItem ID : " <<pName;
    	corder.pID = pID;
    	cout << "\npID " <<corder.pID;
    	s2 << tCost;
    	s2 >> corder.cost;
    	s3 << quantity;
    	s3 >> corder.quantity;
    	oPlaced = 1;
    	oID++;
		fstream write;
		write.open("oid.txt");
    	write << oID <<"\n";
    	write.close();
	}
	if(oPlaced){
	    stringstream s1,s2,s3;
    	s1 << oID;
        s1 >> norder.oID;
    	norder.pID = pID;
    	norder.pname = pName;
    	norder.iName = iName;
    	s2 << quantity;
    	s2 >> norder.recieved;
    	norder.processed = "0";
    	s3 << quantity;
    	s3 >> norder.pending;
    	norder.revenue = "0";
    	norder.status = "received";
    	ol.push_back(norder);
    	od.list_to_file(ol);
		cl.push_back(corder);
		co.list_to_file(cl);	
	}
	else{
		cout <<"\ncould not placed order \n";
	}
}
void vPO(string cID){
	list<ClientO> cl = co.file_to_list();
	list<ClientO> :: iterator it;
    for(it = cl.begin(); it!=cl.end(); it++){
    	if(it->cID == cID){
            cout <<"\nOrder ID : " <<it->oID <<"\nPlant ID : " <<it->pID <<"\nPlant Name : " <<it->pName 
            <<"\nItem ID : " <<it->iID <<"\nItem Name : " <<it->iName <<"\nQuantity : " <<it->quantity <<"\nCost : " <<it->cost <<"\n";
        }
    }
}

#include <iostream>
//#include "Item.h"
//#include "PHDetails.h"
//#include "Order.h"
#include "Validate.h"
using namespace std;

void listOfPO(string pID);
void manageGoods(string pID);
void updatePOS(string pID);


class Item itm;
class PHDetails ph1;
//class Order o;

//list<ItemD> itm;


void Add(string pID){
    //cout <<"\pID\n";
    list<ItemD> item = itm.file_to_list();
    ItemD it;
    
    it.pID = pID;
    //cout << it.iID;
    // cout <<"\nEnter Item name : ";
    // cin >> it.name;
    while(true){
        cout <<"Enter Item  Name : ";
        cin >> it.name;
        if(!is_valid_name(it.name)){
            cout <<"\nItem Name Should be string\n";
        }
        else{
            break;
        }
    }
    cout <<"\nEnter Item Description : ";
    cin >> it.des;
    // cin >> it.rawMaterial;
    // cout << "\nTime Required : ";
    while(true){
        cout <<"Enter Item Raw Material : ";
        cin >> it.rawMaterial;
        if(!is_valid_name(it.rawMaterial)){
            cout <<"\nRaw Material Should be string\n";
        }
        else{
            break;
        }
    }
    // cout << "\nTime Required : ";
    // cin >> it.time_req;
     while(true){
            cout <<"\nEnter Time Required : ";
            cin >> it.time_req;
            if(!is_valid_num(it.time_req)){
                cout <<"\nTime Should be Integer\n";
            }
            else{
                break;
            }
        }
    // cout << "\nManufacturing Laborer Count : ";
    // cin >> it.manLab_Count;
    while(true){
            cout <<"\nEnter Manufacturing Laborer Count : ";
            cin >> it.manLab_Count;
            if(!is_valid_num(it.manLab_Count)){
                cout <<"\nManufacturing Laborer Count Should be Integer\n";
            }
            else{
                break;
            }
        }
    // cout << "\nManufacturing Cost : ";
    // cin >> it.man_cost;
    while(true){
            cout <<"\nEnter Manufacturing Cost : ";
            cin >> it.man_cost;
            if(!is_valid_num(it.man_cost)){
                cout <<"\nManufacturing Cost Should be Integer\n";
            }
            else{
                break;
            }
        }
    item.push_back(it);
    cout <<"\nItem Added successfuly\n";
    itm.list_to_file(item);
}

void Update(string pID){
    list<ItemD> item = itm.file_to_list();
    list<ItemD> :: iterator it;
    bool message = false;
    string iname;
    // cout <<"\nEnter Item name to Update : ";
    // cin >> iname;
    while(true){
        cout <<"Enter Item  Name to Update : ";
        cin >> iname;
        if(!is_valid_name(iname)){
            cout <<"\nItem Name Should be string\n";
        }
        else{
            break;
        }
    }
    for(it = item.begin(); it!=item.end(); it++){
        if(it->pID == pID && it->name == iname){
            message = true;
            string des, rawMaterial, manLab_Count, time_req, man_cost;
            cout <<"\nEnter new Description : ";
            cin >> des;
            // cout <<"\nEnter new Raw Material : ";
            // cin >> rawMaterial;
            while(true){
                cout <<"Enter Item Raw Material : ";
                cin >> rawMaterial;
                if(!is_valid_name(rawMaterial)){
                    cout <<"\nRaw Material Should be string\n";
                }
                else{
                    break;
                }
            }
            // cout <<"\nEnter new Manufacturing Laborer Count : ";
            // cin >> manLab_Count;
            while(true){
                cout <<"\nEnter Manufacturing Laborer Count : ";
                cin >> manLab_Count;
                if(!is_valid_num(manLab_Count)){
                    cout <<"\nManufacturing Laborer Count Should be Integer\n";
                }
                else{
                    break;
                }
            }
            // cout <<"\nEnter new Time Required : ";
            // cin >> time_req;
            while(true){
                cout <<"\nEnter Time Required : ";
                cin >> time_req;
                if(!is_valid_num(time_req)){
                    cout <<"\nTime Should be Integer\n";
                }
                else{
                    break;
                }
            }
            cout <<"\nEnter new Manufacturing Cost : ";
            cin >> man_cost;
            it->name = iname;
            it->des = des;
            it->rawMaterial = rawMaterial;
            it->manLab_Count = manLab_Count;
            it->time_req = time_req;
            it->man_cost = man_cost;
            //break;
        }
    }
    if(message == true){
        itm.list_to_file(item);
        cout <<"\nItem details have been updated\n";
    }
    else{
         cout <<"\nSorry there is no Item with name you enter\n";
    }
}

void Delete(string pID){
    list<ItemD> item = itm.file_to_list();
    list<ItemD> :: iterator it;
    bool message = false;
    string iname;
    // cout <<"\nEnter Item name to Delete : ";
    // cin >> iname;
    while(true){
        cout <<"Enter Item  Name to Update : ";
        cin >> iname;
        if(!is_valid_name(iname)){
            cout <<"\nItem Name Should be string\n";
        }
        else{
            break;
        }
    }
    for(it = item.begin(); it!=item.end(); it++){
        if(it->pID == pID && it->name == iname){
            message = true;
            item.erase(it);
            break;
        }
    }
    if(message == true){
        itm.list_to_file(item);
        cout <<"\nItem successfuly deleted\n";
    }
    else{
         cout <<"\nSorry there is no Item with name you enter\n";
    }
}

void View(string pID){
    list<ItemD> item = itm.file_to_list();
    list<ItemD> :: iterator it;
    bool message = false;
    for(it = item.begin(); it!=item.end(); it++){
        if(it->pID == pID){
            message = true;
            cout <<"\nItem ID : " <<it->iID <<"\nitem Name : " <<it->name <<"\nItem Description : " <<it->des 
            <<"\nRaw Material : " <<it->rawMaterial <<"\nTime Required : " <<it->time_req 
            <<"\nManufacturing Laborer Count : " <<it->manLab_Count <<"\nMan Cost : " <<it->man_cost <<"\n";
        }
    }
    if(message == false){
        cout <<"\nPlant Head have no plant yet\n";
    }
}


class PlantHead{
	public :
	void plantheadPage(string pID){
	    int ch = 0;
	    cout <<" \n ************Welcome to PlantHead Module*************** \n";
	    cout <<" \n ****************************************************** \n";
	    while(ch != 4){
	        cout <<" \n 1. View the list of purchase orders \n";
	        cout <<" \n 2. Manage Goods \n";
	        cout <<" \n 3. Update the purchase order status \n";
	        cout <<" \n 4. Logout \n";
	        cout <<" \n Enter Your Choice : ";
	        cin >> ch;
	        switch(ch){
	            case 1:
	                listOfPO(pID);
	                break;
	            case 2:
	                manageGoods(pID);
	                break;
	            case 3:
	                updatePOS(pID);
	                break;
	            case 4:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
	}
};

void listOfPO(string pID){
    list<OrderD> od = o.file_to_list();
    list<OrderD> :: iterator it;
    for(it = od.begin(); it!=od.end(); it++){
        if(pID == it->pID){
            cout <<"\nOrder ID : " <<it->oID <<"\nPlant Name : " <<it->pname <<"\nItem Name : " <<it->iName <<"\nRecieved : " <<it->recieved 
            <<"\nProcessed ID : " <<it->processed <<"\nPending : " <<it->pending <<"\nRevenue : " <<it->revenue <<"\nStatus : " <<it->status <<"\n";
        }
    }
}


void manageGoods(string pID){
        int ch = 0;
	    cout <<" \n *************Manage Goods*************** \n";
	    cout <<" \n **************************************** \n";
	    while(ch != 5){
	        cout <<" \n 1. Add Item\n";
	        cout <<" \n 2. Update Item\n";
	        cout <<" \n 3. Delete Item\n";
	        cout <<" \n 4. View Item\n";
	        cout <<" \n 5. Exit \n";
	        while(true){
    	        cout <<" \n Enter Your Choice : ";
    	        cin >> ch;
    	        if(isalpha(ch)){
    	            continue;
    	        }
    	        else{
    	            break;
    	        }
	        }
	        switch(ch){
	            case 1:
	                Add(pID);
	                break;
	            case 2:
	                Update(pID);
	                break;
	            case 3:
	                Delete(pID);
	                break;
	            case 4:
	                View(pID);
	                break;
	           case 5:
	                break;
	            default:
	                cout <<" \nPlease Enter a Valid Choice \n";
	                continue;
	        }
	    }
	
}
void updatePOS(string pID){
    list<OrderD> od = o.file_to_list();
    list<OrderD> :: iterator it;
    string name;
    // cout <<"\nEnter order name to update status : ";
    // cin >> name;
    while(true){
        cout <<"\nEnter order name to Update status : ";
        cin >> name;
        if(!is_valid_name(name)){
            cout <<"\nItem Name Should be string\n";
        }
        else{
            break;
        }
    }
    bool message = false;
    for(it = od.begin(); it!=od.end(); it++){
        if(pID == it->pID && it->pname == name){
            message = true;
            string newstatus;
            // cout <<"\nEnter new status : ";
            // cin >> newstatus;
            while(true){
                cout <<"\nEnter new status : ";
                cin >> newstatus;
                if(!is_valid_name(newstatus)){
                    cout <<"\nStatus Should be string\n";
                }
                else{
                    break;
                }
            }
            it->status = newstatus;
        }
    }
    if(message == true){
        cout <<"\nStatus update successfuly \n";
        o.list_to_file(od);
    }
    else{
        cout <<"\n Order name doesn't exist \n";
    }
	
}

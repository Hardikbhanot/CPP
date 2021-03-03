// ONSHOP SHOPPING MADE EASY 

// UI by Sonu 

#include<iostream>
#include<fstream>
#include<cstring>
// hierhhejejkjsj
using namespace std;

int logstat=0,itemCh=0;

//Register class

class Register{


    char	userName[20] , password[20];
    
public:    
        //meghansh
    	void take(){
    		cout<<"\t\t\tEnter your user name ";
    		cin>>userName;
    		cout<<"\n\t\t\tEnter your password ";
    		cin>>password;

		}
//		void show(){
//			cout<<"Username : "<<userName;
//			cout<<"\nPassword : "<<password;
//		 }

		//meghansh

        void fileopw(){
        	ofstream o;
        	ifstream i;
        	char newName[20]="users/";
        	strcat(newName,userName);
        	i.open(newName,ios::binary);
        	if(i.is_open()){
        		cout<<"\t\t\tUser already exists";
				i.close();
			}
			else{
            	o.open(newName,ios::binary);
            	o.write((char*)this,sizeof(Register));
        		o.close();
        		cout<<"\t\t\tUser created successfully\n\t\t\t";
        }
		}	
//		void fileopr(){
//			ifstream i;
//			Register temp;
//			i.open(userName,ios::binary);
//			i.read((char*)&temp,sizeof(Register));
//			temp.show();
//}	
        //meghansh
		void logincheck(){
			ifstream ch;
			Register tem;
			char newName[20]="users/";
        	strcat(newName,userName);
			ch.open(newName,ios::binary);
			if(!ch.is_open()){
				cout<<"\t\t\tUser doesn't Exist"<<endl;
			}
			else{
				ch.read((char*)&tem,sizeof(Register));
				if(!strcmp(userName,"meghansh")&&!strcmp(password,"megh1612")){
                   	::logstat=1;
			       	cout<<"\n\t\t\tWelcome admin"<<userName<<endl<<endl;
			    
			}
			else if(!strcmp(tem.userName,userName)&&!strcmp(tem.password,password)){
				::logstat=2;
				cout<<"\n\t\t\tWelcome  "<<tem.userName<<endl<<endl;
			}
			else
			    cout<<"\n\t\t\tUsername or password is not correct\n ";
		}
			ch.close();
		}
		
};
class item{
	char itemName[20];
    long price;
public:
	//Sonu
	void itemUpdate(){
		cout<<"\t\t\tEnter the name of the item : ";
		cin>>itemName;
    	cout<<"\n\t\t\tEnter the Price : ";
		cin>>price;
	}
	//sonu
	void itemWrite(){
		
		ofstream it,itt;
		char newName[20]="items/";
		strcat(newName,itemName);      
		strcat(newName,".txt");    
		it.open(newName ,ios::out);
		it<<itemName<<"\t"<<price;
		it.close();
		itt.open("itemList/items.txt",ios::app);
		itt<<itemName<<"\t"<<price<<endl;
		itt.close();
}
};
//Arush
void priceCalc(int qty,char name[]){
		
		ifstream st;
	
		char newName[20]="items/",nme[20]; //concatenation    newName=items/
 		strcat(newName,name);                 //newName = items/ + name 
		strcat(newName,".txt");        //   newName =   items/ + name + .txt      
		char c='y';
		long amount,totalAmount;
		st.open(newName);

//	    if(st.is_open())

	    st>>nme;
		st>>amount;
		totalAmount = qty*amount;	
		cout<<"\n\t\t\tYour total amount is : "<<totalAmount;
		cout<<"\n\t\t\tDo you want to buy?(Y/N) ";
		cin>>c;
		if(c=='y'||c=='Y'){
		cout<<"\n\t\t\t!!!Item purchased!!!\n";

	}
	
//else
//	    cout<<"\n\t\t\tEnter a valid Item name !!!";
	
}
//Arush	
void itemCheck(char name[]){
		ifstream st;
	    
		char newName[20]="items/",nme[20];
		strcat(newName,name);
		strcat(newName,".txt");
	  	st.open(newName);
	  	if(st.is_open()){
	  	    ::itemCh=1;    
	  	}
}
//Sonu
void itemShow(){
		ifstream rd;
		string itep;
		cout<<"\n\t\t\t  =============================\n";
		cout<<"\t\t\t  |       ITEMS :-)            |\n";
		cout<<"\t\t\t  =============================\n";
		rd.open("itemList/items.txt");
		cout<<"\t\t\t ITEM  \t PRICE\n";
	while(!rd.eof()){	
		getline(rd,itep);
		cout<<"\t\t\t "<<itep<<"\n";
}
	
}
//Arush
void itemDeleteAll(){
	
	ofstream op;
	op.open("itemList/items.txt");	
	op.close();
}		
int main(){
system("color b");
Register user;
int choice;
item goods;
char addItem[20],newName[20]="items/";

//welcome page

cout<<"\t\t\t=======================================\n";
cout<<"\t\t\t|       WELCOME TO ONSHOP             |\n";
cout<<"\t\t\t=======================================\n";
cout<<"\t\t\t        MAKE SHOPPING EASY\n\n\t\t\t";
system("pause");	
system("cls");

//choice page

choicePage:
cout<<"\t\t\t=======================================\n";
cout<<"\t\t\t|       ENTER YOUR CHOICE             |\n";
cout<<"\t\t\t=======================================\n";
cout<<"\n\t\t\t1.Login \t2.SignUp\t3.Exit ";
cin>>choice;
system("cls");
switch(choice){
    	//login sign up
case 1:	
        //login
        cout<<"\n\t\t\t  =============================\n";
		cout<<"\t\t\t  |    PLEASE Login :-)       |\n";
		cout<<"\t\t\t  =============================\n\n\n";
		user.take();
		user.logincheck();
		system("pause");
		system("cls");
        //		admin login
		if(logstat==1){
			int admin;
			adminChoice:
			cout<<"\t\t\t=======================================\n";
			cout<<"\t\t\t|           ADMIN ACCESS              |\n";
			cout<<"\t\t\t=======================================\n";	
		 	cout<<"\t\t\t1.Update items\t2.Show Items\t3.Remove  ";
			cin>>admin;
			system("cls");
	    	switch(admin){
				case 0: char d;
			         	cout<<"\n\n\n\t\t\tDelete all items (Y/N)? ";
			         	cin>>d;
			         	if(d=='y'|d=='Y'){
			         	itemDeleteAll();
			         	system("cls");
			         	cout<<"\n\n\n\t\t\tDo you want to continue?(Y/N) ";
			         	cin>>d;
			         	if(d=='y'||d=='Y'){
			         	  	system("cls");
						  	goto adminChoice;
			         	 
		    		    }
					 	else{
			        		system("cls");
			            	goto choicePage;
			            }
			        		break;
				case 1:     
			            cout<<"\t\t\t=======================================\n";
						cout<<"\t\t\t|           UPDATE ITEMS              |\n";
						cout<<"\t\t\t=======================================\n";
		   			    goods.itemUpdate();
		                goods.itemWrite();
		                system("cls");
			         	cout<<"\n\n\n\t\t\tDo you want to continue?(Y/N) ";
			         	cin>>d;
			         	if(d=='y'||d=='Y'){
			         	  system("cls");
						  goto adminChoice;
			         	}
						else{
			        		system("cls");
			            	goto choicePage;
			            }
		   					break;
	
				case 3: 
						char ite[20];
			        	cout<<"\n\n\n\t\t\tEnter the item to Remove ";
			        	cin>>ite;
			        	strcat(newName,ite);
			        	strcat(newName,".txt");
						if(!remove(newName)){
							cout<<"\n\n\n\t\t\tItem Removed please update the list manually ";
					    } 
						system("cls");
			         	cout<<"\n\n\n\t\t\tDo you want to continue?(Y/N) ";
			         	cin>>d;
			         	if(d=='y'||d=='Y'){
			         	  	system("cls");
						  	goto adminChoice;
			         	 
					    }
					 	else{
			        		system("cls");
			            	goto choicePage;
			            }
			        		break;
				case 2: 
			      		itemShow();
			      		cout<<"\t\t\t";
			        	system("pause");
						system("cls");
			         	cout<<"\n\n\n\t\t\tDo you want to continue?(Y/N) ";
			         	cin>>d;
			         	if(d=='y'||d=='Y'){
			         	  	system("cls");
						  	goto adminChoice;
			         	 
					    }
					 	else{
			        		system("cls");
			            	goto choicePage;
			            }
			        		break;			  		
			default: 
						cout<<"\n\n\n\t\t\tEnter the correct choice ";
		        		     
		   } 
		   }
		   }
		//user login item display
		else if(logstat==2){
			
				label:
			    
				itemShow();
				cout<<"\t\t\tEnter the name of item to purchase ";
				cin>>addItem;
				itemCheck(addItem);
				if(::itemCh==1){	

						char a='y';
						cout<<"\n\t\t\tProceed to buy(Y/N) ";
						cin>>a;
				if(a=='y'||a=='Y'){
					system("cls");
				// BUYING
				char b='y';
				int qty;
				cout<<"\n\n\n\t\t\tEnter the quantity ";
				cin>>qty;
				priceCalc(qty,addItem);
				system("pause");
				system("cls");
				goto choicePage;			
				
				}

				else{
						system("cls");
			  		  	goto label;
			}
			}
			  	else{
			      	cout<<"\n\t\t\t!!Enter a valid item name!!\n";
	                system("pause");
					system("cls");
					goto choicePage;   		       
				  }
			}
		        
		    		break;
case 2:	
		//register
		cout<<"\n\t\t\t  =============================\n";
		cout<<"\t\t\t  |  PLEASE signup :-)  |\n";
		cout<<"\t\t\t  =============================\n";
	   	user.take();
	   	user.fileopw();
		system("pause");
		system("cls");
		goto choicePage; 
       	break;
case 3: 
        system("cls");
        cout<<"\n\t\t\t  =============================\n";
		cout<<"\t\t\t  | THANKS FOR VISITING :-)  |\n";
		cout<<"\t\t\t  =============================\n";
        system("exit");       
	    break;       	
default:
  		cout<<"\n\n\n\t\t\tEnter a valid choice\n";
  		
}

return 0;

}


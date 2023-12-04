using namespace std;
#include<iostream>
#include<string.h>
struct Player{
 int Pid;
 int Mtch;
 char Pname[20];
 int Trun;
 double slry;

 Player(){
    cout<<" helo plr dtabse"<<"\n";
 }
 void setPid(int d){
    this->Pid=d;
   }
   int getPid(){
    return this->Pid;
   }
   void setMtch(int mt){
    this->Mtch=mt;
   }
   int getMtch(){
    return this->Mtch;
   }
   void setPname(char* naam){
    strcpy(this->Pname,naam);
   }
   char* getPname(){
    return this->Pname;
   }
   void setTrun(int tr){
    this->Trun=tr;
   }
   double getTrun(){
    return this->Trun;
   }
   void setSlry(double an){
    this->slry=an;
   }
    double getSlry(){
    return this->slry;
   }
   void display(){
    cout<<"-----------------all stored inf here------------"<<"\n";
    cout<<"id= "<<Pid<<"\n";
    cout<<"match= "<<Mtch<<"\n";
    cout<<"pname= "<<Pname<<"\n";
    cout<<"ttl match= "<<Trun<<"\n";
    cout<<"salryr= "<<slry<<"\n";
   }

};

  struct Sports{
  
  void Searchplayer(Player* database ,int n){
        int newid;
       char nem[30];
        int choice;
        for(int j=0;j<n;j++){ 
    // cout<<"\nid is------"<< database[j].id<<"\n";
    // cout<<"price----- "<<database[j].price<<"\n";
    //  cout<<"rating----- "<<database[j].rating<<"\n";
    //  cout<<"bname ------ "<<database[j].bname<<"\n";
    // cout<<"author----- "<<database[j].author<<"\n";
    database[j].display();
   }   
    cout<<"\nenter your choice to search 1= byid and 2= byname--->";
    cin>>choice;
    int found=0;
   switch (choice){

case 1:
       // int newid;
        // char name[10];
        cout<<"enter id of player for saerch\n";
        cin>>newid;
        for(int i=0;i<n;i++){
        if(database[i].Pid==newid ){
          found++;
            // cout<<"\nplayer is found\n";
            // cout<<"id= "<<database[i].id;
            // cout<<"\nrating= "<<database[i].rating;
            // cout<<"\nprice= "<<database[i].price;
            // cout<<"\nname= "<<database[i].bname;
            // cout<<"\nauthor= "<<database[i].author; 
            database[i].display();
           break;
        }
          }    
          if(found==0){
            cout<<"\nnot found"<<"\n";
      }  
        break;
   

       case 2:
           //char name[10];
         cout<<"\nenter player name   for search\n";
         cin>>nem;
           for(int i=0;i<n;i++){
           if (strcmp(database[i].Pname, nem) == 0) { 
           found=1;
            cout<<"\nplyer is found\n";
            // cout<<"id= "<<database[i].id;
            // cout<<"\nprice= "<<database[i].price;
            // cout<<"\nrating= "<<database[i].rating;
            // cout<<"\nname= "<<database[i].bname;
            // cout<<"\nauthor "<<database[i].author; 
             database[i].display();
            break;
            } 

          }
          if(found==0){
            cout<<"\nnot found"<<"\n";
          }
          break;
      }
    }
  
 void Playerrecord(Player* database, int n){  
    char wrtr[15];
    cout<<"Enter the player Name to display his record= ";
     cin>> wrtr;
    // cout<<" found all detail\t  ID\t | Price\t | Rating\t |namebook\t| author |\n";
    int found = 0;
    for (int i = 0; i < n; i++) {
         if (strcmp(database[i].Pname, wrtr) == 0) {
      //  cout<<"\nid is------"<< database[i].id<<"\n";
      // cout<<"price----- "<<database[i].price<<"\n";
      // cout<<"rating----- "<<database[i].rating<<"\n";
      // cout<<"bname ------ "<<database[i].bname<<"\n";
      // cout<<"author----- "<<database[i].author<<"\n";
       database[i].display();
           found++;
           break;
        }
    }
      if (found==0) { 
        cout<<"No record found for this player  in the database= "<<wrtr<<"\n";
      
               }
  }

void Displaytop3(Player* database,int n){
 // int temp;
cout<<"TOP raking player from our database.................\n";
for(int i=0;i<n;i++){
 cout<<"display plyr num \n"<<i+1;
}
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (database[j].Trun < database[j + 1].Trun) {
                 Player  temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
           }
        }
     }
     cout<<"TOP 3 plyer based on runs...........result..............\n";
     for(int i=0;i<n;i++){
   database[i].display();
    }
}

void Removeplayer(Player* database,int n){
    int pId;
    cout<<"Enter the plyer ID to remove inform\n ";
    cin>>pId;
int found=0;
    for (int i = 0; i < n; i++) {
        if (database[i].Pid == pId) {
            for (int j = i; j < n - 1; j++) {
                database[j] = database[j + 1];
            }
            n--;
            found=1;
        } 
   }
      for(int i=0;i<n;i++){
    cout<<"\nplyer  no of recrd afer remve "<<i+1<<"\n";
       database[i].display();
        }

        if(found!=1){
        cout<<"\ninvalid id.........................try again\n";
        }
 }

 void Updateplayer(Player* database,int n) {
    int plId,rn;
    int tm;
    int count=0;
    cout<<"\nEnter the plyer ID for update \n";
    cin>>plId;
//update based on id
    for (int i = 0; i<n; i++) {
        if (database[i].Pid == plId) {
            count++;
            cout<<"Enter update run ";
            cin>>rn;
             database[i].setTrun(rn);
            cout<<"Enter update match ";
            cin>>tm;
            database[i].setMtch(tm);
            cout<<"player data for ID update compltly"<<plId<<"\n";
            break;
            
        }
    }
      if(count==0) {
        cout<<"pleyr with ID  not found in the database"<<plId<<"\n";
      }
     for(int i=0;i<n;i++){
      cout<<"\n"<<"after update player inf"<<"\n";
     database[i].display();
    }
}

 void Displayall(Player* database, int n){
  for(int i=0;i<n;i++){
    cout<<"display player num.........."<<"\n";
    database[i].display();
     }
 }

 void Addplayer(Player* database,int& n){
    database= new Player[n+1];          //  (BOOK*)realloc(sizeof(BOOK)*n+1);
     int id1;
    double price1; 
    int r,m;
    char name1[30];
    cout<<"THIS IS NEW ADDED player\n";
   // for(int i=0;i<*n;i++){
        cout<<"enter player id\n";
        cin>>id1;
       // database[i].id=id1;
       cout<<"enter player match\n";
         cin>>m;  
        cout<<"enter plyer run\n";
        cin>>r;  
         //fflush(stdin);
        cout<<"enter player name\n";
         cin>>name1;
         cout<<"enter plyer slry\n";
        cin>>price1; 

   // }
         database[n].Pid=id1;
          database[n].Mtch=m;
         database[n].Trun=r;
       strcpy(database[n].Pname,name1);
        database[n].slry=price1;
    
       n=n+1;
     cout<<"\n total player -"<<n;
     cout<<"\nid="<<id1;
      cout<<"\nmatch \n"<<m;
     cout<<"\nrun= "<<r;
     cout<<"\nplyrname= "<<name1;
     cout<<"\nsalry="<<price1;
     

    for(int i=0;i<n;i++){  
  //Displayall(database,n);
  cout<<"\nsuccessfully added  you can check now by displayall\n ";
     cout<<"\nplayer no "<<i+1<<"\n";
    cout<<"id is------  "<< database[i].Pid<<"\n";
    cout<<"match----- "<<database[i].Mtch<<"\n";
   cout<<"run----- "<<database[i].Trun<<"\n";
    cout<<"pname ------  "<<database[i].Pname<<"\n";
     cout<<"slry----- "<<database[i].slry<<"\n"; 
    }
  }

  };

  int main(){
 Sports game;
 Player* database;
    int choice;
     int n;
     int& num=n;
     cout<<" Enter  the num how many player you want to store in database";
     cin>>n;
   // database=(Player*)malloc(sizeof(int)*n);
   int d,m,r;
   double sl;
   char pnaam[20];
     database = new Player[n]; 
        for(int i=0;i<n;i++){
        cout<<"PLAYER No _____________________________________________________"<<i+1<<"\n";
        cout<<"enter PLayer id\n";
        cin>>d;
        database[i].setPid(d);  
        cout<<"enter player  totl match\n";
        cin>>m; 
         database[i].setMtch(m);
         cout<<"enter player name\n";
        cin>>pnaam;
        database[i].setPname(pnaam);
        cout<<"enter totl run"<<"\n";
        cin>>r;
        database[i].setTrun(r);
         cout<<"enter salary player\n";
         cin>>sl;
        database[i].setSlry(sl);

       database[i].getPid();
        database[i].getMtch();
         database[i].getTrun();
          database[i].getPname();
           database[i].getSlry();
        database[i].display();
    }
        do{
       cout<<"\nMenu:\n";
        cout<<"1. Add  new plyer\n";
        cout<<"2. Remove  player\n";
        cout<<"3. Search for  player\n";
        cout<<"4. Show player record\n";
        cout<<"5. Update player data\n";
        cout<<"6. Display top player\n";
        cout<<"7. Display all player\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice= \n";
        cin>>choice;
       switch(choice){
        case 1:
            
         game.Addplayer(database,n); 
        
        break;

        case 2:
             game.Removeplayer(database,num);
        break;

        case 3:
            game.Searchplayer(database ,n);
        break;

       case 4:
          game.Playerrecord(database,n);
        break;
        
       case 5:
         game.Updateplayer(database,n );
       break;

        case 6:
          game.Displaytop3(database,n);
         break;

    case 7:
         game.Displayall(database,n);      
    break;

    case 0:
    cout<<" Goodbye radhe radhe ";
    break;
 }
        }

  while (choice!=0);
 //delete database;
}


  


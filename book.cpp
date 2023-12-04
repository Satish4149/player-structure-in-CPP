using namespace std;
#include<iostream>
#include<stdlib.h>
#include<string.h>
  struct BOOK{
    int id;
    double price;
    int rating;
    char bname[30];
    char author[30];
    BOOK(){
        cout<<"\nhello librry\n";
    }
 
   void setBid(int d){
    this->id=d;
   }
   int getBid(){
    return this->id;
   }
   void setPrice(double pr){
    this->price=pr;
   }
   int getPrice(){
    return this->price;
   }
   void setBname(char* naam){
    strcpy(this->bname,naam);
   }
   char* getBname(){
    return this->bname;
   }
   void setRating(int rt){
    this->rating=rt;
   }
   double getRating(){
    return this->rating;
   }
   void setAname(char* an){
    strcpy(this->author,an);
   }
    char* getAname(){
    return this->author;
   }
   void display(){
    cout<<"-----------------all stored inf here------------"<<"\n";
    cout<<"id= "<<id<<"\n";
    cout<<"price= "<<price<<"\n";
    cout<<"bname= "<<bname<<"\n";
    cout<<"rating= "<<rating<<"\n";
    cout<<"Author= "<<author<<"\n";
   }
  //  BOOKMNGMNT(int id1,double rs,int rt,char* Bnam,char* Anam){    //prametr conrsut
  //     this->id=id1;
  //     this->price=rs;
  //     this->rating=rt;
  //     strcpy(this->bname,Bnam);
  //     strcpy(this->author,Anam);
  //   }
  };
   struct Library{
    void Searchbook(BOOK* database ,int n){
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
        cout<<"enter id of book for saerch\n";
        cin>>newid;
        for(int i=0;i<n;i++){
        if(database[i].id==newid ){
          found++;
            cout<<"\nbook is found\n";
            cout<<"id= "<<database[i].id;
            cout<<"\nrating= "<<database[i].rating;
            cout<<"\nprice= "<<database[i].price;
            cout<<"\nname= "<<database[i].bname;
            cout<<"\nauthor= "<<database[i].author; 
           // database[i].display();
           break;
        }
          }    
          if(found==0){
            cout<<"\nnot found"<<"\n";
            break;
      }  
   

       case 2:
           //char name[10];
         cout<<"\nenter book name of book  for search\n";
         cin>>nem;
           for(int i=0;i<n;i++){
           if (strcmp(database[i].bname, nem) == 0) { 
           found=1;
            cout<<"\nbook is found\n";
            cout<<"id= "<<database[i].id;
            cout<<"\nprice= "<<database[i].price;
            cout<<"\nrating= "<<database[i].rating;
            cout<<"\nname= "<<database[i].bname;
            cout<<"\nauthor "<<database[i].author; 
            break;
            } 

          }
          if(found==0){
            cout<<"\nnot found"<<"\n";
          break;
          }
      }
    }
  
 void Authorbook(BOOK* database, int n){  
    char wrtr[15];
    cout<<"Enter the Author Name to display his books= ";
     cin>> wrtr;
     cout<<" found all detail\t  ID\t | Price\t | Rating\t |namebook\t| author |\n";
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(database[i].author, wrtr) == 0) {
       cout<<"\nid is------"<< database[i].id<<"\n";
      cout<<"price----- "<<database[i].price<<"\n";
      cout<<"rating----- "<<database[i].rating<<"\n";
      cout<<"bname ------ "<<database[i].bname<<"\n";
      cout<<"author----- "<<database[i].author<<"\n";
           found++;
           break;
        }
    }
      if (found==0) { 
        cout<<"No books found for author  in the database= "<<wrtr<<"\n";
      
               }
  }

void Displaytop3(BOOK* database,int n){
 // int temp;
cout<<"TOP rating book from our database.................\n";
for(int i=0;i<n;i++){
 cout<<"display booknum \n"<<i+1;
}
     for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (database[j].rating < database[j + 1].rating) {
                 BOOK  temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
           }
        }
     }
     cout<<"TOP 3 BOOK based on rating...........result..............\n";
     for(int i=0;i<n;i++){
   database[i].display();
    }
}

void Removebook(BOOK* database,int n){
    int bookId;
    cout<<"Enter the Book ID to remove inform\n ";
    cin>>bookId;
int found=0;
    for (int i = 0; i < n; i++) {
        if (database[i].id == bookId) {
            for (int j = i; j < n - 1; j++) {
                database[j] = database[j + 1];
            }
            n--;
            found=1;
        } 
   }
      for(int i=0;i<n;i++){
    cout<<"\nbook no afer remve "<<i+1<<"\n";
       database[i].display();
        }

        if(found!=1){
        cout<<"\ninvalid id.........................try again\n";
        }
 }

 void Updatebook(BOOK* database,int n) {
    int bookId,rati;
    double pri;
    int count=0;
    cout<<"\nEnter the Book ID for update \n";
    cin>>bookId;
//update based on id
    for (int i = 0; i<n; i++) {
        if (database[i].id == bookId) {
            count++;
            cout<<"Enter update price ";
            cin>>pri;
             database[i].setPrice(pri);
            cout<<"Enter update rating ";
            cin>>rati;
            database[i].setRating(rati);
            cout<<"Book data for ID update compltly"<<bookId<<"\n";
            break;
            
        }
    }
      if(count==0) {
        cout<<"Book with ID  not found in the database"<<bookId<<"\n";
      }
     for(int i=0;i<n;i++){
      cout<<"\n"<<"after update book inf"<<"\n";
     database[i].display();
    }
}

 void Displayall(BOOK* database, int n){
  for(int i=0;i<n;i++){
    cout<<"display book num.........."<<"\n";
    database[i].display();
     }
 }

 void Addbook(BOOK* database,int& n){
    database= new BOOK[n+1];          //  (BOOK*)realloc(sizeof(BOOK)*n+1);
     int id1;
    double price1; 
    int rating1;
    char name1[30];
    char author1[30];
    cout<<"THIS IS NEW ADDED BOOK\n";
   // for(int i=0;i<*n;i++){
        cout<<"enter book id\n";
        cin>>id1;
       // database[i].id=id1;
        cout<<"enter book price\n";
        cin>>price1;   
        cout<<"enter book rating\n";
        cin>>rating1;  
         //fflush(stdin);
        cout<<"enter book name\n";
         cin>>name1;
        cout<<"enter book author\n";
        cin>>author1;
   // }
         database[n].id=id1;
         database[n].price=price1;
         database[n].rating=rating1;
       strcpy(database[n].bname,name1);
       strcpy(database[n].author,author1);
    
       n=n+1;
     cout<<"\n total book -"<<n;
     cout<<"id="<<id1;
     cout<<"\nprice="<<price1;
     cout<<"\nrating= "<<rating1;
     cout<<"\nname= "<<name1;
     cout<<"\nauthor\n"<<author1; 

    for(int i=0;i<n;i++){  
  //Displayall(database,n);
  cout<<"\nsuccessfully added  you can check now by displayall\n ";
     cout<<"\nbook no "<<i+1<<"\n";
    cout<<"id is------  "<< database[i].id<<"\n";
    cout<<"price----- "<<database[i].price<<"\n";
   cout<<"rating----- "<<database[i].rating<<"\n";
    cout<<"bname ------  "<<database[i].bname<<"\n";
     cout<<"author----- "<<database[i].author<<"\n"; 
    }
  }
};
//   ..we dont declrt bcz all ar in global
 void Addbook(BOOK*,int&);
  void Removebook(BOOK*,int);
 void Authorbook(BOOK*,int);
 void Updatebook(BOOK* ,int);
 void Displaytop3(BOOK*,int);
 void Searchbook(BOOK*,int);
 void Displayall(BOOK*,int);
int main(){
    Library lib;
    BOOK* database;
    int choice;
     int n;
     int& num=n;
     cout<<" Enter  the num how many books you want to store in database";
     cin>>n;
   // database=(BOOK*)malloc(sizeof(int)*n);
   int d,pri;
   double rat;
   char naam[20];
   char Aname[20];
     database = new BOOK[n]; 
        for(int i=0;i<n;i++){
        cout<<"BOOK No _____________________________________________________"<<i+1<<"\n";
        cout<<"enter book id\n";
        cin>>d;
        database[i].setBid(d);
         cout<<"enter book price\n";
         cin>>pri;
          database[i].setPrice(pri);  
        cout<<"enter book rating\n";
        cin>>rat; 
         database[i].setRating(rat);
         cout<<"enter book name\n";
        cin>>naam;
        database[i].setBname(naam);
         cout<<"enter book author\n";
        cin>>Aname;
        database[i].setAname(Aname);

       database[i].getBid();
        database[i].getPrice();
         database[i].getRating();
          database[i].getBname();
           database[i].getAname();
        database[i].display();
    }
        do{
       cout<<"\nMenu:\n";
        cout<<"1. Add  new book\n";
        cout<<"2. Remove  book\n";
        cout<<"3. Search for  book\n";
        cout<<"4. Show author books\n";
        cout<<"5. Update book data\n";
        cout<<"6. Display top books\n";
        cout<<"7. Display all books\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice= \n";
        cin>>choice;
       switch(choice){
        case 1:
            
         lib.Addbook(database,n); 
        
        break;

        case 2:
             lib.Removebook(database,num);
        break;

        case 3:
            lib.Searchbook(database ,n);
        break;

       case 4:
          lib.Authorbook(database,n);
        break;
        
       case 5:
         lib.Updatebook(database,n );
       break;

        case 6:
          lib.Displaytop3(database,n);
         break;

    case 7:
         lib.Displayall(database,n);      
    break;

    case 0:
    cout<<" Goodbye radhe radhe ";
    break;
 }
        }

  while (choice!=0);
 //delete database;
}
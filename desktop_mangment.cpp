#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip> 
#include <fstream>
using namespace std;

class Desktop{
  public:
    DIR *dp; 
    int i=0, j=0, k=0, l=0, m=0, L_file=0, cpp=0, file_size;
    string str,str1,str2,drive,name;
    struct dirent *ep;

    void process(int a){
        str1=str2="C:\\Users\\Dell\\Desktop\\";
        switch(a){
           case 1:
           {
               dp = opendir ("C:\\Users\\Dell\\Downloads\\");
            if (dp != NULL){         
              while (ep = readdir (dp)){
                  str=ep->d_name;
                  //*******************    S I Z E   ******************************
                   ifstream in_file("C:\\Users\\Dell\\Downloads\\"+str, ios::binary);
                   in_file.seekg(0, ios::end);
                   int file_size = in_file.tellg();
                 //*******************    S I Z E   *******************************
                   if(file_size>=0){
                         cout<<" "<<i+1<<".\t" << file_size<<" bytes \t:"<<str<<"\n";
                         if(str.substr(str.find_last_of(".") + 1) == "jpg" || str.substr(str.find_last_of(".") + 1) == "png" || str.substr(str.find_last_of(".") + 1) == "jpeg" || str.substr(str.find_last_of(".") + 1) == "gif") {
                                 j++;
                           }
                         if(str.substr(str.find_last_of(".") + 1) == "docx"){
                                 k++;
                           }
                         if(str.substr(str.find_last_of(".") + 1) == "txt"){
                                 l++;
                           }
                         if(str.substr(str.find_last_of(".") + 1) == "exe" || str.substr(str.find_last_of(".") + 1) == "lnk"){
                                 m++;
                           }
                        i++;
                     }
                }
              (void) closedir (dp);
             }
             else{
                 cout<<"Couldn't access the desktop.\n";
              }
            }
            break;
            case 2:{
                 dp = opendir ("C:\\Users\\Dell\\Downloads\\");
                if (dp != NULL){
                   while (ep = readdir (dp)){ 
                      str=ep->d_name;
                     //*******************    S I Z E   ******************************
                     ifstream in_file("C:\\Users\\Dell\\Downloads\\"+str, ios::binary);
                     in_file.seekg(0, ios::end);
                     int file_size = in_file.tellg();
                     //*******************    S I Z E   *******************************
              
                     if(file_size>=0){
                         if(str.substr(str.find_last_of(".") + 1) == "jpg" || str.substr(str.find_last_of(".") + 1) == "png" || str.substr(str.find_last_of(".") + 1) == "jpeg" || str.substr(str.find_last_of(".") + 1) == "gif") {
                                ab(str2+str,str2+"ESFP-II\\Image\\"+str);
                             }
                         if(str.substr(str.find_last_of(".") + 1) == "docx"){
                                ab(str2+str,str2+"ESFP-II\\Word\\"+str);
                             }
                         if(str.substr(str.find_last_of(".") + 1) == "txt"){
                                ab(str2+str,str2+"ESFP-II\\Text\\"+str);
                             }
                         if(str.substr(str.find_last_of(".") + 1) == "exe" || str.substr(str.find_last_of(".") + 1) == "lnk"){
                                ab(str2+str,str2+"ESFP-II\\Executed\\"+str);
                            }
                         if(str.substr(str.find_last_of(".") + 1) == "cpp"){
                               cpp++;
                            }
                       i++;
                      }
                    }
                   (void) closedir (dp);
                }
                else{
                      cout<<"Couldn't access the desktop.\n";
                 }
              }
              break;
              case 3:
                  {
                      str2="C:\\Users\\Dell\\Downloads\\";
                      dp = opendir ("C:\\Users\\Dell\\Downloads\\");
                      if (dp != NULL){         
                          while (ep = readdir (dp)){
                                 str=ep->d_name;
                                 //*******************    S I Z E   ******************************
                                 ifstream in_file("C:\\Users\\Dell\\Downloads\\"+str, ios::binary);
                                 in_file.seekg(0, ios::end);
                                 int file_size = in_file.tellg();
                                 //*******************    S I Z E   *******************************
                                 if(file_size>=0){
                                      if(file_size>L_file){
                                          L_file=file_size;
                                          name=str;
                                          drive=str2;
                                        }
                                      str=str.substr(0,str.find_last_of('.'));
                                      int lenght=str.length();
                                      if(lenght>=5){
                                            cout<<endl<<str;
                                        }
                                   }
                             }
                             (void) closedir (dp);
                        }
                      else{
                           cout<<"Couldn't access the desktop.\n";
                        }
                   }
                   break;
        }
     }
     void display(int a){
         switch(a){
             case 1:
             {
                cout<<"\t\t__________________________________________________________________________\n";
                cout<<"\t\t|\t Total number of Files on Desktop\t\t : "<<i<<"\t\t |"<<endl;
                cout<<"\t\t|\t Total number of img File on Desktop\t\t : "<<j<<"\t\t |"<<endl;
                cout<<"\t\t|\t Total number of words File on Desktop\t\t : "<<k<<"\t\t |"<<endl;
                cout<<"\t\t|\t Total number of text File on Desktop\t\t : "<<l<<"\t\t |"<<endl;
                cout<<"\t\t|\t Total number of executable files on Desktop\t : "<<m<<"\t\t |"<<endl;
                cout<<"\t\t``````````````````````````````````````````````````````````````````````````\n";
                      i=j=k=l=m=0;
               }
               break;
             case 2:
              {
                      cout<<"   No. of file with .cpp extention are : "<<cpp<<endl<<endl;
               }
               break;
             case 3:{
                     cout<<"-> Largetst File is :"<<name<<endl<<"-> Size of:"<<L_file<<" bytes "<<endl;
                     cout<<"-> Drive of file :"<<drive<<endl;
               }
               break;
         }
      }
      void ab(string sourcefile,string destinationfile){
               cout<<endl<<sourcefile<<endl;
               string line;
               ifstream ini_file {sourcefile,ios::binary};
               ofstream out_file {destinationfile,ios::binary};
               if(ini_file && out_file){
                  while(getline(ini_file,line)){
                      out_file << line << "\n";
                    }
                 cout << "Transferd \n";
                }
               else {
                     printf("Cannot read File");
                  }
            ini_file.close();
            out_file.close();
        }
      Desktop(){
        int key;
        cout<<"\n\tH e l l o  E v e r y o n e ! ! !  \n"<<"\tWelcome to ICT ganpat University Desktop Managment System.....\n"<<"Press '1' and enter to Performing Task : ";
        cin>>key;
      }
};

int main (void){
  char ch;
  int a;
  cout<<"\t\t ________________________________________________________________________\n";
  cout<<"\t\t|\t\t D e s k t o p  M a n a g e m e n t  S y s t e m\t | \n";
  cout<<"\t\t `````````````````````````````````````````````````````````````````````````\n";

  Desktop obj;      // O B J E C T     O F     C L A S S
  
  // T A S K  - 1  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  a=1;
      do{
          cout<<setfill(' ')<<setw(65)<<"__________________________\n";
          cout<<setfill(' ')<<setw(65)<<": Size Of Individual Files :"<<setfill(' ')<<setw(35)<<" |\n";
          cout<<setfill(' ')<<setw(65)<<"``````````````````````````\n";
          cout<<setfill('_')<<setw(60)<<"\n";
          cout<<"\\ \t"<<"Size \t \t:Name of file"<<setfill(' ')<<setw(23)<<" /\n";
          cout<<" "<<setfill('`')<<setw(58)<<"\n";
                 obj.process(a);
          cout<<setfill('_')<<setw(78)<<"\n\n";
          cout<<setfill(' ')<<setw(71)<<"--::: S U M M R Y  O F F I L E S ::--\n";
                 obj.display(a);
          cout<<"Are you want to refress [Y/N]?";   cin>>ch;
         }while(ch=='y' || ch=='Y');
  // T A S K - 2 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  a=2;
          cout<<setfill('_')<<setw(60)<<"\n";
      cout<<"Are you want to organize all file in single their respective extention Drive [Y/N]? ";
      cin>>ch;
      if(ch=='y' || ch=='Y'){
            obj.process(a);
        }
          cout<<setfill('_')<<setw(60)<<"\n";
      cout<<"Are you want to find no. of c++ file and .cpp executed file [Y/N]? ";
      cin>>ch;
      if(ch=='y' || ch=='Y'){
            obj.display(a);
        }
  // T A S K - 3 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  a=3;
          cout<<setfill('_')<<setw(60)<<"\n";
     cout<<"To continue, Press any Key and Enter..........\n";
     char any;
     cin>>any;
     cout<<setfill('_')<<setw(71)<<"\n";
     cout<<"| Name of files having at least 5 characters excluding extensions:   /\n";
     cout<<setfill('`')<<setw(70)<<"\n";
            obj.process(a);
     cout<<endl<<setfill('_')<<setw(28)<<"\n";
     cout<<"| Name of Largest File:   /\n";
     cout<<setfill('`')<<setw(27)<<"\n";
            obj.display(a);
          cout<<setfill('_')<<setw(80)<<"\n";
  getch();
  return 0;
}
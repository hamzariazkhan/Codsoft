#include<iostream>
using namespace std;
class numguessing {
    public:
    int a;
    char c;
        void instructions(){
            cout<<"WELCOME TO THE NUMBER GUESSING GAME.\n1) THERE IS A NUMBER BETWEEN 1 TO 10 USER HAS TO GUESS THIS NUMBER.\n2) THE GAME WILL CONTINUE UNTIL YOU GUESS THE RIGHT NUMBER.\n3) IT WILL GUIDE YOU THAT YOUR GUESSING NUMBER IS HIGH OR LOW.";
        }
        void process(){
             int rannum=1+(rand()%10);
            do{
            cout<<"\n\n\nEnter Your Guessing Number : ";
            cin>>a;
            if(a<rannum){
                cout<<"Your Number is too small.";}
            else if(a>rannum){
                cout<<"Your Number is too high.";}
            else{
                cout<<"Congratulations! You Guess the correct Number.\n\n";}
            }while(a!=rannum);
            cout<<"You want to play again? Y/N : ";
            cin>>c;
            if(c=='Y' ||c=='y'){
                process();
            }
            else if(c=='N' || c=='n'){
                cout<<"The Game is Finished\n Thank You!.";
            }
            else{
                cout<<"You enter the wrong option!";
            }
        }
};
int main(){
    numguessing numguess;
    numguess.instructions();
    numguess.process();
}
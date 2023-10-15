#include<iostream>
using namespace std;
template <class t>
class calculator{
    private:
        t firstnum,secondnum;
        t addresult,subresult,mulresult,divresult;
    public:
        void getdata(){
            cout<<"Enter your First number : ";
            cin>>firstnum;
            cout<<"Enter your Second number : ";
            cin>>secondnum;
        }
        void addition(){
            addresult=firstnum+secondnum;
            cout<<"Your result of Addition is : "<< addresult;}
        void subtraction(){
            subresult=firstnum-secondnum;
            cout<<"Your result of Subtraction is : " <<subresult;
        }
        void multiplication(){
            mulresult=firstnum*secondnum;
            cout<<"Your result of Multiplication is : " <<mulresult;
        }
        void division(){
            divresult=firstnum/secondnum;
            cout<<"Your result of Division is : "<< divresult;
        }
};
int main(){
    int a=0;
    cout<<"1) For Addition press '1'\n2) For Subtraction press '2'\n3) For Multiplication press '3'\n4) For Division press '4'\nEnter your choice to perform basic operations : \n";
    cin>>a;
    calculator<float> c1;
    if(a==1){
        c1.getdata();
        c1.addition();
    }
    else if(a==2){
        c1.getdata();
        c1.subtraction();
    }
    else if(a==3){
        c1.getdata();
        c1.multiplication();
    }
    else if(a==4){
        c1.getdata();
        c1.division();}
    else{
        cout<<"You have enter wrong choices";
    }

}
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct todolist{
    int id;
    string task;
};

int ID;
void banner(){
    cout<<"\t_________________________________________________"<<endl<<endl;
    cout<<"\t              MY TODO LIST "<<endl;
    cout<<"\t_________________________________________________"<<endl;
};
void addtask(){
    system("cls");
    banner();
    todolist todo;
    cout<<"ENTER TODO TASK "<<endl;
    cin.get();
    getline(cin,todo.task);
    char save;
    cout<<"\tDO YOU WANT TO SAVE THIS TASK? (Y/N) : ";
    cin>>save;
    if (save=='Y'|| save=='y' ){
        ID++;
        ofstream fout;
        fout.open("Todo.txt",ios :: app);
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;
        fout.close();
        char more;
        cout<<"\tDO YOU WANT TO ADD MORE TASK? (Y/N) : ";
        cin>>more;
        if (more=='Y'|| more=='y' ){
            addtask();
        }
        else{
            system("cls");
            cout<<"\tTASK ADDED SUCCESSFULLY."<<endl;
        }
        system("cls");
    }
};
void showtask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("Todo.txt");
    cout<<"TASK : "<<endl;
    while (!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.task!=""){
            cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
        }
        else{
            cout<<"\tYOUR TASK LIST IS EMPTY! "<<endl;
        }
        fin.close();
        char exit;
        cout<<"\tDO YOU WANT TO EXIT SHOW TASK MENU? (Y/N) : ";
        cin>>exit;
        if (exit!='Y'|| exit!='y' ){
            showtask();
        }
        system("cls");
    }
    
};
int searchtask(){
    system("cls");
    banner();
    int id;
    cout<<"ENTER TASK ID : ";
    cin>>id;
    todolist todo;
    ifstream fin("Todo.txt");
    while(!fin.eof()){
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id==id){
            system("cls");
            cout<<"TASK : "<<endl;
            cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
            return id;
        }
    }
    system("cls");
    cout<<"\tNOT FOUND!"<<endl;
};
void deletetask(){
    system("cls");
    int id=searchtask();
    if(id!=0){
        char del;
        cout<<"\nARE YOU SURE YOU WANT TO DELETE? (Y/N) : ";
        cin>>del;
        if(del=='y' || del=='Y'){
            todolist todo;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream fin;
            fin.open("Todo.txt");
            int index=1;
            while(!fin.eof()){
                fin>>todo.id;
                fin.ignore();
                getline(fin,todo.task);
                if(todo.id!=id){
                    tempfile<<"\n"<<index;
                    tempfile<<"\n"<<todo.task;
                    index++;
                    ID--;

                }
            }
            fin.close();
            tempfile.close();
            remove("Todo.txt");
            rename("temp.txt","Todo.txt");
            system("cls");
            cout<<"\nDELETE SUCCESSFULLY!"<<endl;
        }
        else{
            system("cls");
            cout<<"\tNOT DELETED!"<<endl;
        }
    }
};

int main(){
    system("cls");
    while(true){
        banner();
        cout<<"\n\t1) ADD TASK";
        cout<<"\n\t2) SHOW TASK";
        cout<<"\n\t3) SEARCH TASK";
        cout<<"\n\t4) DELETE TASK";
        int choice;
        cout<<"\n\tENTER YOUR CHOICE : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addtask();
            break;
        case 2:
            showtask();
            break;
        case 3:
            searchtask();
            break;
        case 4:
            deletetask();
            break;
        default:
            break;
        }
    }
}
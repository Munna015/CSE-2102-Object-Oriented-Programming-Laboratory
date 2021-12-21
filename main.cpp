#include<bits/stdc++.h>
using namespace std;
template<class T>
class Road_Information
{
public:
    T sr,ar,dr;
public:
    Road_Information(T a,T b,T c)
    {
        sr=a;
        ar=b;
        dr=c;
    }
    virtual void show()
    {
        ;
    }


};
class Identity
{
protected:
    string username,password;
public:
    Identity(string a,string b)
    {
        username=a;
        password=b;

    }
    bool operator==(Identity I2)
    {
        if(username==I2.username && password==I2.password)
        {
            return true;
        }
        return false;
    }
};
template<class T>
class Personal_Information:public Road_Information<int>
{


public:
    Personal_Information(T a,T b,T c):Road_Information(a,b,c)
    {
        ;
    }
    void file_write()
    {
        system("cls");
        cout << "\t\t\t\tRoadcode||Username||Password "<<endl;
        cout<<  "\t\t\t\t-----------------------------"<<endl;
        cout<<"\t\t\t\t";

        ofstream fout;
        fout.open("officer.csv",fstream::out);
        for(int i=0; i<sr+dr+ar; i++)
        {
            string roadcode,p,q;
            cin>>roadcode;
            cin>>p;
            cin>>q;
            fout<<roadcode<<","
                <<p<<","
                <<q
                <<"\n";
            cout<<"\t\t\t\t";


        }
        fout.close();
        //cout<<endl;
        //cout<<"\t\t\t\t";
    }
};
class Update_Information
{

public:

    void update()
    {
        system("cls");
A:
        cout<<"\t\t\t\tWhat do you want:\n\t\t\t\t1.Add Officer \n\t\t\t\t2.Remove Officer"<<endl;
        cout<<"\t\t\t\t";
        int y;
        cin>>y;
        if(y==1)
        {
            system("cls");
            ofstream fout("officer.csv",fstream::app);
            cout << "\t\t\t\tRoadcode||Username||Password "<<endl;
            cout<<  "\t\t\t\t-----------------------------"<<endl;
            cout<<"\t\t\t\t";
            string roadcode,username,password;
            cin>>roadcode>>username>>password;
            fout<<roadcode<<","
                <<username<<","
                <<password
                <<"\n";
            fout.close();
            system("cls");
        }
        else if(y==2)
        {
            system("cls");
E:
            int t=0;
            string roadcode,username,password,a,b,c;
            ifstream fin;
            ofstream fout;
            fin.open("officer.csv",fstream::in);
            fout.open("temp.csv",fstream::out);
            string line,word;
            cout << "\t\t\t\tRoadcode||Username||Password "<<endl;
            cout<<  "\t\t\t\t-----------------------------"<<endl;
            cout<<"\t\t\t\t";
            cin>>roadcode>>username>>password;

            while(getline(fin,line))
            {
                stringstream s(line);
                getline(s,a,',');
                getline(s,b,',');
                getline(s,c,',');
                if(a!=roadcode && b!=username && c!=password)
                {
                    fout<<a<<","
                        <<b<<","
                        <<c
                        <<"\n";
                }
                else
                    t++;

            }
            if(t==0)
            {
                system("cls");
                cout<<"\t\t\t\tDon't match the information what you want to delete"<<endl;
                goto E;
            }



            fin.close();
            fout.close();
            remove("officer.csv");
            rename("temp.csv", "officer.csv");
            system("cls");
        }

        else
        {
            cout<<"\t\t\t\tPlease select the option carefully"<<endl;
            goto A;
        }
    }


};
template<class T>
class Result:public Personal_Information<int>,public Update_Information
{
public:
    T s,asr,sar,dhr;
    Result(T a,T b,T c,T d,T e,T f):Personal_Information(d,e,f)
    {
        asr=a;
        sar=b;
        dhr=c;
    }

    void data_entry()
    {
        system("cls");
        getchar();
        int x;
B:
        ifstream fin;
        fin.open("input.csv",fstream::in);
        string a,b,c,d;
        cout<<"\t\t\t\tPlease enter your Username:";
        getline(cin,a);
        cout<<"\t\t\t\tPlease enter your password:";
        getline(cin,b);
        vector<string>v;
        string line,word,temp;
        while( getline(fin,line))
        {

            stringstream s(line);
            while(getline(s,word,','))
            {
                v.push_back(word);
            }
        }
        c=v[0];
        d=v[1];
        Identity I1(a,b),I2(c,d);

        if(I1==I2)
        {

A:
            system("cls");
            cout<<"\t\t\t\tWhat do you want:\n\t\t\t\t1.Primary Bus entry\n\t\t\t\t2.Update\n\t\t\t\t3.Exit"<<endl;
            cout<<"\t\t\t\t";
            cin>>x;
            if(x==1)
            {

                file_write();
                system("cls");
//                 cout<<endl;
//                  cout<<"\t\t\t\t";
            }
            else if(x==2)
            {
                update();
            }
            else if(x==3)
            {
                exit(0);
            }
            else
            {
                system("cls");
                cout<<"\t\t\t\tPlease select the option carefully"<<endl;
                goto A;
            }

        }
        else
        {
            system("cls");
            cout<<"\t\t\t\tUser name and password don't match"<<endl;
            goto B;
        }

    }
    void show();

};
template<typename T>
void Result<T>::show()
{

    //system("cls");
    int x;
    int t=0;
A:
    cout<<"\t\t\t\tRoadcode: \n\t\t\t\t1.Savar \n\t\t\t\t2.Asulia \n\t\t\t\t3.Dhamrai:";
    cin>>x;
    getchar();

    if(x==1)
    {
        //system("cls");
        string e,line,f;
        cout<<"\t\t\t\tEnter your Username:";
        getline(cin,e);
        cout<<"\t\t\t\tEnter Your Password:";
        getline(cin,f);
        string a,b,c,word;
        vector<string>v;
        ifstream fin;
        fin.open("officer.csv",fstream::in);
        while(getline(fin,line))
        {
            v.clear();
            stringstream sin(line);
            while(getline(sin,word,','))
            {
                v.push_back(word);
            }
            a=v[0];
            b=v[1];
            c=v[2];
            Identity I1(e,f),I2(b,c);
            if(I1==I2 && a=="s")
            {
                t++;
            }
        }
        if(t!=0)
        {
            if(sar!=0)
            {
                system("cls");
                cout<<"\t\t\t\tWellcome,Please enter the bus"<<endl;
                sar--;
                //system("cls");
            }
            else
            {
                system("cls");
                cout<<"\t\t\t\tPlease Wait for the next bus,Thank you"<<endl;
                //system("cls");
            }
        }

        else
        {
            system("cls");
            cout<<"\t\t\t\tSorry Username and password don't match"<<endl;
            //system("cls");
            goto A;
        }

        fin.close();

    }
    else if(x==2)
    {

        system("cls");
        string e,f,line;
        cout<<"\t\t\t\tEnter your Username:";
        getline(cin,e);
        cout<<"\t\t\t\tEnter Your Password:";
        getline(cin,f);
        string a,b,c,word;
        ifstream fin;
        vector<string>v;
        fin.open("officer.csv",fstream::in);
        while(getline(fin,line))
        {
            v.clear();
            stringstream sin(line);
            while(getline(sin,word,','))
            {
                v.push_back(word);
            }
            a=v[0];
            b=v[1];
            c=v[2];
            Identity I1(e,f),I2(b,c);
            if(I1==I2 && a=="a")
            {
                t++;
            }
        }
        if(t!=0)
        {
            if(asr!=0)
            {
                system("cls");
                cout<<"\t\t\t\tWellcome,Please enter the bus"<<endl;
                asr--;
                //system("cls");
            }
            else
            {
                system("cls");
                cout<<"\t\t\t\tPlease Wait for the nest bus,Thank you"<<endl;
                //system("cls");
            }
        }

        else
        {
            system("cls");
            cout<<"\t\t\t\tSorry Username and password don't match"<<endl;
            //system("cls");
            goto A;
        }

        fin.close();

    }
    else if(x==3)
    {

        system("cls");
        string e,f,line;
        cout<<"\t\t\t\tEnter your Username:";
        getline(cin,e);
        cout<<"\t\t\t\tEnter Your Password:";
        getline(cin,f);
        string a,b,c,word;
        ifstream fin;
        vector<string>v;
        fin.open("officer.csv",fstream::in);
        while(getline(fin,line))
        {
            v.clear();
            stringstream sin(line);
            while(getline(sin,word,','))
            {
                v.push_back(word);
            }
            a=v[0];
            b=v[1];
            c=v[2];
            Identity I1(e,f),I2(b,c);
            if(I1==I2 &&  a=="d")
            {
                t++;
            }
        }
        if(t!=0)
        {
            if(dhr!=0)
            {
                system("cls");
                cout<<"\t\t\t\tWellcome,Please enter the bus"<<endl;
                dhr--;
                //system("cls");
            }
            else
            {
                system("cls");
                cout<<"\t\t\t\tPlease Wait for the next bus,Thank you"<<endl;
                //system("cls");
            }
        }

        else
        {
            system("cls");
            cout<<"\t\t\t\tSorry Username and password don't match"<<endl;
            //system("cls");
            goto A;
        }


        fin.close();

    }
    else
    {
        system("cls");
        cout<<"Please select the option carefully"<<endl;
        goto A;
    }




}

int main ()
{
    int x;
    Result <int>r(3,3,3,3,3,3);
    Road_Information <int>*bptr;

    while(1)
    {
        cout<<"*******************************MUNNA GROUP OF INDUSTRIES**************************************************"<<endl;
        cout<<"\t\t\t\tNabinagar,Savar,Dhaka"<<endl;;
        cout<<"\t\t\t  E-mail:munna1707015@gmail.com"<<endl;
        cout<<"\t\t\t\tWhat do yo want:"<<endl;
        cout<<"\t\t\t\t1.ADMIN"<<endl;
        cout<<"\t\t\t\t2.LOG IN"<<endl;
        cout<<"\t\t\t\t";
        cin>>x;
        if(x==1)
            r.data_entry();
        else if(x==2)
        {
            bptr=&r;
            bptr->show();

        }
        else
        {
            system("cls");
            cout<<"\t\t\t\tPlease select the option carefully"<<endl;

        }
    }
    return 0;
}

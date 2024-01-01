#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cstring>
#include<cstdlib>
using namespace std;
class alogin{
    string admin;

public:
    int loginPortal()
    {

        cout <<"ENTER ADMIN ID"<< endl;
        cin >> admin;
        if (admin == "123456")
        {

            int p = login_pwd();
            if (p == 1)
            {
                cout <<"SUCCESSFULLY LOGINED" << endl;
                return 1;
            }
        }
        else
        {
            cout <<"USER NAME NOT FOUND"<< endl;
            loginPortal();
            cout <<"LOGIN FAILED"<< endl;
            return 0;
        }
    }
    int login_pwd();
};

int alogin::login_pwd()
{
    string pw;
    cout << "ENTER PASWORD" << endl;
    cin >> pw;
    if (pw == "123456")
    {
        cout << "----WELCOME!!------" << endl;
        return 1;
    }
    else
    {
        cout << "INCORRECT PASWORD" << endl;
        login_pwd();
        return 0;
    }
}
void diamond_class(int gc, int sc)
{
    if (gc != 0)
    {
        cout << gc << endl;
        cout<<"TRAINER  ALLOTED\n"<<endl;
        cout<<"TRAINER NAME: RAVI"<<endl;
    }
    else
    {
        cout << "NO TRAINER AVAILABLE\n";
    }
}

void gold_class(int gc, int sc)
{
    if (sc != 0)
    {
        cout << sc << endl;

        cout<<"TRAINER ALLOTED\n"<<endl;
		cout<<"TRAINER NAME:RAMU"<<endl;
    }
    else
    {
        cout << "NO TRAINER AVAILABLE"<<endl;
        if (gc != 0)
        {
            cout<<"ENTER ANOTHER CLASS\n"<<endl;
            diamond_class(gc, sc);
        }
    }
}
int trainer_class(char *c)
{
    char class_type[10];
    int i, g_class = 3, s_class = 5;
    strcpy(class_type, c);

    if ((g_class != 0) || (s_class) != 0)
    {

        if (strcmp(class_type, "DIAMOND") == 0)
        {
            g_class--;
            diamond_class(g_class, s_class);
        }
        else if (strcmp(class_type, "GOLD") == 0)
        {
            s_class--;
            gold_class(g_class, s_class);
        }
    }
    else
    {
        cout<<"TRAINERS NOT AVAILABLE\n";
        return 1;
    }
}
class member
{
    int member_number, j;
    char mem_name[50], classs[50], timings[50];
    float fee;

    long int contact;

public:
    int time_slots()
    {
        int k;
        cout<<"PLEASE SELECT YOUR GYM TIMINGS\n"<<endl;
			cout<<"PRESS 1 for: MORNING 6-7"<<endl;
			cout<<"PRESS 2 for: MORNING 7-8"<<endl;
			cout<<"PRESS 3 for: MORNING 8-9"<<endl;
			cout<<"PRESS 4 for: EVENING 6-7"<<endl;
			cout<<"PRESS 5 for: EVENING 7-8"<<endl;
			cout<<"PRESS 6 for: EVENING 8-9"<<endl;
        cin >> k;
        switch (k)
        {
        case 1:
            strcpy(timings, "6AM-7AM");
            break;
        case 2:
            strcpy(timings, "7AM-8AM");
            break;
        case 3:
            strcpy(timings, "8AM-9AM");
            break;
        case 4:
            strcpy(timings, "4PM-5PM");
            break;
        case 5:
            strcpy(timings, "5PM-6PM");
            break;
        case 6:
            strcpy(timings, "6PM-7PM");
            break;
        }
    }
    void login_mem()
    {
       int k,l,j;
    		cout<<endl<<"ENTER USER ID:";
    		cin>>member_number;
    		cout<<endl<<"ENTER NAME OF USER:";
    		getchar();
    		cin.getline(mem_name ,50);
    		cout<<endl<<"ENTER THE PHONE NUMBER:";
    		cin>>contact;
    		cout<<"1)DIAMOND MEMBER"<<endl;
			cout<<"2)GOLD MEMBER"<<endl;
		cout<<"enter the choice\n";
		cin>>k;
        switch (k)
        {
        case 1:
        {
            strcpy(classs,"DIAMOND");
            fee = 2500;
            cout <<"YOUR MONTHLY FEES WOULD BE:" << fee << endl;
            l = trainer_class(classs);
        }
        break;
        case 2:
        {
            strcpy(classs,"GOLD");
            fee = 2000;
            cout <<"YOUR MONTHLY FEES WOULD BE:" << fee << endl;
            l = trainer_class(classs);
        }
        break;
        }
        time_slots();
    }

    void display_mem(){
        cout<< "MEMBER ID:"<< member_number<<endl;
        cout<< "USER NAME:" << mem_name<<endl;
        cout<< "CATEOGIRI:" << classs<<endl;
        cout<< "FEES:"<<fee<<endl;
        cout<< "PHONE NUMBER:" << contact<<endl;
        cout<< "SLOTS:"<< timings << endl;
    }
    int getmem()
    {
        return member_number;
    }

    float getfee()
    {
        return fee;
    }

    char *getName()
    {
        return mem_name;
    }

    float getcontact()
    {
        return contact;
    }
};

fstream fp;
member m1;

void save_member()
{
    fp.open("newdata2.dat", ios::out | ios::app);
    m1.login_mem();
    fp.write((char *)&m1, sizeof(m1));
    fp.close();
    cout<< "USER SUCCESSFULLY ADDED"<<endl;
    getchar();
}

void show_all()
{
    cout<<"\t\tRECORDS...";
    fp.open("newdata2.dat", ios::in);
    while (fp.read((char *)&m1, sizeof(m1)))
    {
        m1.display_mem();
        getchar();
    }
    fp.close();
}

void display_record(int num)
{
    bool found = false;
    fp.open("newdata2.dat", ios::in);
    while (fp.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getmem() == num)
        {
            m1.display_mem();
            found = true;
        }
    }

    fp.close();
    if (found == true)
        cout<<"NO RECORD FOUND"<<endl;
    getchar();
}

void edit_member()
{
    int num;
    bool found = false;
    cout<<"ENTER USER ID"<<endl;
    cin >> num;

    fp.open("newdata2.dat", ios::in | ios::out);
    while (fp.read((char *)&m1, sizeof(m1)) && found == false)
    {
        if (m1.getmem() == num)
        {
            m1.display_mem();
            cout <<"ENTER USER DETAILS"<< endl;
            m1.login_mem();
            int pos = 1 * sizeof(m1);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&m1, sizeof(m1));
            cout << endl
                 << endl
                 << "\t Record Successfully Updated...";
            found = true;
        }
    }
    fp.close();
    if (found == false)
        cout<<"RECORD UNFOUND"<<endl;
    getchar();
}
void delete_member(){
    int num;
    cout<<"ENTER THE MEMBER ID"<<endl;
    cin >> num;
    fp.open("newdata2.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp2.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&m1, sizeof(m1)))
    {
        if (m1.getmem() != num)
        {
            fp2.write((char *)&m1, sizeof(m1));
        }
    }
    fp2.close();
    fp.close();
    remove("newdata2.dat");
    rename("Temp2.dat", "newdata2.dat");
    cout<<"\tRECORD DELETED SUCCESSFULLY"<<endl;
    getchar();
}
void manage_function()
{
    for (;;)
    {
        int option;
        cout<<"**********************************************"<<endl;
		cout<<"----------WELCOME TO SRM GYM:----------"<<endl;
		cout<<"***********************************************"<<endl;
    	cout<<"\n\tPress 1 to CREATE NEW USER";
    	cout<<"\n\tPress 2 to DISPLAY ALL RECORDS OF USER";
    	cout<<"\n\tPress 3 to SEARCH PARTICULAR RECORD ";
    	cout<<"\n\tPress 4 to EDIT USER DETAILS";
    	cout<<"\n\tPress 5 to DELETE USER DETAILS";
    	cout<<"\n\tPress 6 to  BACK TO MAIN MENU";
    	cout<<"\n\n\tOption: ";
        cin>>option;
        switch (option)
        {
        case 1:
            save_member();
            break;

        case 2:
            show_all();
            break;

        case 3:
            int num;
            cout << "\n\n\tPlease Enter The member Number: ";
            cin >> num;
            display_record(num);
            break;

        case 4:
            edit_member();
            break;

        case 5:
            delete_member();
            break;

       
        default:
            manage_function();
        }
    }
}
void f_User()
{
    for (;;)
    {
        int m;
        cout<<"1)JOIN GYM"<<endl;
        cout<<"2)QUIT GYM"<<endl;
        cout<<"3)edit your profile"<<endl;
        cout<<"4)DISPLAY RECORDS"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
        cin>>m;
        switch(m){
        case 1:
            save_member();
            break;
        case 2:
            delete_member();
            break;
        case 3:
            edit_member();
            break;
        case 4:
            manage_function();
            break;
        }
    }
}
int main()
{

    int i, k;
    string name, code;
    cout<<"SELECT MODE" << endl;
    cout<<"1)USER LOGIN"<< endl;
    cout<<"2)ADMIN LOGIN"<< endl;
    cin >> i;

    if (i == 1)
    {
        cout << "YOU ARE IN USER MODE" << endl;
        f_User();
    }
    if (i == 2)
    {
        cout << "YOU ARE IN ADMIN MODE" << endl;

        alogin ad;
        k = ad.loginPortal();
        if (k == 1)
        {
            manage_function();
        }
        else
        {
            cout << "YOU CANT ACCESS MANGERAL DETAILS!";
        }
    }

return 0;
}



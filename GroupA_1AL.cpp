#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const int max_store = 100;
string c_ic[max_store], c_uname[max_store], c_pwd[max_store], c_amt[max_store];

class Bank{
    fstream c_file;
    string f_name, u_name, ic, pwd, dep;
    string l_ic, l_pwd;
    string s_ic;
    int opt;
    char decision;

public:
    Bank()
    {
        string c_line;
        c_file.open("clients_list.txt", ios::in);
        if(c_file.is_open())
        {
            int i = 0;

            while(getline(c_file,c_line))
            {
                int l = c_line.length();
                c_ic[i] = c_line.substr(8, 12);
                c_pwd[i] = c_line.substr(30, 10);
                c_amt[i] = c_line.substr(50, 10);
                c_uname[i] = c_line.substr(60, l - 60);
                i++;
            }
            c_file.close();
        }
    }

    void reg_acc();
    void reg_acc_ui();
    void login();
    void login_ui();
    void view_rec();
    void view_rec_ui();
    void search_acc();
    void search_acc_ui();
    void match_acc(string m_ic, string m_pwd);
    void home_page(string h_ic, string h_pwd);
    void home_page_ui();
    void deposit(string d_i, string d_pwd);
    void deposit_ui();
    void withdraw(string wd_ic, string wd_pwd);
    void withdraw_ui();
    void check_amt(string ca_ic, string ca_pwd);
    void ch_uname(string chu_ic, string chu_pwd);
    void ch_pwd(string chp_ic, string chp_pwd);
    void dlt_acc(string dlt_ic, string dlt_pwd);
};

int main(){

    char gui1 = 2;

    Bank a;
    int option;
    system("cls");
    cout <<   "                                         _______________________________________\n";
    cout << "\n                                                BANKING MANAGEMENT SYSTEM ";
    cout << "\n                                                 Welc"<<gui1<<"me to CARE'U$ BANK"
         << "\n                                         _______________________________________\n"

         << "\n                                                [1]  Register an account \n"
         << "\n                                                [2]  Log in account \n"
         << "\n                                                [3]  View all account \n"
         << "\n                                                [4]  Search account \n"
         << "\n                                                [5]  Save and exit \n"

         << "\nPlease select an option [1|2|3|4|5]: ";
    cin >> option;

    while(option < 1 || option > 5)
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout << "Incorrect input. Please insert again: ";
        cin >> option;
    }

    switch(option)
    {
        case 1:
            a.reg_acc();
            break;

        case 2:
            a.login();
            break;

        case 3:
            a.view_rec();
            break;

        case 4:
            a.search_acc();
            break;

        case 5:
            {
            int loadui;
            double loadingtime;
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n                                                Thanks for trusting Care'U$ Bank."<<endl;
            cout<<"                                                        Exiting";
            for (loadui=0;loadui<10;loadui++)
            {
                cout<<".";
                for(loadingtime=0;loadingtime<=190000000;loadingtime++);
            }

            exit(0);

            }
    }
}

void Bank::reg_acc(){

    reg_acc_ui();
    cin.ignore();
    cout << "Please insert your IC number(12 characters): ";
    getline(cin, ic);
     for(int i = 0; i <= max_store; i++)
    {
        if(c_ic[i] == ic)
        {
            cout << "This account already exists" << endl;
            cout << "Insert y to login page, insert n to main menu page [y|n]: ";
            cin >> decision;
            while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
            {
                cin.ignore();
                cin.clear();
                cin.sync();
                cout << "Incorrect input. Please insert again: ";
                cin >> decision;
            }
            if(decision == 'y' || decision == 'Y')
            {
                login();
            }
            if(decision == 'n' || decision == 'N')
            {
                main();
            }

        }
    }
    while(ic.size() != 12)
    {
        cout << "Invalid IC Number. Please enter a valid IC number :";
        getline(cin, ic);
    }
    reg_acc_ui();


    cout << "Please insert the username you like: ";
    getline(cin, u_name);
    reg_acc_ui();


    cout << "Please insert your password (10 characters): ";
    getline(cin, pwd);
    while(pwd.size() != 10)
    {
        cout << "Invalid Password. Please insert a valid password :";
        getline(cin, pwd);

    }
    reg_acc_ui();


    cout << "Please deposit your money into your account: ";
    cin >> dep;
    while(dep.size() > 10 || dep.size() < 0)
    {
        cout << "Your deposit must within 10 digits" << endl;
        cout << "Please insert your amount: ";
        cin >> dep;
    }
    reg_acc_ui();


    for (int i = 0; i <= max_store; i++)
    {
        if (c_ic[i] == "")
        {
            c_ic[i] = ic;
            c_pwd[i] = pwd;
            c_amt[i] = dep;
            c_uname[i] = u_name;

            c_file.open("clients_list.txt", ios::app);
            if(c_file.is_open())
            {
                c_file << setw(20)
                       << c_ic[i] << setw(20)
                       << c_pwd[i] << setw(20)
                       << c_amt[i] << setw(20)
                       << c_uname[i] << setw(20)
                       << endl;
                c_file.close();
                cout << "                                 Congratulation! You have succeed in register an account!" << endl;
                cout <<"\nAccount_Report:"<<endl;
                cout <<"________________________________________________________________________________________________________________________\n\n";
                cout <<"           IC NUMBER             |          USERNAME         |          PASSWORD         |          AMOUNT(RM)           "<<endl;
                cout <<"________________________________________________________________________________________________________________________\n\n\n";
                cout
                     << setw(22)
                     << c_ic[i] << setw(30)
                     << c_uname[i] << setw(30)
                     << c_pwd[i] << setw(23)
                     << c_amt[i] << endl;
            cout <<"\n________________________________________________________________________________________________________________________\n\n";
            }
            else
            {
                cout << "Save failed" << endl;
            }
            break;
        }
    }

    cout << "Do you want to log in to your account?" << endl;
    cout << "Insert y to log in, insert n to go back main menu [y|n]: ";
    cin.ignore();
    cin.clear();
    cin >> decision;

    while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout <<"Incorrect input. Please insert again: ";
        cin >> decision;
    }

    if(decision == 'y' || decision == 'Y')
    {
        login();
    }
    if(decision == 'n' || decision == 'N')
    {
        main();
    }
}

void Bank::reg_acc_ui(){
system("cls");
    cout << "                                       ______________________________________________\n" <<endl;
    cout << "                                           A c c o u n t  R e g i s t r a t i o n " <<endl;
    cout << "                                       ______________________________________________" <<endl;
    cout << "";
    cout << "\n\n                                         [!]  IC NUMBER    : "<<ic;
    cout <<   "\n                                         [!]  USERNAME(ID) : "<<u_name;
    cout <<   "\n                                         [!]  PASSWORD     : "<<pwd;
    cout <<   "\n                                         [!]  Deposit(RM)  : "<<dep;
    cout <<"\n\n"<<endl;

}

void Bank::login(){

    cin.ignore();

    login_ui();
    cout << "Please insert your IC number :";
    cin >> l_ic;
    login_ui();
    cout << "Please insert your password :";
    cin >> l_pwd;
    login_ui();
    match_acc(l_ic, l_pwd);

}

void Bank::login_ui(){
    system("cls");
    cout << "                                       ______________________________________________\n" <<endl;
    cout << "                                                         L o g  i n                  " <<endl;
    cout << "                                       ______________________________________________" <<endl;
    cout << "";
    cout << "\n\n                                          [!]  IC NUMBER    : "<<l_ic;
    cout <<   "\n                                          [!]  PASSWORD     : "<<l_pwd;
    cout <<"\n\n"<<endl;
}

void Bank::match_acc(string m_ic, string m_pwd){

    int check = 0;

    for (int i = 0; i <= max_store; i++)
    {
        if ((c_ic[i] == m_ic) && (c_pwd[i] == m_pwd))
        {
            check++;
            cout << "                                        Login successfully. Welcome back dear user"<< endl;
            cout << "                                                     Loading";
            int loadui;
            double loadingtime;
            for (loadui=0;loadui<10;loadui++)
            {
                cout<<".";
                for(loadingtime=0;loadingtime<=150000000;loadingtime++);
            }

            home_page(m_ic, m_pwd);
            break;
        }
    }

    if (check == 0)
    {
        cout << "The account is not exist. Please check your insertion of input." << endl;
        cout << "Insert y to try again, insert n to go back to main menu: ";
        cin >> decision;

        while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
        {
            cin.ignore();
            cin.clear();
            cin.sync();
            cout << "Incorrect input. Please insert again: ";
            cin >> decision;
        }

        if(decision == 'y' || decision == 'Y')
        {
            login();
        }
        if(decision == 'n' || decision == 'N')
        {
            main();
        }
    }
}

void Bank::home_page(string h_ic, string h_pwd){

    cin.ignore();
    system("cls");
    cout <<"UserIC: "<<h_ic<<endl;
    home_page_ui();
    cin >> opt;

    while(opt < 1 || opt > 7)
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout << "Incorrect input. Please insert again: ";
        cin >> opt;
    }

    switch (opt){

        case 1:
            check_amt(h_ic, h_pwd);
            break;

        case 2:
            ch_uname(h_ic, h_pwd);
            break;

        case 3:
            ch_pwd(h_ic, h_pwd);
            break;

        case 4:
            dlt_acc(h_ic, h_pwd);
            break;

        case 5:
            deposit(h_ic, h_pwd);
            break;

        case 6:
            withdraw(h_ic, h_pwd);
            break;

        case 7:
            main();
            break;
    }
}

void Bank::home_page_ui(){
    cout <<   "                                         _______________________________________\n";
    cout << "\n                                                         H o m e  "
         << "\n                                         _______________________________________\n"

         << "\n                                                 [1]  Check Amount \n"
         << "\n                                                 [2]  Change Username \n"
         << "\n                                                 [3]  Change Password \n"
         << "\n                                                 [4]  Delete Account \n"
         << "\n                                                 [5]  Deposit \n"
         << "\n                                                 [6]  Withdraw \n"
         << "\n                                                 [7]  Save and Log out \n"

         << "\nPlease select an option [1|2|3|4|5|6|7]: ";
}

void Bank::deposit(string d_ic, string d_pwd){

    fstream temp_file;
    float dep_amt = 0, fdep_amt = 0;

    cin.ignore();
    for(int i = 0; i <= max_store; i++)
    {
        if(c_ic[i] == d_ic)
        {
            system("cls");
            cout << "                                       ______________________________________________\n" <<endl;
            cout << "                                                    $$  D e p o s i t  $$ "   <<endl;
            cout << "                                       ______________________________________________" <<endl;

            cout <<"\n\n\n                                    Current balance(RM):"<<c_amt[i]<<endl;

            fdep_amt = stof(c_amt[i]);
            cout << "\n\n\nPlease insert the amount you would like to deposit: ";
            cin >> dep_amt;
            while(dep_amt < 0)
            {
                cout << "Invalid amount. Please insert again: ";
                cin >> dep_amt;
            }
            fdep_amt = fdep_amt + dep_amt;
            ostringstream sdep_amt;
            sdep_amt << fdep_amt;
            c_amt[i] = sdep_amt.str();

            system("cls");
            cout<<"\n\n\n\n\n\n                                        Your transaction is updating";
            int loadui;
            int loadingtime;
            for (loadui=0;loadui<4;loadui++)
            {
              cout<<".";
              for(loadingtime=0;loadingtime<=1900000000;loadingtime++);
            }

            system("cls");
            cout << "                                       ______________________________________________\n" <<endl;
            cout << "                                                    $$  D e p o s i t  $$ "   <<endl;
            cout << "                                       ______________________________________________" <<endl;

            cout <<"\n\n\n                                    Current balance(RM):"<<c_amt[i]<<endl;
            cout << "\n\n\nYour current amount is RM " << c_amt[i] << endl;
            break;
        }
    }
    for(int j = 0; j <= max_store; j++)
    {
        if(c_ic[j] != "")
        {
            temp_file.open("temp_list.txt", ios::app);
            if(temp_file.is_open())
            {
                temp_file << setw(20)
                          << c_ic[j] << setw(20)
                          << c_pwd[j] << setw(20)
                          << c_amt[j] << setw(20)
                          << c_uname[j] << setw(20)
                          << endl;
                temp_file.close();
            }
            else
            {
                cout << "saved failed" << endl;
            }
        }
        if(c_ic[j] == "")
        {
            break;
        }
    }
    remove("clients_list.txt");
    rename("temp_list.txt", "clients_list.txt");
    cout << "Do you want to deposit again?" << endl;
    cout << "Insert y to deposit, insert n to go back to home page [y|n]: ";
    cin >> decision;

    while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout << "Incorrect input. Please insert again: ";
        cin >> decision;
    }

    if(decision == 'y' || decision == 'Y')
    {
        deposit(d_ic, d_pwd);
    }
    if(decision == 'n' || decision == 'N')
    {
        home_page(d_ic, d_pwd);
    }
}

void Bank::withdraw(string wd_ic, string wd_pwd){

    fstream temp_file;
    float wd_amt = 0, fwd_amt = 0;

    cin.ignore();
    for(int i = 0; i <= max_store; i++)
    {
        if(c_ic[i] == wd_ic)
        {
            system("cls");
            cout << "                                       ______________________________________________\n" <<endl;
            cout << "                                                    $$  W i t h d r a w  $$ "   <<endl;
            cout << "                                       ______________________________________________" <<endl;

            cout <<"\n\n\n                                    Current balance(RM):"<<c_amt[i]<<endl;

            fwd_amt = stof(c_amt[i]);
            cout << "\n\n\nPlease insert the amount you would like to withdraw: ";
            cin >> wd_amt;
            while(fwd_amt < wd_amt || wd_amt < 0)
            {
                cout << "Invalid amount. Please insert again: ";
                cin >> wd_amt;
            }
            fwd_amt = fwd_amt - wd_amt;
            ostringstream swd_amt;
            swd_amt << fwd_amt;
            c_amt[i] = swd_amt.str();

            system("cls");
            cout<<"\n\n\n\n\n\n                                        Your transaction is updating";
            int loadui;
            int loadingtime;
            for (loadui=0;loadui<4;loadui++)
            {
              cout<<".";
              for(loadingtime=0;loadingtime<=1900000000;loadingtime++);
            }

            system("cls");
            cout << "                                       ______________________________________________\n" <<endl;
            cout << "                                                    $$  W i t h d r a w  $$ "   <<endl;
            cout << "                                       ______________________________________________" <<endl;

            cout <<"\n\n\n                                        Current balance:"<<c_amt[i]<<endl;
            cout << "\n\n\nYour current amount is RM " << c_amt[i] << endl;
            break;
        }
    }
    for(int j = 0; j <= max_store; j++)
    {
        if(c_ic[j] != "")
        {
            temp_file.open("temp_list.txt", ios::app);
            if(temp_file.is_open())
            {
                temp_file << setw(20)
                          << c_ic[j] << setw(20)
                          << c_pwd[j] << setw(20)
                          << c_amt[j] << setw(20)
                          << c_uname[j] << setw(20)
                          << endl;
                temp_file.close();
            }
            else
            {
                cout << "saved failed" << endl;
            }
        }
        if(c_ic[j] == "")
        {
            break;
        }

    }
    remove("clients_list.txt");
    rename("temp_list.txt", "clients_list.txt");
    cout << "Do you want to withdraw again?" << endl;
    cout << "Insert y to withdraw, insert n to go back to home page [y|n]: ";
    cin >> decision;

    while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout << "Incorrect input. Please insert again: ";
        cin >> decision;
    }

    if(decision == 'y' || decision == 'Y')
    {
        withdraw(wd_ic, wd_pwd);
    }
    if(decision == 'n' || decision == 'N')
    {
        home_page(wd_ic, wd_pwd);
    }
}

void Bank::check_amt(string ca_ic, string ca_pwd){

    cin.ignore();
    for(int i = 0; i <= max_store; i++)
    {
        if(c_ic[i] == ca_ic)
        {
            system("cls");
            cout <<"\n                                                Account_Balance_Report"<<endl;
            cout <<"________________________________________________________________________________________________________________________\n\n";
            cout <<"           IC NUMBER               |             AMOUNT(RM)           "<<endl;
            cout <<"________________________________________________________________________________________________________________________\n\n\n";
            cout << setw(22)
                 << c_ic[i] << setw(35)
                 << c_amt[i] <<endl;
            cout <<"\n________________________________________________________________________________________________________________________\n\n";

            break;
        }
    }
    cout << "\nInsert y to go back to home page, insert n to go back to main menu [y|n]: ";
    cin >> decision;

    while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout << "Incorrect input. Please insert again: ";
        cin >> decision;
    }

    if(decision == 'y' || decision == 'Y')
    {
        home_page(ca_ic, ca_pwd);
    }
    if(decision == 'n' || decision == 'N')
    {
        main();
    }
}

void Bank::ch_uname(string chu_ic, string chu_pwd){

    cin.ignore();
    fstream temp_file;
    string u_name;

    for(int i = 0; i <= max_store; i++)
    {
        if(c_ic[i] == chu_ic)
        {
            system("cls");
            cout << "                                       ______________________________________________\n" <<endl;
            cout << "                                              C h a n g e  U s e r n a m e "   <<endl;
            cout << "                                       ______________________________________________" <<endl;

            cout <<"\n                                       Current username:"<<c_uname[i]<<endl;
            cout <<"\n                                           New username:"<<endl;

            cout << "\n\n\n\nPlease insert your new username: ";
            getline(cin,u_name);
            c_uname[i] = u_name;
            break;
        }
    }
    for(int j = 0; j <= max_store; j++)
    {
        if(c_ic[j] != "")
        {
            temp_file.open("temp_list.txt", ios::app);
            if(temp_file.is_open())
            {
                temp_file << setw(20)
                          << c_ic[j] << setw(20)
                          << c_pwd[j] << setw(20)
                          << c_amt[j] << setw(20)
                          << c_uname[j] << setw(20)
                          << endl;
                temp_file.close();
            }
            else
            {
                cout << "saved failed" << endl;
            }
        }
        if(c_ic[j] == "")
        {
            break;
        }

    }
    remove("clients_list.txt");
    rename("temp_list.txt", "clients_list.txt");
    cout << "Username successfully updated."<<endl;
    cout << "Do you want to change the username again?" << endl;
    cout << "Insert y to change the username, insert n to go back to home page [y|n]: ";
    cin >> decision;

    while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout << "Incorrect input. Please insert again: ";
        cin >> decision;
    }

    if(decision == 'y' || decision == 'Y')
    {
        ch_uname(chu_ic, chu_pwd);
    }
    if(decision == 'n' || decision == 'N')
    {
        home_page(chu_ic, chu_pwd);
    }

}

void Bank::ch_pwd(string chp_ic, string chp_pwd){

    cin.ignore();
    fstream temp_file;
    string u_pwd;

    for(int i = 0; i <= max_store; i++)
    {
        if(c_ic[i] == chp_ic)
        {
            system("cls");
            cout << "                                       ______________________________________________\n" <<endl;
            cout << "                                              C h a n g e  P a s s w o r d "   <<endl;
            cout << "                                       ______________________________________________" <<endl;

            cout <<"\n                                       Current password:"<<c_pwd[i]<<endl;
            cout <<"\n                                           New password:"<<endl;

            cout << "\n\n\n\nPlease insert your new password: ";
            getline(cin, u_pwd);
            while(u_pwd.size() != 10)
            {
            cout << "Invalid Password. Please insert a valid password :";
            getline(cin, u_pwd);
            }
            c_pwd[i] = u_pwd;
            break;
        }
    }
    for(int j = 0; j <= max_store; j++)
    {
        if(c_ic[j] != "")
        {
            temp_file.open("temp_list.txt", ios::app);
            if(temp_file.is_open())
            {
                temp_file << setw(20)
                          << c_ic[j] << setw(20)
                          << c_pwd[j] << setw(20)
                          << c_amt[j] << setw(20)
                          << c_uname[j] << setw(20)
                          << endl;
                temp_file.close();
            }
            else
            {
                cout << "saved failed" << endl;
            }
        }
        if(c_ic[j] == "")
        {
            break;
        }

    }
    remove("clients_list.txt");
    rename("temp_list.txt", "clients_list.txt");
    cout << "Password successfully updated."<<endl;
    cout << "Do you want to change the password again?" << endl;
    cout << "Insert y to change the password, insert n to go back to home page [y|n]: ";
    cin >> decision;

    while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
    {
        cin.ignore();
        cin.clear();
        cin.sync();
        cout << "Incorrect input. Please insert again: ";
        cin >> decision;
    }

    if(decision == 'y' || decision == 'Y')
    {
        ch_pwd(chp_ic, chp_pwd);
    }
    if(decision == 'n' || decision == 'N')
    {
        home_page(chp_ic, chp_pwd);
    }
}

void Bank::dlt_acc(string dlt_ic, string dlt_pwd){

    cin.ignore();
    fstream temp_file;
    char delopt;

    system("cls");
            cout << "                                       ______________________________________________\n" <<endl;
            cout << "                                                        W a r n i n g ! "   <<endl;
            cout << "                                       ______________________________________________" <<endl;
            cout << "\n\n\nAre you sure you want to delete your account ?"<<endl;
            cout << "Insert y to delete account, insert n to go back to home page [y|n]: ";
            cin >> delopt;
            while((delopt != 'y' && delopt != 'Y') && (delopt != 'n' && delopt != 'N'))
            {
                cin.ignore();
                cin.clear();
                cin.sync();
                cout << "Incorrect input. Please insert again: ";
                cin >> delopt;
            }
            if(delopt == 'y' || delopt == 'Y')
            {
                 for(int i = 0; i <= max_store; i++)
                {
                    if(c_ic[i] == dlt_ic)
                    {
                        for(int j = 0; j <= max_store; j++)
                        {
                            if(c_ic[j] != c_ic[i])
                            {
                                temp_file.open("temp_list.txt", ios::app);
                                if(temp_file.is_open())
                                {
                                    temp_file << setw(20)
                                              << c_ic[j] << setw(20)
                                              << c_pwd[j] << setw(20)
                                              << c_amt[j] << setw(20)
                                              << c_uname[j] << setw(20)
                                              << endl;
                                    temp_file.close();
                                }
                                else
                                {
                                    cout << "saved failed" << endl;
                                }
                            }
                            if(c_ic[j] == "")
                            {
                                c_ic[i] = "";
                                c_pwd[i] = "";
                                c_amt[i] = "";
                                c_uname[i] = "";
                                break;
                            }
                        }
                    }
                }
                remove("clients_list.txt");
                rename("temp_list.txt", "clients_list.txt");
                cout << "deleting the account";
                int loadui;
                double loadingtime;
                for (loadui=0;loadui<10;loadui++)
                {
                    cout<<".";
                    for(loadingtime=0;loadingtime<=190000000;loadingtime++);
                }

                cout<<"\nYour account is deleted. Return to main menu in a few second."<<endl;
                for (loadui=0;loadui<10;loadui++)
                {
                    for(loadingtime=0;loadingtime<=100000000;loadingtime++);
                }
                main();
            }
            if(delopt == 'n' || delopt == 'N')
            {
                home_page(dlt_ic,dlt_pwd);
            }

}

void Bank::view_rec(){

    string ad_uname, ad_pwd;
    system("cls");
    cout << "                                       ______________________________________________\n" <<endl;
    cout << "                                                   A d m i n  L o g i n                  " <<endl;
    cout << "                                       ______________________________________________" <<endl;
    cout << "";
    cout << "\n\n                                          [!]  USERNAME     : "<<ad_uname;
    cout <<   "\n                                          [!]  PASSWORD     : "<<ad_pwd;
    cout <<"\n\n"<<endl;

    cout << "Please insert admin username: ";
    cin >> ad_uname;

    system("cls");
    cout << "                                       ______________________________________________\n" <<endl;
    cout << "                                                   A d m i n  L o g i n                  " <<endl;
    cout << "                                       ______________________________________________" <<endl;
    cout << "";
    cout << "\n\n                                          [!]  USERNAME     : "<<ad_uname;
    cout <<   "\n                                          [!]  PASSWORD     : "<<ad_pwd;
    cout <<"\n\n"<<endl;


    cout << "Please insert admin password: ";
    cin >> ad_pwd;

    if(ad_uname == "groupA" && ad_pwd == "groupA123")
    {
        view_rec_ui();
        for(int i = 0; i <= max_store; i++)
        {
            if(c_ic[i] != "")
            {
                cout << setw(20)
                     << c_ic[i] << setw(20)
                     << c_uname[i] << endl;

            }
            if(c_ic[i] == "")
            {
                break;
            }
        }
        cout <<"____________________________________________________________________________"<<endl;
        cout << "\nThat is all records! Do you want to go back to main menu?" << endl;
        cout << "Insert y to go back to main menu, insert n to exit [y|n]: ";
        cin >> decision;

        while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
        {
            cin.ignore();
            cin.clear();
            cin.sync();
            cout << "Incorrect input. Please insert again: ";
            cin >> decision;
        }

        if(decision == 'y' || decision == 'Y')
        {
            main();
        }
        if(decision == 'n' || decision == 'N')
        {
            exit(0);
        }
    }
      else
    {
        cout << "Incorrect admin username and admin password" << endl;
        cout << "Insert y to insert again, insert n to go back to main menu [y|n]: ";
        cin >> decision;

        while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
        {
            cin.ignore();
            cin.clear();
            cin.sync();
            cout << "Incorrect input. Please insert again: ";
            cin >> decision;
        }

        if(decision == 'y' || decision == 'Y')
        {
            view_rec();
        }
        if(decision == 'n' || decision == 'N')
        {
            main();
        }
    }
}

void Bank::view_rec_ui(){
    system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n                                                 Loading data";
            int loadui;
            double loadingtime;
            for (loadui=0;loadui<10;loadui++)
            {
                cout<<".";
                for(loadingtime=0;loadingtime<=190000000;loadingtime++);
            }
            system("cls");
            cout <<"____________________________________________________________________________\n\n";
            cout <<"        IC NUMBER    |      UserName           "<<endl;
            cout <<"____________________________________________________________________________\n"<<endl;


}

void Bank::search_acc(){
    int check = 0;
    search_acc_ui();

    cout << "\n\n\nPlease insert IC number to search your account: ";
    cin >> s_ic;
    search_acc_ui();
    cout << "                                          Searching for the account";
            int loadui;
            double loadingtime;
            for (loadui=0;loadui<10;loadui++)
            {
                cout<<".";
                for(loadingtime=0;loadingtime<=190000000;loadingtime++);
            }

    for(int i = 0; i <= max_store; i++)
    {
        if(c_ic[i] == s_ic)
        {
            check++;
            search_acc_ui();
            cout << "                                                    Account found!\n" << endl;
            cout <<"________________________________________________________________________________________________________________________\n\n";
            cout <<"           IC NUMBER               |             Username           "<<endl;
            cout <<"________________________________________________________________________________________________________________________\n\n"<<endl;
            cout <<"          "<<c_ic[i] << "                " << c_uname[i] << endl;
            cout <<"\n________________________________________________________________________________________________________________________\n\n";
            cout << "Do you want to log into this account?" << endl;
            cout << "Insert y to log in, insert n to go back to main menu [y|n]: ";
            cin >> decision;

            while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
            {
                cin.ignore();
                cin.clear();
                cin.sync();
                cout << "Incorrect input. Please insert again: ";
                cin >> decision;
            }

            if(decision == 'y' || decision == 'Y')
            {
                login();
            }
            if(decision == 'n' || decision == 'N')
            {
                main();
            }
        }
    }

    if(check == 0)
    {   search_acc_ui();
        cout << "                                                   Account Doest Not Exist!\n" << endl;
        cout << "\n\nDo you want to search again?" << endl;
        cout << "Insert y to search again, insert n to go back to main menu [y|n]: ";
        cin >> decision;

        while((decision != 'y' && decision != 'Y') && (decision != 'n' && decision != 'N'))
        {
            cin.ignore();
            cin.clear();
            cin.sync();
            cout << "Incorrect input. Please insert again: ";
            cin >> decision;
        }

        if(decision == 'y' || decision == 'Y')
        {
            search_acc();
        }
        if(decision == 'n' || decision == 'N')
        {
            main();
        }
    }
}

void Bank::search_acc_ui(){
    system("cls");
    cout << "                                       ______________________________________________\n" <<endl;
    cout << "                                                   S e a r c h  A c c o u n t" <<endl;
    cout << "                                       ______________________________________________" <<endl;
    cout << "";
    cout << "\n\n                                              [!] IC NUMBER: "<<s_ic<<endl;
    cout << "\n\n";
}

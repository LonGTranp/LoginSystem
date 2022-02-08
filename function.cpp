#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "function.h"
using namespace std;

void showMenu()
{
    cout << "\n+------------------------------+\n";
    cout << "|1. Register                   |\n";
    cout << "|2. Sign up                    |\n";
    cout << "|3. Exit                       |\n";
    cout << "+------------------------------+\n";
}

void Menu(USER a[], int n, string filename)
{
    bool Switch = true;
    while (Switch)
    {
        showMenu();
        int input;
        cout << "\nNhap thao tac: ";
        cin >> input;
        switch (input)
        {
        case 1:
            SignIn(a, n);
            break;
        case 2:
            SignUp(a, n, filename);
            break;
        case 3:
            Switch = false;
            break;
        default:
            break;
        }
    }
}

void Nhap(USER &a, ifstream &fileIn)
{
    getline(fileIn, a.username);
    getline(fileIn, a.password);
}

void Nhap(USER a[], int &n, string filename)
{
    ifstream fileIn;
    fileIn.open(filename);
    fileIn >> n;
    fileIn.ignore();
    for (int i = 0; i < n; i++)
        Nhap(a[i], fileIn);
    fileIn.close();
}

void SignIn(USER a[], int n)
{
    bool sign = false;
    string userName;
    string passWord;
    cout << "Nhap tai khoan: ";
    cin.ignore();
    getline(cin, userName);
    cout << "Nhap mat khau: ";
    getline(cin, passWord);
    for (int i = 0; i < n; i++)
    {
        if (userName == a[i].username && passWord == a[i].password)
            sign = true;
    }
    if (sign)
        cout << "Dang nhap thanh cong.\n";
    else
        cout << "Tai khoan hoac mat khau khong chinh xac.\n";
}

void SignUp(USER a[], int &n, string filename)
{
    cin.ignore();
    string passWord, passWord2;
    cout << "Nhap tai khoan: ";
    getline(cin, a[n].username);
    cout << "Nhap mat khau: ";
    getline(cin, passWord);
    cout << "Nhap lai mat khau: ";
    getline(cin, passWord2);
    while (passWord != passWord2)
    {
        cout << "Mat khau khong chinh xac.\nVui long nhap lai: ";
        getline(cin, passWord2);
    }
    a[n].password = passWord2;
    n++;
    cout << "Tao tai khoan thanh cong.\n";
    SaveFile(a, n, filename);
}

void SaveFile(USER a[], int n, string filename)
{
    ofstream fileOut;
    fileOut.open(filename);
    fileOut << n << endl;
    for (int i = 0; i < n; i++)
    {
        fileOut << a[i].username << endl
                << a[i].password << endl;
    }
    fileOut.close();
}
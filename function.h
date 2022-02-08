#include <string>
using namespace std;

struct user
{
    string username;
    string password;
};
typedef struct user USER;

void showMenu();
void Menu(USER[], int, string);
void Nhap(USER &, ifstream &);
void Nhap(USER[], int &, string);
void SignIn(USER[], int);
void SignUp(USER[], int &, string);
void SaveFile(USER[], int, string);
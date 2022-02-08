#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "function.h"
using namespace std;

int main()
{
    USER *a;
    int n;
    string filename = "ListUser.txt";
    a = new USER[100];
    Nhap(a, n, filename);
    Menu(a, n, filename);
    delete[] a;
    return 0;
}
#include <iostream>
#include <iomanip>
#include "Factory.h"
#include "other.h"
using namespace std;

int main()
{
    system("color 0D");
    Factory f;
    char ch = 'y';
    while (ch == 'y')
    {
        system("cls");
        f.make_order();
        ch = IsChar("Do you want to make another order (y/n)? ");
    }
    return 0;
}
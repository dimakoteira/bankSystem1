#include <iostream>
#include"clsLoginScreen.h";
#include"clsDate.h"
int main()
{
    while (true) {
        if (!clsLoginScreen::loginScreen())
            break;
    }
  
}

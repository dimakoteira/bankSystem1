#include <iostream>
#include"../includes/clsLoginScreen.h";
#include"clsDate.h"
int main()
{
    while (true) {
        if (!clsLoginScreen::loginScreen())
            break;
    }
  
}

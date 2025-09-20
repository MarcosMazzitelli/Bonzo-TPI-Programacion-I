#include <iostream>
#include <cstdlib>
#include <ctime>
#include "menu.h"

using namespace std;


int main()
{
    srand(static_cast<unsigned int>(time(NULL))); // Inicializa la semilla para rand()
    menu();

}


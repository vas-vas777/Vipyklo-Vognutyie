// Lab2-game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <C:\МГТУ\ТеорияИгр\NumCpp-master\include\NumCpp\Linalg.hpp>
#include <C:\МГТУ\ТеорияИгр\NumCpp-master\include\NumCpp\NdArray.hpp>
#include "Header.h"


int main(int argc, char *argv[])
{
   // std::cout.imbue(std::locale("RUS"));
    enter_values_of_kernel_function(argc,argv);
    analitic_method();
    braun_robin();
}

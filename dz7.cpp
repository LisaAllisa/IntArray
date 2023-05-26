#include "pch.h"
#include <iostream>
#include "IntArray.h"
#include <exception>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    IntArray array(10);
      
    {
        for (int i { 0 }; i < 10; ++i)
        array[i] = i + 1;
    }

//    array.Erase();

    array.resize(8);

    array.insertBefore(348, 15);

    array.remove(1);
    
    array.insertAtEnd(300);

    array.insertAtBeggining(1110);

    {
        IntArray b{ array };
        b = array;
        b = b;
        array = array;
    }
    
    for (int i{ 0 }; i < array.getM_length(); ++i)
        std::cout << array[i] << " ";

    std::cout << "\n";

    return 0;
}


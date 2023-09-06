// #include <iostream>
// int main()
// {
//     int sum = 0;
//     // sum values from 1 through 10 inclusive
//     for (int val = 1; val <= 10; ++val) 
//         sum += val; // equivalent to sum = sum + val 
//     std::cout   << "Sum of 1 to 10 inclusive is " 
//                 << sum  << std::endl; 
//     return 0;
// }

#include <iostream>
#include "Struct.h"

int main()
{
    Sales_Data data1, data2;
    double price = 0;

    std :: cout << "ISBN : " << std :: endl;
    std :: cin >> data1.bookName;
    std :: cout << "Number : " << std :: endl;
    std :: cin >> data1.units_sold;
    std :: cout << "Price : " << std :: endl;
    std :: cin >> price;
    data1.revenue = data1.units_sold * price;
    std :: cout << "Total : " << data1.revenue << std :: endl;

    std :: cout << "ISBN : " << std :: endl;
    std :: cin >> data2.bookName;
    std :: cout << "Number : " << std :: endl;
    std :: cin >> data2.units_sold;
    std :: cout << "Price : " << std :: endl;
    std :: cin >> price;
    data2.revenue = data2.units_sold * price;
    std :: cout << "Total : " << data2.revenue << std :: endl;

    if(data1.bookName == data2.bookName){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalPrice = data2.revenue + data1.revenue;

        std :: cout << data1.bookName << " " << totalCnt << " " << totalPrice << " ";

        if(totalCnt != 0) std :: cout << totalPrice / totalCnt << std :: endl;
        else std :: cout << "no sale" << std::endl;
        return 0;

    }
    else {
        std :: cerr << "Data must resfer to the same ISBN " << std :: endl;
        return -1;
    }



    return 0;
}
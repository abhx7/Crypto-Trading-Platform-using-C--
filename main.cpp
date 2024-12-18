#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"

int main()
{   
    //Wallet wallet{};
    MerkelMain app{};
    app.init();
    
    //CSVReader::readCSV("20200317.csv");

    // Wallet wallet{};
    // wallet.insertCurrency("USDT", 100);
    // wallet.insertCurrency("BTC", 0.5);

    // std::cout <<  wallet.containsCurrency("USDT", 1000) << std::endl;
    // std::cout <<  wallet.containsCurrency("BTC", 0.25) << std::endl;

    // bool result = wallet.containsCurrency("BTC", 1.5);
    // std::cout << "Result should be true " << result << std::endl;
    // result = wallet.removeCurrency("BTC", 2.0);
    // std::cout << "Result should be false " << result << std::endl;
    // result = wallet.removeCurrency("BTC", 1.0);
    // std::cout << "Result should be true " << result << std::endl;

}

// int main()
// {
//     try
//     {
//         Wallet wallet{};
//         wallet.insertCurrency("BTC", 1.5);
//         std::cout << wallet.toString() << std::endl;

//         MerkelMain app{};
//         app.init();
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << "Application error: " << e.what() << std::endl;
//     }
//     return 0;
// }




//     std::vector<OrderBookEntry> orders;

//     orders.push_back(  OrderBookEntry{1000, 
//                           0.02, 
//                         "2020/03/17 17:01:24.884492", 
//                         "BTC/USDT", 
//                         OrderBookType::bid}    );

//     orders.push_back(  OrderBookEntry{2000, 
//                           0.02, 
//                         "2020/03/17 17:01:24.884492", 
//                         "BTC/USDT", 
//                         OrderBookType::bid}    );
        

//    // std::cout << "The price is " << orders[1].price << std::endl;

//     for (OrderBookEntry& order : orders)
//     {
//         std::cout << "The price is " << order.price << std::endl;
//     }

//     for (unsigned int i = 0; i < orders.size() ; ++i)
//     {
//         std::cout << "The price is " << orders[i].price << std::endl;
//     }

//     for (unsigned int i = 0; i < orders.size() ; ++i)
//     {
//         std::cout << "The price is " << orders.at(i).price << std::endl;
//     }





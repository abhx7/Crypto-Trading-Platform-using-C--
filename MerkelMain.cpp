#include "MerkelMain.h"
#include "OrderBook.h"
#include <iostream>
#include <functional>

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    std::cout << "1: Print help\n"
              << "2: Print exchange stats\n"
              << "3: Place an ask\n"
              << "4: Place a bid\n"
              << "5: Print wallet\n"
              << "6: Continue\n";
}

int MerkelMain::getUserOption()
{
    int userOption;
    std::cout << "Type in 1-6: ";
    std::cin >> userOption;

    if (std::cin.fail() || userOption < 1 || userOption > 6)
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid input. Choose a number between 1 and 6.\n";
        return 0;
    }
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    static std::map<int, std::function<void()>> menu = {
        {1, [this]() { printHelp(); }},
        {2, [this]() { printMarketStats(); }},
        {3, [this]() { enterOffer(); }},
        {4, [this]() { enterBid(); }},
        {5, [this]() { printWallet(); }},
        {6, [this]() { gotoNextTimeframe(); }}};

    if (menu.find(userOption) != menu.end())
    {
        menu[userOption]();
    }
    else
    {
        std::cout << "Error. Choose a valid option between 1 and 6.\n";
    }
}

void MerkelMain::printHelp()
{
    std::cout << "Help: Analyze the market and make bids/offers to earn money.\n";
}

void MerkelMain::printMarketStats()
{
    for (const auto& product : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << product << "\n";
        auto entries = orderBook.getOrders(OrderBookType::ask, product, currentTime);
        std::cout << "Asks seen: " << entries.size() << "\n"
                  << "Max ask: " << OrderBook::getHighPrice(entries) << "\n"
                  << "Min ask: " << OrderBook::getLowPrice(entries) << "\n";
    }
}

void MerkelMain::enterOffer()
{
    std::cout << "Enter ask amount:\n";
}

void MerkelMain::enterBid()
{
    std::cout << "Enter bid amount:\n";
}

void MerkelMain::printWallet()
{
    std::cout << "Wallet: Rs. 1000\n";
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Advancing to the next timeframe.\n";
    currentTime = orderBook.getNextTime(currentTime);
}

// #include "MerkelMain.h" 
// #include <iostream> 
// #include <vector>
// #include <map>

// /** your main function should call this */

// void MerkelMain::init()
// {
//     //loadOrderBook(); 
//     int input;
//     currentTime = orderBook.getEarliestTime();
//     while (true)
//     {
//         printMenu();
//         input = getUserOption();
//         processUserOption(input);
//     }
// }

// /** load up some dummy data for now */
// // void MerkelMain::loadOrderBook()
// // {
// //     orders.push_back(OrderBookEntry{1000, 0.02, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});
// //     orders.push_back(OrderBookEntry{2000, 0.02, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});
// // }

// // Function to convert OrderBookType to a string
// std::string orderBookTypeToString(OrderBookType type)
// {
//     switch (type)
//     {
//     case OrderBookType::bid:
//         return "Bid";
//     case OrderBookType::ask:
//         return "Ask";
//     default:
//         return "Unknown";
//     }
// }

// /** prints all available options from the menu */
// void MerkelMain::printMenu()
// {
//     std::cout << "1: Print help" << std::endl;
//     std::cout << "2: Print exchange stats" << std::endl;
//     std::cout << "3: Place an ask" << std::endl;
//     std::cout << "4: Place a bid" << std::endl;
//     std::cout << "5: Print wallet" << std::endl;
//     std::cout << "6: Continue" << std::endl;
// }

// int MerkelMain::getUserOption()
// {
//     int userOption;
//     std::cout << "Type in 1-6: ";
//     std::cin >> userOption;
//     std::cout << "You chose: " << userOption << std::endl;
//     return userOption;
// }

// void MerkelMain::printHelp()
// {
//     std::cout << "Help - your aim is to make money." << std::endl;
//     std::cout << "Analyse the market and make bids and offers." << std::endl;
// }

// void MerkelMain::printMarketStats()
// {
//     //std::cout << "Exchange stats" << std::endl;
//     for (std::string const& p : orderBook.getKnownProducts())
//     {
//         std::cout << "Product : " << p << std::endl;
//         std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
//         std::cout << "Asks seen : " << entries.size() << std::endl;
//         std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
//         std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
//     }
// }

// void MerkelMain::enterOffer()
// {
//     std::cout << "Enter ask amount: " << std::endl;
// }

// void MerkelMain::enterBid()
// {
//     std::cout << "Enter bid amount: " << std::endl;
// }

// void MerkelMain::printWallet()
// {
//     std::cout << "Amount in wallet: Rs. 1000" << std::endl;
// }

// void MerkelMain::gotoNextTimeframe()
// {
//     std::cout << "Going to next time frame. " << std::endl;
//     currentTime = orderBook.getNextTime(currentTime);
// }

// #include <functional> // For std::bind

// void MerkelMain::processUserOption(int userOption)
// {
//     // Map from integers to lambdas that call the member functions
//     std::map<int, std::function<void()>> menu = {
//         {1, [this]() { printHelp(); }},
//         {2, [this]() { printMarketStats(); }},
//         {3, [this]() { enterOffer(); }},
//         {4, [this]() { enterBid(); }},
//         {5, [this]() { printWallet(); }},
//         {6, [this]() { gotoNextTimeframe(); }} };

//     // Check if the userOption is valid and call the corresponding function
//     if (menu.find(userOption) != menu.end())
//     {
//         menu[userOption]();
//     }
//     else
//     {
//         std::cout << "Error. Choose an option between 1 and 6." << std::endl;
//     }
// }
#pragma once 
#include <vector> 
#include "OrderBookEntry.h" 
#include "OrderBook.h"
#include "CSVReader.h"
#include <map>

class MerkelMain
{
public:
    MerkelMain() = default;

    /** Call this to start the sim */
    void init();


private:
    //void loadOrderBook(); 
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void processUserOption(int userOption);

    std::string currentTime;

    // this is the new way 
    // we will represent the orders 
    OrderBook orderBook{ "20200317.csv" };
    // we don't want this any more as 
    // OrderBook will store this data itself 
    //std::vector < OrderBookEntry> orders; 
};
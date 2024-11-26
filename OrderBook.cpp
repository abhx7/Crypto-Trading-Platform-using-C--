#include "OrderBook.h"
#include "OrderBookEntry.h" 
#include "CSVReader.h" 
#include <string> 
#include <vector>
#include <map>

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
    std::map<std::string, bool> prodMap;
    for (const OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }

    std::vector<std::string> products;
    for (const auto& e : prodMap)
    {
        products.push_back(e.first);
    }
    return products;
}

std::string OrderBook::getEarliestTime()
{
    //possible upgrade is iterating over all the orders to find the smallest time step
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(const std::string& timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }

    if (next_timestamp == "")
    {
        next_timestamp = getEarliestTime();
    }

    return next_timestamp;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
    std::string product,
    std::string timestamp)
{
    std::vector<OrderBookEntry> order_sub;
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == type &&
            e.product == product &&
            e.timestamp == timestamp)
        {
            order_sub.push_back(e);
        }
    }
    return order_sub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price > max)
        {
            max = e.price;
        }
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price < min)
        {
            min = e.price;
        }
    }
    return min;
}
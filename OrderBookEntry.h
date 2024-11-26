#pragma once

#include <iostream>
#include <string>
#include <vector>


// Enum declaration moved outside main()
enum class OrderBookType
{
    bid,
    ask,
    unknown
};


class OrderBookEntry
{
public: /** Create a new OrderBookEntry with the price * set to the sent value */
    OrderBookEntry(double _price,
        double _amount,
        const std::string& _timestamp,
        const std::string& _product,
        OrderBookType _orderType);

    double price;            // : 0.02187308
    double amount;           // : 7.44564869
    std::string timestamp;   // : 2020 / 03 / 17 17 : 01 : 24.884492
    std::string product;     // : ETH / BTC
    OrderBookType orderType; // : bid
    static OrderBookType stringToOrderBookType(const std::string& s);
};
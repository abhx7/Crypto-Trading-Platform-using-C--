# MerkelMain Trading Simulator

## Overview
MerkelMain is a simple trading simulator designed to analyze market trends, place bids and asks, and manage a virtual wallet. It uses a CSV-based order book to simulate market data and provides an interactive menu for user inputs.

---

## Features
1. **Interactive Menu**:
   - Print help information.
   - Display exchange statistics.
   - Place asks and bids.
   - View wallet contents.
   - Move to the next timeframe.

2. **CSV-Based Order Book**:
   - Reads market data from a CSV file.
   - Extracts order information (bids/asks) for analysis.

3. **Data Processing**:
   - Calculate statistics like max/min prices and order counts.
   - Navigate through market data timeframes.

---

## Project Structure

### Header Files
- **`MerkelMain.h`**: Declares the main trading simulation logic.
- **`OrderBook.h`**: Manages the order book and market data.
- **`OrderBookEntry.h`**: Represents individual entries in the order book.
- **`CSVReader.h`**: Parses market data from a CSV file.

### Source Files
- **`main.cpp`**: Entry point for the program.
- **`MerkelMain.cpp`**: Implements the main menu and user interaction logic.
- **`OrderBook.cpp`**: Processes market data, calculates statistics, and handles time navigation.
- **`CSVReader.cpp`**: Handles file reading and parsing.
- **`OrderBookEntry.cpp`**: Provides structure and utility methods for order entries.

---
## Key Classes and Functions
### MerkelMain
init(): Starts the trading simulation.
printMenu(): Displays the interactive menu.
processUserOption(int userOption): Maps user input to the appropriate action.
### OrderBook
getKnownProducts(): Lists all products in the market data.
getOrders(): Filters orders based on type, product, and timestamp.
getHighPrice() & getLowPrice(): Retrieve price statistics for orders.
### CSVReader
readCSV(): Reads and parses a CSV file into OrderBookEntry objects.

```yaml
1: Print help
2: Print exchange stats
3: Place an ask
4: Place a bid
5: Print wallet
6: Continue
Type in 1-6: 2
You chose: 2
Product: BTC/USDT
Asks seen: 10
Max ask: 50000
Min ask: 45000
```


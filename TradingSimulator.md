# MerkelMain Trading Simulator

## Overview
MerkelMain is a comprehensive trading simulator designed to analyze market trends, place bids and asks, and manage a virtual wallet. It uses a CSV-based order book to simulate market data and provides an interactive menu for user inputs. The simulator includes features for order matching and wallet management.

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
   - Automatically matches asks and bids based on price and amount.

3. **Data Processing**:
   - Calculate statistics like max/min prices and order counts.
   - Navigate through market data timeframes.
   - Maintain and update a virtual wallet based on successful trades.

---

## Project Structure

### Header Files
- **`MerkelMain.h`**: Declares the main trading simulation logic.
- **`OrderBook.h`**: Manages the order book and market data, handles order matching.
- **`OrderBookEntry.h`**: Represents individual entries in the order book.
- **`CSVReader.h`**: Parses market data from a CSV file.
- **`Wallet.h`**: Manages virtual wallet operations like adding, removing, and verifying funds.

### Source Files
- **`main.cpp`**: Entry point for the program.
- **`MerkelMain.cpp`**: Implements the main menu and user interaction logic.
- **`OrderBook.cpp`**: Processes market data, calculates statistics, and handles order matching.
- **`CSVReader.cpp`**: Handles file reading, tokenization, and parsing.
- **`OrderBookEntry.cpp`**: Provides structure and utility methods for order entries.
- **`Wallet.cpp`**: Manages the virtual wallet's operations and updates based on transactions.

---

## Key Classes and Functions

### `MerkelMain`
- **`init()`**: Starts the trading simulation and initializes the wallet.
- **`printMenu()`**: Displays the interactive menu.
- **`processUserOption(int userOption)`**: Maps user input to the appropriate action (e.g., placing asks/bids, printing stats).
- **`enterAsk()` & `enterBid()`**: Allow users to place asks and bids, validating input against wallet funds.

### `OrderBook`
- **`getKnownProducts()`**: Lists all products in the market data.
- **`getOrders()`**: Filters orders based on type, product, and timestamp.
- **`matchAsksToBids()`**: Matches asks and bids for a specific product and timestamp.
- **`insertOrder()`**: Inserts a new order into the order book while maintaining order.
- **`getHighPrice()` & `getLowPrice()`**: Retrieve price statistics for orders.

### `Wallet`
- **`insertCurrency()`**: Adds currency to the wallet.
- **`removeCurrency()`**: Removes currency from the wallet.
- **`canFulfillOrder()`**: Checks if the wallet can fulfill an ask or bid.
- **`processSale()`**: Updates the wallet based on successful transactions.
- **`toString()`**: Returns a string representation of the wallet contents.

### `CSVReader`
- **`readCSV()`**: Reads and parses a CSV file into `OrderBookEntry` objects.
- **`tokenise()`**: Splits a CSV line into tokens for processing.
- **`stringsToOBE()`**: Converts strings into an `OrderBookEntry` object.

---

## Build and Run

### Compile the code:
```bash
g++ -std=c++17 -o MerkelMain main.cpp MerkelMain.cpp OrderBook.cpp CSVReader.cpp OrderBookEntry.cpp Wallet.cpp
```

Run the app
```bash
./MerkelMain
```

Sample Menu Interaction
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

CSV File Format

The simulator uses a CSV file (20200317.csv) as input data. Each row contains the following fields:
```csv
2020/03/17 17:01:24.884492,BTC/USDT,bid,10000,1.5
2020/03/17 17:01:24.884492,BTC/USDT,ask,11000,0.5
```

## Troubleshooting
1. File Not Found:
- Ensure the CSV file (20200317.csv) exists in the project directory.
- Verify that the filename and path are correct.

2. Invalid Input:
- The menu only accepts numbers 1-6. Inputs outside this range are ignored.
- Ensure the format for bids/asks follows: product,price,amount.

3. Parsing Errors:
- Ensure the CSV file uses the expected format: timestamp,product,type,price,amount.
- Check for missing or malformed lines in the CSV file.

4. Insufficient Wallet Funds:
- Ensure your wallet has enough funds for the transaction. Use Print wallet to check available currencies.

## Future Improvements

Advanced Features:
- Support for multiple users with individual wallets.
- Integration with real-time market data.

Performance Enhancements:
- Optimize order matching for large datasets.
- Use a database or in-memory data structure for faster order lookups.

UI Enhancements:
- Add a graphical user interface (GUI) for better usability.


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

## Installation and Usage

### Prerequisites
- C++ Compiler (e.g., GCC, Clang, or MSVC)
- CMake (optional, for build automation)

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/MerkelMain.git
   cd MerkelMain

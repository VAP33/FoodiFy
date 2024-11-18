# Foodify Order System

This is a C-based simulation program for a simple ordering system. It models a restaurant where customers can place food and beverage orders from a predefined menu, and the system will calculate the total bill based on their choices. The program features case-insensitive comparison, input length validation, and dynamic order display.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Menu](#menu)
- [How It Works](#how-it-works)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [Contributing](#contributing)
- [License](#license)

## Overview

This program simulates the ordering process at a restaurant, where customers can choose from a list of food items and beverages. The program displays the available menu items, accepts user input for the order, performs case-insensitive matching to the menu, calculates the total bill, and shows a summary of the full order. It is written in C, and uses the CS50 library for user input handling.

### Key Features

- **Menu Display**: Shows a list of available food items and beverages with prices.
- **Case-Insensitive Input**: The program allows users to enter their orders without worrying about letter case.
- **Input Validation**: User inputs are validated for length to prevent buffer overflow and ensure stability.
- **Bill Calculation**: Calculates the total price based on the selected food items and beverages.
- **Order Summary**: Displays the full order, including both food and beverage items, and the total bill.

## Features

- **Food and Beverage Selection**: Users can choose from a predefined list of food items and beverages.
- **Case-Insensitive Matching**: Orders are matched to the menu items irrespective of case (e.g., `burger`, `Burger`, and `BURGER` are treated as the same).
- **Input Length Check**: Limits the length of user inputs to prevent excessively long strings.
- **Order Confirmation**: Confirms the selected items with the user and displays the total price.
- **String Handling**: Demonstrates string copying and concatenation operations.

## Menu

The available menu items are divided into **Food** and **Beverages** categories.

### Food Items

| Item     | Price  | Price Value (for calculation) |
|----------|--------|-------------------------------|
| Burger   | ₹100   | 100                           |
| Fries    | ₹50    | 50                            |
| Salad    | ₹80    | 80                            |

### Beverages

| Beverage | Price  | Price Value (for calculation) |
|----------|--------|-------------------------------|
| Coke     | ₹50    | 50                            |
| Sprite   | ₹67    | 67                            |
| Water    | ₹20    | 20                            |

## How It Works

1. **Menu Display**: The program first shows the available food and beverage items.
2. **User Input**: The user is prompted to input the name of the food item they want to order.
3. **Case-Insensitive Matching**: The system compares the user's input to the menu items and performs a case-insensitive comparison.
4. **Item Availability**: If the item is available, the price is displayed and added to the total.
5. **Beverage Selection**: The user is then asked if they want a beverage. If yes, they choose from the available beverages.
6. **Final Bill Calculation**: The total price of the order is calculated by summing the prices of the selected items (food and beverage).
7. **Order Confirmation**: The program displays the full order, including both food and beverage choices, and the total bill.

## Requirements

To compile and run the program, you will need:

- **A C Compiler**: The program is written in C, and you'll need a C compiler like GCC.
- **CS50 Library**: The program uses the CS50 library to handle user input. If you're not using the CS50 environment, you will need to install the library on your system.
  
### Installing the CS50 Library

If you're running this outside of the CS50 environment, you can install the CS50 library with the following command on a Unix-like system:

```bash
sudo apt-get install libcs50

#include <stdio.h>
#include <cs50.h>     // CS50 library for get_string (if you are using CS50)
#include <string.h>   // For string operations like strcmp, strncpy, etc.
#include <ctype.h>    // For ctype functions like tolower() (if needed)

#ifdef __unix__  // Linux/macOS support
    #include <strings.h>  // Include strings.h for strcasecmp()
#endif

#define MAX_ORDER_LENGTH 100

// Define a struct for Items and Beverages
typedef struct
{
    string name;
    string price;
    int price_value;
} Item;

typedef struct
{
    string name;
    string price;
    int price_value;
} Beverage;

// Case-insensitive comparison function for Linux/macOS and Windows
#ifdef __unix__ // Linux/macOS support
    #define CASE_INSENSITIVE_COMPARE(a, b) (strcasecmp(a, b))  // Use strcasecmp on Unix systems
#else // Windows support
    #define CASE_INSENSITIVE_COMPARE(a, b) (_stricmp(a, b))     // Use _stricmp on Windows
#endif

// Function to ensure input length does not exceed MAX_ORDER_LENGTH
string get_input_with_max_length(string prompt, int max_length) {
    string input;
    do {
        input = get_string("%s", prompt); // Get the input string
        if (strlen(input) > max_length) {
            printf("Please enter a valid input (maximum %d characters allowed).\n", max_length);
        }
    } while (strlen(input) > max_length); // Repeat until input is within the length limit
    return input;
}

int main(void)
{
    // Menu items and beverages
    Item menu[] = {
        {"Burger", "₹100", 100},
        {"Fries", "₹50", 50},
        {"Salad", "₹80", 80}
    };

    Beverage beverages[] = {
        {"Coke", "₹50", 50},
        {"Sprite", "₹67", 67},
        {"Water", "₹20", 20}
    };

    printf("Welcome to McDonald's! Check out our menu:\n");
    int num_items = sizeof(menu) / sizeof(menu[0]);

    // Display the menu
    for (int i = 0; i < num_items; i++)
    {
        printf("%s - %s\n", menu[i].name, menu[i].price);
    }

    // Get the user's order
    string order = get_input_with_max_length("Please enter the order to be placed: ", MAX_ORDER_LENGTH);

    bool item_found = false;
    int total_price = 0; // Initialize total price
    string item_order = ""; // String to store the item name

    // Compare the order with menu items
    for (int i = 0; i < num_items; i++)
    {
        if (CASE_INSENSITIVE_COMPARE(menu[i].name, order) == 0)  // Case-insensitive comparison
        {
            item_found = true;
            printf("Item Available!\n");
            printf("Price: %s\n", menu[i].price);
            total_price += menu[i].price_value; // Add food item price to total
            item_order = menu[i].name; // Store the name of the ordered item

            // Ask for beverage choice
            if (get_string("Do you want to have a beverage? (y/n): ")[0] == 'y')
            {
                printf("Available beverages:\n");

                int num_beverages = sizeof(beverages) / sizeof(beverages[0]);

                for (int j = 0; j < num_beverages; j++)
                {
                    printf("%s - %s\n", beverages[j].name, beverages[j].price);
                }

                // Get the beverage order
                string beverage_order = get_input_with_max_length("Please enter a beverage: ", MAX_ORDER_LENGTH);

                bool beverage_found = false;

                // Compare the beverage with available beverages
                for (int j = 0; j < num_beverages; j++)
                {
                    if (CASE_INSENSITIVE_COMPARE(beverages[j].name, beverage_order) == 0)  // Case-insensitive comparison
                    {
                        beverage_found = true;
                        printf("Beverage Found!\n");
                        printf("Price: %s\n", beverages[j].price);
                        total_price += beverages[j].price_value; // Add beverage price to total

                        // String concatenation operation
                        char full_order[MAX_ORDER_LENGTH * 2];  // Buffer for the full order
                        snprintf(full_order, sizeof(full_order), "%s with %s", item_order, beverages[j].name);
                        printf("Concatenated full order: %s\n", full_order);  // Show concatenated string

                        printf("Thank You for Ordering with McDonald's!\n");
                        break;
                    }
                }

                if (!beverage_found)
                {
                    printf("Sorry, the beverage is not available!\n");
                }
            }
            else
            {
                printf("Okay, thanks for ordering with McDonald's!\n");
            }
            break;
        }
    }

    if (!item_found)
    {
        printf("The item is NOT available!\n");
    }

    // Print the final bill if an item was found
    if (item_found)
    {
        printf("Your total bill is: ₹%d\n", total_price);
    }

    return 0;
}

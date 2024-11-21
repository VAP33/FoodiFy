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

    printf("Welcome to Foodify! Check out our menu:\n");
    int num_items = sizeof(menu) / sizeof(menu[0]);

    // Display the menu
    for (int i = 0; i < num_items; i++)
    {
        printf("%s - %s\n", menu[i].name, menu[i].price);
    }

    // Get the user's order
    string order = get_string("Please enter the order to be placed: ");

    // Length checking (Truncate if necessary)
    printf("\n=== STRING LENGTH CHECKING ===\n");
    printf("Length of the order input: %lu\n", strlen(order));  // Print length of the input
    if (strlen(order) > MAX_ORDER_LENGTH)
    {
        order[MAX_ORDER_LENGTH] = '\0';  // Truncate the string if it's too long
        printf("Your order has been truncated to %d characters.\n", MAX_ORDER_LENGTH);
    }

    bool item_found = false;
    int total_price = 0; // Initialize total price
    string item_order = ""; // String to store the item name

    // Compare the order with menu items
    for (int i = 0; i < num_items; i++)
    {
        printf("\n=== STRING COMPARISON ===\n");
        printf("Comparing order '%s' with menu item '%s':\n", order, menu[i].name);
        if (CASE_INSENSITIVE_COMPARE(menu[i].name, order) == 0)  // Case-insensitive comparison
        {
            item_found = true;
            printf("Item Available!\n");
            printf("Price: %s\n", menu[i].price);
            total_price += menu[i].price_value; // Add food item price to total
            item_order = menu[i].name; // Store the name of the ordered item

            // String copying operation
            printf("\n=== STRING COPYING ===\n");
            char item_copy[MAX_ORDER_LENGTH + 1]; // Buffer for storing the order item
            strncpy(item_copy, menu[i].name, MAX_ORDER_LENGTH); // Copy the menu item name
            item_copy[MAX_ORDER_LENGTH] = '\0';  // Ensure null termination
            printf("Copied order item: %s\n", item_copy);  // Show copied string

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
                string beverage_order = get_string("Please enter a beverage: ");

                // Length checking for beverage order
                printf("\n=== STRING LENGTH CHECKING (Beverage) ===\n");
                printf("Length of the beverage order input: %lu\n", strlen(beverage_order));  // Print length
                if (strlen(beverage_order) > MAX_ORDER_LENGTH)
                {
                    beverage_order[MAX_ORDER_LENGTH] = '\0';  // Truncate the string if it's too long
                    printf("Your beverage order has been truncated to %d characters.\n", MAX_ORDER_LENGTH);
                }

                bool beverage_found = false;

                // Compare the beverage with available beverages
                for (int j = 0; j < num_beverages; j++)
                {
                    printf("\n=== STRING COMPARISON (Beverage) ===\n");
                    printf("Comparing beverage order '%s' with beverage '%s':\n", beverage_order, beverages[j].name);
                    if (CASE_INSENSITIVE_COMPARE(beverages[j].name, beverage_order) == 0)  // Case-insensitive comparison
                    {
                        beverage_found = true;
                        printf("Beverage Found!\n");
                        printf("Price: %s\n", beverages[j].price);
                        total_price += beverages[j].price_value; // Add beverage price to total

                        // String concatenation operation
                        printf("\n=== STRING CONCATENATION ===\n");
                        char full_order[MAX_ORDER_LENGTH * 2];  // Buffer for the full order
                        snprintf(full_order, sizeof(full_order), "%s with %s", item_order, beverages[j].name);
                        printf("Concatenated full order: %s\n", full_order);  // Show concatenated string

                        printf("Thank You for Ordering with Foodify!\n");
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
                printf("Okay, thanks for ordering with Foodify!\n");
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

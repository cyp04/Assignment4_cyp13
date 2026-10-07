#include <stdio.h>	// Allows use of printf()
#include <stdlib.h>	// Allows use of malloc() and free()
#include <string.h>	// Allows use of strlen(), strcpy(), and strcmp()
#include "item.h"	// Includes the Item structure definition

// Function prototypes

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index);
void free_items(Item *item_list, int size);
double average_price(Item *item_list, int size);
void print_items(Item *item_list, int size);

int main(int argc, char *argv[])
{

	// Number of items that will be stored in the array
	int size = 5;

	// Counter used when searching through the item list
        int ct = 0;

	// Pointer used to store the SKU entered in the command line
	char *sku;

	// Dynamically allocate memory for an array of 5 item structures
        Item *item_list = malloc(size * sizeof(Item));

	// Check whether memory allocation was successful
        if (item_list == NULL)
        {
                printf("Memory allocation failed.\n");
                return 1;
        }

	// Add five items to the item list
        add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
        add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
        add_item(item_list, 2.50, "14512", "bakery", "bread", 2);
        add_item(item_list, 1.25, "58241", "produce", "banana", 3);
        add_item(item_list, 4.75, "42683", "meat", "chicken", 4);

	// Print all items currently stored in the array
        print_items(item_list, size);

	// Calculate and print the average price of items  
      	printf("average price of items = %f\n", average_price(item_list, size));

	// Check if the user entered a SKU when running the program
        if (argc < 2)
        {

                printf("Please enter a SKU.\n");

		// Free allocated memory before exiting
                free_items(item_list, size);
                return 1;
        }

	// Store the SKU entered by the user
        sku = argv[1];

	// Search through the array until a matching SKU is found
        while (ct < size && strcmp(item_list[ct].sku, sku) != 0)
        {
                ct++;
        }

	// If the SKU was found, print the item's information
        if (ct < size)
        {
                printf("__________________________\n");
                printf("Item name = %s\n", item_list[ct].name);
                printf("Item sku = %s\n", item_list[ct].sku);
                printf("Item category = %s\n", item_list[ct].category);
                printf("Item price = %f\n", item_list[ct].price);
                printf("__________________________\n");
        }
        else
        {

		// Display a message if no matching SKU was found
	        printf("Item not found.\n");
        }

	// Free all allocated memory after the program finishes
        free_items(item_list, size);

        return 0;
}

// Adds a new item to the array at the given index
void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
	// Store the item's price
        item_list[index].price = price;

	// Allocate memory and copy the item's SKU
        item_list[index].sku = malloc(strlen(sku) + 1);
        strcpy(item_list[index].sku, sku);

	// Allocate memory and copy the item's category
        item_list[index].category = malloc(strlen(category) + 1);
        strcpy(item_list[index].category, category);

	// Allocate memory and copy the item's name
        item_list[index].name = malloc(strlen(name) + 1);
        strcpy(item_list[index].name, name);
}

// Prints the information for every item in the array
void print_items(Item *item_list, int size)
{
        int i;

	// Loop through all items and display their information
        for (i = 0; i < size; i++)
        {
                printf("__________________________\n");
                printf("Item name = %s\n", item_list[i].name);
                printf("Item sku = %s\n", item_list[i].sku);
                printf("Item category = %s\n", item_list[i].category);
                printf("Item price = %f\n", item_list[i].price);
        }

        printf("__________________________\n");
}

// Calculates the average price of all items
double average_price(Item *item_list, int size)
{
        double total = 0;
        int i;

	// Add together the prices of all items
        for (i = 0; i < size; i++)
        {
                total += item_list[i].price;
        }

	// Return the total divided by the number of items
        return total / size;
}

// Frees the memory used by the item array
void free_items(Item *item_list, int size)
{
        int i;

	// Free the memory allocated for each item's strings
        for (i = 0; i < size; i++)
        {
                free(item_list[i].sku);
                free(item_list[i].category);
                free(item_list[i].name);
        }
	
	// Free the memory allocated for the item array
        free(item_list);
}

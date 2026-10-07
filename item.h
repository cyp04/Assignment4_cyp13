#ifndef ITEM_H
#define ITEM_H

// Defines a structure called _Item.
// This structure stores information about one item.

struct _Item 
{
	double price; 		// Stores the item's price as a decimal number
	char *sku;		// Pointer to a string that stores the item's SKU number
	char *name;		// Pointer to a string that stores the item's name
	char *category;		// Pointer to a string that stores the item's category
};

// Creates the name "Item" as another name for "struct_Item".
// This lets us write "Item" instead of "struct_Item" in the program.

typedef struct _Item Item;

#endif

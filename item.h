// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 3

// Item Class
// - This class stores 5 data fields that are meant to represent an item in a collection.
// The data fields are a name for an item, the type of the item (or what it is), the year
// the item was made, a description or condition of the item, and how much the item is
// worth. 

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

// Constant for the max size of a character array.
const int SIZE = 100;

// Constant used to store the name of the file where data is being read from. Change this
// to change the file input source.
const char file_name[] = "data.txt";

// Constant for the size of the hash table array used in the Table class. See "table.h"
// and "table.cpp".
const int HASH_SIZE = 50;


class Item 
{

  public:
    // Default constructor to create an instance of an item with integers set to 0 and
    // character arrays set to nullptrs.
    Item();

    // Deconstructor that deletes character arrays and sets them to nullptrs, and sets all
    // integer values to 0.
    ~Item();
    
    // Parameterized constructor that can be used to create item instance with the passed
    // arguments used in the corresponding data fields.
    Item(char * p_name, char * p_type, int p_year, char * p_description, int p_worth);

    // Takes the values in the item passed as an argument and sets the corresponding
    // calling item values.
    int copy_item(Item& copy_from);

    // Uses values passed as aruments to change the data members of the calling item.
    int set_item(char * name, char * type, int year, char * description, int worth);
    
    // Displays private data members to the console. 
    int display(void);

    // Displays data members of an item with a matching type to the argument passed. 
    int display_type_match(char * match);

    // Displays data members of item with a matching name to the argument passed. 
    int display_name_match(char * match);

    // Arguments include a name and an empty item instance passed by reference. If the name matches, the
    // values are copied into the argument provided item.
    int retrieve_match(char * name_to_match, Item& found_item); 

    // Argument includes an empty item instance passed by reference. Copies the data
    // members of the calling item into the argument item.
    int retrieve(Item& found_item); 

    // Determines if the name passed as an argument matches the calling item. Returns
    // 1 for true, 0 for false.
    int is_match(char * name_to_match);

  // ===============================================================================================
  private:
    char * name;
    char * type;
    int  year;
    char * description; 
    int worth;
};




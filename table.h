// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 3

#include "item.h"


// Node struct 
// - This struct holds an Item instance and a pointer to another node struct. By default
// the next node pointer is set to nullptr.

struct node 
{
  Item item;
  node * next;

  node(){
    item = Item();
    next = nullptr;
  }
};


// Table Class
// - This class makes use of an array of head nodes. Each head node has the capability to
// extend into a linear linked list. By default each array index will hold a head node
// that is set to a nullptr. How indexes are filled is determined by a hash function that
// uses the name of an Item to calculate a "random" index. When collisions occur, nodes
// are added at the head. 

class Table 
{

  public:
    // Parameterized constructor that takes an integer argument and creates the table
    // array with a length of the argument passed. 
    Table(int size);

    // Deconstructor
    ~Table(void);
    
    // Takes arguments of a character array and an Item instace that is holding data. The
    // character array can be any data field from the Item instance, but consistency is
    // needed in order to achieve an even spread of collisions. Character array is passed
    // to the hash_function method where an index is calculated based on the characters of
    // the character array.
    int insert(char * key_value, Item & to_add);

    // Takes a character array of a name to match and an array where matches will be stored. 
    int retrieve(char * name_to_find, Item items[HASH_SIZE]);

    // Displays all items stored in the hash table.
    int display_all(void); 

    // Displays all items that have a TYPE matching the argument supplied character array.
    int display_type(char * match_type);

    // Displays all items that have a NAME matching the argument supplied character array.
    int display_name(char * match_name); 

    // Removes all items with a name matching the argument supplied character array.
    int remove_matched_name(char * name_to_remove); // Iterative function

    // Reads from file name that is specified in "item.h" as a constant. Places
    // information read into appropriate data fields of an item instance, and places item
    // instances into the hash table.
    int read_file();

    // Outputs the number of collisions. Intended for testing purposes.
    int collisions();

    // Outputs the number of items. Intended for testing purposes.
    int items();

    
  // ===============================================================================================
  
  private:
    node ** hash_table;
    int  table_size;
    int hash_function(char * key);
    int col_ct;
    int item_ct;

};



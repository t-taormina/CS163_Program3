// Tyler Taormina CS163
// July 2022
// Program 3

#include "Item.h"

struct node 
{
  Item item;
  node * next;
};

// Comments for .h files
// - Why you would want to use the data type
// - How to call the functions(args, return types)
// - Aimed at the application programmer

class Table 
{

  public:
    Table(int size);
    ~Table(void);
    
    int insert(char * key_value, Item & to_add);
    int retrieve(char * name_to_find, Item & found);

    int display_all(void); // for testing
    int display_all_type(char * type);
    int display_matched_name(char * name_to_match); 


    int remove_matched_name(char * name_to_remove); // Iterative function
    int retrieved_match(char * name_to_match, Item& found_item); // Iterative function
    
  // ===============================================================================================
  
  private:
    node ** hash_table;
    int  table_size;
    int hash_function(char * key);

};



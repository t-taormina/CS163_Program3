// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 3

#include "item.h"

struct node 
{
  Item item;
  node * next;

  node(){
    item = Item();
    next = nullptr;
  }
};


class Table 
{

  public:
    Table(int size);
    ~Table(void);
    
    int insert(char * key_value, Item & to_add);
    int retrieve(char * name_to_find, Item items[HASH_SIZE]);

    int display_all(void); // for testing
    int display_type(char * match_type);
    int display_name(char * match_name); 
    int read_file();
    int collisions();
    int items();

    int remove_matched_name(char * name_to_remove); // Iterative function
    
  // ===============================================================================================
  
  private:
    node ** hash_table;
    int  table_size;
    int hash_function(char * key);
    int col_ct;
    int item_ct;

};



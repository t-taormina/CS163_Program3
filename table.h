//// Tyler Taormina CS163
// taormina@pdx.edu
// July 2022
// Program 3

#include "Item.h"

int displayMenu();
int validate_menu_choice();
void processChoice (int& flag, int menu_choice, class Table & table);
int get_input(char* & arg_value);
int convert_character_array_to_int(char * arr, int & num);
int convert_yes_no(char * arr, int & num);



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
    int read_file();

    int remove_matched_name(char * name_to_remove); // Iterative function
    
  // ===============================================================================================
  
  private:
    node ** hash_table;
    int  table_size;
    int hash_function(char * key);

};



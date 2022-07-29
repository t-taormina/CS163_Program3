#include "table.h"

Table::Table(int size){}

Table::~Table(void) {}

int Table::hash_function(char * key){}
    
int Table::insert(char * key_value, const Item & to_add){}
int Table::retrieve(char * name_to_find, Item * found){}

int Table::display_all(void){} // for testing
int Table::display_all_type(char * type){}
int Table::display_matched_name(char * name_to_match){}


int Table::remove_matched_name(char * name_to_remove){} // Iterative function
int Table::retrieved_match(char * name_to_match, Item& found_item){} // Iterative functi


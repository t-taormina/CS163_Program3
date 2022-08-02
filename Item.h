// Tyler Taormina CS163
// July 2022
// Program 3

#include <iostream>
#include <cstring>
#include <cctype>

// Comments for .h files
// - Why you would want to use the data type
// - How to call the functions(args, return types)
// - Aimed at the application programmer

class Item 
{

  public:
    Item();
    ~Item();
    // p_ -> this is meant to indicate that it is the parameter item 
    Item(char * p_name, char * p_type, int p_year, char * p_description, int p_worth);
    int copy_item(Item& copy_from);
    int set_item(char * name, char * type, int year, char * description, int worth);
    int display(void);

    int retrieve_match(char * name_to_match, Item& found_item); 
    int retrieve(Item& found_item); 
    char * get_name();
    char * get_type();
    char * get_description();

  // ===============================================================================================
  private:
    char * name;
    char * type;
    int  year;
    char * description; 
    int worth;
};



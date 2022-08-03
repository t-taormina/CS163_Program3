// Tyler Taormina CS163
// taormina@pdx.edu
// July 2022
// Program 3

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

// Comments for .h files
// - Why you would want to use the data type
// - How to call the functions(args, return types)
// - Aimed at the application programmer

// Utility functions in main.cpp
const int SIZE = 100;
const char file_name[] = "data.txt";


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
    int display_type_match(char * match);
    int display_name_match(char * match);

    int retrieve_match(char * name_to_match, Item& found_item); 
    int retrieve(Item& found_item); 

  // ===============================================================================================
  private:
    char * name;
    char * type;
    int  year;
    char * description; 
    int worth;
};



// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 3

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

const int SIZE = 100;
const char file_name[] = "data.txt";
const int HASH_SIZE = 50;


class Item 
{

  public:
    Item();
    ~Item();
    
    Item(char * p_name, char * p_type, int p_year, char * p_description, int p_worth);
    int copy_item(Item& copy_from);
    int set_item(char * name, char * type, int year, char * description, int worth);
    int display(void);
    int display_type_match(char * match);
    int display_name_match(char * match);

    int retrieve_match(char * name_to_match, Item& found_item); 
    int retrieve(Item& found_item); 
    int is_match(char * name_to_match);

  // ===============================================================================================
  private:
    char * name;
    char * type;
    int  year;
    char * description; 
    int worth;
};




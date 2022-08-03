// Tyler Taormina 
// taormina@pdx.edu
// Program 3 CS163
// July 2022
#include "Item.h"


Item::Item() : name(nullptr), type(nullptr), year(0), description(nullptr), worth(0) {}


Item::~Item() 
{
  if (name != nullptr)
    delete [] name; 

  if (type != nullptr)
    delete [] type;

  if (description != nullptr)
    delete [] description;

  name = type = description = nullptr;
  year = worth = 0;
}

// Will overwrite the data of the item being used to call the function.
int Item::copy_item(Item& copy_from)
{
  // Don't copy an item that contains nullptrs. 
  if (copy_from.name == nullptr || copy_from.type == nullptr || copy_from.description == nullptr)
    return 0;

  // If the item being copied to is already holding data, delete, allocate, and set.
  if (name != nullptr) 
    delete [] name;
  if (type != nullptr)
    delete [] type;
  if (description != nullptr)
    delete [] description;

  // Allocate the proper amount of space within the arrays.
  name = new char[strlen(copy_from.name) + 1];
  type = new char [strlen(copy_from.type) + 1];
  description = new char [strlen(copy_from.description) + 1];

  // Copy from Item object passed in parameters.
  strcpy(name, copy_from.name);
  strcpy(type, copy_from.type);
  strcpy(description, copy_from.description);
  year = copy_from.year;
  worth = copy_from.worth;
  return 1;
}


int Item::set_item(char * arg_name, char * arg_type, int arg_year, char * arg_description, int arg_worth)
{
  // Do not set values for an item that has already been established.
  if (name != nullptr || 
      type != nullptr ||
      description != nullptr)
    return 0;

  // Allocate the proper amount of space within the arrays.
  name = new char[strlen(arg_name) + 1];
  type = new char [strlen(arg_type) + 1];
  description = new char [strlen(arg_description) + 1];

  // Copy parametrs into appropriate member data fields.
  strcpy(name, arg_name);
  strcpy(type, arg_type);
  strcpy(description, arg_description);
  year = arg_year;
  worth = arg_worth;
  return 1;
}


int Item::display(void)
{
  // Do not display items with nullptrs stored in members.
  if (name == nullptr || type == nullptr || description == nullptr)
    return 0;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Type: " << type << std::endl;
  std::cout << "Year: " << year << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Worth: " << worth << std::endl;
  return 1;
}


int Item::retrieve_match(char * name_to_match, Item& found_item)
{
  if (name_to_match == nullptr)
    return 0;

  int success = 1;
  if (strcmp(name_to_match, name) == 0)
  {
    if (found_item.name != nullptr ||found_item.type != nullptr || found_item.description != nullptr)
      success = 0;
    else
    {
      success  = retrieve(found_item);
    }
    return success;
  }
  else
    return 0;
}


int Item::retrieve(Item& found_item)
{
   // Verify no null values being passed
  if (found_item.name != nullptr || found_item.type != nullptr || found_item.description != nullptr)
     return 0;
 
    // Verify no data already stored in event
  if (name == nullptr || type == nullptr || description== nullptr)
     return 0;

  int success = found_item.set_item(name, type, year, description, worth);
  return success;
}



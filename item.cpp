// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 3 

// Item Class
// - This class stores 5 data fields that are meant to represent an item in a collection.
// The data fields are a name for an item, the type of the item (or what it is), the year
// the item was made, a description or condition of the item, and how much the item is
// worth. 

#include "item.h"


// Default constructor.
Item::Item() : name(nullptr), type(nullptr), year(0), description(nullptr), worth(0) {}

// Deconstructor
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


// @DEV
// Args -> empty item instance
// Returns -> 0 if the item we are copying from has nullptrs in its data members
//            1 if the function runs successfully
int Item::copy_item(Item& copy_from)
{
  // Don't copy an item that contains nullptrs. 
  if (copy_from.name == nullptr || copy_from.type == nullptr || copy_from.description == nullptr)
    return 0;

  // If the item recieving the copies is already holding data, delete, allocate, and set.
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


// @DEV
// Args -> character arrays: name, type, and description
//         integers: year and worth
// Returns -> 0 if the item we are trying to set is already holding valid values
//            1 if the function runs successfully
int Item::set_item(char * arg_name, char * arg_type, int arg_year, char * arg_description, int arg_worth)
{

  // Do not set values to nullptrs
  if (arg_name == nullptr ||
      arg_type == nullptr ||
      arg_description == nullptr)
    return 0;

  int success = 1;
  // Do not set values for an item that has already been established.
  if (name != nullptr || 
      type != nullptr ||
      description != nullptr)
    success = 0;

  else {
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
  }
    return success;
}


// @DEV
// Args -> character arrays: name to compare with data members for a match.
// Returns -> 0 if there is no match
//            1 if there is a match
int Item::is_match(char * name_to_match)
{
  // Default success indicates that the name is not a match. 
  int success = 0;
  // Success only changes if we find a match.
  if (strcmp(name_to_match, name) == 0)
    success = 1;
  return success;
}


// @DEV
// Args -> None
// Returns -> 0 if there are nullptrs stored in data members
//            1 if function runs successfully
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


// @DEV
// Args -> None
// Returns -> 0 if there are nullptrs stored in data members or there is no match
//            1 if function runs successfully
int Item::display_type_match(char * match)
{
  // Do not display items with nullptrs stored in members.
  if (name == nullptr || type == nullptr || description == nullptr || strcmp(match,type) != 0)
    return 0;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Type: " << type << std::endl;
  std::cout << "Year: " << year << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Worth: " << worth << std::endl;
  return 1;
}


// @DEV
// Args -> character array: name to find a match
// Returns -> 0 if there are nullptrs stored in data members or there is no match
//            1 if there is a match and the function runs successfully
int Item::display_name_match(char * match)
{
  // Do not display items with nullptrs stored in members.
  // Do not display if there is no match.
  if (name == nullptr || type == nullptr || description == nullptr || strcmp(match,name) != 0)
    return 0;
  // Match found.
  std::cout << "Name: " << name << std::endl;
  std::cout << "Type: " << type << std::endl;
  std::cout << "Year: " << year << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Worth: " << worth << std::endl;
  return 1;
}


// @DEV
// Args -> character array: name to match
//         Item: empty item instance 
// Returns -> 0 if there is no match or param passed argument is not empty.
//            1 if function runs successfully and there is a match
int Item::retrieve_match(char * name_to_match, Item& found_item)
{
  if (name_to_match == nullptr)
    return 0;

  int success = 0;
  if (strcmp(name_to_match, name) == 0)
  {
    success  = retrieve(found_item);
  }
  return success;
}


// @DEV
// Args -> Item: empty item instance 
// Returns -> 0 if there is nullptrs in the calling item instance or the parameter passed arg is not empty.
//            1 if function runs successfully
int Item::retrieve(Item& found_item)
{
  int success = found_item.set_item(name, type, year, description, worth);
  return success;
}



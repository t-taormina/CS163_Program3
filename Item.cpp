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
}


int Item::copy_item(const Item& copy_from)
{
  return 0;
}


int Item::create_item(char * name, char * type, int year, char * description, int worth)
{
  return 0;
}


int Item::display(void)
{
  return 0;
}


int Item::retrieve(char * name_to_match, Item& found_item)
{
  return 0;
}


int Item::retrieve(Item& found_item)
{
  return 0;
}

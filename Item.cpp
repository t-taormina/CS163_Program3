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
  // Don't copy an item that contains nullptrs. 
  if (copy_from.get_name() == nullptr || 
      copy_from.get_type() == nullptr ||
      copy_from.get_description() == nullptr)
    return 0;




  return 1;
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

char * Item::get_name()
{
  return name;
}

char * Item::get_type()
{
  return type;
}

char * Item::get_description()
{
  return description;
}

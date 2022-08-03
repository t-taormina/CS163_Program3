// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 3


#include "table.h"


Table::Table(int size)
{
  hash_table = new node * [size];
  table_size = size;
  col_ct = 0;
  item_ct = 0;
  for (int i = 0; i < table_size; i++)
    *(hash_table + i) = nullptr;
}


Table::~Table(void) 
{
  node ** ptr = hash_table;
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(ptr + i)) != nullptr)
    {
      node * head = (*(ptr + i));
      node * temp = head->next;
      while (head)
      {
        temp = head->next;
        delete head;
        head = temp;
      }
    }
  }
}

    
int Table::insert(char * key_value, Item & to_add)
{
  // Do not compute hash function if the key value argument is set to nullptr.
  if (key_value == nullptr)
    return 0;
  int success;
  int index = hash_function(key_value);
  if (*(hash_table + index) == nullptr) // Empty index in array.
  {
    (*(hash_table + index)) = new node;
    (*(hash_table + index))->next = nullptr;
    success = (*(hash_table + index))->item.copy_item(to_add);
    item_ct++;
  }
  else
  {
    node * temp = ( *(hash_table + index) );
    (*(hash_table + index)) = new node;
    success = (*(hash_table + index))->item.copy_item(to_add);
    (*(hash_table + index))->next = temp;
    item_ct++;
    col_ct++;
  }
  return success;
}



int Table::retrieve(char * name_to_find, Item & found)
{
  if (name_to_find == nullptr)
    return 0;

  int index = hash_function(name_to_find);
  int success;
  
  if (*(hash_table + index) == nullptr)
    return 0; // No nodes in index

  // Traverse non-empty index
  node * temp = (*(hash_table + index));
  while (temp && success)
  {
    success = temp->item.retrieve_match(name_to_find, found);
    temp = temp->next;
  }

  return success;
}


// Return 0 for an empty hash table. Return 1 otherwise.
int Table::display_all(void)
{
  int success = 0;
  for (int i = 0; i < table_size; i++)
  {
    if (*(hash_table + i) != nullptr)
    {
      success = 1;
      node * temp = (*(hash_table + i));
      while (temp)
      {
        temp->item.display();
        temp = temp->next;
      }
    }
  }
  return success;
} 
                               

int Table::display_type(char * match_type)
{
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(hash_table + i)) != nullptr)
    {
      node * head = (*(hash_table + i));
      node * temp;
      while (head)
      {
        temp = head->next;
        head->item.display_type_match(match_type);
        head = temp;
      }
    }
  }

  return 1;
}


int Table::display_name(char * match_name)
{
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(hash_table + i)) != nullptr)
    {
      node * head = (*(hash_table + i));
      node * temp;
      while (head)
      {
        temp = head->next;
        head->item.display_name_match(match_name);
        head = temp;
      }
    }
  }
  return 0;
}


int Table::remove_matched_name(char * name_to_remove)
{
  return 0;
}



// PRIVATE FUNCTIONS
// =================================================================================


int Table::hash_function(char * key)
{
  int hash = 0;
  int key_length = strlen(key);
  for (int i = 0; i < key_length; i++)
  {
    if (int(key[i]) % 2 == 0 )
    {
      int num = int(key[i]) * 13 * 2;
      hash += (num * num);
    }
      
    else
      hash += int(key[i]) * 7 * 33;
  }

  return hash % table_size;
}


int Table::read_file()
{
  // All local variables that will be used to gather input

  ifstream inFile;
  inFile.open(file_name);
  if (!inFile.is_open())
    return 0;
  char name[SIZE];
  char type[SIZE];
  //char year[SIZE];
  char description[SIZE];
  //char worth[SIZE];

  int year_int = 0;
  int worth_int = 0;
  int check = 0;


  inFile.get(name, SIZE, '|');
  inFile.ignore(SIZE, '|');
  while (!inFile.eof())
  {
    inFile.get(type, SIZE, '|');  
    inFile.ignore(SIZE, '|');
    inFile >> year_int;
    inFile.ignore(SIZE, '|');
    //std::inFile.get(year, SIZE, '|');
    inFile.get(description, SIZE, '|');
    inFile.ignore(SIZE, '|');
    inFile >> worth_int;
    inFile.ignore(SIZE, '\n');
    //std::inFile.get(worth, SIZE, '\n');

    //check = convert_character_array_to_int(year, year_int);
    //check = convert_character_array_to_int(worth, worth_int);

    Item item;
    item.set_item(name, type, year_int, description, worth_int);
    insert(name, item);
    inFile.get(name, SIZE, '|');
    inFile.ignore(SIZE, '|');
  }
  inFile.close();
  return 1;
}


int Table::collisions()
{
  cout << "Collisions: " << col_ct <<  endl;
  return 0;
}


int Table::items()
{
  cout << "Items: " << item_ct <<  endl;
  return 0;
}

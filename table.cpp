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
  for (int i = 0; i < table_size; i++)
  {
    if ((*(hash_table + i)) != nullptr) {
      node * head = (*(hash_table + i));
      node * temp;
      while (head) {
        temp = head->next;
        delete head;
        head = temp;
      }
      head = temp = nullptr;
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



int Table::retrieve(char * name_to_find, Item items[HASH_SIZE])
{
  if (name_to_find == nullptr)
    return 0;

  int index = hash_function(name_to_find);
  int success = 0;
  
  if (*(hash_table + index) == nullptr)
    return 0; // No nodes in index

  // Traverse non-empty index
  node * temp = (*(hash_table + index));
  while (temp)
  {
    Item found;
    success+= temp->item.retrieve_match(name_to_find, found);
    items[success - 1].copy_item(found);
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

// Deletes all of a certain name and returns the number of 
// items removed.  
int Table::remove_matched_name(char * name_to_remove)
{
  int index = hash_function(name_to_remove);
  int success = 0;
  if ((*(hash_table + index)) == nullptr)
    return success;
  node * head = (*(hash_table + index));
  node * temp;

  // will remove multiple matches in a row at the head
  while (head && head->item.is_match(name_to_remove)) {
    temp = head->next;
    delete head;
    head = temp;
    success++;
  }

  node * prev = head;
  node * current = head->next;
  // After we determine there isn't a match in the head node and we, will check all nodes
  // left and drag a previous pointer for reconnecting the links if we find a match.
  while (current) {
    temp = current->next; // on the last node this will be nullptr by the default constructor
    if (current->item.is_match(name_to_remove)) {
        delete current;
        current = temp;
        prev->next = current;
        success++;
    }
    prev = current; 
    current = temp;
  }
  return success;
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

  ifstream inFile(file_name); // file_name is a constant defined in item.h
  if (!inFile.is_open())
    return 0;

  int year; int worth; int check;
  year = worth = check = 0;
  char * name = new char [SIZE];

  inFile.get(name, SIZE, '|');
  inFile.ignore(SIZE, '|');
  while (!inFile.eof())
  {
    char * type = new char [SIZE];
    char * description = new char [SIZE];

    inFile.get(type, SIZE, '|');  
    inFile.ignore(SIZE, '|');
    inFile >> year;
    inFile.ignore(SIZE, '|');
    inFile.get(description, SIZE, '|');
    inFile.ignore(SIZE, '|');
    inFile >> worth;
    inFile.ignore(SIZE, '\n');

    Item item;
    item.set_item(name, type, year, description, worth);
    insert(name, item);

    delete [] name;
    delete [] type;
    delete [] description;

    name = new char [SIZE];
    inFile.get(name, SIZE, '|');
    inFile.ignore(SIZE, '|');
  }
  delete [] name;
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

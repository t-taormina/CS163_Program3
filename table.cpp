#include "table.h"

Table::Table(int size)
{
  hash_table = new node * [size];
  table_size = size;
  node ** ptr = hash_table;
  for (int i = 0; i < table_size; i++)
    *(ptr + i) = nullptr;
}


Table::~Table(void) 
{
  node ** ptr = hash_table;
  for (int i = 0; i < table_size; i++)
  {
    if ( *(ptr + i) != nullptr)
    {
      node * head = (*(ptr + i));
      node * temp = head->next;
      while (head)
      {
        temp = head->next;
        delete head;
        head = nullptr;
        head = temp;
        temp = temp->next;
      }
    }
  }
}

    
int Table::insert(char * key_value, Item & to_add)
{
  // Do not compute hash functino if the key value argument is set to nullptr.
  if (key_value == nullptr)
    return 0;
  int success;
  int index = hash_function(key_value);
  if (*(hash_table + index) == nullptr) // Empty index in array.
  {
    *(hash_table + index) = new node;
    success = (*(hash_table + index))->item.copy_item(to_add);
  }
  else
  {
    node * temp = ( *(hash_table + index) );
    *(hash_table + index) = new node;
    success = (*(hash_table + index))->item.copy_item(to_add);
    (*(hash_table + index))->next = temp;
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
                               

int Table::display_all_type(char * type)
{
  return 0;
}


int Table::display_matched_name(char * name_to_match)
{
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
      hash += int(key[i]) * 3;
    else
      hash += int(key[i]) * 7;
  }

  return hash % table_size;
}

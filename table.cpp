// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 3

// Table Class
// - This class makes use of an array of head nodes. Each head node has the capability to
// extend into a linear linked list. By default each array index will hold a head node
// that is set to a nullptr. How indexes are filled is determined by a hash function that
// uses the name of an Item to calculate a "random" index. When collisions occur, nodes
// are added at the head. 


#include "table.h"


// @DEV Default constructor
// Args -> integer: size of hash table array
// Returns -> none, initiliazes each index (head node) to nullptr
Table::Table(int size)
{
  hash_table = new node * [size];
  table_size = size;
  col_ct = 0;
  item_ct = 0;
  for (int i = 0; i < table_size; i++)
    *(hash_table + i) = nullptr; // (head = nullptr)
}


// Deconstructor
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

 
// @DEV
// Args -> character array: key value used in hash function to calculate index 
//         Item: populated item to store in table
// Returns -> 0 if key values passed is a nullptr.
//            1 if the function runs successfully
int Table::insert(char * key_value, Item & to_add)
{
  // Do not compute hash function if the key value argument is set to nullptr.
  if (key_value == nullptr)
    return 0;
  int success;
  int index = hash_function(key_value);

  // Empty index in array.
  if (*(hash_table + index) == nullptr)   {
    (*(hash_table + index)) = new node;
    (*(hash_table + index))->next = nullptr;
    success = (*(hash_table + index))->item.copy_item(to_add);
    item_ct++;
  }

  // Index already contains a Node. Set new item in head node and push everything else
  // back. 
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



// @DEV
// Args -> character array: name to match 
//         Item array : Array to hold all items that are matched
// Returns -> 0 if character array passed is a nullptr or there is no match
//            Num > 0: indicates the number of items matched 
int Table::retrieve(char * name_to_find, Item items[HASH_SIZE])
{
  if (name_to_find == nullptr)
    return 0;

  // find index where name should be
  int index = hash_function(name_to_find);
  int success = 0;
  
  if (*(hash_table + index) == nullptr)
    return 0; // No nodes in index

  // Traverse non-empty index
  node * temp = (*(hash_table + index));
  while (temp)
  {
    // If found, increment success which will count the number of matches
    Item found;
    success+= temp->item.retrieve_match(name_to_find, found);
    items[success - 1].copy_item(found);
    temp = temp->next;
  }

  return success;
}


// @DEV
// Args -> none 
// Returns -> total number of items stored 
int Table::display_all(void)
{
  int success = 0;
  for (int i = 0; i < table_size; i++)
  {
    // Check for empty head node
    if (*(hash_table + i) != nullptr)
    {
      node * temp = (*(hash_table + i));
      while (temp)
      {
        temp->item.display();
        temp = temp->next;
        success++;
      }
    }
  }
  return success;
} 
                               

// @DEV
// Args -> character array: type to match 
// Returns -> number of type matches found in the table.
int Table::display_type(char * match_type)
{
  int success = 0;
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(hash_table + i)) != nullptr)
    {
      node * head = (*(hash_table + i));
      node * temp;
      while (head)
      {
        temp = head->next;
        if (head->item.display_type_match(match_type)) 
          success++;
        head = temp;
      }
    }
  }

  return success;
}


// @DEV
// Args -> character array: name to match 
// Returns -> number of name matches found in the table.
int Table::display_name(char * match_name)
{
  int success = 0;
  for (int i = 0; i < table_size; i++)
  {
    if ( (*(hash_table + i)) != nullptr)
    {
      node * head = (*(hash_table + i));
      node * temp;
      while (head)
      {
        temp = head->next;
        if (head->item.display_name_match(match_name))
          success++;
        head = temp;
      }
    }
  }
  return success;
}


// @DEV - This function will remove ALL name matches found in the table.
// Args -> character array: name to match 
// Returns -> number of name matches found and removed from the table.
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


// @DEV - Calculates an index based on the characters passed in the character array
//        argumeent.
// Args -> character array: key used for calculation 
// Returns -> integer from calculation
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


// @DEV - Reads data file into items and places items in table.
// Args -> none
// Returns -> 0 if unable to open file
//            1 if function runs successfully
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

// @DEV - outputs number of collisions for testing purposes.
// Args -> none
// Returns -> 0 for function running successfully 

int Table::collisions()
{
  cout << "Collisions: " << col_ct <<  endl;
  return 0;
}

// @DEV - outputs number of items for testing purposes.
// Args -> none
// Returns -> 0 for function running successfully 
int Table::items()
{
  cout << "Items: " << item_ct <<  endl;
  return 0;
}

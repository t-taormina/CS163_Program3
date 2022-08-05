// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 3 

#include "client.h"


// Program runner.
int run() {
  Table table(HASH_SIZE);// hash size variable is constant in item.h

  int flag = 1;
  
  while(flag > 0)
    {
      displayMenu();
      int menu_choice = validate_menu_choice();
      processChoice(flag, menu_choice, table);
    }
  return 0;
}

// Displays the menu of functions for the user to choose from.
// Returns-> the integer value for the menu choice 
int displayMenu() {
    std::cout << "==================================================================\n";
    std::cout << "                         MENU" << std::endl;
    std::cout << "==================================================================\n";

    std::cout << "===============================\n";
    std::cout << "1) Read items from file\n";
    std::cout << "2) Display all items in table \n";
    std::cout << "3) Display match by name\n";
    std::cout << "4) Display all match by type\n";
    std::cout << "5) Remove by name\n";
    std::cout << "6) Retrieve match by name\n";
    std::cout << "7) Add a collectable\n";
    std::cout << std::endl;
    std::cout << "0) Exit Program\n";
    std::cout << "Enter: ";
    return 0;
}


// Provides option processing for the menu 
void processChoice (int& flag, int menu_choice, Table & table)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      // Read file into events and output.
      case 1:
        { 
          table.read_file();
          table.collisions();
          table.items();
          break;
        }

      // Display full table. 
      case 2: 
        {
          table.display_all();
          break;
        }

      // Display name matches.
      case 3:
        {
          char * match = new char[SIZE];
          cout << "Please enter the name of shoe to display: ";
          get_input(match);
          table.display_name(match);
          delete [] match;
          break;         
        }

      // Display type matches.
      case 4: 
        {
          char * match = new char[SIZE];
          cout << "Please enter the type of shoe to display: ";
          get_input(match);
          table.display_type(match);
          delete [] match;
          break;
        }

      // Remove name matches.
      case 5: 
        {
          char * match = new char[SIZE];
          cout << "Please enter the name of shoe to remove from the list (will remove all shoes with matching name: ";
          get_input(match);
          int del_items = table.remove_matched_name(match);
          cout << "# items deleted: " << del_items << endl;
          delete [] match;
          break;
        }

      // Retrieve name matches.
      case 6: 
        {
          Item items[HASH_SIZE];
          char * match = new char[SIZE];
          cout << "Please enter the name of shoes to retrieve: ";
          get_input(match);
          int matches = table.retrieve(match, items);
          cout << "# of matches: " << matches << endl;
          for (int i = 0; i < matches; i++)
            (*(items + i)).display();
          delete [] match;
          break;
        }

      // Add an item to the table.
      case 7:
        {
          Item item;
          char * key = new char[SIZE];
          make_item(key, item);
          table.insert(key, item);
          delete [] key;
          break;
        }

      // Exit
      case 0:
        {
          std::cout << "Are you sure you want to exit?" << std::endl;
          proceed = no;
          break;
        }

      // Prevent undesired outputs from having an effect.
      default:
          break;
    }

    if (proceed == no)
    {
      std::cout << "Enter 0 to end program.\n" << std::endl;
      std::cout << "Enter any other number to continue program.\n" << std::endl;
      std::cin >> flag;
      std::cin.ignore(SIZE, '\n');
    }
}


// Returns-> Integer value for the menu choice
int validate_menu_choice()
{
  int menu_choice_int = 0;
  cin >> menu_choice_int;
  std::cin.ignore(SIZE, '\n');
 
  while (menu_choice_int > 7 || menu_choice_int < 0) {
    cout << "Please select a valid menu item." << endl;
    cin >> menu_choice_int;
  }
  return menu_choice_int;
}


// Create an item using user input.
int make_item(char* & key, Item & item) {
  char * name = new char[SIZE];
  char * type = new char[SIZE];
  char * description = new char[SIZE];
  int year;
  int worth;
  int checker;

  cout << "Please enter the name of the item to add to the list: ";
  checker = get_input(name);

  cout << "Please enter the type of the item: ";
  checker = get_input(type);

  cout << "Please enter the year the item was made: ";
  std::cin >> year;
  std::cin.ignore(SIZE, '\n');

  cout << "Please enter a description of the item: ";
  checker = get_input(description);

  cout << "Please enter the worth of the item: ";
  std::cin >> worth;
  std::cin.ignore(SIZE, '\n');

  item.set_item(name, type, year, description, worth);
  strcpy(key,name);
  delete [] name;
  delete [] type;
  delete [] description;
  return checker;
}


// Gets user input from console and stores in character array.
int get_input(char* & value)
{
  std::cin.get(value, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
  return 1;
}


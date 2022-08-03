// Tyler Taormina CS163
// June, 2022
// Program 3- Stack and queues at the Fair

// GITHUB : https://github.com/till-t/CS163_Program3.git
//
// things to do:
//     - 

// Requirements for test plan
// ===================================================================================================
// Test for item class
// - 
 
#include "table.h"


int main()
{
  Table table(20);

  int flag = 1;
  
  while(flag > 0)
    {
      displayMenu();
      int menu_choice_int = validate_menu_choice();
      processChoice(flag, menu_choice_int, table);
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
    std::cout << "8) \n";
    std::cout << std::endl;
    std::cout << "0) Exit Program\n";
    std::cout << "Enter: ";
    return 0;
}


// Returns-> Integer value for the menu choice
int validate_menu_choice()
{
  char * menu_choice = new char[SIZE];
  int menu_choice_int = 0;
  get_input(menu_choice);
  int check = convert_character_array_to_int(menu_choice, menu_choice_int);
  if (menu_choice_int > 8 || menu_choice_int < 0) 
    check = 0;

  while(!check)
  {
    delete [] menu_choice;
    menu_choice_int = 0;
    menu_choice = new char[SIZE];
    std::cout << "Only numbers are accepted." << std::endl << "Please enter a valid number: ";
    get_input(menu_choice);
    check = convert_character_array_to_int(menu_choice, menu_choice_int);
    if (menu_choice_int > 8 || menu_choice_int < 0) 
      check = 0;
  }

  delete [] menu_choice;
  return menu_choice_int;
}


// Provides option processing for the menu 
void processChoice (int& flag, int menu_choice, Table & table)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      // read file into events and output
      case 1:
        { 
          table.read_file();
          table.collisions();
          break;
        }

      // display table 
      case 2: 
        {
          table.display_all();
          break;
        }

      case 3:
        {
          char * match = new char[SIZE];
          cout << "Please enter the name of shoe to display: ";
          get_input(match);
          table.display_name(match);
          delete [] match;
          break;         
        }

      case 4: 
        {
          char * match = new char[SIZE];
          cout << "Please enter the type of shoe to display: ";
          get_input(match);
          table.display_type(match);
          delete [] match;
          break;
        }

      case 5: 
        {
         break;
        }

      case 6: 
        {
          break;
        }

      case 7:
        {
         break;
        }

      case 8: 
        {
         break;
        }

      case 0:
        {
          std::cout << "Are you sure you want to exit?" << std::endl;
          proceed = no;
          break;
        }

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




  /*

  // Character array conversion to integers begins here
  int check = convert_character_array_to_int(rating, rating_int);
  while(!check)
  {
    delete [] rating;
    rating = new char[SIZE];
    cout << "Please enter a rating 1 - 10. 1 being the worst ever and 10 being the best: ";
    get_input(rating);
    rating_int = 0;
    check = convert_character_array_to_int(rating, rating_int);
  }

  check = convert_yes_no(repeatable, repeatable_int);
  while(!check)
  {
    delete [] repeatable;
    repeatable = new char[SIZE];
    cout << "Please enter a Y/y or N/n: ";
    get_input(repeatable);
    repeatable_int = 0;
    check = convert_yes_no(repeatable, repeatable_int);
  }

  event.set_event(name, description, review, rating_int, repeatable_int);
  */
  



// Converts character array to integer 
// Returns-> 0 if the array contains characters other than integers 0-9
//           1 if the array only contains digits 0-9 and was successfully converted
int convert_character_array_to_int(char * arr, int & num)
{ 
  for (int i = 0; i < strlen(arr); i++)
  {
    if (int(arr[i]) < 48 || int(arr[i]) > 57)
      return 0;
    num = num * 10 + (int(arr[i]) - 48);
  }
  return 1;
}


// Converts characters Y/y to 1 and N/n to 0 
// Returns-> 0 if the array is greater than 1 character in length or the character is neither Y/y or N/n
//           1 if a Y/y is entered
//           2 if a N/n is entered
int convert_yes_no(char * arr, int & num)
{
  int success = 0;
  if (strlen(arr) > 1)
    return 0;

  int i = 0;

  // ASCII values for Y = 89 and y = 121
  if (int(arr[i]) == 89 || int(arr[i]) == 121)
  {
    num = 1;
    success = 1;
  }
  // ASCII values for N = 78 and n = 110
  if (int(arr[i]) == 78 || int(arr[i]) == 110)
  {
    num = 0;
    success = 2;
  }
  return success;
}


int get_input(char* & value)
{
  std::cin.get(value, SIZE, '\n');
  std::cin.ignore(SIZE, '\n');
  return 1;
}


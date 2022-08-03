#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector<string> name;
  vector<string> type;
  vector<int> year;
  vector<string> description;
  vector<int> worth;

  for (int i = 1971; i < 2022; i++)
    year.push_back(i);

  for (int x = 1; x < 11; x++)
    worth.push_back(x*100);


  string line;
  ifstream ifile ("text_files/collectibles.txt");
  if (ifile.is_open())
  {
    while (getline(ifile,line))
      name.push_back(line);

    ifile.close();
  }
  else cout << "unable to open name file" << endl;
    

  ifstream type_file ("text_files/type.txt");
  if (type_file.is_open())
  {
    while (getline(type_file,line))
      type.push_back(line);

    type_file.close();
  }
  else cout << "unable to open type file" << endl;


  ifstream condition_file("text_files/condition.txt");
  if (condition_file.is_open())
  {
    while (getline(condition_file,line))
      description.push_back(line);

    condition_file.close();
  }
  else cout << "unable to open des file" << endl;

  //for (int l = 0; l < name.size(); l++)
   // cout << name[l] << endl;

  ofstream file ("data.txt");
  if (!file.is_open())
    cout << "unable to open output file" << endl;
  

  int name_index = 0;
  int type_index = 0;
  int year_index = 0;
  int description_index = 0;
  int worth_index = 0;
  
  for (int k = 0; k < 1000; k++)
  {

    if (name_index == name.size())
     name_index = 0; 

    if (type_index == type.size())
     type_index = 0; 

    if (year_index == year.size())
     year_index = 0; 

    if (description_index == description.size())
     description_index = 0; 

    if (worth_index == worth.size())
     worth_index = 0; 
    
    file << name[name_index] << "|" << type[type_index] << "|" << year[year_index] << "|" << description[description_index] << "|" << worth[worth_index] << "\n";

    
    name_index++;
    type_index++;
    year_index++;
    description_index++;
    worth_index++;

  }

  file.close();
  return 0;
}




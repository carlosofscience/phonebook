// source code for Calculator class
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include "Phonebook.h"

using namespace std;

void Phonebook::run()
{
  string filename = "";
  cout << "Name of phonebook file to read in: ";
  cin >> filename;
  this->phonebookData = readPhoneBook(filename);

  if(phonebookData.length() > 0)
  {
    cout << "Phonebook successfully read in!" << endl;
  }

  string userInput = "";

  while (true)
  {
    cout << "Please enter person to search for: ";
    cin >> userInput;
    if (userInput == ".") break;
    cout << getContactByName(userInput) << endl;
  }


  cout << "Thank you for using this program!" << endl;
}

string Phonebook::readPhoneBook(string filename, int resuriveDepth)
{
  string line;
  int lineNum = 0, contactQuantity = 0;
  ifstream file(filename.c_str());
  string contancts;

  // cout << "Attempting to read file: \"" << filename << "\"" << '\n';

  //first of all find out how many contacts are there throught all the phonebook's files
  if (file.is_open())
  {
    while (getline(file, line))
    {
      if (!lineNum)
      {
        int size = 0;
        stringstream linestream(line);
        linestream >> size;
        contactQuantity += size;
        // cout << filename << " file size is: " << contactQuantity << '\n';
      }
      else
      {
        //skipping the first line since is reserved for file size and not actual contact data
        int nestedPhoneBookPos = 0;
        string PHONE_BOOK_TAG = "PHONEBOOK-FILE";
        nestedPhoneBookPos = line.find(PHONE_BOOK_TAG);

        if (nestedPhoneBookPos == -1)
        {
          contancts += line + "\n";
        }
        else
        {
          if (resuriveDepth < 3)
          {
            string nestedPhoneBookFileName = line.substr(nestedPhoneBookPos + PHONE_BOOK_TAG.length(), line.length() - 1);

            nestedPhoneBookFileName = replace(nestedPhoneBookFileName, " ", "");
            // cout << "\nReading nested phone book: " << nestedPhoneBookFileName << '\n';
            contancts += readPhoneBook(nestedPhoneBookFileName, resuriveDepth + 1);
            // cout << "returning to read: " << filename << endl;
          }
          else
          {
            //stop reading and return value
            // cout << "recursive loop depth of (" << resuriveDepth << ") files as been reached!" << endl;
            return "";
          }
        }
      }

      // cout << line << '\n';
      lineNum++;
    }
    // cout << "Closing file: " << filename << endl;
    file.close();
  }
  else
  {
    cout << "Unable to open file!" << endl;
  }

  return contancts;
}

std::string Phonebook::replace(std::string string, std::string toReplace, std::string toBeReplaced)
{

  for (int index = string.find(toReplace); index >= 0; index = string.find(toReplace))
  {
    if (toBeReplaced == "")
    {
      string.erase(index, 1);
    }
    else
    {
      string.replace(index, toBeReplaced.length(), toBeReplaced);
    }
  }

  return string;
}

std::string Phonebook::getContactByName(std::string name)
{
  string target = "";
  for (int index = 0; index < name.length(); index++)
  {
    char character = name[index];
    target += std::tolower(character);
  }

  // cout << "-finding a match (" << target.length() << ") for: " << target << endl;

  string wordMatch = "";
  int matchedEntries = 0;

  string line;
  std::istringstream book_stream(this->phonebookData);

  while (getline(book_stream, line))
  {
    for (int i = 0; i < line.length(); i++)
    {
      char character = std::tolower(line[i]);

      // cout << character << " == " << target[matchedEntries] << " = " << (character == target[matchedEntries]) << endl;

      if (character == target[matchedEntries])
      {
        if (matchedEntries < target.length() - 1)
        {
          matchedEntries++;
        }
        else
        {
          //found index of word, can exit loop
          // cout << "found a match for \"" << target << "\" at line " << i << endl;
          return line;
        }
      }
      else
      {
        //reset matches
        matchedEntries = 0;
      }
    }
  }

  return "***No Entry found.***";
}

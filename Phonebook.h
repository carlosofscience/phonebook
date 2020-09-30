// header file for Phonebook class
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>

class Phonebook
{
private:
  std::string phonebookData;
  std::string replace(std::string string, std::string toReplace, std::string toBeReplaced);

public:
  void run();
  std::string readPhoneBook(std::string filename, int resuriveDepth = 0);
  std::string getContactByName(std::string name);
};

#endif
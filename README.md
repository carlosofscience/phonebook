# phonebook
C++98 terminal program that reads in phone-book file and prompts user for a non-case sensitive search of the contacts.

The program prompts user for the phonebook file to be entered, the program will limit the input files to 3 and if successful then it will read the contacts within the files recursively an continue to prompt for a name to search in the phonebook data loaded to memory allowing non-case sensitive search. Alternatively, the user can opt out the program by typing a dot '.' or continue to search for a name.

# Compile instructions
First make sure you can compile c++98. In my case I used ```g++ (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4```. Then, run the following command in the terminal to compile the program:

    g++ main.cpp Phonebook.cpp -o main.exe

This command will create an executable called ```main.exe```:

    ./main.exe
    
# Objectives

To practice and learn how to implement recursion with I/O files in C++98 programming language. 
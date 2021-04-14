#include <iostream>
#include <fstream>
#include <algorithm>
using std::cout, std::endl, std::cin, std::string, std::ofstream;

int main(int argc, char *argv[])
{
  if (argc == 1) {
    throw std::runtime_error("No input filename found; Please provide one as the first argument when invoking this program!");
  }
  ofstream file;
  file.open(argv[1]);

  bool cont = true;
  do{
    // My Variables
    string user_input;
    int count_one;
    int i;

    // Creating a menu
    cout << "*** Main Menu ***" << endl;
    cout << "\n1. Record some names\nQ. Quit" << endl;
    cout << "Enter your choice: ";
    cin.clear();
    cin >> user_input;

    // Transforms string to lowercase
    transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);
    // If user selects option 1
    if (user_input == "1"){
      // Asking user the amount of names desired to record
      cout << "Okay, how many names would you like to record? ";
      cin.clear();
      cin >> count_one;
      cout << "Alright, recording " << count_one << " names." << endl;

      // Creating for loop for adding names to file
      for (i = 1; i <= count_one; i++){
        string name_one;
        cout << "(" << i << " of " << count_one << ") Please enter the next name: ";
        cin.clear();
        cin >> name_one;
        cout << "Thank you. Recording the name \"" << name_one << "\" to disk" << endl;
        // Writing name one to the file names.db
        file << name_one << endl;
      }
      // Finishing message for option 1
      cout << "You have finished all " << count_one << " names. Returning to main menu." << endl;

    }
    // User selects the option to quit
    else if (user_input == "quit" || user_input == "q") {
      cont = false;
      cout << "Okay, quitting!" << endl;
    }
    else{
      cout << "Invalid choice!" << endl;
    }

  } while(cont);
  return 0;
}

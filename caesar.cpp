#include <cctype>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

int main(int argc, char** argv) {
  if(argc != 3 || (strcmp(argv[1],"-e") != 0 && strcmp(argv[1],"-d") != 0)) 
  { //If the user provides the wrong number of command line arguments
    //if the first argument is not expected
    //if the second argument is not composed entirely of the digits 0 through 9
    usage();
    return 1;
  }
    //check if key is a digit
  string strKey = argv[2];
  for(char c : strKey)
  {
    if(!isdigit(c))
    {
      usage();
      return 1;
    }
  }
  //check if key is negative
  int intKey = atoi(argv[2]);
  if(intKey < 0)
  {
    usage();
    return 1;
  }
  int key = atoi(argv[2])%26; //key is a multiple of 26
  //user input
  string input = "";
  while (getline(cin, input)) {
    if (strcmp(argv[1], "-e") == 0) {
      // encrypt shift right
      for (size_t i = 0; i < input.length(); i++) {
        if (islower(input[i])) {
          input[i] = char((input[i] - 'a' + key) % 26 + 'a');
        } else if (isupper(input[i])) {
          input[i] = char((input[i] - 'A' + key) % 26 + 'A');
        }
      }
    } else if (strcmp(argv[1], "-d") == 0) {
      // decrypt shift left
      for (size_t i = 0; i < input.length(); i++) {
        if (islower(input[i])) {
          input[i] = char((input[i] - 'a' - key + 26) % 26 + 'a');
        } else if (isupper(input[i])) {
          input[i] = char((input[i] - 'A' - key + 26) % 26 + 'A');
        }
      }
    }
    cout << input << endl;
  }
  return 0;
}

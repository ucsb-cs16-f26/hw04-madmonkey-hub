#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

int main(int argc, char** argv) {
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
  if(argc != 3 || (strcmp(argv[1],"-e") != 0 && strcmp(argv[1],"-d") != 0)) {    //If the user provides the wrong number of command line arguments
    //if the first argument is not expected
    //if the second argument is not composed entirely of the digits 0 through 9
    usage();
    return 1;
  }
  //user input
  string input = "";
  //getline(isstream& input,string& stringVariable)
  //stores each input line into vector
  while (getline(cin, input)) 
  {
    int key = atoi(argv[2])%26; //key is a multiple of 26
    //size_t means size type and is used to represent the sizes and counts of objects
    if(strcmp(argv[1],"-e"))
    {
      for(size_t i=0;i<input.length();i++)
      {
        if(islower(input[i])) input[i] = char((input[i] - 'a' + key) % 26 + 'a');
        if(isupper(input[i])) input[i] = char((input[i] - 'A' + key) % 26 + 'A');
      }
    }
    if(strcmp(argv[1],"-d"))
    {
      for(size_t i=0;i<input.length();i++)
      {
        if(islower(input[i])) input[i] = char((input[i] - 'a' + key) % 26 - 'a');
        if(isupper(input[i])) input[i] = char((input[i] - 'A' + key) % 26 - 'A');
      }
    }
    cout << input << endl;
  }
  return 0;
  
}

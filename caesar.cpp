#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

bool isValidNumber(const char* str) {
    if (str == nullptr || *str == '\0') return false;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

int main(int argc, char** argv) {
  if(argc != 3 || (strcmp(argv[1],"-e") != 0 && strcmp(argv[1],"-d") != 0) || atoi(argv[2]) < 0 || !isValidNumber(argv[2])) {    //If the user provides the wrong number of command line arguments
    //if the first argument is not expected
    //if the second argument is not composed entirely of the digits 0 through 9
    usage();
    return 1;
  }
  //user input
  vector<string> input;
  string input_line = "";
  //getline(isstream& input,string& stringVariable)
  //stores each input line into vector
  while (getline(cin, input_line)) 
  {
      if (input_line.empty())
      {
          break; //stops taking input when user enters empty line
      }
      input.push_back(input_line);
  }
  int size = input.size(); //size of input vector
  int key = atoi(argv[2])%26; //key is a multiple of 26
  vector<string> encrypt;
  vector<string> decrypt;
  for(int i=0;i<size;i++)
  {
    string encrypt_line="";
    string decrypt_line="";
    //size_t means size type and is used to represent the sizes and counts of objects
    for(size_t j=0;j<input[i].length();j++)
    {
      //shift uppercase letters
      if(isupper(input[i][j])) 
      {
        // When encrypting, all English letters (a through z and A through Z) should be “rotated right” by the user-supplied key 
        encrypt_line += char((input[i][j] - 'A' + key) % 26 + 'A');
        //When decrypting, all letters should be rotated left.
        decrypt_line += char((input[i][j] - 'A' - key) % 26 + 'A');
      }
      //shift lowercase letters
      else if(islower(input[i][j])) 
      {
        // When encrypting, all English letters (a through z and A through Z) should be “rotated right” by the user-supplied key 
        encrypt_line += char((input[i][j] - 'a' + key) % 26 + 'a');
        //When decrypting, all letters should be rotated left.
        decrypt_line += char((input[i][j] - 'a' - key) % 26 + 'a');
      }
      else
      {
        encrypt_line += input[i][j];
        decrypt_line += input[i][j];
      }
    }
    encrypt.push_back(encrypt_line);
    decrypt.push_back(decrypt_line);
  }

  for(int i=0;i<size;i++)
  {
    //print out original input
    cout << input[i] << endl;
    if(strcmp(argv[1],"-e")==0)
    {
      //print encrypt
      cout<< encrypt[i] << endl;
    }
    else if(strcmp(argv[1],"-d")==0)
    {
      //print decrypt
      cout<< decrypt[i] << endl;
    }
  }
}

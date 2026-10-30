#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void usage() {
  std::cout << "USAGE: substitution [-ed] [key]\n";
}

int main(int argc, char** argv) {
  if(argc != 3 || (strcmp(argv[1],"-e") != 0 && strcmp(argv[1],"-d") != 0)) {
    usage();
    return 1;
  }
  //key must be 26 characters
  string key = argv[2];
  if(key.length()!=26)
  {
    usage();
    return 1;
  }
  //key must be alphabet characters not symbols or letters
  for(size_t i = 0;i<key.length();i++)
  {
    if(!isalpha(key[i]))
    {
        usage();
        return 1;
    }
    //no repeating characters
    for(size_t j=i+1;j<key.length();j++)
    {
        //tolower so capitalization doesn't matter
        if(tolower(key[i])==tolower(key[j]))
        {
            usage();
            return 1;
        }
    }
  }
  // user input
  string input = "";
  while (getline(cin, input))
  {
    if(strcmp(argv[1],"-e"))
    {
        //size_t for unsigned int
        for(size_t i = 0;i<input.length();i++)
        {
            //lowercase encryption
            if(islower(input[i]))
            {
                int index = input[i] - 'a';
                input[i] = tolower(argv[2][index]);
            }
            //uppercase encryption
            else if(isupper(input[i]))
            {
                int index = input[i] - 'A';
                input[i] = toupper(argv[2][index]);
            }
        }
    }
    else if(strcmp(argv[1],"-d"))
    {
        for(size_t i=0;i<input.length();i++)
        {
            //checks if character is alphabetical letter not symbols
            //if(islower(input[i])||isupper(input[i]))
            //{
                //get index of key collarlated to input character
                int index = -1;
                for(int j=0;j<26;j++)
                {
                    if(toupper(key[j])==toupper(input[i]))
                    {
                        index=j;
                        break;
                    }
                }
                if(index!=-1)
                {
                    //decrypt lowercase
                    if(islower(input[i])) input[i] = char('a' + index);
                    //decrypt uppercase
                    if(isupper(input[i])) input[i] = char('A' + index);
                }
            //}
        }
    }
    cout << input << endl;
  }
  return 0;
}

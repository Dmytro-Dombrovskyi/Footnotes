///   Програма отримує текст вигляду:
///   "Today i have no money, and just *walking on the street. etc..."
///   Программа повинна розпізнавати виноски типу * і заміняти
///   їх на числову відповідно:


#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
void ReadFromFile(std::string FileName, std::string &copyString);
using namespace std;

int main()
{
   std::string filename = "data.txt";
   std::string workingString;
   try
   {
      ReadFromFile(filename, workingString);
   }
   catch(std::ios_base::failure &ex) { std::cerr << ex.what(); }
   catch(std::exception &ex) { std::cerr << ex.what(); }

   std::cout << workingString;
   // std::cin.get();
   return 0;
}

void ReadFromFile(std::string FileName, std::string &copyString)
{
   std::fstream File;
   File.open(FileName.c_str(), std::ios_base::in);
   if(!File.is_open())
      throw std::ios_base::failure("couldn't open file!");
   else //if(File.is_open())
   {
      char ch;
      while(File.get(ch)) copyString.push_back(ch);

      if(File.eof())
         File.clear();
      else
         throw std::ios_base::failure("Fail read data!");

      File.close();
   }
}

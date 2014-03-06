///   Програма отримує текст вигляду:
///   "Today i have no money, and just *walking on the street. etc..."
///   Программа повинна розпізнавати виноски типу * і заміняти
///   їх на числову відповідно:


#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
void ReadFromFileToString(std::string FileName, std::string &copyString);
using namespace std;

int main()
{
   std::string filename = "data.txt";
   std::string workingString;
   try
   {
      ReadFromFileToString(filename, workingString);
   }
   catch(std::ios_base::failure &ex) { std::cerr << ex.what(); }
   catch(std::exception &ex) { std::cerr << ex.what(); }

   const size_t SizeData = workingString.length();









   std::cout << workingString << std::endl;
   std::cout << workingString.length();

   // std::cin.get();
   return 0;
}

void ReadFromFileToString(std::string FileName, std::string &copyString)
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
void CheckFile(std::string FileName, const size_t Size)
{
   std::fstream File;
   File.open(Filename.c_str(), std::ios_base::in | std::ios_base::out)
   {

   }
}

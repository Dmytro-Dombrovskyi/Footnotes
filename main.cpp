///   Програма отримує текст вигляду:
///   "Today i have no money, and just *walking on the street. etc..."
///   Программа повинна розпізнавати виноски типу * і заміняти
///   їх на числову відповідно:


#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
//#include <strstream>

void ReadFromFileToString(std::string FileName, std::string &copyString);
void CheckFile(std::string FileName, const char delim = '*'/*, const size_t Size*/);
using namespace std;

int main()
{
   std::string filename = "data.txt";
   std::string workingString;
   try
   {
      //ReadFromFileToString(filename, workingString);
      CheckFile(filename);
   }
   catch(std::ios_base::failure &ex) { std::cerr << ex.what(); }
   catch(std::exception &ex) { std::cerr << ex.what(); }

   //const size_t SizeData = workingString.length();


  // std::cout << workingString << std::endl;
  // std::cout << workingString.length();

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

void CheckFile(std::string FileName, const char delim/*, const size_t Size*/)
{
   std::string readString;
   std::string footnotes;
   std::string text;

   int counter = 0;
   std::fstream File1, File2, File_clear;
   File1.open(FileName.c_str(), std::ios_base::in);
   File2.open("tempfile.txt", std::ios_base::out | std::ios_base::trunc);
   File_clear.open("clearfile.txt", std::ios_base::out | std::ios_base::trunc);
   {
      while(File1)
      {
         getline(File1, text, delim);
         File_clear << text;
         text.clear();
         if(!File1.eof())
         {
            while(File1.peek() == delim && File1.get() == delim) continue;
            File_clear <<"(" << (++counter) << ")";

            File1 >> readString;
            File2 << counter << ": "<< readString << std::endl;
         }
      }
      if(File1.eof())
      {
         File1.clear();
         File1.close();
         File2.close();
         File_clear.close();
      }
      else
         throw(std::ios_base::failure("End of file wasn't reached!"));
   }
   std::cout << text << std::endl;
   std::cout << footnotes << std::endl;
}

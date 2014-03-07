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
   std::string footString;
   const size_t ArrSize = 10;
   std::string footnotes[ArrSize];

   std::string String_for_footnotes;
   std::string text;

   size_t total_counter = 0;
   std::fstream CurrentFile, TemporaryFile, FootnotesFile;
   CurrentFile.open(FileName.c_str(), std::ios_base::in);
   TemporaryFile.open("TemporaryFile.txt", std::ios_base::out | std::ios_base::in | std::ios_base::trunc);
   FootnotesFile.open("FootnotesFile.txt", std::ios_base::out | std::ios_base::in | std::ios_base::trunc);
   {

      size_t temp__counter = 0;

      while(CurrentFile)
      {

         getline(CurrentFile, text, delim);
         TemporaryFile << text;
         text.clear();

         temp__counter = 0;
         if(!CurrentFile.eof())
         {
            while(CurrentFile.peek() == delim &&
                  CurrentFile.get() == delim && ++temp__counter)  continue;

            if(total_counter > temp__counter)
            {
               //int point = CurrentFile.tellg();
               CurrentFile >> footString;
               if(footnotes[temp__counter] != footString)
               {
                  throw(std::ios_base::failure("Error. Footnotes are repeated!"));
               }
               //else
              // {
              //    CurrentFile.seekg(-footString.length(), std::ios_base::cur);
              // }
            }
            else
            {
               ++total_counter;

               TemporaryFile <<"(" << total_counter << ")";

               CurrentFile >> footString;
               footnotes[total_counter] = footString;

               FootnotesFile << total_counter << ": "<< footString << std::endl;
            }
         }
      }
      if(CurrentFile.eof())
      {
         CurrentFile.close();
         TemporaryFile.close();
         FootnotesFile.close();
      }
      else
         throw(std::ios_base::failure("End of file wasn't reached!"));
   }
   for(size_t i = 0; i <= total_counter; ++i)
   {
      std::cout << footnotes[i] << std::endl;
   }
}

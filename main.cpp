#include "Footnotes.h"
//#include <strstream>

//void CheckFile(std::string FileName, const char delim = '*'/*, const size_t Size*/);

int main()
{
   //std::string name = "data.txt";
	try
	{
		Footnotes file("E:\\GIT_REPO\\Footnotes\\data.txt");
		file.MakeFileWithFootnotes('*');
		//file.PrintFileOriginal( );
		file.PrintFileWithoutFootnotes( );
		file.PrintFootnotes( );
		std::cout << "Num Footnotes: " << file.getNumFootnotes( ) << std::endl;
	}
	catch (std::exception &ex)
	{
	std::cerr << ex.what();
	}
   
	std::cout << "Done!" << std::endl;
   std::cin.get();
   return 0;
}



//void CheckFile(std::string FileName, const char delim/*, const size_t Size*/)
//{
//   std::string footString;
//   const size_t ArrSize = 10;
//   std::string footnotes[ArrSize];
//
//   std::string String_for_footnotes;
//   std::string text;
//
//   size_t total_counter = 0;
//   std::fstream CurrentFile, TemporaryFile,
//	   FootnotesFile;
//   CurrentFile.open(FileName.c_str(), std::ios_base::in);
//   TemporaryFile.open("TemporaryFile.txt",
//	   std::ios_base::out | std::ios_base::in |
//	   std::ios_base::trunc);
//   FootnotesFile.open("FootnotesFile.txt",
//	   std::ios_base::out | std::ios_base::in |
//	   std::ios_base::trunc);
//   {
//
//      size_t temp__counter = 0;
//
//      while(CurrentFile)
//      {
//
//         getline(CurrentFile, text, delim);
//         TemporaryFile << text;
//         text.clear();
//
//         temp__counter = 0;
//         if(!CurrentFile.eof())
//         {
//            while(CurrentFile.peek() == delim &&
//                  CurrentFile.get() == delim && ++temp__counter)  continue;
//
//            if(total_counter > temp__counter)
//            {
//               //int point = CurrentFile.tellg();
//               CurrentFile >> footString;
//               if(footnotes[temp__counter] != footString)
//               {
//                  throw(std::ios_base::failure("Error. Footnotes are repeated!"));
//               }
//               //else
//              // {
//              //    CurrentFile.seekg(-footString.length(), std::ios_base::cur);
//              // }
//            }
//            else
//            {
//               ++total_counter;
//
//               TemporaryFile <<"(" << total_counter << ")";
//
//               CurrentFile >> footString;
//               footnotes[total_counter] = footString;
//
//               FootnotesFile << total_counter << ": "<< footString << std::endl;
//            }
//         }
//      }
//      if(CurrentFile.eof())
//      {
//         CurrentFile.close();
//         TemporaryFile.close();
//         FootnotesFile.close();
//      }
//      else
//         throw(std::ios_base::failure("End of file wasn't reached!"));
//   }
//   for(size_t i = 0; i <= total_counter; ++i)
//   {
//      std::cout << footnotes[i] << std::endl;
//   }
//}

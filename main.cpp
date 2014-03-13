#include "Footnotes.h"
using namespace exception_footnotes;
int main()
{
   std::string name_of_file = 
		 "D:\\dima\\GIT_REPO\\Footnotes\\data.txt";
	 std::string outFile = 
		 "D:\\dima\\GIT_REPO\\Footnotes\\footnotes.txt";
	try
	{
		Footnotes file(name_of_file.c_str());
		file.MakeFileWithFootnotes('*');
		file.CreateFileWithFootnotes (outFile);
		//file.PrintFileOriginal ();
		//file.PrintFootnotes ();
		file.PrintFileWithFootnotes ();
	}
	//catch(fail_open_file &ex) { std::cerr << ex.what (); }
	//catch(eof_wasnt_reached &ex)	{ std::cerr << ex.what (); }	
	catch(footnotes_not_equals &ex) { std::cerr << ex.what (); }
	catch(std::ios_base::failure &ex) { std::cerr << ex.what( ); }
	catch(std::exception &ex)	{ std::cerr << ex.what( ); }

	std::cout << "\nDone!" << std::endl;
   std::cin.get();
   return 0;
}

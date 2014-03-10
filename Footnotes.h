#ifndef FOOTNOTES_H_INCLUDED
#define FOOTNOTES_H_INCLUDED
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdexcept>
//#include <cstdlib>

using std::string;

class Footnotes
{
private:
   string file_original_;
   string file_without_footnotes_;
   string file_with_footnotes_;

   string warning_;

   int num_footnotes_;
   //int delim_counter;

   int size_footnotes_array_;
   string *footnotes_;
   void IncreaseFootnotesArray
      (const int mult_value = 2);


public:
	//Footnotes() {}
	Footnotes(const string, const string = "()*");
    virtual ~Footnotes() {}
	void PrintFileOriginal() const;
	void PrintFileWithFootnotes() const;
   void PrintFootnotes() const;

   void MakeFileWithFootnotes(const char = '*');

};

#endif // FOOTNOTES_H_INCLUDED

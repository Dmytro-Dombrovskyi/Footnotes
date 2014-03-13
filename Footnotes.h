#ifndef FOOTNOTES_H_INCLUDED
#define FOOTNOTES_H_INCLUDED
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "my_exception.h"
using std::string;
using namespace exception_footnotes;

class Footnotes
{
private:
   string file_original_;   
   string file_with_footnotes_;
	 string file_footnotes_;

   string warning_;

   int num_footnotes_;   

   int size_footnotes_array_;
   string *footnotes_;

	inline bool IsPlaceInFootnotesArray(const int value)
	{
		return (size_footnotes_array_ >= value) ? true : false;
	}
	void PutFootnotesIntoArray(const int number, const string copy_footnotes)
	{
		footnotes_[number] = copy_footnotes;
	}
	inline void AddNumFootnotes(const int number)
	{
		if(num_footnotes_ - 1 < number)
			SetNumFootnotes(number + 1);
	}
	inline void SetNumFootnotes(const int value)
	{		
		num_footnotes_ = value;	
	}
	void AddFootnotesNumberToFile( const int );
	void CompareFootnotesWithCounter(const int delim_counter, 
																	 const string temp_footnotes);
	void IncreaseFootnotesArray
		(const int mult_value);
	void MakeStringFileFootnotes();

public:
	//Footnotes() {}
	Footnotes(const string, const string = "()*");
  virtual ~Footnotes() {}
	void PrintFileOriginal() const;
	void PrintFileWithFootnotes() const;
  void PrintFootnotes() const;	

  void MakeFileWithFootnotes(const char = '*');
   
	void CreateFileWithFootnotes(string filename);
	
	int getNumFootnotes( ) const
		{ return num_footnotes_; }

};





#endif // FOOTNOTES_H_INCLUDED

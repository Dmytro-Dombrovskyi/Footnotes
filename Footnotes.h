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
   string file_;
   size_t num_footnotes_;
public:
	//Footnotes() {}
	Footnotes(const string);
    virtual ~Footnotes() {}
	void PrintFileInfo() const { std::cout << file_; }

   //void WriteToFileString(const string write) {}
	void CheckFootnotesInString(const char = '*');
	
   //void CopyFromFile(const string fileCopy){}
   
};

#endif // FOOTNOTES_H_INCLUDED

#pragma once
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>
using std::string;

namespace exception_footnotes
{
	class fail_open_file
	{
	private:
		string file_;
		string str_problem;
	public:
		explicit fail_open_file (string i_filename,
			const char * i_problem = "Error! Couldn't open file: ") :
			file_ (i_filename), str_problem (i_problem) {	}
		string what () const 
		{
			string temp = str_problem + file_;
			return temp;
		}
	};

	class eof_wasnt_reached
	{
	private:
		string file_name_;
	public:
		explicit eof_wasnt_reached (string i_filename) :
			file_name_ (i_filename) {}
		string what () const 
		{
			string problem =
				"Error! End of file wasn't reached in file: ";
			return problem.append (file_name_);
		}
	};

	class footnotes_not_equals
	{
	private:
		string footnotes1_;
		string footnotes2_;
		string problem_;
	public:		
		footnotes_not_equals (string i_footnotes1, string i_footnotes2,
			string i_problem = "Error! Footnotes aren't equal: ")
			: footnotes1_ (i_footnotes1), footnotes2_ (i_footnotes2),
				problem_(i_problem) { }
		virtual string what () const
		{			
			string what_str = problem_ + footnotes1_ + " != " + footnotes2_;			
			return what_str;
		}
	};
	//////////////////////////////////////////////////////////
	class fail : public std::ios_base::failure {
	public:
		fail () : failure("Footnotes aren't equal!") {}
		//const char* what () const
		//{ 			
		//	return "footnotes aren't equal!";
		//}
	};
	///////////////////////////////////////////////////////////
}

#endif // MY_EXCEPTION_H




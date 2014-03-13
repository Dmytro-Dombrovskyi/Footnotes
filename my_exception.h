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
	class fail_open_file : public std::exception 
	{
	private:
		std::string file_;
		std::string str_problem;
	public:
		explicit fail_open_file (string i_filename,
			const char * i_problem = "Error! Couldn't open file: ") :
			file_ (i_filename), str_problem (i_problem) {	}
		const char * what () 
		{
			std::string temp = str_problem + file_;
			return temp.c_str ();
		}
	};

	class eof_wasnt_reached : public std::exception 
	{
	private:
		std::string file_name_;
	public:
		explicit eof_wasnt_reached (string i_filename) :
			file_name_ (i_filename) {}
		const char * what () 
		{
			std::string problem =
				"Error! End of file wasn't reached in file: ";
			return problem.append (file_name_).c_str();
		}
	};

	class footnotes_not_equals : public std::exception 
	{
	private:
		string footnotes1_;
		string footnotes2_;
	public:
		footnotes_not_equals (string i_footnotes1, string i_footnotes2)
			: footnotes1_ (i_footnotes1), footnotes2_ (i_footnotes2) {}
		const char * what () 
		{
			string problem = "Error! Footnotes aren't equal: ";
			problem.append (footnotes1_).append (" != ").append (footnotes2_);			
			return problem.c_str ();
		}
	};


}

#endif // MY_EXCEPTION_H




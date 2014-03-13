#include "Footnotes.h"

// constructor: copy data from file to string
Footnotes::Footnotes(const string i_FileName,	const string i_Warning)
	: warning_(i_Warning), num_footnotes_(0),
	size_footnotes_array_(3),
	footnotes_(new string[size_footnotes_array_])
{
	std::ifstream inFile;
	inFile.open(i_FileName.c_str(), std::ios_base::in);
	if (inFile.is_open())
	{
		char ch;
		while(inFile.get(ch)) file_original_.push_back(ch);
		if(inFile.eof ()) { inFile.close (); }
		else
			throw exception_footnotes::eof_wasnt_reached
			(i_FileName);
	}
	else
	{
		throw exception_footnotes::fail_open_file 
			(i_FileName);
	}
}

// find delimetrs in string file and summing them. 
// main function in class footnotes!
void Footnotes::MakeFileWithFootnotes (const char delim) {
	int delim_counter = 0;
	string temp_footnotes;
	const int max_i = file_original_.length ();

	for(int i = 0; i < max_i; ++i) {
		// find delims in string
		while(file_original_[i] != delim) {
			file_with_footnotes_.push_back (file_original_[i]);
			++i;
			if(file_original_[i] == delim || i >= max_i) break;
		}

		if(file_original_[i] == delim) {
			// summing delims
			delim_counter = 0;
			while(file_original_[i] == delim) {
				++i;
				if(file_original_[i] != delim) break;
				++delim_counter;
			}
			// check space in footnotes string array:
			// and inreased it if it need;
			if(!IsPlaceInFootnotesArray (delim_counter)) {
				IncreaseFootnotesArray (delim_counter);
			}

			// write word in temp string
			while(!isspace (file_original_[i])) {
				temp_footnotes.push_back (file_original_[i]);
				++i;
				if(isspace (file_original_[i])) break;
			}
			// check footnotes and compare information on them
			CompareFootnotesWithCounter (delim_counter, temp_footnotes);
			temp_footnotes.clear ();
		}
	}
	MakeStringFileFootnotes ();
}
// compare temp_footnotes with current filling footnotes in array
// and choose: get into array, get warning or get an exception
void Footnotes::CompareFootnotesWithCounter(const int delim_counter, 
																						const string temp_footnotes)
{
	if(num_footnotes_ <= delim_counter || footnotes_[delim_counter] == "")
	{
		PutFootnotesIntoArray(delim_counter, temp_footnotes);
		AddNumFootnotes(delim_counter);
		AddFootnotesNumberToFile();
	}
	else
	{
		if(footnotes_[delim_counter] == temp_footnotes)
			file_with_footnotes_.append(warning_);
		else
		{
			throw exception_footnotes::footnotes_not_equals
				(footnotes_[delim_counter], temp_footnotes);
		}
	}
}
// add number in ( ) of footnotes in file_with_footnotes
void Footnotes::AddFootnotesNumberToFile () {
	file_with_footnotes_.push_back ('(');
	std::stringstream ss;
	ss << num_footnotes_;
	file_with_footnotes_.append (ss.str ());
	file_with_footnotes_.push_back (')');
}
// get bigger size to array;
void Footnotes::IncreaseFootnotesArray (const int mult_value)
{
	const int new_size_array = mult_value + (size_footnotes_array_ * 2);
   string *temp_footnotes =	new string[new_size_array];

	for(int i = 0; i < size_footnotes_array_; ++i)
	{
		temp_footnotes[i] = footnotes_[i];
	}
	delete[]footnotes_;
	footnotes_ = new string[new_size_array];
	footnotes_ = temp_footnotes;
	size_footnotes_array_ = new_size_array;
}
// fills string file_footnotes in order
void Footnotes::MakeStringFileFootnotes()
{
  std::stringstream ss;
	ss << "Footnotes: \n";
	for (int i = 1; i <= num_footnotes_; ++i)
	{
		ss << i << ": " << footnotes_[i - 1] << "\n";
	}
	string strTemp = ss.str();
	file_footnotes_.append(strTemp);
}
// Create file "filename" and write footnotes text and footnotes to it
void Footnotes::CreateFileWithFootnotes (string filename) {
	std::ofstream OutFile (filename.c_str (), std::ios_base::out |
												 std::ios_base::trunc);
	{
		if(OutFile.is_open ()) {
			OutFile << file_with_footnotes_ << "\n";
			OutFile << file_footnotes_;
			OutFile.clear ();
			OutFile.close ();
		}
		else {
			throw
				exception_footnotes::fail_open_file	(filename);
		}
	}
}
// Print String file_original_ on console
void Footnotes::PrintFileOriginal() const
{
	std::cout << file_original_ << std::endl;
}
// Print String file footnotes on console
void Footnotes::PrintFootnotes() const
{
	std::cout << file_footnotes_ << std::endl;
}
// Print String file_with_footnotes on console
void Footnotes::PrintFileWithFootnotes() const
{
	std::cout << file_with_footnotes_ << std::endl;
}

#include "Footnotes.h"

Footnotes::Footnotes(const string i_FileName)
	: num_footnotes_(0)
{
	std::ifstream inFile;
	inFile.open(i_FileName.c_str(), std::ios_base::in);
	if (inFile.is_open())
	{
		char ch;
		while (inFile.get(ch)) file_.push_back(ch);
		if (inFile.eof())
		{
			inFile.clear();
			inFile.close();
		}
		else
			throw std::ios_base::failure
			("End of file wasn't reached!");
	}
	else
	{
		throw std::ios_base::failure
			("Error open file!");
	}
}
void Footnotes::CheckFootnotesInString(const char delim)
{
	size_t delim_counter = 0;
	const size_t footnotes_size = 10;
	string footnotes[footnotes_size];
	size_t max_i = file_.length();
	//char ch;
	for (size_t i = 0; i < max_i; ++i)
	{
		//std::cout << file_[i];
		//if (isspace(ch = file_[i])) ++delim_counter;
		if (file_[i] == delim)
		{
			delim_counter = 0;
			while (file_[i] == delim)
			{
				++delim_counter;
				++i;
				if (file_[i] != delim) break;
				continue;
			}
			while (!isspace(file_[i]))
			{
				footnotes[delim_counter].push_back(file_[i]);
				++i;
				if (isspace(file_[i])) break;
				continue;
			}
		}//--i;
	}
	//std::cout << delim_counter << "spaces!";
	std::cout << "Footnotes: " << std::endl;
	for (size_t i = 1; i <= delim_counter; ++i)
	{
		std::cout << i << ": " << footnotes[i] << std::endl;
	}
}

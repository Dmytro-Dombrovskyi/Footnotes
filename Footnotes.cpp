#include "Footnotes.h"

Footnotes::Footnotes(const string i_FileName)
	: size_footnotes_array(0), num_footnotes_(5),
	  footnotes_(new string[num_footnotes_])
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
	int delim_counter = 0;
	int footnotes_counter = 0;
	//string footnotes[footnotes_size];
	string temp_footnotes;
	string text;
	string warning_footnotes = "()*";
	const int max_i = file_.length();
	//char ch;
	for (int i = 0; i < max_i; ++i)
	{
		// find delims in string
		while (file_[i] != delim)
		{
			text.push_back(file_[i]);
			++i;
			if(file_[i] == delim || i >= max_i) break;
		}
		if(file_[i] == delim)
		{
			delim_counter = 0;
			while (file_[i] == delim)
			{				
				++i;
				if (file_[i] != delim) break;
				++delim_counter;
			}
			// check space in footnotes string array:
			if(delim_counter >= num_footnotes_)
			{
				int new_num_footnotes = num_footnotes_ + 10;
				string *temp_footnotes =
								new string[new_num_footnotes];
				for(int i = 0; i < num_footnotes_; ++i)
				{
					temp_footnotes[i] = footnotes_[i];
				}
				delete[]footnotes_;
				footnotes_ = temp_footnotes;
				num_footnotes_ = new_num_footnotes;
			}
			// write word in temp string
			while (!isspace(file_[i]))
			{
				temp_footnotes.push_back(file_[i]);
				++i;
				if (isspace(file_[i])) break;
			}
			// check footnotes and compare them
			if(footnotes_counter > delim_counter)
			{
				if(footnotes_[delim_counter] == temp_footnotes)	
					text.append(warning_footnotes);
				else
				{					
					throw std::ios_base::failure
						("Error! Footnotes aren't equal!");					
				}

			}
			else  // write footnotes in array
			{
				footnotes_[footnotes_counter] = temp_footnotes;
				++footnotes_counter;
				temp_footnotes.clear();
			}
		}
	}
	size_footnotes_array = num_footnotes_;
	num_footnotes_ = delim_counter;
	std::cout << "Footnotes: " << std::endl;
	for (int i = 0; i <= num_footnotes_; ++i)
	{
		std::cout << i << ": " << footnotes_[i] << std::endl;
	}

}

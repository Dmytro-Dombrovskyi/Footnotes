#include "Footnotes.h"
// constructor: copy data from file to string
Footnotes::Footnotes(const string i_FileName,
							const string i_Warning)
	: warning_(i_Warning), num_footnotes_(0), 
	size_footnotes_array_(10),
	footnotes_(new string[size_footnotes_array_])
{
	std::ifstream inFile;
	inFile.open(i_FileName.c_str(), std::ios_base::in);
	if (inFile.is_open())
	{
		char ch;
		while(inFile.get(ch)) file_original_.push_back(ch);
		if(inFile.eof( )) { inFile.close( ); }
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

void Footnotes::IncreaseFootnotesArray (const int mult_value)
{
	const int new_size_array = size_footnotes_array_ * mult_value;
   string *temp_footnotes =	new string[new_size_array];

	for(int i = 0; i < size_footnotes_array_; ++i)
	{
		temp_footnotes[i] = footnotes_[i];
	}
	delete[]footnotes_;
	footnotes_ = temp_footnotes;
	size_footnotes_array_ = new_size_array;
}

// find delimetrs in string file and summing them
void Footnotes::MakeFileWithFootnotes(const char delim)
{
	int delim_counter = 0;
	string temp_footnotes;
	const int max_i = file_original_.length();
	//char ch;
	for (int i = 0; i < max_i; ++i)
	{
		// find delims in string
		while (file_original_[i] != delim)
		{
			file_without_footnotes_.push_back(file_original_[i]);
			++i;
			if(file_original_[i] == delim || i >= max_i) break;
		}

		if(file_original_[i] == delim)
		{
			// summing delims
			delim_counter = 0;
			while (file_original_[i] == delim)
			{
				++i;
				if (file_original_[i] != delim) break;
				++delim_counter;
			}

			// check space in footnotes string array:
			// and inreased it if it need;
			if(delim_counter >= size_footnotes_array_)
			{
				this->IncreaseFootnotesArray(2);				
			}

			// write word in temp string
			while (!isspace(file_original_[i]))
			{
				temp_footnotes.push_back(file_original_[i]);
				++i;
				if (isspace(file_original_[i])) break;
			}
			// check footnotes and compare information on them
			if(num_footnotes_ <= delim_counter || footnotes_[delim_counter] == "")
			{
				footnotes_[delim_counter] = temp_footnotes;
				if(num_footnotes_ < delim_counter) 
					num_footnotes_ = delim_counter;
				file_without_footnotes_.append("()");
				temp_footnotes.clear();
			}			
			else
			{
				if(footnotes_[delim_counter] == temp_footnotes)
					file_without_footnotes_.append(warning_);
				else
				{
					throw std::ios_base::failure
						("Error! Footnotes aren't equal!");
				}
			}
		}
	}
}

void Footnotes::PrintFileOriginal() const
{
	std::cout << file_original_;
}

void Footnotes::PrintFootnotes() const
{
	std::cout << "Footnotes: " << std::endl;
	for (int i = 0; i <= num_footnotes_; ++i)
	{
		std::cout << i << ": " << footnotes_[i] << std::endl;
	}
}

void Footnotes::PrintFileWithFootnotes() const
{
	std::cout << file_with_footnotes_;
}

void Footnotes::PrintFileWithoutFootnotes( ) const
{
	std::cout << file_without_footnotes_;
}

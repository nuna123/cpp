#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>




int	main(int argc, char *argv[])
{
	if (argc != 4)
		return (
			std::cout	<< "Wrong num of Arguments! usage: [filename] [s1] [s2]" 
						<< std::endl,
			 1);

	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		content;

	std::string		filename = argv[1];
	std::string		str_tofind = argv[2];
	std::string		str_toreplace = argv[3];

	infile.open(filename.c_str());
	outfile.open((filename + ".replaced").c_str());
	if(!infile || !outfile) // file couldn't be opened
		return (
			std::cout	<< "Error: file could not be opened"
						<< std::endl,
			 1);

	while(!infile.eof()) 
	{
		getline(infile,content);
		outfile << "";

		while (content.find(str_tofind) != std::string::npos)
		{
			outfile << content.substr(0, content.find(str_tofind));
			outfile << str_toreplace;
			content =  content.substr(content.find(str_tofind) + str_tofind.length(), content.length());
		}
		outfile << content;
		if (!infile.eof())
			outfile << "\n";
	}

	infile.close();
	
	return 0;

}
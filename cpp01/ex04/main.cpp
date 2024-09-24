/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:45:15 by arepsa            #+#    #+#             */
/*   Updated: 2024/05/09 18:45:15 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> //EOF

/* 
** Program accepts 3 arguments - filename, string to be replaced and new string
** Open the file <filename> and copy its content into a new file
** <filename>.replace, replace every occurrence of s1 with s2.
*/

bool is_file_empty(const std::string& filename) {
	std::ifstream file(filename.c_str());
	//peek() returns the next character in the input stream without extracting it
	return file.peek() == EOF;
}

/* 
** replace s1 with s2 in the string on place
*/
void	overwrite_str(std::string& string, std::string& s1, std::string s2){
		//find() returns the position of the first character of the first match.
		size_t pos = string.find(s1);
		//If no matches ere found, find() returns string::npos.
		while (pos != std::string::npos)
		{
			string.erase(pos, s1.length());
			string.insert(pos, s2);
			pos = string.find(s1, pos + s2.length());
		}
}

/* 
** open infile, implicit file opening by passing the filename string as parameter
** create outfile, replace string contents and output string contents into it 
** runtime_error object is derived from exception class
*/
int	do_replace(std::string& infileName, std::string& s1, std::string& s2){
	try {
		std::ifstream infile(infileName.c_str());
		if (!infile) {
			if (errno == ENOENT)
				throw std::runtime_error("Error: File does not exist.");
			else if (errno == EACCES)
				throw std::runtime_error("Error: Permission denied.");
			else
				throw std::runtime_error("Error: Could not open file.");
		}

		if (is_file_empty(infileName)) {
		   std::cerr << "Warning: Input file is empty." << std::endl;
		   return 1;
		}

		std::string outName = infileName + ".replace";
		std::ofstream outfile(outName.c_str());
		if (!outfile)
			throw std::runtime_error("Error: Could not create output file.");

		std::string	line;
		while (std::getline(infile, line))
		{
			overwrite_str(line, s1, s2);
			outfile << line << std::endl;
		}
		infile.close();
		outfile.close();
		return 0;
	} catch (const std::exception& err) {
		std::cerr << err.what() << std::endl;
		return 1;
	}
}

int	main(int argc, char** argv) {

	if (argc == 4)
	{
		std::string infileName = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		if (infileName.empty() || s1.empty()){
			std::cerr << "Warning: Filename and string to replace cannot be empty." << std::endl;
			return 1;
		} 
		return do_replace(infileName, s1, s2);
	}
	else {
		std::cerr << "Incorrect input." << std::endl;
		std::cerr << "Usage: ./sed <filename> <string_to_replace> <new_string>" << std::endl;
		return 1;
	}
	return 0;
}

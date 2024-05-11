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
** replace s1 with s2 in the string 
*/
void	overwrite_string(std::string& string, std::string& s1, std::string s2){
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
** open infile and construct string by reading from infile buffer
** replace string contents
** create outfile and output string contants into it
** runtime_error object is derived from exception class
*/
int	do_replace(std::string& infileName, std::string& s1, std::string& s2){
	try {
		std::ifstream infile(infileName.c_str());
		if (!infile)
            throw std::runtime_error("Error: Could not open file.");
		std::string input((std::istreambuf_iterator<char>(infile)),
                          (std::istreambuf_iterator<char>()));;
	/* 	std::string input;
		getline(infile, input, '\0'); */

		infile.close();

		overwrite_string(input, s1, s2);

		std::string ofName = infileName;
		std::ofstream outfile(infileName.append(".replace").c_str());
		if (!outfile) 
        	throw std::runtime_error("Error: Could not create output file.");
		outfile << input;
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
		} else if (is_file_empty(infileName))
            std::cerr << "Warning: Input file is empty." << std::endl;
		else
			do_replace(infileName, s1, s2);
	}
	else {
		std::cerr << "Incorrect input." << std::endl;
		std::cerr << "Usage: ./sed <filename> <string_to_replace> <new_string>" << std::endl;
	}
	return 0;
}
#include <iostream>
#include <string>

#include "BigInteger.h"
#include "rsa.h"

using namespace std;

void usage(char* execName) 
{
    stderr << execName <<
        ": SYNOPSIS\n"
        "   This program will encrypt a file\n"
        "\n"
        "USAGE\n"
        "   %s [-i:o:n:h] "
        "-[i: specifies the input], [o: specifies the output], [p: specifies file containing "
        "public key], [h: help page]"
        "\n"
        "OPTIONS\n"
        "   -i         specifies the input file to encrypt (default: stdin)\n"
        "   -o         specifies the output file to encrypt (default: stdout)\n"
        "   -p         specifies the file containing the public key (default: rsa.pub)\n"

        "   -h         displays program synopsis and usage\n" 
		<< endl;
}
int main(int argc, char* argv[])
{
	int opt = 0;
	string publicKeyFileName = "rsa.pub"; //rsa.pub is deafult
	string inputFileName = "stdin"; // stdin is deafult
	string outputFileName = "stdout"; // stdout is deafult

	// Getting user input
	while ((opt = getopt(argc, argv, "i:o:ph")) != -1)
	{
		switch (opt)
		{
			case 'i': inputFileName = optarg; break;
        	case 'o': outputFileName = optarg; break;
        	case 'n': publicKeyFfileName = optarg; break;
			case 'h': usage(arv[0]); return EXIT_FAILURE;
			deafult: stderr << "Incorrect usage please see -h for help" << endl; return 1;
		}
	}

	// Opening Files
	ifstream publicKeyFile(publicKeyFileName);
	ifstream inputFile(inputFileName);
	ostream outputFile(outputfileName);

	//Read public file
	return 0;
}

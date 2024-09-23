# WordIndexGenerator

## Project Overview
WordIndexGenerator is a C program that parses text input to index words based on their frequency and the lines on which they appear. This tool is useful for identifying unique words while excluding common words is required.

## Features
- **Word Parsing**: Analyzes text to find unique words.
- **Indexing**: Indexes words by frequency and line number.
- **Exclusion of Common Words**: Ignores frequently used words to focus on significant words.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites
Make sure you have a C compiler installed, such as GCC. You can install GCC on Ubuntu using:

```bash
sudo apt update
sudo apt install gcc
```

### Installation
Clone the repo from GitHub:
```bash
git clone https://github.com/ahmdmshazly/WordIndexGenerator.git
cd WordIndexGenerator
```

### Building the Project
To compile the project, run the following command from the root of the directory:
```bash
gcc -o WordIndexGenerator src/main.c
```

### Running the Program
To run the program, you can use:

```bash
./WordIndexGenerator < input.txt > output.txt
```
Replace input.txt with the path to your input file and output.txt with the path to where you want to save the output.

### Usage Example
To analyze a text file and see the indexed words along with their frequencies and line numbers, you might do:

```bash
./WordIndexGenerator < sample.txt > result.txt
```

## Contributing
Feel free to fork the repository and submit pull requests. You can also open issues to discuss potential changes or report bugs.

## License
This project is licensed under the MIT License - see the LICENSE.md file for details.

## Author
- [AHMED MOHAMED](mailto:ahmdmshazly@cmu.edu)  


-------------------------

***Note: This README is a part of a submission to an academic course.***



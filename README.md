#  CSV IO Util
This package provides functionality for exporting and importing CSV files in C++.
Furthermore, it provides utility functions to handle file paths, directories and files on a Linux system.

## Usage
### Documentation
For a detailed documentation refer to the Doxygen pages.
When building the package you can use the flag '-DBUILD_DOC=TRUE' to build the documentation. You can access it in the doc folder afterwards.

### Importer Example
```c++
// create file path
const std::string file_path = "path/to/file.csv";

// create CsvImporter object
CsvImporter csv_importer(file_path);

// if another delimiter than "," should be used, one can change the delimiter
csv_importer.setDelimiter(";");  // change the delimiter to ";"

// create a vector to store the values for each column
std::vector<std::string> column_values;

// parse the CSV file line by line
while(csv_importer.getNextLine(column_values))
{
  for (size_t i = 0; i < column_values.size(); i++)
  {
  // do what ever you like with the column values
  }
}
```
### Exporter Example
Example with automatic line break:
```c++
// create file path
const std::string file_path = "path/to/file.csv";

// define number of columns
size_t nr_of_columns = 3;

// create CsvExporter object
CsvExporter csv_exporter(file_path, nr_of_columns);

// insert line with column headlines
csv_exporter << "Name of first column"
        << "Name of second column"
        << "Name of third second";  

// insert first data line
csv_exporter << "String value" << 2 << 1.234567890;

// insert second data line
csv_exporter << "Another String value" << 1.0 << 2;

// ensure the buffer is written to the file
csv_exporter.flush();
```

Example with manual line break:
```c++
// create file path
const std::string file_path = "path/to/file.csv";

// create CsvExporter object without specifying the column number
CsvExporter csv_exporter(file_path);

// insert line with column headlines
csv_exporter << "Name of first column"
        << "Name of second column"
        << "Name of third second";  
// insert line break
csv_exporter.nextLine();

// insert first data line
csv_exporter << "String value" << 2 << 1.234567890;
// insert line break
csv_exporter.nextLine();

// insert second data line
csv_exporter << "Another String value" << 1.0 << 2;

// ensure the buffer is written to the file
csv_exporter.flush();
```

## Installation
While the package is set up to be build using [catkin](http://wiki.ros.org/catkin), it has no ROS dependencies.
After cloning it into your catkin workspace use package using `catkin build`.

## Future Development & Contribution
The project during which the package was developed has been discontinued.
But in case you find bugs, typos or have suggestions for improvements feel free to open an issue.
We would especially appreciate Pull Requests fixing open issues.

## Author
- Felix Biemüller

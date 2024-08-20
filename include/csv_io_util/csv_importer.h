//--------------------------------------------------------------------------------------------------------------------------------
// Copyright 2024 Felix Biemüller, Technische Universität Darmstadt

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
// files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED  TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
//--------------------------------------------------------------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>
#include <fstream>

namespace csv_io_util
{
/**
 * @brief The CsvImporter class can be used to import the values of a csv file line by line.
 */
class CsvImporter
{
public:
  /**
   * @brief Creates a CsvImporter object that can be used to read a csv file line by line
   * @param file_path path to the file that should be read
   */
  explicit CsvImporter(const std::string& file_path);

  /** @brief Destroys the CsvImporter Object and also closes the file stream.
   */
  ~CsvImporter();

  /**
   * @brief If there is another line in the csv that has not been read yet, the line is tokenized acording to the
   * current delimiter.
   * @param column_values This vector of strings is set, such that it represent each element in the line that has been
   * read, if a new line was available.
   * @return true if a new line could have been read, false otherwise
   */
  bool getNextLine(std::vector<std::string>& column_values);

  /**
   * @brief Sets the string that is used to separate the values in the csv file. The default value when not set is a
   * single comma without spaces.
   * @param delimiter the string that is used to separate the values
   */
  void setDelimiter(const std::string& delimiter);

private:
  std::fstream file_stream_;
  std::string delimiter_ = ",";
};
}  // namespace csv_io_util

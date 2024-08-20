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
#include <iostream>
#include <fstream>

#include "csv_io_util/file_system_util.h"

namespace csv_io_util
{
/**
 * @brief The CsvExporter class can be used to conveniently export data as csv file.
 */
class CsvExporter
{
public:
  /**
   * @brief Creates an CsvExporter object that stores the values in the giv a csv format. If the file path is in an directory, which does not exist yet, it is created.
   * @param file_path path to the file that is written
   * @param column_number the number of columns that should be used. If set to a value greater than zero, the line break
   * is automatically inserted at the end of the line without the need to invoke nextLine() (see setColumnNumber() for details).
   */
  CsvExporter(const std::string& file_path, size_t column_number = 0);

  /** @brief Destroys the CsvExporter Object and also closes the output stream, to ensure that all elements that are in
   * the buffer get written to the file.
   */
  ~CsvExporter();

  /**
   * @brief Sets the string that is used to separate the values in the csv file. The default value when not set is a
   * single comma without spaces.
   * @param delimiter the string that is used to separate the values
   */
  void setDelimiter(const std::string& delimiter);

  /**
   * @brief Sets the number of columns of the csv file such that automatically the end line tag is inserted everytime
   * the last element for the row is appended. The mode can be deactivated by calling it with zero as argument.
   * @param column_number the number of columns that should be used when inserting the values
   */
  void setColumnNumber(size_t column_number);

  /**
   * @brief Sets the number of digits that should be written to the file after the dot. If this function is not called
   * the default is the maximal number of digits that is needed to maintain double accuracy.
   * @param digits number of digits that should be written to the file after the dot
   */
  void setOutputPrecision(int digits);

  /**
   * @brief the stream operator os used to append values to the csv file
   * @param val_to_insert string value that should be appended
   */
  CsvExporter& operator<<(const std::string& val_to_insert);

  /**
   * @brief the stream operator os used to append values to the csv file
   * @param val_to_insert int value that should be appended
   */
  CsvExporter& operator<<(int val_to_insert);

  /**
   * @brief the stream operator os used to append values to the csv file
   * @param val_to_insert double value that should be appended
   */
  CsvExporter& operator<<(double val_to_insert);

  /**
   * @brief This function puts an end line character to the file if the automatic mode has not been activated by CsvExporter() or setColumnNumber().
   * Otherwise a logic_error exception is thrown, to ensure, that automatic mode and manual mode are not mixed up.
   */
  void nextLine();

  /**
   * @brief Writes all current values in the buffer to the file. This function can be called to ensure, that the data is
   * written to the file befor the programm has terminated to prevent data loss as the result of a failure or power loss.
   */
  void flush();

private:
  template <class T>
  CsvExporter& insertValueImpl(const T& val_to_insert)
  {
    if (column_number_ != 0 && current_column_ >= column_number_)
    {
      output_stream_ << std::endl;
      current_column_ = 0;
    }
    output_stream_ << val_to_insert << delimiter_;
    current_column_++;
    return *this;
  }

  size_t column_number_ = 0;
  std::ofstream output_stream_;
  std::string delimiter_ = ",";
  size_t current_column_ = 0;
};
}  // namespace csv_io_util

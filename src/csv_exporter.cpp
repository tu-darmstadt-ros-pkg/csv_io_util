#include "csv_io_util/csv_exporter.h"

#include <iomanip>
#include <limits>

namespace csv_io_util
{
CsvExporter::CsvExporter(const std::string& file_path, size_t column_number)
{
  // create the directory if it does not exist yet
  std::string directory_path = getDirectoryOfFile(file_path);
  createDirectoryIfNonexistent(directory_path);

  // open the output stream
  output_stream_.open(file_path, std::ofstream::out | std::ofstream::trunc);

  // set the output precision of double values to the maximum
  setOutputPrecision(std::numeric_limits<long double>::digits10 + 1);

  // set the number of columns
  setColumnNumber(column_number);
}

void CsvExporter::setColumnNumber(size_t column_number)
{
  current_column_ = 0;
  column_number_ = column_number;
}

CsvExporter::~CsvExporter()
{
  if (output_stream_.is_open())
  {
    output_stream_.close();
  }
}

void CsvExporter::setDelimiter(const std::string& delimiter) { delimiter_ = delimiter; }

void CsvExporter::setOutputPrecision(int digits) { output_stream_ << std::fixed << std::setprecision(digits); }

CsvExporter& CsvExporter::operator<<(const std::string& val_to_insert) { return insertValueImpl(val_to_insert); }

CsvExporter& CsvExporter::operator<<(int val_to_insert) { return insertValueImpl(val_to_insert); }

CsvExporter& CsvExporter::operator<<(double val_to_insert) { return insertValueImpl(val_to_insert); }

void CsvExporter::nextLine()
{
  if (column_number_ != 0)
  {
    throw std::logic_error("nextLine() should not be called, when a fixed number of columns is set.");
  }
  output_stream_ << std::endl;
}

void CsvExporter::flush() { output_stream_.flush(); }

}  // namespace csv_io_util

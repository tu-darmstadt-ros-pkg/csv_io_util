#include <boost/algorithm/string.hpp>

#include "csv_io_util/csv_importer.h"

namespace csv_io_util
{
CsvImporter::CsvImporter(const std::string& file_path) { file_stream_.open(file_path, std::ios::in); }

CsvImporter::~CsvImporter() { file_stream_.close(); }

bool CsvImporter::getNextLine(std::vector<std::string>& column_values)
{
  std::string line;

  if (getline(file_stream_, line))
  {
    boost::split(column_values, line, boost::is_any_of(delimiter_), boost::token_compress_off);
    return true;
  }
  else
  {
    return false;
  }
}

void CsvImporter::setDelimiter(const std::string& delimiter) { delimiter_ = delimiter; }
}  // namespace csv_io_util

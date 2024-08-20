#include "gtest/gtest.h"

#include "csv_io_util/csv_exporter.h"
namespace csv_io_util
{
namespace test
{
TEST(CSV_EXPORT, write_file_manual_line_break)
{
  const std::string file_name = "file1.csv";

  // clean up old file if it exists
  deleteFile(file_name);

  CsvExporter csv_exp(file_name);

  csv_exp << "Col 1"
          << "Col 2"
          << "Col 3";
  csv_exp.nextLine();
  csv_exp << "Va 1" << 2 << 1.234567890;

  csv_exp.flush();

  EXPECT_TRUE(checkIfFileExists(file_name));
}

TEST(CSV_EXPORT, write_file_automatic_line_break)
{
  const std::string file_name = "file1.csv";

  // clean up old file if it exists
  deleteFile(file_name);

  CsvExporter csv_exp(file_name, 3);

  csv_exp << "Col 1"
          << "Col 2"
          << "Col 3";
  csv_exp << "Va 1" << 2 << 1.234567890;

  csv_exp.flush();

  EXPECT_TRUE(checkIfFileExists(file_name));
}
}  // namespace test
}  // namespace csv_io_util

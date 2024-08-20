#include "gtest/gtest.h"

#include "csv_io_util/csv_importer.h"

namespace csv_io_util
{
namespace test
{
std::vector<std::vector<std::string>> expected_results = { { "a", "b", "c", "0.7", "3", "test" }, { " ", "x", "y", "z", "1", "2", "3", "" }, { "0", "8", "9", "" } };

TEST(CSV_IMPORT, read_file_with_comma_separator)
{
  CsvImporter csv_import(SOURCE_DIR "/test/test_csv/comma_separator.csv");

  std::vector<std::string> tokens;

  for (int line_nr = 0; line_nr < expected_results.size(); line_nr++)
  {
    ASSERT_TRUE(csv_import.getNextLine(tokens));
    int nr_of_expected_tokens = expected_results[line_nr].size();

    ASSERT_EQ(tokens.size(), nr_of_expected_tokens);

    for (int i = 0; i < nr_of_expected_tokens; i++)
    {
      EXPECT_EQ(tokens[i], expected_results[line_nr][i]) << "Token of line " << line_nr << " at position " << i << " was \"" << tokens[i] << "\" but expected \""
                                                         << expected_results[line_nr][i] << "\".\n";
    }
  }
  ASSERT_FALSE(csv_import.getNextLine(tokens));
}

TEST(CSV_IMPORT, read_file_with_semicolon_separator)
{
  CsvImporter csv_import(SOURCE_DIR "/test/test_csv/semicolon_separator.csv");
  csv_import.setDelimiter(";");

  std::vector<std::string> tokens;

  for (int line_nr = 0; line_nr < expected_results.size(); line_nr++)
  {
    ASSERT_TRUE(csv_import.getNextLine(tokens));
    int nr_of_expected_tokens = expected_results[line_nr].size();

    ASSERT_EQ(tokens.size(), nr_of_expected_tokens);

    for (int i = 0; i < nr_of_expected_tokens; i++)
    {
      EXPECT_EQ(tokens[i], expected_results[line_nr][i]) << "Token of line " << line_nr << " at position " << i << " was \"" << tokens[i] << "\" but expected \""
                                                         << expected_results[line_nr][i] << "\".\n";
    }
  }
  ASSERT_FALSE(csv_import.getNextLine(tokens));
}
}  // namespace test
}  // namespace csv_io_util

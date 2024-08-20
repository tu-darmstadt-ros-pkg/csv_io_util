#include "gtest/gtest.h"

#include "csv_io_util/file_system_util.h"

namespace csv_io_util
{
namespace test
{
TEST(FileSystemUtilTest, GetDirectoryFromFilePath)
{
  std::string valid_file_path = "/this/is/a/valid/file_path.txt";
  std::string valid_directory_path = getDirectoryOfFile(valid_file_path);
  EXPECT_EQ(valid_directory_path, "/this/is/a/valid");

  std::string invalid_path = "thereisnoslash";
  std::string invalid_directory_path = getDirectoryOfFile(invalid_path);
  EXPECT_EQ(invalid_directory_path, "");
}

TEST(FileSystemUtilTest, delteFile)
{
  std::string test_file = "test.xyz";

  deleteFile(test_file);

  std::ofstream out_stream(test_file);
  out_stream.close();

  EXPECT_TRUE(checkIfFileExists(test_file));

  deleteFile(test_file);

  EXPECT_FALSE(checkIfFileExists(test_file));
}
}  // namespace test
}  // namespace csv_io_util

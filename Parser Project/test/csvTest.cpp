#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "csvHandler.h"

class CsvFileHandlerTest : public ::testing::Test
{
protected:
    CsvFileHandler validObj;
    CsvFileHandler invalidObj;
    std::string validFileName = "dataCsv.csv";
    std::string invalidFileName = "data.csv";
    CsvFileHandlerTest() : validObj(validFileName), invalidObj(invalidFileName) {}
};
TEST_F(CsvFileHandlerTest, WhenFileIsOpenedThenReturnTrue)
{
    bool result = validObj.openingFile();
    EXPECT_TRUE(result);
}
TEST_F(CsvFileHandlerTest, WhenFileIsNotOpenedThenReturnFalse)
{
    bool result = invalidObj.openingFile();
    EXPECT_FALSE(result);
}

TEST_F(CsvFileHandlerTest, WhenParsingFileIsValidThenReturnTrue)
{
    EXPECT_EQ(true, validObj.openingFile());
    EXPECT_EQ(true, validObj.parsingFile());
}

TEST_F(CsvFileHandlerTest, WhenParsingFileIsInvalidThenReturnFalse)
{
    EXPECT_EQ(false, invalidObj.openingFile());
    EXPECT_EQ(false, invalidObj.parsingFile());
}

TEST_F(CsvFileHandlerTest, WhenAccesingFileContentIsCorrectThenReturnFalse)
{
    EXPECT_EQ(true, validObj.openingFile());
    EXPECT_EQ(true, validObj.parsingFile());
    EXPECT_EQ(true, validObj.accessingFileContent());
}

TEST_F(CsvFileHandlerTest, WhenAccesingFileContentIfMissingThanReturnFalse)
{
    EXPECT_EQ(false, invalidObj.openingFile());
    EXPECT_EQ(false, invalidObj.parsingFile());
    EXPECT_EQ(false, invalidObj.accessingFileContent());
}
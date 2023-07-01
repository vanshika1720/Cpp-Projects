#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "jsonHandler.h"

class JsonFileHandlerTest : public ::testing::Test
{
    protected:
    JsonFileHandler validObj;
    JsonFileHandler invalidObj;
    std::string validFileName = "data.json";
    std::string invalidFileName = "dataj.json";
    JsonFileHandlerTest():validObj(validFileName),invalidObj(invalidFileName){}
};
TEST_F(JsonFileHandlerTest, WhenFileIsOpenedThanReturnTrue)
{   
    bool result = validObj.openingFile();
    EXPECT_TRUE(result);
}
TEST_F(JsonFileHandlerTest, WhenFileIsNotOpenedThanReturnFalse)
{
    bool result = invalidObj.openingFile();
    EXPECT_FALSE(result);
}

TEST_F(JsonFileHandlerTest, WhenParsingFileIsValidThanReturnTrue)
{
    EXPECT_EQ(true, validObj.openingFile());
    EXPECT_EQ(true, validObj.parsingFile());
}

TEST_F(JsonFileHandlerTest, WhenParsingFileIsInvalidThanReturnF)
{
    EXPECT_EQ(false,invalidObj.openingFile());
    EXPECT_EQ(false,invalidObj.parsingFile()); 
}

TEST_F(JsonFileHandlerTest, WhenAccesingFileContentIsCorrectThanReturnFalse)
{
    EXPECT_EQ(true, validObj.openingFile());
    EXPECT_EQ(true, validObj.parsingFile());
    EXPECT_EQ(true, validObj.accessingFileContent());
}

TEST_F(JsonFileHandlerTest, WhenAccesingFileContentIfMissingThanReturnFalse)
{
    EXPECT_EQ(false,invalidObj.openingFile());
    EXPECT_EQ(false,invalidObj.parsingFile()); 
    EXPECT_EQ(false,invalidObj.accessingFileContent());
}



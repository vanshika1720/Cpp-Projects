#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "xmlHandler.h"

class XmlFileHandlerTest : public ::testing::Test
{
    protected:
    XmlFileHandler validObj;
    XmlFileHandler invalidObj;
    std::string validFileName = "dataXml.xml";
    std::string invalidFileName = "datax.xml";
    XmlFileHandlerTest():validObj(validFileName),invalidObj(invalidFileName){}
};

TEST_F(XmlFileHandlerTest, WhenFileIsOpenedThanReturnTrue)
{   
    bool result = validObj.openingFile();
    EXPECT_TRUE(result);
}
TEST_F(XmlFileHandlerTest, WhenFileIsNotOpenedThanReturnFalse)
{
    bool result = invalidObj.openingFile();
    EXPECT_FALSE(result);
}

TEST_F(XmlFileHandlerTest, WhenParsingFileIsValidThanReturnTrue)
{
    EXPECT_EQ(true,validObj.openingFile());
    EXPECT_EQ(true,validObj.parsingFile());
}

TEST_F(XmlFileHandlerTest, WhenParsingFileIsInvalidThanReturnFalse)
{
    EXPECT_EQ(false,invalidObj.openingFile());
    EXPECT_EQ(false,invalidObj.parsingFile());  
}

TEST_F(XmlFileHandlerTest, WhenAccesingFileContentIsCorrectThanReturnFalse)
{
    EXPECT_EQ(true, validObj.openingFile());
    EXPECT_EQ(true, validObj.parsingFile());
    EXPECT_EQ(true, validObj.accessingFileContent());
}

TEST_F(XmlFileHandlerTest, WhenAccesingFileContentIfMissingThanReturnFalse)
{
    EXPECT_EQ(false,invalidObj.openingFile());
    EXPECT_EQ(false,invalidObj.parsingFile()); 
    EXPECT_EQ(false,invalidObj.accessingFileContent());

}



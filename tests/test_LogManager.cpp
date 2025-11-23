#include <gtest/gtest.h>
#include <fstream>
#include <string>

#include "LogManager.h"

using namespace df;

class LogManagerTest : public ::testing::Test {
protected:
    virtual void SetUp() override {
        // Ensure a clean start state
        LM.shutDown();

        // Remove any old log file
        std::remove(LOGFILE_NAME.c_str());
    }

    virtual void TearDown() override {
        // Clean up after test case
        LM.shutDown();
        std::remove(LOGFILE_NAME.c_str());
    }

    // Helper: read entire log file into a string
    std::string readLogfile() {
        std::ifstream file(LOGFILE_NAME);
        if (!file)
            return "";
        return std::string((std::istreambuf_iterator<char>(file)),
                           std::istreambuf_iterator<char>());
    }
};


// -------------------------------------------------------------
//  Basic startup/shutdown
// -------------------------------------------------------------

TEST_F(LogManagerTest, StartupCreatesLogfile) {
    EXPECT_EQ(LM.startUp(), 0);

    std::ifstream file(LOGFILE_NAME);
    EXPECT_TRUE(file.good());
}


// -------------------------------------------------------------
//  Log level get/set
// -------------------------------------------------------------

TEST_F(LogManagerTest, LogLevelSetGet) {
    LM.startUp();

    LM.setLogLevel(3);
    EXPECT_EQ(LM.getLogLevel(), 3);

    LM.setLogLevel(0);
    EXPECT_EQ(LM.getLogLevel(), 0);
}


// -------------------------------------------------------------
//  Basic writeLog() with formatting
// -------------------------------------------------------------

TEST_F(LogManagerTest, WriteLogWritesToFile) {
    LM.startUp();
    LM.setFlush(true);    // helps ensure file contents are readable

    LM.writeLog("Hello %s!", "world");

    std::string log = readLogfile();
    EXPECT_NE(log.find("Hello world!"), std::string::npos);
}


// -------------------------------------------------------------
//  Log level filtering
// -------------------------------------------------------------

TEST_F(LogManagerTest, WriteLogRespectsLogLevel) {
    LM.startUp();
    LM.setFlush(true);
    LM.setLogLevel(2);

    LM.writeLog(1, "should NOT appear");
    LM.writeLog(3, "should appear");

    std::string log = readLogfile();
    EXPECT_EQ(log.find("should NOT appear"), std::string::npos);
    EXPECT_NE(log.find("should appear"), std::string::npos);
}

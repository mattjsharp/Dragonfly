#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "Manager.h"
#include "GameManager.h"
#include "utility.h"
#include "limits.h"

// Get singleton instance of LogManager.
#define LM df::LogManager::getInstance()

namespace df {

const std::string LOGFILE_NAME = "dragonfly.log";

class LogManager : public Manager {
private:
    LogManager();                       // Private since a singleton.
    LogManager(LogManager const&);      // Don't allow copy.
    void operator=(LogManager const&);  // Don't allow assignment
    bool m_do_flush;        // True if flush to disk after each write.
    int m_log_level;        // Logging level.
    bool m_log_time_string; // True if prepend time.
    bool m_log_step_count;  // True if prepend step count.
    FILE* m_p_f;            // Pointer to logfile struct.

public:
    // If logfile is open, close it.
    ~LogManager() override;

    // Get the one and only instance of the LogManager.
    static LogManager &getInstance();

    // Start up the LogManager (open logfile "dragonfly.log").
    int startUp() override;

    // Shut down the LogManager (close logfile).
    void shutDown() override;

    // Set flush of logfile after write.
    void setFlush(bool do_flush=true);

    // Write to logfile.
    // Supports printf() formatting of strings.
    // Return number of bytes written (excluding prepends), -1 if error.
    int writeLog(const char* fmt, ...) const;

    // Write to logfile.
    // Only write if indicated log level >= LogManager log level.
    // Supports printf() formatting of strings.
    // Return number of bytes written (excluding prepends), -1 if error.
    int writeLog(int log_level, const char *fmt, ...) const;

    // Set logging level.
    void setLogLevel(int log_level);

    // Get the logging level.
    int getLogLevel() const;

    // Set prepend time string to log messages.
    void setLogTimeString(bool log_time_string=true);

    // Set prepend step count to log messages.
    void setLogStepCount(bool log_step_count=true);
};

}

#endif // __LOG_MANAGER_H__

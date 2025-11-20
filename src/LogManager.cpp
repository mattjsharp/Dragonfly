#include "LogManager.h"

namespace df {

    namespace { // Anonymous namespace for local helper functions and constants.
        const size_t PREFIX_BUFFER_SIZE = 128;
        const size_t MESSAGE_BUFFER_SIZE = 1024;

        int getPrefix(
            char* str,
            size_t size,
            bool log_time_string,
            bool log_step_count
        ) {
            int prefix_len = 0;

            str[0] = '\0';

            if (log_time_string)
               prefix_len +=
                    snprintf(
                        str,
                        size,
                        "[%s] ",
                        getTimeString()
                    );

            if (log_step_count)
                prefix_len +=
                    snprintf(
                        str + strlen(str),
                        size - strlen(str),
                        "[%04d] ",
                        GM.getStepCount()
                    );

            return prefix_len;
        }

        int vfwriteLog(
            FILE* f,
            const char* prefix,
            const char* fmt,
            bool do_flush,
            va_list args
        ) {
            char buffer[MESSAGE_BUFFER_SIZE];

            buffer[0] = '\0';

            if (f == NULL)
                return -1;

            int message_len = vsnprintf(buffer, sizeof(buffer), fmt, args);

            if (!fprintf(f, "%s%s\n", prefix, buffer))
                return -1;

            if (do_flush)
                fflush(f);

            return message_len;
        }
    }

    LogManager::LogManager() {
        setType("LogManager");
        m_p_f = NULL;
        m_do_flush = false;
        m_log_time_string = true;
        m_log_step_count = false;
        m_log_level = 1;
    }

    LogManager::~LogManager() {
        shutDown();
    }

    LogManager &LogManager::getInstance() {
        static LogManager instance;
        return instance;
    }

    int LogManager::startUp() {
        Manager::startUp(); // Call base class method to set m_is_started to true.

        m_p_f = fopen(LOGFILE_NAME.c_str(), "w");

        return m_p_f == NULL ? -1 : 0; // 0 if file opens.
    }

    void LogManager::shutDown() {
        Manager::shutDown();

        if (m_p_f != NULL) {
            fclose(m_p_f);
            m_p_f = NULL; // Preventing double-free.
        }
    }

    void LogManager::setFlush(bool do_flush) {
        m_do_flush = do_flush;
    }

    int LogManager::writeLog(const char *fmt, ...) const {
        va_list args;
        va_start(args, fmt);

        char prefix[PREFIX_BUFFER_SIZE];
        getPrefix(prefix, PREFIX_BUFFER_SIZE, m_log_time_string, m_log_step_count);

        int result =
            vfwriteLog(
                m_p_f,
                prefix,
                fmt,
                m_do_flush,
                args
            );

        va_end(args);
        return result;
    }

    int LogManager::writeLog(int log_level, const char *fmt, ...) const {
        if (log_level < m_log_level) {
            return -1;
        }

        char prefix[PREFIX_BUFFER_SIZE];
        getPrefix(prefix, PREFIX_BUFFER_SIZE, m_log_time_string, m_log_step_count);

        va_list args;
        va_start(args, fmt);

        int result =
            vfwriteLog(
                m_p_f,
                prefix,
                fmt,
                m_do_flush,
                args
            );

        va_end(args);
        return result;
    }

    void LogManager::setLogLevel(int log_level) {
        m_log_level = log_level;
    }

    int LogManager::getLogLevel() const {
        return m_log_level;
    }

    void LogManager::setLogTimeString(bool log_time_string) {
        m_log_time_string = log_time_string;
    }

    void LogManager::setLogStepCount(bool log_step_count) {
        m_log_step_count = log_step_count;
    }
}

#include "loger.h"

#include <ctime>
#include <stdio.h>
#include <stdarg.h>

static FILE *logFile = stderr;
static Level lvlLog = INFO;


void openLogFile() {
    logFile = fopen("loger.txt", "a");
    if (logFile == NULL) {
        printf("Log file no open\n");
        return;
    }
    fprintf(logFile, "DAY MOUNTH YEAR HOUR MINUTE SEC\n");
}

void printMessage(const char *text, Level level, ...) { // FIXME vfprintf
    va_list args;
    va_start (args, text);
    if (logFile == NULL)
        return;
    time_t t = time(NULL);
    tm *now = localtime(&t);
    if (level <= lvlLog) {
        fprintf
        (
            logFile, 
            "%-3d %-6d %-4d %-4d %-6d %-3d\t" "%s:\t",
            now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, 
            now->tm_hour, now->tm_min, now->tm_sec, levToS(level) 
        );
        vfprintf(logFile, text, args);
    }

    va_end(args);
}

void closeLogFile() {
    if (logFile != NULL)
        fclose(logFile);
}

const char* levToS(Level level) {
    switch (level) {
        case INFO: return "INFO";
        case DEBUG: return "DEBUG";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL_ERROR: return "CRITICAL ERROR";
        default: return "Unknown level";
    }
}
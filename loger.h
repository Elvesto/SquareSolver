#ifndef LOGER_H_
#define LOGER_H_

enum Level {
    CRITICAL_ERROR = 0,
    ERROR,
    WARNING,
    DEBUG,
    INFO
};

void openLogFile();
void printMessage(const char *text, Level level, ...);
void closeLogFile();
const char* levToS(Level level);

#endif // LOGER_H_
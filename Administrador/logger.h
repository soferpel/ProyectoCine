#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} LogLevel;

typedef struct {
    FILE *file;
    LogLevel level;
} Logger;

Logger *logger_init(const char *filename, LogLevel level);
void logger_close(Logger *logger);
void logger_log(Logger *logger, LogLevel level, const char *format, ...);

#endif

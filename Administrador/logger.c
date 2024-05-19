#include "logger.h"
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

Logger *logger_init(const char *filename, LogLevel level) {
    Logger *logger = malloc(sizeof(Logger));
    if (!logger) {
        perror("Failed to allocate memory for logger");
        return NULL;
    }

    logger->file = fopen(filename, "a");
    if (!logger->file) {
        perror("Failed to open log file");
        free(logger);
        return NULL;
    }

    logger->level = level;
    return logger;
}

void logger_close(Logger *logger) {
    if (logger) {
        if (logger->file) {
            fclose(logger->file);
        }
        free(logger);
    }
}

void logger_log(Logger *logger, LogLevel level, const char *format, ...) {
    if (level < logger->level) {
        return;
    }

    const char *level_strings[] = {"DEBUG", "INFO", "WARN", "ERROR"};
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(logger->file, "[%04d-%02d-%02d %02d:%02d:%02d] [%s] ",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec,
            level_strings[level]);

    va_list args;
    va_start(args, format);
    vfprintf(logger->file, format, args);
    va_end(args);

    fprintf(logger->file, "\n");
    fflush(logger->file);
}

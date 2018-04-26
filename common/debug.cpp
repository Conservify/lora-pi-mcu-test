#include <cstdint>
#include <cstdio>

#ifdef ARDUINO
#include <Arduino.h>
#endif

#include "debug.h"

Logger logger;

constexpr int32_t FK_DEBUG_LINE_MAX = 256;

void fklog(const char *f, ...) {
    char buffer[FK_DEBUG_LINE_MAX];
    va_list args;

    va_start(args, f);
    vsnprintf(buffer, FK_DEBUG_LINE_MAX, f, args);
    va_end(args);

    #ifdef ARDUINO
    Serial.print(buffer);
    #else
    fprintf(stderr, buffer);
    #endif
}

void fklogln(const char *f, ...) {
    char buffer[FK_DEBUG_LINE_MAX];
    va_list args;

    va_start(args, f);
    vsnprintf(buffer, FK_DEBUG_LINE_MAX, f, args);
    va_end(args);

    #ifdef ARDUINO
    Serial.println(buffer);
    #else
    fprintf(stderr, buffer);
    fprintf(stderr, "\n");
    #endif
}

Logger& Logger::print(const char *str) {
    #ifdef ARDUINO
    Serial.print(str);
    #else
    fprintf(stderr, str);
    #endif
    return *this;
}

Logger& Logger::printf(const char *f, ...) {
    char buffer[FK_DEBUG_LINE_MAX];
    va_list args;
    va_start(args, f);
    vsnprintf(buffer, FK_DEBUG_LINE_MAX, f, args);
    va_end(args);
    return print(buffer);
}
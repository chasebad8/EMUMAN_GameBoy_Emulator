#include <stdio.h>
#include <string.h>
#include <time.h>
/**
 * A super primative logger allowing for
 * different systems to get logged.
 */


void debug_log(const char* fileName, const char* str)
{
    char* log;
    if (strcmp(fileName, "MMU") == 0) {
        log = "./logs/mmu.log";
    }
    else if (strcmp(fileName, "CPU") == 0) {
        log = "./logs/cpu.log";
    }

    FILE *fp = fopen(log,"a");
    if(fp == NULL)
    {
        fprintf(stderr, "Failed to open log files\n");
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] [%s]: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, "DEBUG", str);

    if(fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close log files\n");
    }
}

void info_log(const char* fileName, const char* str)
{
    char* log;
    if (strcmp(fileName, "MMU") == 0) {
        log = "./logs/mmu.log";
    }
    else if (strcmp(fileName, "CPU") == 0) {
        log = "./logs/cpu.log";
    }

    FILE *fp = fopen(log,"a");
    if(fp == NULL)
    {
        fprintf(stderr, "Failed to open log files\n");
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] [%s]: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, "INFO", str);

    if(fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close log files\n");
    }
}

void error_log(const char* fileName, const char* str)
{
    char* log;
    if (strcmp(fileName, "MMU") == 0) {
        log = "./logs/mmu.log";
    }
    else if (strcmp(fileName, "CPU") == 0) {
        log = "./logs/cpu.log";
    }

    FILE *fp = fopen(log,"a");
    if(fp == NULL)
    {
        fprintf(stderr, "Failed to open log files\n");
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] [%s]: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, "ERROR", str);

    if(fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close log files\n");
    }
}
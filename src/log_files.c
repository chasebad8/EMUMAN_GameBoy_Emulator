#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

void debug_log(FILE *fp, const char* str)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] [%s]: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, "DEBUG", str);
}

void info_log(FILE *fp, const char* str)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] [%s]: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, "INFO", str);
}

void error_log(FILE *fp, const char* str)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(fp, "[%d-%02d-%02d %02d:%02d:%02d] [%s]: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, "ERROR", str);
}

int create_logs(FILE **mmu_fp, FILE **cpu_fp)
{
    *mmu_fp = fopen("./logs/mmu.log", "a");
    if(*mmu_fp == NULL)
    {
        return -1;
    }

    *cpu_fp = fopen("./logs/cpu.log", "a");
    if(*cpu_fp == NULL)
    {
        return -1;
    }

    return 1;
}

int close_logs(FILE **mmu_fp, FILE **cpu_fp)
{
    if(fclose(*mmu_fp) != 0)
    {
        return -1;
    }

    if(fclose(*cpu_fp) != 0)
    {
        return -1;
    }

    return 1;
}
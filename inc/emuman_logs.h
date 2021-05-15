#ifndef EMUMAN_EMUMAN_LOGS_H
#define EMUMAN_EMUMAN_LOGS_H

#endif //EMUMAN_EMUMAN_LOGS_H

int create_logs(FILE **mmu_fp, FILE **cpu_fp);
int close_logs(FILE **mmu_fp, FILE **cpu_fp);
void debug_log(FILE *fp, const char* str);
void info_log(FILE *fp, const char* str);
void error_log(FILE *fp, const char* str);


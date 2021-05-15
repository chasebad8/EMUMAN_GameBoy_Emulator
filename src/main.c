#include <stdio.h>
#include "../inc/emuman_logs.h"
#include <time.h>

FILE *mmu_fp; //MMU log
FILE *cpu_fp; //CPU log

int main() {
    //Open logs for writing
    if(create_logs(&mmu_fp, &cpu_fp) != 1)
    {
        fprintf(stderr, "Failed to open log files\n");
    }

    debug_log(mmu_fp, "We have a working log system!!");


    //Close all created logs
    if(close_logs(&mmu_fp, &cpu_fp) != 1)
    {
        fprintf(stderr, "Failed to close log files\n");
    }

    return 0;
}
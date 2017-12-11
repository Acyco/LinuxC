/* sscanf_example.c -- 使用sscanf函数获取cpu频率 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cpu_t_s
{
    float clock_speed;
    char model_name[1024];
};

void get_cpu_clock_speed (struct  cpu_t_s * cp)
{
    FILE * fp;
    char buffer[2048];
    size_t bytes_read;
    char * match;

    fp = fopen ("/proc/cpuinfo", "r");
    bytes_read = fread (buffer, 1, sizeof (buffer), fp);
    fclose (fp);
    if (bytes_read == 0 || bytes_read > sizeof (buffer))
        exit(0);
    buffer[bytes_read] = '\0';
    match = strstr (buffer, "cpu MHz");
    
    if (match == NULL)
        exit(0);
    sscanf (match, "cpu MHz :%f", &cp->clock_speed);

    match = strstr (buffer, "model name");
    if (match == NULL)
        exit(0);
    sscanf (match, "model name :%s", cp->model_name);
}

int main (void)
{
    struct cpu_t_s * ccp, cpu;
    ccp = &cpu;

    get_cpu_clock_speed (ccp);
    printf ("CPU clock speed: %4.0f MHz\nCPU name:%s\n",
            ccp->clock_speed, ccp->model_name);
    return 0;
}

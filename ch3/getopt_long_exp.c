/* getopt_lon_exp.c */
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

const char * program_name;
void print_usage (FILE * stream, int exit_code)
{
    fprintf (stream, "Usage: %s options [ inputfile ... ]\n", program_name);
    fprintf (stream, " -h --help .\n"
             " -o --output filename.\n"
             " -v --version.\n");
    exit (exit_code);
}

int main (int argc, char * argv[])
{
    int next_option;

    const char* const short_options = "ho:v";
    const struct option long_options[] = {
        { "help", 0, NULL, 'h' },
        { "output", 1, NULL, 'o' },
        { "version", 0, NULL, 'v' },
        { "NULL", 0, NULL, 0 },
    };
    const char * output_filename = NULL;
    program_name = argv[0];
    do
    {
        next_option = getopt_long (argc, argv, short_options, long_options, NULL);
        switch (next_option)
        {
        case 'h':
            print_usage (stdout, 0);
            break;
        case 'o':
            output_filename = optarg;
            execl ("/bin/cat", "cat", output_filename, NULL);
            break;
        case 'v':
            printf ("the version is v1.0\n");
            break;
        case ':':
            break;
        case '?':
            print_usage (stderr, 1);
            break;
        default:
            print_usage (stderr, 1);
            break;
        }
    }while (next_option !=-1);
    return 0;
}


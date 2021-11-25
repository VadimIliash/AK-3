#include <stdio.h>
#include <getopt.h>
#include <string.h>

//Vadim Iliash IV-93

void cycle(int opts,int index, bool help, bool version, bool list, int argc, char **argv) {
    const char *sOptions = "hvm:";
    static struct option lOptions[] = {
            {"help",    no_argument,       0, 'h'},
            {"version", no_argument,       0, 'v'},
            {"m",       required_argument, 0, 'm'},

    };
    const char *hOption =
                          "-h or --help\n"
                          "-v or --version\n"
                          "-m[<val1>,...]";
    while ((opts = getopt_long(argc, argv, sOptions, lOptions, &index)) != -1) {
        switch (opts) {
            case 'h': {
                if (!help) {
                    help = true;
                    printf("%s\n", hOption);
                }
                break;
            }

            case 'v': {
                if (!version) {
                    version = true;
                    printf("3.28.1\n");
                }
                break;
            }
            case 'm': {
                if (!list) {
                    char *args;
                    printf("Option list:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    list = true;
                }
                break;
            }
            default: {
                printf("Mistake!\n");
                
                
            }
        }
        
    }
    
}
int main(int argc, char **argv) {

    bool help, version, list = false;

    int index, opts;
    cycle(opts,index, help, version,  list,  argc,  argv);
    
    return 0;
}





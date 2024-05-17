#include <stdio.h>
#include <stdlib.h>
#include "../libft/ft_isdigit.c"
//#include "../ps_check.c"

// Mock of your `error` function to count errors instead of exiting
int error_count = 0;
void error() {
    error_count++;
	return ;
}

void check_char(char **argv) {
    int i, j;

    if (!argv)
        error();
    i = 1;
    while (argv[i]) {
        j = 0;
        // Check if the first character is + or -; if so, skip it
        if (argv[i][j] == '+' || argv[i][j] == '-')
            j++;
        // After the optional sign, there must be at least one digit
        if (!ft_isdigit(argv[i][j]))
            error();  // Raise error if there's no digit following the sign or if the string is just digits
        // Check remaining characters, all must be digits
        while (argv[i][j]) {
            if (!ft_isdigit(argv[i][j]))
                error();
            j++;
        }
        i++;
    }
}

void test_check_char(char **argv, int expected_errors)
{
    error_count = 0; // Reset error count
    check_char(argv);
    if (error_count == expected_errors)
	{
        printf("Test passed\n");
    } else {
        printf("Test failed: Expected %d errors, but got %d\n", expected_errors, error_count);
    }
}

int main(void) {
    char *str_arr_00[] = {"progname", "1", "45", "67", "27", "894", NULL};      // valid
    char *str_arr_01[] = {"progname", "-1", "-45", "-67", "-27", "-894", NULL}; // valid
    char *str_arr_02[] = {"progname", "1", NULL};                               // valid
    char *str_arr_03[] = {"progname", "-1", NULL};                              // valid
    char *str_arr_05[] = {"progname", "-1", "-45", "-", "-27", "-894", NULL};   // error
    char *str_arr_06[] = {"progname", "-1", "a", "-67", "-27", "-894", NULL};   // error
    char *str_arr_07[] = {"progname", "-1", "-45", "-67", "/-.", "-894", NULL}; // error

    test_check_char(str_arr_00, 0);
    test_check_char(str_arr_01, 0);
    test_check_char(str_arr_02, 0);
    test_check_char(str_arr_03, 0);
    test_check_char(str_arr_05, 1);
    test_check_char(str_arr_06, 1);
    test_check_char(str_arr_07, 1);

    return 0;
}

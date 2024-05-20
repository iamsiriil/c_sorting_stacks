#ifndef TEST_PUSH_SWAP_H
# define TEST_PUSH_SWAP_H

# include <stdio.h>
# include "./push_swap.h"

extern int log_count;

# ifdef DEBUG
# define LOG_MESSAGE(format, ...) \
    do { \
		printf("%03d: in %s: ", ++log_count, __func__); \
        printf(format, ##__VA_ARGS__); \
		fflush(stdout); \
    } while (0)
# else
# define LOG_MESSAGE(format, ...)
# endif

// Test utils
void		print_argv(char **argv);
void		print_arr(long int *arr, int size);
void		print_stack(t_clist *stack);

#endif
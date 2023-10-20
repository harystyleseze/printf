#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS FUNC */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES FUNC*/
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print_func(const char *fmt, int *count,
va_list list_arg, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to handle printing of chars and strings */
int print_character_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);
int print_string_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);
int print_percent_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle printing of numbers */
int print_integer_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);
int print_binary_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);
int print_octal_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_decimal_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_func_upper(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa_func(va_list par_type, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to handle printing non printable characters */
int handles_print_non_printable_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);

/* Function to handle printing memory address */
int handles_print_pointer_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags_func(const char *format, int *count);
int get_width_func(const char *format, int *count, va_list list_arg);
int get_precision_func(const char *format, int *count, va_list list_arg);
int get_size_func(const char *format, int *count);

/*Function to print string in reverse*/
int print_reverse_func(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int func_to_print_rot13_string(va_list par_type, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_character_func(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number_function(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_number_func(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int handles_write_pointer_func(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned_func(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILITIES ******************/
int handles_is_printable_func(char);
int append_hexa_code_func(char, char[], int);
int handles_is_digit_func(char);

long int convert_number_size_func(long int num, int size);
long int convert_unsigned_size_func(unsigned long int num, int size);

#endif /* MAIN_H */

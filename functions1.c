#include "main.h"

/* PRODUCE UNSIGNED NUMBER */
/**
 * print_unsigned - Produce an unsigned number
 * @types: Arrays of arguments
 * @buffer: Print to be handled by the buffer array.
 * @flags:  Sum active flags
 * @width: Return the width
 * @precision: Specification of the Precision.
 * @size: Value specifier
 * Return: Amount of the chars produced.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRODUCE UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal - Produce an unsigned number in the octal notation
 * @types: Arrays of arguments
 * @buffer: print to be handled by the buffer array
 * @flags:  Sum active flags
 * @width: Return the width
 * @precision: Specification of the Precision
 * @size: Value specifier
 * Return: amount of the chars produced
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/* PRODUCE UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* PRODUCE THE UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types:Arrays of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Sum active flags
 * @width: return the width
 * @precision: Precision specification
 * @size: Value specifier
 * Return: Number of the chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* PRINT HEXX NUM IN LOWER OR UPPER */
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Array of arguments
 * @map_to: Array of values to map the number.
 * @buffer: Buffer of array to handle the print
 * @flags:  Sum the active flags
 * @flag_ch: Sum the active flags
 * @width: return width
 * @precision: Precision specification
 * @size: Size specifier
 * @size:Value specification
 * Return: Amount of chars printe
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

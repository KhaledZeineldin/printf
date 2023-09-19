#include "main.h"
/**
 * _printf- writes the string to stdout
 * @format: the string to be printed
 *
 * Return: On success string length
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, flag = 6, index_counter = 0; 

	va_start (args, format);
	if(format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (!format || (format[0] == '%' && !format[1]))
			break;
		if (*format == '%' && *(format + 1) == ' ' && !*(format + 2))
			return (count);

		if (*format != '%' && *format != '\0')
		{
			_putchar(*format);
			count++;
			format++;
		}
		else if (*format == '%')
		{ 
			format++; 
			if (*(format) == ' ')
			{
				while (*format == ' ')
				{
					format++;
				}


			}
			if (*format == '\0')
				break; 
			if (*format == 'c')
			{
				unsigned char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
				{
					count += _printf("(null)");
				}
				else
				{
					while (*str)
					{
						_putchar(*str);
						str++;
						count++;
					}
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' )
			{
				int num = va_arg(args, int);
				count+=print_decimal(num);
			}
			else if (*format == 'i')
			{
				int num = va_arg(args, int);
				count+=print_decimal(num);
			}
			else if (*format == 'r')
			{
				char * str = va_arg(args, char *);
				while (str[index_counter] != '\0')
				{
					index_counter++;
				}
				index_counter--;
				while (index_counter >= 0)
				{
					_putchar(str[index_counter]);
					index_counter--;
					count++;
				}
			}
			else
			{
				while (*format >= '0' && *format <= '9')
				{
					format++;
					if (*format >= '0' && *format <= '9')
					{
						flag  = 0;
					}
					else
					{
						if (*format != '\0')
						{
							flag = 1;
							break;
						}

					}
				}
				if (flag == 1)
				{
					return(-1);
				}
				else if (flag == 0)
				{
					return (count);
				}
				else 
				{
					return (-1);
				}
			}
			format++;
		}
	}
	va_end (args);
	return (count);
}

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"


/*int main()
{
	char *line = NULL;
	int ret;
	while((ret = get_next_line(0, &line)) > 0)
	{
		printf (" RET -> %d", ret);
		printf(" -> %s\n", line);
		if (line)
			free(line);
	}
	return 0;
}*/


/*
**  1 line with 8 chars with Line Feed gnl1_1.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors; 

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl1_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			count_lines++;
			printf (" RET = %d", ret);
			if (count_lines > 50)
				break;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" instead of \"%sF\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/


/*
** 2 lines with 8 chars with Line Feed gnl1_2.c
*/
/*
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl1_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" and \"abcdefg\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
*/

/*
** 4 lines with 8 chars with Line Feed gnl1_3.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl1_3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
			{
				errors++;
				printf ("errors 1 = %d\n", errors);
			}
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			{
				errors++;
				printf ("errors 2 = %d\n", errors);
			}
			if (count_lines == 2 && strcmp(line, "4567890") != 0)
			{
				errors++;
				printf ("errors 3 = %d\n", errors);
			}
			if (count_lines == 3 && strcmp(line, "defghij") != 0)
			{
				errors++;
				printf ("errors 4 = %d\n", errors);
			}
			count_lines++;
			printf ("COUNT = %d\n", count_lines);
			if (count_lines > 50)
				break;
		}
		close(fd);
		if (count_lines != 4)
			printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghij\"\n");
		if (count_lines == 4 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/

/*
** 1 line via STDIN with 8 chars with Line Feed gnl2_1.c
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");
	return (0);
}

/*
** 2 lines via STDIN with 8 chars with Line Feed gnl2_2.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 2)
		printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\" and \"abcdefg\"\n");
	if (count_lines == 2 && errors == 0)
		printf("OK\n");
	return (0);
}*/

/*
** 4 lines via STDIN with 8 chars with Line Feed gnl2_3.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			errors++;
		if (count_lines == 2 && strcmp(line, "4567890") != 0)
			errors++;
		if (count_lines == 3 && strcmp(line, "defghij") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 4)
		printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghij\"\n");
	if (count_lines == 4 && errors == 0)
		printf("OK\n");
	return (0);
}*/

/*
** 1 line with 16 chars with Line Feed gnl3_1.c
*/
/*
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl3_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567890abcde\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK Sylvain\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/

/*
** 2 lines with 16 chars with Line Feed gnl3_2.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl3_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567890abcde\" and \"fghijklmnopqrst\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/

//4 lines 16 chars with Line Feed (gnl3_3.c):

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl3_3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
			{
				errors++;
				printf ("errors 1 = %d\n", errors);
			}
			if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
			{
				errors++;
				printf ("errors 2 = %d\n", errors);
			}
			if (count_lines == 2 && strcmp(line, "edcba0987654321") != 0)
			{
				errors++;
				printf ("errors 3 = %d\n", errors);
			}
			if (count_lines == 3 && strcmp(line, "tsrqponmlkjihgf") != 0)
			{
				errors++;
				printf ("errors 4 = %d\n", errors);
			}
			printf ("COUNT = %d\n", count_lines);	
			count_lines++;
			
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 4)
			printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567890abcde\", \"fghijklmnopqrst\", \"edcba0987654321\" and \"tsrqponmlkjihgf\"\n");
		if (count_lines == 4 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/

/*
** 1 line via STDIN with 16 chars with Line Feed gnl4_1.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567890abcde\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");
	return (0);
}*/


/*
** 2 lines via STDIN with 16 chars with Line Feed gnl4_2.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 2)
		printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567890abcde\" and \"fghijklmnopqrst\"\n");
	if (count_lines == 2 && errors == 0)
		printf("OK\n");
	return (0);
}*/

/*
** 4 lines via STDIN with 16 chars with Line Feed gnl4_3.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
			errors++;
		if (count_lines == 2 && strcmp(line, "edcba0987654321") != 0)
			errors++;
		if (count_lines == 3 && strcmp(line, "tsrqponmlkjihgf") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 4)
		printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567890abcde\", \"fghijklmnopqrst\", \"edcba0987654321\" and \"tsrqponmlkjihgf\"\n");
	if (count_lines == 4 && errors == 0)
		printf("OK\n");
	return (0);
}
*/



/*
** 1 line with 4 chars with Line Feed gnl5_1.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl5_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "123") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"123\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s", filename);
	return (0);
}*/


/*
** 2 lines with 4 chars with Line Feed gnl5_2.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl5_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "123") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abc") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"123\" and \"abc\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
} */

/*
** 4 lines with 4 chars with Line Feed gnl5_3.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl5_3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "123") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abc") != 0)
				errors++;
			if (count_lines == 2 && strcmp(line, "456") != 0)
				errors++;
			if (count_lines == 3 && strcmp(line, "def") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 4)
			printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"123\", \"abc\", \"456\" and \"def\"\n");
		if (count_lines == 4 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/

/*
** 1 line via STDIN with 4 chars with Line Feed gnl6_1.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "123") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"123\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");
	return (0);
}*/


/*
** 2 lines via STDIN with 4 chars with Line Feed gnl6_2.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "123") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abc") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 2)
		printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"123\" and \"abc\"\n");
	if (count_lines == 2 && errors == 0)
		printf("OK\n");
	return (0);
}*/

/*
** 4 lines via STDIN with 4 chars with Line Feed gnl6_3.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "123") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abc") != 0)
			errors++;
		if (count_lines == 2 && strcmp(line, "456") != 0)
			errors++;
		if (count_lines == 3 && strcmp(line, "def") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 4)
		printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"123\", \"abc\", \"456\" and \"def\"\n");
	if (count_lines == 4 && errors == 0)
		printf("OK\n");
	return (0);
}*/

/*int main()
{
	char *line = NULL;
	while(get_next_line(0, &line) > 0)
	{
		printf(" -> %s\n", line);
	}
	free(line);
	return 0;
}*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl7_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "12345678") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		printf ("RET = %d", ret);
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/


/*
** 2 lines with 8 chars without Line Feed gnl7_2.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl7_2.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
				errors++;
			if (count_lines == 1 && strcmp(line, "abcdefgh") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 2)
			printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" and \"abcdefgh\"\n");
		if (count_lines == 2 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "/Users/spetitcu/Documents/doc101/get_next_line/gnl7_3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
			{
				errors++;
				printf(" countlines1 = %d\n", count_lines);
			}
			if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			{
				errors++;
				printf(" countlines2 = %d\n", count_lines);
			}
			if (count_lines == 2 && strcmp(line, "4567890") != 0)
			{
				errors++;
				printf(" countlines3 = %d\n", count_lines);
			}
			if (count_lines == 3 && strcmp(line, "defghijk") != 0)
			{
				errors++;
				printf(" countlines4 = %d\n", count_lines);
			}
			count_lines++;
			printf ("COUNT = %d\n", count_lines);
			printf(" \033[33m LINE MAIN = %s\n\033[00m", line);		
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 4)
			printf("-> should have returned '1' four times instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> should have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghijk\"\n");
		if (count_lines == 4 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}*/

/*
** 1 line via STDIN with 8 chars without Line Feed gnl8_1.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "12345678") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 1)
		printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
	if (count_lines == 1 && errors == 0)
		printf("OK\n");
	return (0);
}*/


/*
** 2 lines via STDIN with 8 chars without Line Feed gnl8_2.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abcdefgh") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 2)
		printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\" and \"abcdefgh\"\n");
	if (count_lines == 2 && errors == 0)
		printf("OK");
	return (0);
}*/


/*
** 4 lines via STDIN with 8 chars without Line Feed gnl8_3.c
*/

/*int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "abcdefg") != 0)
			errors++;
		if (count_lines == 2 && strcmp(line, "4567890") != 0)
			errors++;
		if (count_lines == 3 && strcmp(line, "defghijk") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 4)
		printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567\", \"abcdefg\", \"4567890\" and \"defghijk\"\n");
	if (count_lines == 4 && errors == 0)
		printf("OK\n");
	return (0);
}*/
/*int				main(void)
{
	char		*line1;
	int			fd1;
	int			ret1;
	char		*filename1;
	int			errors;

	filename1 = "/Users/spetitcu/Documents/doc101/get_next_line/gnl11_1.txt";
	fd1 = open(filename1, O_RDONLY);

	if (fd1 > 2)
	{
		errors = 0;
		line1 = NULL;


		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The getdelim() function reads a line from stream, delimited by the character") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The getdelim() function reads a line from stream, delimited by the character\" from file %s\n", filename1);
            printf("\033[33;01mNUM --->  1\n\033[00m");
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "delimiter.  The getline() function is equivalent to getdelim() with the new-") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"delimiter.  The getline() function is equivalent to getdelim() with the new-\" from file %s\n", filename1);
			printf("\033[33;01mNUM --->  2\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "line character as the delimiter.  The delimiter character is included as") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"line character as the delimiter.  The delimiter character is included as\" from file %s\n", filename1);
			printf("\033[33;01mNUM --->  3\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "part of the line, unless the end of the file is reached.") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"part of the line, unless the end of the file is reached.\" from file %s\n", filename1);
			printf("\033[33;01mNUM --->  4\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"\" from file %s\n", filename1);
			printf("\033[33;01m NUM --->  10\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The caller may provide a pointer to a malloced buffer for the line in") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"The caller may provide a pointer to a malloced buffer for the line in\" from file %s\n", filename1);
			printf("\033[33;01m NUM ---> 11\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linep, and the capacity of that buffer in *linecapp.  These functions") != 0)
		{
			printf("-> must have returned '1' and read line #7 \"*linep, and the capacity of that buffer in *linecapp.  These functions\" from file %s\n", filename1);
			printf("\033[33;01m NUM --->  12\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "expand the buffer as needed, as if via realloc().  If linep points to a NULL") != 0)
		{
			printf("-> must have returned '1' and read line #8 \"expand the buffer as needed, as if via realloc().  If linep points to a NULL\" from file %s\n", filename1);
			printf("\033[33;01m NUM --->  13\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "pointer, a new buffer will be allocated.  In either case, *linep and") != 0)
		{
			printf("-> must have returned '1' and read line #9 \"pointer, a new buffer will be allocated.  In either case, *linep and\" from file %s\n", filename1);
			printf("\033[33;01m NUM --->  14\n\033[00m");
            errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linecapp will be up-dated accordingly.") != 0)
		{
			printf("-> must have returned '1' and read line #10 \"*linecapp will be up-dated accordingly.\" from file %s\n", filename1);
			printf("\033[33;01m NUM --->  15\n\033[00m");
            errors++;
		}


		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 0)
		{
			printf("-> must have returned '0' at the end of file %s\n", filename1);
			printf("\033[33;01m NUM --->  18\n\033[00m");
            errors++;
		}

		close(fd1);

		if (errors == 0)
			printf("OK\n");
	}
	else
    {
		printf("An error occured while opening files %s\n", filename1);
        printf("\033[33;01m NUM --->  20\n\033[00m");
    }
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:36:01 by mairive           #+#    #+#             */
/*   Updated: 2024/12/20 16:38:17 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ******************************* */
/* Partie 1 - Fonctions de la libc */
/* ******************************* */

/* DESC: The isalpha() function tests for any character for which isupper(3)
 * or islower(3) is true.
 * The value of the argument must be resprensentable as an unsigned char
 * or the value of EOF.
 *
 * RETURN VALUES: The isalpha function return zero if the character tests false
 * and returns non-zero if the character tests true. */
int					ft_isalpha(int c);

/* DESC: The isdigit() function tests for a decimal digit character.
 * The value of the argument must be representable as an unsigned char
 * or the value of EOF.
 *
 * RETURN VALUES: The isdigit function return zero if the character tests false
 * and return non-zero if the character tests true. */
int					ft_isdigit(int c);

/* DESC: The isalnum() function tests for any character for which isalpha(3) or
 * isdigit(3) is true.
 * The value of the argument must be representable as an unsigned char
 * or the value of EOF.
 *
 * RETURN VALUES: The isalnum() function returns zero if the character tests
 * false and returns non-zero if the character tests true. */
int					ft_isalnum(int c);

/* DESC: Add the 'new' element at the front of the list
 *
 * PARAMETERS
	lst: pointer address to the first element of the list
	new: pointer address of the new element to add to the list */
int					ft_isascii(int c);

/* DESC: The isprint function tests for any printing char, including space
 * The value of the argument must representable as an unsigned char
 * or the value of EOF.
 *
 * RETURN VALUES: The isprint function returns zero if the char tests false
 * and returns non-zero if the character tests true. */
int					ft_isprint(int c);

/* DESC: The strlen() function computes the length of the string s.
 *
 * RETURN VALUES: The strlen() function returns the number of characters that
 * precede the terminating NUL character.*/
size_t				ft_strlen(const char *s);

/* DESC: The memset() function writes len bytes of value c (converted to an
 * unsigned char) to the string b.
 *
 * RETURN VALUES: The memset() function returns its first argument.*/
void				*ft_memset(void *s, int c, size_t n);

/* DESC: The bzero() function writes n zeroed bytes to the string s.
 * If n is zero, bzero() does nothing. */
void				ft_bzero(void *s, size_t n);

/* DESC: The memcpy() function copies n bytes from memory area src to memory
 * area dst. If dst and src overlap, behavior is undefined. Applications in
 * which dst and src might overlap should use memove(3) instead.
 *
 * RETURN VALUES: The memcpy() function returns the original value of dst */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/* DESC: The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap; the copy is always done in a
 * non-destructive manner.
 *
 * RETURN VALUES: The memmove() function returns the original value of dst.*/
void				*ft_memmove(void *dest, const void *src, size_t n);

/* DESC: The strlcpy() function copy strings with the same input parameters and
 * output result as snprintf(3). It is designed to be safer, more consistent,
 * and less error prone replacement for the easily misused function strncpy(3)
 * 	strlcpy() take the full size of the destination buffer and guarantee
 * NUL-termination if there is room. Note that room for the NUL should be
 * included in dstsize. Also note that strlcpy() only operate on true ''C''
 * strings. This means that for strlcpy() src must be NUL-terminated.
 * 	strlcpy() copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0.
 * If the src and dst strings overlap, the behavior is undefined.
 *
 * RETURN VALUES:
 * The strlcpy() function return the total length of the strings it tried to
 * create. That means the length of src.
 * If the return value is >= dstsize, the output string has been truncated.
 * It is the caller's responsibility to handle this.*/
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/* DESC: strlcat function concatenate strings. It is designed to be safer, more
 * consistent, and less error prone replacements for the easily misused
 * function strncat(3).
 * 		strlcat() take the full size of the destination buffer and guarantee
 * NUL-termination if there is room. Note that room for the NUL should be
 * included in dstsize. Also note that strlcat() only operate on true ''C''
 * strings. This means that both src and dst must be NUL-terminated.
 * 		strlcat() appends string src to the end of dst. It will append at most
 * dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
 * dstsize is 0 or the original dst string was longer than dstsize (in practice
 * this should not happen as it means that either dstsize is incorrect or
 * that dst is not a proper string).
 * 	If the src and dst strings overlap, the behavior is undefinded.
 *
 * RETURN VALUES: Like snprintf(3), strlcat() function return the total length
 * of the string it tried to create. That means the initial length of dst plus
 * the length of src.
 * If the return value is >= dstsize, the output string has been truncated.
 * It is the caller's responsibility to handle this.*/
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/* DESC: The toupper() function converts a lower-case letter to the
 * corresponding upper-case letter. The argument must be representable as an
 * unsigned char or the value of EOF.
 *
 * RETURN VALUES: If the argument is a lower-case letter, the toupper() function
 * returns the corresponding upper-casse letter if there is one; otherwise,
 * the argument is returned unchanged. */
int					ft_toupper(int c);

/* DESC: The tolower() function converts an upper-case letter to the
 * corresponding lower-case letter. The argument must be representable as an
 * unsigned char or the value of EOF.
 *
 * RETURN VALUES: If the argument is an upper-case letter, the tolower()
 * function returns the corresponding lower-case letter if there is one;
 * otherwise, the argument is returned unchanged. */
int					ft_tolower(int c);

/* DESC: The strchr() function locates the first occurence of c (converted to
 * a char) in the string pointed to by s. The terminating null character is
 * considered to be part of the string; therefor if c is '\0', the function
 * locate the terminating '\0'.
 *
 * RETURN VALUES:The function strchr() return a pointer to the located
 * character, or NULL if the character does not appear in the string.*/
char				*ft_strchr(const char *s, int c);

/* DESC: The strrchr() function is identical to strchr(), except it locates
 * the last occurence of c.
 *
 * RETURN VALUES: The function strrchr() returns a pointer to the located
 * character, or NULL if the character does not appear in the string.*/
char				*ft_strrchr(const char *s, int c);

/* DESC: The strncmp() function lexicographically compare the null-terminated
 * strings s1 and s2.
 * The strncmp() function compares not more than n characters. Because strncmp()
 * is designed for comparing strings rather than binary data, characters that
 * appear after a '\0' character are not compared.
 *
 * RETURN VALUES: The strncmp() function returns an integer greater than, equal
 * to, or less than 0, according as the string s1 is greater than, equal to,
 * or less than the string s2. The comparison is done using unsigned
 * characters, so that '\200' is greater than '\0'.*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/* DESC: the memchr() function locates the first occurence of c (convered to
 * an unsigned char) in string s.
 *
 * RETURN VALUES: The memchr() function returns a pointer to the byte located,
 * or NULL if no such byte exists within n bytes.*/
void				*ft_memchr(const void *s, int c, size_t n);

/* DESC: The memcmp() function compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 *
 * RETURN VALUES: The memcmp() function returns zero if the two strings are
 * identical, otherwise returns the difference betwee the first two differing
 * bytes (treated as unsigned char values, so that '\200' is greater than '\0',
 *  for example).
 * Zero-length strings are always identical. This behaviour is not required by
 * C and portable code should only depend on the sign of the returned value.*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/* DESC: The strnstr() function locates the first occurence of the
 * null-terminated string little in the string big, where not more than
 * len characters are searched.
 * Characters that appear after a '\0' character are not searched.
 *
 *
 * RETURN VALUES: If little is an empty string, big is returned; if little
 * occurs nowhere in big, NULL is returned; otherwise a pointer to the
 * first character of the first occurence of little is returned. */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

// DESC: The atoi() function converts the initial portion of the string pointed
// to by str to int representation.
// the string may begin with an arbitrary number of whitespaces as determinded
// y isspace(3).
// After the whitespaces, there can be one single optional '+' or '-' sign.
// The remainder of the string will be converted to an int,stopping at the
// first char wich is not a valid digit.

// RETURN VALUES: The int representation of the string.
int					ft_atoi(const char *nptr);

/* DESC: The calloc() function allocates memory.
 * The allocated memory is aligned such that it can be used for any data type.
 * The calloc() function contigously allocates enough space for count objects
 * that are size bytes of memory each and returns a pointer to the
 * allocated memory.
 * The allocated memory is filled with bytes of value zero.
 *
 * RETURN VALUES: If successful, calloc() returns a pointer to allocated memory
 * If there is an error, they return NULL*/
void				*ft_calloc(size_t nmemb, size_t size);

/* DESC: The strdup() function allocates sufficient memory for a copy of the
 * string s, does the copy, and returns a pointer to it. The pointer may
 * subsequently be used as an argument to the function free(3).
 *
 * If insufficient memory is available, NULL is returned.*/
char				*ft_strdup(const char *s);

/* ************************************ */
/* Partie 2 - Fonctions supplementaires */
/* ************************************ */

/* DESC: Allocate (with malloc(3)) and return a new string from the string s.
 * This new string starts at index 'start' and has a maximum size of 'len'.
 *
 * PARAMETERS
 * 	s: string from which to extract the new string
 * 	start: start index of the new string in the string 's'
 * 	len: maximum size of the new string
 *
 * RETURN VALUES
 * ft_substr() returns the new string; NULL if the memory allocation failed.*/
char				*ft_substr(char const *s, unsigned int start, size_t len);

/* DESC: Allocate (with malloc(3)) and returns a new string resulting from the
 * concatenation of s1 and s2.
 *
 * PARAMETERS
 * 	s1: prefix string
 * 	s2: suffix string
 *
 * 	RETURN VALUES: ft_strjoin() returns the new string; NULL if the memory
 * 	allocation failed.*/
char				*ft_strjoin(char const *s1, char const *s2);

/* DESC: Allocate (with malloc(3)) and returns a copy of s1, without the
 * characters specified in set at the beginning and the end of s1.
 *
 * PARAMETERS
 *   s1: string to trim
 *   set: characters to trim
 *
 * RETURN VALUES ft_strtrim() returns a trimmed copy of s1; NULL if the
 * memory allocation failed.*/
char				*ft_strtrim(char const *s1, char const *s2);

/* DESC: Allocate (with malloc(3)) and returns an array of strings obtained by
 * 	splitting s with the character c, used as delimiter.
 * 	The returned array must be NUL-terminated.
 *
 * PARAMETERS
 * 	s: string to split
 * 	c: delimiter character
 *
 * RETURN VALUES: ft_split() returns an array of strings resulting from the
 * 	splitting of s; NULL if the memory allocation failed */
char				**ft_split(char const *s, char c);

/* DESC: Allocate (with malloc(3)) and returns a string representing n.
 * 	Negative numbers must be handled.
 *
 * PARAMETERS
	n: int to convert
 *
 * RETURN VALUES: ft_itoa() returns the string representing n;
 * 	NULL if the memory allocation failed.*/
char				*ft_itoa(int n);

/* DESC: Apply the function 'f' to each characters in the string 's' to create
 * a new string (with malloc) resulting of the successive applications of 'f'.
 *
 * PARAMETERS
	s: string over which to iterate
	f: function to apply to each character

 * RETURN VALUES: ft_strmapi() returns a new string resulting of the
 * successive applications of 'f'; NULL if the memory allocations failed.*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* DESC: Apply the function 'f' to each characters of the string 's', passing
 * its index as a first parameter.
 * Each character is transmitted by address to 'f' so it can be modified if
 * necessary.*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*DESC: The ft_putchar_fd() function writes the character c on the file
 * descriptor fd.
 *
 * PARAMETERS
	c: character to write
	fd: file descriptor on which to write */
void				ft_putchar_fd(char c, int fd);

/* DESC: Write the string s on the file descriptor fd.
 *
 * PARAMETERS
	s: string to write
	fd: file descriptor on which to write */
void				ft_putstr_fd(char *s, int fd);

/* DESC: ft_putendl_fd() writes the string s, followed by a newline, on the
 * file descriptor fd
 *
 * PARAMETERS
	s: string to write
	fd: the file descriptor on which to write */
void				ft_putendl_fd(char *s, int fd);

/* DESC: ft_putnbr_fd() writes the int n on the file descriptor fd
 *
 * PARAMETERS
	n: int to write
	fd: file descriptor on which to write */
void				ft_putnbr_fd(int n, int fd);

/* ********************************************************************** */
/*                   Partie bonus - Listes chainees                       */
/* ********************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* DESC: Allocate with malloc and return a new element/node.
 * Initialize element->content with whatever is in 'content' and next to NULL.
 *
 * PARAM: content: the content of the new element.
 *
 * RETURN: the new element. */
t_list				*ft_lstnew(void *content);

/* DESC: Add the 'new' element at the front of the list
 *
 * PARAMETERS
	lst: pointer address to the first element of the list
	new: pointer address of the new element to add to the list */
void				ft_lstadd_front(t_list **lst, t_list *new);

/* DESC: Count the number of elements of the list
 *
 * PARAMETERS: lst: start of the list
 *
 * RETURN VALUES: The size of the list */
int					ft_lstsize(t_list *lst);

/* DESC: Returns the last element of the list
 *
 * PARAMETERS:
	lst: the start of the list

 * RETURN VALUES: Last element of the list */
t_list				*ft_lstlast(t_list *lst);

/* DESC: Add the 'new' element at the back of the list.
 *
 * RETURN: No return value
 *
 * PARAM:	lst: pointer adress of the first element of the list
 * 			new: pointer adress of the new element to add to the list */
void				ft_lstadd_back(t_list **lst, t_list *new);

/* DESC: Free the memory of the element passed as parameter using the 'del'
 * function then free(3). The memory of 'next' must not be freed.
 *
 * PARAMETERS
	lst: the element to free
	del: address of the function that can delete the element's conten */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/* DESC: Deletes and free the memory of the element passed as parameter and all
 * the following elements using 'del' and free(3). Finally, the initial pointer
 * must be set to NULL.
 *
 * PARAMETERS
	lst: pointer address to one element
	del: address of the function that can delete the element's content  */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/* PARAM lst: pointer adress to one element \ f: function to apply
 * DESC: Iterate over the list 'lst' and apply the function 'f' to the content
 * of all elements. */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/* DESC: Iterate over the list 'lst' and apply the function 'f' to the content
 * of each elements. Create a new list resulting of the successive applications
 * of 'f'. The function 'del' is used to destroy the content of an element
 * if necessary.
 *
 * PARAM:	lst: pointer adress to the first element
 * 			f: adress of the function to apply
 * 			del: adress of the function to delete an element's content
 *
 * RETURN: the new list or NULL if malloc fails. */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ********************************************************************** */
/*                  Ajout de ft_printf and co                             */
/* ********************************************************************** */

/* DESC: Outputs the character c to the standard output.
 *
 * PARAMETERS
 * 	c: character to print
 *
 * RETURN VALUES
 * ft_print_char() returns the number of characters printed. */
int					ft_print_char(char c);

/* DESC: Outputs the string str to the standard output.
 *
 * PARAMETERS
 * 	str: string to print
 *
 * RETURN VALUES
 * ft_print_string() returns the number of characters printed.
 * If str is NULL, the function behaves as if it prints "(null)". */
int					ft_print_string(char *str);

/* DESC: Outputs the memory address ptr in hexadecimal format.
 *
 * PARAMETERS
 * 	ptr: memory address to print
 *
 * RETURN VALUES
 * ft_print_ptr() returns the number of characters printed.
 * If ptr is NULL, the function prints "(nil)". */
int					ft_print_ptr(unsigned long long ptr);

/* DESC: Outputs the signed integer nbr to the standard output.
 *
 * PARAMETERS
 * 	nbr: signed integer to print
 *
 * RETURN VALUES
 * ft_print_nbr() returns the number of characters printed. */
int					ft_print_nbr(int nbr);

/* DESC: Outputs the unsigned integer usgn_nbr to the standard output.
 *
 * PARAMETERS
 * 	usgn_nbr: unsigned integer to print
 *
 * RETURN VALUES
 * ft_print_unsigned() returns the number of characters printed. */
int					ft_print_unsigned(unsigned int usgn_nbr);

/* DESC: Outputs the unsigned integer hexa in hexadecimal format.
 *        The format (uppercase or lowercase) depends on the character c.
 *
 * PARAMETERS
 * 	c: 'x' for lowercase hexadecimal or 'X' for uppercase hexadecimal
 * 	hexa: number to print in hexadecimal
 *
 * RETURN VALUES
 * ft_print_hexa() returns the number of characters printed.
 * If c is not 'x' or 'X', the behavior is undefined. */
int					ft_print_hexa(char c, unsigned int hexa);

/* DESC: Outputs a value of the type specified by c from the variadic arguments.
 *        Handles the following specifiers: 'c', 's', 'p', 'd', 'i', 'u', 'x',
	'X'.
 *
 * PARAMETERS
 * 	c: type specifier
 * 	args: variadic arguments list containing the value to print
 *
 * RETURN VALUES
 * ft_print_type() returns the number of characters printed.
 * If c is an unsupported specifier, the behavior is undefined. */
int					ft_print_type(char c, va_list args);

/* DESC: A formatted output function that mimics the standard printf function.
 *        Supports the following specifiers: 'c', 's', 'p', 'd', 'i', 'u', 'x',
	'X'.
 *
 * PARAMETERS
 * 	format: format string containing the text and specifiers
 * 	...: variadic arguments corresponding to the specifiers
 *
 * RETURN VALUES
 * ft_printf() returns the total number of characters printed.
 * If an allocation or write error occurs, the behavior is undefined. */
int					ft_printf(const char *format, ...);

/* ********************************************************************** */
/*                 GET NEXT LINE                                          */
/* ********************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//----------------------STRUCT-------------------

// Data structure with:
// - buffer array of size BUFFER_SIZE,
// - position index in the buffer (i_buffer),
// - result of the last read operation.
//
// Enables a single static variable in the program.
struct				s_gnl
{
	char			buffer[BUFFER_SIZE];
	ssize_t			i_buffer;
	ssize_t			res_read;
};

//----------------------FT_UTILS-------------------

/* DESC: Frees the memory pointed to by ptr and sets it to NULL.
 *
 * PARAMETERS
 * 	ptr: pointer to the memory block to free
 *
 * RETURN VALUES
 * free_all() always returns NULL. */
void				*free_all(char *ptr);

/* DESC: Adds a NULL terminator at the current position in the string and
 * returns the string.
 *
 * PARAMETERS
 * 	ptr: string to null-terminate
 * 	i: pointer to the current index in the string
 *
 * RETURN VALUES
 * end_string() returns the input string ptr. */
char				*end_string(char *ptr, ssize_t *i);

/* DESC: Copies n bytes from the memory area src to the memory area dest.
 *
 * PARAMETERS
 * 	dest: destination memory area
 * 	src: source memory area
 * 	n: number of bytes to copy
 *
 * RETURN VALUES
 * ft_memcpy() returns the original value of dest.
 * If dest or src is NULL, the behavior is undefined. */
void				*ft_memcpy(void *dest, const void *src, size_t n);

//----------------------FT_GNL-------------------

/* DESC: Reads the text file pointed to by the file descriptor, one line
 * at a time. Reads continue until a newline or EOF is reached.
 *
 * PARAMETERS
 * 	fd: file descriptor to read from
 *
 * RETURN VALUES
 * get_next_line() returns the next line read, including the newline character.
 * If there is nothing left to read or an error occurs, it returns NULL. */
char				*get_next_line(int fd);

/* DESC: Reads data from the file descriptor and appends it to the existing
 * line buffer, resizing it dynamically.
 *
 * PARAMETERS
 * 	fd: file descriptor to read from
 * 	line: pointer to the current line buffer
 * 	size_line: pointer to the current size of the line buffer
 * 	data: pointer to the buffer management structure
 *
 * RETURN VALUES
 * read_line() returns the updated line buffer or NULL in case of an error. */
char				*read_line(int fd, char *line, ssize_t *size_line,
						struct s_gnl *data);

/* DESC: Refills the buffer in the s_gnl structure with data read from
 * the file descriptor.
 *
 * PARAMETERS
 * 	fd: file descriptor to read from
 * 	data: pointer to the buffer management structure
 *
 * RETURN VALUES
 * refill_buffer() does not return a value. It modifies the buffer in place. */
void				refill_buffer(int fd, struct s_gnl *data);

/* DESC: Resizes the line buffer to accommodate additional characters,
 * updates its size, and copies existing content.
 *
 * PARAMETERS
 * 	line: current line buffer
 * 	size_line: pointer to the current size of the line buffer
 * 	i_line: pointer to the current index in the line buffer
 *
 * RETURN VALUES
   *
   * resize_line() returns the resized buffer 
   * or NULL if memory allocation fails. */
char				*resize_line(char *line, ssize_t *size_line,
						ssize_t *i_line);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

// Assembly functions declarations 
extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);

int main() {
    // Test ft_strlen vs strlen
    const char *test_str = "Hello, Assembly!";
    size_t len_asm = ft_strlen(test_str);
    size_t len_c = strlen(test_str);
    printf("Length of '%s' (Assembly): %zu, (C standard): %zu\n\n", test_str, len_asm, len_c);

    // Test ft_strcpy vs strcpy
    char dest_asm[50], dest_c[50];
    ft_strcpy(dest_asm, test_str);
    strcpy(dest_c, test_str);
    printf("Copied string (Assembly): %s\n", dest_asm);
    printf("Copied string (C standard): %s\n\n", dest_c);

    // Test ft_strcmp vs strcmp
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    const char *str3 = "World";

    int cmp_result_asm1 = ft_strcmp(str1, str2);  // Should return 0
    int cmp_result_c1 = strcmp(str1, str2);      // Should return 0
    int cmp_result_asm2 = ft_strcmp(str1, str3);  // Should return negative value
    int cmp_result_c2 = strcmp(str1, str3);      // Should return negative value

    printf("Comparing '%s' and '%s' (Assembly): %d, (C standard): %d\n", str1, str2, cmp_result_asm1, cmp_result_c1);
    printf("Comparing '%s' and '%s' (Assembly): %d, (C standard): %d\n\n", str1, str3, cmp_result_asm2, cmp_result_c2);

    // Test ft_write vs write
    const char *write_str = "Hello, writing with ft_write and write!\n";
    int fd = STDOUT_FILENO;  // Writing to standard output (stdout)
    ssize_t bytes_written_asm = ft_write(fd, write_str, strlen(write_str));
    ssize_t bytes_written_c = write(fd, write_str, strlen(write_str));
    printf("Bytes written (Assembly): %zd, (C standard): %zd\n\n", bytes_written_asm, bytes_written_c);

    // Test ft_read vs read
    char buffer_asm[100], buffer_c[100];
    int read_fd = open("incredible_poem", O_RDONLY);
    if (read_fd == -1) {
        perror("Error opening file");
        return 1;
    }
    ssize_t bytes_read_asm = ft_read(read_fd, buffer_asm, sizeof(buffer_asm) - 1);
    
    close(read_fd);

    read_fd = open("incredible_poem", O_RDONLY);
    if (read_fd == -1) {
        perror("Error opening file");
        return 1;
    }
    ssize_t bytes_read_c = read(read_fd, buffer_c, sizeof(buffer_c) - 1);
    
    if (bytes_read_asm == -1 || bytes_read_c == -1) {
        perror("Error reading file");
        close(read_fd);
        return 1;
    }

    buffer_asm[bytes_read_asm] = '\0';  // Null-terminate the string
    buffer_c[bytes_read_c] = '\0';      // Null-terminate the string

    printf("Read content (Assembly): \n%s\n", buffer_asm);
    printf("Read content (C standard): \n%s\n", buffer_c);
    close(read_fd);

    return 0;
}

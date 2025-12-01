#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
    int fd = open("random_10mb.txt", O_RDONLY);
    
    if (fd == -1) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Get file size
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        printf("Error: Could not get file size\n");
        close(fd);
        return 1;
    }

    // Map file into memory
    char *file_data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        printf("Error: Could not map file\n");
        close(fd);
        return 1;
    }

    long total = 0;
    
    // Sum all bytes in the mapped memory
    for (off_t i = 0; i < sb.st_size; i++) {
        total += (unsigned char) file_data[i];
    }
    
    // Cleanup
    munmap(file_data, sb.st_size);
    close(fd);
    
    printf("%ld\n", total);

    return 0;
}
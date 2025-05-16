#include <unistd.h> 
 
int main() { 
const char *dir = "/path/to/empty/directory"; 
// Attempt to remove the directory 
if (rmdir(dir) == 0) { 
printf("Directory removed successfully.\n"); 
} else { 
perror("rmdir"); 
} 
return 0; 
}

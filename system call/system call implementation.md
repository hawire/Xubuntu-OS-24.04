The rmdir() system call is used to remove an empty directory from the filesystem. It is part 
of the POSIX standard and is implemented in the Linux kernel. The directory must be empty 
(i.e., it should not contain any files or subdirectories, except for the special entries . and 
..#include <stdio.h> 



**Explanation** 
- Include <unistd.h> for the rmdir() system call.
-  Provide the path to the empty directory you want to remove.
- Use rmdir() to remove the directory. It returns 0 on success; otherwise, it returns -1 
   and sets errno to indicate the error.
- Use perror() to display the error message if the call fails.

  
**Common Errors**
- Directory Not Empty: rmdir() can only remove empty directories. 
- Permission Denied: Ensure you have the necessary permissions. 
- Invalid Path: Verify the directory path exists and is correct.

  
**System Call Invocation:**
  When you call rmdir() in your program, it interacts with the 
kernel to perform the operation. The kernel checks the directory's attributes and ensures it 
meets the conditions for removal.


**Conditions for Success:** 
   - The directory must be empty. 
   - The user must have write and execute permissions on the parent directory. 
   - The filesystem must support directory removal (e.g., ext4, Btrfs, etc.).
     

**Kernel-Level Operations:** 
   - The kernel verifies that the directory is empty by checking its inode.
   - If the directory is empty, the kernel removes the directory entry from its parent directory.
   - The inode associated with the directory is deallocated.


**Return Values**
- Success: Returns 0. 
- Failure: Returns -1 and sets errno to indicate the error. 


**Common Errors (errno)** 
- EACCES: Permission denied to access the directory or its parent. 
- ENOTEMPTY: The directory is not empty. 
- ENOENT: The specified directory does not exist. 
- EPERM: The directory cannot be removed due to filesystem restrictions. 
- EBUSY: The directory is in use (e.g., as a mount point or the current working directory).



```
#include <stdio.h> 
#include <unistd.h> 
#include <errno.h> 
int main() { 
  const char *dir = "/path/to/empty/directory"; 
      // Attempt to remove the directory 
if (rmdir(dir) == 0) { 
   printf("Directory '%s' removed successfully.\n", dir); 
} else { 
     // Print error message based on errno 
switch (errno) { 
  case EACCES: 
     perror("Permission denied"); 
     break; 
  case ENOTEMPTY: 
    perror("Directory not empty"); 
    break; 
case ENOENT: 
  perror("Directory does not exist"); 
  break; 
case EPERM: 
  perror("Operation not permitted"); 
  break; 
case EBUSY: 
  perror("Directory is in use"); 
  break; 
default: 
  perror("Error removing directory"); 
  }
} 
 return 0;
} 

```

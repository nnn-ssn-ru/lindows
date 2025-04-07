#include <stdio.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

int main() {
    mount("proc", "/proc", "proc", 0, NULL);
    mount("sysfs", "/sys", "sysfs", 0, NULL);
    mount("devtmpfs", "/dev", "devtmpfs", 0, NULL);

    for (int i = 1; i <= 12; i++) {
        char dev[20];
        sprintf(dev, "/dev/tty%d", i);
        mknod(dev, S_IFCHR | 0666, makedev(4, i));
    }

    execl("/bin/sh", "sh", NULL);

    return 0;
}
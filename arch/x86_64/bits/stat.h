/* copied from kernel definition, but with padding replaced
 * by the corresponding correctly-sized userspace types. */

struct stat {
    dev_t           st_dev;     /* ID of device containing file */
    ino_t           st_ino;     /* inode number */
    mode_t          st_mode;    /* protection */
    nlink_t         st_nlink;   /* number of hard links */
    uid_t           st_uid;     /* user ID of owner */
    gid_t           st_gid;     /* group ID of owner */
    dev_t           st_rdev;    /* device ID (if special file) */
    off_t           st_size;    /* total size, in bytes */
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    blksize_t       st_blksize; /* blocksize for file system I/O */
    blkcnt_t        st_blocks;  /* number of blocks allocated */
};


struct dirent {
    unsigned long   d_fileno;   /* file number of entry */
    unsigned long   d_off;      /* directory offset of entry */
    unsigned short  d_reclen;   /* length of this record */
    char            d_name[128];
    char            pad;
    char            d_type;
};

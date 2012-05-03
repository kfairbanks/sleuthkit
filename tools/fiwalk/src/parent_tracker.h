#ifndef PARENT_TRACKER_H
#define PARENT_TRACKER_H

/*
    Logic for keeping track of directory parents and children
    Necessary for systems that do not have pointer in the child back to the parent
*/

#ifdef __cplusplus
#include <list>
#include <stack>

typedef struct PT_DENTRY_INFO{
    int addr;               //inode_num
    int num_entries;
    int num_used_entries;
    int curr_entry;
} PT_DENTRY_INFO;

class parent_tracker{
    private:
    std::list<int> child_list;
    std::stack<PT_DENTRY_INFO> parent_stack;
    int is_dot_or_double_dot(const TSK_FS_FILE *);
    int inc_dentry_counter(PT_DENTRY_INFO *);
    int dec_dentry_counter(PT_DENTRY_INFO *);

    public:

    parent_tracker();
    int add_pt_dentry_info(const TSK_FS_DIR *);
    int stat_dentry_stack();

    int process_dentry(const TSK_FS_DIR *, const TSK_FS_FILE *);


};
#endif


#endif
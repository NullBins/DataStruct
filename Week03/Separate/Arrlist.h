#define MAX 100
#define DEFVAL 50

typedef struct {
    int elem[MAX];
    int size;
} arrlist_t;

arrlist_t list1;
arrlist_t list2;

void init_list(arrlist_t* listp, int size);
int get_index(arrlist_t* listp, int index);
int find_index(arrlist_t* listp, int val);
int get_sum(arrlist_t* listp);
void input_list(arrlist_t* listp);
void print_list(arrlist_t* listp);
void find_loop();
void add_list(arrlist_t* listp, int val);
void insert_list(arrlist_t* listp, int pos, int val);
int delete_list(arrlist_t* listp, int pos);
int update_list(arrlist_t* listp, int pos, int val);
void get_line(int n);
int only_num(int *num);
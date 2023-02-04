struct s1 {
    int a;
    int b;
};

int main(int argc, char **argv) {
    struct s1 *test = &(struct s1){.a = 10, .b = 20,};
}
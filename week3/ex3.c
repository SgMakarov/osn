#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct list_node *prev;
    struct list_node *next;
    int value;

} list_node;

typedef struct {
    list_node *head;
    list_node *tail;
} list;

list create_list() {
    list l;
    l.head = NULL;
    l.tail = NULL;
    return l;
}

list_node *create_node(int value) {
    list_node *ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = NULL;
    ln->prev = NULL;
    return ln;
}

void add_last(list *l, int value) {
    if (l->tail == NULL) {
        l->tail = create_node(value);
        l->head = l->tail;
        return;
    }
    list_node *tmp = create_node(value);

    l->tail->next = (struct list_node *) tmp;
    tmp->prev = (struct list_node *) l->tail;
    l->tail = tmp;
}

void add_first(list *l, int value) {
    if (l->head == NULL) {
        l->head = create_node(value);
        l->tail = l->head;
        return;
    }

    list_node *tmp = create_node(value);
    l->head->prev = (struct list_node *) tmp;
    tmp->next = (struct list_node *) l->head;
    l->head = tmp;

}

int remove_last(list *l) {
    if (l->tail == NULL) return 0;
    int tmp = l->tail->value;
    if (l->tail == l->head) {
        free(l->tail);

        l->tail = NULL;
        l->head = NULL;
        return tmp;
    } else {


        l->tail = (list_node *) (l->tail->prev);
        free(l->tail->next);
        l->tail->next = NULL;
        return tmp;
    }
}

int remove_first(list *l) {
    if (l->tail == NULL) return 0;
    int tmp = l->head->value;
    if (l->head == l->tail) {
        free(l->head);
        l->tail = NULL;
        l->head = NULL;
        return tmp;
    } else {
        l->head = (list_node *) (l->head->next);
        free(l->head->prev);
        l->head->prev = NULL;
        return tmp;
    }
}

void print_list(list l) {
    list_node *iterator = l.head;
    printf("[ ");
    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = (list_node *) iterator->next;
    }
    fputc(']', stdout);
    fputc('\n', stdout);
}

void print_list_reverse(list l) {
    list_node *iterator = l.tail;
    printf("[ ");
    while (iterator != NULL) {
        printf("%d ", iterator->value);
        iterator = (list_node *) iterator->prev;
    }
    fputc(']', stdout);
    fputc('\n', stdout);
}

int main() {
    list l = create_list();
    add_first(&l, 1);
    add_first(&l, 0);
    add_first(&l, -1);
    add_last(&l, 2);
    add_last(&l, 3);
    add_last(&l, 4);

    print_list(l);
    print_list_reverse(l);
    fputc('\n', stdout);

    printf("deleted %d\n", remove_last(&l));
    printf("deleted %d\n", remove_last(&l));
    fputc('\n', stdout);


    print_list(l);
    print_list_reverse(l);
    fputc('\n', stdout);


    printf("deleted %d\n", remove_first(&l));
    printf("deleted %d\n", remove_first(&l));
    fputc('\n', stdout);

    print_list(l);
    print_list_reverse(l);
    fputc('\n', stdout);

    printf("deleted %d\n", remove_first(&l));
    printf("deleted %d\n", remove_first(&l));
    fputc('\n', stdout);

    print_list(l);


}

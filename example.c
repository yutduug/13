
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[40];
};

int main(void)
{
    int i;
    struct Book **bookshelf;

    // 구조체 포인터 3개 동적 할당
    bookshelf = (struct Book **)malloc(3 * sizeof(struct Book *));

    if (bookshelf == NULL) {
        printf("메모리 할당 오류\n");
        return 1;
    }

    // 각 포인터마다 Book 구조체 10개씩 동적 할당
    for (i = 0; i < 3; i++) {
        bookshelf[i] = (struct Book *)malloc(10 * sizeof(struct Book));

        if (bookshelf[i] == NULL) {
            printf("메모리 할당 오류\n");

            for (int j = 0; j < i; j++) {
                free(bookshelf[j]);
            }

            free(bookshelf);
            return 1;
        }
    }

    // 데이터 저장
    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ Programming");

    (bookshelf[2] + 4)->number = 3;
    strcpy((bookshelf[2] + 4)->title, "Communications Theory");

    // 데이터 출력
    printf("book (1,3) : %d, %s\n",
           (bookshelf[1] + 3)->number,
           (bookshelf[1] + 3)->title);

    printf("book (2,4) : %d, %s\n",
           bookshelf[2][4].number,
           bookshelf[2][4].title);

    // 동적 메모리 반납
    for (i = 0; i < 3; i++) {
        free(bookshelf[i]);
    }

    free(bookshelf);

    return 0;
}

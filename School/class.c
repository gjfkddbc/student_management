#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand,srand
#include <time.h> //time
#include <string.h> //strcmp
#include <math.h> //pow

char name[101][101] = { 0 };
double id[100] = { 0 };
int point[100] = { 0 };
char book[101][101] = { 0 };
char mode= 's';
char answer = 'y';
double number_answer = 0;
int name_count = 0;
char name_check[101] = { 0 };
int id_make[10] = { 0 };
double id_check = 0;
int a; //scanf,getchar 값을 반환하기 위해 사용
//C 6262(스택사이즈 초과)를 해결하기 위해 전역 변수로 선언

//scanf 뒤 getchar는 남아있는 버퍼를 제거하기위해 사용함
int main() {
    srand((unsigned int)time(NULL));

    printf("****************** WARNING: When you choose mode or y/n, enter only one letter ********************\n");

    while (1) {

        //start mode
        while (mode == 's') {
            printf("Choose your menu (number)\n");
            if (name[0][0] == 0) {
                printf("* No one registered, register first *\n");
            }
            printf("1. register mode\n2. advantage point mode\n3. book mode\n> ");
        Choose:

            a = scanf("%lf", &number_answer);
            a = getchar();
          
            switch ((int)number_answer) {
            case 1: 
                mode = 'r';
                break;
            case 2: 
                mode = 'a';
                break;
            case 3: 
                mode = 'b';
                break;
            default: 
                mode = 'm';//mistake
                printf("Choose again\n> ");
                goto Choose;
            }
            printf("\n");
        }

        //register mode
        while (mode == 'r') {


            printf("What's student's name? \n> ");
            a = scanf("%s", &name_check);
            a = getchar();

            for (int i = 0; i < 10;i++) {

                int compare = strcmp(name[i], name_check);

                if (compare == 0) {

                    printf("already registered\n");

                    printf("%s's id is ", name[i]);

                    printf("%.0lf", id[i]);

                    printf("\n\n");
                    goto Exit;
                }

            }

            for (int i = 0;i < 101;i++) {
                name[name_count][i] = name_check[i];
            }

        Again:

            for (int i = 0;i < 10;i++)
                id_make[i] = rand() % 9 + 1;

            for (int i = 0;i < 10;i++) {
                id_check = id_check + (id_make[i] * (pow(10, i)));
            }

            for (int i = 0;i < 100;i++) {
                if (id_check == id[i]) {

                    goto Again;

                }

            }

            id[name_count] = id_check;

            printf("%s's id is %.0lf\n\n", name[name_count], id[name_count]);

            name_count++;

        Exit:

            printf("Would you like to register more? [y/n] \n> ");
            
        Question:

            a = scanf("%s", &answer);
            a = getchar();
            printf("\n");

            if (answer == 'y') {
                mode = 'r';
            }
            else if (answer == 'n')
            {
                mode = 's';
            }
            else {
                mode = 'm';
                //printf("Ifyou enter more than two letter, press enter a few times\n");
                printf("Choose again\n> ");
                goto Question;
            }

        }

        //advantage point mode
        while (mode == 'a') {
            
            printf("Enter your id\n> ");
            a = scanf("%lf", &number_answer);
            //a = getchar();
            
            for  (int i = 0; i < 101; i++){
                if (number_answer == id[i]) {
                    printf("%s's point is %d\n\n", name[i], point[i]);
                    goto Finish;
                }
            }

            printf("ID does not exist \n\n");

        Finish:

            printf("Would you like to stay here? [y/n] \n> ");
        Ask:


            a = scanf("%s", &answer);
            a = getchar();
            printf("\n");

            if (answer == 'y') {
                mode = 'a';
            }
            else if (answer == 'n')
            {
                mode = 's';
            }
            else {
                mode = 'm';
               // printf("Ifyou enter more than two letter, press enter a few times\n");
                printf("Choose again\n> ");
                goto Ask;
            }
        }

        //book mode
        while (mode == 'b') {

            printf("Enter your id\n> ");
            a = scanf("%lf", &number_answer);
            a = getchar();

            for (int i = 0; i < 101; i++) {
                if (number_answer == id[i]) {
                    printf("%s borrows %s\n\n", name[i], book[i]);
                    goto End;
                }
            }

            printf("ID does not exist \n\n");

        End:

            printf("Would you like to stay here? [y/n] \n> ");
        Back:


            a = scanf("%s", &answer);
            a = getchar();
            printf("\n");

            if (answer == 'y') {
                mode = 'b';
            }
            else if (answer == 'n')
            {
                mode = 's';
            }
            else {
                mode = 'm';
                //printf("If you enter more than two letter, press enter a few times\n");
                printf("Choose again\n> ");
                goto Back;
            }
        }

    }

}

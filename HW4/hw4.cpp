#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string>
#include <string.h>

struct node {
    int value;
    int column;
    int row;
    struct node* next;
};

void datainlink(struct node *current,int Row, int Col, int Val);
void mwrite(struct node *first, struct node *current);
void mtranspose(struct node *first, struct node *current);
void mmult(struct node *f1, struct node *f2,int num_col_f1,int num_row_f1,int num_col_f2,int num_row_f2);

int main()
{
    struct node *first1,*current1,*previous1;
    struct node *first2,*current2,*previous2;
    int total_row1 =0;
    int total_col1 =0;
    int total_val1 =0; // # of non-zero.
    int total_row2 =0;
    int total_col2 =0;
    int total_val2 =0; // # of non-zero.
    int temp_row =0;
    int temp_col =0;
    int temp_val =0; // number of each node.
    int flag=0;

    int weight;
    int option;
    char str[100];
    char temp_str[30];
    printf("matrix a: enter number of rows, number of columns, number of nonzero terms.\n");
    gets(str);
    int lastone=strlen(str)-1;

    while(str[lastone]==' ')
        lastone--;

    weight=1;
    while(str[lastone]>='0' && str[lastone]<='9') {
        total_val1 = total_val1 + (str[lastone]-'0')*weight;
        weight*=10;
        lastone--;
    }
    lastone--;
    weight=1;
    while(str[lastone]>='0' && str[lastone]<='9') {
        total_col1 = total_col1 + (str[lastone]-'0')*weight;
        weight*=10;
        lastone--;
    }
    lastone--;
    weight=1;
    while(str[lastone]>='0' && str[lastone]<='9') {
        total_row1 = total_row1 + (str[lastone]-'0')*weight;
        weight*=10;
        lastone--;
    }

    for(int i=0; i<total_val1; i++) {
        gets(str);
        int lastone=strlen(str)-1;

        while(str[lastone]==' ')
            lastone--;

        weight=1;//If the number is 10000, I will parse it until I encounter.
        temp_val=0;
        while(str[lastone]>='0' && str[lastone]<='9') {
            temp_val = temp_val + (str[lastone]-'0')*weight;
            weight*=10;
            lastone--;
        }
        lastone--;
        weight=1;
        temp_col=0;
        while(str[lastone]>='0' && str[lastone]<='9') {
            temp_col = temp_col + (str[lastone]-'0')*weight;
            weight*=10;
            lastone--;
        }
        if(temp_col>=total_col1) { 
            do {
                printf("Your column number is wrong!Please input its column number again.\n");
                gets(temp_str);
                temp_col=atoi(temp_str);
            } while(temp_col>=total_col1);
        }

        lastone--;
        weight=1;
        temp_row=0;
        while(str[lastone]>='0' && str[lastone]<='9') {
            temp_row = temp_row + (str[lastone]-'0')*weight;
            weight*=10;
            lastone--;
        }
        if(temp_row>=total_row1) { 
            do {
                printf("Your row number is wrong!Please input its row number again.\n");
                gets(temp_str);
                temp_row=atoi(temp_str);
            } while(temp_row>=total_row1);
        }

        current1=(struct node *)malloc(sizeof(struct node));
        datainlink(current1,temp_row,temp_col,temp_val);

        if(i==0) {
            first1=current1;  
        } else {
            previous1->next=current1;
        }
        current1->next=NULL; 
        previous1=current1; 

    }

    printf("matrix b: enter number of rows, number of columns, number of nonzero terms.\n");
    gets(str);
    lastone=strlen(str)-1;
    total_row2 =0;
    total_col2 =0;
    total_val2 =0; // # of non-zero.

    while(str[lastone]==' ')
        lastone--;

    weight=1;
    while(str[lastone]>='0' && str[lastone]<='9') {
        total_val2 = total_val2 + (str[lastone]-'0')*weight;
        weight*=10;
        lastone--;
    }
    lastone--;
    weight=1;
    while(str[lastone]>='0' && str[lastone]<='9') {
        total_col2 = total_col2 + (str[lastone]-'0')*weight;
        weight*=10;
        lastone--;
    }
    lastone--;
    weight=1;
    while(str[lastone]>='0' && str[lastone]<='9') {
        total_row2 = total_row2 + (str[lastone]-'0')*weight;
        weight*=10;
        lastone--;
    }


    for(int i=0; i<total_val2; i++) {
        gets(str);
        int lastone=strlen(str)-1;

        while(str[lastone]==' ')
            lastone--;

        weight=1;//If the number is 10000, I will parse it until I encounter .
        temp_val=0;
        while(str[lastone]>='0' && str[lastone]<='9') {
            temp_val = temp_val + (str[lastone]-'0')*weight;
            weight*=10;
            lastone--;
        }
        lastone--;
        weight=1;
        temp_col=0;
        while(str[lastone]>='0' && str[lastone]<='9') {
            temp_col = temp_col + (str[lastone]-'0')*weight;
            weight*=10;
            lastone--;
        }
        if(temp_col>=total_col2) { 
            do {
                printf("Your column number is wrong!Please input its column number again.\n");
                gets(temp_str);
                temp_col=atoi(temp_str);
            } while(temp_col>=total_col2);
        }
        lastone--;
        weight=1;
        temp_row=0;
        while(str[lastone]>='0' && str[lastone]<='9') {
            temp_row = temp_row + (str[lastone]-'0')*weight;
            weight*=10;
            lastone--;
        }
        if(temp_row>=total_row2) { 
            do {
                printf("Your row number is wrong!Please input its row number again.\n");
                gets(temp_str);
                temp_row=atoi(temp_str);
            } while(temp_row>=total_row2);
        }

        !

        current2=(struct node *)malloc(sizeof(struct node));
        datainlink(current2,temp_row,temp_col,temp_val);

        if(i==0) {
            first2=current2;  
        } else {
            previous2->next=current2;
        }
        current2->next=NULL; 
        previous2=current2; 
    }
    printf("----------------(Friendly remind)----------------\n");
    printf("Input 1 make matrix b transposed.(Won't show')\n");
    printf("Input 2 show matrix b's content.(Please after you input 1!)'\n");
    printf("Input 3 show matrix a * b transpose.'\n");
    printf("Input 4 terminate program.'\n");
    printf("----------------(The following is answer.)----------------\n");
    do {
        scanf("%d",&option);
        if(option==1) {
            if(flag==0)
                flag=1;
            else
                flag=0;//to tell whether you tranpose the matrix.
            mtranspose(first2, current2);
        }

        if(option==2) {
            printf("b transpose: \n");
            if(flag==1)
                printf("numRows = %d, numCols = %d \n",total_col2,total_row2);
            if(flag==0)
                printf("numRows = %d, numCols = %d \n",total_row2,total_col2);
            printf("The matrix by row, column and value: \n");
            mwrite(first2, current2);
        }
        if(option==3) {
            printf("a * b transpose: \n");
            printf("numRows = %d, numCols = %d \n",total_row1,total_row2);
            printf("The matrix by row, column and value: \n");
            mmult(first1, first2,total_col1,total_row1,total_col2,total_row2);
        }
    } while(option<4);


    return 0;
}


void datainlink(struct node *current,int Row, int Col, int Val)
{
    current->row=Row;
    current->column=Col;
    current->value=Val;
    current->next=NULL;
}

void mwrite(struct node *first, struct node *current)
{
    current=first;
    while(current!=NULL) { 
        printf("%d %d %d \n",current->row,current->column,current->value); 
        current=current->next; 
    }
}

void mtranspose(struct node *first, struct node *current)
{
    int temp;
    current=first;
    while(current!=NULL) {
        temp=current->row;
        current->row=current->column;
        current->column=temp;
        current=current->next;
    }
}

void mmult(struct node *f1, struct node *f2,int num_col_f1,int num_row_f1,int num_col_f2,int num_row_f2)  // f1 means first1, f2 means first2. c1 means current1,and so on�o�@�w�n��mb��
{
    //printf("first row %d,first col %d,second row %d,second col %d\n",num_row_f1,num_col_f1,num_row_f2,num_col_f2);//for test.
    struct node* fd, *fd2,*this_line;
    struct node* f1_head=f1;
    struct node* f2_head=f2;
    int temp_sum;
    int i,j;

    fd2=f2;
    if(num_col_f1!=num_col_f2)
        printf("You can't multiply them together!\n");
    else {
        for(i=0; i<=num_row_f1; i++) {
            this_line=f1_head;
            for(j=0; j<=num_col_f2; j++) {
                f1_head=this_line;
                temp_sum=0;

                while(f1_head!=NULL && f2_head!=NULL && (f1_head->row == i) && (f2_head->column==j)) {
                    if(f1_head->column==f2_head->row) {
                        temp_sum+=(f1_head->value)*(f2_head->value);
                        f1_head=f1_head->next;
                        f2_head=f2_head->next;
                    } else if((f1_head->column) < (f2_head->column)) {
                        f1_head=f1_head->next;
                    } else if(f1->column > f2_head->column) {
                        f2_head=f2_head->next;
                    }
                }
                while(f2_head!=NULL && f2_head->row==j)
                    f2_head=f2_head->next;

                if(temp_sum==0)
                    continue;
                else {
                    printf("%d %d %d\n",i,j,temp_sum);
                }
            }
            while(f1_head!=NULL && f1_head->row==i)
                f1_head=f1_head->next;
            f2_head=fd2;
        }
    }
}

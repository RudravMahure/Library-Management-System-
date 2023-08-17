#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define MAX 10
struct books
{
    int id;
    char name[20];
    char author[20];
    int quantity;
    float cost;
    char category[10];
} bk[MAX];
struct student
{
    int regis;
} st[MAX];
struct date
{
    int date;
    int month;
    int year;
} dt[MAX];

int num;
FILE *fp, *ft, *fr, *fr1;
int count = 0;
void createbook();
void display();
void addbook();
void searchbook();
void search_category();
void update();
void delete();
void issue();
void return_book();
void issue_student();
void book_issue();
void delete_2();
int main()
{
    int reg, option;
    char res = 'y';
    char res2 = 'n';
    char user[10];
    char pass[10];
    char ch;
    do
    {
        printf("\n Are you admin or student:");
        scanf(" %s", user);
        printf("Enter your registration Id:");
        scanf("%d", &reg);
        printf("Enter password:");
        int j = 0;
        while ((ch = _getch()) != 13)
        {
            pass[j] = ch;
            j++;
            printf("*");
        }
        pass[j] = '\0';
        char admin[10] = "admin";
        char stud[10] = "student";
        int value_ad = strcmp(user, admin);
        int value_st = strcmp(user, stud);
        printf("\n*************************************************************************************************************************\n");
        if (value_ad == 0) // password
        {
            do
            {
                printf("\n 1.Create database for book \n 2.Display book \n 3.Add book data base");
                printf("\n 4.Search book by name \n 5.Search book by category \n 6.Update quantity database \n 7.issue book \n 8.return book \n 9.Delete book from database");
                printf("\n 10.Total booked issued from library");
                printf("\n 11.Booked issued by particular student");
                printf("\n 12.Close application");
                printf("\n Enter your choice:");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    // CREATION OF DATABASE FOR BOOK
                    createbook();
                    break;
                case 2:
                    // DISPLAY DATABASE
                    display();
                    break;
                case 3:
                    // ADD NEW BOOK IN DATABASE
                    addbook();
                    break;
                case 4:
                    // SEARCH BOOK IN DATA BASE BY NAME
                    searchbook();
                    break;
                case 5:
                    // SEARCH BOOK BY CATEGORY
                    search_category();
                    break;
                case 6:
                    // UPDATE PRICE AND QUANTITY
                    update();
                    break;
                case 7:
                    // ISSUE BOOK
                    issue();
                    break;
                case 8:
                    // RETURN BOOK
                    return_book();
                    break;
                case 9:
                    // DELETE DATA FROM DATABASE
                    delete ();
                    break;
                case 10:
                    // TOTAL BOOK ISSUED
                    book_issue();
                    break;
                case 11:
                    // BOOKED ISSUED BY STUDENT
                    issue_student();
                    break;
                case 12:
                    // CLOSING OF APPLICATION
                    printf("\n THANK YOU FOR USING LIBRARY SYSTEM \n RETURN TO MAIN MENU");
                    res = 'n';
                    break;
                default:
                    printf("\n PLEASE ENTER VALID CHOICE");
                    break;
                }

            } while (res == 'y');
        }
        else if (value_st == 0)
        {
            do
            {
                printf("\n 1.Display book avaiable in library");
                printf("\n 2.Search book by name \n 3.Search book by category \n 4.Books issued by me");
                printf("\n 5.Return Main Menu");
                printf("\n Enter your choice:");
                scanf("%d", &option);
                switch (option)
                {
                // Display book avaiable
                case 1:
                    display();
                    break;
                case 2:
                    // Search book by name
                    searchbook();
                    break;
                case 3:
                    // Search book by category
                    search_category();
                    break;
                case 4:
                    // book issue by student
                    issue_student();
                    break;
                case 5:
                    // exit function
                    printf("\n THANK YOU FOR USING LIBRARY SYSTEM \n RETURN TO MAIN SCREEN");
                    res = 'n';
                    break;
                }
            } while (res == 'y');
        }
        else
        {
            printf("\n Wrong Student registration or Password");
        }
        printf("\n Do you want to exit system...");
        printf("\n Y for YES \n N for no");
        printf("\n Enter choice:");
        scanf(" %c", &res2);
    } while (res2 == 'n');
    return 0;
}
// CREATION OF DATABASE FOR BOOK
void createbook()
{
    int n;
    fp = fopen("project.txt", "w");
    if (fp == NULL)
    {
        printf("\n FIle opening error");
    }
    else
    {
        printf("\n Enter number of books in database:");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("%d RECORD", i + 1);
            printf("\n \t \t Book name:");
            scanf("%s", bk[i].name);
            printf("\n \t \t Author name:");
            scanf("%s", bk[i].author);
            printf("\n \t \t Book id:");
            scanf("%d", &bk[i].id);
            printf("\n \t \t Quantity of book:");
            scanf("%d", &bk[i].quantity);
            printf("\n \t \t Cost  of each book:");
            scanf("%f", &bk[i].cost);
            printf("\n \t \t Category:");
            scanf("%s", bk[i].category);
            fprintf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
            count++;
        }
        printf("\n DATA BASE IS CREATED");
        printf("\n*************************************************************************************************************************\n");
        fclose(fp);
    }
}
// DISPLAY DATABASE
void display()
{
    fp = fopen("project.txt", "r");
    int i = 0;
    printf("\n Book name \t\t Author name \t\t Book id \t Quantity \t Cost \t\t Category");
    printf("\n************************************************************************************************************************\n");
    while (fscanf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        printf("\n %s \t\t %s \t\t %d \t\t %d \t\t %f  \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
        i++;
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fp);
}
// ADD NEW BOOK IN DATABASE
void addbook()
{

    int n;
    int i = count + 1;
    int j = 0;
    fp = fopen("project.txt", "a");
    printf("Number of book you want to add:");
    scanf("%d", &n);
    if (fp == NULL)
    {
        printf("\n File opening error");
    }
    else
    {
        while (n != 0)
        {
            printf("%d RECORD", j + 1);
            printf("\n \t \t Book name:");
            scanf("%s", bk[i].name);
            printf("\n \t \t Author name:");
            scanf("%s", bk[i].author);
            printf("\n \t \t Book id:");
            scanf("%d", &bk[i].id);
            printf("\n \t \t Quantity of book:");
            scanf("%d", &bk[i].quantity);
            printf("\n \t \t Cost  of each book:");
            scanf("%f", &bk[i].cost);
            printf("\n \t \t Category:");
            scanf("%s", bk[i].category);
            fprintf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
            printf("\n ***********RECORD ADDED**********\n");
            n--;
            i++;
            count++;
            j++;
        }
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fp);
}
// SEARCH BOOK IN DATABASE
void searchbook()
{
    fp = fopen("project.txt", "r");
    char sname[20];
    int flag = 1;
    int value;
    char fname[20];
    int i = 0;
    int count = 0;
    printf("\n Enter the name of book you want to search:");
    scanf("%s", sname);
    i = 0;
    while (fscanf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        if (strcmp(bk[i].name, sname) == 0)
        {
            printf("\n \t \t Book Name:%s", bk[i].name);
            printf("\n \t \t Auhtor Name:%s", bk[i].author);
            printf("\n \t \t Book id:%d", bk[i].id);
            printf("\n \t \t Cost of book:%f", bk[i].cost);
            printf("\n \t \t Quantity of book in library:%d", bk[i].quantity);
            printf("\n \t \t Category:%s", bk[i].category);
            printf("\n*************************************************************************************************************************\n");
            flag = 0;
            return;
        }
        i++;
    }
    if (flag == 1)
    {
        printf("\n SORRY WE DON'T HAVE BOOK YOU WANT");
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fp);
}
// SEARCH BOOK BY CATEGORY
void search_category()
{
    int i = 0;
    int flag2 = 1;
    char scat[10];
    fp = fopen("project.txt", "r");
    printf("\n Enter the category of book you want to search:");
    scanf("%s", scat);
    while (fscanf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        if (strcmp(bk[i].category, scat) == 0)
        {
            printf("\n \t \t Book Name:%s", bk[i].name);
            printf("\n \t \t Auhtor Name:%s", bk[i].author);
            printf("\n \t \t Book id:%d", bk[i].id);
            printf("\n \t \t Cost of book:%f", bk[i].cost);
            printf("\n \t \t Quantity of book in library:%d", bk[i].quantity);
            printf("\n \t \t Category:%s", bk[i].category);
            printf("\n*************************************************************************************************************************\n");
            flag2 = 0;
        }
        i++;
    }
    if (flag2 == 1)
    {
        printf("\n SORRY WE DON'T HAVE %s CATEGORY OF BOOKS", scat);
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fp);
}
// UPDATE THE QUANTITY OF BOOKS IN LIBRARY
void update()
{
    int i = 0;
    int quant;
    int sid;
    int flag = 1;
    fp = fopen("project.txt", "r");
    ft = fopen("temp.txt", "w");
    printf("\n Enter the Book id:");
    scanf("%d", &sid);
    printf("\n Enter the quantity of book:");
    scanf("%d", &quant);
    while (fscanf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        if (sid == bk[i].id)
        {
            bk[i].quantity = bk[i].quantity+quant;
            fprintf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
            flag = 0;
            i++;
            printf("\n ********DATA UPDATE************");
            i++;
        }
        else
        {
            fprintf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
            i++;
        }
    }
    if (flag == 1)
    {
        printf("\n BOOK NOT FOUND");
    }
    fclose(fp);
    fclose(ft);

    fp = fopen("project.txt", "w");
    ft = fopen("temp.txt", "r");
    i = 0;
    while (fscanf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        fprintf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
        i++;
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fp);
    fclose(ft);
}
// DELETION OF BOOK FROM DATABASE
void delete()
{
    int del;
    int i = 0;
    int id;
    printf("\n Enter Book id of book you want to delete:");
    scanf("%d", &id);
    fp = fopen("project.txt", "r");
    ft = fopen("temp.txt", "w");
    while (fscanf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        if (id == bk[i].id)
        {
            del = i;
            i++;
        }
        else
        {
            fprintf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
            i++;
        }
    }
    i = 0;
    fclose(fp);
    fclose(ft);
    char sname[20], sauthor[20], scat[20];
    int ID, quan;
    float price;
    fp = fopen("project.txt", "w");
    ft = fopen("temp.txt", "r");
    while (fscanf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        strcpy(sname, bk[i].name);
        strcpy(sauthor, bk[i].author);
        ID = bk[i].id;
        quan = bk[i].quantity;
        price = bk[i].cost;
        strcpy(scat, bk[i].category);
        fprintf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", sname, sauthor, ID, quan, price, scat);
    }
    printf("\n *******BOOK IS DELETED***********");
    printf("\n*************************************************************************************************************************\n");
    fclose(fp);
    fclose(ft);
}
// Deletion from issued book
void delete_2()
{
    int del;
    int i = 0;
    int id;
    printf("\n Enter Book id of book you want to delete:");
    scanf("%d", &id);
    fr = fopen("student.txt", "r");
    fr1 = fopen("student1.txt", "w");
    while (fscanf(fr, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",&st[i].regis,bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category,&dt[i].date,&dt[i].month,&dt[i].year) != EOF)
    {
        if (id == bk[i].id)
        {
            del = i;
            i++;
        }
        else
        {
            fprintf(fr1, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",st[i].regis,bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category,dt[i].date,dt[i].month,dt[i].year);
            i++;
        }
    }
    i = 0;
    fclose(fr);
    fclose(fr1);
    char sname[20], sauthor[20], scat[20];
    int ID, quan;
    float price;int date1,month1,year1;
    int reg1;
    fr = fopen("student.txt", "w");
    fr1 = fopen("student1.txt", "r");
    while (fscanf(fr1, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",&st[i].regis,bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category,&dt[i].date,&dt[i].month,&dt[i].year) != EOF)
    {
        strcpy(sname, bk[i].name);
        strcpy(sauthor, bk[i].author);
        ID = bk[i].id;
        quan = bk[i].quantity;
        price = bk[i].cost;
        strcpy(scat, bk[i].category);
        date1=dt[i].date;
        month1=dt[i].month;
        year1=dt[i].year;
        reg1=st[i].regis;
        fprintf(fr, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",reg1, sname, sauthor, ID, quan, price, scat,date1,month1,year1);
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fr);
    fclose(fr1);
}
// ISSUE BOOK
void issue()
{
    int Id;
    int i = 0;
    int quan;
    int flag = 1;
    int quant;
    int reg;
    printf("\n Enter the book id of book you want to issue:");
    scanf("%d", &Id);
    printf("\n Enter registration id:");
    scanf("%d", &reg);
    fp = fopen("project.txt", "r");
    ft = fopen("temp.txt", "w");
    fr = fopen("student.txt", "a");
    while (fscanf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        if (Id == bk[i].id)
        {
            if (bk[i].quantity > 0)
            {
                printf("\n**********BOOK ISSUED**********");
                quan = bk[i].quantity - 1;
                time_t t;
                t = time(NULL);
                struct tm tm = *localtime(&t);
                st[i].regis = reg;
                printf("\n  Issue Date: %d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
                printf("\n*************************************************************************************************************************\n");
                printf("\n  Return Book before: %d-%d-%d", tm.tm_mday, tm.tm_mon + 2, tm.tm_year + 1900);
                dt[i].date = tm.tm_mday;
                dt[i].month = tm.tm_mon + 2;
                dt[i].year = tm.tm_year + 1900;
                quant = 1;
                printf("\n*************************************************************************************************************************\n");
                fprintf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, quan, bk[i].cost, bk[i].category);
                fprintf(fr, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d", st[i].regis, bk[i].name, bk[i].author, bk[i].id, quant, bk[i].cost, bk[i].category, dt[i].date, dt[i].month, dt[i].year);
                i++;
            }
            else
            {
                printf("\n SORRY CURRENTLY BOOK IS NOT AVAILABLE \n PLEASE COME LATER \n");
            }
            flag = 0;
        }
        else
        {
            fprintf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
            i++;
        }
    }
    if (flag == 1)
    {
        printf("\n********** Searched booked not found *************");
    }
    fclose(fp);
    fclose(ft);
    fclose(fr);
    char sname[20], sauthor[20], scat[20];
    int ID;
    float price;
    fp = fopen("project.txt", "w");
    ft = fopen("temp.txt", "r");
    while (fscanf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        strcpy(sname, bk[i].name);
        strcpy(sauthor, bk[i].author);
        ID = bk[i].id;
        quan = bk[i].quantity;
        price = bk[i].cost;
        strcpy(scat, bk[i].category);
        fprintf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", sname, sauthor, ID, quan, price, scat);
    }
    fclose(fp);
    fclose(ft);
    printf("\n*************************************************************************************************************************\n");
}
// RETURN BOOK
void return_book()
{

    int Id;
    int i = 0;
    int quan;
    int flag = 1;
    int reg;
    int flag2 = 1;
    int quant;
    int del;
    printf("\n Enter the book id of book you want to return:");
    scanf("%d", &Id);
    printf("\n Enter Registration id:");
    scanf("%d", &reg);
    i = 0;
    fp = fopen("project.txt", "r");
    ft = fopen("temp.txt", "w");
    while (fscanf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        if (Id == bk[i].id)
        {
            printf("\n*********BOOK RETURNED**********");
            quan = bk[i].quantity + 1;
            flag = 0;
            fprintf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, quan, bk[i].cost, bk[i].category);
            i++;
        }
        else
        {
            fprintf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category);
            i++;
        }
    }
    fclose(fp);
    fclose(ft);
    char sname[20], sauthor[20], scat[20];
    int ID;
    float price;
    int reg2;
    int date, month, year;
    fp = fopen("project.txt", "w");
    ft = fopen("temp.txt", "r");
    while (fscanf(ft, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category) != EOF)
    {
        strcpy(sname, bk[i].name);
        strcpy(sauthor, bk[i].author);
        ID = bk[i].id;
        quan = bk[i].quantity;
        price = bk[i].cost;
        strcpy(scat, bk[i].category);
        fprintf(fp, "\n %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s", sname, sauthor, ID, quan, price, scat);
        i++;
    }
    fclose(fp);
    fclose(ft);
    i = 0;
    fr = fopen("student.txt", "r");
    fr1 = fopen("student1.txt", "w");
    while (fscanf(fr, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",&st[i].regis,bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category,&dt[i].date,&dt[i].month,&dt[i].year) != EOF)
    {
        if (Id == bk[i].id && reg==st[i].regis)
        {
            del = i;
            flag2=0;
            i++;
        }
        else
        {
            fprintf(fr1, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",st[i].regis,bk[i].name, bk[i].author, bk[i].id, bk[i].quantity, bk[i].cost, bk[i].category,dt[i].date,dt[i].month,dt[i].year);
            i++;
        }
    }
    i = 0;
    fclose(fr);
    fclose(fr1);
    int date1,month1,year1;
    int reg1;
    fr = fopen("student.txt", "w");
    fr1 = fopen("student1.txt", "r");
    while (fscanf(fr1, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",&st[i].regis,bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category,&dt[i].date,&dt[i].month,&dt[i].year) != EOF)
    {
        strcpy(sname, bk[i].name);
        strcpy(sauthor, bk[i].author);
        ID = bk[i].id;
        quan = bk[i].quantity;
        price = bk[i].cost;
        strcpy(scat, bk[i].category);
        date1=dt[i].date;
        month1=dt[i].month;
        year1=dt[i].year;
        reg1=st[i].regis;
        fprintf(fr, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d",reg1, sname, sauthor, ID, quan, price, scat,date1,month1,year1);
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fr);
    fclose(fr1);
    if (flag == 1)
    {
        printf("\n BOOK DOES NOT BELONG TO OUR LIBRABRY \n");
        printf("\n*************************************************************************************************************************\n");
    }
    if (flag2 == 1)
    {
        printf("\n YOU HAVEN'T ISSUED ANY BOOK");
    }
    printf("\n*************************************************************************************************************************\n");
}
// book issued by student
void issue_student()
{
    int reg;
    int flag = 1;
    int i = 0;
    printf("\n Enter your registration number:");
    scanf("%d", &reg);
    fr = fopen("student.txt", "r");
    while (fscanf(fr, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d", &st[i].regis, bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category, &dt[i].date, &dt[i].month, &dt[i].year) != EOF)
    {
        if (reg == st[i].regis)
        {
            printf("\n BOOKED ISSUED BY YOU");
            printf("\n*************************************************************************************************************************\n");
            printf("\n \t \t Registration number:%d", st[i].regis);
            printf("\n \t \t Book Name:%s", bk[i].name);
            printf("\n \t \t Auhtor Name:%s", bk[i].author);
            printf("\n \t \t Book id:%d", bk[i].id);
            printf("\n \t \t Cost of book:%f", bk[i].cost);
            printf("\n \t \t Quantity of book in library is 1");
            printf("\n \t \t Category:%s", bk[i].category);
            printf("\n \t \t Retunr date:%d-%d-%d", dt[i].date, dt[i].month, dt[i].year);
            flag = 0;
        }
        i++;
    }
    if (flag == 1)
    {
        printf("\n You haven't issue any book");
    }
    printf("\n*************************************************************************************************************************\n");
    fclose(fr);
}
// Total book issued from library
void book_issue()
{
    int i = 0, flag = 1;
    fr = fopen("student.txt", "r");
    printf("\n LIST OF BOOKED ISSUED BY STUDENT");
    while (fscanf(fr, "\n %d \t\t %s \t\t %s \t\t %d \t\t %d \t\t %f \t\t %s \t\t %d-%d-%d", &st[i].regis, bk[i].name, bk[i].author, &bk[i].id, &bk[i].quantity, &bk[i].cost, bk[i].category, &dt[i].date, &dt[i].month, &dt[i].year) != EOF)
    {
        if (bk[i].quantity > 0)
        {
            printf("\n*************************************************************************************************************************\n");
            printf("\n \t \t Registration number:%d", st[i].regis);
            printf("\n \t \t Book Name:%s", bk[i].name);
            printf("\n \t \t Auhtor Name:%s", bk[i].author);
            printf("\n \t \t Book id:%d", bk[i].id);
            printf("\n \t \t Cost of book:%f", bk[i].cost);
            printf("\n \t \t Quantity of book in library is %d", bk[i].quantity);
            printf("\n \t \t Category:%s", bk[i].category);
            printf("\n \t \t Retunr date:%d-%d-%d", dt[i].date, dt[i].month, dt[i].year);
            printf("\n*************************************************************************************************************************\n");
            i++;
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\n CURRENTLY NO BOOK IS ISSUED");
    }
}
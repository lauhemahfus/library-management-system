#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>

struct book{
    char name[50];
    char author[50];
    char category[20];
    int isbn;
    int available;
};

struct user{
    char name[50];
    int id;
    char mobile[20];
    char issue_east[50];
    int issue_east_date[3];
    char issue_west[50];
    int issue_west_date[3];
};

typedef struct book book;
typedef struct user user;

void main_menu();
void admin_home();
void user_home();
void add_book();
void add_user();
void show_book_list();
void show_user_list();
void search_book();
void search_book_name();
void search_book_isbn();
void search_book_category();
void search_book_author();
void search_user();
void search_user_id();
void search_user_phone();
void issue_book();
void receive_book();
void borrowing_rules();
void bd_war_corner();
void delete_book();
void delete_user();
void Password();
int fee(int id, int im, int iy, int rd, int rm, int ry);
int book_available(char book_name[]);
int update_book(char *book_name, int add_or_rem);
void issue_receipt(char uname[30], int uid, char bname[30], char sname[10], int issuedate[]);
void receive_receipt(char uname[30], int uid, char bname[30], char sname[10], int issuedate[], int receivedate[], int fine);
void welcome_page();
void header_box(char name[]);
void header_line();
void clrscr();



int main()
{
    welcome_page();
    getch();
    clrscr();
    system("color 07");
    main_menu();

    return 0;
}


void main_menu()
{
    char choice;
    clrscr();
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t Main Menu");
    printf("\n\n\n");
    printf("\t\t\t\t1. Admin\n");
    printf("\n\t\t\t\t2. User\n");
    printf("\n\t\t\t\t0. Exit\n");
    printf("\n\n\n\n\t\t\t\t\tEnter your choice: ");
    choice = getch();
    switch(choice)
    {
        case '1':
            Password();
            admin_home();
            break;
        case '2':
            user_home();
            break;
        case '0':
            exit(1);
            break;
        default:
            printf("\t\t\t\tInvalid input.");
            getch();
            main_menu();
    }
}
void admin_home()
{
    int choice;
    clrscr();
    header_box("Admin Menu");
    printf("\n\n\n");
    printf("\t\t\t\t1.  Add Book\n");
    printf("\n\t\t\t\t2.  Add User\n");
    printf("\n\t\t\t\t3.  Book List\n");
    printf("\n\t\t\t\t4.  User List\n");
    printf("\n\t\t\t\t5.  Search Book\n");
    printf("\n\t\t\t\t6.  Search User\n");
    printf("\n\t\t\t\t7.  Issue Book\n");
    printf("\n\t\t\t\t8.  Receive Book\n");
    printf("\n\t\t\t\t9.  Delete Book\n");
    printf("\n\t\t\t\t10.  Delete User\n");
    printf("\n\t\t\t\t0.  Main Menu\n");
    printf("\n\n\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            add_book();
            break;
        case 2:
            add_user();
            break;
        case 3:
            show_book_list();
            admin_home();
            break;
        case 4:
            show_user_list();
            break;
        case 5:
            search_book();
            admin_home();
            break;
        case 6:
            search_user();
            break;
        case 7:
            issue_book();
            break;
        case 8:
            receive_book();
            break;
        case 9:
            delete_book();
            break;
        case 10:
            delete_user();
            break;
        case 0:
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid input.");
            getch();
            admin_home();
            break;
    }

}

void user_home()
{
    clrscr();
    int choice;
    clrscr();
    header_box("USER MENU");
    printf("\n\n\n");
    printf("\t\t\t\t1.  Book List\n");
    printf("\n\t\t\t\t2.  Search Book\n");
    printf("\n\t\t\t\t3.  Borrowing Rules\n");
    printf("\n\t\t\t\t4.  Bangladesh Liberation War Corner\n");
    printf("\n\t\t\t\t0. Main Menu\n");
    printf("\n\n\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            show_book_list();
            user_home();
            break;
        case 2:
            search_book();
            user_home();
            break;
        case 3:
            borrowing_rules();
            break;
        case 4:
            bd_war_corner();
            break;
        case 0:
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid input.");
            getch();
            user_home();
            break;
    }
}


void add_book()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t ADD BOOK\n\n\n");
    FILE *fp;
    fp = fopen("book", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        clrscr();
        header_line();
        printf("\n\n\t\t\t\t\t\t\t ADD BOOK\n\n\n");
        getchar();
        printf("\n\t\t\tEnter Book Name : ");
        scanf("%[^\n]s",p.name);

        getchar();
        printf("\n\t\t\tEnter Author Name : ");
        scanf("%[^\n]s",p.author);
        getchar();
        printf("\n\t\t\tEnter Book Category : ");
        scanf("%[^\n]s",p.category);

        printf("\n\t\t\tEnter ISBN : ");
        scanf("%d",&p.isbn);

        printf("\n\t\t\tEnter how many copy left: ");
        scanf("%d",&p.available);
        fwrite(&p, sizeof(p), 1, fp);
        fclose(fp);
        clrscr();
        header_line();
        printf("\n\n\t\t\t\t\t\t\t ADD BOOK\n\n\n");
        printf("\n\n\t\t\t\t\tRecord added Successfully\n");
        printf("\n\n\t\t\t\t\t\tPress any key to continue ....\n");
        getch();
        admin_home();

    }
}

void add_user()
{
	clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t ADD USER\n\n\n");
    FILE *fp;
    fp = fopen("user", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        user p;
        clrscr();
        header_line();
        printf("\n\n\t\t\t\t\t\t\t ADD USER\n\n\n");
        printf("\n\t\t\tEnter User Id : ");
        scanf("%d",&p.id);
        getchar();
        printf("\n\t\t\tEnter User Name : ");
        scanf("%[^\n]s",p.name);
        getchar();
        printf("\n\t\t\tEnter User Mobile Number : ");
        scanf("%[^\n]s",p.mobile);
        strcpy(p.issue_east, "None");
        strcpy(p.issue_west, "None");
        p.issue_east_date[0] = 0;
        p.issue_east_date[1] = 0;
        p.issue_east_date[2] = 0;
        p.issue_west_date[0] = 0;
        p.issue_west_date[1] = 0;
        p.issue_west_date[2] = 0;
        fwrite(&p, sizeof(p), 1, fp);
        fclose(fp);
        clrscr();
        header_line();
        printf("\n\n\t\t\t\t\t\t\t ADD USER\n\n\n");
        printf("\n\n\t\t\t\t\tRecord added Successfully\n");
        printf("\n\n\t\t\t\t\t\tPress any key to continue ....\n");
        getch();
        getch();
        admin_home();

    }
}

void show_book_list()
{
    int b =1,tb =0;
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t BOOK LIST\n\n\n");
    FILE *fp;
    fp = fopen("book", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-3s | %-29s | %-30s | %-20s | %-10s | %-10s |\n","No.", "Name", "Author", "Category", "ISBN", "Available");
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            printf("-------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-3d |", b);
            printf("%-30s | ",p.name);
            printf("%-30s | ",p.author);
            printf("%-20s | ",p.category);
            printf("%-10d | ",p.isbn);
            printf("%-10d | ",p.available);
            printf("\n");
            fflush(stdin);
            b++;
            tb+=p.available;
        }
        printf("-------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\nTOTAL AVAILABLE BOOK : %d\n", tb);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
        getch();

    }
}
void show_user_list()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t USER LIST\n\n\n");
    FILE *fp;
    int u =0,b=0;
    fp = fopen("user", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        user p;
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-5s | %-30s | %-20s | %-30s | %-10s | %-30s | %-10s |\n", "ID", "Name", "Mobile Number", "East slot book", "Date", "West slot book", "Date");
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("| %-5d | ",p.id);
            printf("%-30s | ",p.name);
            printf("%-20s | ",p.mobile);
            printf("%-30s | ",p.issue_east);
            printf("%2d/%2d/%-4d | ",p.issue_east_date[0],p.issue_east_date[1], p.issue_east_date[2]);
            printf("%-30s | ",p.issue_west);
            printf("%2d/%2d/%-4d | ",p.issue_west_date[0],p.issue_west_date[1], p.issue_west_date[2]);
            printf("\n");
            fflush(stdin);
            if(strcmp(p.issue_east, "None") != 0) b++;
            if(strcmp(p.issue_west, "None") != 0) b++;
            u++;
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\n\nTOTAL USER: %d\n", u);
        printf("TOTAL ISSUED BOOK: %d\n", b);
        printf("\n\n\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        admin_home();

    }
}
void search_book()
{
    int choice;
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH BOOK BY\n\n\n");
    printf("\t\t\t\t\t How do you want to search book? ");
    printf("\n\n\n");
    printf("\t\t\t\t1. Name\n");
    printf("\n\t\t\t\t2. ISBN\n");
    printf("\n\t\t\t\t3. Author\n");
    printf("\n\t\t\t\t4. Category\n");
    printf("\n\t\t\t\t0. Main Menu\n");
    printf("\n\n\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            search_book_name();
            break;
        case 2:
            search_book_isbn();
            break;
        case 3:
            search_book_author();
            break;
        case 4:
            search_book_category();
            break;
        case 0:
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid input.");

    }

}
void search_book_author()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\tSEARCH BOOK BY AUTHOR\n\n\n");
    char author_name[50];
    getchar();
    printf("\n\n\t\t\t\tEnter Author Name : ");
    scanf("%[^\n]s",author_name);
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH BOOK BY AUTHOR\n\n\n");
    FILE *fp;
    fp = fopen("book", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-20s | %-10s | %-10s |\n","Name", "Author", "Category", "ISBN", "Available");
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(strcmp(author_name, p.author) == 0)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-30s | ",p.name);
                printf("%-30s | ",p.author);
                printf("%-20s | ",p.category);
                printf("%-10d | ",p.isbn);
                printf("%-10d | ",p.available);
                printf("\n");
                fflush(stdin);
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        search_book();

    }
}
void search_book_name()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\tSEARCH BOOK BY NAME\n\n\n");
    char book_name[50];
    getchar();
    printf("\n\n\t\t\t\tEnter Book Name : ");
    scanf("%[^\n]s",book_name);
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH BOOK BY NAME\n\n\n");
    FILE *fp;
    fp = fopen("book", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-20s | %-10s | %-10s |\n","Name", "Author", "Category", "ISBN", "Available");
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(strcmp(book_name, p.name) == 0)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-30s | ",p.name);
                printf("%-30s | ",p.author);
                printf("%-20s | ",p.category);
                printf("%-10d | ",p.isbn);
                printf("%-10d | ",p.available);
                printf("\n");
                fflush(stdin);
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        search_book();

    }
}
void search_book_isbn()
{
    clrscr();
    int isbn;
    header_line();
    printf("\n\n\t\t\t\t\tSEARCH BOOK BY ISBN\n\n\n");
    printf("\n\n\t\t\t\tEnter ISBN Number: ");
    scanf("%d", &isbn);
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH BOOK BY ISBN\n\n\n");
    FILE *fp;
    fp = fopen("book", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-20s | %-10s | %-10s |\n","Name", "Author", "Category", "ISBN", "Available");

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.isbn == isbn)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-30s | ",p.name);
                printf("%-30s | ",p.author);
                printf("%-20s | ",p.category);
                printf("%-10d | ",p.isbn);
                printf("%-10d | ",p.available);
                printf("\n");
                fflush(stdin);
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        search_book();

    }

}
void search_book_category()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\tSEARCH BOOK BY CATEGORY\n\n\n");
    char category[50];
    getchar();
    printf("\n\n\t\t\t\tEnter Book Category : ");
    scanf("%[^\n]s",category);
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH BOOK BY CATEGORY\n\n\n");
    FILE *fp;
    fp = fopen("book", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-20s | %-10s | %-10s |\n","Name", "Author", "Category", "ISBN", "Available");
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(strcmp(category, p.category) == 0)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-30s | ",p.name);
                printf("%-30s | ",p.author);
                printf("%-20s | ",p.category);
                printf("%-10d | ",p.isbn);
                printf("%-10d | ",p.available);
                printf("\n");
                fflush(stdin);
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        search_book();

    }
}
void search_user()
{
    int choice;
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH USER BY\n\n\n");
    printf("\t\t\t\t\t How do you want to search USER? ");
    printf("\n\n\n");
    printf("\t\t\t\t1. ID\n");
    printf("\n\t\t\t\t2. Phone Number\n");
    printf("\n\t\t\t\t0. Main Menu\n");
    printf("\n\n\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            search_user_id();
            break;
        case 2:
            search_user_phone();
            break;
        case 0:
            main_menu();
            break;
        default:
            printf("\t\t\t\tInvalid input.");
            user_home();
    }
}
void search_user_id()
{
    clrscr();
    int id;
    header_line();
    printf("\n\n\t\t\t\t\tSEARCH USER BY ID\n\n\n");
    printf("\n\n\t\t\t\tEnter ID Number: ");
    scanf("%d", &id);
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH USER BY ID\n\n\n");
    FILE *fp;
    fp = fopen("user", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        user p;
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-5s | %-30s | %-20s | %-30s | %-10s | %-30s | %-10s |\n", "ID", "Name", "Mobile Number", "East slot book", "Date", "West slot book", "Date");

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.id == id)
            {
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-5d | ",p.id);
                printf("%-30s | ",p.name);
                printf("%-20s | ",p.mobile);
                printf("%-30s | ",p.issue_east);
                printf("%2d/%2d/%-4d | ",p.issue_east_date[0],p.issue_east_date[1], p.issue_east_date[2]);
                printf("%-30s | ",p.issue_west);
                printf("%2d/%2d/%-4d | ",p.issue_west_date[0],p.issue_west_date[1], p.issue_west_date[2]);
                printf("\n");
                fflush(stdin);
            }
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        search_user();

    }
}
void search_user_phone()
{
    clrscr();
    char number[20];
    header_line();
    printf("\n\n\t\t\t\t\tSEARCH USER BY PHONE NUMBER\n\n\n");
    printf("\n\n\t\t\t\tEnter PHONE Number: ");
    scanf("%s", number);
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\t\t SEARCH USER BY PHONE NUMBER\n\n\n");
    FILE *fp;
    fp = fopen("user", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        user p;
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-5s | %-30s | %-20s | %-30s | %-10s | %-30s | %-10s |\n", "ID", "Name", "Mobile Number", "East slot book", "Date", "West slot book", "Date");

        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (strcmp(p.mobile, number) == 0)
            {
                printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-5d | ",p.id);
                printf("%-30s | ",p.name);
                printf("%-20s | ",p.mobile);
                printf("%-30s | ",p.issue_east);
                printf("%2d/%2d/%-4d | ",p.issue_east_date[0],p.issue_east_date[1], p.issue_east_date[2]);
                printf("%-30s | ",p.issue_west);
                printf("%2d/%2d/%-4d | ",p.issue_west_date[0],p.issue_west_date[1], p.issue_west_date[2]);
                printf("\n");
                fflush(stdin);
            }
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fflush(stdin);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        search_user();
    }
}
void issue_book()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\tISSUE BOOK TO USER\n\n\n");
    int user_id;
    printf("\n\t\t\t\tEnter User Id to issue book: ");
    scanf("%d",&user_id);
    char book_name[30];
    FILE *fp,*temp;
    fp = fopen("user", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        getch();
        admin_home();
    }
    else
    {
        int flag = 0;
        user p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.id == user_id)
            {
                char slot[10];

                printf("\n\t\t\t\tEnter which slot you want to take book: ");
                scanf("%s", slot);

                if (strcmp(slot, "East") == 0)
                {
                    if (strcmp(p.issue_east, "None") == 0)
                    {
                        getchar();
                        printf("\n\t\t\t\tEnter book name: ");
                        scanf("%[^\n]s",book_name);
                        int f = book_available(book_name);
                        if(f)
                        {
                            update_book(book_name, 0);
                            strcpy(p.issue_east, book_name);
                            printf("\n\t\t\t\tEnter issue date: ");
                            scanf("%d",&p.issue_east_date[0]);
                            printf("\n\t\t\t\tEnter issue Month: ");
                            scanf("%d",&p.issue_east_date[1]);
                            printf("\n\t\t\t\tEnter issue Year: ");
                            scanf("%d",&p.issue_east_date[2]);
                            clrscr();
                            issue_receipt(p.name, p.id, p.issue_east, "East", p.issue_east_date);
                            getch();
                        }

                    }
                    else
                    {
                        printf("\n\n\n\n\t\t\t\t\tYou already have book in East slot. Try West slot.\n");
                    }


                }
                else if (strcmp(slot, "West") == 0)
                {
                    if (strcmp(p.issue_west, "None") == 0)
                    {
                        getchar();
                        printf("\n\t\t\t\tEnter book name: ");
                        scanf("%[^\n]s",book_name);
                        int f = book_available(book_name);
                        if(f)
                        {
                            update_book(book_name, 0);
                            strcpy(p.issue_west, book_name);
                            printf("\n\t\t\t\tEnter issue date: ");
                            scanf("%d",&p.issue_west_date[0]);
                            printf("\n\t\t\t\tEnter issue Month: ");
                            scanf("%d",&p.issue_west_date[1]);
                            printf("\n\t\t\t\tEnter issue Year: ");
                            scanf("%d",&p.issue_west_date[2]);
                            clrscr();
                            issue_receipt(p.name, p.id, p.issue_west, "West", p.issue_west_date);
                            getch();
                        }

                    }
                    else
                    {
                        printf("\n\n\n\n\t\t\t\t\tYou already have book in West slot. Try East slot.\n");
                    }


                }
                fwrite(&p, sizeof(p), 1, temp);
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            clrscr();
            printf("\n\n\n\n\t\t\t\t\tNo User found for %d ID\n",user_id);
        }
        fclose(fp);
        fclose(temp);
        remove("user");
        rename("temp","user");
        fflush(stdin);
    }
    printf("\n\n\n\n\t\t\t\t\tPress any key to continue....\n");
    getch();
    admin_home();
}
void receive_book()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\t\tRECEIVE BOOK FROM USER\n\n\n");
    int user_id;
    printf("\n\t\t\t\tEnter User Id to issue book: ");
    scanf("%d",&user_id);
    int fine_day, fine;
    FILE *fp,*temp;
    fp = fopen("user", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        user p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.id == user_id)
            {
                char slot[10];
                printf("\n\t\t\t\tEnter Receive Book Slot: ");
                scanf("%s", slot);
                if(strcmp(slot, "East") == 0)
                {
                    update_book(p.issue_east, 1);
                    int d,m,y;
                    printf("\n\t\t\t\tEnter return date: ");
                    scanf("%d", &d);
                    printf("\n\t\t\t\tEnter return Month: ");
                    scanf("%d", &m);
                    printf("\n\t\t\t\tEnter return Year: ");
                    scanf("%d", &y);
                    fine_day = fee( p.issue_east_date[0],  p.issue_east_date[1],  p.issue_east_date[2], d,m,y);
                    int date[3] ={d, m,y};
                    if (fine_day<7)
                        fine = 0;
                    else
                        fine = (fine_day-7)*30;
                    clrscr();
                    receive_receipt(p.name, p.id, p.issue_east,"East",  p.issue_east_date, date, fine);
                    getch();
                    strcpy(p.issue_east, "None");
                    p.issue_east_date[0] = 0;
                    p.issue_east_date[1] = 0;
                    p.issue_east_date[2] = 0;

                }
                else if(strcmp(slot, "West") == 0)
                {
                    update_book(p.issue_west, 1);
                    int d,m,y;
                    printf("\n\t\t\t\tEnter return date: ");
                    scanf("%d", &d);
                    printf("\n\t\t\t\tEnter return Month: ");
                    scanf("%d", &m);
                    printf("\n\t\t\t\tEnter return Year: ");
                    scanf("%d", &y);
                    fine_day = fee(p.issue_west_date[0],  p.issue_west_date[1],  p.issue_west_date[2], d,m,y);
                    int date[3] ={d, m,y};
                    if (fine_day<7)
                        fine = 0;
                    else
                        fine = (fine_day-7)*30;
                    clrscr();
                    receive_receipt(p.name, p.id, p.issue_west,"West", p.issue_west_date, date, fine);
                    getch();
                    strcpy(p.issue_west, "None");
                    p.issue_west_date[0] = 0;
                    p.issue_west_date[1] = 0;
                    p.issue_west_date[2] = 0;
                }else
                {
                    printf("Invalid input\n");
                }
                fwrite(&p, sizeof(p), 1, temp);
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            clrscr();
            printf("\n\n\n\n\t\t\t\t\tNo User found for %d number\n",user_id);
        }
        fclose(fp);
        fclose(temp);
        remove("user");
        rename("temp","user");
        fflush(stdin);
    }
    printf("\n\n\n\n\t\t\t\t\tPress any key to continue....\n");
    getch();
    admin_home();
}
void borrowing_rules()
{
    clrscr();
    header_line();
    printf("\n\n\n\n");
    printf("\t\t\t\t\t Borrowing Step");
    printf("\n\n\n");
    printf("\t\t\t\t Step 1.  Give your I'd to librarian\n");
    printf("\n\t\t\t\t Step 2.  Tell him which book you want to borrow\n");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t Borrowing Rules");
    printf("\n\n\n");
    printf("\n\t\t\t\tRules 1.  You can only borrow  2 book at a time\n");
    printf("\n\t\t\t\tRUles 2.  You have to return book within 7 day if you fail for each day you have to pay 30TK\n");
    printf("\n\n\n\t\t\t\t\t\t Press any key to go home...\n");
    getch();
    user_home();
}
void bd_war_corner()
{
    clrscr();
    header_line();
    printf("\n\n\t\t\t\t\tBangladesh LIBERATION WAR CORNER\n\n\n");
    int tb =0;
    FILE *fp;
    fp = fopen("book", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-30s | %-30s | %-20s | %-10s | %-10s |\n","Name", "Author", "Category", "ISBN", "Available");
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(strcmp("Bangladesh war", p.category) == 0)
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-30s | ",p.name);
                printf("%-30s | ",p.author);
                printf("%-20s | ",p.category);
                printf("%-10d | ",p.isbn);
                printf("%-10d | ",p.available);
                printf("\n");
                fflush(stdin);
                tb+=p.available;
            }
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("TOTAL LIBERATION WAR BOOK AVAILABLE: %d\n", tb);
        fflush(stdin);
        fclose(fp);
        printf("\n\n\n\n\t\t\t\t\tPress any key to continue....\n");
        getch();
        user_home();
    }
}

void delete_book()
{
    clrscr();
    header_line();
    printf("\n\n\n\t\t\t\t\t Delete Book");

    int isbn;
    printf("\n\n\t\t\tEnter ISBN Number : ");
    scanf("%ld",&isbn);

    FILE *fp,*temp;
    fp = fopen("book", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        book p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.isbn == isbn)
            {
                clrscr();
                printf("\n\n\n\n\n\n\n\t\t\tBook removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            clrscr();
            printf("\n\n\n\n\n\n\n\t\t\tNo record found for %d ISBN\n",isbn);
        }
        fclose(fp);
        fclose(temp);
        remove("book");
        rename("temp","book");
        fflush(stdin);
        printf("\n\n\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        admin_home();

    }
}
void delete_user()
{
    clrscr();
    int id;
    header_line();
    printf("\n\n\n\t\t\t\t\t Delete User");

    printf("\n\n\n\t\t\tEnter User Id You Want to Delete : ");
    scanf("%ld",&id);

    FILE *fp,*temp;
    fp = fopen("user", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        user p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.id == id)
            {
                clrscr();
                printf("\n\n\n\n\n\n\n\t\t\tUser removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            clrscr();
            printf("No User found for %d number\n",id);
        }
        fclose(fp);
        fclose(temp);
        remove("user");
        rename("temp","user");
        fflush(stdin);
        printf("\n\n\t\t\t\t\t\tPress any key to continue....\n");
        getch();
        admin_home();

    }
}
int update_book(char *book_name, int add_or_rem)
{

    FILE *f,*t;
    f = fopen("book", "rb");
    t = fopen("t","wb+");
    book p;
    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if(strcmp(p.name, book_name)==0)
        {
            int b = p.available;
            if(add_or_rem ==1)
            {
                p.available = b+1;
            }
            else if(add_or_rem == 0)
            {
                p.available = b-1;
            }
        }
        fwrite(&p,sizeof(p),1,t);
        fflush(stdin);
    }
    fclose(f);
    fclose(t);
    remove("book");
    rename("t","book");
    fflush(stdin);
}

int book_available(char book_name[])
{
    int found =1, flag =0;
    FILE *fp;
    fp = fopen("book", "rb");
        book p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(strcmp(book_name, p.name) == 0)
            {
                found = 0;
                flag =1;
                if(p.available == 1){
                    printf("\n\n\n\n\t\t\t\t\tSorry! There are only one book left you can't borrow this.\n");
                    flag = 0;
                }

                fflush(stdin);
                break;
            }
        }
        if(found)
            printf("\n\n\n\n\t\t\t\t\tSorry! No book found in database.\n");
        fclose(fp);
        if(flag)
            return 1;
        else
            return 0;
}

int fee(int id, int im, int iy, int rd, int rm, int ry)
{
    int day;
    if(iy == ry)
    {
        if(im == rm)
        {
            day = rd-id;
        }
        else
        {
            day = (30-id) +rd;
        }
    }
    else
    {
       int month = (12-im) +rm;
        day = (30*month-id) +rd;
    }
    return day;
}
void Password()
{

    system("cls");
    char ch,pass[5];
    int i=0,j;
    printf("\n\n\n\t\t\t\tEnter Password: ");
    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    char password[5]= "103";
    if(strcmp(pass,password)==0)
    {
        printf("\n\n\t\t\t\tAccess granted!\n");
        printf("\n\n\n\t\t\t\t\tPress any key to go next page....");
        getch();
    }
    else
    {
        printf("\n\n\t\t\t\tWrong Password\n");
        printf("\n\n\t\t\t\tPress any key to try again.\n");
        getch();
        main_menu();
    }
}

void clrscr()
{
    system("@cls||clear");
}
void welcome_page()
{
    system("color 0B");
    printf("\t\t _______                   _  _  _                    _     _       _                      _\n");
    printf("\t\t(_______)          _      | || || |           _      | |   | |     (_)                    (_)_\n");
    printf("\t\t _____   ____  ___| |_    | || || | ____  ___| |_    | |   | |____  _ _   _ ____  ____ ___ _| |_ _   _\n");
    printf("\t\t|  ___) / _  |/___)  _)   | ||_|| |/ _  )/___)  _)   | |   | |  _ )| | | | / _  )/ ___)___) |  _) | | |\n");
    printf("\t\t| |____( ( | |___ | |__   | |___| ( (/ /|___ | |__   | |___| | | | | |( V ( (/ /| |  |___ | | |_| |_| |\n");
    printf("\t\t|_______)_||_(___/ (___)   (______|(____|___/ (___)   (______|_| |_|_| (_/ (____)_|  (___/|_|(___)__  |\n");
    printf("\t\t                                                                                                (____/ \n\n");
    printf("\t\t\t\t       .--.           .---.        .-.\n");
    printf("\t\t\t\t   .---|--|   .-.     |   |  .---. |~|    .--.\n");
    printf("\t\t\t\t.--|===|  |---|_|--.__|   |--|:::| |~|-==-|==|---.\n");
    printf("\t\t\t\t|  |   |  |===| |~~|  |   |--|   |_|~|    |  |___|-.\n");
    printf("\t\t\t\t|  |   |  |===| |==|  |   |  |:::|=| |    |  |---|=|\n");
    printf("\t\t\t\t|  |   |  |   |_|__|  |   |__|   | | |    |  |___| |\n");
    printf("\t\t\t\t|~~|===|--|===|~|~~|  |~~~|--|:::|=|~|----|==|---|=|\n");
    printf("\t\t\t\t^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-^\n\n");
    printf("\t  _    _ _                        __  __                                       _     ___         _             \n");
    printf("\t | |  (_) |__ _ _ __ _ _ _ _  _  |  \\/  |__ _ _ _  __ _ __ _ ___ _ __  ___ _ _| |_  / __|_  _ __| |_ ___ _ __  \n");
    printf("\t | |__| | '_ \\ '_/ _` | '_| || | | |\\/| / _` | ' \\/ _` / _` / -_) '  \\/ -_) ' \\  _| \\__ \\ || (_-<  _/ -_) '  \\ \n");
    printf("\t |____|_|_.__/_| \\__,_|_|  \\_, | |_|  |_\\__,_|_||_\\__,_\\__, \\___|_|_|_\\___|_||_\\__| |___/\\_, /__/\\__\\___|_|_|_|\n");
    printf("\t                           |__/                        |___/                             |__/                  \n\n\n\n");
    printf("\n\n\n\t\t\t\t\tPress any key to go next page....");


}


void issue_receipt(char uname[30], int uid, char bname[30], char sname[10], int issuedate[] )
{
    printf("\t\t\t(((  _--_    _--_    _--_    _--_    _--_    _--_    _--_    _-)))\n");
    printf("\t\t\t ))_-    -__-    -__-    -__-    -__-    -__-    -__-    -__-  ((\n");
    printf("\t\t\t((       _ _                                                    ))\n");
    printf("\t\t\t )) .-. | | |                                                  ((\n");
    printf("\t\t\t((  |_|_|.|=|  ___  _   _ _  _ \t __    _ _                      ))\n");
    printf("\t\t\t )) | | |.|.| | __|| | | | || | |  |  |_| |_ ___ ___ ___ _ _   ((\n");
    printf("\t\t\t((  | |=|.|=| | _| | 'V' | \\/ |\t|  |__| | . |  _| ''|  _| | |   ))\n");
    printf("\t\t\t )) |_|_|_|_| |___|!_/ \\_!\\___/\t|_____|_|___|_| |__||_| |_  |  ((\n");
    printf("\t\t\t((                                                      |___|   ))\n");
    printf("\t\t\t ))*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))  USER NAME : %-30s                ((\n", uname);
    printf("\t\t\t((   USER ID   : %-30d                 ))\n", uid);
    printf("\t\t\t ))  BOOK NAME : %-30s                ((\n", bname);
    printf("\t\t\t ))  SLOT      : %-30s                 ))\n", sname);
    printf("\t\t\t((   ISSUE DATE: %2d/%2d/%4d%20s                ((\n", issuedate[0],issuedate[1],issuedate[2]," " );
    printf("\t\t\t ))                                                            ((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))                                                            ((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))  _--_    _--_    _--_    _--_    _--_    _--_    _--_    _-((\n");
    printf("\t\t\t(((_-    -__-    -__-    -__-    -__-    -__-    -__-    -__-  )))\n");
}
void receive_receipt(char uname[30], int uid, char bname[30], char sname[10], int issuedate[], int receivedate[], int fine)
{

    printf("\t\t\t(((  _--_    _--_    _--_    _--_    _--_    _--_    _--_    _-)))\n");
    printf("\t\t\t ))_-    -__-    -__-    -__-    -__-    -__-    -__-    -__-  ((\n");
    printf("\t\t\t((       _ _                                                    ))\n");
    printf("\t\t\t )) .-. | | |                                                  ((\n");
    printf("\t\t\t((  |_|_|.|=|  ___  _   _ _  _ \t __    _ _                      ))\n");
    printf("\t\t\t )) | | |.|.| | __|| | | | || | |  |  |_| |_ ___ ___ ___ _ _   ((\n");
    printf("\t\t\t((  | |=|.|=| | _| | 'V' | \\/ |\t|  |__| | . |  _| ''|  _| | |   ))\n");
    printf("\t\t\t )) |_|_|_|_| |___|!_/ \\_!\\___/\t|_____|_|___|_| |__||_| |_  |  ((\n");
    printf("\t\t\t((                                                      |___|   ))\n");
    printf("\t\t\t ))*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))  USER NAME   : %-30s              ((\n", uname);
    printf("\t\t\t((   USER ID     : %-30d               ))\n", uid);
    printf("\t\t\t ))  BOOK NAME   : %-30s              ((\n", bname);
    printf("\t\t\t ))  SLOT        : %-30s               ))\n", sname);
    printf("\t\t\t((   ISSUE DATE  : %2d/%2d/%4d%20s              ((\n",issuedate[0],issuedate[1],issuedate[2], " " );
    printf("\t\t\t ))  RECEIVE DATE: %2d/%2d/%4d%20s                ))\n",receivedate[0],receivedate[1],receivedate[2], " " );
    printf("\t\t\t ))  FINE        : %-30d              ((\n", fine);
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))                                                            ((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))                                                            ((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))  _--_    _--_    _--_    _--_    _--_    _--_    _--_    _-((\n");
    printf("\t\t\t(((_-    -__-    -__-    -__-    -__-    -__-    -__-    -__-  )))\n");
}

void header_box(char name[])
{
    printf("\t\t\t((       _ _                                                    ))\n");
    printf("\t\t\t )) .-. | | |                                                  ((\n");
    printf("\t\t\t((  |_|_|.|=|  ___  _   _ _  _ \t __    _ _                      ))\n");
    printf("\t\t\t )) | | |.|.| | __|| | | | || | |  |  |_| |_ ___ ___ ___ _ _   ((\n");
    printf("\t\t\t((  | |=|.|=| | _| | 'V' | \\/ |\t|  |__| | . |  _| ''|  _| | |   ))\n");
    printf("\t\t\t )) |_|_|_|_| |___|!_/ \\_!\\___/\t|_____|_|___|_| |__||_| |_  |  ((\n");
    printf("\t\t\t((                                                      |___|   ))\n");
    printf("\t\t\t ))*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))                                                            ((\n");
    printf("\t\t\t((                           %-30s     ))\n", name);
    printf("\t\t\t ))                                                            ((\n");
    printf("\t\t\t((                                                              ))\n");
    printf("\t\t\t ))*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-((\n");
}
void header_line()
{
    printf("     _ _                     \n");
    printf(".-. | | |                     \n");
    printf("|_|_|.|=|  ___  _   _ _  _ \t\n");
    printf("| | |.|.| | __|| | | | || | \n");
    printf("| |=|.|=| | _| | 'V' | \\/ |\t\n");
    printf("|_|_|_|_| |___|!_/ \\_!\\___/\t\n");
    printf("  _    _ _                        __  __                                       _     ___         _             \n");
    printf(" | |  (_) |__ _ _ __ _ _ _ _  _  |  \\/  |__ _ _ _  __ _ __ _ ___ _ __  ___ _ _| |_  / __|_  _ __| |_ ___ _ __  \n");
    printf(" | |__| | '_ \\ '_/ _` | '_| || | | |\\/| / _` | ' \\/ _` / _` / -_) '  \\/ -_) ' \\  _| \\__ \\ || (_-<  _/ -_) '  \\ \n");
    printf(" |____|_|_.__/_| \\__,_|_|  \\_, | |_|  |_\\__,_|_||_\\__,_\\__, \\___|_|_|_\\___|_||_\\__| |___/\\_, /__/\\__\\___|_|_|_|\n");
    printf("                           |__/                        |___/                             |__/                  \n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
}

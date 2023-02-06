/**Student Database Management
        Created By
FA20-BSE-064(HAFIZ KUNWAR MUHAMMAD AHMAD)*/

#include<stdlib.h>  //This header file includes I/O functions such as : printf, scanf
#include<string.h>  //This header file includes string functions such as : strcpy
#include<stdio.h>   //This header file includes functions such as : malloc, system.


//-------------------------------------------<< Defining the Structure of Student Node >>---------------------------------

struct Student      //I am using Singly Linked List. Which contain various attributes of student.
{
    int rollnumber;
    char name[100];
    char lastname[100];
    char gender[100];
    int age;
    char address[100];
    char phone[100];
    char mail[100];
    int semester;
    char dept[100];
    int semFee;
    int HostelFee;
    int TotalFee;
    struct Student *next;

};
//Global variables declaration
struct Student *head;
int countNode = 0;

//---------------------------------------------<< INSERT Function >>--------------------------------------------
void insert(int rollnumber, char* name, char* lastname, char* gender, int age, char* address, char* phone, char* mail, int semester, char* dept, int semFee, int HostelFee, int TotalFee)
{

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->lastname, lastname);
    strcpy(student->gender, gender);
    student->age = age;
    strcpy(student->address, address);
    strcpy(student->phone, phone);
    strcpy(student->mail, mail);
    student->semester = semester;
    strcpy(student->dept, dept);
    student->semFee = semFee;
    student->HostelFee = HostelFee;
    student->TotalFee = TotalFee;
    student->next = NULL;

    if(head==NULL)
    {
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else
    {
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    printf("\n\n\t\t\t\t\t **************************( STUDENT RECORD ADDED SUCCESSFULY )**************************\n\n");
    printf("\t\t\t\t\t\t    **************************(STUDENT ID :%d)**************************", student->rollnumber);
    countNode++;

    printf("\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}

//---------------------------------------------<< SEARCHING Function >>--------------------------------------------
void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL)
    {
        if(temp->rollnumber==rollnumber)
        {
            printf("\n\t\t\t\t\t***********************************( RECORD FOUND )***********************************\n\n");
            recordhead();
            printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10d | %10s   |\n", temp->rollnumber, temp->name, temp->lastname,  temp->gender,  temp->age,  temp->address,  temp->phone,  temp->mail,  temp->semester,  temp->dept);
            printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
            getch();
            system("cls");
            return;
        }
        temp = temp->next;
    }
    printf("\n\n\t\t\t\tStudent with roll number %d is not found !!!\n\n\n", rollnumber);
    recordhead();
    printf("\n\t\t\t\t\t***********************************( RECORD NOT FOUND )***********************************\n\n");
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}

//---------------------------------------------<< UPDATE Function >>--------------------------------------------
void update(int rollnumber)
{

    struct Student * temp = head;
    while(temp!=NULL)
    {

        if(temp->rollnumber==rollnumber)
        {
            printf("\n\t\t\t\tRecord with roll number %d Found !!!\n\n", rollnumber);
            printf("\n\t\t\t\t\t***********************************( RECORD FOUND )***********************************\n\n");
            recordhead();
            printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10d | %10s   |\n", temp->rollnumber, temp->name, temp->lastname,  temp->gender,  temp->age,  temp->address,  temp->phone,  temp->mail,  temp->semester,  temp->dept);
            printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

            printf("\n\t\t\t\tUpdate Details:\n\n");

            printf("\t\t\t\tEnter new First name: ");
            scanf("%s", temp->name);
            fflush(stdin);

            printf("\t\t\t\tEnter new last name: ");
            scanf("%s", temp->lastname);
            fflush(stdin);

            printf("\t\t\t\tEnter new gender: ");
            scanf("%s", temp->gender);
            fflush(stdin);

            printf("\t\t\t\tEnter new age: ");
            scanf("%d",&temp->age);
            fflush(stdin);

            printf("\t\t\t\tEnter new address: ");
            scanf("%s",&temp->address);
            fflush(stdin);

            printf("\t\t\t\tEnter new phone: ");
            scanf("%s",&temp->phone);
            fflush(stdin);

            printf("\t\t\t\tEnter new mail: ");
            scanf("%s",&temp->mail);
            fflush(stdin);

            printf("\t\t\t\tEnter new semester: ");
            scanf("%d",&temp->semester);
            fflush(stdin);

            printf("\t\t\t\tEnter new departmert: ");
            scanf("%s",&temp->dept);
            fflush(stdin);

            printf("\t\t\t\tEnter new semester fees: ");
            scanf("%d",&temp->semFee);
            fflush(stdin);

            printf("\t\t\t\tEnter new Hostel fees: ");
            scanf("%d",&temp->HostelFee);
            fflush(stdin);

            temp->TotalFee = temp->semFee+temp->HostelFee;
            fflush(stdin);

            printf("\n\t\t\t\t\t***********************************( Editing Successful )***********************************\n\n");

            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
            getch();
            system("cls");
            return;
        }
        temp = temp->next;

    }

    printf("\n\n\t\t\t\tStudent with roll number %d is not found !!!\n\n", rollnumber);
    recordhead();
    printf("\n\t\t\t\t\t***********************************( RECORD NOT FOUND )***********************************\n\n");
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}

//---------------------------------------------<< DELETE Function >>--------------------------------------------
void Delete(int rollnumber)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head;
    while(temp1!=NULL)
    {

        if(temp1->rollnumber==rollnumber)
        {

            printf("\n\n\t\t\t\tRecord with roll number %d Found !!!\n\n", rollnumber);
            recordhead();
            printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10d | %10s   |\n", temp1->rollnumber, temp1->name, temp1->lastname,  temp1->gender,  temp1->age,  temp1->address,  temp1->phone,  temp1->mail,  temp1->semester,  temp1->dept);
            printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

            if(temp1==temp2)
            {
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else
            {
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("\n\n\t\t\t\t\t\t**********************( THIS RECORD IS DELETED )***********************\n\n");
            countNode--;

            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
            getch();
            system("cls");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("\n\n\t\t\t\tStudent with roll number %d is not found !!!\n\n", rollnumber);
    recordhead();
    printf("\n\t\t\t\t\t***********************************( RECORD NOT FOUND )***********************************\n\n");
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}

//---------------------------------------------<< DISPLAY Function >>--------------------------------------------
void display()
{
    struct Student * temp = head;

    recordhead();
    if(temp == NULL)
    {
        printf("\n\t\t\t\t\t***********************************( RECORD NOT FOUND )***********************************\n\n");
        printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }

    while(temp!=NULL)
    {
        printf("\t\t|%3d  |   %9s       | %9s      |%4s   |%4d  | %10s    | %12s | %20s | %10d | %10s   |\n", temp->rollnumber, temp->name, temp->lastname,  temp->gender,  temp->age,  temp->address,  temp->phone,  temp->mail,  temp->semester,  temp->dept);
        printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

        temp = temp->next;

    }

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}

//---------------------------------------------<< DISPLAY Function >>--------------------------------------------
void displayFees()
{
    struct Student * temp = head;

    recordFeehead();
    if(temp == NULL)
    {
        printf("\n\t\t\t\t\t***********************************( RECORD NOT FOUND )***********************************\n\n");
        printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }

    while(temp!=NULL)
    {
        if(temp->HostelFee > 0)
        {
        printf("\t\t|%3d  |   %9s       | %9s      | %10d | %10s   | %22d | %22d | %16d |\n", temp->rollnumber, temp->name, temp->lastname, temp->semester,  temp->dept, temp->semFee, temp->HostelFee, temp->TotalFee);
        printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

        temp = temp->next;
        }
        else
        {
        printf("\t\t|%3d  |   %9s       | %9s      | %10d | %10s   | %22d |          ***           | %16d |\n", temp->rollnumber, temp->name, temp->lastname, temp->semester,  temp->dept, temp->semFee, temp->semFee);
        printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");

        temp = temp->next;
        }

    }

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}

//---------------------------------------------<< SORTING Function >>--------------------------------------------
void sortingRecord()
{
    struct Student *current = head, *temp1 = NULL;
    int temp;

    if(head == NULL)
    {
        return;
    }
    else
    {
        while(current != NULL)
        {
            temp1 = current->next;

            while(temp1 != NULL)
            {
                if(current->rollnumber > temp1->rollnumber) //sorting record roll number wise
                {
                    temp = current->rollnumber;
                    current->rollnumber = temp1->rollnumber;
                    temp1->rollnumber = temp;
                }
                temp1 = temp1->next;
            }
            current = current->next;
        }
    }
}

//---------------------------------------------<< REVERSE Function >>--------------------------------------------
void reverseRecord()
{
    struct Student *prevnode, *currentnode, *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode!=0) //reversing records by addresses
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

//---------------------------------------------<< COUNT Function >>--------------------------------------------
void count()
{
    printf("\n\t\t\t\t\t\t\t-----------There are (%d) STUDENT RECORDS in the DATABASE-----------\n", countNode);

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}


//---------------------------------------------<< CREATION Function >>--------------------------------------------
//Function to Enter Data Hardcoded
void creation()
{
    //First Hard coded Creation
    head = NULL;
    int choice;
    int rollnumber;
    char name[100];
    char lastname[100];
    char gender[100];
    int age;
    char address[100];
    char phone[100];
    char mail[100];
    int semester;
    char dept[100];
    int semFee;
    int HostelFee;
    int TotalFee;

    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = 2;
    strcpy(student->name, "Ahmad");
    strcpy(student->lastname, "Afzal");
    strcpy(student->gender, "M");
    student->age = 20;
    strcpy(student->address, "A1 Lhr");
    strcpy(student->phone, "03001234");
    strcpy(student->mail, "afzal@gmail.com");
    student->semester = 3;
    strcpy(student->dept, "SE");
    student->semFee = 80000;
    student->HostelFee = 0;
    TotalFee = semFee+HostelFee;
    student->TotalFee = TotalFee;
    student->next = NULL;

    if(head==NULL)
    {
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else
    {
        // if list is not empty
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    countNode++;

    //Second Hard coded Creation
    struct Student * student2 = (struct Student *) malloc(sizeof(struct Student));
    student2->rollnumber = 4;
    strcpy(student2->name, "Kunwar");
    strcpy(student2->lastname, "Ahmad");
    strcpy(student2->gender, "M");
    student2->age = 22;
    strcpy(student2->address, "D1 Lhr");
    strcpy(student2->phone, "03007890");
    strcpy(student2->mail, "ahmad@gmail.com");
    student2->semester = 1;
    strcpy(student2->dept, "CS");
    student2->semFee = 90000;
    student2->HostelFee = 3300;
    student2->TotalFee = 93300;
    student2->next = NULL;

    if(head==NULL)
    {
        // if head is NULL
        // set student as the new head
        head = student2;
    }
    else
    {
        // if list is not empty
        // insert student in beginning of head
        student2->next = head;
        head = student2;
    }
    countNode++;

}


//---------------------------------------------<< MAIN Function >>--------------------------------------------
int main()
{
    head = NULL;
    int choice;
    int rollnumber;
    char name[100];
    char lastname[100];
    char gender[100];
    int age;
    char address[100];
    char phone[100];
    char mail[100];
    int semester;
    char dept[100];
    int semFee;
    int HostelFee;
    int TotalFee;

    welcome();
    creation();

    do
    {
        menu();
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            header();
            printf("\n\t\t\t\t\t***********************************INSERT STUDENT RECORD***********************************\n\n");
            printf("\t\t\t\tEnter Roll Number: ");
            scanf("%d", &rollnumber);
            printf("\t\t\t\tEnter First Name: ");
            scanf("%s", name);
            printf("\t\t\t\tEnter Last Name: ");
            scanf("%s", lastname);
            printf("\t\t\t\tEnter Gender[M/F]: ");
            scanf("%s", &gender);
            printf("\t\t\t\tEnter Age: ");
            scanf("%d", &age);
            printf("\t\t\t\tEnter Address: ");
            scanf("%s", &address);
            printf("\t\t\t\tEnter Phone: ");
            scanf("%s", &phone);
            printf("\t\t\t\tEnter Mail: ");
            scanf("%s", &mail);
            printf("\t\t\t\tEnter Semester: ");
            scanf("%d", &semester);
            printf("\t\t\t\tEnter Department: ");
            scanf("%s", &dept);
            printf("\t\t\t\tEnter Semester Fees: ");
            scanf("%d", &semFee);
            printf("\t\t\t\tEnter Hostel Fee: ");
            scanf("%d", &HostelFee);
            TotalFee = semFee+HostelFee;
            insert(rollnumber, name, lastname, gender, age, address, phone, mail, semester, dept, semFee, HostelFee, TotalFee);
            break;
        case 2:
            header();
            printf("\n\t\t\t\t\t***********************************SEARCH STUDENT RECORD***********************************\n\n");
            printf("\t\t\t\tEnter Roll Number to Search: ");
            scanf("%d", &rollnumber);
            search(rollnumber);
            break;
        case 3:
            header();
            printf("\n\t\t\t\t\t***********************************DELETE STUDENT RECORD***********************************\n\n");
            printf("\t\t\t\tEnter Roll Number to Delete: ");
            scanf("%d", &rollnumber);
            Delete(rollnumber);
            break;
        case 4:
            header();
            printf("\n\t\t\t\t\t***********************************UPDATE STUDENT RECORD***********************************\n\n");
            printf("\t\t\t\tEnter Roll Number to Update: ");
            scanf("%d", &rollnumber);
            update(rollnumber);
            break;
        case 5:
            header();
            printf("\n\t\t\t\t\t***********************************DISPLAY STUDENT RECORD***********************************\n\n");
            display();
            break;
        case 6:
            header();
            printf("\n\t\t\t\t\t***********************************DISPLAY STUDENT FEE RECORD***********************************\n\n");
            displayFees();
            break;
        case 7:
            sortingRecord();
            header();
            printf("\n\t\t\t\t\t***********************************SORTED STUDENT RECORD***********************************\n\n");
            display();
            break;
        case 8:
            reverseRecord();
            header();
            printf("\n\t\t\t\t\t***********************************REVERSED STUDENT RECORD***********************************\n\n");
            display();
            break;
        case 9:
            header();
            printf("\n\t\t\t\t\t***********************************COUNT STUDENT RECORD***********************************\n\n");
            count();
            break;
        case 0:
            ex_it();
            break;
        //If Wrong Selection is done
        default:
            {
                system("cls");
                header();
                printf("\n\nt\t\t\t\t\t************************          INVALID SELECTION          ************************\n\n");
                printf("\t\t\t\t\t\t\tPress Any to continue....................");
                getch();
                system("cls");
            }

        }
    }
    while (choice != 0);

    return 0;
}




//-------------------------------------------<< Main Menu >>--------------------------------------------
void menu()
{
    //Menu which Display first
    header();
    printf("\n\n\n               ");
    printf("\t\t\t                                  __________*********__________\n\n               ");
    printf("\t\t\t                                    1 - Insert Student Record\n\n               ");
    printf("\t\t\t                                    2 - Search Student Record\n\n               ");
    printf("\t\t\t                                    3 - Delete Student Record\n\n               ");
    printf("\t\t\t                                    4 - Update Student Record\n\n               ");
    printf("\t\t\t                                    5 - Display Student Record\n\n               ");
    printf("\t\t\t                                    6 - Display Fees Record\n\n               ");
    printf("\t\t\t                                    7 - Sort Student Record\n\n               ");
    printf("\t\t\t                                    8 - Reverse Student Record\n\n               ");
    printf("\t\t\t                                    9 - Count Student Record\n\n               ");
    printf("\t\t\t                                    0 - Exit\n\n               ");
    printf("\t\t\t                                  __________*********__________\n\n\n               \t\t\t\t\tEnter Option : ");
}


//-----------------------------------------<< Record Header >>------------------------------------------------
void recordhead()
{
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|[Id]       First Name       Last Name      Gender   Age        Address        Contact            Email           Semester      Department  |\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
}

//-----------------------------------------<< Record Fees Header >>------------------------------------------------
void recordFeehead()
{
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|[Id]       First Name       Last Name       Semester     Department           Semeseter Fees          Hostel Fees            Total Fees    |\n");
    printf("\t\t|                                                                                                                                           |\n");
    printf("\t\t|-------------------------------------------------------------------------------------------------------------------------------------------|\n");
}
//-----------------------------------------<< Program Head >>------------------------------------------------
void header()
{
    printf("\t\t ___________________________________________________________________________________________________________________________________________\n");
    printf("\t\t|                                                      |                             |                                                      |\n");
    printf("\t\t|                  ****************                    | STUDENT DATABASE MANAGEMENT |                  ****************                    |\n");
    printf("\t\t|                                                      |_____________________________|                                                      |\n");
    printf("\t\t|___________________________________________________________________________________________________________________________________________|\n\n\n");
}



//----------------------------------------------<< START PAGE Function >>-------------------------------------------------------
void welcome()
{
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t###################################################################################################################\n");
    printf("\t\t\t\t#  _____________________________________________________________________________________________________________  #\n");
    printf("\t\t\t\t# | ___________________________________________________________________________________________________________ | #\n");
    printf("\t\t\t\t# ||                               .............................................                               || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||                                             FA20-BSE-064                                                  || #\n");
    printf("\t\t\t\t# ||             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                               WELCOME TO                                 ::                || #\n");
    printf("\t\t\t\t# ||             ::                      STUDENT DATABASE MANAGEMENT                         ::                || #\n");
    printf("\t\t\t\t# ||             ::                    MADE BY: HAFIZ KUNWAR M. AHMAD                        ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::                                                                          ::                || #\n");
    printf("\t\t\t\t# ||             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::                || #\n");
    printf("\t\t\t\t# ||                                                                                                           || #\n");
    printf("\t\t\t\t# ||                               .............................................                               || #\n");
    printf("\t\t\t\t# ||___________________________________________________________________________________________________________|| #\n");
    printf("\t\t\t\t# |_____________________________________________________________________________________________________________| #\n");
    printf("\t\t\t\t#                                                                                                                 #\n");
    printf("\t\t\t\t###################################################################################################################\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\tPress Any key to continue....................");
    getch();
    system("cls");
}
//--------------------------------------------- << END Page Function >>----------------------------------------------------------
void ex_it()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t  _____________________________________________________________________________________________________________  \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |                                              THANK YOU                                                      | \n");
    printf("\t\t\t\t |                                        MADE BY: HAFIZ KUNWAR                                                | \n");
    printf("\t\t\t\t |                                             FA20-BSE-064                                                    | \n");
    printf("\t\t\t\t |                                                                                                             | \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");
    printf("\t\t\t\t |_____________________________________________________________________________________________________________| \n");

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPress Any key to exit....................");
    getch();
}


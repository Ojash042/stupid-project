#include <stdio.h>
#include <stdlib.h>

struct prisoner
{
    int PrisonerId;
    char Prisoner_FName[25];
    char Prisoner_LName[25];
    char Prisoner_Cell[10];
    int age;

    struct birthdetails
    {
    int day;
    char month[3];
    int year;
    }birth;
     
    struct releasedetails
    {
    int day;
    char month[3];
    int year;
    }release;

    char crime[25];

    }pri;

void Padd();
void Pread ();
void Psearch();
void Pdelete();
void banner();
void export();

FILE *fp;
FILE *fpcsv;

void main()
{   
    int choice;
    banner();
    printf("\nEnter \n[1] to update data \n[2] to view data \n[3] to search for a record \n[4] to delete a record\n[5] to export entire data in csv format\n[6] exit\n");
    printf(">>");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            Padd();
        break;

        case 2:
            Pread();
        break;

        case 3:
            Psearch();
        break;

        case 4:
            Pdelete();
        break;
    }
}

void Padd()
{
    fp=fopen("C:\\Users\\ojash.OJASH\\Documents\\Projects\\C\\School Project\\stupid-project\\prisoners.txt","a+"); //creates file in same directory as the program
    //fpcsv = fopen("./prisoners.csv","a+");

    printf("Enter prisoner id:");
    scanf("%d",&pri.PrisonerId);
    //fflush(stdin);
    printf("Enter prisoner's name\n");
    printf("Enter first name:");
    scanf("%s",pri.Prisoner_FName);
    printf("Enter last name:");
    scanf("%s",pri.Prisoner_LName);
    //fflush(stdin);
    printf("Enter prisoner cell no:");
    scanf("%s",pri.Prisoner_Cell);
    printf("Enter prisoner age:");
    scanf("%d",&pri.age);
    printf("Enter crime committed:");
    scanf("%s",pri.crime);
    printf("Enter release year:");
    scanf("%d",&pri.release.year);
    printf("Enter release month:");
    scanf("%s",&pri.release.month);
    printf("Enter release day:");
    scanf("%d",&pri.release.day);
    //fflush(stdin);

    fprintf(fp,"%d %s %s %s | Age:%d | Crime:%s | Release Day =%d-%s-%d \n",pri.PrisonerId,pri.Prisoner_FName,pri.Prisoner_LName,pri.Prisoner_Cell,pri.age,pri.crime,pri.release.year,pri.release.month,pri.release.day);

    fprintf(fpcsv,"S.N,Name,Cell,Age,Crime,Release Date\n");
    fprintf(fpcsv,"%d %s %s %s %d %s %d %s %d\n",pri.PrisonerId,pri.Prisoner_FName,pri.Prisoner_LName,pri.Prisoner_Cell,pri.age,pri.crime,pri.release.year,pri.release.month,pri.release.day);
    fclose(fpcsv);

    fclose(fp);
    main();

}

void Pread()
{
    int choice,count;
    count = 0;
    char filename[100];
    char c;
    char stri[100];
    system("cls");
    banner();
    fp=fopen("C:\\Users\\ojash.OJASH\\Documents\\Projects\\C\\School Project\\stupid-project\\prisoners.txt","r");
      if (fp == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }
    /*printf("\nEnter \n[1] to view entire data \n[2] to view data of certain prisoner\n");*/
    /*for (c = getc(fp); c != EOF; c = getc(fp)){ 
        if (c == '\n'){ // Increment count if this character is newline 
            count = count + 1; 
        }
    }
        fscanf(fp, "%[^\n]", &stri);
        printf("\n%s", stri);
    for (int i=0; i<count;i++){
        fscanf(fp,"%d %s %s %s %d %s %d %s %d",&pri.PrisonerId, &pri.Prisoner_FName, &pri.Prisoner_LName,&pri.Prisoner_Cell, &pri.age, &pri.crime, &pri.release.year, &pri.release.month, &pri.release.day);
        printf("PrisonerID:%d | Prisoner Name:%s %s | Prisoner Cell no:%s | Age:%d | Crime:%s | Release Day: %d-%s-%d \n",pri.PrisonerId,pri.Prisoner_FName,pri.Prisoner_LName,pri.Prisoner_Cell,pri.age,pri.crime,pri.release.year,pri.release.month,pri.release.day);
    }*/
    char g;
    while((c=fgetc(fp))!=EOF){
        printf("%c",c);
    }
        fclose(fp);
}


void Psearch()
{
    system("cls");
    banner();
    int iden,ig;
    char c;
    int count=0;
    fp = fopen("C:\\prisoner.txt","r");
    printf("Enter the prisoner's Id: ");
    scanf("%d",iden);
    for (c = getc(fp); c != EOF; c = getc(fp)){ 
        if (c == '\n'){ // Increment count if this character is newline 
            count = count + 1; 
        }
    }
    for (int i=0; i<0;i++){
        fscanf(fp,"%d %s %s %s %d %s %d %s %d",&pri.PrisonerId, &pri.Prisoner_FName, &pri.Prisoner_LName,&pri.Prisoner_Cell, &pri.age, &pri.crime, &pri.release.year, &pri.release.month, &pri.release.day);
        if (pri.PrisonerId==iden)
        {
        printf("PrisonerID:%d | Prisoner Name:%s %s | Prisoner Cell no:%s | Age:%d | Crime:%s | Release Day: %d-%s-%d \n",pri.PrisonerId,pri.Prisoner_FName,pri.Prisoner_LName,pri.Prisoner_Cell,pri.age,pri.crime,pri.release.year,pri.release.month,pri.release.day);
        }
        
    }
    
}

void Pdelete()
{
    system("cls");
    banner();
    printf("Hello");
}

void export()
{

}

void banner()
{
printf("        ########   ########   ##     ##   ######  \n");
printf("        ##     ##  ##     ##  ###   ###  ##    ## \n");
printf("        ##     ##  ##     ##  #### ####  ##       \n");
printf("        ########   ########   ## ### ##   ######  \n");
printf("        ##         ##   ##    ##     ##        ## \n");
printf("        ##         ##    ##   ##     ##  ##    ## \n");
printf("        ##         ##     ##  ##     ##   ######  \n\n\n");
printf("      }----------------------------------------------{\n");
printf("}-------------Prisoner Record Management System-------------{\n");
printf("      }----------------------------------------------{\n\n");

}
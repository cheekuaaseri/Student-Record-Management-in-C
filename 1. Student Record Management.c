#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
typedef struct studentdata{
        char suid[20], sname[20], sfname[20], smname[20], sclass[20], semail[50];
        int smobileno;
}std;

typedef struct admindata
{
    char aname[20], ausername[50], apassword[20];
}admin;
//

void firstrun(admin adata);
void welcome();
void end();
void processing(int seconds);
void admin_login(admin adata , std sdata);
void admin_options(admin adata , std sdata);
void admin_change_password(admin adata);
void add_Student(std sdata);
void search_student(std sdata);



int main(){
    admin adata;
    std sdata;
    int c;
    welcome();
    printf("        Make a Choice ----------->                                   \n\n");
    printf("        Press 1 for ADMIN Login                                        \n");
    printf("        Press 2 for Reset Database or First Login                      \n");
    printf("        Press 3 to Close the System                                    \n");
    printf("                                                  ");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("        You are at Admin Login                                         \n");
        processing(1);
        admin_login(adata,sdata);
        break;
    case 2:
        printf("        This Will Lead to Wipe Database --> Approx. 20 Seconds         \n");
        processing(20);
        firstrun(adata);
        printf("-----------------------------------------------------------------------\n");
        printf("        Wiping Data is Done -- Press Any Key to Continue               \n");
        getch();
        system("cls");
        main();
        break;
    case 3:
        printf("        Here's The Exit                                                \n");
        end();
        break;
    default:
        printf("        Invalid Input --- Try to add Suitable Input From Above         \n");
        processing(2);
        main();
        break;
    }
return 0;
}







void firstrun(admin adata){
    FILE *ptrfirstrun , *resetstd;
    ptrfirstrun = fopen("Admin_StudentRecord_Management.dat","wb");
    strcpy(adata.ausername,"admin");
    strcpy(adata.apassword,"admin");
    strcpy(adata.aname,"admin");
    fwrite(&adata,sizeof(adata),1,ptrfirstrun);
    // printf("-----------------------------------------------------------------------\n");
    // printf("        Wiping Data is Done -- Press Any Key to Continue               \n");
    printf("\n        Default Username Is :   %s",adata.ausername);
    printf("\n        Default Password Is :   %s\n",adata.apassword);
    rewind(ptrfirstrun);
    fclose(ptrfirstrun);
    resetstd =fopen ("StudentRecord_StudentRecord_Management.dat","wb");
    fclose(resetstd);

}
void welcome(){
    system("cls");
    printf("\n");
    printf("***********************************************************************\n");
    printf("**                   Welcome to Student Portal                       **\n");
    printf("***********************************************************************\n");
    printf("\n");
}
void end(){
    printf("\n");
    printf("        Closing the PORTAL                                             \n");
    processing(2);
    printf("\n");
    printf("***********************************************************************\n");
    printf("**                      Bye!! See You Soon                           **\n");
    printf("***********************************************************************\n");
}
void processing(int seconds){
    int delay2= (seconds*100);
    printf("        System Under Processing        ");
    for (int i = 1; i < 11; i++)
    {
        printf("# ");
        Sleep(delay2);
    }
    printf("\n");   
}

void admin_login(admin adata , std sdata){
    int d=0;
    FILE *ptradmin_login;
    ptradmin_login = fopen("Admin_StudentRecord_Management.dat","rb");
    if (ptradmin_login == NULL)
    {
    printf("\n   Trying You to Get        ---------> Please Wait\n");
    processing(10);
    printf("\n***********************************************************************\n");
    printf("<--------Disclamer :  Database is Crashed / Currupted----------------->\n");
    printf("***********************************************************************\n");
    printf("\n     Please Do an Reset to make System Work Normally                 \n");
    printf("-----------------------------------------------------------------------\n");
    printf("            Press Any Key to Continue                                  \n");
    getch();
    main();
    }
    char dummyusername[50];
    char dummypassword[50];
    fflush(stdin);
    printf("-----------------------------------------------------------------------\n");
    printf("            Enter Username    :            ");
    gets(dummyusername);
    fflush(stdin);
    printf("            Enter Password    :            ");
    gets(dummypassword);
    printf("-----------------------------------------------------------------------\n");
    fflush(stdin);
    processing(2);
    while (fread(&adata,sizeof(adata),1,ptradmin_login)!= NULL)
    {
        int temp = strcmp(dummyusername,adata.ausername);
        int temp2 = strcmp(dummypassword,adata.apassword);
        if (temp == 0 && temp2 ==0)
        {
            printf("                                        Login Succesfull               \n");
            d=1;
            break;
        }
    }
    rewind(ptradmin_login);
    fclose(ptradmin_login);
    if (d==1)
    {
        Sleep(100);
        admin_options(adata,sdata);
    }
    else {
    printf("-----------------------------------------------------------------------\n");
    printf("            Wrong Username & Password                                  \n");
    printf("            Try Again -- Press Any Key to Continue                     \n");
    getch();
    admin_login(adata,sdata);
    }
}

void admin_options(admin adata , std sdata){ // mark emp attendence, search & print all data, add emp, edit emp data
    int c;
    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    printf("        Choose Your Desired Option                                   \n\n");
    printf("        Press 1 to Change Admin Password                               \n");
    printf("        Press 2 to Add Addmision Record                                \n");
    printf("        Press 3 to Delete Addmision Record                                \n");
    printf("        Press 4 to Search in Record                                    \n");
    printf("        Press 5 to Print Student Data                                  \n");
    printf("        Press 6 to Exit from Portal                                    \n");
    printf("                                                  ");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        printf("-----------------------------------------------------------------------\n");
        printf("                       Change Password Wizard                          \n");
        printf("-----------------------------------------------------------------------\n");
        processing(2);
        admin_change_password(adata);
        printf("            Press Any Key to Continue                                  \n");
        getch();
        admin_options(adata,sdata);
        break;
    case 2:
        printf("-----------------------------------------------------------------------\n");
        printf("                    Add New Addmision Record                           \n");
        printf("-----------------------------------------------------------------------\n");
        processing(2);
        add_Student(sdata);
        printf("            Press Any Key to Continue                                  \n");
        getch();
        admin_options(adata,sdata);
        break;
    case 3:
        printf("-----------------------------------------------------------------------\n");
        printf("                     Delete Addmision Record                           \n");
        printf("-----------------------------------------------------------------------\n");
        processing(2);
        del_student(sdata);
        printf("            Press Any Key to Continue                                  \n");
        getch();
        admin_options(adata,sdata);
        break;
    case 4:
        printf("-----------------------------------------------------------------------\n");
        printf("                     Search in Student Records                         \n");
        printf("-----------------------------------------------------------------------\n");
        processing(2);
        search_student(sdata);
        printf("            Press Any Key to Continue                                  \n");
        getch();
        admin_options(adata,sdata);
        break;
    case 5:
        printf("-----------------------------------------------------------------------\n");
        printf("                     Student Data Printing Wizard                      \n");
        printf("-----------------------------------------------------------------------\n");
        show_student(sdata);
        printf("            Press Any Key to Continue                                  \n");
        getch();
        admin_options(adata,sdata);
        break;
    case 6:
        processing(4);
        printf("        Here's The Exit                                                \n");
        end();
        return 0;
        break;
    
    default:
        printf("        Invalid Input --- Try to add Suitable Input From Above         \n");
        processing(2);
        admin_options(adata, sdata);
        break;
    }
}

void admin_change_password(admin adata){
    char dummyusername[20];
    char dummypassword[20];
    FILE *ptr_admin_password_change, *ptr_temp;
    ptr_admin_password_change = fopen("Admin_StudentRecord_Management.dat","rb");
    ptr_temp = fopen("temp_StudentRecord_Management.dat","wb");

    fflush(stdin);
    fflush(stdin);
    printf("-----------------------------------------------------------------------\n");
    printf("        Enter Old Username    :            ");
    gets(dummyusername);
    fflush(stdin);
    printf("        Enter old Password    :            ");
    gets(dummypassword);
    printf("-----------------------------------------------------------------------\n");
    fflush(stdin);
    processing(3);
    fread(&adata, sizeof(adata),1,ptr_admin_password_change);
    int temp = strcmp(dummyusername,adata.ausername);
    int temp2 = strcmp(dummypassword,adata.apassword);
    if (temp ==0 && temp2 == 0)
    {
        printf("-----------------------------------------------------------------------\n");
        printf("        Enter New Username    :            ");
        gets(adata.ausername);
        fflush(stdin);
        printf("        Enter New Password    :            ");
        gets(adata.apassword);
        printf("-----------------------------------------------------------------------\n");
        fflush(stdin);
        fwrite(&adata,sizeof(adata),1,ptr_temp);
        processing(3);
    }
    else
    {
        printf("-----------------------------------------------------------------------\n");
        printf("            Wrong Username & Password                                  \n");
        printf("            Try Again -- Press Any Key to Continue                     \n");
        fclose(ptr_admin_password_change);
        fclose(ptr_temp);
        getch();
        admin_change_password(adata);
    }
    fflush(stdin);
    rewind(ptr_admin_password_change);
    fclose(ptr_admin_password_change);
    remove("Admin_StudentRecord_Management.dat");
    fflush(stdin);
    rewind(ptr_temp);
    fclose(ptr_temp);
    rename("temp_StudentRecord_Management.dat","Admin_StudentRecord_Management.dat");
    printf("-----------------------------------------------------------------------\n");
    printf("                      Password Changed Succesfully                     \n");
    printf("-----------------------------------------------------------------------\n");

}

void add_Student(std sdata){
    FILE *ptr_add_student;
    ptr_add_student = fopen("StudentRecord_StudentRecord_Management.dat","ab+");
    int p;
    printf("-----------------------------------------------------------------------\n");
    do {
    fflush(stdin);
    printf("\n         Enter Student ID                 :         ");
    gets(sdata.suid);                                                                     
    fflush(stdin);
    printf("         Enter Student Name               :         ");
    gets(sdata.sname);                                                                    
    fflush(stdin);
    printf("         Enter Student Fathers's Name     :         ");
    gets(sdata.sfname);                                                                   
    fflush(stdin);
    printf("         Enter Student Mother's Name      :         ");
    gets(sdata.smname);                                                                   
    fflush(stdin); 
    printf("         Enter Student Class / Section    :         ");
    gets(sdata.sclass);                                                                   
    fflush(stdin);
    printf("         Enter Student Email              :         ");
    gets(sdata.semail);                                                                   
    fflush(stdin);
    printf("         Enter Mobile no.                 :         ");
    scanf("%d",&sdata.smobileno);
    fwrite(&sdata,sizeof(sdata),1,ptr_add_student);
    fflush(stdin);
    printf("-----------------------------------------------------------------------\n");
    printf("                        Student Added Succesfully                      \n");
    printf("-----------------------------------------------------------------------\n");
    printf("\n            Enter 0 to Add more                   ");
    scanf("%d",&p);
    }while (p==0);
    rewind(ptr_add_student);
    fclose(ptr_add_student);
}

void search_student(std sdata){
    int c, d=0;
    FILE *ptr_search_student;
    ptr_search_student = fopen("StudentRecord_StudentRecord_Management.dat","rb");

    printf("                                                                       \n");
    printf("        Press 1 to Search By Student UID                               \n");
    printf("        Press 2 to Search By Student NAME                              \n");
    printf("        Press 3 to Search By Student FATHERS NAME                      \n");
    printf("        Press 4 to Search By Student MOTHERS NAME                      \n");
    printf("        Press 5 to Search By Student MOBILE NUMBER                     \n");
    printf("        Press 6 to Search By Student COURSE                            \n");
    printf("                                                  ");
    scanf("%d",&c);
    fflush(stdin);
    switch (c)
    {
    case 1:
        char id[20];
        printf("        Enter UID of Student               :      ");
        gets(id);
        processing(2);
        fflush(stdin);
        while (fread(&sdata,sizeof(sdata),1,ptr_search_student)!= NULL)
        {
            int temp = strcmp(id, sdata.suid);
        if (temp == 0){
            printf("\n        Student UID                  :      %s", sdata.suid);
            printf("\n        Enter Student Name           :      %s", sdata.sname);
            printf("\n        Enter Student Father Name    :      %s",sdata.sfname);
            printf("\n        Enter Student Mother Name    :      %s",sdata.smname);
            printf("\n        Enter Student Course         :      %s",sdata.sclass);
            printf("\n        Enter Student Email          :      %s",sdata.semail);
            printf("\n        Enter Student MObile Number  :      %d\n",sdata.smobileno);
            d=1;
        }
        }
        if (d==0){
            printf("                                      --> UID is Not in Database       \n");
            search_student(sdata);
        }
        break;
    case 2:
        char name[20];
        printf("        Enter Name of Student              :      ");
        gets(name);
        processing(2);
        fflush(stdin);
        while (fread(&sdata,sizeof(sdata),1,ptr_search_student)!= NULL)
        {
            int temp = strcmp(name, sdata.sname);
        if (temp == 0){
            printf("\n        Student UID                  :      %s", sdata.suid);
            printf("\n        Enter Student Name           :      %s", sdata.sname);
            printf("\n        Enter Student Father Name    :      %s",sdata.sfname);
            printf("\n        Enter Student Mother Name    :      %s",sdata.smname);
            printf("\n        Enter Student Course         :      %s",sdata.sclass);
            printf("\n        Enter Student Email          :      %s",sdata.semail);
            printf("\n        Enter Student MObile Number  :      %d\n",sdata.smobileno);
            d=1;
        }
        }
        if (d==0){
            printf("                              --> Student Name is Not in Database       \n");
            search_student(sdata);
        }
        
        break;
    case 3:
        char fname[20];
        printf("        Enter Father's Name of Student     :      ");
        gets(fname);
        processing(2);
        fflush(stdin);
        while (fread(&sdata,sizeof(sdata),1,ptr_search_student)!= NULL)
        {
            int temp = strcmp(fname, sdata.sfname);
        if (temp == 0){
            printf("\n        Student UID                  :      %s", sdata.suid);
            printf("\n        Enter Student Name           :      %s", sdata.sname);
            printf("\n        Enter Student Father Name    :      %s",sdata.sfname);
            printf("\n        Enter Student Mother Name    :      %s",sdata.smname);
            printf("\n        Enter Student Course         :      %s",sdata.sclass);
            printf("\n        Enter Student Email          :      %s",sdata.semail);
            printf("\n        Enter Student MObile Number  :      %d\n",sdata.smobileno);
            d=1;
        }
        }
        if (d==0){
            printf("                     --> Student Father's Name is Not in Database       \n");
            search_student(sdata);
        }
        break;
    case 4:
        char mname[20];
        printf("        Enter Mother's Name of Student     :      ");
        gets(mname);
        processing(2);
        fflush(stdin);
        while (fread(&sdata,sizeof(sdata),1,ptr_search_student)!= NULL)
        {
            int temp = strcmp(mname, sdata.smname);
        if (temp == 0){
            printf("\n        Student UID                  :      %s", sdata.suid);
            printf("\n        Enter Student Name           :      %s", sdata.sname);
            printf("\n        Enter Student Father Name    :      %s",sdata.sfname);
            printf("\n        Enter Student Mother Name    :      %s",sdata.smname);
            printf("\n        Enter Student Course         :      %s",sdata.sclass);
            printf("\n        Enter Student Email          :      %s",sdata.semail);
            printf("\n        Enter Student MObile Number  :      %d\n",sdata.smobileno);
            d=1;
        }
        }
        if (d==0){
            printf("                     --> Student Mother's Name is Not in Database       \n");
            search_student(sdata);
        }
        break;
    case 5:
        int mb;
        printf("        Enter Mobile No. of Student        :      ");
        scanf("%d",&mb);
        processing(2);
        while (fread(&sdata,sizeof(sdata),1,ptr_search_student)!= NULL)
        {
        if (mb == sdata.smobileno){
            printf("\n        Student UID                  :      %s", sdata.suid);
            printf("\n        Enter Student Name           :      %s", sdata.sname);
            printf("\n        Enter Student Father Name    :      %s",sdata.sfname);
            printf("\n        Enter Student Mother Name    :      %s",sdata.smname);
            printf("\n        Enter Student Course         :      %s",sdata.sclass);
            printf("\n        Enter Student Email          :      %s",sdata.semail);
            printf("\n        Enter Student MObile Number  :      %d\n",sdata.smobileno);
            d=1;
        }
        }
        if (d==0){
            printf("                            --> Mobile Number is Not in Database       \n");
            search_student(sdata);
        }
        break;
    case 6:
        char course[20];
        printf("        Enter Name of Student              :      ");
        gets(course);
        processing(2);
        fflush(stdin);
        while (fread(&sdata,sizeof(sdata),1,ptr_search_student)!= NULL)
        {
            int temp = strcmp(course, sdata.sclass);
        if (temp == 0){
            printf("\n        Student UID                  :      %s", sdata.suid);
            printf("\n        Enter Student Name           :      %s", sdata.sname);
            printf("\n        Enter Student Father Name    :      %s",sdata.sfname);
            printf("\n        Enter Student Mother Name    :      %s",sdata.smname);
            printf("\n        Enter Student Course         :      %s",sdata.sclass);
            printf("\n        Enter Student Email          :      %s",sdata.semail);
            printf("\n        Enter Student MObile Number  :      %d\n",sdata.smobileno);
            d=1;
        }
        }
        if (d==0){
            printf("                                    --> Course is Not in Database       \n");
            search_student(sdata);
        }
        break;
    
    default:
        printf("                                      --> Wrong Input                   \n");
        search_student(sdata);
        break;
    }
    rewind(ptr_search_student);
    fclose(ptr_search_student);
}

void show_student(std sdata){
    FILE *ptr_search_student;
    ptr_search_student = fopen("StudentRecord_StudentRecord_Management.dat","rb");
    while (fread(&sdata,sizeof(sdata),1,ptr_search_student)!= NULL)
        {
            printf("\n        Student UID                  :      %s", sdata.suid);
            printf("\n        Enter Student Name           :      %s", sdata.sname);
            printf("\n        Enter Student Father Name    :      %s",sdata.sfname);
            printf("\n        Enter Student Mother Name    :      %s",sdata.smname);
            printf("\n        Enter Student Course         :      %s",sdata.sclass);
            printf("\n        Enter Student Email          :      %s",sdata.semail);
            printf("\n        Enter Student MObile Number  :      %d\n",sdata.smobileno);
        }
}

void del_student(std sdata){
    fflush(stdin);
    char temp[20];
    int p;
    FILE *ptr_del_student, *ptr_help;
    do {
    ptr_del_student = fopen("StudentRecord_StudentRecord_Management.dat","rb");
    rewind(ptr_del_student);
    if (ptr_del_student == NULL)
    {
    printf("\n   Trying You to Get        ---------> Please Wait\n");
    processing(10);
    printf("\n***********************************************************************\n");
    printf("<--------Disclamer :  Database is Crashed / Currupted----------------->\n");
    printf("***********************************************************************\n");
    printf("\n     Please Do an Reset to make System Work Normally                 \n");
    printf("-----------------------------------------------------------------------\n");
    printf("            Press Any Key to Continue                                  \n");
    getch();
    main();
    }
    ptr_help = fopen("temp_StudentRecord_Management.dat","wb");
    fflush(stdin);
    printf("-----------------------------------------------------------------------\n");
    printf("            Enter Student Id To Delete       ");
    gets(temp);
    processing(5);
    fflush(stdin);
    while (fread(&sdata,sizeof(sdata),1,ptr_del_student)!= NULL)
    {
        int temp2 = strcmp(temp,sdata.suid);
        if (temp2 !=0)
        {
            fwrite(&sdata,sizeof(sdata),1,ptr_help);
        }
    }
    fflush(stdin);
    rewind(ptr_del_student);
    fclose(ptr_del_student);
    remove("StudentRecord_StudentRecord_Management.dat");
    fflush(stdin);
    getch();
    rewind(ptr_help);
    fclose(ptr_help);
    fflush(stdin);
    rename("temp_StudentRecord_Management.dat","StudentRecord_StudentRecord_Management.dat");
    printf("-----------------------------------------------------------------------\n");
    printf("                        Student Removed Succesfully                    \n");
    printf("-----------------------------------------------------------------------\n");
    printf("        Enter 0 to remove more or 1 to Back Menu  ");
    scanf("%d",&p);
    }while(p==0);
}

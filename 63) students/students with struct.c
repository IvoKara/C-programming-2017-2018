#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<io.h>
#define lename 51
#define maxmark 20
#define maxls 30

typedef struct{
    int No;
    char name[lename];
    int marks[maxmark];
    float avr;
} stdnt;

stdnt s;
int i,j;

float average(int *marks,int n)
{
    int k=0;
    float ar=0;
    for(i=0;i<n;i++)
        if(marks[i]>0)
        {ar+=marks[i];k++;}
    return ar/k;
}

int valid_name_en(char *ime)
{
    int k, help;
    char a, z;
    for(k=1;k<strlen(ime);k++)
    {
        a='A';z='Z';
        help=(ime[k-1]==' ' || ime[k-1]=='-')?0:32;
        a+=help;
        z+=help;
        if(ime[k]<a||ime[k]>z)
        {
            if(ime[k]==' ' || ime[k]=='-')
                continue;
            printf("Invalid name.Try Again.\n");
            return 0;
        }
    }
    return 1;
}

int valid_name_bg(char *ime)
{
    int k;
    char a,q;
    int help1,help2;
    for(k=1;k<strlen(ime);k++)
    {
        a=-128;q=-97;
        help1=(ime[k-1]==' '||ime[k-1]=='-')?0:32;
        help2=(ime[k-1]==' '||ime[k-1]=='-')?0:80;
        a+=help1;
        q+=help2;
        if(ime[k]<a||ime[k]>q)
        {
            if(ime[k]==' ' || ime[k]=='-')
                continue;
            printf("Greshka\n");
            return 0;
        }
    }
    return 1;
}

void input_name(char *ime)
{
    int ok;
    char spaces[lename]=" ";
    printf("Name: ");
    gets(ime);
    strcat(spaces,ime);
    if(spaces[1]>0)
        ok=valid_name_en(spaces);
    else
        ok=valid_name_bg(spaces);
    if(!ok)
        input_name(ime);
}

int max_len_name(char *filepath)
{
    FILE *f;
    f=fopen(filepath,"rb");
    int max_len_name=0;
    while(!feof(f))
    {
        fread(&s,sizeof(s),1,f);
        if(max_len_name<strlen(s.name))
            max_len_name=strlen(s.name);
    }
    fclose(f);
    return max_len_name;
}

void printAll(char *filepath, char *lpath)
{

    int namelen = max_len_name(filepath);
    int leslen = max_len_name(lpath);
    int width,left,right;
    FILE *f;
    for(i=0;i<namelen+6;i++)
        printf("%c",'_');
    f=fopen(lpath,"rb");
    while(!feof(f))
    {
        if(fread(&s,sizeof(s),1,f))
        {
            width=leslen-strlen(s.name);
            left=width/2;
            right=width-left;
            printf("|%*c%s%*c",left+1,32,s.name,right+1,32);
        }
    }
    printf("| Average\n");
    fclose(f);
    f=fopen(filepath,"rb");
    while(!feof(f))
    {
        if(fread(&s,sizeof(s),1,f))
        {
            printf("\n%3d| %-*s |",s.No, namelen, s.name);
            j=0;
            while(s.marks[j]!=1)
            {
                if(s.marks[j]==0)
                    printf("%*c",leslen+3,'|');
                else
                {
                    left=(leslen+2)/2;
                    right=leslen-left;
                    printf("%*d%*c",left,s.marks[j],right+3,'|');
                }
                j++;
            }
            printf(" %.2f\n",s.avr);
        }

    }
    fclose(f);
}

void output(char *filepath)
{
    FILE *f;
    f=fopen(filepath,"rb");
    //printf("\nThis is the output: ");
    while(!feof(f))
    {
        if(fread(&s,sizeof(s),1,f))
            printf(" %s \n",s.name);
    }
    fclose(f);
}

int create_folder(char *folderpath, char *foldername)
{
    strcat(folderpath,"/");
    strcat(folderpath,foldername);
    return CreateDirectory(folderpath,NULL);
}

void create_file(char *filepath, char *filename)
{
    strcat(filepath,"/");
    strcat(filepath,filename);
    FILE *f;
    f=fopen(filepath,"wb");
    fclose(f);
}

int repeat(char *filepath, char *predmet)
{
    FILE *f;
    int byte=0;
    f=fopen(filepath,"rb");
    while(1)
    {
        fseek(f,byte,SEEK_SET);
        if(fread(&s,sizeof(s),1,f))
        {
            byte=ftell(f);
        }
        if(strcmp(s.name,predmet)==0)
        {
            fseek(f,0,SEEK_END);
            if(byte!=ftell(f))
            {
                byte=fseek(f,-sizeof(s),SEEK_END);
                printf("There is such a lesson\n");
            }
            break;
        }
    }
    fclose(f);
    return byte;
}

int file_len(char *filepath)
{
    int n;
    FILE *f;
    f=fopen(filepath,"rb");
    fseek(f,0,SEEK_END);
    n=ftell(f);
    fclose(f);
    return n;
}

void enumer(char *filepath)
{
    int size=0;
    FILE *f;
    f=fopen(filepath,"rb+");
    j=1;
    for(i=0;!feof(f);i+=size)
    {
        fseek(f,i,SEEK_SET);            ///като стигне на каря пак му казва да чете, затова става безкраен цикъл
        if(fread(&s,sizeof(s),1,f))
        {
            s.No=j;
            j++;
            fseek(f,i,SEEK_SET);
            fwrite(&s,sizeof(s),1,f);
            size=sizeof(s);
        }
    }
    fclose(f);
}

void filename_check(char *filename)
{
    char left[5]="\0",right[5]="\0";
    for(i=0;i<strlen(filename);i++)
        if(filename[i]==' ')
            break;
    strncpy(left,filename,i);
    if(strrchr(filename,' '))
        strcpy(right,strrchr(filename,' ')+1);
    strcat(left,right);
    strcpy(filename,left);
    for(i=0;i<strlen(filename);i++)
    {
        if(filename[i]>='a'&&filename[i]<='z')
            filename[i]-=32;
    }
}

void sort_in_file(char *filepath)     ///sort struct
{
    stdnt min, swap, next;
    int i,j,k;
    int n=file_len(filepath);
    int size=0;
    FILE *f;
    f=fopen(filepath,"rb+");
    for(i=0;i<n-size;i+=sizeof(min))
    {
        fseek(f,i,SEEK_SET);
        fread(&min,sizeof(min),1,f);
        k=i;
        for(j=i+sizeof(min);j<n;j+=size)
        {
            fread(&next,sizeof(next),1,f);
            size=sizeof(next);
            if(strcmp(min.name,next.name)==1)
            {min=next; k=j;}
        }
        fseek(f,i,SEEK_SET);
        fread(&swap,sizeof(swap),1,f);
        fseek(f,i,SEEK_SET);
        fwrite(&min,sizeof(min),1,f);
        fseek(f,k,SEEK_SET);
        fwrite(&swap,sizeof(swap),1,f);
    }
    fclose(f);
}

void rm_classes(char *mainpath, char *class_name)
{
    char cp1[15],cp2[20];
    char lp1[20],lp2[35];
    char c[10];
    strcpy(c,class_name);
    strcpy(cp1,mainpath);
    strcat(cp1,"/");
    strcat(cp1,c);
    strcpy(cp2,cp1);
    strcat(cp2,"/");
    strcat(c,".data");
    strcat(cp2,c);
    strcpy(lp1,cp1);
    strcat(lp1,"/lessons");
    strcpy(lp2,lp1);
    strcat(lp2,"/lessons.data");
    DeleteFile(lp2);
    RemoveDirectory(lp1);
    DeleteFile(cp2);
    RemoveDirectory(cp1);   ///RemoveDirectory doesn't work? huh?????
}

void del_data(char *path, int pos)           ///RemoveDirectory works on empty folders only
{
    stdnt cl;
    FILE *f;
    f=fopen(path,"rb+");
    fseek(f,0,SEEK_END);
    int size = ftell(f);
    if(pos!=size-sizeof(cl))
    {
        fseek(f,-sizeof(cl),SEEK_END);
        fread(&cl,sizeof(cl),1,f);
        fseek(f,pos,SEEK_SET);
        fwrite(&cl,sizeof(cl),1,f);
    }
    _chsize(fileno(f),size-sizeof(cl));
    //fseek(f,0,SEEK_END);
    //size = ftell(f);
    fclose(f);
    sort_in_file(path);
}

int check_class_data(char *mainpath, char *class_name)
{
    FILE *f;
    char path[50];
    char c[10];
    strcpy(c,class_name);
    strcpy(path,mainpath);
    strcat(path,"/");
    strcat(path,c);
    strcat(path,"/");
    strcat(c,".data");
    strcat(path,c);
    f=fopen(path,"rb+");
    if(f)
    {
        if(fread(&s,sizeof(s),1,f))
        {fclose(f); return 1;}
    }
    fclose(f);
    return 0;
}

void view_classes(char *mainpath)
{
    stdnt cl;
    FILE *classes;
    for(j=0;j>=0;j+=sizeof(cl))
    {
        classes=fopen("CLASSES/classes.data","rb");
        fseek(classes,j,SEEK_SET);
        if(fread(&cl,sizeof(cl),1,classes))
        {
            fclose(classes);
            if(!check_class_data(mainpath,cl.name))
            {
                    //printf("deleting %s\n", cl.name);
                del_data("CLASSES/classes.data",j);         ///remove the class from the list
                    //output("CLASSES/classes.data");
                rm_classes(mainpath,cl.name);
                j=0;
            }
        }
        else break;
    }
    fclose(classes);
}

void add_classes(char *class_name)
{
    stdnt cl;
    FILE *classes;
    classes=fopen("CLASSES/classes.data","ab+");
    strcpy(cl.name,class_name);
    fwrite(&cl,sizeof(cl),1,classes);
    fclose(classes);
    sort_in_file("CLASSES/classes.data");
        //output("CLASSES/classes.data");
}

void new_lessons(char *path_copy)
{
    int i=0;
    char predmet[lename];
    create_folder(path_copy,"lessons");
    create_file(path_copy,"lessons.data");
    FILE *f;
    do
    {
        f=fopen(path_copy,"rb+");
        if(f)
            printf("Lesson: ");
        fseek(f,i,SEEK_SET);
        gets(s.name);
        if(strcmp(s.name,"0")==0)
            break;
        fwrite(&s,sizeof(s),1,f);
        fclose(f);
        strcpy(predmet,s.name);
        i=repeat(path_copy,predmet);           ///проверка дали е повече от един
    }while(1);
    fclose(f);
    sort_in_file(path_copy);                          ///ако се повтаря, обръща наобратно
}

void new_student(char *filepath, char *lesson_ref)
{
    stdnt l;
    fflush(stdin);
    input_name(s.name);
    printf("Input mark 0 when the student don't learn the lesson\n");
    FILE *f;
    f=fopen(lesson_ref,"rb");
    for(i=0;!feof(f);i++)
    {
        if(fread(&l,sizeof(l),1,f))
        {
            do
            {
                printf("Mark %s: ",l.name);
                scanf("%d", &s.marks[i]);
            }while((s.marks[i]<2 || s.marks[i]>6) && s.marks[i]!=0);
        }
    }
    fclose(f);
    s.avr=average(s.marks,i-1);
    s.marks[i]=1;
    f=fopen(filepath,"ab");
    fwrite(&s,sizeof(s),1,f);
    fclose(f);
}

void new_classes(char *mainpath)
{
    char filepath[20];
    char filename[10];
    char lpath[40];
    strcpy(filepath,mainpath);
    printf("Class: ");
    gets(filename);
    filename_check(filename);
    if(!create_folder(filepath,filename))
    {printf("There is such a class\n"); new_classes(mainpath);}  /// провери дали съществува напр: 12б = 12 б = 12Б = 12 Б
    add_classes(filename);
    strcpy(lpath,filepath);
    strcat(filename,".data");
    create_file(filepath,filename);
    printf("Input 0 to stop the input of lessons\n");
    new_lessons(lpath);
    int stud;
    printf("How much students: ");
    scanf("%d", &stud);
    for(j=0;j<stud;j++)
        new_student(filepath,lpath);
    sort_in_file(filepath);
    enumer(filepath);
    printAll(filepath,lpath);
}

int hilight(int op, HANDLE console)
{
    FILE *f;
    f=fopen("CLASSES/classes.data","rb");
    i=1;
    for(j=0;1;j+=sizeof(s))
    {
        fseek(f,j,SEEK_SET);
        if(fread(&s,sizeof(s),1,f))
        {
            SetConsoleTextAttribute(console, 7);
            if(op==i)
                SetConsoleTextAttribute(console, 12);
            printf("\n  %s",s.name);
            SetConsoleTextAttribute(console, 7);
            i++;
        }
        else break;
    }
    fclose(f);
    return i-1;
}
void op_menu(char *mainpath)
{

}
void main_menu(char *mainpath)
{
    HANDLE console;
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    int op=1,num_classes;
    char arrow;
    do
    {
        printf(" Classes:");
        num_classes = hilight(op,console);
        if(op==num_classes+1)
            SetConsoleTextAttribute(console, 12);
        printf("\n New classes");
        SetConsoleTextAttribute(console, 7);
        if(op==num_classes+2)
            SetConsoleTextAttribute(console, 12);
        printf("\n Exit");
        SetConsoleTextAttribute(console, 7);
        arrow = getch();
        switch(arrow)
        {
            /// number of classes
            case 72: op--; if(op<=0) op=num_classes+2;break;  ///up arrow
            case 80: op++; if(op>num_classes+2) op=1;break;  ///down arrow
        }
        system("cls");
    }while(arrow!=13);
    op_menu(mainpath);
}

void main()
{
    HANDLE console;
    console = SetConsoleTitle("Electronic Markbook");
    char mainpath[10]="CLASSES";          ///important
    CreateDirectory(mainpath,NULL);        ///always
    FILE *classes;
    classes=fopen("CLASSES/classes.data","ab+");
    SetFileAttributes("CLASSES",FILE_ATTRIBUTE_HIDDEN);
    SetFileAttributes("CLASSES/classes.data",FILE_ATTRIBUTE_HIDDEN);
    fclose(classes);
    view_classes(mainpath);
        ///output("CLASSES/classes.data");
    /*new_classes(mainpath);
        output("CLASSES/classes.data");*/
    main_menu(mainpath);
}

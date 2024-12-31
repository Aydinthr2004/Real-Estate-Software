#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char admin[]={ 'A' , 'y' , 'd' , 'i' , 'n' , 't' , 'h' , 'r' , '\0'};
char admin_password[]={'a' , 'y' , 'd' , 'i' , 'n' , 'a' , 'y' , 'd' , 'i' , 'n' , '\0' };
char inputUser[50];
char inputpassword[100];
int counter_for_admin=0;
FILE *fpp2;
void admin_reports(void)
{
    system("cls");
    printf("welcome Aydin to Reports information Tab\n\n");
    printf("1. The number of properties in the system \n"); //tedad amlak mojod
    printf("2. List of properties available in a specific municipal area in the system \n"); //mantaqe shahrdari
    printf("3. List of properties available with a specific building age in the system \n"); //sen bana khas
    printf("4. List of properties available based on size of property in the system \n"); //barasaa metraj asli
    printf("5. List of properties available based on price of property in the system \n");
    printf("6. List of properties available based on number of rooms on property in the system \n");
    printf("7. List of total price of all properties registered in the system \n");
    printf("8. List of users who entered the property in order in the system\n");
    printf("9. List of Rent properties available based on mortgage and monthly price in the system \n");
    printf("10. List of properties registered in a certain time  in the system \n");
    printf("11. List of properties available in a specific floor in the system \n");
    printf("12. List of properties deleted in a certain time  in the system \n");
    printf("13. List of users along with the last visit time of the program in the system \n");
    printf("14. Back to main menu \n");

    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    char four[]= {'4' , '\0'};
    char five[]= {'5' , '\0'};
    char six[]= {'6' , '\0'};
    char seven[]= {'7' , '\0'};
    char eight[]= {'8' , '\0'};
    char nine[]= {'9' , '\0'};
    char ten[]={ '1' , '0' , '\0' };
    char eleven[]={ '1' , '1' , '\0' };
    char twelve[]={ '1' , '2' , '\0' };
    char thirteen[]={ '1' , '3' , '\0' };
    char fourteen[]={ '1' , '4' , '\0' };
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
            counter++;
        number_of_properties();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        specific_municipal_area();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        specific_building_age();
    }
    if( strcmp(choice , four) == 0){
        counter++;
        based_on_size();
    }
    if( strcmp(choice , five) == 0){
        counter++;
        based_on_price();
    }
    if( strcmp(choice , six) == 0){
        counter++;
        based_on_number_of_rooms();
    }
    if( strcmp(choice , seven) == 0){
        counter++;
        Total_price();
     }
     if( strcmp(choice , eight) == 0){
        counter++;
        order_users();
     }
    if( strcmp(choice , nine) == 0){
        counter++;
        mortgage_and_monthly_price();
    }
    if( strcmp(choice , ten) == 0){
        counter++;
        properties_certain_time();
    }
    if( strcmp(choice , eleven) == 0){
        counter++;
        specific_floor();
    }
    if( strcmp(choice , twelve) == 0){
        counter++;
        delete_properties_certain_time();
    }
    if( strcmp(choice , thirteen) == 0){
        counter++;
        all_users();
    }
     if( strcmp(choice , fourteen) == 0){
        counter++;
        admin_mainmenu();
     }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        admin_mainmenu();

    }





}
void all_users (void)
{
    system("cls");
    printf("welcome to List of users along with the last visit time of the program in the system \n\n");

    struct user{
        char user_name[50];
        char password[100];
        char password2[100];
        char name[50];
        char family_name[50];
        char user_code[20];
        char user_phone[20];
        char email[300];
        char year[10];
        char month[10];
        char day[10];
        struct user *link;
    };
    typedef struct user User;
    //p--->sare list q----->payane list
    User *p = NULL,*q=NULL;
    FILE *fp;
    fp = fopen("sign_up.txt","r");

    while(!feof(fp))
    {

    //Ejade gere jadid
    User *d;
    d = malloc(sizeof(User));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp,"%s\n",d->user_name);
    fscanf(fp,"%s\n",d->password);
    fscanf(fp,"%s\n",d->name);
    fscanf(fp,"%s\n",d->family_name);
    fscanf(fp,"%s\n",d->user_code);
    fscanf(fp,"%s\n",d->user_phone);
    fscanf(fp,"%s\n",d->email);
    fscanf(fp,"%s\n",d->year);
    fscanf(fp,"%s\n",d->month);
    fscanf(fp,"%s\n",d->day);


    printf("User name : %s\n",d->user_name);
    printf("Password : %s\n",d->password);
    printf("Name : %s\n",d->name);
    printf("Family Name : %s\n",d->family_name);
    printf("User Code : %s\n",d->user_code);
    printf("Phone Number : %s\n",d->user_phone);
    printf("Email : %s\n",d->email);
    printf("Year : %s\n",d->year);
    printf("month : %s\n",d->month);
    printf("day : %s\n",d->day);
    printf("\n\n");


    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp);
    free(p);





    printf("\n\nPress any key to back main menu");
    getche();
    admin_mainmenu();





}
int counter_rent_land11 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char two[]= {'2' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,two) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Land for rent in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);








}
int counter_rent_Office_property11 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char two[]= {'2' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,two) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property for rent in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);










}
int counter_rent_Residential_property11 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char two[]= {'2' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,two) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of property for rent in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);









}
int counter_land11 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char two[]= {'2' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,two) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Land sales in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);








}
int counter_Office_property11 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char two[]= {'2' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,two) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property sales in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);









}
int counter_Residential_property11 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char two[]= {'2' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,two) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);







}
void delete_properties_certain_time (void)
{
    system("cls");
    printf("welcome to List of properties deleted in a certain time informations Tab\n\n");




    int min_yaer , min_month , min_day , max_yaer , max_month , max_day ;
    printf("\nPlease enter the desired minimum period, we start from the year : ");
    scanf("%d", &min_yaer);
    printf("\nPlease enter the minimum month : ");
    scanf("%d", &min_month);
    printf("\nPlease enter the minimum day : ");
    scanf("%d", &min_day);
    printf("\nPlease enter the desired maximum period, we start from the year : ");
    scanf("%d", &max_yaer);
    printf("\nPlease enter the maximum month : ");
    scanf("%d", &max_month);
    printf("\nPlease enter the maximum day : ");
    scanf("%d", &max_day);

    printf("\n\n");

    int counter1 =  counter_Residential_property11(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of deleted properties for sale in this period is equal to : %d ", counter1);
    int counter2 =  counter_Office_property11(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of deleted office properties for sale in this period is equal to : %d ", counter2);
    int counter3 =  counter_land11(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of deleted Lands for sale in this period is equal to : %d ", counter3);
    int counter4 =  counter_rent_Residential_property11(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of deleted properties for rent in this period is equal to : %d ", counter4);
    int counter5 =  counter_rent_Office_property11(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of deleted office properties for rent in this period is equal to : %d ", counter5);
    int counter6 =  counter_rent_land11(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of deleted Lands for rent in this period is equal to : %d ", counter6);
    int result;
    result = counter1 + counter2 + counter3 + counter4 + counter5 + counter6;
    printf("\n\n\nAll properties in this this period of time that deleted are equal to : %d ", result);


    printf("\n\nPress any key to back main menu");
    getche();
    admin_mainmenu();





}
int counter_rent_land10 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Land for rent in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);








}
int counter_rent_Office_property10 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property for rent in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);










}
int counter_rent_Residential_property10 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of property for rent in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);









}
int counter_land10 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Land sales in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);








}
int counter_Office_property10 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property sales in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);









}
int counter_Residential_property10 ( int min_yaer , int min_month , int min_day , int max_yaer , int max_month , int max_day )
{
    int counter1=0;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;
    int temp11;
    int temp12;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->year);
        temp2 = atoi(d->month);
        temp3 = atoi(d->day);
        temp7 = temp1*365;
        temp8 = temp2*30;
        temp4 = temp7 + temp8 + temp3;
        temp9 = min_yaer*365;
        temp10 = min_month*30;
        temp5 = temp9 + temp10 + min_day;
        temp11 = max_yaer*365;
        temp12 = max_month*30;
        temp6 = temp11 + temp12 + max_day;
        if( (temp4 >= temp5) && (temp4 <= temp6) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales in this period of time : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);









}
void properties_certain_time(void)
{
    system("cls");
    printf("welcome to List of properties registered in a certain time informations Tab\n\n");




    int min_yaer , min_month , min_day , max_yaer , max_month , max_day ;
    printf("\nPlease enter the desired minimum period, we start from the year : ");
    scanf("%d", &min_yaer);
    printf("\nPlease enter the minimum month : ");
    scanf("%d", &min_month);
    printf("\nPlease enter the minimum day : ");
    scanf("%d", &min_day);
    printf("\nPlease enter the desired maximum period, we start from the year : ");
    scanf("%d", &max_yaer);
    printf("\nPlease enter the maximum month : ");
    scanf("%d", &max_month);
    printf("\nPlease enter the maximum day : ");
    scanf("%d", &max_day);

    printf("\n\n");

    int counter1 =  counter_Residential_property10(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of registered properties for sale in this period is equal to : %d ", counter1);
    int counter2 =  counter_Office_property10(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of registered office properties for sale in this period is equal to : %d ", counter2);
    int counter3 =  counter_land10(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of registered Lands for sale in this period is equal to : %d ", counter3);
    int counter4 =  counter_rent_Residential_property10(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of registered properties for rent in this period is equal to : %d ", counter4);
    int counter5 =  counter_rent_Office_property10(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of registered office properties for rent in this period is equal to : %d ", counter5);
    int counter6 =  counter_rent_land10(min_yaer , min_month , min_day , max_yaer , max_month , max_day);
    printf("\nThe list of registered Lands for rent in this period is equal to : %d ", counter6);
    int result;
    result = counter1 + counter2 + counter3 + counter4 + counter5 + counter6;
    printf("\n\n\nAll properties in this this period of time are equal to : %d ", result);


    printf("\n\nPress any key to back main menu");
    getche();
    admin_mainmenu();




}
void order_users ( void )
{
    system("cls");
    printf("welcome to List of users who entered the property in order in the system \n\n");

    fpp2 = fopen("counter_user_for_admin.txt","r");
    int ch;

    while(ch != EOF)
    {
        ch = fgetc(fpp2);
        putchar(ch);
    }
    //bastane file
    fclose(fpp2);





    printf("\n\nPress any key to back main menu");
    getche();
    admin_mainmenu();

}
int counter_Residential_property9(void)
{
    int result=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->price);
        result=temp+result;

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(result);







}
int counter_Office_property9(void)
{
    int result=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->price);
        result=temp+result;

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(result);




}
int counter_land9(void)
{
    int result=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->price);
        result=temp+result;

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(result);





}
void Total_price(void)
{
    system("cls");
    printf("welcome to List of total price of all properties registered in the system \n\n");


    printf("\n\n");

    int counter1 =  counter_Residential_property9();
    printf("\nThe total price of properties for sale is equal to : %d Mil Toman", counter1);
    int counter2 =  counter_Office_property9();
    printf("\nThe total price of office properties for sale is equal to : %d Mil Toman", counter2);
    int counter3 =  counter_land9();
    printf("\nThe total price of Lands for sale is equal to : %d Mil Toman", counter3);
    int result;
    result = counter1 + counter2 + counter3;
    printf("\n\n\nAll properties total price is equal to : %d Mil Toman", result);

    printf("\n\nPress any key to back main menu");
    getche();
    admin_mainmenu();

}
void admin_mainmenu( void )
{
    system("cls");
    printf("welcome Admin Aydin :) \n\n");
    printf("1. Add new information \n");
    printf("2. Delete information \n");
    printf("3. Reports \n");
    printf("4. Account settings \n");
    printf("5. log out \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    char four[]= {'4' , '\0'};
    char five[]= {'5' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        new_information();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        delete_information();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        admin_reports();
    }
    if( strcmp(choice , four) == 0){
        counter++;
        settings();
    }
    if( strcmp(choice , five) == 0){
        counter++;
        welcome();
    }
    if( counter == 0)
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        admin_mainmenu();
    }








}
int counter_rent_Office_property8 ( int floor_counter )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->floor);
        if( temp == floor_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property for rent that have this specific floor is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);








}
int counter_rent_Residential_property8( int floor_counter )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->floor);
        if( temp == floor_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property for rent that have this specific floor is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);







}
int counter_Office_property8 ( int floor_counter )
{
     int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->floor);
        if( temp == floor_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information from The number of office properties for sale that have this specific floor is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);







}
int counter_Residential_property8 ( int floor_counter )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->floor);
        if( temp == floor_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information from The number of properties for sale that have in this specific floor is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);


    return(counter1);





}
void specific_floor(void)
{
    system("cls");
    printf("welcome to List of properties available based on specific floor from property Tab\n\n");
    int floor_counter;
    printf("\nEnter the desired specific floor in your property : ");
    scanf("%d", &floor_counter);

    printf("\n\n");

    int counter1 =  counter_Residential_property8( floor_counter );
    printf("\nThe number of properties for sale that have in this specific floor is equal to : %d ", counter1);
    int counter2 =  counter_Office_property8( floor_counter );
    printf("\nThe number of office property for sale that have this specific floor is equal to : %d ", counter2);
    int counter3 = counter_rent_Residential_property8( floor_counter );
    printf("\n\nThe number of Residential property for rent that have this specific floor is equal to : %d ", counter3);
    int counter4 = counter_rent_Office_property8( floor_counter );
    printf("\nThe number of office property for rent that have this specific floor is equal to : %d ", counter4);
    int result;
    result = counter1 + counter2 + counter3 + counter4;
    printf("\n\n\nAll properties that have this specific floor is equal to : %d ", result);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();



}
int counter_rent_land7 ( int min_mortgage , int max_mortgage , int min_monthly , int max_monthly )
{
    int counter1=0;
    int temp1;
    int temp2;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->mortgage_price);
        temp2 = atoi(d->monthly_price);
        if( (temp1>=min_mortgage) && (temp1<=max_mortgage) && (temp2>=min_monthly) && (temp2<=max_monthly) )
            {
            counter1++;
            printf("\n\nwe have this %dth information of Land for rent in this mortgage and monthly price range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);






}
int counter_rent_Office_property7( int min_mortgage , int max_mortgage , int min_monthly , int max_monthly )
{
    int counter1=0;
    int temp1;
    int temp2;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->mortgage_price);
        temp2 = atoi(d->monthly_price);
        if( (temp1>=min_mortgage) && (temp1<=max_mortgage) && (temp2>=min_monthly) && (temp2<=max_monthly) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property for rent that have this mortgage and monthly price range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);








}
int counter_rent_Residential_property7( int min_mortgage , int max_mortgage , int min_monthly , int max_monthly  )
{
    int counter1=0;
    int temp1;
    int temp2;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp1 = atoi(d->mortgage_price);
        temp2 = atoi(d->monthly_price);
        if( (temp1>=min_mortgage) && (temp1<=max_mortgage) && (temp2>=min_monthly) && (temp2<=max_monthly) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property for rent that have this mortgage and monthly price range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);


}
void mortgage_and_monthly_price(void)
{
    system("cls");
    printf("welcome to List of properties available based on mortgage and monthly price informations Tab\n\n");
    int min_counter_mortgage_price , max_counter_mortgage_price , min_counter_monthly_price , max_counter_monthly_price ;
    printf("\nplease Enter your min mortgage price of property for rent (based on Million TOMAN) : ");
    scanf("%d", &min_counter_mortgage_price);
    printf("\n\nplease Enter your max mortgage price of property for rent (based on Million TOMAN) : ");
    scanf("%d", &max_counter_mortgage_price);
    printf("\nplease Enter your min monthly price of property for rent (based on Million TOMAN) : ");
    scanf("%d", &min_counter_monthly_price);
    printf("\n\nplease Enter your max monthly price of property for rent (based on Million TOMAN) : ");
    scanf("%d", &max_counter_monthly_price);

    printf("\n\n");

    int counter1 =  counter_rent_Residential_property7(min_counter_mortgage_price , max_counter_mortgage_price , min_counter_monthly_price , max_counter_monthly_price);
    printf("\nThe number of Residential property for rent in this price range is equal to : %d ", counter1);
    int counter2 =  counter_rent_Office_property7(min_counter_mortgage_price , max_counter_mortgage_price , min_counter_monthly_price , max_counter_monthly_price);
    printf("\nThe number of office property for rent in this price range is equal to : %d ", counter2);
    int counter3 =  counter_rent_land7(min_counter_mortgage_price , max_counter_mortgage_price , min_counter_monthly_price , max_counter_monthly_price);
    printf("\nThe number of Lands for rent in this price range is equal to : %d ", counter3);
    int result;
    result = counter1 + counter2 + counter3;
    printf("\n\n\nAll properties in this mortgage and monthly price for rent are equal to : %d ", result);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();


}
int counter_rent_Office_property6( int rooms_counter )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->rooms);
        if( temp == rooms_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property for rent that have this number of rooms is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);







}
int counter_rent_Residential_property6(  int rooms_counter )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->rooms);
        if( temp == rooms_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property for rent that have this number of rooms is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);








}
int counter_Office_property6 ( int rooms_counter )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
         temp = atoi(d->rooms);
        if( temp == rooms_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information from The number of office properties for sale that have this number of rooms : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);





}
int counter_Residential_property6 ( int rooms_counter )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->rooms);
        if( temp == rooms_counter )
        {
            counter1++;
            printf("\n\nwe have this %dth information from The number of properties for sale that have this number of rooms : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);


    return(counter1);






}
void based_on_number_of_rooms(void)
{
    system("cls");
    printf("welcome to List of properties available based on number of rooms on property Tab\n\n");
    int rooms_counter;
    printf("\nEnter the desired number of rooms in your property : ");
    scanf("%d", &rooms_counter);

    printf("\n\n");

    int counter1 =  counter_Residential_property6( rooms_counter );
    printf("\nThe number of properties for sale that have this number of rooms is equal to : %d ", counter1);
    int counter2 =  counter_Office_property6( rooms_counter );
    printf("\nThe number of office property for sale that have this number of rooms is equal to : %d ", counter2);
    int counter3 = counter_rent_Residential_property6( rooms_counter );
    printf("\n\nThe number of Residential property for rent that have this number of rooms is equal to : %d ", counter3);
    int counter4 = counter_rent_Office_property6( rooms_counter );
    printf("\nThe number of office property for rent that have this number of rooms is equal to : %d ", counter4);
    int result;
    result = counter1 + counter2 + counter3 + counter4;
    printf("\n\n\nAll properties that have this number of rooms is equal to : %d ", result);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();




}
int counter_land5( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->price);
        if( (temp >= min) && (temp <= max) )
            {
            counter1++;
            printf("\n\nwe have this %dth information of Land sales in this price range (based on Million TOMAN) : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);





}
int counter_Office_property5 ( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->price);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property sales in this price range is (based on Million TOMAN) : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);





}
int counter_Residential_property5( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->price);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales in this price range is (based on Million TOMAN) : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);





}
void based_on_price(void)
{
    system("cls");
    printf("welcome to List of properties available based on price of property Tab\n\n");
    int min_counter_price,max_counter_price;
    printf("\nplease Enter your min price of property (based on Million TOMAN) : ");
    scanf("%d", &min_counter_price);
    printf("\n\nplease Enter your max price of property (based on Million TOMAN) : ");
    scanf("%d", &max_counter_price);

    printf("\n\n");

    int counter1 =  counter_Residential_property5( min_counter_price , max_counter_price );
    printf("\nThe number of Residential property sales in this price range is equal to : %d ", counter1);
    int counter2 = counter_Office_property5(min_counter_price , max_counter_price );
    printf("\nThe number of office property sales in this price range is equal to : %d ", counter2);
    int counter3 = counter_land5( min_counter_price , max_counter_price );
    printf("\nThe number of Land sales in this price range is equal to : %d ", counter3);
    int result;
    result = counter1 + counter2 + counter3;
    printf("\n\n\nAll properties in this municipal area are equal to : %d ", result);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();




}
int counter_rent_land4 ( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->size);
        if( (temp >= min) && (temp <= max) )
            {
            counter1++;
            printf("\n\nwe have this %dth information of Land for rent in this size range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);


    return(counter1);




}
int counter_rent_Office_property4( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->size);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of office property for rent in this size range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);





}
int counter_rent_Residential_property4( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->size);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property for rent in this size range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);





}
int counter_land4 ( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->size);
        if( (temp >= min) && (temp <= max) )
            {
            counter1++;
            printf("\n\nwe have this %dth information of Land sales in this size range : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);



}
int counter_Office_property4 ( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->size);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales in this age range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);




}
int counter_Residential_property4( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->size);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales in this age range is : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);



}
void based_on_size(void)
{
    system("cls");
    printf("welcome to List of properties available based on size of property Tab\n\n");
    int min_counter_size,max_counter_size;
    printf("\nplease Enter your min size of property : ");
    scanf("%d", &min_counter_size);
    printf("\n\nplease Enter your max size of property : ");
    scanf("%d", &max_counter_size);

    printf("\n\n");

    int counter1 =  counter_Residential_property4( min_counter_size , max_counter_size );
    printf("\nThe number of Residential property sales in this size range is equal to : %d ", counter1);
    int counter2 = counter_Office_property4( min_counter_size , max_counter_size );
    printf("\nThe number of office property sales in this size range is equal to : %d ", counter2);
    int counter3 = counter_land4( min_counter_size , max_counter_size );
    printf("\nThe number of Land sales in this size range is equal to : %d ", counter3);
    int counter4 = counter_rent_Residential_property4( min_counter_size , max_counter_size );
    printf("\n\nThe number of Residential property for rent in this size range is equal to : %d ", counter4);
    int counter5 = counter_rent_Office_property4( min_counter_size , max_counter_size );
    printf("\nThe number of office property for rent in this size range is equal to : %d ", counter5);
    int counter6 = counter_rent_land4( min_counter_size , max_counter_size );
    printf("\nThe number of Land for rent in this size range is equal to : %d ", counter6);
    int result;
    result = counter1 + counter2 + counter3 + counter4 + counter5 + counter6;
    printf("\n\n\nAll properties in this municipal area are equal to : %d ", result);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();




}
int counter_rent_Office_property3( int min , int max )
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->age);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);



}
int counter_rent_Residential_property3(int min , int max)
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->age);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);
    return(counter1);




}
int counter_Office_property3(int min , int max)
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->age);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);
    return(counter1);



}
int counter_Residential_property3(int min , int max)
{
    int counter1=0;
    int temp;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);




    if( strcmp(d->active,one) == 0 )
    {
        temp = atoi(d->age);
        if( (temp >= min) && (temp <= max) )
        {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
        }

    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);
    return(counter1);


}
void specific_building_age(void)
{
    system("cls");
    printf("welcome to specific building age information Tab\n\n");
    int min_counter_age,max_counter_age;
    printf("\nplease Enter your min age of property : ");
    scanf("%d", &min_counter_age);
    printf("\n\nplease Enter your max age of property : ");
    scanf("%d", &max_counter_age);

    printf("\n\n");

    int counter1 =  counter_Residential_property3( min_counter_age , max_counter_age );
    printf("\nThe number of Residential property sales in this age range is equal to : %d ", counter1);
    int counter2 = counter_Office_property3( min_counter_age , max_counter_age );
    printf("\nThe number of office property sales in this age range is equal to : %d ", counter2);
    int counter3 = counter_rent_Residential_property3( min_counter_age , max_counter_age );
    printf("\n\nThe number of Residential property for rent in this age range is equal to : %d ", counter3);
    int counter4 = counter_rent_Office_property3( min_counter_age , max_counter_age );
    printf("\nThe number of office property for rent in this age range is equal to : %d ", counter4);
    int result;
    result = counter1 + counter2 + counter3 + counter4 ;
    printf("\n\n\nAll properties in this age range are equal to : %d ", result);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
}
int counter_rent_land2(char counter_area[50])
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        if( strcmp(d->area,counter_area) == 0 )
            {
            counter1++;
            printf("\n\nwe have this %dth information of Land for rent : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);


    return(counter1);



}
int counter_rent_Office_property2(char counter_area[50])
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        if( strcmp(d->area,counter_area) == 0 )
           {
            counter1++;
            printf("\n\nwe have this %dth information of office property for rent : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);


}
int counter_rent_Residential_property2(char counter_area[50])
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        if( strcmp(d->area,counter_area) == 0 )
            {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property for rent : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("mortgage price : %s\n",d->mortgage_price);
            printf("monthly price : %s\n",d->monthly_price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);

}
int counter_land2(char counter_area[50])
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        if( strcmp(d->area,counter_area) == 0 )
            {
            counter1++;
            printf("\n\nwe have this %dth information of Land sales : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("size : %s\n",d->size);
            printf("phone : %s\n",d->phone);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);

}
int counter_Office_property2(char counter_area[50])
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        if( strcmp(d->area,counter_area) == 0 )
            {
            counter1++;
            printf("\n\nwe have this %dth information of office property sales : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);



}
int counter_Residential_property2(char counter_area[50])
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
    {
        if( strcmp(d->area,counter_area) == 0 )
         {
            counter1++;
            printf("\n\nwe have this %dth information of Residential property sales : \n", counter1);
            printf("area : %s\n",d->area);
            printf("address : %s\n",d->address);
            printf("type : %s\n",d->type);
            printf("age : %s\n",d->age);
            printf("size : %s\n",d->size);
            printf("floor : %s\n",d->floor);
            printf("orig size : %s\n",d->orig_size);
            printf("phone : %s\n",d->phone);
            printf("rooms : %s\n",d->rooms);
            printf("price : %s\n",d->price);
            printf("year : %s\n",d->year);
            printf("month : %s\n",d->month);
            printf("day : %s\n",d->day);
            printf("code : %s\n",d->random);
            printf("\n");
         }
    }
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);

}
void specific_municipal_area(void)
{
    system("cls");
    printf("welcome to specific municipal area information Tab\n\n");
    char counter_area[50];
    printf("\nEnter your desired municipal area : ");
    fflush(stdin);
    gets(counter_area);
    int length = strlen (counter_area);
    for (int i=0 ; i<length ; i++)
    {
        if (counter_area[i] == ' ' )
        {
            counter_area[i] = '-';
        }
    }
    printf("\n\n");
    int counter1 = counter_Residential_property2(counter_area);
    printf("\nThe number of Residential property sales in this specific municipal area is equal to : %d ", counter1);
    int counter2 = counter_Office_property2(counter_area);
    printf("\nThe number of office property sales in this specific municipal area is equal to : %d ", counter2);
    int counter3 = counter_land2(counter_area);
    printf("\nThe number of Land sales in this specific municipal area is equal to : %d ", counter3);
    int counter4 = counter_rent_Residential_property2(counter_area);
    printf("\n\nThe number of Residential property for rent in this specific municipal area is equal to : %d ", counter4);
    int counter5 = counter_rent_Office_property2(counter_area);
    printf("\nThe number of office property for rent in this specific municipal area is equal to : %d ", counter5);
    int counter6 = counter_rent_land2(counter_area);
    printf("\nThe number of Land for rent in this specific municipal is equal to : %d ", counter6);
    int result;
    result = counter1 + counter2 + counter3 + counter4 + counter5 + counter6;
    printf("\n\n\nAll properties in this municipal area are equal to : %d ", result);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
}
int counter_rent_land(void)
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
        counter1++;
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);


    return(counter1);



}
int counter_rent_Office_property(void)
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
        counter1++;
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);


}
int counter_rent_Residential_property(void)
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
        counter1++;
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);

}
int counter_land(void)
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
        counter1++;
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);

}
int counter_Office_property(void)
{
    int counter1=0;
    char one[]= {'1' , '\0'};
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
        counter1++;
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);

    return(counter1);



}
void number_of_properties(void)
{
    system("cls");
    printf("welcome to Reports information Tab\n\n");



    int counter1=0;
    char one[]= {'1' , '\0'};




    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    if( strcmp(d->active,one) == 0 )
        counter1++;
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp2);
    free(p);
    printf("\nThe number of property sales is equal to : %d ", counter1);
    int counter2 = counter_Office_property();
    printf("\nThe number of office property sales is equal to : %d ", counter2);
    int counter3 = counter_land();
    printf("\nThe number of Land sales is equal to : %d ", counter3);
    int counter4 = counter_rent_Residential_property();
    printf("\n\nThe number of property for rent is equal to : %d ", counter4);
    int counter5 = counter_rent_Office_property();
    printf("\nThe number of office property for rent is equal to : %d ", counter5);
    int counter6 = counter_rent_land();
    printf("\nThe number of Land for rent is equal to : %d ", counter6);
    printf("\n\nPress any key to back main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();



}
void reports(void)
{
    system("cls");
    printf("welcome to Reports information Tab\n\n");
    printf("1. The number of properties in the system \n"); //tedad amlak mojod
    printf("2. List of properties available in a specific municipal area in the system \n"); //mantaqe shahrdari
    printf("3. List of properties available with a specific building age in the system \n"); //sen bana khas
    printf("4. List of properties available based on size of property in the system \n"); //barasaa metraj asli
    printf("5. List of properties available based on price of property in the system \n");
    printf("6. List of properties available based on number of rooms on property in the system \n");
    printf("7. List of Rent properties available based on mortgage and monthly price in the system \n");
    printf("8. List of properties available in a specific floor in the system \n");
    printf("9. Back to main menu \n");

    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    char four[]= {'4' , '\0'};
    char five[]= {'5' , '\0'};
    char six[]= {'6' , '\0'};
    char seven[]= {'7' , '\0'};
    char eight[]= {'8' , '\0'};
    char nine[]={'9' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
            counter++;
        number_of_properties();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        specific_municipal_area();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        specific_building_age();
    }
    if( strcmp(choice , four) == 0){
        counter++;
        based_on_size();
    }
    if( strcmp(choice , five) == 0){
        counter++;
        based_on_price();
    }
    if( strcmp(choice , six) == 0){
        counter++;
        based_on_number_of_rooms();
    }
    if( strcmp(choice , seven) == 0){
        counter++;
        mortgage_and_monthly_price();
    }
    if( strcmp(choice , eight) == 0){
        counter++;
        specific_floor();
    }
     if( strcmp(choice , nine) == 0){
        counter++;
        mainmenu();
     }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        mainmenu();

    }



}
void delete_rent_land(void)
{
    system("cls");
    printf("welcome to Delete Land information\n\n");
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp2);

    char land_code[10] , deactive[10] ,edit_year[10] , edit_month[10] , edit_day[10]; //code melk maskoni mored nazar
    printf("\nNow time to Enter your Land code and next press Enter : ");
    scanf("%s" , &land_code);
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};

    //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

    while(d!=NULL)
    {
    if ( strcmp(land_code,d->random) == 0 ){
        if( strcmp(d->active,one) == 0 ){


     printf("\nNow time to delete your Residential property information if you sure Enter (2) : ");
     scanf("%s", &deactive);
     if ( strcmp(deactive , two) == 0 )
     strcpy(d->active,deactive);
     else
     {
    printf("\n\nyou aren't press '2' !!!!! please try it again because your property was not delete ");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    printf("\nNow time to save the date when you deleted your information if you like take it back tell its to admin : ");
    printf("\nWe start with year : ");
    scanf("%s", &edit_year);
    printf("\nPlease Enter month : ");
    scanf("%s", &edit_month);
    printf("\nPlease Enter day : ");
    scanf("%s", &edit_day);
    if( (atoi(edit_year) >= atoi(d->year) ) && (atoi(edit_month) >= atoi(d->month) ) && (atoi(edit_day) >= atoi(d->day) ) ){
    strcpy(d->year,edit_year);
    strcpy(d->month,edit_month);
    strcpy(d->day,edit_day);
    }
    else
    {
       printf("\n\nyour date input is wrong because you aren't input today date please try it again because your property was not delete ");
        printf("\npress any key to back main menu screen");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();


    }


     c++;
    }
    }

    //raftan be liste ba'di
    d = d->link;
    }
    if(c==0)
    {
    printf("\n\nthe property is not founded please try again");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    if(c>0)
    {
    fp2 = fopen("ejare_zamin.txt","w");
        //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;

    while(d!=NULL)
    {
    fprintf(fp2,"%s\n",d->area);
    fprintf(fp2,"%s\n",d->address);
    fprintf(fp2,"%s\n",d->type);
    fprintf(fp2,"%s\n",d->size);
    fprintf(fp2,"%s\n",d->phone);
    fprintf(fp2,"%s\n",d->mortgage_price);
    fprintf(fp2,"%s\n",d->monthly_price);
    fprintf(fp2,"%s\n",d->year);
    fprintf(fp2,"%s\n",d->month);
    fprintf(fp2,"%s\n",d->day);
    fprintf(fp2,"%s\n",d->random);
    fprintf(fp2,"%s\n",d->active);
    p=d;
    free(p);
    d = d->link;

    }
    fclose(fp2);
    printf("\n\n\nyou are successful press any key to go main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();






    }





}
void delete_rent_Office_property(void)
{
    system("cls");
    printf("welcome to Delete Office property information\n\n");
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp2);

    char Office_property_code[10] , deactive[10] ,edit_year[10] , edit_month[10] , edit_day[10]; //code melk maskoni mored nazar
    printf("\nNow time to Enter your Office property code and next press Enter : ");
    scanf("%s" , &Office_property_code);
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};


    //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

     while(d!=NULL)
    {
    if ( strcmp(Office_property_code,d->random) == 0 ){
        if( strcmp(d->active,one) == 0 ){


     printf("\nNow time to delete your Residential property information if you sure Enter (2) : ");
     scanf("%s", &deactive);
     if ( strcmp(deactive , two) == 0 )
     strcpy(d->active,deactive);
     else
     {
    printf("\n\nyou aren't press '2' !!!!! please try it again because your property was not delete ");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    printf("\nNow time to save the date when you deleted your information if you like take it back tell its to admin : ");
    printf("\nWe start with year : ");
    scanf("%s", &edit_year);
    printf("\nPlease Enter month : ");
    scanf("%s", &edit_month);
    printf("\nPlease Enter day : ");
    scanf("%s", &edit_day);
    if( (atoi(edit_year) >= atoi(d->year) ) && (atoi(edit_month) >= atoi(d->month) ) && (atoi(edit_day) >= atoi(d->day) ) ){
    strcpy(d->year,edit_year);
    strcpy(d->month,edit_month);
    strcpy(d->day,edit_day);
    }
    else
    {
       printf("\n\nyour date input is wrong because you aren't input today date please try it again because your property was not delete ");
        printf("\npress any key to back main menu screen");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();


    }


     c++;
    }
    }

    //raftan be liste ba'di
    d = d->link;
    }
    if(c==0)
    {
    printf("\n\nthe property is not founded please try again");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    if(c>0)
    {
    fp2 = fopen("ejare_melk_edari.txt","w");
        //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;

    while(d!=NULL)
    {
    fprintf(fp2,"%s\n",d->area);
    fprintf(fp2,"%s\n",d->address);
    fprintf(fp2,"%s\n",d->type);
    fprintf(fp2,"%s\n",d->age);
    fprintf(fp2,"%s\n",d->size);
    fprintf(fp2,"%s\n",d->floor);
    fprintf(fp2,"%s\n",d->orig_size);
    fprintf(fp2,"%s\n",d->phone);
    fprintf(fp2,"%s\n",d->rooms);
    fprintf(fp2,"%s\n",d->mortgage_price);
    fprintf(fp2,"%s\n",d->monthly_price);
    fprintf(fp2,"%s\n",d->year);
    fprintf(fp2,"%s\n",d->month);
    fprintf(fp2,"%s\n",d->day);
    fprintf(fp2,"%s\n",d->random);
    fprintf(fp2,"%s\n",d->active);
    p=d;
    free(p);
    d = d->link;

    }
    fclose(fp2);
    printf("\n\n\nyou are successful press any key to go main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();






    }
}
void delete_rent_Residential_property(void)
{
    system("cls");
    printf("welcome to Delete Residential property information\n\n");
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("ejare_melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->mortgage_price);
    fscanf(fp2,"%s\n",d->monthly_price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp2);

    char Residential_property_code[10] , deactive[10] ,edit_year[10] , edit_month[10] , edit_day[10]; //code melk maskoni mored nazar
    printf("\nNow time to Enter your Residential property code and next press Enter : ");
    scanf("%s" , &Residential_property_code);
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};



    //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

    while(d!=NULL)
    {
    if ( strcmp(Residential_property_code,d->random) == 0 ){
        if( strcmp(d->active,one) == 0 ){


     printf("\nNow time to delete your Residential property information if you sure Enter (2) : ");
     scanf("%s", &deactive);
     if ( strcmp(deactive , two) == 0 )
     strcpy(d->active,deactive);
     else
     {
    printf("\n\nyou aren't press '2' !!!!! please try it again because your property was not delete ");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    printf("\nNow time to save the date when you deleted your information if you like take it back tell its to admin : ");
    printf("\nWe start with year : ");
    scanf("%s", &edit_year);
    printf("\nPlease Enter month : ");
    scanf("%s", &edit_month);
    printf("\nPlease Enter day : ");
    scanf("%s", &edit_day);
    if( (atoi(edit_year) >= atoi(d->year) ) && (atoi(edit_month) >= atoi(d->month) ) && (atoi(edit_day) >= atoi(d->day) ) ){
    strcpy(d->year,edit_year);
    strcpy(d->month,edit_month);
    strcpy(d->day,edit_day);
    }
    else
    {
       printf("\n\nyour date input is wrong because you aren't input today date please try it again because your property was not delete ");
        printf("\npress any key to back main menu screen");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();


    }


     c++;
    }
    }

    //raftan be liste ba'di
    d = d->link;
    }
    if(c==0)
    {
    printf("\n\nthe property is not founded please try again");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    if(c>0)
    {
    fp2 = fopen("ejare_melk_maskoni.txt","w");
        //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;

    while(d!=NULL)
    {
    fprintf(fp2,"%s\n",d->area);
    fprintf(fp2,"%s\n",d->address);
    fprintf(fp2,"%s\n",d->type);
    fprintf(fp2,"%s\n",d->age);
    fprintf(fp2,"%s\n",d->size);
    fprintf(fp2,"%s\n",d->floor);
    fprintf(fp2,"%s\n",d->orig_size);
    fprintf(fp2,"%s\n",d->phone);
    fprintf(fp2,"%s\n",d->rooms);
    fprintf(fp2,"%s\n",d->mortgage_price);
    fprintf(fp2,"%s\n",d->monthly_price);
    fprintf(fp2,"%s\n",d->year);
    fprintf(fp2,"%s\n",d->month);
    fprintf(fp2,"%s\n",d->day);
    fprintf(fp2,"%s\n",d->random);
    fprintf(fp2,"%s\n",d->active);
    p=d;
    free(p);
    d = d->link;
    }
    fclose(fp2);
    printf("\n\n\nyou are successful press any key to go main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();






    }

}
void delete_rent(void)
{
    system("cls");
    printf("welcome to Delete rent information Tab\n\n");
    printf("1. Delete Rent of Residential property information \n"); //melk maskoni
    printf("2. Delete Rent of Office property information \n"); //melk edari
    printf("3. Delete Rent of Land information \n"); //zamin
    printf("4. Back to delete information Tab \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    char four[]= {'4' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        delete_rent_Residential_property();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        delete_rent_Office_property();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        delete_rent_land();
    }
    if( strcmp(choice , four) == 0){
        counter++;
        delete_information();
    }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        delete_sale();

    }



}
void delete_land(void)
{
    system("cls");
    printf("welcome to Delete Land information\n\n");
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("zamin.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp2);

    char land_code[10] , deactive[10] ,edit_year[10] , edit_month[10] , edit_day[10]; //code melk maskoni mored nazar
    printf("\nNow time to Enter your Land code and next press Enter : ");
    scanf("%s" , &land_code);
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};


    //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

    while(d!=NULL)
    {
    if ( strcmp(land_code,d->random) == 0 ){
        if( strcmp(d->active,one) == 0 ){


     printf("\nNow time to delete your Residential property information if you sure Enter (2) : ");
     scanf("%s", &deactive);
     if ( strcmp(deactive , two) == 0 )
     strcpy(d->active,deactive);
     else
     {
    printf("\n\nyou aren't press '2' !!!!! please try it again because your property was not delete ");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    printf("\nNow time to save the date when you deleted your information if you like take it back tell its to admin : ");
    printf("\nWe start with year : ");
    scanf("%s", &edit_year);
    printf("\nPlease Enter month : ");
    scanf("%s", &edit_month);
    printf("\nPlease Enter day : ");
    scanf("%s", &edit_day);
    if( (atoi(edit_year) >= atoi(d->year) ) && (atoi(edit_month) >= atoi(d->month) ) && (atoi(edit_day) >= atoi(d->day) ) ){
    strcpy(d->year,edit_year);
    strcpy(d->month,edit_month);
    strcpy(d->day,edit_day);
    }
    else
    {
       printf("\n\nyour date input is wrong because you aren't input today date please try it again because your property was not delete ");
        printf("\npress any key to back main menu screen");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();


    }


     c++;
    }
    }

    //raftan be liste ba'di
    d = d->link;
    }
    if(c==0)
    {
    printf("\n\nthe property is not founded please try again");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    if(c>0)
    {
    fp2 = fopen("zamin.txt","w");
        //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;

    while(d!=NULL)
    {
    fprintf(fp2,"%s\n",d->area);
    fprintf(fp2,"%s\n",d->address);
    fprintf(fp2,"%s\n",d->type);
    fprintf(fp2,"%s\n",d->size);
    fprintf(fp2,"%s\n",d->phone);
    fprintf(fp2,"%s\n",d->price);
    fprintf(fp2,"%s\n",d->year);
    fprintf(fp2,"%s\n",d->month);
    fprintf(fp2,"%s\n",d->day);
    fprintf(fp2,"%s\n",d->random);
    fprintf(fp2,"%s\n",d->active);
    p=d;
    free(p);
    d = d->link;


    }
    fclose(fp2);
    printf("\n\n\nyou are successful press any key to go main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();






    }





}
void delete_Office_property(void)
{
    system("cls");
    printf("welcome to Delete Office property information\n\n");
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_edari.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp2);

    char Office_property_code[10] , deactive[10] ,edit_year[10] , edit_month[10] , edit_day[10]; //code melk maskoni mored nazar
    printf("\nNow time to Enter your Office property code and next press Enter : ");
    scanf("%s" , &Office_property_code);
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};


    //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

    while(d!=NULL)
    {
    if ( strcmp(Office_property_code,d->random) == 0 ){
        if( strcmp(d->active,one) == 0 ){


     printf("\nNow time to delete your Residential property information if you sure Enter (2) : ");
     scanf("%s", &deactive);
     if ( strcmp(deactive , two) == 0 )
     strcpy(d->active,deactive);
     else
     {
    printf("\n\nyou aren't press '2' !!!!! please try it again because your property was not delete ");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    printf("\nNow time to save the date when you deleted your information if you like take it back tell its to admin : ");
    printf("\nWe start with year : ");
    scanf("%s", &edit_year);
    printf("\nPlease Enter month : ");
    scanf("%s", &edit_month);
    printf("\nPlease Enter day : ");
    scanf("%s", &edit_day);
    if( (atoi(edit_year) >= atoi(d->year) ) && (atoi(edit_month) >= atoi(d->month) ) && (atoi(edit_day) >= atoi(d->day) ) ){
    strcpy(d->year,edit_year);
    strcpy(d->month,edit_month);
    strcpy(d->day,edit_day);
    }
    else
    {
       printf("\n\nyour date input is wrong because you aren't input today date please try it again because your property was not delete ");
        printf("\npress any key to back main menu screen");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();


    }


     c++;
    }
    }

    //raftan be liste ba'di
    d = d->link;
    }
    if(c==0)
    {
    printf("\n\nthe property is not founded please try again");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    if(c>0)
    {
    fp2 = fopen("melk_edari.txt","w");
        //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;

    while(d!=NULL)
    {
    fprintf(fp2,"%s\n",d->area);
    fprintf(fp2,"%s\n",d->address);
    fprintf(fp2,"%s\n",d->type);
    fprintf(fp2,"%s\n",d->age);
    fprintf(fp2,"%s\n",d->size);
    fprintf(fp2,"%s\n",d->floor);
    fprintf(fp2,"%s\n",d->orig_size);
    fprintf(fp2,"%s\n",d->phone);
    fprintf(fp2,"%s\n",d->rooms);
    fprintf(fp2,"%s\n",d->price);
    fprintf(fp2,"%s\n",d->year);
    fprintf(fp2,"%s\n",d->month);
    fprintf(fp2,"%s\n",d->day);
    fprintf(fp2,"%s\n",d->random);
    fprintf(fp2,"%s\n",d->active);
    p=d;
    free(p);
    d = d->link;

    }
    fclose(fp2);
    printf("\n\n\nyou are successful press any key to go main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();






    }
}
void delete_Residential_property(void)
{
    system("cls");
    printf("welcome to Delete Residential property information\n\n");
    struct deletee{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    struct deletee *link;
    };
    typedef struct deletee Delete;
    //p--->sare list q----->payane list
    Delete *p = NULL,*q=NULL;
    FILE *fp2;
    fp2 = fopen("melk_maskoni.txt","r");


    while(!feof(fp2))
    {

    //Ejade gere jadid
    Delete *d;
    d = malloc(sizeof(Delete));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp2,"%s\n",d->area);
    fscanf(fp2,"%s\n",d->address);
    fscanf(fp2,"%s\n",d->type);
    fscanf(fp2,"%s\n",d->age);
    fscanf(fp2,"%s\n",d->size);
    fscanf(fp2,"%s\n",d->floor);
    fscanf(fp2,"%s\n",d->orig_size);
    fscanf(fp2,"%s\n",d->phone);
    fscanf(fp2,"%s\n",d->rooms);
    fscanf(fp2,"%s\n",d->price);
    fscanf(fp2,"%s\n",d->year);
    fscanf(fp2,"%s\n",d->month);
    fscanf(fp2,"%s\n",d->day);
    fscanf(fp2,"%s\n",d->random);
    fscanf(fp2,"%s\n",d->active);
    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp2);

    char Residential_property_code[10] , deactive[10] ,edit_year[10] , edit_month[10] , edit_day[10]; //code melk maskoni mored nazar
    printf("\nNow time to Enter your Residential property code and next press Enter : ");
    scanf("%s" , &Residential_property_code);
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};


    //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

    while(d!=NULL)
    {
    if ( strcmp(Residential_property_code,d->random) == 0 ){
        if( strcmp(d->active,one) == 0 ){


     printf("\nNow time to delete your Residential property information if you sure Enter (2) : ");
     scanf("%s", &deactive);
     if ( strcmp(deactive , two) == 0 )
     strcpy(d->active,deactive);
     else
     {
    printf("\n\nyou aren't press '2' !!!!! please try it again because your property was not delete ");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    printf("\nNow time to save the date when you deleted your information if you like take it back tell its to admin : ");
    printf("\nWe start with year : ");
    scanf("%s", &edit_year);
    printf("\nPlease Enter month : ");
    scanf("%s", &edit_month);
    printf("\nPlease Enter day : ");
    scanf("%s", &edit_day);
    if( (atoi(edit_year) >= atoi(d->year) ) && (atoi(edit_month) >= atoi(d->month) ) && (atoi(edit_day) >= atoi(d->day) ) ){
    strcpy(d->year,edit_year);
    strcpy(d->month,edit_month);
    strcpy(d->day,edit_day);
    }
    else
    {
       printf("\n\nyour date input is wrong because you aren't input today date please try it again because your property was not delete ");
        printf("\npress any key to back main menu screen");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();


    }

     c++;
    }
    }

    //raftan be liste ba'di
    d = d->link;
    }
    if(c==0)
    {
    printf("\n\nthe property is not founded please try again");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    if(c>0)
    {
    fp2 = fopen("melk_maskoni.txt","w");
        //gere' jadid
    Delete *d;
    //gharar dadan dar avvale list
    d = p;

    while(d!=NULL)
    {
    fprintf(fp2,"%s\n",d->area);
    fprintf(fp2,"%s\n",d->address);
    fprintf(fp2,"%s\n",d->type);
    fprintf(fp2,"%s\n",d->age);
    fprintf(fp2,"%s\n",d->size);
    fprintf(fp2,"%s\n",d->floor);
    fprintf(fp2,"%s\n",d->orig_size);
    fprintf(fp2,"%s\n",d->phone);
    fprintf(fp2,"%s\n",d->rooms);
    fprintf(fp2,"%s\n",d->price);
    fprintf(fp2,"%s\n",d->year);
    fprintf(fp2,"%s\n",d->month);
    fprintf(fp2,"%s\n",d->day);
    fprintf(fp2,"%s\n",d->random);
    fprintf(fp2,"%s\n",d->active);
    p=d;
    free(p);
    d = d->link;

    }
    fclose(fp2);
    printf("\n\n\nyou are successful press any key to go main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();






    }

}
void delete_sale(void)
{
    system("cls");
    printf("welcome to Delete sale information Tab\n\n");
    printf("1. Delete Residential property information \n"); //melk maskoni
    printf("2. Delete Office property information \n"); //melk edari
    printf("3. Delete Land information \n"); //zamin
    printf("4. Back to delete information Tab \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    char four[]= {'4' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        delete_Residential_property();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        delete_Office_property();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        delete_land();
    }
    if( strcmp(choice , four) == 0){
        counter++;
        delete_information();
    }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        delete_sale();

    }



}
void delete_information(void)
{
    system("cls");
    printf("welcome to delete information menu\n\n");
    printf("1. Delete sale information \n");
    printf("2. Delete rent information \n");
    printf("3. Back to main menu \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        delete_sale();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        delete_rent();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        delete_information();

    }



}
void settings(void)
{
    system("cls");
    printf("welcome to settings menu\n\n");
    struct user{
        char user_name[50];
        char password[100];
        char name[50];
        char family_name[50];
        char user_code[20];
        char user_phone[20];
        char email[300];
        char year[10];
        char month[10];
        char day[10];
        struct user *link;
    };
    typedef struct user User;
    //p--->sare list q----->payane list
    User *p = NULL,*q=NULL;
    FILE *fp;
    fp = fopen("sign_up.txt","r");

    while(!feof(fp))
    {

    //Ejade gere jadid
    User *d;
    d = malloc(sizeof(User));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp,"%s\n",d->user_name);
    fscanf(fp,"%s\n",d->password);
    fscanf(fp,"%s\n",d->name);
    fscanf(fp,"%s\n",d->family_name);
    fscanf(fp,"%s\n",d->user_code);
    fscanf(fp,"%s\n",d->user_phone);
    fscanf(fp,"%s\n",d->email);
    fscanf(fp,"%s\n",d->year);
    fscanf(fp,"%s\n",d->month);
    fscanf(fp,"%s\n",d->day);

    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp);
    char edit_inputUser[50] , edit_inputpassword[100] , editpassword[100];
    printf("\nNow time to login please Enter your user name and password");
    printf("\n\nUsername : ");
    scanf("%s", &edit_inputUser);
    printf("\n\npassword : ");
    scanf("%s", &edit_inputpassword);
    //gere' jadid
    User *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

    while(d!=NULL)
    {
    if ((strcmp(edit_inputUser,d->user_name) == 0) && (strcmp(edit_inputpassword,d->password) == 0))
    {
     printf("\nNow time to change your password please Enter your new password");
     printf("\n\npassword : ");
     scanf("%s", &editpassword);
     if ( strlen(editpassword) < 8) {
        printf("\n\nPassword should be more than 8 characters\n");
        printf("\n\nYour password is incorrect,if you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
     strcpy(d->password , editpassword);
     c++;
    }
    //raftan be liste ba'di
    d = d->link;
    }
    if(c==0)
    {
    printf("\n\nthe user is not founded or the password is incorrect please try again");
    printf("\npress any key to back main menu screen");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();
    }
    if(c>0)
    {
    fp = fopen("sign_up.txt","w");
        //gere' jadid
    User *d;
    //gharar dadan dar avvale list
    d = p;

    while(d!=NULL)
    {
    fprintf(fp,"%s\n",d->user_name);
    fprintf(fp,"%s\n",d->password);
    fprintf(fp,"%s\n",d->name);
    fprintf(fp,"%s\n",d->family_name);
    fprintf(fp,"%s\n",d->user_code);
    fprintf(fp,"%s\n",d->user_phone);
    fprintf(fp,"%s\n",d->email);
    fprintf(fp,"%s\n",d->year);
    fprintf(fp,"%s\n",d->month);
    fprintf(fp,"%s\n",d->day);

    p=d;
    free(p);
    d = d->link;

    }
    fclose(fp);


    printf("\n\n\nyou are successful press any key to go main menu");
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();






    }





}
void rent_land(void) //ejare zamin
{
    system("cls");
    printf("welcome to Add new land for rent\n\n");
    struct rent_land{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    };
    struct rent_land Land;
    FILE *fp7;
    fp7=fopen("ejare_zamin.txt" , "a");



    printf("please Enter code of area and next press Enter : ");
    fflush(stdin);
    gets(Land.area);
    int i;
    int length1 = strlen (Land.area);
    for (i=0 ; i<length1 ; i++)
    {
        if (Land.area[i] == ' ' )
        {
            Land.area[i] = '-';
        }
    }
    printf("please Enter address of land and next press Enter : ");
    fflush(stdin);
    gets(Land.address);
    int length2 = strlen (Land.address);
    for (i=0 ; i<length2 ; i++)
    {
        if (Land.address[i] == ' ' )
        {
            Land.address[i] = '-';
        }
    }
    printf("please Enter type of land (inside the city or outside the city) and next press Enter : ");
    fflush(stdin);
    gets(Land.type);
    int length3 = strlen (Land.type);
    for (i=0 ; i<length3 ; i++)
    {
        if (Land.type[i] == ' ' )
        {
            Land.type[i] = '-';
        }
    }
    printf("please Enter size of land and next press Enter : ");
    fflush(stdin);
    gets(Land.size);
    int length4 = strlen (Land.size);
    for (i=0 ; i<length4 ; i++)
    {
        if (Land.size[i] == ' ' )
        {
            Land.size[i] = '-';
        }
    }
    printf("please Enter owner of land phone number and next press Enter : ");
    fflush(stdin);
    gets(Land.phone);
    int length5 = strlen (Land.phone);
    for (i=0 ; i<length5 ; i++)
    {
        if (Land.phone[i] == ' ' )
        {
            Land.phone[i] = '-';
        }
        }
        if ( strlen(Land.phone) != 11) {
        printf("\n\nUser phone should be has 11 characters\n");
        printf("\n\nif you like please try to input information again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }


    printf("please Enter mortgage price of land( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(Land.mortgage_price);
    int length6 = strlen (Land.mortgage_price);
    for (i=0 ; i<length6 ; i++)
    {
        if (Land.mortgage_price[i] == ' ' )
        {
            Land.mortgage_price[i] = '-';
        }
    }
    printf("please Enter monthly rent price of land( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(Land.monthly_price);
    int length9 = strlen (Land.monthly_price);
    for (i=0 ; i<length9 ; i++)
    {
        if (Land.monthly_price[i] == ' ' )
        {
            Land.monthly_price[i] = '-';
        }
    }
    printf("please Enter the date of arrival this information, we start from the year and next press Enter : ");
    fflush(stdin);
    gets(Land.year);
    int lengthyear= strlen (Land.year);
    for (i=0 ; i<lengthyear ; i++)
    {
        if (Land.year[i] == ' ' )
        {
            Land.year[i] = '-';
        }
    }
    if ( strlen(Land.year) != 4) {
        printf("\n\year should be has 4 characters\n");
        printf("\n\nYour year is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the month and next press Enter : ");
    fflush(stdin);
    gets(Land.month);
    int lengthmonth= strlen (Land.month);
    for (i=0 ; i<lengthmonth ; i++)
    {
        if (Land.month[i] == ' ' )
        {
            Land.month[i] = '-';
        }
    }
    if ( strlen(Land.month) > 2) {
        printf("\n\month should be has 2 or less than 2 characters\n");
        printf("\n\nYour month is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the day and next press Enter : ");
    fflush(stdin);
    gets(Land.day);
    int lengthday= strlen (Land.day);
    for (i=0 ; i<lengthday ; i++)
    {
        if (Land.day[i] == ' ' )
        {
            Land.day[i] = '-';
        }
    }
    if ( strlen(Land.day) > 2) {
        printf("\n\day should be has 2 or less than 2 characters\n");
        printf("\n\nYour day is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }






    printf("You are successful. Please enter exclusive code (At least 6 characters) and remember this code to check your Land property information later : ");
    fflush(stdin);
    gets(Land.random);
    int length7 = strlen (Land.random);
    for (i=0 ; i<length7 ; i++)
    {
        if (Land.random[i] == ' ' )
        {
            Land.random[i] = '-';
        }
    }
    if ( strlen(Land.random) < 6) {
        printf("\n\your code should be has 6 or more than 6 characters\n");
        printf("\n\nYour exclusively code is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("if you sure your input information about Land property is correct please Enter (1) if else press (2) : ");
    fflush(stdin);
    gets(Land.active);
    char one[]= {'1' , '\0'};
    if ( strcmp(Land.active , one) !=0 ) {
        printf("\nyou must be press '1' !!!!!! \n");
        printf("\n\nYour information aren't saved,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }


    fprintf(fp7, "%s\n" ,Land.area);
    fprintf(fp7, "%s\n" ,Land.address);
    fprintf(fp7, "%s\n" ,Land.type);
    fprintf(fp7, "%d\n" ,Land.size);
    fprintf(fp7, "%s\n" ,Land.phone);
    fprintf(fp7, "%s\n" ,Land.mortgage_price);
    fprintf(fp7, "%s\n" ,Land.monthly_price);
    fprintf(fp7, "%s\n" ,Land.year);
    fprintf(fp7, "%s\n" ,Land.month);
    fprintf(fp7, "%s\n" ,Land.day);
    fprintf(fp7, "%s\n" ,Land.random);
    fprintf(fp7, "%s\n" ,Land.active);
    fclose(fp7);

    printf("\n\nYou're succeeded\npress any key to back main menu");
    fpp2 = fopen("counter_user_for_admin.txt","a");
    if( (strcmp(admin,inputUser) != 0) && (strcmp(admin_password,inputpassword) != 0) )
        fprintf(fpp2, "This user has added a property for sale : \n");
    counter_user_for_admin();
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();








}
void rent_Office_property(void) //ejare melk edari
{
    system("cls");
    printf("welcome to Add new rent of Office property\n\n");
    struct rent_office{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    };
    struct rent_office office;
    FILE *fp6;
    fp6=fopen("ejare_melk_edari.txt" , "a");



    printf("please Enter code of area and next press Enter : ");
    fflush(stdin);
    gets(office.area);
    int i;
    int length1 = strlen (office.area);
    for (i=0 ; i<length1 ; i++)
    {
        if (office.area[i] == ' ' )
        {
            office.area[i] = '-';
        }
    }
    printf("please Enter address of property and next press Enter : ");
    fflush(stdin);
    gets(office.address);
    int length2 = strlen (office.address);
    for (i=0 ; i<length2 ; i++)
    {
        if (office.address[i] == ' ' )
        {
            office.address[i] = '-';
        }
    }
    printf("please Enter type of property (Formal Document or Administrative Position) and next press Enter : ");
    fflush(stdin);
    gets(office.type);
    int length3 = strlen (office.type);
    for (i=0 ; i<length3 ; i++)
    {
        if (office.type[i] == ' ' )
        {
            office.type[i] = '-';
        }
    }
    printf("please Enter age of property and next press Enter : ");
    fflush(stdin);
    gets(office.age);
    int length4 = strlen (office.age);
    for (i=0 ; i<length4 ; i++)
    {
        if (office.age[i] == ' ' )
        {
            office.age[i] = '-';
        }
    }
    printf("please Enter size of property and next press Enter : ");
    fflush(stdin);
    gets(office.size);
    int length5 = strlen (office.size);
    for (i=0 ; i<length5 ; i++)
    {
        if (office.size[i] == ' ' )
        {
            office.size[i] = '-';
        }
    }
    printf("please Enter how many floor of property and next press Enter : ");
    fflush(stdin);
    gets(office.floor);
    int length6 = strlen (office.floor);
    for (i=0 ; i<length6 ; i++)
    {
        if (office.floor[i] == ' ' )
        {
            office.floor[i] = '-';
        }
    }
    printf("please Enter original size of property and next press Enter : ");
    fflush(stdin);
    gets(office.orig_size);
    int length7 = strlen (office.orig_size);
    for (i=0 ; i<length7 ; i++)
    {
        if (office.orig_size[i] == ' ' )
        {
            office.orig_size[i] = '-';
        }
    }
    printf("please Enter owner of property phone number and next press Enter : ");
    fflush(stdin);
    gets(office.phone);
    int length8 = strlen (office.phone);
    for (i=0 ; i<length8 ; i++)
    {
        if (office.phone[i] == ' ' )
        {
            office.phone[i] = '-';
        }
    }
    if ( strlen(office.phone) != 11) {
        printf("\n\nUser phone should be has 11 characters\n");
        printf("\n\nif you like please try to input information again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("please Enter number of rooms in property and next press Enter : ");
    fflush(stdin);
    gets(office.rooms);
    int length9 = strlen (office.rooms);
    for (i=0 ; i<length9 ; i++)
    {
        if (office.rooms[i] == ' ' )
        {
            office.rooms[i] = '-';
        }
    }
    printf("please Enter mortgage price of property( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(office.mortgage_price);
    int length10 = strlen (office.mortgage_price);
    for (i=0 ; i<length10 ; i++)
    {
        if (office.mortgage_price[i] == ' ' )
        {
            office.mortgage_price[i] = '-';
        }
    }
    printf("please Enter monthly rent price of property( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(office.monthly_price);
    int length13 = strlen (office.monthly_price);
    for (i=0 ; i<length13 ; i++)
    {
        if (office.monthly_price[i] == ' ' )
        {
            office.monthly_price[i] = '-';
        }
    }
    printf("please Enter the date of arrival this information, we start from the year and next press Enter : ");
    fflush(stdin);
    gets(office.year);
    int lengthyear= strlen (office.year);
    for (i=0 ; i<lengthyear ; i++)
    {
        if (office.year[i] == ' ' )
        {
            office.year[i] = '-';
        }
    }
    if ( strlen(office.year) != 4) {
        printf("\n\year should be has 4 characters\n");
        printf("\n\nYour year is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the month and next press Enter : ");
    fflush(stdin);
    gets(office.month);
    int lengthmonth= strlen (office.month);
    for (i=0 ; i<lengthmonth ; i++)
    {
        if (office.month[i] == ' ' )
        {
            office.month[i] = '-';
        }
    }
    if ( strlen(office.month) > 2) {
        printf("\n\month should be has 2 or less than 2 characters\n");
        printf("\n\nYour month is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the day and next press Enter : ");
    fflush(stdin);
    gets(office.day);
    int lengthday= strlen (office.day);
    for (i=0 ; i<lengthday ; i++)
    {
        if (office.day[i] == ' ' )
        {
            office.day[i] = '-';
        }
    }
    if ( strlen(office.day) > 2) {
        printf("\n\day should be has 2 or less than 2 characters\n");
        printf("\n\nYour day is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }




    printf("You are successful. Please enter exclusive code (At least 6 characters) and remember this code to check your Office property information later : ");
    fflush(stdin);
    gets(office.random);
    int length11 = strlen (office.random);
    for (i=0 ; i<length11 ; i++)
    {
        if (office.random[i] == ' ' )
        {
            office.random[i] = '-';
        }
    }
    if ( strlen(office.random) < 6) {
        printf("\n\your code should be has 6 or more than 6 characters\n");
        printf("\n\nYour exclusively code is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("if you sure your input information about office property is correct please Enter (1) if else press (2) : ");
    fflush(stdin);
    gets(office.active);
    char one[]= {'1' , '\0'};
    if ( strcmp(office.active , one) !=0 ) {
        printf("\nyou must be press '1' !!!!!! \n");
        printf("\n\nYour information aren't saved,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }




    fprintf(fp6, "%s\n" ,office.area);
    fprintf(fp6, "%s\n" ,office.address);
    fprintf(fp6, "%s\n" ,office.type);
    fprintf(fp6, "%s\n" ,office.age);
    fprintf(fp6, "%s\n" ,office.size);
    fprintf(fp6, "%s\n" ,office.floor);
    fprintf(fp6, "%s\n" ,office.orig_size);
    fprintf(fp6, "%s\n" ,office.phone);
    fprintf(fp6, "%s\n" ,office.rooms);
    fprintf(fp6, "%s\n" ,office.mortgage_price);
    fprintf(fp6, "%s\n" ,office.monthly_price);
    fprintf(fp6, "%s\n" ,office.year);
    fprintf(fp6, "%s\n" ,office.month);
    fprintf(fp6, "%s\n" ,office.day);
    fprintf(fp6, "%s\n" ,office.random);
    fprintf(fp6, "%s\n" ,office.active);
    fclose(fp6);

    printf("\n\nYou're succeeded\npress any key to back main menu");
    fpp2 = fopen("counter_user_for_admin.txt","a");
    if( (strcmp(admin,inputUser) != 0) && (strcmp(admin_password,inputpassword) != 0) )
        fprintf(fpp2, "This user has added a property for sale : \n");
    counter_user_for_admin();
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();



}
void rent_Residential_property(void) //ejare melk maskoni
{
    system("cls");
    printf("welcome to Add new rent of Residential property\n\n");
    struct rent{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char mortgage_price[50];
    char monthly_price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    };
    struct rent Rent;
    FILE *fp5;
    fp5=fopen("ejare_melk_maskoni.txt" , "a");
    printf("please Enter code of area and next press Enter : ");
    fflush(stdin);
    gets(Rent.area);
    int i;
    int length1 = strlen (Rent.area);
    for (i=0 ; i<length1 ; i++)
    {
        if (Rent.area[i] == ' ' )
        {
            Rent.area[i] = '-';
        }
    }
    printf("please Enter address of property and next press Enter : ");
    fflush(stdin);
    gets(Rent.address);
    int length2 = strlen (Rent.address);
    for (i=0 ; i<length2 ; i++)
    {
        if (Rent.address[i] == ' ' )
        {
            Rent.address[i] = '-';
        }
    }
    printf("please Enter type of property (Apartment or Villa) and next press Enter : ");
    fflush(stdin);
    gets(Rent.type);
    int length3 = strlen (Rent.type);
    for (i=0 ; i<length3 ; i++)
    {
        if (Rent.type[i] == ' ' )
        {
            Rent.type[i] = '-';
        }
    }
    printf("please Enter age of property and next press Enter : ");
    fflush(stdin);
    gets(Rent.age);
    int length4 = strlen (Rent.age);
    for (i=0 ; i<length4 ; i++)
    {
        if (Rent.age[i] == ' ' )
        {
            Rent.age[i] = '-';
        }
    }
    printf("please Enter size of property and next press Enter : ");
    fflush(stdin);
    gets(Rent.size);
    int length5 = strlen (Rent.size);
    for (i=0 ; i<length5 ; i++)
    {
        if (Rent.size[i] == ' ' )
        {
            Rent.size[i] = '-';
        }
    }
    printf("please Enter how many floor in property and next press Enter : ");
    fflush(stdin);
    gets(Rent.floor);
    int length6 = strlen (Rent.floor);
    for (i=0 ; i<length6 ; i++)
    {
        if (Rent.floor[i] == ' ' )
        {
            Rent.floor[i] = '-';
        }
    }
    printf("please Enter original size of property and next press Enter : ");
    fflush(stdin);
    gets(Rent.orig_size);
    int length7 = strlen (Rent.orig_size);
    for (i=0 ; i<length7 ; i++)
    {
        if (Rent.orig_size[i] == ' ' )
        {
            Rent.orig_size[i] = '-';
        }
    }
    printf("please Enter owner of property phone number and next press Enter : ");
    fflush(stdin);
    gets(Rent.phone);
    int length8 = strlen (Rent.phone);
    for (i=0 ; i<length8 ; i++)
    {
        if (Rent.phone[i] == ' ' )
        {
            Rent.phone[i] = '-';
        }
    }
    if ( strlen(Rent.phone) != 11) {
        printf("\n\nUser phone should be has 11 characters\n");
        printf("\n\nif you like please try to input information again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    if(Rent.phone[0] == '0')
    {
        printf("\n This phone number is incorrect ");
        printf("\n please try again to input new information press any key to get back ");
        getche();
        mainmenu();
    }
    printf("please Enter number of rooms in property and next press Enter : ");
    fflush(stdin);
    gets(Rent.rooms);
    int length9 = strlen (Rent.rooms);
    for (i=0 ; i<length9 ; i++)
    {
        if (Rent.rooms[i] == ' ' )
        {
            Rent.rooms[i] = '-';
        }
    }
    printf("please Enter mortgage price of property( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(Rent.mortgage_price);
    int length10 = strlen (Rent.mortgage_price);
    for (i=0 ; i<length10 ; i++)
    {
        if (Rent.mortgage_price[i] == ' ' )
        {
            Rent.mortgage_price[i] = '-';
        }
    }
    printf("please Enter monthly rent price of property( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(Rent.monthly_price);
    int length13 = strlen (Rent.monthly_price);
    for (i=0 ; i<length13 ; i++)
    {
        if (Rent.monthly_price[i] == ' ' )
        {
            Rent.monthly_price[i] = '-';
        }
    }
    printf("please Enter the date of arrival this information, we start from the year and next press Enter : ");
    fflush(stdin);
    gets(Rent.year);
    int lengthyear= strlen (Rent.year);
    for (i=0 ; i<lengthyear ; i++)
    {
        if (Rent.year[i] == ' ' )
        {
            Rent.year[i] = '-';
        }
    }
     if ( strlen(Rent.year) != 4) {
        printf("\n\year should be has 4 characters\n");
        printf("\n\nYour year is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the month and next press Enter : ");
    fflush(stdin);
    gets(Rent.month);
    int lengthmonth= strlen (Rent.month);
    for (i=0 ; i<lengthmonth ; i++)
    {
        if (Rent.month[i] == ' ' )
        {
            Rent.month[i] = '-';
        }
    }
    if ( strlen(Rent.month) > 2) {
        printf("\n\month should be has 2 or less than 2 characters\n");
        printf("\n\nYour month is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the day and next press Enter : ");
    fflush(stdin);
    gets(Rent.day);
    int lengthday= strlen (Rent.day);
    for (i=0 ; i<lengthday ; i++)
    {
        if (Rent.day[i] == ' ' )
        {
            Rent.day[i] = '-';
        }
    }
    if ( strlen(Rent.day) > 2) {
        printf("\n\day should be has 2 or less than 2 characters\n");
        printf("\n\nYour day is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }




    printf("You are successful. Please enter exclusive code (At least 6 characters) and remember this code to check your rent Residential property information later : ");
    fflush(stdin);
    gets(Rent.random);
    int length11 = strlen (Rent.random);
    for (i=0 ; i<length11 ; i++)
    {
        if (Rent.random[i] == ' ' )
        {
            Rent.random[i] = '-';
        }
    }
    if ( strlen(Rent.random) < 6) {
        printf("\n\your code should be has 6 or more than 6 characters\n");
        printf("\n\nYour exclusively code is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("if you sure your input information about rent Residential property is correct please Enter (1) if else press (2) : ");
    fflush(stdin);
    gets(Rent.active);
    char one[]= {'1' , '\0'};
    if ( strcmp(Rent.active , one) !=0 ) {
        printf("\nyou must be press '1' !!!!!! \n");
        printf("\n\nYour information aren't saved,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }



    fprintf(fp5, "%s\n" ,Rent.area);
    fprintf(fp5, "%s\n" ,Rent.address);
    fprintf(fp5, "%s\n" ,Rent.type);
    fprintf(fp5, "%s\n" ,Rent.age);
    fprintf(fp5, "%s\n" ,Rent.size);
    fprintf(fp5, "%s\n" ,Rent.floor);
    fprintf(fp5, "%s\n" ,Rent.orig_size);
    fprintf(fp5, "%s\n" ,Rent.phone);
    fprintf(fp5, "%s\n" ,Rent.rooms);
    fprintf(fp5, "%s\n" ,Rent.mortgage_price);
    fprintf(fp5, "%s\n" ,Rent.monthly_price);
    fprintf(fp5, "%s\n" ,Rent.year);
    fprintf(fp5, "%s\n" ,Rent.month);
    fprintf(fp5, "%s\n" ,Rent.day);
    fprintf(fp5, "%s\n" ,Rent.random);
    fprintf(fp5, "%s\n" ,Rent.active);
    fclose(fp5);

    printf("\n\nYou're succeeded\npress any key to back main menu");
    fpp2 = fopen("counter_user_for_admin.txt","a");
    if( (strcmp(admin,inputUser) != 0) && (strcmp(admin_password,inputpassword) != 0) )
        fprintf(fpp2, "This user has added a property for sale : \n");
    counter_user_for_admin();
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();




}
void rent (void)
{
    system("cls");
    printf("welcome to Add new rent Tab\n\n");
    printf("1. Add new rent of Residential property \n"); //melk maskoni
    printf("2. Add new rent of Office property \n"); //melk edari
    printf("3. Add new rent of Land \n"); //zamin
    printf("4. Back to new information Tab \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    char four[]= {'4' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        rent_Residential_property();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        rent_Office_property();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        rent_land();
    }
    if( strcmp(choice , four) == 0){
        counter++;
        new_information();
    }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        rent();

    }

}
void land(void) //zamin
{
    system("cls");
    printf("welcome to Add new land sale\n\n");
    struct land{
    char area[10];
    char address[300];
    char type[50];
    char size[10];
    char phone[20];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    };
    struct land Land;
    FILE *fp4;
    fp4=fopen("zamin.txt" , "a");
    printf("please Enter code of area and next press Enter : ");
    fflush(stdin);
    gets(Land.area);
    int i;
    int length1 = strlen (Land.area);
    for (i=0 ; i<length1 ; i++)
    {
        if (Land.area[i] == ' ' )
        {
            Land.area[i] = '-';
        }
    }
    printf("please Enter address of land and next press Enter : ");
    fflush(stdin);
    gets(Land.address);
    int length2 = strlen (Land.address);
    for (i=0 ; i<length2 ; i++)
    {
        if (Land.address[i] == ' ' )
        {
            Land.address[i] = '-';
        }
    }
    printf("please Enter type of land (inside the city or outside the city) and next press Enter : ");
    fflush(stdin);
    gets(Land.type);
    int length3 = strlen (Land.type);
    for (i=0 ; i<length3 ; i++)
    {
        if (Land.type[i] == ' ' )
        {
            Land.type[i] = '-';
        }
    }
    printf("please Enter size of land and next press Enter : ");
    fflush(stdin);
    gets(Land.size);
    int length4 = strlen (Land.size);
    for (i=0 ; i<length4 ; i++)
    {
        if (Land.size[i] == ' ' )
        {
            Land.size[i] = '-';
        }
    }
    printf("please Enter owner of land phone number and next press Enter : ");
    fflush(stdin);
    gets(Land.phone);
    int length5 = strlen (Land.phone);
    for (i=0 ; i<length5 ; i++)
    {
        if (Land.phone[i] == ' ' )
        {
            Land.phone[i] = '-';
        }
    }
     if ( strlen(Land.phone) != 11) {
        printf("\n\nUser phone should be has 11 characters\n");
        printf("\n\nif you like please try to input information again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("please Enter price of land ( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(Land.price);
    int length6 = strlen (Land.price);
    for (i=0 ; i<length6 ; i++)
    {
        if (Land.price[i] == ' ' )
        {
            Land.price[i] = '-';
        }
    }
    printf("please Enter the date of arrival this information, we start from the year and next press Enter : ");
    fflush(stdin);
    gets(Land.year);
    int lengthyear= strlen (Land.year);
    for (i=0 ; i<lengthyear ; i++)
    {
        if (Land.year[i] == ' ' )
        {
            Land.year[i] = '-';
        }
    }
    if ( strlen(Land.year) != 4) {
        printf("\n\year should be has 4 characters\n");
        printf("\n\nYour year is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the month and next press Enter : ");
    fflush(stdin);
    gets(Land.month);
    int lengthmonth= strlen (Land.month);
    for (i=0 ; i<lengthmonth ; i++)
    {
        if (Land.month[i] == ' ' )
        {
            Land.month[i] = '-';
        }
    }
    if ( strlen(Land.month) > 2) {
        printf("\n\month should be has 2 or less than 2 characters\n");
        printf("\n\nYour month is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the day and next press Enter : ");
    fflush(stdin);
    gets(Land.day);
    int lengthday= strlen (Land.day);
    for (i=0 ; i<lengthday ; i++)
    {
        if (Land.day[i] == ' ' )
        {
            Land.day[i] = '-';
        }
    }
    if ( strlen(Land.day) > 2) {
        printf("\n\day should be has 2 or less than 2 characters\n");
        printf("\n\nYour day is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }


    printf("You are successful. Please enter exclusive code (At least 6 characters) and remember this code to check your Land property information later : ");
    fflush(stdin);
    gets(Land.random);
    int length7 = strlen (Land.random);
    for (i=0 ; i<length7 ; i++)
    {
        if (Land.random[i] == ' ' )
        {
            Land.random[i] = '-';
        }
    }
    if ( strlen(Land.random) < 6) {
        printf("\n\your code should be has 6 or more than 6 characters\n");
        printf("\n\nYour exclusively code is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("if you sure your input information about Land property is correct please Enter (1) if else press (2) : ");
    fflush(stdin);
    gets(Land.active);
    char one[]= {'1' , '\0'};
    if ( strcmp(Land.active , one) !=0 ) {
        printf("\nyou must be press '1' !!!!!! \n");
        printf("\n\nYour information aren't saved,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }


    fprintf(fp4, "%s\n" ,Land.area);
    fprintf(fp4, "%s\n" ,Land.address);
    fprintf(fp4, "%s\n" ,Land.type);
    fprintf(fp4, "%s\n" ,Land.size);
    fprintf(fp4, "%s\n" ,Land.phone);
    fprintf(fp4, "%s\n" ,Land.price);
    fprintf(fp4, "%s\n" ,Land.year);
    fprintf(fp4, "%s\n" ,Land.month);
    fprintf(fp4, "%s\n" ,Land.day);
    fprintf(fp4, "%s\n" ,Land.random);
    fprintf(fp4, "%s\n" ,Land.active);
    fclose(fp4);

    printf("\n\nYou're succeeded\npress any key to back main menu");
    fpp2 = fopen("counter_user_for_admin.txt","a");
    if( (strcmp(admin,inputUser) != 0) && (strcmp(admin_password,inputpassword) != 0) )
        fprintf(fpp2, "This user has added a property for sale : \n");
    counter_user_for_admin();
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();




}
void Office_property(void) //melk edari
{
    system("cls");
    printf("welcome to Add new Office property\n\n");
    struct sale_office{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    };
    struct sale_office office;
    FILE *fp3;
    fp3=fopen("melk_edari.txt" , "a");
    printf("please Enter code of area and next press Enter : ");
    fflush(stdin);
    gets(office.area);
    int i;
    int length1 = strlen (office.area);
    for (i=0 ; i<length1 ; i++)
    {
        if (office.area[i] == ' ' )
        {
            office.area[i] = '-';
        }
    }
    printf("please Enter address of property and next press Enter : ");
    fflush(stdin);
    gets(office.address);
    int length2 = strlen (office.address);
    for (i=0 ; i<length2 ; i++)
    {
        if (office.address[i] == ' ' )
        {
            office.address[i] = '-';
        }
    }
    printf("please Enter type of property (Formal Document or Administrative Position) and next press Enter : ");
    fflush(stdin);
    gets(office.type);
    int length3 = strlen (office.type);
    for (i=0 ; i<length3 ; i++)
    {
        if (office.type[i] == ' ' )
        {
            office.type[i] = '-';
        }
    }
    printf("please Enter age of property and next press Enter : ");
    fflush(stdin);
    gets(office.age);
    int length4 = strlen (office.age);
    for (i=0 ; i<length4 ; i++)
    {
        if (office.age[i] == ' ' )
        {
            office.age[i] = '-';
        }
    }
    printf("please Enter size of property and next press Enter : ");
    fflush(stdin);
    gets(office.size);
    int length5 = strlen (office.size);
    for (i=0 ; i<length5 ; i++)
    {
        if (office.size[i] == ' ' )
        {
            office.size[i] = '-';
        }
    }
    printf("please Enter how many floor of property and next press Enter : ");
    fflush(stdin);
    gets(office.floor);
    int length6 = strlen (office.floor);
    for (i=0 ; i<length6 ; i++)
    {
        if (office.floor[i] == ' ' )
        {
            office.floor[i] = '-';
        }
    }
    printf("please Enter original size of property and next press Enter : ");
    fflush(stdin);
    gets(office.orig_size);
    int length7 = strlen (office.orig_size);
    for (i=0 ; i<length7 ; i++)
    {
        if (office.orig_size[i] == ' ' )
        {
            office.orig_size[i] = '-';
        }
    }
    printf("please Enter owner of property phone number and next press Enter : ");
    fflush(stdin);
    gets(office.phone);
    int length8 = strlen (office.phone);
    for (i=0 ; i<length8 ; i++)
    {
        if (office.phone[i] == ' ' )
        {
            office.phone[i] = '-';
        }
    }
    if ( strlen(office.phone) != 11) {
        printf("\n\nUser phone should be has 11 characters\n");
        printf("\n\nif you like please try to input information again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("please Enter number of rooms in property and next press Enter : ");
    fflush(stdin);
    gets(office.rooms);
    int length9 = strlen (office.rooms);
    for (i=0 ; i<length9 ; i++)
    {
        if (office.rooms[i] == ' ' )
        {
            office.rooms[i] = '-';
        }
    }
    printf("please Enter price of property ( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(office.price);
    int length10 = strlen (office.price);
    for (i=0 ; i<length10 ; i++)
    {
        if (office.price[i] == ' ' )
        {
            office.price[i] = '-';
        }
    }
    printf("please Enter the date of arrival this information, we start from the year and next press Enter : ");
    fflush(stdin);
    gets(office.year);
    int lengthyear= strlen (office.year);
    for (i=0 ; i<lengthyear ; i++)
    {
        if (office.year[i] == ' ' )
        {
            office.year[i] = '-';
        }
    }
    if ( strlen(office.year) != 4) {
        printf("\n\year should be has 4 characters\n");
        printf("\n\nYour year is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the month and next press Enter : ");
    fflush(stdin);
    gets(office.month);
    int lengthmonth= strlen (office.month);
    for (i=0 ; i<lengthmonth ; i++)
    {
        if (office.month[i] == ' ' )
        {
            office.month[i] = '-';
        }
    }
     if ( strlen(office.month) > 2) {
        printf("\n\month should be has 2 or less than 2 characters\n");
        printf("\n\nYour month is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the day and next press Enter : ");
    fflush(stdin);
    gets(office.day);
    int lengthday= strlen (office.day);
    for (i=0 ; i<lengthday ; i++)
    {
        if (office.day[i] == ' ' )
        {
            office.day[i] = '-';
        }
    }
    if ( strlen(office.day) > 2) {
        printf("\n\day should be has 2 or less than 2 characters\n");
        printf("\n\nYour day is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }




    printf("You are successful. Please enter exclusive code (At least 6 characters) and remember this code to check your Office property information later : ");
    fflush(stdin);
    gets(office.random);
    int length11 = strlen (office.random);
    for (i=0 ; i<length11 ; i++)
    {
        if (office.random[i] == ' ' )
        {
            office.random[i] = '-';
        }
    }
    if ( strlen(office.random) < 6) {
        printf("\n\your code should be has 6 or more than 6 characters\n");
        printf("\n\nYour exclusively code is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("if you sure your input information about office property is correct please Enter (1) if else press (2) : ");
    fflush(stdin);
    gets(office.active);
    char one[]= {'1' , '\0'};
    if ( strcmp(office.active , one) !=0 ) {
        printf("\nyou must be press '1' !!!!!! \n");
        printf("\n\nYour information aren't saved,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }


    fprintf(fp3, "%s\n" ,office.area);
    fprintf(fp3, "%s\n" ,office.address);
    fprintf(fp3, "%s\n" ,office.type);
    fprintf(fp3, "%s\n" ,office.age);
    fprintf(fp3, "%s\n" ,office.size);
    fprintf(fp3, "%s\n" ,office.floor);
    fprintf(fp3, "%s\n" ,office.orig_size);
    fprintf(fp3, "%s\n" ,office.phone);
    fprintf(fp3, "%s\n" ,office.rooms);
    fprintf(fp3, "%s\n" ,office.price);
    fprintf(fp3, "%s\n" ,office.year);
    fprintf(fp3, "%s\n" ,office.month);
    fprintf(fp3, "%s\n" ,office.day);
    fprintf(fp3, "%s\n" ,office.random);
    fprintf(fp3, "%s\n" ,office.active);
    fclose(fp3);

    printf("\n\nYou're succeeded\npress any key to back main menu");
    fpp2 = fopen("counter_user_for_admin.txt","a");
    if( (strcmp(admin,inputUser) != 0) && (strcmp(admin_password,inputpassword) != 0) )
        fprintf(fpp2, "This user has added a property for sale : \n");
    counter_user_for_admin();
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();





}
void Residential_property() //melk maskoni
{
    system("cls");
    printf("welcome to Add new Residential property\n\n");
    struct sale{
    char area[10];
    char address[300];
    char type[50];
    char age[5];
    char size[10];
    char floor[5];
    char orig_size[10];
    char phone[20];
    char rooms[5];
    char price[50];
    char year[10];
    char month[10];
    char day[10];
    char random[10];
    char active[10];
    };
    struct sale Sale;
    FILE *fp2;
    fp2=fopen("melk_maskoni.txt" , "a");
    printf("please Enter code of area and next press Enter : ");
    fflush(stdin);
    gets(Sale.area);
    int i;
    int length1 = strlen (Sale.area);
    for (i=0 ; i<length1 ; i++)
    {
        if (Sale.area[i] == ' ' )
        {
            Sale.area[i] = '-';
        }
    }
    printf("please Enter address of property and next press Enter : ");
    fflush(stdin);
    gets(Sale.address);
    int length2 = strlen (Sale.address);
    for (i=0 ; i<length2 ; i++)
    {
        if (Sale.address[i] == ' ' )
        {
            Sale.address[i] = '-';
        }
    }
    printf("please Enter type of property (Apartment or Villa) and next press Enter : ");
    fflush(stdin);
    gets(Sale.type);
    int length3 = strlen (Sale.type);
    for (i=0 ; i<length3 ; i++)
    {
        if (Sale.type[i] == ' ' )
        {
            Sale.type[i] = '-';
        }
    }
    printf("please Enter age of property and next press Enter : ");
    fflush(stdin);
    gets(Sale.age);
    int length4 = strlen (Sale.age);
    for (i=0 ; i<length4 ; i++)
    {
        if (Sale.age[i] == ' ' )
        {
            Sale.age[i] = '-';
        }
    }
    printf("please Enter size of property and next press Enter : ");
    fflush(stdin);
    gets(Sale.size);
    int length5 = strlen (Sale.size);
    for (i=0 ; i<length5 ; i++)
    {
        if (Sale.size[i] == ' ' )
        {
            Sale.size[i] = '-';
        }
    }
    printf("please Enter how many floor in property and next press Enter : ");
    fflush(stdin);
    gets(Sale.floor);
    int length6 = strlen (Sale.floor);
    for (i=0 ; i<length6 ; i++)
    {
        if (Sale.floor[i] == ' ' )
        {
            Sale.floor[i] = '-';
        }
    }
    printf("please Enter original size of property and next press Enter : ");
    fflush(stdin);
    gets(Sale.orig_size);
    int length7 = strlen (Sale.orig_size);
    for (i=0 ; i<length7 ; i++)
    {
        if (Sale.orig_size[i] == ' ' )
        {
            Sale.orig_size[i] = '-';
        }
    }
    printf("please Enter owner of property phone number and next press Enter : ");
    fflush(stdin);
    gets(Sale.phone);
    int length8 = strlen (Sale.phone);
    for (i=0 ; i<length8 ; i++)
    {
        if (Sale.phone[i] == ' ' )
        {
            Sale.phone[i] = '-';
        }
    }
    if ( strlen(Sale.phone) != 11) {
        printf("\n\nUser phone should be has 11 characters\n");
        printf("\n\nif you like please try to input information again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("please Enter number of rooms in property and next press Enter : ");
    fflush(stdin);
    gets(Sale.rooms);
    int length9 = strlen (Sale.rooms);
    for (i=0 ; i<length9 ; i++)
    {
        if (Sale.rooms[i] == ' ' )
        {
            Sale.rooms[i] = '-';
        }
    }
    printf("please Enter price of property ( currency in MIL TOMAN )and next press Enter : ");
    fflush(stdin);
    gets(Sale.price);
    int length10 = strlen (Sale.price);
    for (i=0 ; i<length10 ; i++)
    {
        if (Sale.price[i] == ' ' )
        {
            Sale.price[i] = '-';
        }
    }
    printf("please Enter the date of arrival this information, we start from the year and next press Enter : ");
    fflush(stdin);
    gets(Sale.year);
    int lengthyear= strlen (Sale.year);
    for (i=0 ; i<lengthyear ; i++)
    {
        if (Sale.year[i] == ' ' )
        {
            Sale.year[i] = '-';
        }
    }
    if ( strlen(Sale.year) != 4) {
        printf("\n\year should be has 4 characters\n");
        printf("\n\nYour year is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the month and next press Enter : ");
    fflush(stdin);
    gets(Sale.month);
    int lengthmonth= strlen (Sale.month);
    for (i=0 ; i<lengthmonth ; i++)
    {
        if (Sale.month[i] == ' ' )
        {
            Sale.month[i] = '-';
        }
    }
    if ( strlen(Sale.month) > 2) {
        printf("\n\month should be has 2 or less than 2 characters\n");
        printf("\n\nYour month is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("Now Enter the day and next press Enter : ");
    fflush(stdin);
    gets(Sale.day);
    int lengthday= strlen (Sale.day);
    for (i=0 ; i<lengthday ; i++)
    {
        if (Sale.day[i] == ' ' )
        {
            Sale.day[i] = '-';
        }
    }
    if ( strlen(Sale.day) > 2) {
        printf("\n\day should be has 2 or less than 2 characters\n");
        printf("\n\nYour day is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }



    printf("You are successful. Please enter exclusive code (At least 6 characters) and remember this code to check your residential property information later : ");
    fflush(stdin);
    gets(Sale.random);
    int length11 = strlen (Sale.random);
    for (i=0 ; i<length11 ; i++)
    {
        if (Sale.random[i] == ' ' )
        {
            Sale.random[i] = '-';
        }
    }
    if ( strlen(Sale.random) < 6) {
        printf("\n\your code should be has 6 or more than 6 characters\n");
        printf("\n\nYour exclusively code is incorrect,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    printf("if you sure your input information is correct please Enter (1) else press (2) : ");
    fflush(stdin);
    gets(Sale.active);
    char one[]= {'1' , '\0'};
    if ( strcmp(Sale.active , one) !=0 ) {
        printf("\nyou must be press '1' !!!!!! \n");
        printf("\n\nYour information aren't saved,if you like you can try it again carefully later");
        printf("\npress any key");
        getche();
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }



    fprintf(fp2, "%s\n" ,Sale.area);
    fprintf(fp2, "%s\n" ,Sale.address);
    fprintf(fp2, "%s\n" ,Sale.type);
    fprintf(fp2, "%s\n" ,Sale.age);
    fprintf(fp2, "%s\n" ,Sale.size);
    fprintf(fp2, "%s\n" ,Sale.floor);
    fprintf(fp2, "%s\n" ,Sale.orig_size);
    fprintf(fp2, "%s\n" ,Sale.phone);
    fprintf(fp2, "%s\n" ,Sale.rooms);
    fprintf(fp2, "%s\n" ,Sale.price);
    fprintf(fp2, "%s\n" ,Sale.year);
    fprintf(fp2, "%s\n" ,Sale.month);
    fprintf(fp2, "%s\n" ,Sale.day);
    fprintf(fp2, "%s\n" ,Sale.random);
    fprintf(fp2, "%s\n" ,Sale.active);
    fclose(fp2);

    printf("\n\nYou're succeeded\npress any key to back main menu");
    fpp2 = fopen("counter_user_for_admin.txt","a");
    if( (strcmp(admin,inputUser) != 0) && (strcmp(admin_password,inputpassword) != 0) )
        fprintf(fpp2, "This user has added a property for sale : \n");
    counter_user_for_admin();
    getche();
    if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
        admin_mainmenu();
    else
        mainmenu();



}
void counter_user_for_admin (void)
{

    fpp2 = fopen("counter_user_for_admin.txt","a");
    struct user{
        char user_name[50];
        char password[100];
        char name[50];
        char family_name[50];
        char user_code[20];
        char user_phone[20];
        char email[300];
        char year[10];
        char month[10];
        char day[10];
        struct user *link;
    };
    typedef struct user User;
    //p--->sare list q----->payane list
    User *p = NULL,*q=NULL;
    FILE *fp;
    fp = fopen("sign_up.txt","r");

    while(!feof(fp))
    {

    //Ejade gere jadid
    User *d;
    d = malloc(sizeof(User));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp,"%s\n",d->user_name);
    fscanf(fp,"%s\n",d->password);
    fscanf(fp,"%s\n",d->name);
    fscanf(fp,"%s\n",d->family_name);
    fscanf(fp,"%s\n",d->user_code);
    fscanf(fp,"%s\n",d->user_phone);
    fscanf(fp,"%s\n",d->email);
    fscanf(fp,"%s\n",d->year);
    fscanf(fp,"%s\n",d->month);
    fscanf(fp,"%s\n",d->day);

    if( (strcmp( d->user_name , inputUser ) == 0) && (strcmp( d->password , inputpassword ) == 0) )
    {

        fprintf(fpp2,"\nThe information of the users who entered the order of the property is : \n");
        fprintf(fpp2,"User name : %s\n",d->user_name);
        fprintf(fpp2,"Password : %s\n",d->password);
        fprintf(fpp2,"Name : %s\n",d->name);
        fprintf(fpp2,"Family Name : %s\n",d->family_name);
        fprintf(fpp2,"User Code : %s\n",d->user_code);
        fprintf(fpp2,"Phone Number : %s\n",d->user_phone);
        fprintf(fpp2,"Email : %s\n",d->email);
        fprintf(fpp2,"Year : %s\n",d->year);
        fprintf(fpp2,"month : %s\n",d->month);
        fprintf(fpp2,"day : %s\n",d->day);
        fprintf(fpp2,"\n\n");



    }


    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    free(q);
    }
    }
    //bastane file
    fclose(fp);
    fclose(fpp2);
    free(p);





}
void sale(void)
{
    system("cls");
    printf("welcome to Add new sale Tab\n\n");
    printf("1. Add new Residential property \n"); //melk maskoni
    printf("2. Add new Office property \n"); //melk edari
    printf("3. Add new Land \n"); //zamin
    printf("4. Back to new information Tab \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    char four[]= {'4' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        Residential_property();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        Office_property();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        land();
    }
    if( strcmp(choice , four) == 0){
        counter++;
        new_information();
    }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        sale();

    }



}
void new_information(void)
{
    system("cls");
    printf("welcome to Add new information Tab\n\n");
    printf("1. Add new sale \n");
    printf("2. Add new rent \n");
    printf("3. Back to main menu \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        sale();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        rent();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        if( (strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0) )
            admin_mainmenu();
        else
            mainmenu();
    }
    if( counter == 0 )
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        new_information();

    }


}
void mainmenu(void)
{
    system("cls");
    printf("welcome to main menu\n\n");
    printf("1. Add new information \n");
    printf("2. Delete information \n");
    printf("3. Reports \n");
    printf("4. Account settings \n");
    printf("5. log out \n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[0];
    scanf("%s" ,&choice);
    if(choice[0] == '1')
        new_information();
    if(choice[0] == '2')
        delete_information();
    if(choice[0] == '3')
        reports();
    if(choice[0] == '4')
        settings();
    if(choice[0] == '5')
        welcome();
    if( (choice[0] != '1') && (choice[0] != '2') && (choice[0] != '3') && (choice[0] != '4') && (choice[0] != '5'))
    {
        printf("\nplease try again because your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        mainmenu();
    }




}
void signup(void)
{
    system("cls");
    printf("welcome to sign up menu\n\n");
    struct user{
        char user_name[50];
        char password[100];
        char password2[100];
        char name[50];
        char family_name[50];
        char user_code[20];
        char user_phone[20];
        char email[300];
        char year[10];
        char month[10];
        char day[10];

    };
    struct user User;
    FILE *fp;
    fp=fopen("sign_up.txt" , "a");
    int i;
    printf("please Enter user name and next press Enter : ");
    fflush(stdin);
    gets(User.user_name);
    int length1 = strlen (User.user_name);
    for (i=0 ; i<length1 ; i++)
    {
        if (User.user_name[i] == ' ' )
        {
            printf("\n\nYour password is incorrect, please sign up again carefully and don't Enter space when you enter user name ");
            printf("\npress any key");
            getche();
            welcome();
        }
    }
    printf("please Enter user password and next press Enter : ");
    fflush(stdin);
    gets(User.password);
    if ( strlen(User.password) < 8) {
        printf("\n\nPassword should be more than 8 characters\n");
        printf("\n\nYour password is incorrect,if you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();
    }
    printf("please Enter user password again and next press Enter : ");
    fflush(stdin);
    gets(User.password2);
    if(strcmp(User.password2 , User.password )!=0){
        printf("\n\nYour password is incorrect,if you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();

    }

    printf("please Enter Name and next press Enter : ");
    fflush(stdin);
    gets(User.name);
    int length2 = strlen (User.name);
    for (i=0 ; i<length2 ; i++)
    {
        if (User.name[i] == ' ' )
        {
            User.name[i] = '-';
        }
    }
    printf("please Enter family name and next press Enter : ");
    fflush(stdin);
    gets(User.family_name);
    int length3 = strlen (User.family_name);
    for (i=0 ; i<length3 ; i++)
    {
        if (User.family_name[i] == ' ' )
        {
            User.family_name[i] = '-';
        }
    }
    printf("please Enter user code and next press Enter : ");
    fflush(stdin);
    gets(User.user_code);
    int length4= strlen (User.user_code);
    for (i=0 ; i<length4 ; i++)
    {
        if (User.user_code[i] == ' ' )
        {
            User.user_code[i] = '-';
        }
    }
    if ( strlen(User.user_code) != 10) {
        printf("\n\nUser code should be has 10 characters\n");
        printf("\n\nif you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();
    }
    printf("please Enter user phone number and next press Enter : ");
    fflush(stdin);
    gets(User.user_phone);
    int length5= strlen (User.user_phone);
    for (i=0 ; i<length5 ; i++)
    {
        if (User.user_phone[i] == ' ' )
        {
            User.user_phone[i] = '-';
        }
    }
    if ( strlen(User.user_phone) != 11) {
        printf("\n\nUser phone should be has 11 characters\n");
        printf("\n\nif you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();
    }
    printf("please Enter user email and next press Enter : ");
    fflush(stdin);
    gets(User.email);
    int length6= strlen (User.email);
    for (i=0 ; i<length6 ; i++)
    {
        if (User.email[i] == ' ' )
        {
            User.email[i] = '-';
        }
    }
    if ( strlen(User.email) < 12) {
        printf("\n\email should be more than 12 characters\n");
        printf("\n\nYour email is incorrect,if you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();
    }
    printf("please Enter the date of arrival this information, we start from the year and next press Enter : ");
    fflush(stdin);
    gets(User.year);
    int lengthyear= strlen (User.year);
    for (i=0 ; i<lengthyear ; i++)
    {
        if (User.year[i] == ' ' )
        {
            User.year[i] = '-';
        }
    }
     if ( strlen(User.year) != 4) {
        printf("\n\year should be has 4 characters\n");
        printf("\n\nYour year is incorrect,if you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();
    }
    printf("Now Enter the month and next press Enter : ");
    fflush(stdin);
    gets(User.month);
    int lengthmonth= strlen (User.month);
    for (i=0 ; i<lengthmonth ; i++)
    {
        if (User.month[i] == ' ' )
        {
            User.month[i] = '-';
        }
    }
    if ( strlen(User.month) > 2) {
        printf("\n\month should be has 2 or less than 2 characters\n");
        printf("\n\nYour month is incorrect,if you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();
    }
    printf("Now Enter the day and next press Enter : ");
    fflush(stdin);
    gets(User.day);
    int lengthday= strlen (User.day);
    for (i=0 ; i<lengthday ; i++)
    {
        if (User.day[i] == ' ' )
        {
            User.day[i] = '-';
        }
    }
    if ( strlen(User.day) > 2) {
        printf("\n\day should be has 2 or less than 2 characters\n");
        printf("\n\nYour day is incorrect,if you like please sign up again carefully later");
        printf("\npress any key");
        getche();
        welcome();
    }



    printf("\n\n");
    fprintf(fp, "%s\n" , User.user_name);
    fprintf(fp, "%s\n" , User.password);
    fprintf(fp, "%s\n" , User.name);
    fprintf(fp, "%s\n" , User.family_name);
    fprintf(fp, "%s\n" , User.user_code);
    fprintf(fp, "%s\n" , User.user_phone);
    fprintf(fp, "%s\n" , User.email);
    fprintf(fp, "%s\n" , User.year);
    fprintf(fp, "%s\n" , User.month);
    fprintf(fp, "%s\n" , User.day);
    fclose(fp);
    printf("\n\nYou succeeded");
    printf("\npress any key");
    getche();
    welcome();





}
void login(void)
{
    system("cls");
    printf("welcome to log in menu\n\n");
    struct user{
        char user_name[50];
        char password[100];
        char password2[100];
        char name[50];
        char family_name[50];
        char user_code[20];
        char user_phone[20];
        char email[300];
        char year[10];
        char month[10];
        char day[10];
        struct user *link;
    };
    typedef struct user User;
    //p--->sare list q----->payane list
    User *p = NULL,*q=NULL;
    FILE *fp;
    fp = fopen("sign_up.txt","r");

    while(!feof(fp))
    {

    //Ejade gere jadid
    User *d;
    d = malloc(sizeof(User));

    //gharar dadane etelaat dar gere sakhte shode
    fscanf(fp,"%s\n",d->user_name);
    fscanf(fp,"%s\n",d->password);
    fscanf(fp,"%s\n",d->name);
    fscanf(fp,"%s\n",d->family_name);
    fscanf(fp,"%d\n",d->user_code);
    fscanf(fp,"%d\n",d->user_phone);
    fscanf(fp,"%s\n",d->email);
    fscanf(fp,"%s\n",d->year);
    fscanf(fp,"%s\n",d->month);
    fscanf(fp,"%s\n",d->day);

    d->link = NULL;

    //agar avvalin list bud
    if (p == NULL){
    // p va q ra barabare d gharat midahim
    p = d;
    q = p;
    }
    else
    {
    //d ra be akhare list ezafe mikonim
    q->link = d;
    q = d;
    }
    }
    //bastane file
    fclose(fp);

    printf("\nNow time to login please Enter your user name and password");
    printf("\n\nUsername : ");
    scanf("%s", &inputUser);
    printf("\n\npassword : ");

    int j = 0;
    char ch;



    while(1) {
        ch = _getch();

        if(ch == 13) // 13 is the ASCII value of the Enter key
            break;

        printf("*");
        inputpassword[j] = ch;
        j++;
    }

    inputpassword[j] = '\0'; // Null-terminate the password string
    //gere' jadid
    User *d;
    //gharar dadan dar avvale list
    d = p;
    int c=0;

    //tarif admin





    while(d!=NULL)
    {
    if ((strcmp(inputUser,d->user_name) == 0) && (strcmp(inputpassword,d->password) == 0))
    {
     mainmenu();
     c++;
    }
    if((strcmp(admin,inputUser) == 0) && (strcmp(admin_password,inputpassword) == 0))
    {
        admin_mainmenu();
        c++;



    }


    //raftan be liste ba'di
    d = d->link;
    }

    if(c==0)
    {

    printf("\n\nthe user is not founded or the password is incorrect please try again");
    printf("\n\nIf you have not sign up, please sign up first");
    printf("\npress any key to back welcome screen");
    getche();
    welcome();
    }



}
void welcome(void)
{
    system("cls");
    printf("welcome to our program \n\n");
    printf("1. sign up \n");
    printf("2. log in \n");
    printf("3. exit\n");
    printf("\n\n\n>> please enter your choice : ");
    char choice[10];
    int counter=0;
    char one[]= {'1' , '\0'};
    char two[]= {'2' , '\0'};
    char three[]= {'3' , '\0'};
    scanf("%s" ,&choice);
    if( strcmp(choice , one) == 0){
        counter++;
        signup();
    }
    if( strcmp(choice , two) == 0){
        counter++;
        login();
    }
    if( strcmp(choice , three) == 0){
        counter++;
        system("cls");
        printf("I hope you enjoy this program see you soon");
        printf("\n\npress any key to close");
        getche();
        exit(1);
    }
     if( counter == 0 ) //age karbar kerm dasht
    {
        printf("\nplease try again your choice is not correct");
        printf("\n\npress any key to try again");
        getche();
        system("cls");
        welcome();
    }



}
void main()
{
    welcome();
    printf("\n\n\n\n\n\n\npress any key to close");
    getche();




}

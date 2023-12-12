#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void addRecord();
void viewRecord();
void editRecord();
void searchRecord();
void deleteRecord();
void login();
int toupper(int ch);

struct record
{
    char id[20];
    char name[20];
    int  age;
    char gender;
    char blood[10];
    char site[20];
    char emergencyc[20];
    char doctor[20];
    char vaccine[20];
    char contactName[20];
    int  contactAge;
    char contactEmergency[20];
    char contactRelationship[20];
    char reporterName[20];
    char reporterEmergency[20];
    char reporterRelationship[20];
    char testName[20];
    char testDate[20];
    char result;
    int dd,mm,yy;
    int dd1, mm1, yy1;
    int dd2, mm2, yy2;
    int dd3, mm3, yy3;


}pt;


int main()
{
    system("color   F5");
	login();

    int ch;
    printf("\n\n\t********************************************\n");
    printf("\t\t*QUARANTINE MANAGEMENT SYSTEM*\n");
    printf("\t********************************************");

    while(1)
    {

        printf("\n\n\t\tMAIN MENU:");
        printf("\n\n\tADD RECORD\t[1]");
        printf("\n\tSEARCH RECORD\t[2]");
        printf("\n\tEDIT RECORD\t[3]");
        printf("\n\tVIEW RECORD\t[4]");
		printf("\n\tDELETE RECORD\t[5]");
        printf("\n\tEXIT\t\t[6]");
        printf("\n\n\tENTER YOUR CHOICE:");
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            addRecord();
            break;

        case 2:
            searchRecord();
            break;

        case 3:
            editRecord();
            break;

        case 4:
            viewRecord();
            break;

        case 5:
            deleteRecord();
            break;

        case 6:
        	system("cls");
        	printf("\n\n\t\t\t\t*********************************************");
        	printf("\n\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>");
            printf("\n\n\t\t\t\tThanks for using Quarantine Management System");
            printf("\n\n\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<");
            printf("\n\n\t\t\t\t*********************************************");
            getch();
            exit(0);

        default:
            printf("\nYOU ENTERED WRONG CHOICE.");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            return 0;



        }

        system("cls");

    }
    return 0;

}


void addRecord( )

{


    system("cls");
    FILE *fp1 ;
    char another = 'Y' ,id[10];
    char filename[30];
    int choice;
    int len=0;
    int len1=0;
    int len2=0;
    int len3=0;
    int a=0;
    int b=0;
    int p=0;
    int q=0;

            printf("\n\n\t\t***************************\n");
            printf("\t\t* WELCOME TO THE ADD MENU *");
            printf("\n\t\t***************************\n\n");
            printf("\n\n");
            printf("\tENTER FIRST NAME OF PATIENT                        : ");
            fflush(stdin);
            gets(filename);
            fp1 = fopen ("filename", "ab+" ) ;

    if ( fp1 == NULL )
    {

        fp1=fopen("filename","wb+");
        if(fp1==NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();

        }
    }

    while (another == 'Y'|| another=='y')

    {
        choice=0;
        fflush(stdin);

            do
            {
            printf ("\tENTER PATIENT'S ID NUMBER(ex:-333)                 : ");
            scanf("%s",&id);
            len2 = strlen(id);
            rewind(fp1);
            }while(len2 != 3);

        while(fread(&pt,sizeof(pt),1,fp1)==1)
        {
            if(strcmp(pt.id,id)==0)
            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;

            }

        }


        if(choice==0)
        {

             strcpy(pt.id,id);
             printf("\n");
             printf("\tEnter the full name of the patient                 : ");
             fflush(stdin);
             gets(pt.name);

             do
             {
                printf("\tEnter the gender of the patient(M.male / F.female) : ");
                scanf(" %c", &pt.gender);
                pt.gender = toupper(pt.gender);
                fflush(stdin);

              }while(!(pt.gender == 'M' || pt.gender =='F'));




            do
             {
             printf("\tEnter the age of the patient                       : ");
             scanf("%d", &pt.age);
             fflush(stdin);
             }while(16>pt.age || pt.age>120);


             printf("\tEnter the Blood group of the patient               : ");
             gets(pt.blood);
             fflush(stdin);

             printf("\tExposure sites of the patient                      : ");
             gets(pt.site);
             fflush(stdin);



             do
             {

             b = 0;
             printf("\tEnter symptoms onset date(dd/mm/yyyy)              : ");
             scanf("%d/%d/%d",&pt.dd1,&pt.mm1,&pt.yy1);


              if(pt.yy1>=2000 && pt.yy1<=2100)
                {
                 if(pt.mm1>=1 && pt.mm1<=12)
                 {
                     if(pt.dd1>=1 && pt.dd1<=31)
                        {
                            b =1;
                        }
                 }
                }
               fflush(stdin);
             }while(b!=1);


            do
             {
             printf("\tPatient's phone number                             : ");
             gets(pt.emergencyc);
             len3 = strlen(pt.emergencyc);
             fflush(stdin);
             }while(len3 != 10);

             printf("\tEnter the name of the Doctor being referred        : ");
             gets(pt.doctor);
             fflush(stdin);



             printf("\tVaccine name(if not N/A)                           : ");
             gets(pt.vaccine);
             fflush(stdin);


             do
             {

             p = 0;
             printf("\tEnter vaccinated date(dd/mm/yyyy)                  : ");
             scanf("%d/%d/%d",&pt.dd2,&pt.mm2,&pt.yy2);


              if(pt.yy2>=2000 && pt.yy2<=2100)
                {
                 if(pt.mm2>=1 && pt.mm2<=12)
                 {
                     if(pt.dd2>=1 && pt.dd2<=31)
                        {
                            p =1;
                        }
                 }
                }
               fflush(stdin);
             }while(p!=1);





             printf("\n\t*********************DISEASE CONTACT***************************\n");

             printf("\tDisease contact name                               : ");
             gets(pt.contactName);
             fflush(stdin);

             do
             {
             printf("\tDisease contact age                                : ");
             scanf("%d", &pt.contactAge);
             fflush(stdin);
             }while(16>pt.contactAge || pt.contactAge>120);

             do
             {
             printf("\tDisease contact phone number                       : ");
             gets(pt.contactEmergency);
             len1 = strlen(pt.contactEmergency);
             fflush(stdin);
             }while(len1 != 10);


             printf("\tRelationship to patient                            : ");
             gets(pt.contactRelationship);
             fflush(stdin);

             printf("\n\t**************************Reporter*****************************\n");

             printf("\tReporter's name                                    : ");
             gets(pt.reporterName);
             fflush(stdin);

             do
             {
             printf("\tReporter's phone number                            : ");
             gets(pt.reporterEmergency);
             len = strlen(pt.reporterEmergency);
             fflush(stdin);
             }while(len != 10);

             printf("\tRelationship to patient                            : ");
             gets(pt.reporterRelationship);
             fflush(stdin);

             printf("\n\t*******************LABORATORY INFORMATION**********************\n");

             printf("\tTest name                                          : ");
             gets(pt.testName);
             fflush(stdin);

            do
             {
                 q = 0;
             printf("\tTest date(dd/mm/yyyy)                              : ");
             scanf("%d/%d/%d",&pt.dd3,&pt.mm3,&pt.yy3);

             if(pt.yy3>=2000 && pt.yy3<=2100)
             {
                 if(pt.mm3>=1 && pt.mm3<=12)
                 {
                     if(pt.dd3>=1 && pt.dd3<=31)
                        {
                           q =1;
                        }
                 }
             }
             fflush(stdin);
             }while(q != 1);

             do
             {

              printf("\tResult                                             : ");
              scanf(" %c", &pt.result);
              pt.result = toupper(pt.result);

               }while(!(pt.result == 'P' || pt.result =='N'));


            do
             {
                 a = 0;
             printf("\tResult date(dd/mm/yyyy)                            : ");
             scanf("%d/%d/%d",&pt.dd,&pt.mm,&pt.yy);

             if(pt.yy>=2000 && pt.yy<=2100)
             {
                 if(pt.mm>=1 && pt.mm<=12)
                 {
                     if(pt.dd>=1 && pt.dd<=31)
                        {
                           a =1;
                        }
                 }
             }
             fflush(stdin);
             }while(a != 1);






            fwrite ( &pt, sizeof ( pt ), 1, fp1 ) ;
            printf("\nYOUR RECORD IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        fflush (stdin) ;
        another = getch( ) ;

    }

    fclose ( fp1 ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}


void searchRecord( )

{
	system("cls");
    FILE *fp1 ;
	char id[10],choice,filename[14];
    int ch;


    printf("\n\n\t\t*******************************\n");
    printf("\t\t* HERE IS THE SEARCHING MENU *");
    printf("\n\t\t*******************************\n\n");

    do
        {

		printf("\n\tENTER PATIENT NAME TO BE SEARCHED          : ");
        fflush(stdin);
        gets(filename);

        fp1 = fopen ( "filename", "rb" ) ;


        printf("\n\tENTER PATIENT ID NO                        : ");
            gets(id);
            system("cls");
            printf("\nTHE WHOLE RECORD IS:");
     while ( fread ( &pt, sizeof ( pt ), 1, fp1 ) == 1 )

          {
          if(strcmpi(pt.id,id)==0)
               {printf("\n");
                printf("\nPatient's name                  : %s",pt.name);
                printf("\nPatient's gender                : %c",pt.gender);
                printf("\nPatient's age                   : %d",pt.age);
                printf("\nPatient's blood group           : %s",pt.blood);
                printf("\nExposure site of the patient    : %s",pt.site);
                printf("\nSymptoms on set date            : %02d/%02d/%04d",pt.dd1, pt.mm1, pt.yy1);
                printf("\nPatient phone number            : %s", pt.emergencyc);
                printf("\nName of the Doctor referred     : %s",pt.doctor);
                printf("\nVaccine name                    : %s",pt.vaccine);
                printf("\nVaccinated date                 : %02d/%02d/%04d",pt.dd2, pt.mm2, pt.yy2);
                printf("\nContact name                    : %s",pt.contactName);
                printf("\nContact age                     : %d",pt.contactAge);
                printf("\nContact phone number            : %s",pt.contactEmergency);
                printf("\nContact's relationship          : %s",pt.contactRelationship);
                printf("\nReporter name                   : %s",pt.reporterName);
                printf("\nReporter phone number           : %s",pt.reporterEmergency);
                printf("\nReporter's relationship         : %s",pt.reporterRelationship);
                printf("\nTest name                       : %s",pt.testName);
                printf("\nTest date                       : %02d/%02d/%04d",pt.dd3, pt.mm3, pt.yy3);
                printf("\nPatient result                  : %c",pt.result);
                printf("\nResult date                     : %02d/%02d/%04d",pt.dd, pt.mm, pt.yy);

                printf("\n");
            }

            }


        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fp1) ;
	getch();

    return ;

getch();
}

void editRecord()

{

    system("cls");
    FILE *fp1 ;
    char id[10],choice,filename[14];
    int num,count=0;
    int len=0;
    int len1=0;
    int len2=0;
    int len3=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int p=0;
    int q=0;

    printf("\n\n\t\t*******************************\n");
    printf("\t\t* WELCOME TO THE EDITING MENU *");
    printf("\n\t\t*******************************\n\n");

    do
    {

              printf("\nENTER PATIENT NAME TO BE EDITED : ");
              fflush(stdin);
              gets(filename);

              printf("\nENTER PATIENT ID                : ");
              gets(id);
              fp1 = fopen ( "filename", "rb+" ) ;



        while ( fread ( &pt, sizeof ( pt ), 1, fp1 ) == 1 )
        {

            if(strcmp(pt.id,id)==0)
            {

                printf("\nOLD RECORD WAS AS:");
                printf("\nPatient's name                  : %s",pt.name);
                printf("\nPatient's gender                : %c",pt.gender);
                printf("\nPatient's age                   : %d",pt.age);
                printf("\nPatient's blood group           : %s",pt.blood);
                printf("\nExposure site of the patient    : %s",pt.site);
                printf("\nSymptoms on set date            : %02d/%02d/%04d",pt.dd1, pt.mm1, pt.yy1);
                printf("\nPatient phone number            : %s", pt.emergencyc);
                printf("\nName of the Doctor referred     : %s",pt.doctor);
                printf("\nVaccine name                    : %s",pt.vaccine);
                printf("\nVaccinated date                 : %02d/%02d/%04d",pt.dd2, pt.mm2, pt.yy2);
                printf("\nContact name                    : %s",pt.contactName);
                printf("\nContact age                     : %d",pt.contactAge);
                printf("\nContact phone number            : %s",pt.contactEmergency);
                printf("\nContact's relationship          : %s",pt.contactRelationship);
                printf("\nReporter name                   : %s",pt.reporterName);
                printf("\nReporter phone number           : %s",pt.reporterEmergency);
                printf("\nReporter's relationship         : %s",pt.reporterRelationship);
                printf("\nTest name                       : %s",pt.testName);
                printf("\nTest date                       : %02d/%02d/%04d",pt.dd3, pt.mm3, pt.yy3);
                printf("\nPatient result                  : %c",pt.result);
                printf("\nResult date                     : %02d/%02d/%04d",pt.dd, pt.mm, pt.yy);





                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");



                printf("\n1.Name.");
                printf("\n2.Gender.");
                printf("\n3.Age.");
                printf("\n4.Blood group");
                printf("\n5.Exposure sites.");
                printf("\n6.Symptoms on set date.");
                printf("\n7.Patient phone number.");
                printf("\n8.Doctor referred to.");
                printf("\n9.Vaccine name.");
                printf("\n10.Vaccinated date.");
                printf("\n11.Contact name.");
                printf("\n12.Contact age.");
                printf("\n13.Contact's phone number.");
                printf("\n14.Contact relationship to patient.");
                printf("\n15.Reporter name.");
                printf("\n16.Reporter phone number.");
                printf("\n17.Reporter relationship to patient.");
                printf("\n18.Test name.");
                printf("\n19.Test date.");
                printf("\n20.Result.");
                printf("\n21.Result date.");
                printf("\n22.WHOLE RECORD.");
                printf("\n23.GO BACK TO MAIN MENU.");

                do
                {

                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);

                    switch(num)
                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nName:");
                        gets(pt.name);
                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");
                         do
                        {
                        printf("\nGender: ");
                        scanf(" %c", &pt.gender);
                        pt.gender = toupper(pt.gender);
                        fflush(stdin);

                        }while(!(pt.gender == 'M' || pt.gender =='F'));
                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");
                         do
                          {
                         printf("\nAge: ");
                         scanf("%d", &pt.age);
                         fflush(stdin);
                         }while(18>pt.age || pt.age>120);
                        break;

                  case 4:
                        printf("ENTER THE NEW DATA:");
                        printf("\nBlood group: ");
                        gets(pt.blood);
                        break;

                   case 5:
                        printf("ENTER THE NEW DATA:");
                        printf("\nExposure sites:");
                        gets(pt.site);
                        break;


                   case 6:
                        printf("ENTER THE NEW DATA:");
                        do
                        {

                         c = 0;
                          printf("\nSymptoms onset date: ");
                          scanf("%d/%d/%d",&pt.dd1,&pt.mm1,&pt.yy1);
                          fflush(stdin);

                          if(pt.yy1>=2000 && pt.yy1<=2100)
                           {
                             if(pt.mm1>=1 && pt.mm1<=12)
                              {
                                 if(pt.dd1>=1 && pt.dd1<=31)
                                   {
                                     c =1;
                                    }
                               }
                            }
                          }while(c!=1);
                          break;

                   case 7:
                        printf("ENTER THE NEW DATA:");
                        printf("\nPatient phone number: ");
                        gets(pt.emergencyc);
                        break;

                   case 8:
                        printf("ENTER THE NEW DATA:");
                        printf("\nName of the doctor referred to:");
                        gets(pt.doctor);
                        break;


                   case  9:
                         printf("ENTER THE NEW DATA:");
                         printf("\nVaccine name: ");
                         gets(pt.vaccine);
                         break;

                  case 10:
                         printf("ENTER THE NEW DATA:");
                          do
                         {
                             p = 0;
                          printf("\nVaccinated date: ");
                          scanf("%d/%d/%d",&pt.dd2,&pt.mm2,&pt.yy2);

                         if(pt.yy2>=2000 && pt.yy2<=2100)
                          {
                            if(pt.mm2>=1 && pt.mm2<=12)
                            {
                              if(pt.dd2>=1 && pt.dd2<=31)
                               {
                                 p =1;
                                }
                             }
                           }
                          fflush(stdin);
                          }while(p !=1);
                          break;


                    case 11:
                         printf("ENTER THE NEW DATA:");
                         printf("\nContact name: ");
                         gets(pt.contactName);
                         break;

                    case 12:
                         printf("ENTER THE NEW DATA:");
                        do
                         {
                           printf("\nDisease contact age: ");
                           scanf("%d", &pt.contactAge);
                           fflush(stdin);
                        }while(16>pt.contactAge || pt.contactAge>120);
                         break;

                    case 13:
                         printf("ENTER THE NEW DATA:");
                         do
                         {
                          printf("\nDisease contact phone number: ");
                          gets(pt.contactEmergency);
                          len1 = strlen(pt.contactEmergency);
                          fflush(stdin);
                          }while(len1 != 10);
                          break;




                   case 14:
                         printf("ENTER THE NEW DATA:");
                         printf("\nContact's relationship to the patient:");
                         gets(pt.contactRelationship);
                         break;

                    case 15:
                         printf("ENTER THE NEW DATA:");
                         printf("\nReporter name: ");
                         gets(pt.reporterName);
                         break;

                    case 16:
                         printf("ENTER THE NEW DATA:");
                         do
                        {
                         printf("\nReporter's phone number: ");
                         gets(pt.reporterEmergency);
                         len = strlen(pt.reporterEmergency);
                         fflush(stdin);
                         }while(len != 10);
                         break;

                    case 17:
                         printf("ENTER THE NEW DATA:");
                         printf("\nReporter relationship to the patient: ");
                         gets(pt.reporterRelationship);
                         break;

                    case 18:
                         printf("ENTER THE NEW DATA:");
                         printf("\nTest name: ");
                         gets(pt.testName);
                         break;

                    case 19:
                        printf("ENTER THE NEW DATA:");
                         do
                         {
                            q = 0;
                           printf("\tTest date(dd/mm/yyyy): ");
                           scanf("%d/%d/%d",&pt.dd3,&pt.mm3,&pt.yy3);

                          if(pt.yy3>=2000 && pt.yy3<=2100)
                          {
                           if(pt.mm3>=1 && pt.mm3<=12)
                           {
                              if(pt.dd3>=1 && pt.dd3<=31)
                               {
                                 q =1;
                                }
                            }
                          }
                          fflush(stdin);
                         }while(q != 1);
                         break;



                    case 20:
                         printf("ENTER THE NEW DATA:");
                           do
                         {

                         printf("\nResult: ");
                         scanf(" %c", &pt.result);
                         pt.result = toupper(pt.result);

                        }while(!(pt.result == 'P' || pt.result =='N'));

                         break;

                    case 21:
                         printf("ENTER THE NEW DATA:");
                         do
                         {
                             d = 0;
                          printf("\nResult date: ");
                          scanf("%d/%d/%d",&pt.dd,&pt.mm,&pt.yy);

                         if(pt.yy>=2000 && pt.yy<=2100)
                          {
                            if(pt.mm>=1 && pt.mm<=12)
                            {
                              if(pt.dd>=1 && pt.dd<=31)
                               {
                                 d =1;
                                }
                             }
                           }
                          fflush(stdin);
                          }while(d !=1);
                          break;


                    case 22:
                    	printf("ENTER THE NEW DATA:\n");
                        printf("\nName                     : ");
			            gets(pt.name);

                        do
                        {
                        printf("\nGender                   : ");
                        scanf(" %c", &pt.gender);
                        pt.gender = toupper(pt.gender);
                        fflush(stdin);

                        }while(!(pt.gender == 'M' || pt.gender =='F'));


                        do
                        {
                         printf("\nAge                     : ");
                         scanf("%d", &pt.age);
                         fflush(stdin);
                        }while(16>pt.age || pt.age>120);

                        printf("\nBlood group              : ");
			            gets(pt.blood);

			            printf("\nExposure sites           : ");
			            gets(pt.site);

                        do
                        {
                        e = 0;
                        printf("\nSymptoms onset date      : ");
                        scanf("%d/%d/%d",&pt.dd1,&pt.mm1,&pt.yy1);
                        fflush(stdin);

                          if(pt.yy1>=2000 && pt.yy1<=2100)
                           {
                             if(pt.mm1>=1 && pt.mm1<=12)
                              {
                                 if(pt.dd1>=1 && pt.dd1<=31)
                                   {
                                     e =1;
                                    }
                               }
                            }
                          }while(e!=1);

                        do
                        {
                          printf("\nPatient's phone number: ");
                          gets(pt.emergencyc);
                          len3 = strlen(pt.emergencyc);
                          fflush(stdin);
                        }while(len3 != 10);

                        printf("\nName of doctor referred to: ");
			            gets(pt.doctor);

                        printf("\nVaccine name             : ");
			            gets(pt.vaccine);

			            do
                        {

                         p = 0;
                         printf("\nEnter vaccinated date(dd/mm/yyyy): ");
                        scanf("%d/%d/%d",&pt.dd2,&pt.mm2,&pt.yy2);


                        if(pt.yy2>=2000 && pt.yy2<=2100)
                         {
                         if(pt.mm2>=1 && pt.mm2<=12)
                         {
                        if(pt.dd2>=1 && pt.dd2<=31)
                             {
                            p =1;
                              }
                           }
                         }
                        fflush(stdin);
                        }while(p!=1);

                        printf("\nContact name             : ");
                        gets(pt.contactName);
                        do
                        {
                        printf("\nDisease contact age      : ");
                        scanf("%d", &pt.contactAge);
                        fflush(stdin);
                        }while(16>pt.contactAge || pt.contactAge>120);

                        do
                        {
                         printf("\nDisease contact phone number: ");
                         gets(pt.contactEmergency);
                         len1 = strlen(pt.contactEmergency);
                         fflush(stdin);
                        }while(len1 != 10);



                        printf("\nContact's relationship   : ");
                        gets(pt.contactRelationship);
                        printf("\nReporter name            : ");
                        gets(pt.reporterName);

                        printf("\nReporter name: ");
                        gets(pt.reporterName);

                        do
                        {
                        printf("\nReporter's phone number  : ");
                        gets(pt.reporterEmergency);
                        len = strlen(pt.reporterEmergency);
                        fflush(stdin);
                        }while(len != 10);

                        printf("\nReporter's relationship  : ");
                        gets(pt.reporterRelationship);
                        printf("\nTest name                : ");
                        gets(pt.testName);

                        do
                        {
                         q = 0;
                         printf("\nTest date(dd/mm/yyyy): ");
                         scanf("%d/%d/%d",&pt.dd,&pt.mm,&pt.yy);

                         if(pt.yy3>=2000 && pt.yy3<=2100)
                         {
                           if(pt.mm3>=1 && pt.mm3<=12)
                           {
                             if(pt.dd3>=1 && pt.dd3<=31)
                               {
                                 q =1;
                               }
                            }
                          }
                           fflush(stdin);
                          }while(q != 1);


                        do
                        {
                        printf("\nResult                   : ");
                        scanf(" %c", &pt.result);
                        pt.result = toupper(pt.result);

                        }while(!(pt.result == 'P' || pt.result =='N'));


                        do
                         {
                         f = 0;
                         printf("\nResult date              : ");
                         scanf("%d/%d/%d",&pt.dd,&pt.mm,&pt.yy);

                         if(pt.yy>=2000 && pt.yy<=2100)
                          {
                            if(pt.mm>=1 && pt.mm<=12)
                            {
                              if(pt.dd>=1 && pt.dd<=31)
                               {
                                 f =1;
                                }
                             }
                           }
                          fflush(stdin);
                          }while(f !=1);
                          break;


                    case 23:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        break;

                    }

                }
                while(num<1||num>23);

                fseek(fp1,-sizeof(pt),SEEK_CUR);

                fwrite(&pt,sizeof(pt),1,fp1);

                fseek(fp1,-sizeof(pt),SEEK_CUR);

                fread(&pt,sizeof(pt),1,fp1);

                choice=5;

                break;

            }
        }

        if(choice==5)

        {

            system("cls");

                printf("\n\t\tEDITING COMPLETED...\n");
                printf("--------------------\n");
                printf("THE NEW RECORD IS:\n");
                printf("--------------------\n");

                printf("\nPatient's name                  : %s",pt.name);
                printf("\nPatient's gender                : %c",pt.gender);
                printf("\nPatient's age                   : %d",pt.age);
                printf("\nPatient's blood group           : %s",pt.blood);
                printf("\nExposure site of the patient    : %s",pt.site);
                printf("\nSymptoms on set date            : %02d/%02d/%04d",pt.dd1, pt.mm1, pt.yy1);
                printf("\nPatient phone number            : %s", pt.emergencyc);
                printf("\nName of the Doctor referred     : %s",pt.doctor);
                printf("\nVaccine name                    : %s",pt.vaccine);
                printf("\nVaccinated date                 : %02d/%02d/%04d",pt.dd2, pt.mm2, pt.yy2);
                printf("\nContact name                    : %s",pt.contactName);
                printf("\nContact age                     : %d",pt.contactAge);
                printf("\nContact phone number            : %s",pt.contactEmergency);
                printf("\nContact's relationship          : %s",pt.contactRelationship);
                printf("\nReporter name                   : %s",pt.reporterName);
                printf("\nReporter phone number           : %s",pt.reporterEmergency);
                printf("\nReporter's relationship         : %s",pt.reporterRelationship);
                printf("\nTest name                       : %s",pt.testName);
                printf("\nTest date                       : %02d/%02d/%04d",pt.dd3, pt.mm3, pt.yy3);
                printf("\nPatient result                  : %c",pt.result);
                printf("\nResult date                     : %02d/%02d/%04d",pt.dd, pt.mm, pt.yy);





            fclose(fp1);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N): ");
            scanf(" %c",&choice);
            fflush(stdin);
            count++;

        }
        else
        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
        	scanf(" %c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp1 ) ;
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();

}

void viewRecord()

{
    system("cls");
    FILE *fp1;
    char filename[30];

    printf("\n\n\t\t***************************\n");
    printf("\t\t   * LIST OF PATIENTS *");
    printf("\n\t\t***************************\n\n");

    fp1=fopen("filename","rb");
    rewind(fp1);
    while((fread(&pt,sizeof(pt),1,fp1))==1)
    {
    	        printf("||NOTE:-PRESS ENTER KEY TO LOAD OTHER RECORDS||\n");
                 printf("\nOLD RECORD WAS AS:");
                printf("\nPatient's name                  : %s",pt.name);
                printf("\nPatient's gender                : %c",pt.gender);
                printf("\nPatient's age                   : %d",pt.age);
                printf("\nPatient's blood group           : %s",pt.blood);
                printf("\nExposure site of the patient    : %s",pt.site);
                printf("\nSymptoms on set date            : %02d/%02d/%04d",pt.dd1, pt.mm1, pt.yy1);
                printf("\nPatient phone number            : %s", pt.emergencyc);
                printf("\nName of the Doctor referred     : %s",pt.doctor);
                printf("\nVaccine name                    : %s",pt.vaccine);
                printf("\nVaccinated date                 : %02d/%02d/%04d",pt.dd2, pt.mm2, pt.yy2);
                printf("\nContact name                    : %s",pt.contactName);
                printf("\nContact age                     : %d",pt.contactAge);
                printf("\nContact phone number            : %s",pt.contactEmergency);
                printf("\nContact's relationship          : %s",pt.contactRelationship);
                printf("\nReporter name                   : %s",pt.reporterName);
                printf("\nReporter phone number           : %s",pt.reporterEmergency);
                printf("\nReporter's relationship         : %s",pt.reporterRelationship);
                printf("\nTest name                       : %s",pt.testName);
                printf("\nTest date                       : %02d/%02d/%04d",pt.dd3, pt.mm3, pt.yy3);
                printf("\nPatient result                  : %c",pt.result);
                printf("\nResult date                     : %02d/%02d/%04d",pt.dd, pt.mm, pt.yy);


        getch();
     printf("\n\n");

    }
    fclose(fp1);
	getch();

}


void deleteRecord( )

{

    system("cls");
    FILE *fp1,*ft ;
    struct record file ;
    char filename[15],another = 'Y' ,id[16];;
    int choice,check;
    int j=0;
    char pass[8];

    printf("\n\n\t\t*************************\n");
    printf("\t\t* WELCOME TO DELETE MENU*");
    printf("\n\t\t*************************\n\n");


   while ( another == 'Y' || another == 'y' )

    {

    	          printf("\n\tENTER THE NAME OF PATIENT TO BE DELETED:");
		          fflush(stdin);
                  gets(filename);
                  fp1 = fopen ("filename", "rb" ) ;
                  if ( fp1 == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft=fopen("temp","wb");

				if(ft==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\n\tENTER THE ID OF RECORD TO BE DELETED   :");
                fflush(stdin);
                gets(pt.id);

        		while(fread(&file,sizeof(file),1,fp1)==1)

                {

                    if(strcmp(file.id,id)!=0)

                        fwrite(&file,sizeof(file),1,ft);

                }
        fclose(ft);
        fclose(fp1);
        remove("filename");
        rename("temp","filename");
        printf("\nDELETED SUCCESFULLY...");
        getch();

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);

    }


    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();


}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n\n\n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
    printf("\n\n\n\t\t*************************************************\n");
	printf("  \n\n      WELCOME TO QUARANTINE MANAGEMENT SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t*************************************************\n");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong user name and password for four times!!!");

		getch();

		}
		system("cls");
}







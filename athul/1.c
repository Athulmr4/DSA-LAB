#include<stdio.h>
#include<stdlib.h>
struct Day
{
char* dayname;
int date;
char* activitydescription;
};
struct Day* createday()
{
struct Day* newday=(struct Day*)malloc(sizeof(struct Day));
newday->dayname=(char*)malloc(sizeof(char));
newday->activitydescription=(char*)malloc(sizeof(char));
printf("enter day name");
scanf("%s",newday->dayname);
printf("enter date");
scanf("%d",&(newday->date));
printf("enter activity description");
scanf(" %[^\n]",newday->activitydescription);
return newday;
}
void read(struct Day* calender[],int size)
{
for(int i=0;i<size;i++)
{
printf("enter details for day %d:\n",i+1);
calender[i]=createday();
}

void display(struct Day* calender[], int size)
{
printf("\nWeek's Activity Details:\n");
for(int i=0;i<size;i++)
{
printf("day %d:\n",i+1);
printf("day name:%s\n",calender[i]->dayname);
printf("date:%d\n",calender[i]->date);
printf("activity description:%s\n",calender[i]->activitydescription);
printf("\n");
}
}
void freememory(struct Day* calender[],int size)
{
for(int i=0;i<size;i++)
{
free(calender[i]->dayname);
free(calender[i]->activitydescription);
free(calender[i]);
}
}
int main()
{
struct Day* week[7];
read(week,7);
display(week,7);
freememory(week,7);
return 0;
}
}

#include "SDB.h"
Bool SDB_IsFull() // Check if the database is full
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (students[i].Student_ID == 0)
        {
            counter++;
        }
    }
    if (counter < 10)
    {
        return False;
    }
    else
    {
        return True;
    }
}

uint8 SDB_GetUsedSize() 

{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (students[i].Student_ID != 0)
        {
            counter++;
        }
    }
    return counter;
}

Bool SDB_AddEntry()
{
    Bool correctData = False;
    int i = 0;
    Bool added = False;
    Bool zeroflag = False;
    while (students[i].Student_ID != 0)
    {
        i++;
    }
    int id;
    printf("\nEnter Student ID : ");
    scanf("%d", &id);
    while (!zeroflag)
    {
        Bool zero = False;
        if (id <= 0)
        {
            printf("\nID less than or equal zero");
            zero = True;
        }
        if (zero)
        {
            printf("\nEnter ID Again : ");
            scanf("%d", &id);
        }
        else
        {
            students[i].Student_ID = id;
            zeroflag = True;
        }
    }

    while (!added)
    {

        Bool found = False;
        for (int j = 0; j < 10; j++)
        {
            if (id == students[j].Student_ID)
            {
                printf("\nID already exists");
                found = True;
                break;
            }
        }
        if (found)
        {
            printf("\nEnter New ID :");
            scanf("%d", &id);
        }
        else
        {
            students[i].Student_ID = id;
            added = True;
        }
    }
    printf("\n%d", students[i].Student_ID);
    printf("\nEnter Student Year : ");
    scanf("%d", &students[i].Student_Year);
    printf("\nEnter Course 1 ID : ");
    scanf("%d", &students[i].Course1_ID);
    printf("\nEnter Course 1 Grade : ");
    scanf("%d", &students[i].Course1_Grade);
    printf("\nEnter Course 2 ID : ");
    scanf("%d", &students[i].Course2_ID);
    Bool same = False;
    while (!same)
    {
        if (students[i].Course1_ID == students[i].Course2_ID)
        {
            printf("\nCourse is already added");
            printf("%d", students[i].Course2_ID);
            printf("\nEnter Course 2 ID : ");
            scanf("%d", &students[i].Course2_ID);
        }
        else
        {
            same = True;
        }
    }
    printf("\nEnter Course 2 Grade : ");
    scanf("%d", &students[i].Course2_Grade);
    printf("\nEnter Course 3 ID : ");
    scanf("%d", &students[i].Course3_ID);
    same = False;
    while (!same)
    {
        if (students[i].Course3_ID == students[i].Course2_ID || students[i].Course3_ID == students[i].Course1_ID)
        {
            printf("\nCourse is already added");
            printf("%d", students[i].Course3_ID);
            printf("\nEnter Course 3 ID : ");
            scanf("%d", &students[i].Course3_ID);
        }
        else
        {
            same = True;
        }
    }
    printf("\nEnter Course 3 Grade : ");
    scanf("%d", &students[i].Course3_Grade);
    return True;
}

void SDB_DeleteEntry(uint32 id)
{
    Bool found = False;
    for (int i = 0; i < 10; i++)
    {
        if (id == students[i].Student_ID)
        {
            students[i] = DefaultSTD;
            found = True;
            printf("\n%d", i);
        }
    }
    if (!found)
    {
        printf("\nStudent doesn't exist");
    }
}

Bool SDB_ReadEntry(uint32 id)
{
    Bool found = False;
    for (int i = 0; i < 10; i++)
    {
        if (id == students[i].Student_ID)
        {
            printf("\nYear: %d", students[i].Student_Year);
            printf("\nCourse 1 ID : %d", students[i].Course1_ID);
            printf("\nCourse 1 Grade : %d", students[i].Course1_Grade);
            printf("\nCourse 2 ID : %d", students[i].Course2_ID);
            printf("\nCourse 2 Grade : %d", students[i].Course2_Grade);
            printf("\nCourse 3 ID : %d", students[i].Course3_ID);
            printf("\nCourse 3 Grade : %d", students[i].Course3_Grade);
            printf("\nCourse 1 ID : %d", students[i].Course1_ID);
            found = True;
            return True;
        }
    }
    if (!found)
    {
        printf("\nStudent does not exist");
        return False;
    }
}

void SDB_GetList(uint8 *count, uint32 *list)
{
}

Bool SDB_IsIdExist(uint32 id)
{
    Bool found = False;
    for (int i = 0; i < 10; i++)
    {
        if (id == students[i].Student_ID)
        {
            found = True;
            return True;
        }
    }
    if (!found)
        printf("This ID does not exist");
    found = True;
    return False;
}

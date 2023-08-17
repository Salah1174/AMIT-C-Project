#include "SDB.h"
Bool SDB_IsFull() // Check if the database is full
{
    uint8 counter = 0;
    for (uint8 i = 0; i < 10; i++)
    {
        if (students[i].Student_ID == 0)
        {
            counter++;
        }
    }
    if (counter <= 10)
    {
        return False;
    }
    else
    {
        return True;
    }
}

uint8 SDB_GetUsedSize() // Get Used Size of Database

{
    uint8 counter = 0;
    for (uint8 i = 0; i < 10; i++)
    {
        if (students[i].Student_ID != 0)
        {
            counter++;
        }
    }
    return counter;
}

Bool SDB_AddEntry() // Add Student to Database
{
    Bool correctData = False;

    uint8 i = 0;

    Bool added = False; // Flag to check if ID is already used for a student

    Bool zeroflag = False; // Flag to Check if value entered is zero or less than

    while (students[i].Student_ID != 0) // Search for first empty place in database
    {
        i++;
    }
    uint32 id;
    printf("\nEnter Student ID : ");
    scanf("%d", &id);
    while (!zeroflag) // Zero Check
    {
        Bool zero = False;
        if (id <= 0)
        {
            printf("\nID less than or equal zero");
            zero = True; // ID is zero or less than
        }
        if (zero)
        {
            printf("\nEnter ID Again : ");
            scanf("%d", &id);
        }
        else
        {

            zeroflag = True;
        }
    }

    while (!added) // ID Exist Check
    {

        Bool found = False;
        for (uint8 j = 0; j < 10; j++)
        {
            if (id == students[j].Student_ID)
            {
                printf("\nID already exists");
                found = True; // ID exist
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
    students[i].Student_ID = id;
    printf("\nEnter Student Year : ");
    scanf("%d", &students[i].Student_Year);
    printf("\nEnter Course 1 ID : ");
    scanf("%d", &students[i].Course1_ID);
    printf("\nEnter Course 1 Grade : ");
    scanf("%d", &students[i].Course1_Grade);
    printf("\nEnter Course 2 ID : ");
    scanf("%d", &students[i].Course2_ID);
    Bool same = False;
    while (!same) // Check if student add same course twice
    {
        if (students[i].Course1_ID == students[i].Course2_ID)
        {
            printf("\nCourse is already added");
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
    while (!same) // Check if student add same course twice
    {
        if (students[i].Course3_ID == students[i].Course2_ID || students[i].Course3_ID == students[i].Course1_ID)
        {
            printf("\nCourse is already added");
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

void SDB_DeleteEntry(uint32 id) // Delete Student from Database
{
    Bool found = False;
    for (uint8 i = 0; i < 10; i++)
    {
        if (id == students[i].Student_ID) // Check if student is in database
        {
            students[i] = DefaultSTD;
            found = True;
        }
    }
    if (!found)
    {
        printf("\nStudent doesn't exist");
    }
}

Bool SDB_ReadEntry(uint32 id) // Print Data of Student
{
    Bool found = False;
    for (uint8 i = 0; i < 10; i++)
    {
        if (id == students[i].Student_ID) // Check if student is in database
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

void SDB_GetList(uint8 *count, uint32 *list) // Print all IDs in Database
{
    uint8 counter = 0;
    for (int i = 0; i < 10; i++)
    {
        if (students[i].Student_ID != 0)
        {
            list[i] = students[i].Student_ID; // Pass IDs to list
            counter++;
        }
    }
    *count = counter; // Count Number of IDs
    printf("\nNumber of IDs = %d", *count);
}

Bool SDB_IsIdExist(uint32 id) // Check if ID exist in Database
{
    Bool found = False;
    for (uint8 i = 0; i < 10; i++)
    {
        if (id == students[i].Student_ID) // Check if student is in database
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

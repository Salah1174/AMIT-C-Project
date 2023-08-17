#include "SDB.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void SDB_action(uint8 choice)
{
    uint32 id;
    switch (choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
        if (SDB_IsFull())
        {
            printf("\nDatabase is full can't add students");
            break;
        }
        else
        {
            SDB_AddEntry();
            break;
        }
    case 2:
        printf("\nUsed size is  : %d", SDB_GetUsedSize());
        break;
    case 3:
        printf("\nEnter ID : ");
        scanf("%d", &id);
        SDB_ReadEntry(id);
        break;
    case 4:
        uint8 count;
        uint32 list[10];
        SDB_GetList(&count, list);
        for (uint8 i = 0; i < 10; i++)
        {
            if (students[i].Student_ID != 0)
            {
                printf("\nStudent %d ID = %d", i + 1, students[i].Student_ID);
            }
        }
        break;
    case 5:
        printf("\nEnter ID : ");
        scanf("%d", &id);
        if (SDB_IsIdExist(id))
        {
            printf("\nID exists");
        }
        else
        {
            printf("\nId does not exist");
        }
        break;
    case 6:
        if (SDB_GetUsedSize() < 3)
        {
            printf("\nCan not delete students");
            break;
        }
        else
        {
            printf("\nEnter ID : ");
            scanf("%d", &id);
            SDB_DeleteEntry(id);
            break;
        }

    case 7:
        if (SDB_IsFull())
        {
            printf("\nDatabase is full");
        }
        else
        {
            printf("\nDatabase is not full");
        }
        break;
    default:
        break;
    }
}
void SDB_APP()
{
    Bool running = False;
    uint32 id;
    while (True)
    {
        int choice;
        printf("\n1. To add entry, enter 1\n2. To get used size in database, enter 2\n3. To read student data, enter 3\n4. To get the list of all student IDs, enter 4\n5. To check is ID is existed, enter 5\n6. To delete student data, enter 6\n7. To check is database is full, enter 7\n8. To exit enter 0");
        printf("\nChoice : ");
        scanf("%d", &choice);
        SDB_action(choice);
    }
}
int main()
{
    SDB_APP();
}
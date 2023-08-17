#include "STD.h"
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_Year;
    uint32 Course1_ID;
    uint32 Course1_Grade;
    uint32 Course2_ID;
    uint32 Course2_Grade;
    uint32 Course3_ID;
    uint32 Course3_Grade;
} student;
student DefaultSTD = {0, 0, 0, 0, 0, 0, 0, 0}; /*Intial Value for Database elements
                                                 Delete Student's Data*/
student students[10] = {{123, 2024, 209, 79, 210, 88, 211, 95}};

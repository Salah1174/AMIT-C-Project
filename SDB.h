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
student DefaultSTD = {0, 0, 0, 0, 0, 0, 0, 0};
student students[10] = {{123, 2024, 209, 79, 210, 88, 211, 95}, {124, 2024, 209, 79, 210, 88, 211, 95}, {125, 2024, 209, 79, 210, 88, 211, 95}, {126, 2024, 209, 79, 210, 88, 211, 95}, {127, 2024, 209, 79, 210, 88, 211, 95}, {128, 2024, 209, 79, 210, 88, 211, 95}, {129, 2024, 209, 79, 210, 88, 211, 95}, {125, 2024, 209, 79, 210, 88, 211, 95}};

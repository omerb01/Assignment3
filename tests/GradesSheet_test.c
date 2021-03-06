//
// Created by Omer on 15/12/2017.
//

#include <stdlib.h>
#include "test_utilities.h"
#include "../GradesSheet.h"


typedef struct Grade_t {
    int semester;
    int course_id;
    int points_x2;
    int grade_value;
} *Grade;

static bool testGradesSheetCreate() {
    GradesSheet sheet = sheetCreate();
    ASSERT_TEST(sheet != NULL);

    sheetDestroy(sheet);
    return true;
}

static bool testGradesSheetCopy() {
    GradesSheet gsheet = sheetCreate();
    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);

    GradesSheet copied_sheet = sheetCopy(gsheet);
    ASSERT_TEST(copied_sheet != NULL);
    sheetDestroy(gsheet);
    sheetDestroy(copied_sheet);
    return true;
}

static bool testGradesSheetAddGrade() {
    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);
    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    errorcode = sheetAddGrade(gsheet, -1, 2, 3, 4);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    errorcode = sheetAddGrade(gsheet, 1, 1000001, 3, 4);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    errorcode = sheetAddGrade(gsheet, 1, 2, 3, 105);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    sheetDestroy(gsheet);
    return true;
}

static bool testGradesSheetRemoveGrade() {

    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();

    ASSERT_TEST(gsheet != NULL);

    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    errorcode = sheetRemoveLastGrade(gsheet, 10, 56);
    ASSERT_TEST(errorcode == SHEET_GRADE_DOES_NOT_EXIST);
    sheetRemoveLastGrade(gsheet, 7, 71);
    sheetRemoveLastGrade(gsheet, 7, 71);
    errorcode = sheetRemoveLastGrade(gsheet, 7, 71);
    ASSERT_TEST(errorcode == SHEET_GRADE_DOES_NOT_EXIST);
    errorcode = sheetRemoveLastGrade(gsheet, -1, 2);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    errorcode = sheetRemoveLastGrade(gsheet, 1, 1000001);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    sheetDestroy(gsheet);
    return true;
}

static bool testGradesSheetUpdateGrade() {
    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);

    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    errorcode = sheetUpdateLastGrade(gsheet, 5, 99);
    ASSERT_TEST(errorcode == SHEET_GRADE_DOES_NOT_EXIST);
    errorcode = sheetUpdateLastGrade(gsheet, 1, 1000001);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    errorcode = sheetUpdateLastGrade(gsheet, -1, 2);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);

    sheetDestroy(gsheet);
    return true;
}

static bool testGradesSheetHighestLastGrade() {
    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);

    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    int result;
    errorcode = sheetHighestGrade(gsheet, 5, &result);
    ASSERT_TEST(errorcode == SHEET_GRADE_DOES_NOT_EXIST);
    errorcode = sheetHighestGrade(gsheet, 1, NULL);
    ASSERT_TEST(errorcode == SHEET_NULL_ARGUMENT);
    errorcode = sheetHighestGrade(gsheet, -1, &result);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    sheetDestroy(gsheet);
    return true;
}

static bool testSheetPrintFull() {
    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);
    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    sheetAddGrade(gsheet, 7, 394902, 3, 98);
    sheetAddGrade(gsheet, 7, 236703, 6, 100);

    FILE *output_stream = stdout;
    errorcode = sheetPrintFull(output_stream, gsheet);
    ASSERT_TEST(errorcode == SHEET_SUCCESS);
    errorcode = sheetPrintFull(output_stream, NULL);
    ASSERT_TEST(errorcode == SHEET_NULL_ARGUMENT);

    sheetDestroy(gsheet);
    return true;
}

static bool testSheetPrintClear() {
    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);
    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    sheetAddGrade(gsheet, 7, 394902, 3, 98);
    sheetAddGrade(gsheet, 7, 236703, 6, 100);

    FILE *output_stream = stdout;
    errorcode = sheetPrintClean(output_stream, gsheet);
    ASSERT_TEST(errorcode == SHEET_SUCCESS);
    errorcode = sheetPrintClean(output_stream, NULL);
    ASSERT_TEST(errorcode == SHEET_NULL_ARGUMENT);

    sheetDestroy(gsheet);
    return true;

}

static bool testSheetPrintHighestGrades() {
    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);
    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    sheetAddGrade(gsheet, 7, 394902, 3, 98);
    sheetAddGrade(gsheet, 7, 236703, 6, 100);
    FILE *output_stream = stdout;
    errorcode = sheetPrintHighestGrades(output_stream, gsheet, 3);
    ASSERT_TEST(errorcode == SHEET_SUCCESS);
    errorcode = sheetPrintHighestGrades(output_stream, NULL, 5);
    ASSERT_TEST(errorcode == SHEET_NULL_ARGUMENT);
    errorcode = sheetPrintHighestGrades(output_stream, gsheet, -2);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    sheetDestroy(gsheet);
    return true;
}

static bool testSheetPrintLowestGrades() {
    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);
    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    sheetAddGrade(gsheet, 2, 104013, 11, 66);
    sheetAddGrade(gsheet, 2, 104013, 11, 63);
    sheetAddGrade(gsheet, 2, 114071, 7, 98);
    sheetAddGrade(gsheet, 2, 234118, 6, 98);
    sheetAddGrade(gsheet, 2, 234122, 6, 28);
    sheetAddGrade(gsheet, 2, 234122, 6, 96);
    sheetAddGrade(gsheet, 2, 234141, 6, 73);
    sheetAddGrade(gsheet, 2, 394806, 2, 96);
    sheetAddGrade(gsheet, 3, 94412, 8, 80);
    sheetAddGrade(gsheet, 3, 104134, 5, 82);
    sheetAddGrade(gsheet, 3, 134058, 6, 70);
    sheetAddGrade(gsheet, 3, 234218, 6, 75);
    sheetAddGrade(gsheet, 3, 234262, 6, 94);
    sheetAddGrade(gsheet, 3, 234293, 8, 71);
    sheetAddGrade(gsheet, 3, 394902, 3, 96);
    sheetAddGrade(gsheet, 4, 134020, 7, 56);
    sheetAddGrade(gsheet, 4, 134020, 7, 76);
    sheetAddGrade(gsheet, 4, 234123, 9, 94);
    sheetAddGrade(gsheet, 4, 234247, 6, 95);
    sheetAddGrade(gsheet, 4, 234267, 6, 60);
    sheetAddGrade(gsheet, 4, 234267, 6, 68);
    sheetAddGrade(gsheet, 4, 236353, 6, 78);
    sheetAddGrade(gsheet, 4, 394902, 3, 92);
    sheetAddGrade(gsheet, 5, 234107, 8, 51);
    sheetAddGrade(gsheet, 5, 234107, 8, 63);
    sheetAddGrade(gsheet, 5, 234900, 4, 74);
    sheetAddGrade(gsheet, 5, 236327, 6, 77);
    sheetAddGrade(gsheet, 5, 236334, 6, 64);
    sheetAddGrade(gsheet, 5, 236334, 6, 68);
    sheetAddGrade(gsheet, 5, 236343, 6, 80);
    sheetAddGrade(gsheet, 5, 236360, 6, 71);
    sheetAddGrade(gsheet, 5, 324440, 4, 79);
    sheetAddGrade(gsheet, 5, 394902, 3, 97);
    sheetAddGrade(gsheet, 6, 94591, 7, 86);
    sheetAddGrade(gsheet, 6, 234319, 6, 93);
    sheetAddGrade(gsheet, 6, 236370, 6, 90);
    sheetAddGrade(gsheet, 6, 236504, 6, 89);
    sheetAddGrade(gsheet, 6, 236604, 4, 65);
    sheetAddGrade(gsheet, 6, 236653, 6, 87);
    sheetAddGrade(gsheet, 6, 324290, 4, 73);
    sheetAddGrade(gsheet, 6, 394902, 3, 93);
    sheetAddGrade(gsheet, 7, 104174, 7, 25);
    sheetAddGrade(gsheet, 7, 104174, 7, 90);
    sheetAddGrade(gsheet, 7, 236350, 6, 84);
    sheetAddGrade(gsheet, 7, 236503, 6, 71);
    sheetAddGrade(gsheet, 7, 236603, 4, 71);
    sheetAddGrade(gsheet, 7, 394902, 3, 98);
    sheetAddGrade(gsheet, 7, 236703, 6, 100);

    FILE *output_stream = stdout;
    errorcode = sheetPrintLowestGrades(output_stream, gsheet, 3);
    ASSERT_TEST(errorcode == SHEET_SUCCESS);
    errorcode = sheetPrintLowestGrades(output_stream, NULL, 5);
    ASSERT_TEST(errorcode == SHEET_NULL_ARGUMENT);
    errorcode = sheetPrintLowestGrades(output_stream, gsheet, -2);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    sheetDestroy(gsheet);
    return true;
}

int main() {
    RUN_TEST(testGradesSheetCreate);
    RUN_TEST(testGradesSheetCopy);
    RUN_TEST(testGradesSheetAddGrade);
    RUN_TEST(testGradesSheetRemoveGrade);
    RUN_TEST(testGradesSheetUpdateGrade);
    RUN_TEST(testGradesSheetHighestLastGrade);
    RUN_TEST(testSheetPrintFull);
    RUN_TEST(testSheetPrintClear);
    RUN_TEST(testSheetPrintHighestGrades);
    RUN_TEST(testSheetPrintLowestGrades);
/*    SheetResult errorcode;
    GradesSheet gsheet = sheetCreate();
    ASSERT_TEST(gsheet != NULL);
    sheetAddGrade(gsheet, 1, 104012, 11, 84);
    sheetAddGrade(gsheet, 1, 104167, 10, 43);
    sheetAddGrade(gsheet, 1, 104167, 10, 71);
    sheetAddGrade(gsheet, 1, 234114, 8, 88);
    sheetAddGrade(gsheet, 1, 234145, 6, 98);
    sheetAddGrade(gsheet, 1, 394808, 2, 92);
    errorcode = sheetRemoveLastGrade(gsheet, 10, 56);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    errorcode = sheetRemoveLastGrade(gsheet, 7, 71);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    errorcode = sheetRemoveLastGrade(gsheet, -1, 2);
    ASSERT_TEST(errorcode == SHEET_INVALID_ARGUMENT);
    errorcode = sheetRemoveLastGrade(gsheet, 1, 1000001);
    sheetDestroy(gsheet);*/
    return true;
}
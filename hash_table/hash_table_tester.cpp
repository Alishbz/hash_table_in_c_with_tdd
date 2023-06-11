/*************************************************************************
* ALI SAHBAZ
*
*
* Hash Table Driver TEST
*
* Date          : 11.06.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com
*
*************************************************************************/

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h" 
#include "CppUTest/TestOutput.h"
#include "CppUTest/TestTestingFixture.h"
#include "CppUTest/PlatformSpecificFunctions.h"

/*** Testing Lib ***/
#include "hash_table.h"


TEST_GROUP(hash_table_tester)
{  
    hash_table_object _test_hash;
    hash_table_function_out out1 , out2 , out3;
    hash_type finder;

    void setup()
    { 
    }

    void teardown()
    { 
        hash_table_delete(&_test_hash);
    }
};

 
TEST(hash_table_tester, hash_table_create)
{  
    out1 = hash_table_create(&_test_hash);
    CHECK_EQUAL(HASH_TABLE_SUCCESS, out1);
}


TEST(hash_table_tester, hash_table_add_new_hash)
{ 
    out1 = hash_table_create(&_test_hash);
    out2 = hash_table_add_new_hash(&_test_hash , 5 , "keyX");
    CHECK_EQUAL(HASH_TABLE_SUCCESS, out1);
    CHECK_EQUAL(HASH_TABLE_SUCCESS, out2);
}


TEST(hash_table_tester, hash_table_get_hash_with_name)
{ 
    out1 = hash_table_create(&_test_hash); 
    out2 = hash_table_add_new_hash(&_test_hash, 5, "keyY");
    finder = 0;
    out3 = hash_table_get_hash_with_name(&_test_hash, "keyY", &finder);
    CHECK_EQUAL(HASH_TABLE_SUCCESS, out1);
    CHECK_EQUAL(HASH_TABLE_SUCCESS, out2);
    CHECK_EQUAL(HASH_TABLE_SUCCESS, out3);
    CHECK_EQUAL(5, finder);
}


TEST(hash_table_tester, hard_test_1 )
{
    out1 = hash_table_create(&_test_hash);
    int i = 0;
    for (i = 0; i < HASH_TABLE_ALLOCATED_SIZE + 1; i++) {
        char str_key[7]; memset(str_key, 0, 7);
        snprintf(str_key , 7 , "keyW%d" , i);
        if (i == HASH_TABLE_ALLOCATED_SIZE) {
            CHECK_EQUAL(HASH_TABLE_FAIL, hash_table_add_new_hash(&_test_hash, i, (char*)str_key));
        }
        else {
            CHECK_EQUAL(HASH_TABLE_SUCCESS, hash_table_add_new_hash(&_test_hash, i, (char*)str_key));
        }
    }
    
    for (i = 0; i < HASH_TABLE_ALLOCATED_SIZE + 1; i++) {
        finder = 0;
        char str_key[8]; memset(str_key, 0, 8);
        snprintf(str_key, 8, "keyW%d", i);
        if (i == HASH_TABLE_ALLOCATED_SIZE) {
            CHECK_EQUAL(HASH_TABLE_FAIL, hash_table_get_hash_with_name(&_test_hash, (char*)str_key, &finder));
            CHECK_EQUAL(HASH_CLEARED_VALUE, finder);
        }
        else {
            CHECK_EQUAL(HASH_TABLE_SUCCESS, hash_table_get_hash_with_name(&_test_hash, (char*)str_key, &finder));
            CHECK_EQUAL(i, finder);
        }
    } 
}
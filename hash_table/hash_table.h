/*************************************************************************
* ALI SAHBAZ
*
*
* Hash Table Driver
*
* Date          : 11.06.2023
* By            : Ali Sahbaz
* e-mail        : ali_sahbaz@outlook.com
*
*************************************************************************/
#pragma once
#ifndef hash_table_H
#define hash_table_H
  

#ifdef __cplusplus
extern "C" {
#endif

 
/*** Lib Configs for user ***/
#define HASH_TABLE_ALLOCATED_SIZE  50
#define HASH_HOLDER_ARRAY_SIZE     16 
typedef unsigned char hash_type;
#define HASH_CLEARED_VALUE         ((hash_type)0 )

 
typedef enum
{
	HASH_TABLE_SUCCESS=0,
	HASH_TABLE_FAIL
} hash_table_function_out;


typedef struct
{
	hash_type     value;
	unsigned char key[HASH_HOLDER_ARRAY_SIZE];

	//** start from 1 ... and going to .... HASH_TABLE_ALLOCATED_SIZE **
	unsigned int  private_index;
} hash_str;
 

/*** @Super_Object  ****/  
typedef struct
{
	unsigned char is_init;

	hash_str hash[HASH_TABLE_ALLOCATED_SIZE];

	unsigned int hash_size;

}hash_table_object;







/****  Hash Create/Delete and Make User Functions  ****/

hash_table_function_out
hash_table_create(hash_table_object* const me  );


hash_table_function_out
hash_table_add_new_hash(hash_table_object* const me,
						hash_type          value,
						const char       * hash_name);


hash_table_function_out
hash_table_delete(hash_table_object* const me);





/****  Hash Get User Functions  ****/

hash_table_function_out
hash_table_get_hash_with_name(hash_table_object* const me, 
							  const char       * hash_name ,
							  hash_type        * value_out);





 // TODO, should be expanded





#ifdef __cplusplus
}
#endif

#endif
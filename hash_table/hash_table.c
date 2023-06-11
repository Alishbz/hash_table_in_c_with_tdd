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
#include "stdio.h"
#include "string.h"
#include "hash_table.h"
 


// TODO, this driver should be expanded in the feature 




static void
_clear_hash_str(hash_str* me)
{
	if (me == NULL) { 
		return; 
	}

	me->value = HASH_CLEARED_VALUE;

	me->private_index = 0;

	unsigned int index = HASH_HOLDER_ARRAY_SIZE;

	do {
		me->key[--index] = 0;
	} while (index);
}

static void
_create_hash_str(hash_str* me , 
	             hash_type val , 
	             const char* hash_name , 
	             unsigned int prv_index)
{
	if (me == NULL || hash_name == NULL) {
		return;
	}

	me->value = val;

	me->private_index = prv_index;

	unsigned int index = 0;

	do {
		if (hash_name[index] == 0) { break; }
		me->key[index] = hash_name[index];
		index++;
	} while (index < HASH_HOLDER_ARRAY_SIZE);
}





hash_table_function_out
hash_table_create(hash_table_object* const me)
{
	if (me == NULL || HASH_TABLE_ALLOCATED_SIZE < 1) {
		return HASH_TABLE_FAIL;
	}

	unsigned int index = HASH_TABLE_ALLOCATED_SIZE;

	me->hash_size = HASH_TABLE_ALLOCATED_SIZE;

	do {
	 
		_clear_hash_str(&me->hash[--index]);

	} while (index);
	 
	me->is_init = 1;
	 
	return HASH_TABLE_SUCCESS;
}


hash_table_function_out
hash_table_delete(hash_table_object* const me)
{
	// TODO
	return hash_table_create(me); 
}



hash_table_function_out
hash_table_add_new_hash(hash_table_object* const me,
						hash_type          value,
						const char       * hash_name)
{

	if (me == NULL || hash_name == NULL || !me->is_init ) {
		return HASH_TABLE_FAIL;
	}
	char is_succes = 0;
	unsigned int prv_index_decider = 1;
	unsigned int index = me->hash_size;
	  
	do { 
		if (me->hash[--index].private_index == 0)
		{
			if (index != (me->hash_size-1)) {
				prv_index_decider = me->hash[index].private_index + 1;
			}

			_create_hash_str(&me->hash[index],
						  	 value,
							 hash_name,
							 prv_index_decider); 
			is_succes = 1;
			break;
		} 
	} while (index);

	if (is_succes) {
		return HASH_TABLE_SUCCESS;
	}
	return HASH_TABLE_FAIL;
}




hash_table_function_out
hash_table_get_hash_with_name(hash_table_object* const me,
							  const char* hash_name,
							  hash_type* value_out)
{
	if (me == NULL || hash_name == NULL || !me->is_init) {
		return HASH_TABLE_FAIL;
	}
	char is_succes = 0;
	unsigned int index = me->hash_size;

	do { 
		if (me->hash[--index].private_index) {

			if (strstr(me->hash[index].key, hash_name)) {
			    /** finded step out **/
				*value_out = me->hash[index].value;
				is_succes = 1;
				break;
			} 
		}
		else {
			/** not find step out **/
			*value_out = HASH_CLEARED_VALUE;
			return HASH_TABLE_FAIL;
		}
		  
	} while (index);

	if (is_succes) {
		return HASH_TABLE_SUCCESS;
	}
	return HASH_TABLE_FAIL;
}
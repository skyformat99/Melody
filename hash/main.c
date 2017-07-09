/*
 * A unit test and example of how to use the simple C hashmap
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "hashmap.h"
#include <string.h>

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024)

typedef struct data_struct_s
{
    char url[KEY_MAX_LENGTH];
    char task_name[100];
} data_struct_t;

int main(int argc, char** argv)
{
    int index;
    int error;
    hashmap_map* mymap;
    char key_string[KEY_MAX_LENGTH];
    data_struct_t* value;
    
    mymap = hashmap_new();
    printf("key_string:%d,number:",mymap->table_size);

    /* First, populate the hash map with ascending values */
    for (index=0; index<KEY_COUNT; index+=1)
    {
        /* Store the key string along side the numerical value so we can free it later */
        value = malloc(sizeof(data_struct_t));
        memset(value, 0, sizeof(data_struct_t));
        snprintf(value->url, KEY_MAX_LENGTH, "%s%d", "http://www.baidu.com", index);
        snprintf(value->task_name, KEY_MAX_LENGTH, "%s%d", "task", index);

        mymap = hashmap_put(mymap, value->task_name, value);
        assert(error==MAP_OK);
        data_struct_t * tvalue;
        memset(tvalue, 0, sizeof(data_struct_t));
        tvalue->task_name = ( data_struct_t *) mymap->data[index].data->task_name;
        tvalue->url = ( data_struct_t *) mymap->data[index].data->url;
        printf("key_string:%s",mymap->data[index].key);
        printf("value_url:%s",tvalue->url);
        printf("value_taskname:%s",tvalue->task_name);
    }

    /* Now, check all of the expected values are there */

/*    for (index=0; index<KEY_COUNT; index+=1)
    {
        snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);

        error = hashmap_get(mymap, key_string, (void**)(&value));
        
        *//* Make sure the value was both found and the correct number *//*
        assert(error==MAP_OK);
        assert(value->number==index);
    }
    
    *//* Make sure that a value that wasn't in the map can't be found *//*
    snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, KEY_COUNT);

    error = hashmap_get(mymap, key_string, (void**)(&value));
        
    *//* Make sure the value was not found *//*
    assert(error==MAP_MISSING);

    *//* Free all of the values we allocated and remove them from the map *//*
    for (index=0; index<KEY_COUNT; index+=1)
    {
        snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);

        error = hashmap_get(mymap, key_string, (void**)(&value));
        assert(error==MAP_OK);

        error = hashmap_remove(mymap, key_string);
        assert(error==MAP_OK);

        free(value);        
    }*/

    /* Now, destroy the map */
    hashmap_free(mymap);

    return 1;
}
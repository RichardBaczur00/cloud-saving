#ifndef CONFIG_PARSER_H_INCLUDED

#define CONFIG_PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <json-c/json.h>

typedef struct {
    char name[32];
    char type[16];
    size_t offset;
} FieldConfig;

typedef struct {
    FieldConfig* fields;
    size_t numFields;
} Config;


Config* loadConfig(const char*);
void freeConfig(Config*);

#endif
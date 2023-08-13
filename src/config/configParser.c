#include "config/configParser.h"

Config* loadConfig(const char* filename) {
    
    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*) calloc(fileSize, sizeof(char));
    fread(buffer, 1, fileSize, file);
    fclose(file);

    Config* config = (Config*) malloc(sizeof(Config));
    if (!config) {
        free(buffer);
        return NULL;
    }

    json_object *root = json_object_from_file(filename);
    printf("Json fields:\n %s\n", json_object_to_json_string(root));

    if (!root) {
        return NULL;
    }

    json_object *fields = json_object_object_get(root, "fields");
    printf("Json fields:\n %s\n", json_object_to_json_string(fields));
    config->numFields = json_object_array_length(fields);
    config->fields = (FieldConfig*)malloc(config->numFields * sizeof(FieldConfig));

    for (int i = 0; i < config->numFields; ++i) {
        json_object *field = json_object_array_get_idx(fields, i);
        json_object *name = json_object_object_get(field, "name");
        json_object *type = json_object_object_get(field, "type");
        json_object *offset = json_object_object_get(field, "offset");
        strcpy(config->fields[i].name, json_object_get_string(name));
        strcpy(config->fields[i].type, json_object_get_string(type));
        config->fields[i].offset = json_object_get_int(offset);
    }

    free(buffer);

    return NULL;
}

void freeConfig(Config* config) {
    if (!config) return;

    free(config->fields);
    free(config);
}
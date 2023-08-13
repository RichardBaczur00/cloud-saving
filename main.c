#include "config/configParser.h"

int main(void) {
    Config* conf = loadConfig("chestie.json");

    printf("Num fields: %ld\n", conf->numFields);

    for (int i = 0; i < conf->numFields; ++i) {
        FieldConfig field = conf->fields[i];
        printf("%s of type %s at %ld offset\n", field.name, field.type, field.offset);
    }

    return 0;
}
#include "config/configParser.h"

int main(void) {
    Config* conf = loadConfig("chestie.json");

    printf("Num fields: %d\n", conf->numFields);

    for (int i = 0; i < conf->numFields; ++i) {
        printf("%s of type %s at %d offset\n", conf->fields->name, conf->fields->type, conf->fields->offset);
    }

    return 0;
}
#ifndef SERIALIZE_H_INCLUDED

#define SERIALIZE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "config/configParser.h"

char* serializedData;

void initSerializedGameData(char*, size_t);
void addToSerialization(const char*, void* data);
char* serializeData();

#endif
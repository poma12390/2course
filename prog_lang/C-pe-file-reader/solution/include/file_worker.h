#ifndef SECTION_EXTRACTOR_NUMBER_UTIL_H
#define SECTION_EXTRACTOR_NUMBER_UTIL_H

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <pe.h>

FILE* open_file(char *argv, struct PEFile *file, char* mode);

int8_t open_pe_file(FILE *in, struct PEFile *file);

void write_section_data(FILE *in, FILE *out, const struct SectionHeader section_header);

struct SectionHeader find_section_by_name(const struct PEFile *file, const char *name);

#endif

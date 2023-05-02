/// @file
/// @brief Main application file


#include "pe.h"
#include <file_worker.h>

#define APP_NAME "section-extractor"

/// @brief Print usage test
/// @param[in] f File to print to (e.g., stdout)
void usage(FILE *f)
{
  fprintf(f, "Usage: " APP_NAME " <in_file> <section_name> <out_file>\n");
}
/// @brief Clear memory
/// @param[in] file clear memory of this file
/// @param[in] in close stream
void interrupt(struct PEFile *file, FILE *in){
        free(file);
        fclose(in);
}

/// @brief Application entry point
/// @param[in] argc Number of command line arguments
/// @param[in] argv Command line arguments
/// @return 0 in case of success or error code
int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: " APP_NAME " <source-pe-file> <section-name> <output-bin-image>\n");
        return 1;
    }
    struct PEFile *file = malloc(sizeof(struct PEFile));
    if (!file) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    FILE *in = open_file(argv[1], file, "rb");
    if (!in) {
        return 1;
    }
    int8_t code = open_pe_file(in, file);
    if (code != 0) {
        interrupt(file, in);
        return 1;
    }
    char *section_name = argv[2];
    struct SectionHeader section_header = find_section_by_name(file, section_name);
    if (section_header.pointer_to_raw_data == 0) {
        printf("Failed to find section\n");
        free(file->section_headers);
        interrupt(file, in);
        return 1;
    }
    FILE *out = open_file(argv[3], file, "wb");
    if (!out) {
        printf("Failed to open output file.\n");;
        fclose(in);
        return 1;
    }
    write_section_data(in, out, section_header);
    free(file->section_headers);
    interrupt(file, in);
    fclose(out);
    return 0;
}


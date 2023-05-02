/// @file
/// @brief file worker application file


#include "file_worker.h"
#include "pe.h"



/// @brief Print usage test
/// @param[in] argv link to file
/// @param[in] file clear memory if smth broke
/// @param[in] mode mode to open file
/// @return opened file
FILE* open_file(char *argv, struct PEFile *file, char* mode){
    FILE *in = fopen(argv, mode);
    if (!in) {
        printf("Failed to open PE file.\n");
        free(file);
        return NULL;
    }
    return in;
}

/// @brief write section data
/// @param[in] in file to take section from
/// @param[in] out file to write section
/// @param[in] section_header section header
void write_section_data(FILE *in, FILE *out, const struct SectionHeader section_header) {
    if (section_header.pointer_to_raw_data == 0) {
        return;
    }

    //jump to section start
    fseek(in, section_header.pointer_to_raw_data, SEEK_SET);
    char *section = malloc(section_header.size_of_raw_data);

    size_t count_of_find_sections = fread(section, section_header.size_of_raw_data, 1, in);
    //write section
    size_t count_of_edit_sections=fwrite(section, section_header.size_of_raw_data, 1, out);
    if (count_of_edit_sections== 0 || count_of_find_sections == 0) {
        printf("Failed to edit section.\n");
        return;
    }
    free(section);
}

/// @brief find section
/// @param[in] file file to find section in
/// @param[in] name name of section
/// @return section header
struct SectionHeader find_section_by_name(const struct PEFile *file, const char *name) {
    for (int16_t i = 0; i < file->header.number_of_sections; i++) {
        if (memcmp(file->section_headers[i].name, name, strlen(name)) == 0) {
            return file->section_headers[i];
        } 
    }
    return (struct SectionHeader) {0};
}

/// @brief open pe file
/// @param[in] in file to check for pe
/// @param[in] file pe file
/// @return 0 if good
int8_t open_pe_file(FILE *in, struct PEFile *file) {
    if (!in) {
        return 1;
    }
    
    //Go to end of headers
    fseek(in, OFFSET, SEEK_SET);
    uint32_t offset;

    size_t count_of_offset=fread(&offset, sizeof(uint32_t), 1, in);
    //check file signature
    fseek(in, offset, SEEK_SET);
    //read magic
    size_t count_of_signatures=fread(&file->magic, sizeof(file->magic), 1, in);
    uint32_t changed_uint=(file->magic);
    if (count_of_offset==0 || count_of_signatures == 0 || changed_uint == PE_FILE_SIGNATURE) {
        printf("Uncorrect PE file.\n");
        return 1;
    }
    


    //read header file
    fread(&file->header, sizeof(file->header), 1, in);
    file->section_headers = malloc(file->header.number_of_sections * sizeof(struct SectionHeader));
    //check valid headers
    fseek(in, file->header.size_of_optional_header, SEEK_CUR);
    //read sections
    //check readble headers
    size_t count_of_headers;
    count_of_headers=fread(file->section_headers, sizeof(struct SectionHeader), file->header.number_of_sections, in);
    if (count_of_headers!= file->header.number_of_sections) {
        printf("Failed to read headers.\n");
        free(file->section_headers);
        return 1;
    }
    
    return 0;
}

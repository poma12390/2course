
#ifndef SECTION_EXTRACTOR_PE_FILE_C
#define SECTION_EXTRACTOR_PE_FILE_C

#include <stdint.h>

/// Offset to the signature of PE file
#define OFFSET 0x3c

/// Signature of PE file
#define PE_FILE_SIGNATURE 0x00005045


//pack struct if visual studio
#ifdef _MSC_VER
    #pragma pack(push, 1)
#endif


struct //pack if clang or gcc
#if defined __clang__ || defined __GNUC__
    __attribute__((packed))
#endif
PEHeader {

    /// The number that identifies the type of target machine
    int16_t machine;

    /// The number of sections. This indicates the size of the section table, which immediately follows the headers
    int16_t number_of_sections;

    /// The low 32 bits of the number of seconds since 00:00 January 1, 1970, which indicates when the file was created
    int32_t time_date_stamp;

    /// The file offset of the COFF symbol table, or zero if no COFF symbol table is present
    int32_t pointer_to_symbol_table;

    /// The number of entries in the symbol table
    int32_t number_of_symbols;

    /// The size of the optional header, which is required for executable files but not for object files
    int16_t size_of_optional_header;

    /// The flags that indicate the attributes of the file
    int16_t characteristics;

};

struct //pack if clang or gcc
#if defined __clang__ || defined __GNUC__
    __attribute__((packed))
#endif
SectionHeader {

    /// The name of the section
    uint8_t name[8];

    /// The total size of the section when loaded into memory
    union {
        /// The physical address of the section
        uint32_t physical_address;

        /// The virtual size of the section
        uint32_t virtual_size;
    } misc;

    /// The virtual address of the section
    uint32_t virtual_address;

    /// The size of the section in the raw data file
    uint32_t size_of_raw_data;

    /// The file pointer to the section's raw data
    uint32_t pointer_to_raw_data;

    /// The file pointer to the section's relocation entries
    uint32_t pointer_to_relocations;

    /// The file pointer to the section's line-number entries
    uint32_t pointer_to_linenumbers;

    /// The number of relocation entries for the section
    uint16_t number_of_relocations;

    /// The number of line-number entries for the section
    uint16_t number_of_linenumbers;

    /// The characteristics of the section, such as permissions and flags
    uint32_t characteristics;

};

//pack struct if visual studio
#ifdef _MSC_VER
    #pragma pack(pop)
#endif

struct //pack if clang or gcc
#if defined __clang__ || defined __GNUC__
    __attribute__((packed))
#endif
OptionalHeader {
    //The unsigned integer that identifies the state of the image file
    uint16_t magic;
    //The linker major version number.
    uint8_t major_linker_version;
    //The linker minor version number.
    uint8_t minor_linker_version;
    //The size of the code (text) section
    uint32_t size_of_code;
    //The size of the initialized data section
    uint32_t size_of_initialied_data;
    //The size of the uninitialized data section
    uint32_t size_of_uninitialied_data;
    //The address of the entry point relative to the image base when the executable file is loaded into memory.
    uint32_t adress_of_entry_point;
    //The address that is relative to the image base of the beginning-of-code section when it is loaded into memory.
    uint32_t base_of_code;

};

#ifdef _MSC_VER
    #pragma pack(pop)
#endif

struct 
#if defined __clang__ || defined __GNUC__
    __attribute__((packed))
#endif
PEFile {

      /// Offset to a file magic
    uint32_t magic_offset;
    /// Offset to a main PE header
    uint32_t header_offset;
    /// Offset to an optional header
    uint32_t optional_header_offset;
    /// Offset to a section table
    uint32_t section_header_offset;

    /// Magic number that identifies the file as a PE format image file
    uint32_t magic;

    /// Main header
    struct PEHeader header;

    /// Optional header
    struct OptionalHeader optional_header;

    /// Array of section headers with the size of header.number_of_sections
    struct SectionHeader *section_headers;

};





#endif


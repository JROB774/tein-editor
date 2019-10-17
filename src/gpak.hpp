#pragma once

// The GPAK system returns error codes as we don't want to call the error log
// system on another thread. So the returned code tells us which error to log.

enum GPAK_Error
{
    GPAK_ERROR_NONE,   // Successfully packed/unpacked GPAK.
    GPAK_ERROR_WRITE,  // Failed to open the GPAK for writing.
    GPAK_ERROR_READ,   // Failed to open the GPAK for reading.
    GPAK_ERROR_EMPTY,  // No files were found in paths to pack.
};

struct GPAK_Entry
{
    u16  name_length;
    std::string name;
    u32    file_size;
};

FILDEF void gpak_unpack (const char* _filename, bool _overwrite);
FILDEF void gpak_pack   (const char* _filename, std::vector<std::string> _paths);

FILDEF float gpak_unpack_progress ();
FILDEF float gpak_pack_progress   ();

FILDEF bool is_gpak_unpack_complete ();
FILDEF bool is_gpak_pack_complete   ();

FILDEF void do_unpack ();
FILDEF void do_pack   ();

FILDEF void cancel_unpack ();
FILDEF void cancel_pack   ();

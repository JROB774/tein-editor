#pragma once

// Never shipped in the actual release, this is just a built-in utility to
// provided padding to all the tile assets before packing them into an atlas
// so that there are no issues with sampling when scaling the tile images.

#if defined(DEBUG_BUILD)
FILDEF void pack_textures ();
#else
#define pack_textures()
#endif // DEBUG_BUILD

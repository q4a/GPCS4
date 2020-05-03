#pragma once

// Global configs



//App name
#define GPCS4_APP_NAME "GPCS4"


// Debug build
// Configured in project properties settings.
// #define GPCS4_DEBUG


// Windows compile
#ifndef GPCS4_LINUX
#define GPCS4_WINDOWS
#endif  //GPCS4_LINUX


// Linux compile
// #define GPCS4_LINUX

 
// Graphics switch
// Define this will turn off graphics output,
// useful when developing non-graphics parts of GPCS4
// #define GPCS4_NO_GRAPHICS


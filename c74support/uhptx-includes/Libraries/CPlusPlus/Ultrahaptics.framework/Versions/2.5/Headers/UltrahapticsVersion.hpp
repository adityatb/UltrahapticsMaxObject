#pragma once

#include "UltrahapticsDecoration.hpp"

/*! \file */

/**
 * @defgroup VERSION_DEFINES Version Definitions
 *
 * @{
 */
/** The version of this SDK as an integer, with one byte for each of the major, minor and patch versions */
#define UH_SDK_VERSION_INT   0x020502
/** A string representing the version of this SDK, without any platform or variant information */
#define UH_SDK_VERSION       "2.5.2"
/** A string representing the version of this SDK, with platform and variant information as appropriate */
#define UH_SDK_VERSION_LONG  "2.5.2-macOS-x86_64"
/** The major version of this SDK as an integer */
#define UH_SDK_VERSION_MAJOR 2
/** The minor version of this SDK as an integer */
#define UH_SDK_VERSION_MINOR 5
/** The patch version of this SDK as an integer */
#define UH_SDK_VERSION_PATCH 2
/** A string representing the date this SDK was built, in ISO8601 format */
#define UH_SDK_BUILD_DATE    "2018-01-25"

/** The name of the platform this SDK is built for */
#define UH_SDK_PLATFORM_NAME "macOS-x86_64"
/** The variant of this SDK build */
#define UH_SDK_VARIANT       "Public"
/** @} */

namespace Ultrahaptics
{

/** A structure representing the version of this SDK */
struct UH_API_CLASS_DECORATION VersionInfo
{
public:
    /** A string representing the version of this SDK, without any platform or variant information */
    const char* const  VersionString;
    /** A string representing the version of this SDK, with platform and variant information as appropriate */
    const char* const  LongVersionString;
    /** A string representing the date this SDK was built, in ISO8601 format */
    const char* const  BuildDate;
    /** The name of the platform this SDK is built for */
    const char* const  PlatformName;
    /** The variant of this SDK build */
    const char* const  VariantName;

    /** The major version of this SDK */
    const unsigned int MajorVersion;
    /** The minor version of this SDK */
    const unsigned int MinorVersion;
    /** The patch version of this SDK */
    const unsigned int PatchVersion;

    VersionInfo();
};

}


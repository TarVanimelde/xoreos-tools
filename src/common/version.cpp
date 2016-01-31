/* xoreos-tools - Tools to help with xoreos development
 *
 * xoreos-tools is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos-tools is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos-tools is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos-tools. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Basic xoreos-tools version information
 */

#include <cstdio>

#include "src/common/version.h"

#if defined(HAVE_CONFIG_H)
	#include "config.h"
#endif

// Define default values if the real ones can't be determined

#ifndef PACKAGE_NAME
	#define PACKAGE_NAME "xoreos-tools"
#endif

#ifndef PACKAGE_VERSION
	#define PACKAGE_VERSION "0.0.4"
#endif

#ifndef XOREOS_REVDESC
	#define XOREOS_REVDESC "unknown"
#endif

#ifndef XOREOS_REV
	#define XOREOS_REV "unk"
#endif

#ifndef XOREOS_BUILDDATE
	#define XOREOS_BUILDDATE __DATE__ " " __TIME__
#endif

// If we're in full release mode, the revision is ignored
#ifdef XOREOS_RELEASE
	#undef XOREOS_REV
	#define XOREOS_REV ""
	#define XOREOS_REVSEP ""
#else
	#define XOREOS_REVSEP "+"
#endif

// Distributions may append an extra version string
#ifdef XOREOS_DISTRO
	#undef XOREOS_REV
	#define XOREOS_REV XOREOS_DISTRO
#endif

const char *XOREOS_NAME            = PACKAGE_NAME;
const char *XOREOS_VERSION         = PACKAGE_VERSION;
const char *XOREOS_NAMEVERSION     = PACKAGE_NAME " " PACKAGE_VERSION XOREOS_REVSEP XOREOS_REV;
const char *XOREOS_NAMEVERSIONFULL = PACKAGE_NAME " " PACKAGE_VERSION XOREOS_REVSEP XOREOS_REV " [" XOREOS_REVDESC "] (" XOREOS_BUILDDATE ")";
const char *XOREOS_URL             = "https://xoreos.org/";

const char *XOREOS_AUTHORS =
	"Copyright (c) 2012-2016 by the xoreos team.\n"
	"Please see the AUTHORS file for details.\n"
	"\n"
	"This is free software; see the source for copying conditions.  There is NO\n"
	"warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.";

void printVersion() {
	std::printf("%s\n", XOREOS_NAMEVERSIONFULL);
	std::printf("%s\n", XOREOS_URL);
	std::printf("\n");
	std::printf("%s\n", XOREOS_AUTHORS);
	std::printf("\n");
}

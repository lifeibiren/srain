/* Copyright (C) 2020 Fei Li <lifeibiren@gmail.com>
 *
 * This file is part of Srain.
 *
 * Srain is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file self.c
 * @brief Get executable' itself path
 * @author lifeibiren <lifeibiren@gmail.com>
 * @version 1.1.1
 * @date 2020-07-11
 */

#include "self.h"

#ifdef _WIN32
#include <windows.h>
#include <Shlwapi.h>
#include <io.h>

#elif defined __APPLE__
#include <libgen.h>
#include <limits.h>
#include <mach-o/dyld.h>
#include <unistd.h>

#elif defined __linux__
#include <limits.h>
#include <libgen.h>
#include <unistd.h>

#ifdef __sun
#define PROC_SELF_EXE "/proc/self/path/a.out"
#else
#define PROC_SELF_EXE "/proc/self/exe"
#endif

#endif

#ifdef _WIN32
gchar *srn_get_executable_path() {
   char rawPathName[MAX_PATH];
   GetModuleFileNameA(NULL, rawPathName, MAX_PATH);
   return g_build_filename(rawPathName, NULL);
}

gchar *srn_get_executable_dir() {
    gchar *exePath = srn_get_executable_path();
    gchar *executableDir = g_path_get_dirname(exePath);
    g_free(exePath);
    return executableDir;
}

#elif defined __linux__
gchar *srn_get_executable_path() {
   char rawPathName[PATH_MAX];
   realpath(PROC_SELF_EXE, rawPathName);
   return g_build_filename(rawPathName, NULL);
}

gchar *srn_get_executable_dir() {
    gchar *exePath = srn_get_executable_path();
    gchar *executableDir = g_path_get_dirname(exePath);
    g_free(exePath);
    return executableDir;
}

#elif defined __APPLE__
gchar *srn_get_executable_path() {
    char rawPathName[PATH_MAX];
    char realPathName[PATH_MAX];
    uint32_t rawPathSize = (uint32_t)sizeof(rawPathName);

    if(!_NSGetExecutablePath(rawPathName, &rawPathSize)) {
        realpath(rawPathName, realPathName);
    }
    return g_build_filename(realPathName, NULL);
}

gchar *srn_get_executable_dir() {
    gchar *executablePath = srn_get_executable_path();
    gchar *executableDir = g_path_get_dirname(executablePathStr);
    g_free(executablePath);
    return executableDir;
}

#endif

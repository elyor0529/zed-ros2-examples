/*
 * MIT License
 * 
 * Copyright (c) 2020 Stereolabs
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ZED_OD_PLUGIN__VISIBILITY_CONTROL_H_
#define ZED_OD_PLUGIN__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ZED_OD_PLUGIN_EXPORT __attribute__ ((dllexport))
    #define ZED_OD_PLUGIN_IMPORT __attribute__ ((dllimport))
  #else
    #define ZED_OD_PLUGIN_EXPORT __declspec(dllexport)
    #define ZED_OD_PLUGIN_IMPORT __declspec(dllimport)
  #endif
  #ifdef ZED_OD_PLUGIN_BUILDING_LIBRARY
    #define ZED_OD_PLUGIN_PUBLIC ZED_OD_PLUGIN_EXPORT
  #else
    #define ZED_OD_PLUGIN_PUBLIC ZED_OD_PLUGIN_IMPORT
  #endif
  #define ZED_OD_PLUGIN_PUBLIC_TYPE ZED_OD_PLUGIN_PUBLIC
  #define ZED_OD_PLUGIN_LOCAL
#else
  #define ZED_OD_PLUGIN_EXPORT __attribute__ ((visibility("default")))
  #define ZED_OD_PLUGIN_IMPORT
  #if __GNUC__ >= 4
    #define ZED_OD_PLUGIN_PUBLIC __attribute__ ((visibility("default")))
    #define ZED_OD_PLUGIN_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ZED_OD_PLUGIN_PUBLIC
    #define ZED_OD_PLUGIN_LOCAL
  #endif
  #define ZED_OD_PLUGIN_PUBLIC_TYPE
#endif

#endif  // ZED_OD_PLUGIN__VISIBILITY_CONTROL_H_

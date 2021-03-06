/* vim: tabstop=2 shiftwidth=2 expandtab textwidth=80 linebreak wrap
 *
 * Copyright 2012 Matthew McCormick
 * Copyright 2015 Pawel 'l0ner' Soltys
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CPU_H_
#define CPU_H_

#include <string>
#include <sys/types.h>

#if defined(__APPLE__) && defined(__MACH__)
  #define CP_USER 0
  #define CP_SYS  1
  #define CP_IDLE 2
  #define CP_NICE 3
  #define CP_STATES 4
#endif

/** Get the current CPU stats */
u_int8_t get_cpu_count();
float cpu_percentage( unsigned );

std::string tick( int percentage );
std::string cpu_string( unsigned int cpu_usage_delay );

#endif

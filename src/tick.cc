/*
 * Copyright 2012 Matthew McCormick
 * Copyright 2013 Justin Crawford <Justasic@gmail.com>
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

#include <string>
#include <sstream>

std::string tick( int percentage )
{
  std::ostringstream oss;
  std::string ticks = "▁▂▃▄▅▆▇█";
  int ticks_count = ticks.size() / 3;
  int tick_pos = (ticks_count * percentage) / 101;

  if (percentage > 90) {
    oss << "#[fg=red]";
  } else if (percentage > 75) {
    oss << "#[fg=yellow]";
  } else {
    oss << "#[fg=green]";
  }

  oss << ticks.substr(tick_pos * 3, 3);

  return oss.str();
}

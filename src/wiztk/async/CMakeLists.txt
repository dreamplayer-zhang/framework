# Copyright 2017 - 2018 The WizTK Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(
        async_sources
        ${PROJECT_SOURCE_DIR}/include/wiztk/async/event-loop.hpp
        ${PROJECT_SOURCE_DIR}/include/wiztk/async/message.hpp
        ${PROJECT_SOURCE_DIR}/include/wiztk/async/message-queue.hpp
        ${PROJECT_SOURCE_DIR}/include/wiztk/async/scheduler.hpp
        ${PROJECT_SOURCE_DIR}/include/wiztk/async/type.hpp
        event-loop/private.cpp
        event-loop/private.hpp
        event-loop/quit-event.cpp
        event-loop/quit-event.hpp
        event-loop.cpp
        message-queue.cpp
        scheduler.cpp
)

if (BUILD_SHARED_LIBRARY)
    add_library(wiztk-async SHARED ${config_header} ${async_sources})
    set_target_properties(wiztk-async PROPERTIES VERSION 1 SOVERSION 1)
else ()
    add_library(wiztk-async ${config_header} ${async_sources})
endif ()

target_link_libraries(
        wiztk-async
        PUBLIC wiztk-base
)

target_include_directories(
        wiztk-async
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

install(TARGETS wiztk-async DESTINATION lib)

/*
 * Copyright 2016 Freeman Zhang <zhanggyb@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "wiztk/gui/application.hpp"
#include "wiztk/gui/window.hpp"
#include "wiztk/gui/spinner.hpp"

using namespace wiztk;
using namespace wiztk::gui;

int main(int argc, char *argv[]) {
  Application app(argc, argv);

  auto *win = new Window(320, 280, "Simple Shm");
  win->SetAppId("Simple-Shm");

  auto *widget = new Spinner;
  win->SetContentView(widget);

  win->Show();

  return app.Run();
}
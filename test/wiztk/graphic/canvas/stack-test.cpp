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

#include "stack-test.hpp"

#include "wiztk/base/color.hpp"
#include "wiztk/base/rect.hpp"
#include "wiztk/graphic/paint.hpp"
#include "wiztk/graphic/canvas.hpp"
#include "wiztk/graphic/bitmap.hpp"

using namespace wiztk;
using namespace wiztk::base;
using namespace wiztk::graphic;

static const int kWidth = 400;
static const int kHeight = 300;
static const std::string kFileNamePrefix("graphic_canvas_");

TEST_F(StackTest, save_layer_1) {
  Bitmap bitmap;
  bitmap.AllocateN32Pixels(kWidth, kHeight);

  Canvas canvas(bitmap);
  canvas.Clear(0xFFFFFFFF);

  Paint paint;
  paint.SetColor(0xFFFF0000);
  RectF rect = RectF::FromXYWH(0.f, 0.f, kWidth, kHeight);
  rect = rect.Inset(50.f);
  canvas.DrawRect(rect, paint);

  canvas.SaveLayer(nullptr, nullptr);
  paint.SetColor(0xFF0000FF);
  canvas.DrawRect(RectF::FromXYWH(100, 100, 80, 100), paint);
  canvas.Restore();

  canvas.Flush();

  std::string filename = kFileNamePrefix + "save_layer_1.png";
  bitmap.WriteToFile(filename);

  std::cout << std::endl
            << "Check image file: " << filename
            << std::endl
            << std::endl;

  ASSERT_TRUE(true);
}
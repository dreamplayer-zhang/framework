/*
 * Copyright 2017 - 2018 The WizTK Authors.
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

#include <wiztk/gui/push-button.hpp>
#include <wiztk/gui/mouse-event.hpp>
#include <wiztk/gui/context.hpp>

#include <wiztk/graphics/canvas.hpp>
#include <wiztk/graphics/paint.hpp>
#include <wiztk/graphics/path.hpp>
#include <wiztk/graphics/gradient-shader.hpp>
#include "wiztk/graphics/font-style.hpp"

#include <wiztk/gui/theme.hpp>

#include <wiztk/gui/timer.hpp>
#include "wiztk/base/color.hpp"

namespace wiztk {
namespace gui {

using base::RectF;
using graphics::Canvas;
using graphics::Paint;
using graphics::Path;
using graphics::Shader;
using graphics::Font;
using graphics::FontStyle;
using graphics::TextAlignment;

PushButton::PushButton(const std::string &text)
    : AbstractButton(text) {
  /* Debug */
  srand((unsigned int) Timer::GetClockTime());
  regular_.red = std::rand() % 255 / 255.f;
  regular_.green = std::rand() % 255 / 255.f;
  regular_.blue = std::rand() % 255 / 255.f;

  highlight_ = regular_ + 25;
  active_ = regular_ - 25;
}

PushButton::~PushButton() = default;

void PushButton::OnDraw(const Context &context) {
  Canvas *canvas = context.canvas();

  const RectF &rect = GetBounds();
  int scale = context.surface()->GetScale();

  canvas->Scale(scale, scale);

  Paint paint;
  paint.SetAntiAlias(true);
  if (IsHovered()) {
    if (IsPressed()) {
      paint.SetColor(active_);
      canvas->DrawRect(rect, paint);
    } else {
      paint.SetColor(highlight_);
      canvas->DrawRect(rect, paint);
    }
  } else {
    paint.SetColor(regular_);
    canvas->DrawRect(rect, paint);
  }

  const Font &font = GetFont();
//  const std::string &text = GetText();

//  paint.SetColor(schema.inactive.foreground.color);
  ColorF text_color = regular_;
  text_color.ReverseRGB();
  paint.SetColor(text_color);
  paint.SetStyle(Paint::kStyleFill);
  paint.SetFont(font);
  paint.SetTextSize(font.GetSize() * scale);

  paint.SetTextAlign(TextAlignment::kCenter);
  canvas->DrawText(GetText(), rect.center_x(), rect.center_y(), paint, TextAlignment::kMiddle);
}

} // namespace gui
} // namespace wiztk

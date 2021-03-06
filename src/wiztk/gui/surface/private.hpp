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

#ifndef WIZTK_GUI_SURFACE_PRIVATE_HPP_
#define WIZTK_GUI_SURFACE_PRIVATE_HPP_

#include "wiztk/gui/surface.hpp"
#include "wiztk/gui/abstract-rendering-api.hpp"
#include "wiztk/gui/abstract-rendering-backend.hpp"

namespace wiztk {
namespace gui {

struct Surface::Private {

  using PointI = base::Point2I;

  WIZTK_DECLARE_NONCOPYABLE_AND_NONMOVALE(Private);
  Private() = delete;

  Private(Surface *surface, AbstractEventHandler *event_handler, const Margin &margin)
      : margin(margin),
        event_handler(event_handler),
        render_task(surface),
        commit_task(surface) {
  }

  ~Private() = default;

  Size size;

  Margin margin;

  struct wl_surface *wl_surface = nullptr;

  CommitMode commit_mode = kSynchronized;

  Transform transform = kTransformNormal;

  int32_t scale = 1;

  AbstractEventHandler *event_handler = nullptr;

  /**
   * Position in parent surface
   *
   * For root surface, this should always be (0, 0)
   */
  PointI relative_position;

  /**
    * @brief The parent surface
    */
  Surface *parent = nullptr;

  /**
    * @brief The sibling surface placed up
    */
  Surface *above = nullptr;

  /**
    * @brief The sibling surface placed down
    */
  Surface *below = nullptr;

  /**
   * @brief The shell surface shows front
   */
  Surface *upper = nullptr;

  /**
   * @brief The shell surface shows back
   */
  Surface *lower = nullptr;

  AbstractRenderingAPI *rendering_api = nullptr;

  AbstractRenderingBackend *rendering_backend = nullptr;

  union {
    void *placeholder;
    Shell *shell;
    Sub *sub;
  } role = {nullptr};

  RenderTask render_task;

  CommitTask commit_task;

  base::Deque<AbstractView::RenderNode> render_deque;

  static void OnEnter(void *data, struct wl_surface *wl_surface,
                      struct wl_output *wl_output);

  static void OnLeave(void *data, struct wl_surface *wl_surface,
                      struct wl_output *wl_output);

  static const struct wl_surface_listener kListener;

};

} // namespace gui
} // namespace wiztk

#endif // WIZTK_GUI_SURFACE_PRIVATE_HPP_

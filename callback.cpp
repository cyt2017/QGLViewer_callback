/****************************************************************************

 Copyright (C) 2002-2014 Gilles Debunne. All rights reserved.

 This file is part of the QGLViewer library version 2.7.1.

 http://www.libqglviewer.com - contact@libqglviewer.com

 This file may be used under the terms of the GNU General Public License 
 versions 2.0 or 3.0 as published by the Free Software Foundation and
 appearing in the LICENSE file included in the packaging of this file.
 In addition, as a special exception, Gilles Debunne gives you certain 
 additional rights, described in the file GPL_EXCEPTION in this package.

 libQGLViewer uses dual licensing. Commercial/proprietary software must
 purchase a libQGLViewer Commercial License.

 This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************************/

#include "callback.h"
#include <QGLViewer/qglviewer.h>
#include <math.h>

Scene::Scene(const QGLViewer *const v) {
  // Connect the viewer signal to our draw slot.
    //!将观看信号连接到绘图槽
  connect(v, SIGNAL(drawNeeded()), this, SLOT(draw()));
}

//! Draws a spiral 绘制一个螺旋 模型
void Scene::draw() {
  const float nbSteps = 200.0;
  glBegin(GL_QUAD_STRIP);//!点通过GL_QUAD_STRIP生成四边形
  for (float i = 0; i < nbSteps; ++i) {
    float ratio = i / nbSteps;//(0~0.995)
    float angle = 21.0 * ratio;//(0~20.895)
    float c = cos(angle);//(0.934~1)
    float s = sin(angle);//(0~0.3566)
    float r1 = 1.0 - 0.8 * ratio;//(0.204~1)
    float r2 = 0.8 - 0.8 * ratio;//(0.004~0.8)
    float alt = ratio - 0.5;//(-0.5~0.495)
    const float nor = .5;
    const float up = sqrt(1.0 - nor * nor);//0.866
    glColor3f(1.0 - ratio, 0.2f, ratio);
    glNormal3f(nor * c, up, nor * s);
    glVertex3f(r1 * c, alt, r1 * s);
    glVertex3f(r2 * c, alt + 0.05, r2 * s);
  }
  glEnd();
}

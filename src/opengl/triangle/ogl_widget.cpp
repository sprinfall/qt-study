#include "opengl/triangle/ogl_widget.h"

#include <QOpenGLShader>
#include <QOpenGLContext>
#include <QWheelEvent>

OglWidget::OglWidget(QWidget* parent)
    : QOpenGLWidget(parent),
      vbo_(QOpenGLBuffer::VertexBuffer),
      ibo_(QOpenGLBuffer::IndexBuffer) {
}

OglWidget::~OglWidget() {
  // Make sure the context is current and then explicitly
  // destroy all underlying OpenGL resources.
  makeCurrent();

  delete program_;
  delete vshader_;
  delete fshader_;

  vbo_.destroy();
  ibo_.destroy();

  //vao_.destroy();

  doneCurrent();
}

void OglWidget::mousePressEvent(QMouseEvent* evt) {
  //if (evt->buttons().testFlag(Qt::LeftButton)) {
  //  last_pos_ = evt->pos();
  //}
  QOpenGLWidget::mousePressEvent(evt);
}

void OglWidget::mouseMoveEvent(QMouseEvent* evt) {
  //if (evt->buttons().testFlag(Qt::LeftButton)) {
  //  // Rotate

  //  // See: https://stackoverflow.com/questions/14308595/rotate-camera-around-point-of-interest-in-opengl

  //  QPoint pos = evt->pos();

  //  QPoint diff = pos - last_pos_;

  //  auto axis = QVector3D{ (float)diff.y(), (float)diff.x(), 0.f }.normalized();
  //  auto angle = QLineF{ pos, last_pos_ }.length() / 4.f;

  //  quaternion_ = QQuaternion::fromAxisAndAngle(axis, angle);

  //  // NOTE: 这边是累加
  //  view_matrix_.rotate(quaternion_);

  //  last_pos_ = pos;

  //  update();
  //}

  QOpenGLWidget::mouseMoveEvent(evt);
}

void OglWidget::wheelEvent(QWheelEvent* evt) {
  //QPoint delta = evt->angleDelta();
  //Zoom(delta.y() > 0);

  //update();

  QOpenGLWidget::wheelEvent(evt);
}

void OglWidget::initializeGL() {
  initializeOpenGLFunctions();

  bool transparent = true;
  glClearColor(0, 0, 0, transparent ? 0 : 1);

  // clang-format off
  float vertices_[12] {
    0.5f,  0.5f, 0.0f,  // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
  };

  unsigned int indices_[6] {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
  };

  // clang-format on
  //vao_.create();
  //if (vao_.isCreated()) {
  //  vao_.bind();
  //}

  vshader_ = new QOpenGLShader{ QOpenGLShader::Vertex };

  const char* vsrc =
      "#version 330 core\n"
      "layout (location = 0) in vec3 vertex;\n"
      "void main()\n"
      "{\n"
      "    gl_Position = vec4(vertex, 1.0);\n"
      "}\n";

  vshader_->compileSourceCode(vsrc);

  fshader_ = new QOpenGLShader{ QOpenGLShader::Fragment };

  const char* fsrc =
      "#version 330 core\n"
      "out vec4 FragColor;"
      "void main()\n"
      "{\n"
      "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n";

  fshader_->compileSourceCode(fsrc);

  program_ = new QOpenGLShaderProgram{};
  program_->addShader(vshader_);
  program_->addShader(fshader_);
  program_->link();

  vertex_attr_ = 0;  // layout (location = 0)
  //vertex_attr_ = program_->attributeLocation("vertex");

  vbo_.create();
  vbo_.bind();
  vbo_.allocate(&vertices_[0], sizeof(float) * 12);
  //program_->setAttributeBuffer(vertex_attr_, GL_FLOAT, 0, 3, 0);
  vbo_.release();

  ibo_.create();
  ibo_.bind();
  ibo_.allocate(indices_, sizeof(unsigned int) * 6);
  ibo_.release();
}

void OglWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  //vao_.bind();

  program_->bind();
  program_->enableAttributeArray(vertex_attr_);

  vbo_.bind();
  program_->setAttributeBuffer(vertex_attr_, GL_FLOAT, 0, 3, 0);
  vbo_.release();

  ibo_.bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
  ibo_.release();

  program_->disableAttributeArray(vertex_attr_);
  program_->release();
}

void OglWidget::resizeGL(int width, int height) {
  //glViewport(0, 0, width, height);

  //UpdateProjectionMatrix(width, height);
}

// in: 放大 (拉近); out: 缩小
// range_ 值越小，模型看上去越大；详见 Ortho() 即 glOrtho。
void OglWidget::Zoom(bool in) {
  //if (in) {
  //  range_ /= 1.25;
  //  if (range_ < 5) {
  //    range_ = 5;
  //  }
  //} else {
  //  range_ *= 1.25;
  //  if (range_ > 75) {
  //    range_ = 75;
  //  }
  //}

  //UpdateProjectionMatrix(width(), height());
  //update();
}

void OglWidget::UpdateProjectionMatrix(int width, int height) {
  //proj_matrix_.setToIdentity();

  //int trans_x = 0;
  //int trans_y = 0;

  //float ratio = (float)width / height;

  //float left = -(range_ * ratio) - trans_x;
  //float right = (range_ * ratio) - trans_x;
  //float bottom = -range_ - trans_y;
  //float top = range_ - trans_y;
  //float znear = -(range_ + 100.f);
  //float zfar = (range_ + 100.f);

  //proj_matrix_.ortho(left, right, bottom, top, znear, zfar);
}

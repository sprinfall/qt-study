#include "opengl/texture/ogl_widget.h"

#include <QOpenGLShader>
#include <QOpenGLContext>
#include <QOpenGLTexture>

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

  vao_.destroy();

  if (texture_ != nullptr) {
    delete texture_;
  }

  doneCurrent();
}

void OglWidget::initializeGL() {
  initializeOpenGLFunctions();

  bool transparent = true;
  glClearColor(0, 0, 0, transparent ? 0 : 1);

  vshader_ = new QOpenGLShader{ QOpenGLShader::Vertex };

  const char* vsrc =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "layout (location = 1) in vec3 aColor;\n"
      "layout (location = 2) in vec2 aTexCoord;\n"
      "//out vec3 ourColor;\n"
      "out vec2 TexCoord;\n"
      "void main()\n"
      "{\n"
      "    gl_Position = vec4(aPos, 1.0);\n"
      "    //ourColor = aColor;\n"
      "    TexCoord = aTexCoord;\n"
      "}\n";

  vshader_->compileSourceCode(vsrc);

  fshader_ = new QOpenGLShader{ QOpenGLShader::Fragment };

  const char* fsrc =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "//in vec3 ourColor;\n"
      "in vec2 TexCoord;\n"
      "uniform sampler2D texture1;\n"
      "void main()\n"
      "{\n"
      "    FragColor = texture(texture1, TexCoord);\n"
      "}\n";

  fshader_->compileSourceCode(fsrc);

  program_ = new QOpenGLShaderProgram{};
  program_->addShader(vshader_);
  program_->addShader(fshader_);
  program_->link();

  // clang-format off
  float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,  // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f   // top left 
  };
  unsigned int indices[] = {  
    0, 1, 3,  // first triangle
    1, 2, 3   // second triangle
  };
  // clang-format on

  vao_.create();
  //if (vao_.isCreated()) {
    vao_.bind();
  //}

  vbo_.create();
  vbo_.bind();
  vbo_.allocate(vertices, sizeof(vertices));

  // position attribute
  program_->setAttributeBuffer(0, GL_FLOAT, 0, 3, 8 * sizeof(float));
  program_->enableAttributeArray(0);
  // color attribute
  //program_->setAttributeBuffer(1, GL_FLOAT, 3 * sizeof(float), 3, 8 * sizeof(float));
  //program_->enableAttributeArray(1);
  // texture coord attribute
  program_->setAttributeBuffer(2, GL_FLOAT, 6 * sizeof(float), 2, 8 * sizeof(float));
  program_->enableAttributeArray(2);

  vbo_.release();

  ibo_.create();
  ibo_.bind();
  ibo_.allocate(indices, sizeof(indices));
  ibo_.release();

  QString texture_file{ "D:/github/qt-study/src/opengl/texture/container.jpg" };
  QImage image{ texture_file };
  if (image.isNull()) {
    qDebug() << "Invalid texture image!";
  }

  texture_ = new QOpenGLTexture{ image.mirrored() };

  texture_->setMinificationFilter(QOpenGLTexture::Nearest);
  texture_->setMagnificationFilter(QOpenGLTexture::Linear);
  texture_->setWrapMode(QOpenGLTexture::Repeat);

  vao_.release();
}

void OglWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  program_->bind();

  program_->setUniformValue("texture1", 1);

  vao_.bind();

  texture_->bind(1);

  ibo_.bind();
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
  ibo_.release();

  vao_.release();

  program_->release();
}

void OglWidget::resizeGL(int width, int height) {
}

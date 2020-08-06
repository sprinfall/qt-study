#ifndef OGL_WIDGET_H_
#define OGL_WIDGET_H_

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLTexture;

class OglWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

public:
  explicit OglWidget(QWidget* parent = nullptr);

  ~OglWidget() override;

protected:
  // QOpenGLWidget override

  // Sets up the OpenGL resources and state. Gets called once before the first
  // time resizeGL() or paintGL() is called.
  void initializeGL() override;

  // Renders the OpenGL scene. Gets called whenever the widget needs to be
  // updated.
  void paintGL() override;

  // Sets up the OpenGL viewport, projection, etc. Gets called whenever the
  // widget has been resized (and also when it is shown for the first time
  // because all newly created widgets get a resize event automatically).
  void resizeGL(int width, int height) override;

private:
  QOpenGLShader* vshader_ = nullptr;
  QOpenGLShader* fshader_ = nullptr;
  QOpenGLShaderProgram* program_ = nullptr;

  QOpenGLVertexArrayObject vao_;

  QOpenGLBuffer vbo_;
  QOpenGLBuffer ibo_;

  QOpenGLTexture* texture_ = nullptr;
};

#endif  // OGL_WIDGET_H_

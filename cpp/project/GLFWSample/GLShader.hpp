const char *vertex_shader =
"void main(void){ \n"
  "gl_Position = gl_ModelViewMatrix * gl_Vertex; \n"
  "gl_FrontColor = vec4(1.0) - gl_Color; \n"
"}";

const char *fragment_shader =
"void main(){ \n"
"  gl_FragColor = vec4(1.0) - gl_Color; \n"
"}";
GLuint shader_program;

//リンクする
void Link(GLuint prog)
{
  GLsizei size, len;
  GLint linked;
  char *infoLog;
  glLinkProgram(prog);
  glGetProgramiv(prog, GL_LINK_STATUS, &linked);

  if (linked == GL_FALSE)
  {
    printf("リンクできませんでした!! \n");
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &size);
    if (size > 0)
    {
      infoLog = (char *)malloc(size);
      glGetProgramInfoLog(prog, size, &len, infoLog);
      printf(infoLog);
      free(infoLog);
    }
  }
}

void CompileAndLinkShader()
{
  //glewの初期化
  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    printf("Error: %s\n", glewGetErrorString(err));
  }

  // GPU,OpenGL情報
  printf("VENDOR= %s \n", glGetString(GL_VENDOR));
  printf("GPU= %s \n", glGetString(GL_RENDERER));
  printf("OpenGL= %s \n", glGetString(GL_VERSION));
  printf("GLSL= %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));

  GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vshader, 1, &vertex_shader, 0);

  // Compile the fragment shader.
  GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fshader, 1, &fragment_shader, 0);

  // Create a program that stitches the two shader stages together.
  shader_program = glCreateProgram();
  glAttachShader(shader_program, vshader);
  glAttachShader(shader_program, fshader);

  glDeleteShader(vshader);
  glDeleteShader(fshader);

  Link(shader_program);
}

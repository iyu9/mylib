//Shader Utils

const char *vertex_shader =
  "in vec4 position;\n"
  "out vec4 myPos;\n"
  "void main() {\n"
  "  myPos = position;\n"
  "  gl_Position = position;\n"
  "}\n";

const char *fragment_shader =
  "uniform float phase;\n"
  "in vec4 myPos;\n"
  "void main() {\n"
  "  gl_FragColor = ...;\n"
  "}\n";

void CompileAndLinkShader()
{
  // Compile the vertex shader.
  GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vshader, 1, &vertex_shader, 0);
   
  // Compile the fragment shader.
  GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fshader, 1, &fragment_shader, 0);
    
  // Create a program that stitches the two shader stages together.
  GLuint shader_program = glCreateProgram();
  glAttachShader(shader_program, vshader);
  glAttachShader(shader_program, fshader);
  glLinkProgram(shader_program);
}

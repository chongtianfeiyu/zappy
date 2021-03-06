#version 120

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform sampler2D fTexture0;

attribute vec4 vPosition;
attribute vec4 vColor;
attribute vec4 vNormal;
attribute vec2 vTexCoord;

varying vec4 fColor;
varying vec4 fPosition;
varying vec4 fNormal;
varying vec2 fUv;

void main(void)
{
  fPosition = model * vPosition;
  fColor = vColor;
  fNormal = normalize(model * vec4(vNormal.xyz, 0.0));
  fUv = vTexCoord;
  gl_Position = projection * view * model * vPosition;
}

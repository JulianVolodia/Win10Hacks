#ifdef GL_ES
    precision mediump float;
    varying mediump vec2 v_texCoord1;
    varying mediump vec2 v_texCoord2;
    varying mediump vec2 v_texCoord3;
#else
    varying vec2 v_texCoord1;
    varying vec2 v_texCoord2;
    varying vec2 v_texCoord3;
#endif

uniform sampler2D CC_Texture0;
uniform sampler2D CC_Texture1;
uniform sampler2D CC_Texture2;

uniform float u_amount;

void main(void)
{
}
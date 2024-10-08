#version 130




in vec2 vfTexCoord;
flat in int vfCharIndex;


out vec4 fragColor;


uniform sampler2D bitfontAtlas;

uniform vec4 fontColor;
uniform vec4 backColor;




void main(){

	if(vfCharIndex != 127-32){
		if (texture(bitfontAtlas, vfTexCoord).w == 0.){
			fragColor = backColor;
		}else{
			fragColor = fontColor;
		}
	}else{
		fragColor = vec4(0.,0.,0.,0.);
	}
}





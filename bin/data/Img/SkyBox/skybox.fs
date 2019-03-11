#version 330 core

in vec3 TexCoords;
out vec4 FragColor;


uniform samplerCube skybox;
uniform vec3 color;

void main()
{    
    FragColor = texture(skybox, TexCoords);
	//FragColor = vec4(texture(skybox, TexCoords), 1.0f);
	//FragColor = vec4( 1.0, 0, 0, 1 )
	//FragColor.rgb = color;
    //FragColor.a = 1;
}
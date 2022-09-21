//
// FOnline default effect
// For interface sprites
//

#include "IOStructures.inc"

sampler2D MainTexture;


// Vertex shader
VS_2D VSSimple(VS_2D input)
{
	// Just pass forward
	return input;
}


// Pixel shader
float4 PSSimple(PS_2D input) : COLOR
{
	float4 output;

	// Sample
	float4 texColor = tex2D(MainTexture, input.Tex);
	output.rgb = (texColor.rgb * input.Color.rgb) * 2;
	output.a = texColor.a * input.Color.a;

	return output;
}


// Techniques
technique Simple
{
	pass p0
	{
		VertexShader = (compile vs_2_0 VSSimple());
		PixelShader  = (compile ps_2_0 PSSimple());
	}
}


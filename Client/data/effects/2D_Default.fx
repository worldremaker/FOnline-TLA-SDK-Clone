//
// FOnline default effect
// For sprites
//

#include "IOStructures.inc"

sampler2D MainTexture;
sampler2D EggTexture;


// Vertex shader
VS_2D_EGG VSSimple(VS_2D_EGG input)
{
	// Just pass forward
	return input;
}


// Pixel shader
float4 PSSimple(PS_2D_EGG input) : COLOR
{
	float4 output;

	// Sample
	float4 texColor = tex2D(MainTexture, input.Tex);
	output.rgb = (texColor.rgb * input.Color.rgb) * 2;
	output.a = texColor.a * input.Color.a;

	// Egg transparent
	if(input.TexEgg.x != 0.0f) output.a *= tex2D(EggTexture, input.TexEgg).a;

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


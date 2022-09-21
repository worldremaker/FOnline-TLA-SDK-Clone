//
// FOnline default effect
// For primitives (light, mini-map, pip-boy maps, etc)
//

#include "IOStructures.inc"


// Vertex shader
VS_2D_PRIMITIVE VSSimple(VS_2D_PRIMITIVE input)
{
	// Just pass forward
	return input;
}


// Pixel shader
float4 PSSimple(PS_2D_PRIMITIVE input) : COLOR
{
	// Just pass forward
	return input.Color;
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


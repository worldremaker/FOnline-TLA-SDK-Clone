//
// FOnline default effect
// For skinned and static meshes
//

#include "IOStructures.inc"

// Texture
sampler2D MainTexture;

// Bones per vertex, for skinned meshes
int BonesInfluences               = 2;

// Ground position
float4 GroundPosition             = {0.0f, 0.0f, 0.0f, 0.0f};

// Lighting
float4 LightDir                          = {0.0f, 0.0f, -1.0f, 1.0f}; // Light direction 
float4 LightDiffuse                      = {0.6f, 0.6f, 0.6f, 1.0f};  // Light diffuse color
float4 MaterialAmbient : MATERIALAMBIENT = {0.1f, 0.1f, 0.1f, 1.0f};  // Ambient color
float4 MaterialDiffuse : MATERIALDIFFUSE = {0.8f, 0.8f, 0.8f, 1.0f};  // Diffuse color

// Matrix pallette, for static meshes used WorldMatrices[0]
static const int MaxMatrices      = 60;
float4x3 WorldMatrices[MaxMatrices] : WORLDMATRIXARRAY;
float4x4 ProjectionMatrix           : VIEWPROJECTION;

// Some useful game angles
static const float CameraAngle    = 25.7f * 3.141592654f / 180.0f;
static const float CameraAngleCos = cos(CameraAngle);
static const float CameraAngleSin = sin(CameraAngle);
static const float ShadowAngle    = 14.3f * 3.141592654f / 180.0f;
static const float ShadowAngleTan = tan(ShadowAngle);


// Vertex shader
VS_3D_OUTPUT VSSimpleNormal(VS_3D_SIMPLE_INPUT input)
{
	VS_3D_OUTPUT output;
	float3 pos    = mul(input.Pos, WorldMatrices[0]);
	float3 normal = normalize(mul(input.Normal, WorldMatrices[0]));

	// Calculate position
	output.Pos = mul(float4(pos.xyz, 1.0f), ProjectionMatrix);

	// Calculate color
	output.Diffuse.rgb = MaterialAmbient.rgb + max(0.0f, dot(normal, LightDir.rgb)) * MaterialDiffuse.rgb;
	output.Diffuse.rgb *= LightDiffuse.rgb;
	output.Diffuse.a = 1.0f;

	// Copy the input texture coordinate through
	output.Tex = input.Tex;

	return output;
}

VS_3D_OUTPUT_SHADOW VSSimpleShadow(VS_3D_SIMPLE_INPUT_SHADOW input)
{
	VS_3D_OUTPUT_SHADOW output;
	float3           pos = mul(input.Pos, WorldMatrices[0]);

	// Calculate shadow position
	float d = (pos.y - GroundPosition.y) * CameraAngleCos - (pos.z - GroundPosition.z) * CameraAngleSin;
	pos.y -= d * CameraAngleCos;
	pos.z += d * CameraAngleSin;
	d *= ShadowAngleTan;
	pos.y += d * CameraAngleSin;
	pos.z += d * CameraAngleCos;

	// Transform position from world space into view and then projection space
	output.Pos = mul(float4(pos.xyz, 1.0f), ProjectionMatrix);

	// Copy the input texture coordinate through
	output.Tex = input.Tex;

	return output;
}

VS_3D_OUTPUT VSSkinnedNormal(VS_3D_SKINNED_INPUT input, uniform int bones)
{
	VS_3D_OUTPUT   output;
	float3      pos        = 0.0f;
	float3      normal     = 0.0f;    
	float       lastWeight = 0.0f;

	// Cast the vectors to arrays for use in the for loop below
	float blendWeightsArray[4] = (float[4])input.BlendWeights;
	int   indexArray[4]        = (int[4])D3DCOLORtoUBYTE4(input.BlendIndices);

	// Calculate the pos using the "normal" weights 
	// and accumulate the weights to calculate the last weight
	for(int i = 0; i < bones-1; i++)
	{
		lastWeight = lastWeight + blendWeightsArray[i];
		pos += mul(input.Pos, WorldMatrices[indexArray[i]]) * blendWeightsArray[i];
		normal += mul(input.Normal, WorldMatrices[indexArray[i]]) * blendWeightsArray[i];
	}
	lastWeight = 1.0f - lastWeight; 

	// Now that we have the calculated weight, add in the final influence
	pos += (mul(input.Pos, WorldMatrices[indexArray[bones-1]]) * lastWeight);
	normal += (mul(input.Normal, WorldMatrices[indexArray[bones-1]]) * lastWeight); 

	// Transform position from world space into view and then projection space
	output.Pos = mul(float4(pos.xyz, 1.0f), ProjectionMatrix);

	// Normalize normals
	normal = normalize(normal);

	// Shade
	output.Diffuse.rgb = MaterialAmbient.rgb + max(0.0f, dot(normal, LightDir.rgb)) * MaterialDiffuse.rgb;
	output.Diffuse.rgb *= LightDiffuse.rgb;
	output.Diffuse.a = 1.0f;

	// Copy the input texture coordinate through
	output.Tex = input.Tex;

	return output;
}

VS_3D_OUTPUT_SHADOW VSSkinnedShadow(VS_3D_SKINNED_INPUT_SHADOW input, uniform int bones)
{
	VS_3D_OUTPUT_SHADOW   output;
	float3             pos        = 0.0f;
	float              lastWeight = 0.0f;

	// Cast the vectors to arrays for use in the for loop below
	float blendWeightsArray[4] = (float[4])input.BlendWeights;
	int   indexArray[4]        = (int[4])D3DCOLORtoUBYTE4(input.BlendIndices);

	// Calculate the pos using the "normal" weights 
	// and accumulate the weights to calculate the last weight
	for(int i = 0; i < bones-1; i++)
	{
		lastWeight = lastWeight + blendWeightsArray[i];
		pos += mul(input.Pos, WorldMatrices[indexArray[i]]) * blendWeightsArray[i];
	}
	lastWeight = 1.0f - lastWeight;

	// Now that we have the calculated weight, add in the final influence
	pos += (mul(input.Pos, WorldMatrices[indexArray[bones-1]]) * lastWeight);

	// Calculate shadow position
	float d = (pos.y - GroundPosition.y) * CameraAngleCos - (pos.z - GroundPosition.z) * CameraAngleSin;
	pos.y -= d * CameraAngleCos;
	pos.z += d * CameraAngleSin;
	d *= ShadowAngleTan;
	pos.y += d * CameraAngleSin;
	pos.z += d * CameraAngleCos;

	// Transform position from world space into view and then projection space
	output.Pos = mul(float4(pos.xyz, 1.0f), ProjectionMatrix);

	// Copy the input texture coordinate through
	output.Tex = input.Tex;

	return output;
}


// Pixel shader
float4 PSNormal(PS_3D input) : COLOR
{
	float4 output;

	// Sample
	output = tex2D(MainTexture, input.Tex) * input.Color;

	return output;
}

float4 PSShadow(PS_3D_SHADOW input) : COLOR
{
	float4 output;

	// Black shadow
	output.rgb = 0.0f;

	// Transparent from texture
	output.a = tex2D(MainTexture, input.Tex).a;

	return output;
}


// Techniques
VertexShader VSArray[10] =
{
	compile vs_2_0 VSSimpleNormal(),
	compile vs_2_0 VSSimpleShadow(),
	compile vs_2_0 VSSkinnedNormal(1),
	compile vs_2_0 VSSkinnedNormal(2),
	compile vs_2_0 VSSkinnedNormal(3),
	compile vs_2_0 VSSkinnedNormal(4),
	compile vs_2_0 VSSkinnedShadow(1),
	compile vs_2_0 VSSkinnedShadow(2),
	compile vs_2_0 VSSkinnedShadow(3),
	compile vs_2_0 VSSkinnedShadow(4)
};

PixelShader PSArray[2] =
{
	compile ps_2_0 PSNormal(),
	compile ps_2_0 PSShadow()
};

technique Simple
{
	pass p0 { VertexShader = (VSArray[0]); PixelShader = (PSArray[0]); }
}

technique SimpleWithShadow
{
	pass p0 { VertexShader = (VSArray[1]); PixelShader = (PSArray[1]); }
	pass p1 { VertexShader = (VSArray[0]); PixelShader = (PSArray[0]); }
}

technique Skinned
{
	pass p0 { VertexShader = (VSArray[2 + BonesInfluences]);     PixelShader = (PSArray[0]); }
}

technique SkinnedWithShadow
{
	pass p0 { VertexShader = (VSArray[2 + BonesInfluences + 4]); PixelShader = (PSArray[1]); }
	pass p1 { VertexShader = (VSArray[2 + BonesInfluences]);     PixelShader = (PSArray[0]); }
}



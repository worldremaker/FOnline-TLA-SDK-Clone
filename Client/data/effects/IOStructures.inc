//
// FOnline data input/output structures
// Included to other effects
//


// Vertex shader
struct VS_3D_SIMPLE_INPUT
{
	float4 Pos          : POSITION;
	float3 Normal       : NORMAL;
	float3 Tex          : TEXCOORD;
};

struct VS_3D_SIMPLE_INPUT_SHADOW
{
	float4 Pos          : POSITION;
	float3 Tex          : TEXCOORD;
};

struct VS_3D_SKINNED_INPUT
{
	float4 Pos          : POSITION;
	float4 BlendWeights : BLENDWEIGHT;
	float4 BlendIndices : BLENDINDICES;
	float3 Normal       : NORMAL;
	float3 Tex          : TEXCOORD;
};

struct VS_3D_SKINNED_INPUT_SHADOW
{
	float4 Pos          : POSITION;
	float4 BlendWeights : BLENDWEIGHT;
	float4 BlendIndices : BLENDINDICES;
	float3 Tex          : TEXCOORD;
};

struct VS_3D_OUTPUT
{
	float4 Pos          : POSITION;
	float4 Diffuse      : COLOR;
	float2 Tex          : TEXCOORD;
};

struct VS_3D_OUTPUT_SHADOW
{
	float4 Pos          : POSITION;
	float3 Tex          : TEXCOORD;
};

struct VS_2D_PRIMITIVE
{
	float4 Pos     : POSITION;
	float4 Diffuse : COLOR;
};

struct VS_2D
{
	float4 Pos     : POSITION;
	float4 Diffuse : COLOR;
	float2 Tex     : TEXCOORD;
};

struct VS_2D_EGG
{
	float4 Pos     : POSITION;
	float4 Diffuse : COLOR;
	float2 Tex     : TEXCOORD0;
	float2 TexEgg  : TEXCOORD1;
};


// Pixel shader
struct PS_3D
{
	float4 Color   : COLOR;
	float2 Tex     : TEXCOORD;
};

struct PS_3D_SHADOW
{
	float2 Tex     : TEXCOORD;
};

struct PS_2D_PRIMITIVE
{
	float4 Color   : COLOR;
};

struct PS_2D
{
	float4 Color   : COLOR;
	float2 Tex     : TEXCOORD;
};

struct PS_2D_EGG
{
	float4 Color   : COLOR;
	float2 Tex     : TEXCOORD0;
	float2 TexEgg  : TEXCOORD1;
};





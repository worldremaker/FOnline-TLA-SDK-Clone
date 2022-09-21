//////////////////////////////////////////////////////////////////////////
// FOnline effects specifications
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Default effects
//////////////////////////////////////////////////////////////////////////

 Type              File name
2D sprites        2D_Default.fx
3D models         3D_Default.fx
Interface         Interface_Default.fx
Fonts             Font_Default.fx
Primitive         Primitive_Default.fx

//////////////////////////////////////////////////////////////////////////
// Structures pipeline
// Structures declared in IOStructures.inc
//////////////////////////////////////////////////////////////////////////

 Effect             Vertex input                  Vertex output          Pixel input        Pixel output
2D Game sprites:   VS_2D_EGG                  -> VS_2D_EGG           -> PS_2D_EGG       -> float4 : COLOR
Interface sprites: VS_2D                      -> VS_2D               -> PS_2D           -> float4 : COLOR
Font sprites:      VS_2D                      -> VS_2D               -> PS_2D           -> float4 : COLOR
Primitives:        VS_2D_PRIMITIVE            -> VS_2D_PRIMITIVE     -> PS_2D_PRIMITIVE -> float4 : COLOR
3D Simple-Normal:  VS_3D_SIMPLE_INPUT         -> VS_3D_OUTPUT        -> PS_3D           -> float4 : COLOR
3D Simple-Shadow:  VS_3D_SIMPLE_INPUT_SHADOW  -> VS_3D_OUTPUT_SHADOW -> PS_3D_SHADOW    -> float4 : COLOR
3D Skinned-Normal: VS_3D_SKINNED_INPUT        -> VS_3D_OUTPUT        -> PS_3D           -> float4 : COLOR
3D Skinned-Shadow: VS_3D_SKINNED_INPUT_SHADOW -> VS_3D_OUTPUT_SHADOW -> PS_3D_SHADOW    -> float4 : COLOR

//////////////////////////////////////////////////////////////////////////
// Effect variables
// Engine updates it automatically
// Include/exclude as you wish, this detecting automatically
//////////////////////////////////////////////////////////////////////////

// 2D variables

sampler2D MainTexture;  // Main texture
sampler2D EggTexture;   // Egg texture, if this sampler not used than
                        // TexEgg will be equal to zero (x or y)

// Interface/Font variables

sampler2D MainTexture;  // Main texture

// 3D variables

sampler2D MainTexture;  // Main texture
int BonesInfluences;    // Bones per vertex, for skinned meshes
float4 GroundPosition;  // Ground position
float4 LightDir;        // Light direction 
float4 LightDiffuse;    // Light diffuse color
float4 MaterialAmbient; // Ambient color
float4 MaterialDiffuse; // Diffuse color

// Generic variables

float PassIndex;        // Number of current pass
float Time;             // Current time [0,120), in seconds, cycled
float TimeGame;         // Current game time [0,120), in seconds, cycled
float Random1Pass;      // Random value [0,1], value updated each pass
float Random2Pass;      // Random value [0,1], value updated each pass
float Random3Pass;      // Random value [0,1], value updated each pass
float Random4Pass;      // Random value [0,1], value updated each pass
float Random1Effect;    // Random value [0,1], value updated each effect
float Random2Effect;    // Random value [0,1], value updated each effect
float Random3Effect;    // Random value [0,1], value updated each effect
float Random4Effect;    // Random value [0,1], value updated each effect

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////


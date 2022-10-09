#ifndef __FONLINE__
#define __FONLINE__

//
// FOnline engine structures, for native working
// Last update 02.03.2011
// Server version 411, MSVS2008
// Default calling convention - cdecl
//

#pragma pack(8)

#define WIN32
#define NDEBUG
#define _WINDOWS
#define _MBCS
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _HAS_ITERATOR_DEBUGGING 0
#define _SECURE_SCL 0
#define _HAS_EXCEPTIONS 0

#define EXPORT extern "C" __declspec(dllexport)

#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class asIScriptEngine;

struct Mutex;
struct Spinlock;
struct SyncObj;
struct ScriptString;
struct ScriptArray;
struct CritterType;
struct ProtoItem;
struct GameVar;
struct TemplateVar;
struct NpcPlane;
struct GlobalMapGroup;
struct Item;
struct CritterTimeEvent;
struct Critter;
struct Client;
struct Npc;
struct CritterCl;
struct MapObject;
struct MapEntire;
struct SceneryToClient;
struct ProtoMap;
struct Map;
struct ProtoLocation;
struct Location;
struct Field;
struct SpriteInfo;
struct Sprite;

#ifdef __SERVER
typedef Critter CritterMutual;
#else
typedef CritterCl CritterMutual;
#endif

typedef unsigned __int64 uint64;
typedef unsigned int uint;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef __int64 int64;
typedef char int8;
typedef short int16;

typedef pair<int, int> IntPair;
typedef pair<uint, uint> UintPair;

typedef vector<uint> UintVec;
typedef vector<uint>::iterator UintVecIt;
typedef vector<uint16> Uint16Vec;
typedef vector<uint16>::iterator Uint16VecIt;
typedef vector<int> IntVec;
typedef vector<int>::iterator IntVecIt;
typedef vector<UintPair> UintPairVec;
typedef set<int> IntSet;
typedef set<int>::iterator IntSetIt;
typedef set<uint> UintSet;
typedef set<uint>::iterator UintSetIt;
typedef map<int, int> IntMap;
typedef set<int, int>::iterator IntMapIt;

typedef vector<NpcPlane*> NpcPlaneVec;
typedef vector<NpcPlane*>::iterator NpcPlaneVecIt;
typedef vector<Critter*> CrVec;
typedef vector<Critter*>::iterator CrVecIt;
typedef vector<CritterCl*> CrClVec;
typedef vector<CritterCl*>::iterator CrClVecIt;
typedef vector<Client*> ClVec;
typedef vector<Client*>::iterator ClVecIt;
typedef vector<Npc*> PcVec;
typedef vector<Npc*>::iterator PcVecIt;
typedef vector<Item*> ItemVec;
typedef vector<Item*>::iterator ItemVecIt;
typedef vector<MapObject*> MapObjectVec;
typedef vector<MapObject*>::iterator MapObjectVecIt;
typedef vector<Map*> MapVec;
typedef vector<Map*>::iterator MapVecIt;
typedef vector<Location*> LocVec;
typedef vector<Location*>::iterator LocVecIt;

// Generic
EXPORT extern void (*Log)(const char* frmt, ...);

#define STATIC_ASSERT(a)            {static int arr[(a)?1:-1];}
#define BIN__N(x)                   (x) | x>>3 | x>>6 | x>>9
#define BIN__B(x)                   (x) & 0xf | (x)>>12 & 0xf0
#define BIN8(v)                     (BIN__B(BIN__N(0x##v)))
#define BIN16(bin16,bin8)           ((BIN8(bin16)<<8)|(BIN8(bin8)))

#define FLAG(x,y)                   (((x)&(y))!=0)
#define CLAMP(x,low,high)           (((x)>(high))?(high):(((x)<(low))?(low):(x)))
#define SQRT3T2_FLOAT               (3.4641016151f)
#define SQRT3_FLOAT                 (1.732050807568877f)
#define RAD2DEG                     (57.29577951f)
#define CONVERT_GRAMM(x)            ((x)*453)

#define LEXEMS_SIZE                 (128)
#define MAX_HOLO_INFO               (250)
#define SCORES_MAX                  (50)
#define MAX_NPC_BAGS_PACKS          (20)
#define MAX_ENEMY_STACK             (30)
#define MAX_NPC_BAGS                (50)
#define MAX_STORED_LOCATIONS        (1000)
#define GM_ZONES_FOG_SIZE           (2500)
#define MAX_SCRIPT_NAME             (64)
#define MAPOBJ_SCRIPT_NAME          (25)
#define MAPOBJ_CRITTER_PARAMS       (15)
#define MAX_PARAMETERS_ARRAYS       (100)
#define MAX_NAME                    (30)
#define MAX_STORED_IP               (20)
#define MAX_HEX_OFFSET              (50)
#define AP_DIVIDER                  (100)
#define MAX_CRIT_TYPES              (1000)
#define EFFECT_TEXTURES             (10)
#define EFFECT_SCRIPT_VALUES        (10)

// Vars
#define VAR_CALC_QUEST(tid,val)     ((tid)*1000+(val))
#define VAR_GLOBAL                  (0)
#define VAR_LOCAL                   (1)
#define VAR_UNICUM                  (2)
#define VAR_LOCAL_LOCATION          (3)
#define VAR_LOCAL_MAP               (4)
#define VAR_LOCAL_ITEM              (5)
#define VAR_FLAG_QUEST              (0x1)
#define VAR_FLAG_RANDOM             (0x2)
#define VAR_FLAG_NO_CHECK           (0x4)

// Items
#define USE_PRIMARY                 (0)
#define USE_SECONDARY               (1)
#define USE_THIRD                   (2)
#define USE_RELOAD                  (3)
#define USE_USE                     (4)
#define MAX_USES					(3)
#define USE_NONE                    (15)

#define CAR_MAX_BLOCKS              (80)
#define CAR_MAX_BAG_POSITION        (12)

// Parameters
#define MAX_PARAMS                  (1000)
#define SKILL_OFFSET(skill)         ((skill) + (Game->AbsoluteOffsets ? 0 : SKILL_BEGIN))
#define PERK_OFFSET(perk)           ((perk)  + (Game->AbsoluteOffsets ? 0 : PERK_BEGIN ))
#define TB_BATTLE_TIMEOUT           (100000000)
#define TB_BATTLE_TIMEOUT_CHECK(to) ((to)>10000000)
#define SKILL_BEGIN                 (Game->SkillBegin)
#define SKILL_END                   (Game->SkillEnd)
#define TIMEOUT_BEGIN               (Game->TimeoutBegin)
#define TIMEOUT_END                 (Game->TimeoutEnd)
#define KILL_BEGIN                  (Game->KillBegin)
#define KILL_END                    (Game->KillEnd)
#define PERK_BEGIN                  (Game->PerkBegin)
#define PERK_END                    (Game->PerkEnd)
#define ADDICTION_BEGIN             (Game->AddictionBegin)
#define ADDICTION_END               (Game->AddictionEnd)
#define KARMA_BEGIN                 (Game->KarmaBegin)
#define KARMA_END                   (Game->KarmaEnd)
#define DAMAGE_BEGIN                (Game->DamageBegin)
#define DAMAGE_END                  (Game->DamageEnd)
#define TRAIT_BEGIN                 (Game->TraitBegin)
#define TRAIT_END                   (Game->TraitEnd)
#define REPUTATION_BEGIN            (Game->ReputationBegin)
#define REPUTATION_END              (Game->ReputationEnd)

// Events
#define MAP_LOOP_FUNC_MAX           (5)
#define MAP_MAX_DATA                (100)

// Sprites cutting
#define SPRITE_CUT_HORIZONTAL       (1)
#define SPRITE_CUT_VERTICAL         (2)

// Map blocks
#define FH_BLOCK                              BIN8(00000001)
#define FH_NOTRAKE                            BIN8(00000010)
#define FH_WALL                               BIN8(00000100)
#define FH_SCEN                               BIN8(00001000)
#define FH_SCEN_GRID                          BIN8(00010000)
#define FH_TRIGGER                            BIN8(00100000)
#define FH_CRITTER                   BIN8(00000001)
#define FH_DEAD_CRITTER              BIN8(00000010)
#define FH_ITEM                      BIN8(00000100)
#define FH_BLOCK_ITEM                BIN8(00010000)
#define FH_NRAKE_ITEM                BIN8(00100000)
#define FH_WALK_ITEM                 BIN8(01000000)
#define FH_GAG_ITEM                  BIN8(10000000)
#define FH_NOWAY                    BIN16(00010001,00000001)
#define FH_NOSHOOT                  BIN16(00100000,00000010)

// Game access (not same as in scripts)
#define ACCESS_CLIENT               (0x1)
#define ACCESS_TESTER               (0x2)
#define ACCESS_MODER                (0x4)
#define ACCESS_ADMIN                (0x8)

// GameOptions::ChangeLang
#define CHANGE_LANG_CTRL_SHIFT      (0)
#define CHANGE_LANG_ALT_SHIFT       (1)
// GameOptions::IndicatorType
#define INDICATOR_LINES             (0)
#define INDICATOR_NUMBERS           (1)
#define INDICATOR_BOTH              (2)
// GameOptions::Zoom
#define MIN_ZOOM                    (0.2f)
#define MAX_ZOOM                    (10.0f)

struct GameOptions
{
	uint16 YearStart;
	uint64 YearStartFT;
	uint16 Year;
	uint16 Month;
	uint16 Day;
	uint16 Hour;
	uint16 Minute;
	uint16 Second;
	uint   FullSecondStart;
	uint   FullSecond;
	uint16 TimeMultiplier;
	uint   GameTimeTick;

	bool   DisableTcpNagle;
	bool   DisableZlibCompression;
	uint   FloodSize;
	bool   FreeExp;
	bool   RegulatePvP;
	bool   NoAnswerShuffle;
	bool   DialogDemandRecheck;
	uint   FixBoyDefaultExperience;
	uint   SneakDivider;
	uint   LevelCap;
	bool   LevelCapAddExperience;
	uint   LookNormal;
	uint   LookMinimum;
	uint   GlobalMapMaxGroupCount;
	uint   CritterIdleTick;
	uint   TurnBasedTick;
	int    DeadHitPoints;
	uint   Breaktime;
	uint   TimeoutTransfer;
	uint   TimeoutBattle;
	uint   ApRegeneration;
	uint   RtApCostCritterWalk;
	uint   RtApCostCritterRun;
	uint   RtApCostMoveItemContainer;
	uint   RtApCostMoveItemInventory;
	uint   RtApCostPickItem;
	uint   RtApCostDropItem;
	uint   RtApCostReloadWeapon;
	uint   RtApCostPickCritter;
	uint   RtApCostUseItem;
	uint   RtApCostUseSkill;
	bool   RtAlwaysRun;
	uint   TbApCostCritterMove;
	uint   TbApCostMoveItemContainer;
	uint   TbApCostMoveItemInventory;
	uint   TbApCostPickItem;
	uint   TbApCostDropItem;
	uint   TbApCostReloadWeapon;
	uint   TbApCostPickCritter;
	uint   TbApCostUseItem;
	uint   TbApCostUseSkill;
	bool   TbAlwaysRun;
	uint   ApCostAimEyes;
	uint   ApCostAimHead;
	uint   ApCostAimGroin;
	uint   ApCostAimTorso;
	uint   ApCostAimArms;
	uint   ApCostAimLegs;
	bool   RunOnCombat;
	bool   RunOnTransfer;
	uint   GlobalMapWidth;
	uint   GlobalMapHeight;
	uint   GlobalMapZoneLength;
	uint   EncounterTime;
	uint   BagRefreshTime;
	uint   AttackAnimationsMinDist;
	uint   WhisperDist;
	uint   ShoutDist;
	int    LookChecks;
	uint   LookDir[4];
	uint   LookSneakDir[4];
	uint   LookWeight;
	bool   CustomItemCost;
	uint   RegistrationTimeout;
	uint   AccountPlayTime;
	bool   LoggingVars;
	uint   ScriptRunSuspendTimeout;
	uint   ScriptRunMessageTimeout;
	uint   TalkDistance;
	uint   MinNameLength;
	uint   MaxNameLength;
	uint   DlgTalkMinTime;
	uint   DlgBarterMinTime;
	uint   MinimumOfflineTime;

	bool   AbsoluteOffsets;
	uint   SkillBegin;
	uint   SkillEnd;
	uint   TimeoutBegin;
	uint   TimeoutEnd;
	uint   KillBegin;
	uint   KillEnd;
	uint   PerkBegin;
	uint   PerkEnd;
	uint   AddictionBegin;
	uint   AddictionEnd;
	uint   KarmaBegin;
	uint   KarmaEnd;
	uint   DamageBegin;
	uint   DamageEnd;
	uint   TraitBegin;
	uint   TraitEnd;
	uint   ReputationBegin;
	uint   ReputationEnd;

	int    ReputationLoved;
	int    ReputationLiked;
	int    ReputationAccepted;
	int    ReputationNeutral;
	int    ReputationAntipathy;
	int    ReputationHated;

	// Client and Mapper
	bool   Quit;
	int    MouseX;
	int    MouseY;
	int    ScrOx;
	int    ScrOy;
	bool   ShowTile;
	bool   ShowRoof;
	bool   ShowItem;
	bool   ShowScen;
	bool   ShowWall;
	bool   ShowCrit;
	bool   ShowFast;
	bool   ShowPlayerNames;
	bool   ShowNpcNames;
	bool   ShowCritId;
	bool   ScrollKeybLeft;
	bool   ScrollKeybRight;
	bool   ScrollKeybUp;
	bool   ScrollKeybDown;
	bool   ScrollMouseLeft;
	bool   ScrollMouseRight;
	bool   ScrollMouseUp;
	bool   ScrollMouseDown;
	bool   ShowGroups;
	bool   HelpInfo;
	bool   DebugInfo;
	bool   DebugNet;
	bool   DebugSprites;
	bool   FullScreen;
	bool   VSync;
	int    FlushVal;
	int    BaseTexture;
	int    ScreenClear;
	int    Light;
	string Host;
	int    HostRefCount;
	uint   Port;
	uint   ProxyType;
	string ProxyHost;
	int    ProxyHostRefCount;
	uint   ProxyPort;
	string ProxyUser;
	int    ProxyUserRefCount;
	string ProxyPass;
	int    ProxyPassRefCount;
	string Name;
	int    NameRefCount;
	string Pass;
	int    PassRefCount;
	int    ScrollDelay;
	int    ScrollStep;
	bool   ScrollCheck;
	int    MouseSpeed;
	bool   GlobalSound;
	string MasterPath;
	int    MasterPathRefCount;
	string CritterPath;
	int    CritterPathRefCount;
	string FoDataPath;
	int    FoDataPathRefCount;
	int    Sleep;
	bool   MsgboxInvert;
	int    ChangeLang;
	uint8  DefaultCombatMode;
	bool   MessNotify;
	bool   SoundNotify;
	bool   AlwaysOnTop;
	uint   TextDelay;
	uint   DamageHitDelay;
	int    ScreenWidth;
	int    ScreenHeight;
	int    MultiSampling;
	bool   SoftwareSkinning;
	bool   MouseScroll;
	int    IndicatorType;
	uint   DoubleClickTime;
	uint8  RoofAlpha;
	bool   HideCursor;
	bool   DisableLMenu;
	bool   DisableMouseEvents;
	bool   DisableKeyboardEvents;
	bool   HidePassword;
	string PlayerOffAppendix;
	int    PlayerOffAppendixRefCount;
	int    CombatMessagesType;
	bool   DisableDrawScreens;
	uint   Animation3dSmoothTime;
	uint   Animation3dFPS;
	int    RunModMul;
	int    RunModDiv;
	int    RunModAdd;
	float  SpritesZoom;
	float  SpritesZoomMax;
	float  SpritesZoomMin;
	float  EffectValues[EFFECT_SCRIPT_VALUES];
	bool   AlwaysRun;
	int    AlwaysRunMoveDist;
	int    AlwaysRunUseDist;
	string KeyboardRemap;
	int    KeyboardRemapRefCount;
	uint   CritterFidgetTime;
	uint   Anim2CombatBegin;
	uint   Anim2CombatIdle;
	uint   Anim2CombatEnd;

	// Mapper
	string ClientPath;
	int    ClientPathRefCount;
	string ServerPath;
	int    ServerPathRefCount;
	bool   ShowCorners;
	bool   ShowCuttedSprites;
	bool   ShowDrawOrder;

	// Engine data
	void (*CritterChangeParameter)(Critter& cr, uint index); // Call for correct changing critter parameter
	CritterType* CritterTypes; // Array of critter types, maximum is MAX_CRIT_TYPES

	Field* ClientMap; // Array of client map hexes, accessing - ClientMap[hexY * ClientMapWidth + hexX]
	uint   ClientMapWidth;
	uint   ClientMapHeight;

	Sprite* (*GetDrawingSprites)(uint& count); // Array of currently drawing sprites, tree is sorted
	SpriteInfo* (*GetSpriteInfo)(uint sprId); // Sprite information
	uint (*GetSpriteColor)(uint sprId, int x, int y, bool affectZoom); // Color of pixel on sprite
	bool (*IsSpriteHit)(Sprite* sprite, int x, int y, bool checkEgg); // Is position hitting sprite

	const char* (*GetNameByHash)(uint hash); // Get name of file by hash
	uint (*GetHashByName)(const char* name); // Get hash of file name

	// Callbacks
	uint (*GetUseApCost)(CritterMutual& cr, Item& item, uint8 mode);
	uint (*GetAttackDistantion)(CritterMutual& cr, Item& item, uint8 mode);
};
EXPORT extern GameOptions* Game;

struct Mutex
{
	 int   Locker[6]; // CRITICAL_SECTION, include Windows.h
};

struct Spinlock
{
	long   Locker;
};

struct SyncObj
{
	void*  CurMngr;
};

struct ScriptString
{
	string Buffer;
	int    RefCount;
};

struct ScriptArray
{
	void*  VTable;
	int    RefCount;
	bool   GCFlag;
	void*  ObjType; // asIObjectType

	struct ArrayBuffer
	{
		uint   NumElements;
		uint8  Data[1];
	} *Buffer;

	bool   IsArrayOfHandles;
	int    ElementSize;
	int    CmpFuncId;
	int    SubTypeId;

	uint   GetSize()      {return Buffer->NumElements;}
	void*  At(uint index) {return Buffer->Data + index * ElementSize;}
};

struct CritterType
{
	bool Enabled;
	char Name[64];
	char SoundName[64];
	uint Alias;
	uint Multihex;

	bool Is3d;
	bool CanWalk;
	bool CanRun;
	bool CanAim;
	bool CanArmor;
	bool CanRotate;

	bool Anim1[37]; // _ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
};

struct ProtoItem
{
	uint16 Pid;
	uint8  Type;
	uint8  Slot;
	uint   Flags;
	uint8  Corner;
	bool   DisableEgg;
	int16  Dir;
	uint   PicMapHash;
	uint   PicInvHash;
	uint   Weight;
	uint   Volume;
	uint   Cost;
	uint8  SoundId;
	uint8  Material;

	// Light
	uint8  LightFlags;
	uint8  LightDistance;
	int8   LightIntensity;
	uint   LightColor;

	// Animation
	uint16 AnimWaitBase;
	uint16 AnimWaitRndMin;
	uint16 AnimWaitRndMax;
	uint8  AnimStay[2];
	uint8  AnimShow[2];
	uint8  AnimHide[2];
	int16  OffsetX;
	int16  OffsetY;
	int8   DrawPosOffsY;
	uint8  SpriteCut;
	int8   DrawOrderOffsetHexY;

	// Radio
	uint16 RadioChannel;
	uint16 RadioFlags;
	uint8  RadioBroadcastSend;
	uint8  RadioBroadcastRecv;

	// Indicator
	uint8  IndicatorStart;
	uint8  IndicatorMax;

	// Holodisk
	uint   HolodiskId;

	union
	{
		struct
		{
			uint8  Anim0Male;
			uint8  Anim0Female;
			uint16 AC;
			uint8  Perk;

			uint16 DRNormal;
			uint16 DRLaser;
			uint16 DRFire;
			uint16 DRPlasma;
			uint16 DRElectr;
			uint16 DREmp;
			uint16 DRExplode;

			uint16 DTNormal;
			uint16 DTLaser;
			uint16 DTFire;
			uint16 DTPlasma;
			uint16 DTElectr;
			uint16 DTEmp;
			uint16 DTExplode;
		} Armor;

		struct
		{
			bool   NoWear;
			bool   IsNeedAct;

			bool   IsUnarmed;
			uint8  UnarmedTree;
			uint8  UnarmedPriority;
			uint8  UnarmedCriticalBonus;
			bool   UnarmedArmorPiercing;
			uint8  UnarmedMinAgility;
			uint8  UnarmedMinUnarmed;
			uint8  UnarmedMinLevel;

			uint8  Anim1;
			uint16 VolHolder;
			uint16 Caliber;
			uint16 DefAmmo;
			uint8  ReloadAp;
			uint8  CrFailture;
			uint8  MinSt;
			uint8  Perk;

			uint8  Uses;
			uint16 Skill[MAX_USES];
			uint16 DmgType[MAX_USES];
			uint16 Anim2[MAX_USES];
			uint16 PicDeprecated[MAX_USES];
			uint   PicHash[MAX_USES];
			uint16 DmgMin[MAX_USES];
			uint16 DmgMax[MAX_USES];
			uint16 MaxDist[MAX_USES];
			uint16 Effect[MAX_USES];
			uint16 Round[MAX_USES];
			uint16 ApCost[MAX_USES];
			bool   Aim[MAX_USES];
			bool   Remove[MAX_USES];
			uint8  SoundId[MAX_USES];
		} Weapon;

		struct
		{
			uint   StartCount;
			uint   Caliber;
			int    ACMod;
			int    DRMod;
			uint   DmgMult;
			uint   DmgDiv;
		} Ammo;

		struct
		{
			uint   StartVal1;
			uint   StartVal2;
			uint   StartVal3;

			bool IsCar;

			struct _CAR
			{
				uint8  Speed; 
				uint8  Negotiability;
				uint8  WearConsumption;
				uint8  CritCapacity;
				uint16 FuelTank;
				uint16 RunToBreak;
				uint8  Entire;
				uint8  WalkType;
				uint8  FuelConsumption;

				uint8  Bag0[CAR_MAX_BAG_POSITION / 2];
				uint8  Bag1[CAR_MAX_BAG_POSITION / 2];
				uint8  Blocks[CAR_MAX_BLOCKS / 2];

				uint8  GetBag0Dir(int num)  {return ((num & 1) ? (Bag0  [num / 2] & 0xF) : (Bag0  [num / 2] >> 4));}
				uint8  GetBag1Dir(int num)  {return ((num & 1) ? (Bag1  [num / 2] & 0xF) : (Bag1  [num / 2] >> 4));}
				uint8  GetBlockDir(int num) {return ((num & 1) ? (Blocks[num / 2] & 0xF) : (Blocks[num / 2] >> 4));}
			} Car;
		} MiscEx;

		struct
		{
			uint   ContVolume;
			uint   CannotPickUp;
			uint   MagicHandsGrnd;
			uint   Changeble;
			bool   IsNoOpen;
		} Container;

		struct
		{
			uint   WalkThru;
			bool   IsNoOpen;
			bool   BlockPass;
			bool   BlockRake;
			bool   BlockLight;
		} Door;

		struct
		{
			uint8  Type;
		} Grid;
	};

	uint16 GetPid()            {return Pid;}
	uint   GetInfo()           {return Pid * 100;}
	uint8  GetType()           {return Type;}
	bool   IsItem()            {return Type >= ITEM_ARMOR   && Type <= ITEM_DOOR;}
	bool   IsScen()            {return Type == ITEM_GENERIC;}
	bool   IsWall()            {return Type == ITEM_WALL;}
	bool   IsTile()            {return Type == ITEM_TILE;}
	bool   IsArmor()           {return Type == ITEM_ARMOR;}
	bool   IsDrug()            {return Type == ITEM_DRUG;}
	bool   IsWeapon()          {return Type == ITEM_WEAPON;}
	bool   IsAmmo()            {return Type == ITEM_AMMO;}
	bool   IsMisc()            {return Type == ITEM_MISC;}
	bool   IsMisc2()           {return Type == ITEM_MISC_EX;}
	bool   IsKey()             {return Type == ITEM_KEY;}
	bool   IsContainer()       {return Type == ITEM_CONTAINER;}
	bool   IsDoor()            {return Type == ITEM_DOOR;}
	bool   IsGrid()            {return Type == ITEM_GRID;}
	bool   IsGeneric()         {return Type == ITEM_GENERIC;}
	bool   IsCar()             {return Type == ITEM_MISC_EX && MiscEx.IsCar;}
	bool   LockerIsChangeble() {if(IsDoor()) return true; if(IsContainer()) return Container.Changeble!=0; return false;}
	bool   IsGrouped()         {return IsDrug() || IsAmmo() || IsMisc() || (IsWeapon() && WeapIsGrouped());}
	bool   IsWeared()          {return Type == ITEM_ARMOR || (Type == ITEM_WEAPON && WeapIsWeared());}
	bool   WeapIsNeedAct()     {return Weapon.IsNeedAct;}
	bool   WeapIsWeared()      {return !Weapon.NoWear;}
	bool   WeapIsGrouped()     {return Weapon.NoWear;}
	bool   IsCanPickUp()       {return FLAG(Flags, ITEM_CAN_PICKUP);}

	bool   Container_IsGroundLevel()
	{
		bool is_ground = true;
		if(IsContainer()) is_ground = (Container.MagicHandsGrnd ? true : false);
		else if(IsDoor() || IsCar() || IsScen() || IsGrid() || !IsCanPickUp()) is_ground = false;
		return is_ground;
	}
};

struct TemplateVar
{
	int    Type;
	uint16 TempId;
	string Name;
	string Desc;
	int    StartVal;
	int    MinVal;
	int    MaxVal;
	uint   Flags;

	bool   IsQuest()     {return FLAG(Flags,VAR_FLAG_QUEST);}
	bool   IsRandom()    {return FLAG(Flags,VAR_FLAG_RANDOM);}
	bool   IsNoBorders() {return FLAG(Flags,VAR_FLAG_NO_CHECK);}
};

struct GameVar
{
	uint         MasterId;
	uint         SlaveId;
	int          VarValue;
	TemplateVar* VarTemplate;
	uint         QuestVarIndex;
	uint16       Type;
	int16        RefCount;
	SyncObj      Sync;

	int    GetValue()    {return VarValue;}
	int    GetMin()      {return VarTemplate->MinVal;}
	int    GetMax()      {return VarTemplate->MaxVal;}
	bool   IsQuest()     {return VarTemplate->IsQuest();}
	uint   GetQuestStr() {return VAR_CALC_QUEST(VarTemplate->TempId, VarValue);}
	uint64 GetUid()      {return (((uint64) SlaveId) << 32) | ((uint64) MasterId);}
};

struct NpcPlane
{
	int       Type;
	uint      Priority;
	int       Identifier;
	uint      IdentifierExt;
	NpcPlane* ChildPlane;
	bool      IsMove;

	union
	{
		struct
		{
			bool   IsRun;
			uint   WaitSecond;
			int    ScriptBindId;
		} Misc;

		struct
		{
			bool   IsRun;
			uint   TargId;
			int    MinHp;
			bool   IsGag;
			uint16 GagHexX,GagHexY;
			uint16 LastHexX,LastHexY;
		} Attack;

		struct
		{
			bool   IsRun;
			uint16 HexX;
			uint16 HexY;
			uint8  Dir;
			uint   Cut;
		} Walk;

		struct
		{
			bool   IsRun;
			uint16 HexX;
			uint16 HexY;
			uint16 Pid;
			uint   UseItemId;
			bool   ToOpen;
		} Pick;

		struct
		{
			uint   Buffer[8];
		} Buffer;
	};

	struct
	{
		uint   PathNum;
		uint   Iter;
		bool   IsRun;
		uint   TargId;
		uint16 HexX;
		uint16 HexY;
		uint   Cut;
		uint   Trace;
	} Move;

	bool   Assigned;
	int    RefCounter;

	NpcPlane* GetCurPlane()                  {return ChildPlane?ChildPlane->GetCurPlane():this;}
	bool      IsSelfOrHas(int type)          {return Type==type || (ChildPlane?ChildPlane->IsSelfOrHas(type):false);}
	uint      GetChildIndex(NpcPlane* child) {uint index=0; for(NpcPlane* child_=this;child_;index++) {if(child_==child) break; else child_=child_->ChildPlane;} return index;}
	uint      GetChildsCount()               {uint count=0; NpcPlane* child=ChildPlane; for(;child;count++,child=child->ChildPlane); return count;}
};

struct Item
{
	uint       Id;
	ProtoItem* Proto;
	int        From;
	uint8      Accessory;
	bool       ViewPlaceOnMap;
	int16      Reserved0;

	union
	{
		struct
		{
			uint   MapId;
			uint16 HexX;
			uint16 HexY;
		} ACC_HEX;

		struct
		{
			uint   Id;
			uint8  Slot;
		} ACC_CRITTER;

		struct
		{
			uint   ContainerId;
			uint   SpecialId;
		} ACC_CONTAINER;

		struct
		{
			uint   Buffer[2];
		} ACC_BUFFER;
	};

	struct _Data
	{
		uint16 SortValue;
		uint8  Info;
		uint8  Indicator;
		uint   PicMapHash;
		uint   PicInvHash;
		uint16 AnimWaitBase;
		uint8  AnimStay[2];
		uint8  AnimShow[2];
		uint8  AnimHide[2];
		uint   Flags;
		uint8  Rate;
		int8   LightIntensity;
		uint8  LightDistance;
		uint8  LightFlags;
		uint   LightColor;
		uint16 ScriptId;
		int16  TrapValue;
		uint   Count;
		uint   Cost;
		int    ScriptValues[10];

		union
		{
			struct
			{
				uint8  DeteorationFlags;
				uint8  DeteorationCount;
				uint16 DeteorationValue;
				uint16 AmmoPid;
				uint16 AmmoCount;
			} TechInfo;

			struct
			{
				uint   DoorId;
				uint16 Condition;
				uint16 Complexity;
			} Locker;

			struct
			{
				uint   DoorId;
				uint16 Fuel;
				uint16 Deteoration;
			} Car;

			struct
			{
				uint   Number;
			} Holodisk;

			struct
			{
				uint16 Channel;
			} Radio;
		};
	} Data;

	int16 RefCounter;
	bool  IsNotValid;

#ifdef __SERVER
	int      FuncId[ITEM_EVENT_MAX];
	Critter* ViewByCritter;
	ItemVec* ChildItems;
	char*    Lexems;
	SyncObj  Sync;
#endif

#ifdef __CLIENT
	string   Lexems;
	int      LexemsRefCounter;
#endif

	uint   GetId()      {return Id;}
	uint16 GetProtoId() {return Proto->GetPid();}
	uint   GetInfo()    {return Proto->GetInfo() + Data.Info;}
	uint   GetPicMap()  {return Data.PicMapHash ? Data.PicMapHash : Proto->PicMapHash;}
	uint   GetPicInv()  {return Data.PicInvHash ? Data.PicInvHash : Proto->PicInvHash;}
	uint8  GetType()    {return Proto->GetType();}
	bool   IsGrouped()  {return Proto->IsGrouped();}

	bool   IsPassed()           {return FLAG(Data.Flags, ITEM_NO_BLOCK) && FLAG(Data.Flags, ITEM_SHOOT_THRU);}
	bool   IsRaked()            {return FLAG(Data.Flags, ITEM_SHOOT_THRU);}
	bool   IsFlat()             {return FLAG(Data.Flags, ITEM_FLAT);}
	bool   IsHidden()           {return FLAG(Data.Flags, ITEM_HIDDEN);}
	bool   IsCanTalk()          {return FLAG(Data.Flags, ITEM_CAN_TALK);}
	bool   IsCanUse()           {return FLAG(Data.Flags, ITEM_CAN_USE);}
	bool   IsCanUseOnSmth()     {return FLAG(Data.Flags, ITEM_CAN_USE_ON_SMTH);}
	bool   IsHasTimer()         {return FLAG(Data.Flags, ITEM_HAS_TIMER);}
	bool   IsBadItem()          {return FLAG(Data.Flags, ITEM_BAD_ITEM);}
	bool   IsTwoHands()         {return FLAG(Data.Flags, ITEM_TWO_HANDS);}
	bool   IsBigGun()           {return FLAG(Data.Flags, ITEM_BIG_GUN);}
	bool   IsNoHighlight()      {return FLAG(Data.Flags, ITEM_NO_HIGHLIGHT);}
	bool   IsShowAnim()         {return FLAG(Data.Flags, ITEM_SHOW_ANIM);}
	bool   IsShowAnimExt()      {return FLAG(Data.Flags, ITEM_SHOW_ANIM_EXT);}
	bool   IsLightThru()        {return FLAG(Data.Flags, ITEM_LIGHT_THRU);}
	bool   IsAlwaysView()       {return FLAG(Data.Flags, ITEM_ALWAYS_VIEW);}
	bool   IsGeck()             {return FLAG(Data.Flags, ITEM_GECK);}
	bool   IsNoLightInfluence() {return FLAG(Data.Flags, ITEM_NO_LIGHT_INFLUENCE);}
	bool   IsNoLoot()           {return FLAG(Data.Flags, ITEM_NO_LOOT);}
	bool   IsNoSteal()          {return FLAG(Data.Flags, ITEM_NO_STEAL);}
	bool   IsCanPickUp()        {return FLAG(Data.Flags, ITEM_CAN_PICKUP);}

	bool   IsWeared()           {return GetId() && Proto->IsWeared();}
	bool   IsBroken()           {return (IsWeared() ? FLAG(Data.TechInfo.DeteorationFlags, BI_BROKEN) : false);}
	bool   IsNoResc()           {return (IsWeared() ? FLAG(Data.TechInfo.DeteorationFlags, BI_NOTRESC) : false);}
	bool   IsService()          {return (IsWeared() ? FLAG(Data.TechInfo.DeteorationFlags, BI_SERVICE) : false);}
	bool   IsServiceExt()       {return (IsWeared() ? FLAG(Data.TechInfo.DeteorationFlags, BI_SERVICE_EXT) : false);}
	bool   IsEternal()          {return (IsWeared() ? FLAG(Data.TechInfo.DeteorationFlags, BI_ETERNAL) : false);}
	int    GetBrokenCount()     {return (IsWeared() ? Data.TechInfo.DeteorationCount : 0);}
	int    GetWear()            {return (IsWeared() ? Data.TechInfo.DeteorationValue : 0);}
	int    GetMaxWear()         {return WEAR_MAX;}
	int    GetWearProc()        {int val = GetWear() * 100 / WEAR_MAX; return CLAMP(val, 0, 100);}

	uint   GetCount()           {return IsGrouped() ? Data.Count : 1;}
	uint   GetVolume()          {return GetCount() * Proto->Volume;}
	uint   GetWeight()          {return GetCount() * Proto->Weight;}

	// Armor
	bool   IsArmor()            {return GetType() == ITEM_ARMOR;}

	// Weapon
	bool   IsWeapon()                {return GetType() == ITEM_WEAPON;}
	bool   WeapIsEmpty()             {return !Data.TechInfo.AmmoCount;}
	bool   WeapIsFull()              {return Data.TechInfo.AmmoCount >= Proto->Weapon.VolHolder;}
	uint   WeapGetAmmoCount()        {return Data.TechInfo.AmmoCount;}
	uint   WeapGetAmmoPid()          {return Data.TechInfo.AmmoPid;}
	uint   WeapGetMaxAmmoCount()     {return Proto->Weapon.VolHolder;}
	int    WeapGetAmmoCaliber()      {return Proto->Weapon.Caliber;}
	bool   WeapIsWeared()            {return Proto->WeapIsWeared();}
	bool   WeapIsGrouped()           {return Proto->WeapIsGrouped();}
	bool   WeapIsEffect(int use)     {return Proto->Weapon.Effect[use] != 0;}
	uint16 WeapGetEffectPid(int use) {return Proto->Weapon.Effect[use];}
	int    WeapGetNeedStrength()     {return Proto->Weapon.MinSt;}
	bool   WeapIsUseAviable(int use) {return use >= USE_PRIMARY && use <= USE_THIRD ? (((Proto->Weapon.Uses >> use) & 1) != 0) : false;}
	bool   WeapIsCanAim(int use)     {return use < MAX_USES && Proto->Weapon.Aim[use];}

	// Container
	bool   IsContainer()          {return Proto->IsContainer();}
	bool   ContIsCannotPickUp()   {return Proto->Container.CannotPickUp != 0;}
	bool   ContIsMagicHandsGrnd() {return Proto->Container.MagicHandsGrnd != 0;}
	bool   ContIsChangeble()      {return Proto->Container.Changeble != 0;}

	// Door
	bool   IsDoor()               {return GetType() == ITEM_DOOR;}

	// Locker
	bool   IsHasLocker()          {return IsDoor() || IsContainer();}
	uint   LockerDoorId()         {return Data.Locker.DoorId;}
	bool   LockerIsOpen()         {return FLAG(Data.Locker.Condition, LOCKER_ISOPEN);}
	bool   LockerIsClose()        {return !LockerIsOpen();}
	bool   LockerIsChangeble()    {return Proto->LockerIsChangeble();}
	int    LockerComplexity()     {return Data.Locker.Complexity;}

	// Ammo
	bool   IsAmmo()         {return Proto->IsAmmo();}
	int    AmmoGetCaliber() {return Proto->Ammo.Caliber;}

	// Key
	bool   IsKey()          {return Proto->IsKey();}
	uint   KeyDoorId()      {return Data.Locker.DoorId;}

	// Drug
	bool   IsDrug()         {return Proto->IsDrug();}

	// Misc
	bool   IsMisc()         {return Proto->IsMisc();}

	// Colorize
	bool   IsColorize()        {return FLAG(Data.Flags, ITEM_COLORIZE);}
	uint   GetColor()          {return (Data.LightColor ? Data.LightColor : Proto->LightColor) & 0xFFFFFF;}
	uint8  GetAlpha()          {return (Data.LightColor ? Data.LightColor : Proto->LightColor) >> 24;}

	// Light
	bool   IsLight()           {return FLAG(Data.Flags, ITEM_LIGHT);}
	int    LightGetIntensity() {return Data.LightIntensity ? Data.LightIntensity : Proto->LightIntensity;}
	int    LightGetDistance()  {return Data.LightDistance ? Data.LightDistance : Proto->LightDistance;}
	int    LightGetFlags()     {return Data.LightFlags ? Data.LightFlags : Proto->LightFlags;}
	uint   LightGetColor()     {return (Data.LightColor ? Data.LightColor : Proto->LightColor) & 0xFFFFFF;}

	// Car
	bool   IsCar()                 {return Proto->IsCar();}
	uint   CarGetDoorId()          {return Data.Car.DoorId;}
	uint16 CarGetFuel()            {return Data.Car.Fuel;}
	uint16 CarGetFuelTank()        {return Proto->MiscEx.Car.FuelTank;}
	uint8  CarGetFuelConsumption() {return Proto->MiscEx.Car.FuelConsumption;}
	uint16 CarGetWear()            {return Data.Car.Deteoration;}
	uint16 CarGetRunToBreak()      {return Proto->MiscEx.Car.RunToBreak;}
	uint8  CarGetWearConsumption() {return Proto->MiscEx.Car.WearConsumption;}
	uint   CarGetSpeed()           {return Proto->MiscEx.Car.Speed;}
	uint8  CarGetCritCapacity()    {return Proto->MiscEx.Car.CritCapacity;}

	// Trap
	bool   IsTrap()                {return FLAG(Data.Flags, ITEM_TRAP);}
	int    TrapGetValue()          {return Data.TrapValue;}
};

struct GlobalMapGroup
{
	CrVec    CritMove;
	Critter* Rule;
	uint     CarId;
	int      WXi,WYi;
	float    WXf,WYf;
	int      MoveX,MoveY;
	float    SpeedX,SpeedY;
	bool     IsSetMove;
	uint     TimeCanFollow;
	uint     NextEncaunter;
	bool     IsMultiply;
	uint     MoveLastTick;
	uint     ProcessLastTick;
	uint     EncounterDescriptor;
	uint     EncounterTick;
	bool     EncounterForce;
};

struct CritterTimeEvent
{
	uint   FuncNum;
	uint   Rate;
	uint   NextTime;
	int    Identifier;
};
typedef vector<CritterTimeEvent> CritterTimeEventVec;
typedef vector<CritterTimeEvent>::iterator CritterTimeEventVecIt;

struct Critter
{
	uint   Id;
	uint16 HexX;
	uint16 HexY;
	uint16 WorldX;
	uint16 WorldY;
	uint   BaseType;
	uint8  Dir;
	uint8  Cond;
	uint8  ReservedCE;
	uint8  Reserved0;
	uint   ScriptId;
	uint   ShowCritterDist1;
	uint   ShowCritterDist2;
	uint   ShowCritterDist3;
	uint16 Reserved00;
	int16  Multihex;
	uint   GlobalGroupUid;
	uint16 LastHexX;
	uint16 LastHexY;
	uint   Reserved1[4];
	uint   MapId;
	uint16 MapPid;
	uint16 Reserved2;
	int    Params[MAX_PARAMS];
	uint   Anim1Life;
	uint   Anim1Knockout;
	uint   Anim1Dead;
	uint   Anim2Life;
	uint   Anim2Knockout;
	uint   Anim2Dead;
	uint   Anim2KnockoutEnd;
	uint   Reserved3[3];
	char   Lexems[LEXEMS_SIZE];
	uint   Reserved4[8];
	bool   ClientToDelete;
	uint8  Reserved5;
	uint16 Reserved6;
	uint   Temp;
	uint16 Reserved8;
	uint16 HoloInfoCount;
	uint   HoloInfo[MAX_HOLO_INFO];
	uint   Reserved9[10];
	int    Scores[SCORES_MAX];
	uint   Reserved10[100];

	// Npc data
	uint   HomeMap;
	uint16 HomeX;
	uint16 HomeY;
	uint8  HomeOri;
	uint8  Reserved11;
	uint16 ProtoId;
	uint   Reserved12;
	uint   Reserved13;
	uint   Reserved14;
	uint   Reserved15;
	bool   IsDataExt;
	uint8  Reserved16;
	uint16 Reserved17;
	uint   Reserved18[8];
	uint16 FavoriteItemPid[4];
	uint   Reserved19[10];
	uint   EnemyStackCount;
	uint   EnemyStack[MAX_ENEMY_STACK];
	uint   Reserved20[5];
	uint8  BagCurrentSet[MAX_NPC_BAGS_PACKS];
	int16  BagRefreshTime;
	uint8  Reserved21;
	uint8  BagSize;
	struct
	{
		uint   ItemPid;
		uint   MinCnt;
		uint   MaxCnt;
		uint   ItemSlot;
	} Bag[MAX_NPC_BAGS];
	uint   Reserved22[100];

	// Ext data
	struct
	{
		uint   Reserved23[10];
		uint8  GlobalMapFog[GM_ZONES_FOG_SIZE];
		uint16 Reserved24;
		uint16 LocationsCount;
		uint   LocationsId[MAX_STORED_LOCATIONS];
		uint   Reserved25[40];
		uint   PlayIp[MAX_STORED_IP]; // 0 - registration ip
		uint   Reserved26[40];
	} *DataExt;

	SyncObj Sync;
	bool    CritterIsNpc;
	uint    Flags;
	string  NameStr;
	int     NameStrRefCounter;

	struct
	{
		bool   IsAlloc;
		uint8* Data;
		uint   Width;
		uint   Height;
		uint   WidthB;
	} GMapFog;

	bool     IsRuning;
	uint     PrevHexTick;
	uint16   PrevHexX,PrevHexY;
	int      LockMapTransfers;
	Critter* ThisPtr[MAX_PARAMETERS_ARRAYS];
	uint     AllowedToDownloadMap;
	bool     ParamsIsChanged[MAX_PARAMS];
	IntVec   ParamsChanged;
	int      ParamLocked;
	CrVec    VisCr;
	CrVec    VisCrSelf;
	UintSet  VisCr1,VisCr2,VisCr3;
	UintSet  VisItem;
	Spinlock VisItemLocker;
	uint     ViewMapId;
	uint16   ViewMapPid,ViewMapLook,ViewMapHx,ViewMapHy;
	uint8    ViewMapDir;
	uint     ViewMapLocId,ViewMapLocEnt;

	GlobalMapGroup* GroupSelf;
	GlobalMapGroup* GroupMove;

	ItemVec  InvItems;
	Item*    DefItemSlotHand;
	Item*    DefItemSlotArmor;
	Item*    ItemSlotMain;
	Item*    ItemSlotExt;
	Item*    ItemSlotArmor;
	int      FuncId[CRITTER_EVENT_MAX];
	uint     KnockoutAp;
	uint     NextIntellectCachingTick;
	uint16   IntellectCacheValue;
	uint     LookCacheValue;
	uint     StartBreakTime;
	int	     BreakTime;
	uint     WaitEndTick;
	int      DisableSend;
	uint     AccessContainerId;
	uint     ItemTransferCount;
	uint     TryingGoHomeTick;

	CritterTimeEventVec CrTimeEvents;

	uint     GlobalIdleNextTick;
	uint     ApRegenerationTick;
	bool     IsNotValid;
	int      RefCounter;

	uint   GetItemsWeight()
	{
		uint res = 0;
		for(ItemVecIt it = InvItems.begin(), end = InvItems.end(); it != end; ++it)
		{
			Item* item = *it;
			if(!item->IsHidden()) res += item->GetWeight();
		}
		return res;
	}

	uint   GetItemsVolume()
	{
		uint res = 0;
		for(ItemVecIt it = InvItems.begin(), end = InvItems.end(); it != end; ++it)
		{
			Item* item = *it;
			if(!item->IsHidden()) res += item->GetVolume();
		}
		return res;
	}
};

struct Client : Critter
{
	char   Name[MAX_NAME+1];
	char   Pass[MAX_NAME+1];
	uint8  Access;
	uint   LanguageMsg;
};

struct Npc : Critter
{
	uint        NextRefreshBagTick;
	NpcPlaneVec AiPlanes;
	uint        Reserved;
};

struct CritterCl
{
	uint      Id;
	uint16    Pid;
	uint16    HexX,HexY;
	uint8     Dir;
	int       Params[MAX_PARAMS];
	uint      NameColor;
	uint      ContourColor;
	Uint16Vec LastHexX,LastHexY;
	uint8     Cond;
	uint      Anim1Life;
	uint      Anim1Knockout;
	uint      Anim1Dead;
	uint      Anim2Life;
	uint      Anim2Knockout;
	uint      Anim2Dead;
	uint      Flags;
	uint      BaseType,BaseTypeAlias;
	uint      ApRegenerationTick;
	int16     Multihex;

	string    Name;
	int       NameRefCounter;
	string    NameOnHead;
	int       NameOnHeadRefCounter;
	string    Lexems;
	int       LexemsRefCounter;
	string    Avatar;
	char      Password[MAX_NAME+1];

	ItemVec   InvItems;
	Item*     DefItemSlotHand;
	Item*     DefItemSlotArmor;
	Item*     ItemSlotMain;
	Item*     ItemSlotExt;
	Item*     ItemSlotArmor;
};

struct MapObject
{
	uint8  MapObjType;
	uint16 ProtoId;
	uint16 MapX;
	uint16 MapY;
	int16  Dir;

	uint   LightRGB;
	uint8  LightDay;
	uint8  LightDirOff;
	uint8  LightDistance;
	int8   LightIntensity;

	char   ScriptName[MAPOBJ_SCRIPT_NAME+1];
	char   FuncName[MAPOBJ_SCRIPT_NAME+1];

	uint   Reserved[7];
	int    UserData[10];

	union
	{
		struct
		{
			uint8  Cond;
			uint   Anim1;
			uint   Anim2;
			int16  ParamIndex[MAPOBJ_CRITTER_PARAMS];
			int    ParamValue[MAPOBJ_CRITTER_PARAMS];
		} MCritter;

		struct
		{
			int16  OffsetX;
			int16  OffsetY;
			uint8  AnimStayBegin;
			uint8  AnimStayEnd;
			uint16 AnimWait;
			uint8  InfoOffset;
			uint   PicMapHash;
			uint   PicInvHash;

			uint   Count;

			uint8  DeteorationFlags;
			uint8  DeteorationCount;
			uint16 DeteorationValue;

			bool   InContainer;
			uint8  ItemSlot;

			uint16 AmmoPid;
			uint   AmmoCount;

			uint   LockerDoorId;
			uint16 LockerCondition;
			uint16 LockerComplexity;

			int16  TrapValue;

			int    Val[10];
		} MItem;

		struct
		{
			int16  OffsetX;
			int16  OffsetY;
			uint8  AnimStayBegin;
			uint8  AnimStayEnd;
			uint16 AnimWait;
			uint8  InfoOffset;
			uint   PicMapHash;
			uint   PicInvHash;

			bool   CanUse;
			bool   CanTalk;
			uint   TriggerNum;

			uint8  ParamsCount;
			int    Param[5];

			uint16 ToMapPid;
			uint   ToEntire;
			uint8  ToDir;
		} MScenery;
	};
};

struct MapEntire
{
	uint   Number;
	uint16 HexX;
	uint16 HexY;
	uint8  Dir;
};
typedef vector<MapEntire> EntiresVec;

struct SceneryToClient
{
	uint16 ProtoId;
	uint8  Flags;
	uint8  Reserved0;
	uint16 MapX;
	uint16 MapY;
	int16  OffsetX;
	int16  OffsetY;
	uint   LightColor;
	uint8  LightDistance;
	uint8  LightFlags;
	int8   LightIntensity;
	uint8  InfoOffset;
	uint8  AnimStayBegin;
	uint8  AnimStayEnd;
	uint16 AnimWait;
	uint   PicMapHash;
	int16  Dir;
	uint16 Reserved1;
};
typedef vector<SceneryToClient> SceneryToClientVec;

struct ProtoMap
{
	struct
	{
		uint   Version;
		uint16 MaxHexX, MaxHexY;
		int    WorkHexX, WorkHexY;
		char   ScriptModule[MAX_SCRIPT_NAME + 1];
		char   ScriptFunc[MAX_SCRIPT_NAME + 1];
		int    Time;
		bool   NoLogOut;
		int    DayTime[4];
		uint8  DayColor[12];

		// Deprecated
		uint16 HeaderSize;
		bool   Packed;
		uint   UnpackedDataLen;
	} Header;

	MapObjectVec MObjects;

	struct Tile
	{
		uint   NameHash;
		uint16 HexX, HexY;
		int16  OffsX, OffsY;
		bool   IsRoof;
#ifdef __MAPPER
		bool   IsSelected;
#endif
	};
	typedef vector<Tile> TileVec;
	TileVec Tiles;

#ifdef __MAPPER
	typedef vector<TileVec> TileVecVec;
	TileVecVec TilesField;
	TileVecVec RoofsField;

	TileVec& GetTiles(WORD hx, WORD hy, bool is_roof)
	{
		uint index = hy * Header.MaxHexX + hx;
		return is_roof ? RoofsField[index] : TilesField[index];
	}
#endif

	SceneryToClientVec WallsToSend;
	SceneryToClientVec SceneriesToSend;
	uint HashTiles;
	uint HashWalls;
	uint HashScen;

	MapObjectVec CrittersVec;
	MapObjectVec ItemsVec;
	MapObjectVec SceneriesVec;
	MapObjectVec GridsVec;
	uint8*       HexFlags;

	EntiresVec MapEntires;

	int    PathType;
	string Name;
	uint16 Pid;
};

struct Map
{
	SyncObj   Sync;
	Mutex     DataLocker;
	uint8*    HexFlags;
	CrVec     MapCritters;
	ClVec     MapPlayers;
	PcVec     MapNpcs;
	ItemVec   HexItems;
	Location* MapLocation;

	struct 
	{
		uint   MapId;
		uint16 MapPid;
		uint8  MapRain;
		bool   IsTurnBasedAviable;
		int    MapTime;
		uint   ScriptId;
		int    MapDayTime[4];
		uint8  MapDayColor[12];
		uint   Reserved[20];
		int    UserData[MAP_MAX_DATA];
	} Data;

	ProtoMap* Proto;

	bool      NeedProcess;
	uint      FuncId[MAP_EVENT_MAX];
	uint      LoopEnabled[MAP_LOOP_FUNC_MAX];
	uint      LoopLastTick[MAP_LOOP_FUNC_MAX];
	uint      LoopWaitTick[MAP_LOOP_FUNC_MAX];

	bool      IsTurnBasedOn;
	uint      TurnBasedEndTick;
	int       TurnSequenceCur;
	UintVec   TurnSequence;
	bool      IsTurnBasedTimeout;
	uint      TurnBasedBeginSecond;
	bool      NeedEndTurnBased;
	uint      TurnBasedRound;
	uint      TurnBasedTurn;
	uint      TurnBasedWholeTurn;

	bool      IsNotValid;
	int16     RefCounter;

	uint16 GetMaxHexX()                       {return Proto->Header.MaxHexX;}
	uint16 GetMaxHexY()                       {return Proto->Header.MaxHexY;}
	bool   IsHexTrigger(uint16 hx, uint16 hy) {return FLAG(Proto->HexFlags[hy*GetMaxHexX() + hx], FH_TRIGGER);}
	bool   IsHexTrap(uint16 hx, uint16 hy)    {return FLAG(HexFlags[hy * GetMaxHexX() + hx], FH_WALK_ITEM);}
	bool   IsHexCritter(uint16 hx, uint16 hy) {return FLAG(HexFlags[hy * GetMaxHexX() + hx], FH_CRITTER | FH_DEAD_CRITTER);}
	bool   IsHexGag(uint16 hx, uint16 hy)     {return FLAG(HexFlags[hy * GetMaxHexX() + hx], FH_GAG_ITEM);}
	uint16 GetHexFlags(uint16 hx, uint16 hy)  {return (HexFlags[hy * GetMaxHexX() + hx] <<8 ) | Proto->HexFlags[hy * GetMaxHexX() + hx];}
	bool   IsHexPassed(uint16 hx, uint16 hy)  {return !FLAG(GetHexFlags(hx, hy), FH_NOWAY);}
	bool   IsHexRaked(uint16 hx, uint16 hy)   {return !FLAG(GetHexFlags(hx, hy), FH_NOSHOOT);}
};

struct ProtoLocation
{
	bool        IsInit;
	uint16      LocPid;
	string      Name;

	uint        MaxPlayers;
	Uint16Vec   ProtoMapPids;
	Uint16Vec   AutomapsPids;
	UintPairVec Entrance;
	int         ScriptBindId;

	uint16      Radius;
	bool        Visible;
	bool        AutoGarbage;
	bool        GeckVisible;
};

struct Location
{
	SyncObj        Sync;
	MapVec         LocMaps;

	struct
	{
		uint   LocId;
		uint16 LocPid;
		uint16 WX;
		uint16 WY;
		uint16 Radius;
		bool   Visible;
		bool   GeckVisible;
		bool   AutoGarbage;
		bool   ToGarbage;
		uint   Color;
		uint   Reserved3[59];
	} Data;

	ProtoLocation* Proto;
	int            GeckCount;

	bool   IsNotValid;
	int16  RefCounter;

	bool   IsToGarbage()   {return Data.AutoGarbage || Data.ToGarbage;}
	bool   IsVisible()     {return Data.Visible || (Data.GeckVisible && GeckCount > 0);}
};

struct Field
{
	struct Tile
	{
		void* Anim;
		int16 OffsX;
		int16 OffsY;
		uint8 Layer;
	};
	typedef vector<Tile> TileVec;

	CritterCl* Crit;
	CrClVec    DeadCrits;
	int        ScrX;
	int        ScrY;
	TileVec    Tiles;
	TileVec    Roofs;
	ItemVec    Items;
	int16      RoofNum;
	bool       ScrollBlock;
	bool       IsWall;
	bool       IsWallSAI;
	bool       IsWallTransp;
	bool       IsScen;
	bool       IsExitGrid;
	bool       IsNotPassed;
	bool       IsNotRaked;
	uint8      Corner;
	bool       IsNoLight;
	uint8      LightValues[3];
	bool       IsMultihex;
};

struct SpriteInfo
{
	void*  Surface;
	float  SurfaceUV[4];
	uint16 Width;
	uint16 Height;
	int16  OffsX;
	int16  OffsY;
	void*  Effect;
	void*  Anim3d; // If Anim3d != NULL than this is pure 3d animation
};

struct Sprite
{
	// Ordering
	int     DrawOrderType; // 0..4 - flat, 5..9 - normal
	uint    DrawOrderPos;
	uint    TreeIndex;

	// Sprite information, pass to GetSpriteInfo
	uint    SprId;
	uint*   PSprId; // If PSprId == NULL than used SprId

	// Positions
	int     HexX, HexY;
	int     ScrX, ScrY;
	int16*  OffsX, *OffsY;

	// Cutting
	int     CutType; // See Sprites cutting
	Sprite* Parent, *Child;
	float   CutX, CutW, CutTexL, CutTexR;

	// Other
	uint8*  Alpha;
	uint8*  Light;
	int     EggType;
	int     ContourType;
	uint    ContourColor;
	uint    Color;
	uint    FlashMask;
	bool*   ValidCallback;
	bool    Valid; // If Valid == false than this sprite not valid

#ifdef __MAPPER
	int     CutOyL, CutOyR;
#endif

	uint GetSprId()
	{
		return PSprId ? *PSprId : SprId;
	}

	SpriteInfo* GetSprInfo()
	{
		return Game->GetSpriteInfo(PSprId ? *PSprId : SprId);
	}

 	void GetPos(int& x, int& y)
 	{
 		SpriteInfo* si = GetSprInfo();
 		x = (int)((float)(ScrX - si->Width / 2 + si->OffsX + (OffsX ? *OffsX : 0) + Game->ScrOx) / Game->SpritesZoom);
 		y = (int)((float)(ScrY - si->Height    + si->OffsY + (OffsY ? *OffsY : 0) + Game->ScrOy) / Game->SpritesZoom);
 	}
};


inline Field* GetField(uint hexX, uint hexY)
{
	if(!Game->ClientMap || hexX >= Game->ClientMapWidth || hexY >= Game->ClientMapHeight) return NULL;
	return &Game->ClientMap[hexY * Game->ClientMapWidth + hexX];
}

inline int GetDirection(int x1, int y1, int x2, int y2)
{
	float hx = (float)x1;
	float hy = (float)y1;
	float tx = (float)x2;
	float ty = (float)y2;
	float nx = 3 * (tx - hx);
	float ny = (ty - hy) * SQRT3T2_FLOAT - (float(x2 % 2) - float(x1 % 2)) * SQRT3_FLOAT;
	float dir = 180.0f + RAD2DEG * atan2f(ny, nx);

	if(dir >= 60.0f  && dir < 120.0f) return 5;
	if(dir >= 120.0f && dir < 180.0f) return 4;
	if(dir >= 180.0f && dir < 240.0f) return 3;
	if(dir >= 240.0f && dir < 300.0f) return 2;
	if(dir >= 300.0f && dir < 360.0f) return 1;
	return 0;
}

inline int GetDistantion(int x1, int y1, int x2, int y2)
{
	int dx = (x1 > x2 ? x1 - x2 : x2 - x1);
	if(x1%2 == 0)
	{
		if(y2 <= y1)
		{
			int rx = y1 - y2 - dx / 2;
			return dx + (rx > 0 ? rx : 0);
		}
		else
		{
			int rx = y2 - y1 - (dx + 1) / 2;
			return dx + (rx > 0 ? rx : 0);
		}
	}
	else
	{
		if(y2 >= y1)
		{
			int rx = y2 - y1 - dx / 2;
			return dx + (rx > 0 ? rx : 0);
		}
		else
		{
			int rx = y1 - y2 - (dx + 1) / 2;
			return dx + (rx > 0 ? rx : 0);
		}
	}
}


inline void static_asserts()
{
	STATIC_ASSERT(sizeof(uint)        == 4   );
	STATIC_ASSERT(sizeof(uint16)      == 2   );
	STATIC_ASSERT(sizeof(uint8)       == 1   );
	STATIC_ASSERT(sizeof(int)         == 4   );
	STATIC_ASSERT(sizeof(int16)       == 2   );
	STATIC_ASSERT(sizeof(int8)        == 1   );
	STATIC_ASSERT(sizeof(bool)        == 1   );
	STATIC_ASSERT(sizeof(string)      == 28  );
	STATIC_ASSERT(sizeof(IntVec)      == 16  );
	STATIC_ASSERT(sizeof(IntMap)      == 12  );
	STATIC_ASSERT(sizeof(IntSet)      == 12  );
	STATIC_ASSERT(sizeof(IntPair)     == 8   );
	STATIC_ASSERT(sizeof(GameVar)     == 28  );
	STATIC_ASSERT(sizeof(ProtoItem)   == 184 );
	STATIC_ASSERT(sizeof(Mutex)       == 24  );
	STATIC_ASSERT(sizeof(Spinlock)    == 4   );
	STATIC_ASSERT(sizeof(GameOptions) == 1176);
	STATIC_ASSERT(sizeof(ScriptArray) == 36  );
	STATIC_ASSERT(sizeof(SpriteInfo)  == 36  );
	STATIC_ASSERT(sizeof(Field)       == 92  );
#ifdef __MAPPER
	STATIC_ASSERT(sizeof(Sprite)      == 116 );
#else
	STATIC_ASSERT(sizeof(Sprite)      == 108 );
#endif

	STATIC_ASSERT(offsetof(TemplateVar, Flags)              == 76  );
	STATIC_ASSERT(offsetof(NpcPlane, RefCounter)            == 88  );
	STATIC_ASSERT(offsetof(GlobalMapGroup, EncounterForce)  == 88  );
	STATIC_ASSERT(offsetof(Item, IsNotValid)                == 118 );
	STATIC_ASSERT(offsetof(CritterTimeEvent, Identifier)    == 12  );
	STATIC_ASSERT(offsetof(Critter, RefCounter)             == 9312);
	STATIC_ASSERT(offsetof(Client, LanguageMsg)             == 9380);
	STATIC_ASSERT(offsetof(Npc, Reserved)                   == 9336);
	STATIC_ASSERT(offsetof(CritterCl, ItemSlotArmor)        == 4288);
	STATIC_ASSERT(offsetof(MapEntire, Dir)                  == 8   );
	STATIC_ASSERT(offsetof(SceneryToClient, Reserved1)      == 30  );
	STATIC_ASSERT(offsetof(ProtoMap, HexFlags)              == 332 );
	STATIC_ASSERT(offsetof(Map, RefCounter)                 == 794 );
	STATIC_ASSERT(offsetof(ProtoLocation, GeckVisible)      == 92  );
	STATIC_ASSERT(offsetof(Location, RefCounter)            == 286 );
}

#endif // __FONLINE__

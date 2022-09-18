#ifndef __FONLINE__
#define __FONLINE__

//
// FOnline engine structures, for native working
// Last update 29.08.2010
// Server version 347, MSVS2008
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

#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

class asIScriptEngine;

struct ScriptString;
struct ProtoItem;
struct GameVar;
struct TemplateVar;
struct NpcPlane;
struct GlobalMapGroup;
struct Item;
struct ItemCl;
struct CritterTimeEvent;
struct Critter;
struct Client;
struct Npc;
struct CritterCl;
struct Scenery;
struct MapEntire;
struct SceneryToClient;
struct ProtoMap;
struct Map;
struct GlobalMapZone;
struct ProtoLocation;
struct Location;

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
typedef vector<Client*> ClVec;
typedef vector<Client*>::iterator ClVecIt;
typedef vector<Npc*> PcVec;
typedef vector<Npc*>::iterator PcVecIt;
typedef vector<Item*> ItemVec;
typedef vector<Item*>::iterator ItemVecIt;
typedef vector<Scenery*> SceneryVec;
typedef vector<Scenery*>::iterator SceneryVecIt;
typedef vector<Map*> MapVec;
typedef vector<Map*>::iterator MapVecIt;
typedef vector<Location*> LocVec;
typedef vector<Location*>::iterator LocVecIt;

#define STATIC_ASSERT(a)              {static int arr[(a)?1:-1];}
#define BIN__N(x)                     (x) | x>>3 | x>>6 | x>>9
#define BIN__B(x)                     (x) & 0xf | (x)>>12 & 0xf0
#define BIN8(v)                       (BIN__B(BIN__N(0x##v)))
#define BIN16(bin16,bin8)             ((BIN8(bin16)<<8)|(BIN8(bin8)))
#define BIN32(bin32,bin24,bin16,bin8) ((BIN8(bin32)<<24)|(BIN8(bin24)<<16)|(BIN8(bin16)<<8)|(BIN8(bin8)))

#define FLAG(x,y)                   (((x)&(y))!=0)
#define CLAMP(x,low,high)           (((x)>(high))?(high):(((x)<(low))?(low):(x)))
#define SQRT3T2_FLOAT               (3.4641016151f)
#define SQRT3_FLOAT                 (1.732050807568877f)
#define RAD2DEG                     (57.29577951f)

#define VAR_CALC_QUEST(tid,val)     ((tid)*1000+(val))
#define VAR_GLOBAL                  (0)
#define VAR_LOCAL                   (1)
#define VAR_UNICUM                  (2)
#define VAR_FLAG_QUEST              (0x1)
#define VAR_FLAG_RANDOM             (0x2)
#define VAR_FLAG_NO_CHECK           (0x4)

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

#define CAR_MAX_BLOCKS              (80)
#define CAR_MAX_BAG_POSITION        (12)

#define WEAR_MAX                    (30000)
#define BI_LOWBROKEN                (0x01)
#define BI_NORMBROKEN               (0x02)
#define BI_HIGHBROKEN               (0x04)
#define BI_NOTRESC                  (0x08)
#define BI_BROKEN                   (0x0F)
#define BI_SERVICE                  (0x10)
#define BI_SERVICE_EXT              (0x20)
#define BI_ETERNAL                  (0x40)

#define LOCKER_ISOPEN               (0x01)
#define LOCKER_BROKEN               (0x08)
#define LOCKER_NOOPEN               (0x10)

#define ITEM_TILE                   (0)
#define ITEM_ARMOR                  (1)
#define ITEM_DRUG                   (2)
#define ITEM_WEAPON                 (3)
#define ITEM_AMMO                   (4)
#define ITEM_MISC                   (5)
#define ITEM_MISC_EX                (6)
#define ITEM_KEY                    (7)
#define ITEM_CONTAINER              (8)
#define ITEM_DOOR                   (9)
#define ITEM_GRID                   (10)
#define ITEM_GENERIC                (11)
#define ITEM_WALL                   (12)

#define USE_PRIMARY                 (0)
#define USE_SECONDARY               (1)
#define USE_THIRD                   (2)
#define USE_RELOAD                  (3)
#define USE_USE                     (4)
#define MAX_USES					(3)
#define USE_NONE                    (15)

#define ITEM_HIDDEN                 (0x00000001)
#define ITEM_FLAT                   (0x00000002)
#define ITEM_NO_BLOCK               (0x00000004)
#define ITEM_SHOOT_THRU             (0x00000008)
#define ITEM_LIGHT_THRU             (0x00000010)
#define ITEM_MULTI_HEX              (0x00000020)
#define ITEM_WALL_TRANS_END         (0x00000040)
#define ITEM_TWO_HANDS              (0x00000080)
#define ITEM_BIG_GUN                (0x00000100)
#define ITEM_ALWAYS_VIEW            (0x00000200)
#define ITEM_HAS_TIMER              (0x00000400)
#define ITEM_BAD_ITEM               (0x00000800)
#define ITEM_NO_HIGHLIGHT           (0x00001000)
#define ITEM_SHOW_ANIM              (0x00002000)
#define ITEM_SHOW_ANIM_EXT          (0x00004000)
#define ITEM_GECK                   (0x00010000)
#define ITEM_TRAP                   (0x00020000)
#define ITEM_NO_LIGHT_INFLUENCE     (0x00040000)
#define ITEM_NO_LOOT                (0x00080000)
#define ITEM_NO_STEAL               (0x00100000)
#define ITEM_GAG                    (0x00200000)
#define ITEM_LIGHT                  (0x00400000)
#define ITEM_COLORIZE               (0x00800000)
#define ITEM_CAN_USE_ON_SMTH        (0x01000000)
#define ITEM_CAN_LOOK               (0x02000000)
#define ITEM_CAN_TALK               (0x04000000)
#define ITEM_CAN_PICKUP             (0x08000000)
#define ITEM_CAN_USE                (0x10000000)
#define ITEM_CACHED                 (0x80000000)

#define WEAPON_PERK_FAST_RELOAD     (6)

#define PID_HOLODISK                (58)
#define PID_RADIO                   (100)

#define MAX_PARAMS                  (1000)
#define ST_STRENGTH                 (0)
#define ST_PERCEPTION               (1)
#define ST_ENDURANCE                (2)
#define ST_CHARISMA                 (3)
#define ST_INTELLECT                (4)
#define ST_AGILITY                  (5)
#define ST_LUCK                     (6)
#define ST_MAX_LIFE                 (7)
#define ST_ACTION_POINTS            (8)
#define ST_ARMOR_CLASS              (9)
#define ST_MELEE_DAMAGE             (10)
#define ST_CARRY_WEIGHT             (11)
#define ST_SEQUENCE                 (12)
#define ST_HEALING_RATE             (13)
#define ST_CRITICAL_CHANCE          (14)
#define ST_MAX_CRITICAL             (15)
#define ST_NORMAL_ABSORB            (16)
#define ST_LASER_ABSORB             (17)
#define ST_FIRE_ABSORB              (18)
#define ST_PLASMA_ABSORB            (19)
#define ST_ELECTRO_ABSORB           (20)
#define ST_EMP_ABSORB               (21)
#define ST_EXPLODE_ABSORB           (22)
#define ST_NORMAL_RESIST            (23)
#define ST_LASER_RESIST             (24)
#define ST_FIRE_RESIST              (25)
#define ST_PLASMA_RESIST            (26)
#define ST_ELECTRO_RESIST           (27)
#define ST_EMP_RESIST               (28)
#define ST_EXPLODE_RESIST           (29)
#define ST_RADIATION_RESISTANCE     (30)
#define ST_POISON_RESISTANCE        (31)
#define ST_STRENGTH_EXT             (32)
#define ST_PERCEPTION_EXT           (33)
#define ST_ENDURANCE_EXT            (34)
#define ST_CHARISMA_EXT             (35)
#define ST_INTELLECT_EXT            (36)
#define ST_AGILITY_EXT              (37)
#define ST_LUCK_EXT                 (38)
#define ST_MAX_LIFE_EXT             (39)
#define ST_ACTION_POINTS_EXT        (40)
#define ST_ARMOR_CLASS_EXT          (41)
#define ST_MELEE_DAMAGE_EXT         (42)
#define ST_CARRY_WEIGHT_EXT         (43)
#define ST_SEQUENCE_EXT             (44)
#define ST_HEALING_RATE_EXT         (45)
#define ST_CRITICAL_CHANCE_EXT      (46)
#define ST_MAX_CRITICAL_EXT         (47)
#define ST_NORMAL_ABSORB_EXT        (48)
#define ST_LASER_ABSORB_EXT         (49)
#define ST_FIRE_ABSORB_EXT          (50)
#define ST_PLASMA_ABSORB_EXT        (51)
#define ST_ELECTRO_ABSORB_EXT       (52)
#define ST_EMP_ABSORB_EXT           (53)
#define ST_EXPLODE_ABSORB_EXT       (54)
#define ST_NORMAL_RESIST_EXT        (55)
#define ST_LASER_RESIST_EXT         (56)
#define ST_FIRE_RESIST_EXT          (57)
#define ST_PLASMA_RESIST_EXT        (58)
#define ST_ELECTRO_RESIST_EXT       (59)
#define ST_EMP_RESIST_EXT           (60)
#define ST_EXPLODE_RESIST_EXT       (61)
#define ST_RADIATION_RESISTANCE_EXT (62)
#define ST_POISON_RESISTANCE_EXT    (63)
#define ST_AGE                      (70)
#define ST_GENDER					(71)
#define ST_CURRENT_HP				(72)
#define ST_POISONING_LEVEL          (73)
#define ST_RADIATION_LEVEL          (74)
#define ST_CURRENT_AP				(75)
#define ST_EXPERIENCE				(76)
#define ST_LEVEL                    (77)
#define ST_UNSPENT_SKILL_POINTS     (78)
#define ST_UNSPENT_PERKS            (79)
#define ST_KARMA                    (80)
#define ST_FOLLOW_CRIT              (81)
#define ST_REPLICATION_MONEY        (82)
#define ST_REPLICATION_COUNT        (83)
#define ST_REPLICATION_TIME         (84)
#define ST_REPLICATION_COST         (85)
#define ST_TURN_BASED_AC            (86)
#define ST_MAX_MOVE_AP              (87)
#define ST_MOVE_AP                  (88)
#define ST_NPC_ROLE                 (89)
#define ST_BONUS_LOOK               (101)
#define ST_RATE_OBJECT              (102)
#define ST_FREE_BARTER_PLAYER       (103)
#define ST_DIALOG_ID                (104)
#define ST_AI_ID                    (105)
#define ST_TEAM_ID                  (106)
#define ST_BAG_ID                   (107)
#define ST_BASE_CRTYPE              (112)
#define ST_TALK_DISTANCE            (115)
#define ST_SCALE_FACTOR             (116)
#define ST_ANIM3D_LAYER_BEGIN       (150)
#define ST_ANIM3D_LAYER_END         (179)
#define MAX_SKILL_VAL               (300)
#define SK_SMALL_GUNS               (200)
#define SK_BIG_GUNS                 (201)
#define SK_ENERGY_WEAPONS           (202)
#define SK_UNARMED                  (203)
#define SK_MELEE_WEAPONS            (204)
#define SK_THROWING                 (205)
#define SK_FIRST_AID                (206)
#define SK_DOCTOR                   (207)
#define SK_SNEAK                    (208)
#define SK_LOCKPICK                 (209)
#define SK_STEAL                    (210)
#define SK_TRAPS                    (211)
#define SK_SCIENCE                  (212)
#define SK_REPAIR                   (213)
#define SK_SPEECH                   (214)
#define SK_BARTER                   (215)
#define SK_OUTDOORSMAN              (217)
#define TAG_SKILL1                  (226)
#define TAG_SKILL2                  (227)
#define TAG_SKILL3                  (228)
#define TAG_SKILL4                  (229)
#define TO_SK_REPAIR                (232)
#define TO_SK_SCIENCE               (233)
#define TO_BATTLE                   (238)
#define TO_TRANSFER                 (239)
#define TO_REMOVE_FROM_GAME         (240)
#define TO_KARMA_VOTING             (242)
#define TB_BATTLE_TIMEOUT           (10000000)
#define TB_BATTLE_TIMEOUT_CHECK(to) ((to)>100000)
#define PE_BONUS_HTH_ATTACKS        (302)
#define PE_BONUS_RATE_OF_FIRE       (306)
#define PE_SILENT_RUNNING           (316)
#define PE_MASTER_TRADER            (318)
#define PE_HEAVE_HO                 (336)
#define PE_PATHFINDER               (344)
#define PE_SCOUT                    (346)
#define PE_QUICK_POCKETS            (349)
#define PE_SMOOTH_TALKER            (350)
#define PE_ADRENALINE_RUSH          (380)
#define PE_HTH_EVADE                (394)
#define DAMAGE_POISONED             (500)
#define DAMAGE_RADIATED             (501)
#define DAMAGE_EYE                  (502)
#define DAMAGE_RIGHT_ARM            (503)
#define DAMAGE_LEFT_ARM             (504)
#define DAMAGE_RIGHT_LEG            (505)
#define DAMAGE_LEFT_LEG             (506)
#define MODE_HIDE                   (510)
#define MODE_NO_STEAL               (511)
#define MODE_NO_BARTER              (512)
#define MODE_NO_ENEMY_STACK         (513)
#define MODE_NO_PVP                 (514)
#define MODE_END_COMBAT             (515)
#define MODE_DEFAULT_COMBAT         (516)
#define MODE_NO_HOME                (517)
#define MODE_GECK                   (518)
#define MODE_NO_FAVORITE_ITEM       (519)
#define MODE_NO_ITEM_GARBAGER       (520)
#define MODE_DLG_SCRIPT_BARTER      (521)
#define MODE_UNLIMITED_AMMO         (522)
#define MODE_NO_HEAL                (526)
#define MODE_INVULNERABLE           (527)
#define MODE_NO_FLATTEN             (528)
#define MODE_RANGE_HTH              (530)
#define MODE_NO_LOOT                (532)
#define TRAIT_SMALL_FRAME           (552)
#define TRAIT_FAST_SHOT             (557)
#define TRAIT_SEX_APPEAL            (563)
#define TRAIT_NIGHT_PERSON          (565)

#define ITEM_EVENT_MAX              (8)
#define CRITTER_EVENT_MAX           (42)

#define MAP_EVENT_MAX               (12)
#define MAP_LOOP_FUNC_MAX           (5)
#define MAP_MAX_DATA                (100)

#define FH_BLOCK                       BIN8(00000001)
#define FH_NOTRAKE                     BIN8(00000010)
#define FH_WALL                        BIN8(00000100)
#define FH_SCEN                        BIN8(00001000)
#define FH_SCEN_GRID                   BIN8(00010000)
#define FH_TRIGGER                     BIN8(00100000)
#define FH_CRITTER            BIN8(00000001)
#define FH_DEAD_CRITTER       BIN8(00000010)
#define FH_ITEM               BIN8(00000100)
#define FH_BLOCK_ITEM         BIN8(00010000)
#define FH_NRAKE_ITEM         BIN8(00100000)
#define FH_WALK_ITEM          BIN8(01000000)
#define FH_GAG_ITEM           BIN8(10000000)
#define FH_NOWAY             BIN16(00010001,00000001)
#define FH_NOSHOOT           BIN16(00100000,00000010)

#define ACCESS_CLIENT               BIN8(00000001)
#define ACCESS_TESTER               BIN8(00000010)
#define ACCESS_MODER                BIN8(00000100)
#define ACCESS_ADMIN                BIN8(00001000)

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
	uint   ForceDialog;
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
	uint   HitAimEyes;
	uint   HitAimHead;
	uint   HitAimGroin;
	uint   HitAimTorso;
	uint   HitAimArms;
	uint   HitAimLegs;
	bool   RunOnCombat;
	bool   RunOnTransfer;
	uint   GlobalMapWidth;
	uint   GlobalMapHeight;
	uint   GlobalMapZoneLength;
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

	// Client
	string UserInterface;
	bool   DisableDrawScreens;
	uint   Animation3dSmoothTime;
	uint   Animation3dFPS;
	int    RunModMul;
	int    RunModDiv;
	int    RunModAdd;
};

struct ScriptString
{
	string Buffer;
	int    RefCount;
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
	int8   DrawPosOffsY;

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

			uint8  CountAttack;
			uint8  Skill[MAX_USES];
			uint8  DmgType[MAX_USES];
			uint8  Anim2[MAX_USES];
			uint16 PicDeprecated[MAX_USES];
			uint   PicHash[MAX_USES];
			uint16 DmgMin[MAX_USES];
			uint16 DmgMax[MAX_USES];
			uint16 MaxDist[MAX_USES];
			uint16 Effect[MAX_USES];
			uint16 Round[MAX_USES];
			uint   Time[MAX_USES];
			bool   Aim[MAX_USES];
			bool   Remove[MAX_USES];
			uint8  SoundId[MAX_USES];

			uint8  Weapon_CurrentUse;
			uint16 Weapon_MaxDist;
			uint16 Weapon_DmgMin;
			uint16 Weapon_DmgMax;
			uint8  Weapon_Skill;
			uint8  Weapon_DmgType;
			uint8  Weapon_Anim2;
			uint8  Weapon_ApCost;
			uint8  Weapon_SoundId;
			bool   Weapon_Remove;
			uint16 Weapon_Round;
			uint16 Weapon_Effect;
			bool   Weapon_Aim;
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

				uint8  Bag0[CAR_MAX_BAG_POSITION/2]; // 6
				uint8  Bag1[CAR_MAX_BAG_POSITION/2]; // 6
				uint8  Blocks[CAR_MAX_BLOCKS/2]; // 40

				uint8  GetBag0Dir(int num)  {return ((num % 2) ? (Bag0  [num / 2] & 0xF) : (Bag0  [num / 2] >> 4));}
				uint8  GetBag1Dir(int num)  {return ((num % 2) ? (Bag1  [num / 2] & 0xF) : (Bag1  [num / 2] >> 4));}
				uint8  GetBlockDir(int num) {return ((num % 2) ? (Blocks[num / 2] & 0xF) : (Blocks[num / 2] >> 4));}
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

	void   Weapon_SetUse(uint8 use)
	{
		if(use >= MAX_USES) use = USE_PRIMARY;
		Weapon.Weapon_CurrentUse = use;
		Weapon.Weapon_Skill      = Weapon.Skill[use];
		Weapon.Weapon_DmgType    = Weapon.DmgType[use];
		Weapon.Weapon_Anim2      = Weapon.Anim2[use];
		Weapon.Weapon_DmgMin     = Weapon.DmgMin[use];
		Weapon.Weapon_DmgMax     = Weapon.DmgMax[use];
		Weapon.Weapon_MaxDist    = Weapon.MaxDist[use];
		Weapon.Weapon_Effect     = Weapon.Effect[use];
		Weapon.Weapon_Round      = Weapon.Round[use];
		Weapon.Weapon_ApCost     = Weapon.Time[use];
		Weapon.Weapon_SoundId    = Weapon.SoundId[use];
		Weapon.Weapon_Remove     = Weapon.Remove[use];
		Weapon.Weapon_Aim        = Weapon.Aim[use];
	}

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
	uint64 VarId;
	int    VarValue;
	TemplateVar* VarTemplate;
	uint   QuestVarIndex;
	uint16 Type;
	int16  RefCount;

	int    GetValue()    {return VarValue;}
	int    GetMin()      {return VarTemplate->MinVal;}
	int    GetMax()      {return VarTemplate->MaxVal;}
	bool   IsQuest()     {return VarTemplate->IsQuest();}
	uint   GetQuestStr() {return VAR_CALC_QUEST(VarTemplate->TempId, VarValue);}
	uint   GetMasterId() {return (uint)((VarId >> 24) & 0xFFFFFF);}
	uint   GetSlaveId()  {return (uint)(VarId & 0xFFFFFF);}
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
		uint8  Reserved0;
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
	bool  Reserved1;

	// Used only in server
	int      FuncId[ITEM_EVENT_MAX];
	Critter* ViewByCritter;
	ItemVec* ChildItems;
	int8*    Lexems;

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
	bool   WeapIsUseAviable(int use) {uint8 ca = Proto->Weapon.CountAttack; if(use == USE_PRIMARY) return FLAG(ca, 1); if(use == USE_SECONDARY) return FLAG(ca, 2); if(use == USE_THIRD) return FLAG(ca, 4); return false;}
	bool   WeapIsCanAim(int use)     {return use < MAX_USES && Proto->Weapon.Aim[use];}
	bool   WeapIsFastReload()        {return Proto->Weapon.Perk == WEAPON_PERK_FAST_RELOAD;}

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

	// Radio
	bool   IsRadio()                    {return GetProtoId() == PID_RADIO;}
	uint16 RadioGetChannel()            {return Data.Radio.Channel;}
	void   RadioSetChannel(uint16 chan) {Data.Radio.Channel = chan;}

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

	// Holodisk
	bool   IsHolodisk()            {return GetProtoId() == PID_HOLODISK;}
	uint   HolodiskGetNum()        {return Data.Holodisk.Number;}

	// Trap
	bool   IsTrap()                {return FLAG(Data.Flags, ITEM_TRAP);}
	int    TrapGetValue()          {return Data.TrapValue;}
};

struct ItemCl
{
	Item   Main;
	string Lexems;
	int    LexemsRefCounter;
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
	uint8  CondExt;
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
	uint   Reserved3[10];
	int8   Lexems[LEXEMS_SIZE];
	uint   Reserved4[8];
	bool   ClientToDelete;
	uint8  Reserved5;
	uint16 Reserved6;
	uint   Reserved7;
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
		uint   Reserved25[100];
	} *DataExt;

	bool   CritterIsNpc;
	uint   Flags;
	string NameStr;
	int    NameStrRefCounter;

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
	uint     ViewMapId;
	uint16   ViewMapPid,ViewMapLook,ViewMapHx,ViewMapHy;
	uint8    ViewMapDir;
	uint     ViewMapLocId,ViewMapLocEnt;

	GlobalMapGroup* GroupSelf;
	GlobalMapGroup* GroupMove;

	Item     DefItemSlotMain;
	Item     DefItemSlotExt;
	Item     DefItemSlotArmor;
	ItemVec  InvItems;
	Item*    ItemSlotMain;
	Item*    ItemSlotExt;
	Item*    ItemSlotArmor;
	int      FuncId[CRITTER_EVENT_MAX];
	uint     KnockoutAp;
	uint     LastHealTick;
	uint     StartBreakTime;
	int	     BreakTime;
	uint     WaitEndTick;
	int      DisableSend;
	uint     AccessContainerId;
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
	int8   Name[MAX_NAME+1];
	int8   Pass[MAX_NAME+1];
	uint8  Access;
	uint   LanguageMsg;
};

struct Npc : Critter
{
	uint        NextRefreshBagTick;
	NpcPlaneVec AiPlanes;
	uint        LastBattleWeaponId;
	uint        LastBattleWeaponUse;
	uint        Reserved;
};

struct CritterCl
{
	uint   Id;
	uint16 Pid;
	uint16 HexX,HexY;
	uint8  CrDir;
	int    Params[MAX_PARAMS];
};

struct Scenery
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

	int8   ScriptName[MAPOBJ_SCRIPT_NAME+1];
	int8   FuncName[MAPOBJ_SCRIPT_NAME+1];

	uint   Reserved[7];
	int    UserData[10];

	union
	{
		struct
		{
			uint8  Cond;
			uint8  CondExt;
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
			uint16 PicMap;
			uint16 PicInv;
			uint8  InfoOffset;
			uint8  Reserved[11];

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
			uint16 PicMap;
			uint16 PicInv;
			uint8  InfoOffset;
			uint8  Reserved[11];

			bool   CanUse;
			bool   CanTalk;
			uint   TriggerNum;

			uint8  ParamsCount;
			int    Param[5];

			uint16 ToMapPid;
			uint   ToEntire;
			uint16 ToMapX;
			uint16 ToMapY;
			uint8  ToDir;
		} MScenery;

		struct
		{
			uint   Buffer[25];
		} MAlign;
	};

	struct _RunTime
	{
		int   BindScriptId;
		int   RefCounter;
	} RunTime;
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
		bool   Packed;
		bool   NoLogOut;
		uint16 HeaderSize;
		int    PlayersLimit;
		uint   UnpackedDataLen;
		uint16 MaxHexX;
		uint16 MaxHexY;
		int    Time;
		int    CenterX;
		int    CenterY;
		int8   ScriptModule[MAX_SCRIPT_NAME+1];
		int8   ScriptFunc[MAX_SCRIPT_NAME+1];
		int    DayTime[4];
		uint8  DayColor[12];
	} Header;

	SceneryVec MObjects;
	uint*      Tiles;

	SceneryToClientVec WallsToSend;
	SceneryToClientVec SceneriesToSend;
	uint HashTiles;
	uint HashWalls;
	uint HashScen;

	SceneryVec CrittersVec;
	SceneryVec ItemsVec;
	SceneryVec SceneriesVec;
	SceneryVec GridsVec;
	uint8*     HexFlags;

	EntiresVec MapEntires;

	int    PathType;
	string Name;
	uint16 Pid;

	uint   GetTilesSize()                            {return (Header.MaxHexX/2)*(Header.MaxHexY/2)*sizeof(uint);}
	uint16 GetTile(uint16 tx, uint16 ty)             {return Tiles[ty*(Header.MaxHexX/2)+tx]>>16;}
	uint16 GetRoof(uint16 tx, uint16 ty)             {return Tiles[ty*(Header.MaxHexX/2)+tx]&0xFFFF;}
	void   SetTile(uint16 tx, uint16 ty, uint16 pic) {((uint16*)&Tiles[ty*(Header.MaxHexX/2)+tx])[1]=pic;}
	void   SetRoof(uint16 tx, uint16 ty, uint16 pic) {((uint16*)&Tiles[ty*(Header.MaxHexX/2)+tx])[0]=pic;}
};

struct Map
{
	uint8*    HexFlags;
	CrVec     MapCritters;
	ClVec     MapPlayers;
	PcVec     MapNpcs;
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

	bool      NeedProcess;
	uint      FuncId[MAP_EVENT_MAX];
	uint      LoopEnabled[MAP_LOOP_FUNC_MAX];
	uint      LoopLastTick[MAP_LOOP_FUNC_MAX];
	uint      LoopWaitTick[MAP_LOOP_FUNC_MAX];

	ItemVec   HexItems;
	ProtoMap* Proto;

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

struct GlobalMapZone
{
	LocVec Locations;
	uint16 ZoneX;
	uint16 ZoneY;
	uint   Reserved;
};

struct ProtoLocation
{
	bool        IsInit;
	uint16      LocPid;
	string      Name;

	uint16      MaxCopy;
	Uint16Vec   ProtoMapPids;
	Uint16Vec   AutomapsPids;
	UintPairVec Entrance;
	int         ScriptBindId;

	uint16      Radius;
	bool        Visible;
	bool        AutoGarbage;
	bool        GeckEnabled;
};

struct Location
{
	MapVec         LocMaps;
	GlobalMapZone* LocZone;

	struct
	{
		uint   LocId;
		uint16 LocPid;
		uint16 WX;
		uint16 WY;
		uint16 Radius;
		bool   Visible;
		bool   GeckEnabled;
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
	bool   IsVisible()     {return Data.Visible || IsGeckAviable();}
	bool   IsGeckAviable() {return Data.GeckEnabled && GeckCount>0;}
};


int GetDirection(int x1, int y1, int x2, int y2)
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

int GetDistantion(int x1, int y1, int x2, int y2)
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


void static_asserts()
{
	STATIC_ASSERT(sizeof(uint)    == 4);
	STATIC_ASSERT(sizeof(uint16)  == 2);
	STATIC_ASSERT(sizeof(uint8)   == 1);
	STATIC_ASSERT(sizeof(int)     == 4);
	STATIC_ASSERT(sizeof(int16)   == 2);
	STATIC_ASSERT(sizeof(int8)    == 1);
	STATIC_ASSERT(sizeof(bool)    == 1);
	STATIC_ASSERT(sizeof(string)  == 28);
	STATIC_ASSERT(sizeof(IntVec)  == 16);
	STATIC_ASSERT(sizeof(IntMap)  == 12);
	STATIC_ASSERT(sizeof(IntSet)  == 12);
	STATIC_ASSERT(sizeof(IntPair) == 8);

	STATIC_ASSERT(offsetof(ProtoItem,Weapon.Weapon_Aim)     == 182);
	STATIC_ASSERT(offsetof(GameVar, RefCount)               == 22);
	STATIC_ASSERT(offsetof(TemplateVar, Flags)              == 76);
	STATIC_ASSERT(offsetof(NpcPlane, RefCounter)            == 88);
	STATIC_ASSERT(offsetof(GlobalMapGroup, EncounterForce)  == 84);
	STATIC_ASSERT(offsetof(Item, Lexems)                    == 160);
	STATIC_ASSERT(offsetof(CritterTimeEvent, Identifier)    == 12);
	STATIC_ASSERT(offsetof(Critter, RefCounter)             == 9768);
	STATIC_ASSERT(offsetof(Client, LanguageMsg)             == 9836);
	STATIC_ASSERT(offsetof(Npc, Reserved)                   == 9800);
	STATIC_ASSERT(offsetof(Scenery, RunTime.RefCounter)     == 244);
	STATIC_ASSERT(offsetof(MapEntire, Dir)                  == 8);
	STATIC_ASSERT(offsetof(SceneryToClient, Reserved1)      == 30);
	STATIC_ASSERT(offsetof(ProtoMap, HexFlags)              == 320);
	STATIC_ASSERT(offsetof(Map, RefCounter)                 == 766);
	STATIC_ASSERT(offsetof(GlobalMapZone, Reserved)         == 20);
	STATIC_ASSERT(offsetof(ProtoLocation, GeckEnabled)      == 92);
	STATIC_ASSERT(offsetof(Location, RefCounter)            == 286);
}

#endif // __FONLINE__

////////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////

#ifndef __ENUMS__
#define __ENUMS__

#include <string>
#include <list>

#define PLAYER_ID_RANGE 0x10000000
#define MONSTER_ID_RANGE 0x40000000
#define NPC_ID_RANGE 0x80000000

enum Vocation_t
{
	VOCATION_NONE = 0,
	VOCATION_SORCERER = 1,
	VOCATION_DRUID = 2,
	VOCATION_PALADIN = 3,
	VOCATION_KNIGHT = 4,
	VOCATION_MASTERSORCERER = 5,
	VOCATION_ELDERDRUID = 6,
	VOCATION_ROYALPALADIN = 7,
	VOCATION_ELITEKNIGHT = 8
};

enum multiplier_t
{
	MULTIPLIER_FIRST = 0,
	MULTIPLIER_MELEE = MULTIPLIER_FIRST,
	MULTIPLIER_DISTANCE = 1,
	MULTIPLIER_DEFENSE = 2,
	MULTIPLIER_MAGICDEFENSE = 3,
	MULTIPLIER_ARMOR = 4,
	MULTIPLIER_MAGIC = 5,
	MULTIPLIER_HEALING = 6,
	MULTIPLIER_WAND = 7,
	MULTIPLIER_MANA = 8,
	MULTIPLIER_LAST = MULTIPLIER_MANA
};

enum gain_t
{
	GAIN_FIRST = 0,
	GAIN_HEALTH = GAIN_FIRST,
	GAIN_MANA = 1,
	#ifdef _MULTIPLATFORM76
	GAIN_SOUL = 2,
	GAIN_LAST = GAIN_SOUL
	#else
	GAIN_LAST = GAIN_MANA
	#endif
};

enum CreatureType_t
{
	CREATURETYPE_PLAYER = 0,
	CREATURETYPE_MONSTER = 1,
	CREATURETYPE_NPC = 2
};

enum DatabaseEngine_t
{
	DATABASE_ENGINE_NONE = 0,
	DATABASE_ENGINE_MYSQL,
	DATABASE_ENGINE_SQLITE,
	DATABASE_ENGINE_POSTGRESQL
};

enum Encryption_t
{
	ENCRYPTION_PLAIN = 0,
	ENCRYPTION_MD5,
	ENCRYPTION_SHA1,
	ENCRYPTION_SHA256,
	ENCRYPTION_SHA512
};

enum GuildLevel_t
{
	GUILDLEVEL_NONE = 0,
	GUILDLEVEL_MEMBER,
	GUILDLEVEL_VICE,
	GUILDLEVEL_LEADER
};

enum Channels_t
{
	CHANNEL_GUILD = 0x00,
	CHANNEL_PARTY = 0x01,
	CHANNEL_RVR = 0x03,
	CHANNEL_HELP = 0x07,
	CHANNEL_DEFAULT = 0xFFFE, //internal usage only, there is no such channel
	CHANNEL_PRIVATE = 0xFFFF
};

enum ViolationAction_t
{
	ACTION_NOTATION = 0,
	ACTION_NAMEREPORT,
	ACTION_BANISHMENT,
	ACTION_BANREPORT,
	ACTION_BANFINAL,
	ACTION_BANREPORTFINAL,
	ACTION_STATEMENT,
	//internal use
	ACTION_DELETION,
	ACTION_NAMELOCK,
	ACTION_BANLOCK,
	ACTION_BANLOCKFINAL,
	ACTION_PLACEHOLDER
};

enum RaceType_t
{
	RACE_NONE = 0,
	RACE_VENOM,
	RACE_BLOOD,
	RACE_UNDEAD,
	RACE_FIRE,
	RACE_ENERGY
};

enum CombatType_t
{
	COMBAT_NONE				= 0x00,
	COMBAT_ALL				= COMBAT_NONE, /* for internal use only.*/

	COMBAT_PHYSICALDAMAGE	= 1 << 0,
	COMBAT_ENERGYDAMAGE		= 1 << 1,
	COMBAT_EARTHDAMAGE		= 1 << 2,
	COMBAT_FIREDAMAGE		= 1 << 3,
	COMBAT_UNDEFINEDDAMAGE	= 1 << 4,
	COMBAT_LIFEDRAIN		= 1 << 5,
	COMBAT_MANADRAIN		= 1 << 6,
	COMBAT_HEALING			= 1 << 7,
	COMBAT_DROWNDAMAGE		= 1 << 8,
	COMBAT_ICEDAMAGE		= 1 << 9,
	COMBAT_HOLYDAMAGE		= 1 << 10,
	COMBAT_DEATHDAMAGE		= 1 << 11,

	COMBAT_FIRST			= COMBAT_NONE,
	COMBAT_LAST				= COMBAT_DEATHDAMAGE
};

enum CombatParam_t
{
	COMBATPARAM_NONE = 0,
	COMBATPARAM_COMBATTYPE,
	COMBATPARAM_EFFECT,
	COMBATPARAM_DISTANCEEFFECT,
	COMBATPARAM_BLOCKEDBYSHIELD,
	COMBATPARAM_BLOCKEDBYARMOR,
	COMBATPARAM_TARGETCASTERORTOPMOST,
	COMBATPARAM_CREATEITEM,
	COMBATPARAM_AGGRESSIVE,
	COMBATPARAM_DISPEL,
	COMBATPARAM_USECHARGES,
	COMBATPARAM_TARGETPLAYERSORSUMMONS,
	COMBATPARAM_DIFFERENTAREADAMAGE,
	COMBATPARAM_HITEFFECT,
	COMBATPARAM_HITCOLOR,
	COMBATPARAM_ELEMENTTYPE,
	COMBATPARAM_ELEMENTDAMAGE
};

enum CallBackParam_t
{
	CALLBACKPARAM_NONE = 0,
	CALLBACKPARAM_LEVELMAGICVALUE,
	CALLBACKPARAM_SKILLVALUE,
	CALLBACKPARAM_TARGETTILECALLBACK,
	CALLBACKPARAM_TARGETCREATURECALLBACK
};

enum ConditionParam_t
{
	CONDITIONPARAM_OWNER = 1,
	CONDITIONPARAM_TICKS,
	CONDITIONPARAM_OUTFIT,
	CONDITIONPARAM_HEALTHGAIN,
	CONDITIONPARAM_HEALTHTICKS,
	CONDITIONPARAM_MANAGAIN,
	CONDITIONPARAM_MANATICKS,
	CONDITIONPARAM_DELAYED,
	CONDITIONPARAM_SPEED,
	CONDITIONPARAM_LIGHT_LEVEL,
	CONDITIONPARAM_LIGHT_COLOR,
	#ifdef _MULTIPLATFORM76
	CONDITIONPARAM_SOULGAIN,
	CONDITIONPARAM_SOULTICKS,
	#endif
	CONDITIONPARAM_MINVALUE,
	CONDITIONPARAM_MAXVALUE,
	CONDITIONPARAM_STARTVALUE,
	CONDITIONPARAM_TICKINTERVAL,
	CONDITIONPARAM_FORCEUPDATE,
	CONDITIONPARAM_SKILL_MELEE,
	CONDITIONPARAM_SKILL_FIST,
	CONDITIONPARAM_SKILL_CLUB,
	CONDITIONPARAM_SKILL_SWORD,
	CONDITIONPARAM_SKILL_AXE,
	CONDITIONPARAM_SKILL_DISTANCE,
	CONDITIONPARAM_SKILL_SHIELD,
	CONDITIONPARAM_SKILL_FISHING,
	CONDITIONPARAM_STAT_MAXHEALTH,
	CONDITIONPARAM_STAT_MAXMANA,
	#ifdef _MULTIPLATFORM76
	CONDITIONPARAM_STAT_SOUL,
	#endif
	CONDITIONPARAM_STAT_MAGICLEVEL,
	CONDITIONPARAM_STAT_MAXHEALTHPERCENT,
	CONDITIONPARAM_STAT_MAXMANAPERCENT,
	#ifdef _MULTIPLATFORM76
	CONDITIONPARAM_STAT_SOULPERCENT,
	#endif
	CONDITIONPARAM_STAT_MAGICLEVELPERCENT,
	CONDITIONPARAM_SKILL_MELEEPERCENT,
	CONDITIONPARAM_SKILL_FISTPERCENT,
	CONDITIONPARAM_SKILL_CLUBPERCENT,
	CONDITIONPARAM_SKILL_SWORDPERCENT,
	CONDITIONPARAM_SKILL_AXEPERCENT,
	CONDITIONPARAM_SKILL_DISTANCEPERCENT,
	CONDITIONPARAM_SKILL_SHIELDPERCENT,
	CONDITIONPARAM_SKILL_FISHINGPERCENT,
	CONDITIONPARAM_PERIODICDAMAGE,
	CONDITIONPARAM_BUFF,
	CONDITIONPARAM_SUBID,
	CONDITIONPARAM_FIELD,
	CONDITIONPARAM_COMBAT_PHYSICALDAMAGE,
	CONDITIONPARAM_COMBAT_ENERGYDAMAGE,
	CONDITIONPARAM_COMBAT_EARTHDAMAGE,
	CONDITIONPARAM_COMBAT_FIREDAMAGE,
	CONDITIONPARAM_COMBAT_UNDEFINEDDAMAGE,
	CONDITIONPARAM_COMBAT_LIFEDRAIN,
	CONDITIONPARAM_COMBAT_MANADRAIN,
	CONDITIONPARAM_COMBAT_HEALING,
	CONDITIONPARAM_COMBAT_DROWNDAMAGE,
	CONDITIONPARAM_COMBAT_ICEDAMAGE,
	CONDITIONPARAM_COMBAT_HOLYDAMAGE,
	CONDITIONPARAM_COMBAT_DEATHDAMAGE
};

enum Exhaust_t
{
	EXHAUST_SPELLGROUP_NONE = 1,
	EXHAUST_SPELLGROUP_ATTACK = 2,
	EXHAUST_SPELLGROUP_HEALING = 3,
	EXHAUST_SPELLGROUP_SUPPORT = 4,
	EXHAUST_SPELLGROUP_SPECIAL = 5,
	EXHAUST_MELEE = 6
};

enum ExhaustSubId_t
{
	EXHAUST_DEFAULT = 1,
	EXHAUST_TALKNPC = 2, // No used
	EXHAUST_PLAYERVIP = 3,
	EXHAUST_OUTFIT = 4,
	EXHAUST_PARTY = 5,
	EXHAUST_PLAYERSPEAK = 6,
	EXHAUST_PLAYERLOOK = 7,
	EXHAUST_PLAYERTRADE = 8,
	EXHAUST_PLAYEROPENCHANNEL = 9
};

enum BlockType_t
{
	BLOCK_NONE = 0,
	BLOCK_DEFENSE,
	BLOCK_ARMOR,
	BLOCK_IMMUNITY
};

enum Reflect_t
{
	REFLECT_FIRST = 0,
	REFLECT_PERCENT = REFLECT_FIRST,
	REFLECT_CHANCE,
	REFLECT_LAST = REFLECT_CHANCE
};

enum Increment_t
{
	INCREMENT_FIRST = 0,
	HEALING_VALUE = INCREMENT_FIRST,
	HEALING_PERCENT,
	MAGIC_VALUE,
	MAGIC_PERCENT,
	INCREMENT_LAST = MAGIC_PERCENT
};

enum stats_t
{
	STAT_FIRST = 0,
	STAT_MAXHEALTH = STAT_FIRST,
	STAT_MAXMANA,
	#ifdef _MULTIPLATFORM76
	STAT_SOUL,
	#endif
	STAT_LEVEL,
	STAT_MAGICLEVEL,
	STAT_LAST = STAT_MAGICLEVEL
};

enum lossTypes_t
{
	LOSS_FIRST = 0,
	LOSS_EXPERIENCE = LOSS_FIRST,
	LOSS_MANA,
	LOSS_SKILLS,
	LOSS_CONTAINERS,
	LOSS_ITEMS,
	LOSS_LAST = LOSS_ITEMS
};

enum formulaType_t
{
	FORMULA_UNDEFINED = 0,
	FORMULA_LEVELMAGIC,
	FORMULA_SKILL,
	FORMULA_VALUE
};

enum ConditionId_t
{
	CONDITIONID_DEFAULT = -1,
	CONDITIONID_COMBAT = 0,
	CONDITIONID_HEAD,
	CONDITIONID_NECKLACE,
	CONDITIONID_BACKPACK,
	CONDITIONID_ARMOR,
	CONDITIONID_RIGHT,
	CONDITIONID_LEFT,
	CONDITIONID_LEGS,
	CONDITIONID_FEET,
	CONDITIONID_RING,
	CONDITIONID_AMMO,
	CONDITIONID_OUTFIT
};

enum PlayerSex_t
{
	PLAYERSEX_FEMALE = 0,
	PLAYERSEX_MALE,
	PLAYERSEX_FEMALE_VIP,
	PLAYERSEX_MALE_VIP
	// DO NOT ADD HERE! Every higher sex is only for your
	// own use- each female should be even and male odd.
};

enum WarType_t
{
	WAR_FIRST = 0,
	WAR_GUILD = WAR_FIRST,
	WAR_ENEMY,
	WAR_LAST = WAR_ENEMY
};

struct War_t
{
	War_t()
	{
		war = 0;
		type = WAR_FIRST;

		memset(ids, 0, sizeof(ids));
		memset(frags, 0, sizeof(frags));

		limit = 0;
		payment = 0;
	}

	uint32_t war;
	WarType_t type;

	uint32_t ids[WAR_LAST + 1];
	std::string names[WAR_LAST + 1];
	uint16_t frags[WAR_LAST + 1];

	uint16_t limit;
	uint64_t payment;
};

struct Outfit_t
{
	Outfit_t()
	{
		lookType = lookTypeEx = 0;
		lookHead = lookBody = lookLegs = lookFeet = 0;
	}
	Outfit_t(uint16_t _lookType)
	{
		lookType = _lookType;
		lookTypeEx = 0;
		lookHead = lookBody = lookLegs = lookFeet = 0;
	}

	uint16_t lookType, lookTypeEx;
	uint8_t lookHead, lookBody, lookLegs, lookFeet;

	bool operator==(const Outfit_t& o) const
	{
		return (o.lookType == lookType && o.lookTypeEx == lookTypeEx
			&& o.lookHead == lookHead && o.lookBody == lookBody
			&& o.lookLegs == lookLegs && o.lookFeet == lookFeet);
	}

	bool operator!=(const Outfit_t& o) const
	{
		return !(*this == o);
	}
};

struct LightInfo
{
	uint32_t level, color;

	LightInfo() {level = color = 0;}
	LightInfo(uint32_t _level, uint32_t _color):
		level(_level), color(_color) {}
};
#endif

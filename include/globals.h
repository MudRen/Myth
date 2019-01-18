//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

//#pragma save_binary

#ifndef __SENSIBLE_MODIFIERS__
#define nosave static
#define protected private
#endif

#undef __SENSIBLE_MODIFIERS__
#undef _NO_ANSI___

#define JOB_OB(x)		("/d/job/"+x+"/job")
#define CITY_OB(city,room)   ("/d/"+city+"/"+room)
// Directories

#define BACKUP_DIR      "/u/backup/"
#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"
#define RING_DIR        "/u/mudring/"
// mudring ...
#define WIZARD_ROOM        "/adm/npc/wizroom"

// Daemons
#define TOPTEN_D	        "/adm/daemons/toptend"
#define ALIAS_D			"/adm/daemons/aliasd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define CONVERT_D       "/adm/daemons/gb_b5d"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define CLUB_D			"/adm/daemons/clubd"
#define PARTY_D          "/adm/daemons/partyd"
// mon@xiyouji 10/19/98
#define MISC_D		        "/adm/daemons/miscd"
// added by snowcat 6/20/1997
#define BJTIME_D                "/cmds/usr/bjtime"
#define MONITOR_D		"/adm/daemons/monitord"
#define NATURE_D		"/adm/daemons/natured"
#define OBSTACLE_D              "/adm/daemons/obstacled"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define SPELL_D		        "/adm/daemons/spelld"
#define LEAGUE_D        "/adm/daemons/leagued"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
#define WSAVE_D                "/adm/daemons/w_saved"
#define BAN_D		 "/adm/daemons/band.c"
#define MONEY_D		 "/adm/daemons/moneyd.c"
#define XYJTIME_D          "/adm/daemons/xyjtimed.c" 
#define TOPTEN_D	        "/adm/daemons/toptend"
#define TASK_D                  "/adm/daemons/questd"
#define CRON_D                  "/adm/daemons/cron"
#define DISASTER_D              "/adm/daemons/disasterd"
#define COLOR_D                  "/adm/daemons/colord"
#define NEWS_D                  "/adm/daemons/newsd"
#define NAME_D                  "/adm/daemons/named"
#define NPC_D                   "/adm/daemons/npcd"
#define QUIZ_D                   "/adm/daemons/quizd"
#define CITY_D                   "/adm/daemons/cityd"
#define PFM_D                   "/adm/daemons/pfmd"
#define STATU_D                 "/adm/daemons/statud"
#define PKMANAGER_D                 "/adm/daemons/pk_manager"
//����ȼ��Զ�����ϵͳby koker@2004/06/16
#define UPEXP_D		        "/adm/daemons/upexpd"

#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)              ("/daemon/skill/" + x)
// 75  #define SKILL_D(x)          (call_other("/adm/daemons/skilld", "find_skill", x))
#define CONDITION_D(x)	("/daemon/condition/" + x)
#define BINGQI_D(x)              ("/d/obj/weapon/" + x)

// Clonable/Non-inheritable Standard Objects

#define COIN_OB			"/obj/money/coin"
#define CORPSE_OB               "/obj/misc/corpse"
#define GOLD_OB                 "/obj/money/gold"
#define LOGIN_OB                "/obj/user/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB              "/obj/misc/mailbox"
#define SILVER_OB		"/obj/money/silver"
#define SIMUL_EFUN_OB	"/adm/obj/simul_efun"
#define USER_OB                 "/obj/user/user"
#define VOID_OB                 "/obj/misc/void"
#define EMPTY_OB                 "/obj/misc/empty"

// Inheritable Standard Objects

#define BANK			"/std/room/bank"
#define BULLETIN_BOARD        "/std/misc/bboard"
#define BBS_BOARD               "/std/misc/bbsboard"
#define CHARACTER               "/std/char/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define COMBINED_ITEM	"/std/item/combined"
#define EQUIP                   "/std/misc/equip"
#define FORCE                   "/std/skill/force"
#define HOCKSHOP		"/std/room/hockshop"
#define ITEM                    "/std/item/item"
#define LIQUID                  "/std/misc/liquid"
#define MONEY                   "/std/item/money"
#define NPC			"/std/char/npc"
#define NPC_SAVE		"/std/char/npcsave"
#define POWDER			"/std/medicine/powder"
#define QUEST                   "/std/misc/quest"
#define ROOM                    "/std/room/room"
#define CROOM                   "/std/room/cleanroom"
#define SKILL                   "/std/skill/skill"
#define SSERVER                 "/std/skill/sserver"
#define YUEQI                 "/std/item/yueqi"
#define JOBNPC                "/std/char/jobnpc"
#define PARTY                "/std/char/party"

#define HELL_ROOM             "/std/room/hellroom"
#define MOFENG_ROOM             "/std/room/mofengroom"
// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID	"Backbone"

// Features

#define F_ACTION		"/feature/action.c"
#define F_ALIAS			"/feature/alias.c"
#define F_APPRENTICE	"/feature/apprentice.c"
#define F_ATTACK		"/feature/attack.c"
#define F_ATTRIBUTE		"/feature/attribute.c"
#define F_AUTOLOAD		"/feature/autoload.c"
#define F_CLEAN_UP		"/feature/clean_up.c"
#define F_COMMAND		"/feature/command.c"
#define F_CONDITION		"/feature/condition.c"
#define F_DAMAGE		"/feature/damage.c"
#define F_DBASE			"/feature/dbase.c"
#define F_EDIT			"/feature/edit.c"
#define F_ENCODING		"/feature/encoding.c"
#define F_EQUIP			"/feature/equip.c"
#define F_FINANCE		"/feature/finance.c"
#define F_FOOD			"/feature/food.c"
#define F_LIQUID		"/feature/liquid.c"
#define F_MASTER		"/std/char/master.c"
#define F_MESSAGE		"/feature/message.c"
#define F_MORE			"/feature/more.c"
#define F_MOVE			"/feature/move.c"
#define F_NAME			"/feature/name.c"
#define F_ONEOWNER		"/feature/oneowner.c"
#define F_SAVE			"/feature/save.c"
#define F_SSERVER                  "/feature/sserver.c"
#define F_BACKUP		"/feature/backup.c"
#define F_SKILL			"/feature/skill.c"
#define F_TEAM			"/feature/team.c"
#define F_TREEMAP		"/feature/treemap.c"
#define F_UNIQUE		"/feature/unique.c"
#define F_VENDOR		"/feature/vendor.c"
#define F_VENDOR_SALE		"/feature/vendor_sale.c"
#define F_SHADOW       "/feature/shadow.c"
#define STORY_DIR	        "/clone/gift/"
#define STORY_D	        "/adm/daemons/storyd.c"
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#define PROFILE_COMMANDS
#undef PROFILE_COMMANDS
// add for cmds me
#define F_VI               "/feature/vi.c"
#define CLOSE_D               "/adm/daemons/closed"
#define MUSIC_D               "/adm/daemons/musicd"
#define EXAMINE_D               "/adm/daemons/examined"
#define F_NOCLONE               "/feature/noclone.c"
#define INSTALL_COMBAT_TEST     1
#define NWEAPON_D               "/adm/daemons/nweapond"

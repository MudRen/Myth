//Cracked by Roath
inherit F_CLEAN_UP;
#include <ansi.h>
#include <quest.h>

mapping quests_armor = ([
      10 : ({ "find", HIW"����" NOR,   "baishu",          "", "1" }),
      15 : ({ "find", HIC"����"NOR,    "duanxu"           "", "1" }),
      20 : ({ "find", HIR"�컨"NOR,    "honghua",     "", "1" }),
      30 : ({ "find", HIG"����"NOR,    "lianzi",           "", "1" }),
      40 : ({ "find", RED"��ɽ��"NOR,   "chuanshan jia",      "", "1" }),
      50 : ({ "find", HIY"����"NOR,     "xingren",       "", "1" }),
     100 : ({ "find", HIC"��ĸ"NOR,     "bei mu",              "", "1" }),
     110 : ({ "find", HIB"����"NOR,     "du huo",              "", "1" }),
     200 : ({ "find", YEL"������"NOR,      "chuan huajiao",            "", "1" }),
    4100 : ({ "find", MAG"����"NOR,     "ling xian",       "", "1" }),
    4200 : ({ "find", WHT"����"NOR,     "shengdi",         "", "1" }),
    4300 : ({ "find", HIR"�ܵ�"NOR,     "xiongdan",            "", "1" }),
    4400 : ({ "find", HIW"��Ƭ"NOR,     "bingpian",            "", "1" }),
    4450 : ({ "find", GRN"����"NOR,     "ercha",             "", "1" }),
    4500 : ({ "find", YEL"�ư�"NOR,      "huang bo",       "", "1" }),
    4600 : ({ "find", HIG"��֥"NOR,      "lingzhi",      "", "1" }),
    7000 : ({ "find", CYN"������"NOR,    "shenglong gu",         "", "1" }),
    8000 : ({ "find", RED"Ѫ��"NOR,      "xuejie",         "", "1" }),
    8100 : ({ "find", HIC"����"NOR,      "bo he",        "", "1" }),
    8200 : ({ "find", HIB"����"NOR,      "fang feng",           "", "1" }),
    8300 : ({ "find", YEL"����"NOR,     "huanglian",    "", "1" }),
    8400 : ({ "find", HIY"¹��"NOR,     "lurong",           "", "1" }),
    8500 : ({ "find", YEL"����"NOR,     "she xiang",         "", "1" }),
    9000 : ({ "find", HIW"ѩ��"NOR,     "xuelian",                 "", "1" }),
   11500 : ({ "find", GRN"���Ǿ�"NOR,     "hugu jiu",              "", "1" }),
   22000 : ({ "find", MAG"���ŷ��赤"NOR, "sancai dan",         "", "1" }),
   23000 : ({ "find", "[1;32m��[33m��[35m��[36m��[37m��[m", "zaizao wan",         "", "1" }),
   32500 : ({ "find", HIG"���������"NOR,  "duomei wan",          "", "1" }),
   33000 : ({ "find", HIG"���Ľⶾ��"NOR,  "qingxin wan",        "", "1" }),
   33500 : ({ "find", HIG"�������Ӹ�"NOR,  "sanhua gao",       "", "1" }),
   34000 : ({ "find", HIC"����"NOR,         "qing dai",       "", "1" }),
   34500 : ({ "find", HIM"Ы��"NOR,         "xiefen",      "", "1" }),
   35000 : ({ "find", HIW"����"NOR,      "ru xiang",       "", "1" }),
   35500 : ({ "find", "����",         "west sword",      "", "1" }),
   36000 : ({ "find", HIW"������"NOR,   "baozi",        "", "1" }),
   36500 : ({ "find", "[1;33mСϺ��[m", "xiao xiami",       "", "1" }),
   37000 : ({ "find", "[31mС����[m",  "xiao yumiao",        "", "1" }),
   37500 : ({ "find", "[32m����[m",    "nian yu",       "", "1" }),
   40000 : ({ "find", HIY"��������"NOR, "jia sha",            "", "1" }),
   41000 : ({ "find", HIY"����"NOR,     "jia sha",            "", "1" }),
   41500 : ({ "find", BLK"��֥����Բ"NOR,"blackty",          "", "1" }),
   47000 : ({ "find", "[1;36m����[m",  "jin yu",          "", "1" }),
   48000 : ({ "find", "[36m����[m",    "cao yu",         "", "1" }),
  200000 : ({ "find", "��������",         "pi pa",             "", "1" }),
  210000 : ({ "find", HIC"���µ�"NOR,     "fengyue dao",          "", "1" }),
  220000 : ({ "find", YEL"��ͭ��¯"NOR,   "shou lu",       "", "1" }),
  330000 : ({ "find",  HIW"��ĵ��"NOR,    "mu dan",      "", "1" }),
  550000 : ({ "find", HIY"������"NOR,   "long pao",           "", "1" }),
  700000 : ({ "find", HIY"����"NOR,      "lian qiao",            "", "1" }),
  800000 : ({ "find", HIY "������" NOR, "long pao",           "", "1" }),
 2000000 : ({ "find", HIY"�������"NOR, "tian yi",            "", "1" }),
 2100000 : ({ "find", "������",         "purple cloth",       "", "1" }),
 2200000 : ({ "find", HIY"��������"NOR, "jinlan jiasha",      "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_armor));
}

mapping query_quest(object who)
{
  mapping quest;
  int i;
  string* info;
  string *strs = ({
    "$N����˵������������׼������ȥ��",
    "$Nϸ����һ��˵��������������Ҫʲô",
    "$N��ͷ˵����������ȱЩ",
    "$N����˵�����ɷ�ﱾ��Ѱ��",
  });  
  
  i = quest_accurate_index (m_keys, who->query("combat_exp"));
  i = quest_random_index (m_keys, i);
  info=quests_armor[m_keys[i]];
  
  quest=(["quest":"��"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "����ɷ�ȥѰһЩ����\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*50+10]);
  quest+=(["reward_msg":"$NЦ�����������������ˡ�\n"]);
  return quest;
}

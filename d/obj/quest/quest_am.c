//Cracked by Roath
inherit F_CLEAN_UP;
#include <ansi.h>
#include <quest.h>

mapping quests_armor = ([
      10 : ({ "find", "Ƥ����",         "pi beixin",          "", "1" }),
      15 : ({ "find", "��ȭ����",       "quan jing"           "", "1" }),
      20 : ({ "find", "ţƤ��",         "leather shield",     "", "1" }),
      30 : ({ "find", "�ټ�",           "teng jia",           "", "1" }),
      40 : ({ "find", "ţƤѥ",         "leather boots",      "", "1" }),
      50 : ({ "find", "����ѥ",         "flower boots",       "", "1" }),
     100 : ({ "find", "����",           "cloth",              "", "1" }),
     110 : ({ "find", "Ƥ��",           "pipao",              "", "1" }),
     200 : ({ "find", "��ˮ����",       "nichang",            "", "1" }),
    4100 : ({ "find", "��Ƥ���",       "hupi dachang",       "", "1" }),
    4200 : ({ "find", "Ӳľ��",         "ying mukui",         "", "1" }),
    4300 : ({ "find", "����",           "tie kui",            "", "1" }),
    4400 : ({ "find", "��ͷ��",         "tou jin",            "", "1" }),
    4450 : ({ "find", "����",           "fuchen",             "", "1" }),
    4500 : ({ "find", "��ţƤ��",       "houniu pidun",       "", "1" }),
    4600 : ({ "find", "��������",       "zirong pifeng",      "", "1" }),
    7000 : ({ "find", "ϬţƤ��",       "xiniu piyi",         "", "1" }),
    8000 : ({ "find", "���۷�",         "yayi cloth",         "", "1" }),
    8100 : ({ "find", "ϬƤ����",       "xipi beixin",        "", "1" }),
    8200 : ({ "find", "ţƤ��",         "niupi yi",           "", "1" }),
    8300 : ({ "find", "��Ƥ����",       "xiongpi duanpao",    "", "1" }),
    8400 : ({ "find", "��Ƥȹ",         "hupi qun",           "", "1" }),
    8500 : ({ "find", "��Ƥ��",         "langpi qun",         "", "1" }),
    9000 : ({ "find", "ս��",           "zhan pao",           "", "1" }),
   11000 : ({ "find", "����",           "iron armor",         "", "1" }),
   12000 : ({ "find", "ѩɽ����",       "baipao",             "", "1" }),
   13000 : ({ "find", "���Ե���",       "bagua pao",          "", "1" }),
   14000 : ({ "find", "��ͭ��",         "bronze armor",       "", "1" }),
   20000 : ({ "find", "���ս��",       "heaven armor",       "", "1" }),
   21000 : ({ "find", "��Ƥȹ",         "wolf skirt",         "", "1" }),
   22000 : ({ "find", "��Ƥȹ",         "shoupi qun",         "", "1" }),
   23000 : ({ "find", HIG "�Ž�ȹ" NOR, "palm skirt",         "", "1" }),
   32500 : ({ "find", "����Ƥ",         "mengma pi",          "", "1" }),
   33000 : ({ "find", "��ͷѥ",         "tie tou xue",        "", "1" }),
   33500 : ({ "find", "ͭͷѥ",         "tong tou xue",       "", "1" }),
   34000 : ({ "find", "��צ��",         "tie zhua tao",       "", "1" }),
   34500 : ({ "find", "ͭצ��",         "tong zhua tao",      "", "1" }),
   35000 : ({ "find", "������",         "tie shou tao",       "", "1" }),
   35500 : ({ "find", "ͭ����",         "tong shou tao",      "", "1" }),
   36000 : ({ "find", "��ͷ��",         "tie tou kui",        "", "1" }),
   36500 : ({ "find", "ͭͷ��",         "tong tou kui",       "", "1" }),
   37000 : ({ "find", "������",         "tie hu jian",        "", "1" }),
   37500 : ({ "find", "ͭ����",         "tong hu jian",       "", "1" }),
   38000 : ({ "find", "������",         "tie hu yao",         "", "1" }),
   38500 : ({ "find", "ͭ����",         "tong hu yao",        "", "1" }),
   39000 : ({ "find", "������",         "tie hu wan",         "", "1" }),
   39500 : ({ "find", "ͭ����",         "tong hu wan",        "", "1" }),
   40000 : ({ "find", HIY"��������"NOR, "jia sha",            "", "1" }),
   41000 : ({ "find", HIY"����"NOR,     "jia sha",            "", "1" }),
   41500 : ({ "find", BLK"��֥����Բ"NOR,"blackty",          "", "1" }),
   42000 : ({ "find", "��ţƤ",         "maoniu pi",          "", "1" }),
   43000 : ({ "find", "ˮţƤ",         "shuiniu pi",         "", "1" }),
   44000 : ({ "find", "Ұ��Ƥ",         "yexiang pi",         "", "1" }),
   45000 : ({ "find", "��¹Ƥ",         "gonglu pi",          "", "1" }),
   46000 : ({ "find", "��Ƥ",           "chai pi",            "", "1" }),
   47000 : ({ "find", "�ڹ��",         "wugui jia",          "", "1" }),
   48000 : ({ "find", "���˼�",         "wangba jia",         "", "1" }),
   49000 : ({ "find", "ǧ�ۼ�",         "qianling jia",       "", "1" }),
   49500 : ({ "find", "��з��",         "juxie ke",           "", "1" }),
   51000 : ({ "find", "����Ƥ",         "huabao pi",          "", "1" }),
   52000 : ({ "find", "�׻�Ƥ",         "baihu pi",           "", "1" }),
   53000 : ({ "find", "�ڻ�Ƥ",         "heihu pi",           "", "1" }),
   54000 : ({ "find", "��ʨƤ",         "jinshi pi",          "", "1" }),
   55000 : ({ "find", "��ëʨƤ",       "juanmao pi",         "", "1" }),
   56000 : ({ "find", "ɽèƤ",         "shanmao pi",         "", "1" }),
   57000 : ({ "find", "������",         "armor",              "", "1" }),
   57001 : ({ "find", "������",         "armor",              "", "1" }),
   57002 : ({ "find", "������",         "armor",              "", "1" }),
   57003 : ({ "find", "������",         "armor",              "", "1" }),
   57004 : ({ "find", "������",         "armor",              "", "1" }),
   57005 : ({ "find", "������",         "armor",              "", "1" }),
   57010 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   57011 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   57012 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   57013 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   57014 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   57015 : ({ "find", "��ͭ��",         "armor",              "", "1" }),
   61000 : ({ "find", "��Ƥ����",       "tiger surcoat",      "", "1" }),
   65000 : ({ "find", "��������",       "wanzi tiekui",      "", "1" }),
   68000 : ({ "find", "��ľ��",         "zhangmu dun",        "", "1" }),
   69000 : ({ "find", "�ľ��",         "nanmu dun",          "", "1" }),
   70000 : ({ "find", "ϬţƤ��",       "xiniupi dun",        "", "1" }),
   71000 : ({ "find", "��Ƥ��",         "xiongpi dun",        "", "1" }),
   72000 : ({ "find", "��Ƥ��",         "xiangpi dun",        "", "1" }),
   73000 : ({ "find", "��Ƥ��",         "hupi dun",           "", "1" }),
   90000 : ({ "find", "̫������",       "cloth",              "", "1" }),
  100000 : ({ "find", "������",         "silver armor",       "", "1" }),
  110000 : ({ "find", "�����ȼ�",     "smoky armor",        "", "1" }),
  120000 : ({ "find", "��ˮ����",       "fancy skirt",        "", "1" }),
  200000 : ({ "find", "������",         "baipao",             "", "1" }),
  210000 : ({ "find", "���Ե���",       "bagua pao",          "", "1" }),
  220000 : ({ "find", "�����Ӽ�",     "golden armor",       "", "1" }),
  300000 : ({ "find", "��ħ��",         "xiangmo pao",        "", "1" }),
  310000 : ({ "find", "����ս��",       "zhanpao",            "", "1" }),
  320000 : ({ "find", "�ƻ�Ƥ",         "huang hupi",         "", "1" }),
  330000 : ({ "find", "��Ƥ����",       "shoupi pifeng",      "", "1" }),
  550000 : ({ "find", HIY"������"NOR,   "long pao",           "", "1" }),
  700000 : ({ "find", "�������",       "mangpao",            "", "1" }),
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

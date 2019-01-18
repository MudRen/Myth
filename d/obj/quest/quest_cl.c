//Cracked by Roath
inherit F_CLEAN_UP;

#include <ansi.h>
#include <quest.h>

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "����",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "����",   "zai min" ,   "����(silver)", "5" }), 
// 12000   : ({ "kill",  "�׹Ǿ�", "baigu jing", "",             "3" });
 
//��һ�����ţ��ȼ������������ӣ�����׹Ǿ�������������

mapping quests_cloth = ([
      10 : ({ "find", "�ֲ���",         "linen",              "", "1" }),
      20 : ({ "find", "Ƥ����",         "pi beixin",          "", "1" }),
      30 : ({ "find", "Ƥ��",           "pipao",              "", "1" }),
      40 : ({ "find", HIG"��ɴ��ȹ"NOR, "skirt",             "", "1" }),
     100 : ({ "find", "����",           "cloth",              "", "1" }),
     200 : ({ "find", "��ˮ����",       "nichang",            "", "1" }),
     300 : ({ "find", "���",           "magua",              "", "1" }),
     500 : ({ "find", "��а�",         "ao",                 "", "1" }),
     600 : ({ "find", "����",           "choupao",            "", "1" }),
     700 : ({ "find", "����",           "changpao",           "", "1" }),
     800 : ({ "find", "�ҷ�ֽ",         "paper seal",         "", "1" }),
    1000 : ({ "find", "����",           "gong pao",           "", "1" }),
    1100 : ({ "find", "��ȹ",           "gong qun",           "", "1" }),
    2000 : ({ "find", "�ۺ����",       "pink cloth",         "", "1" }),
    3000 : ({ "find", "��ɫ÷ǳ��ȹ",   "pink skirt",         "", "1" }),
    4000 : ({ "find", "����",           "chang pao",          "", "1" }),
    4100 : ({ "find", "��̺",           "pi tan",             "", "1" }),
    4200 : ({ "find", "����̺",         "bai pitan",          "", "1" }),
    4300 : ({ "find", "��ɫ��̺",       "caise pitan",        "", "1" }),
    4400 : ({ "find", "��������",       "zirong pifeng",      "", "1" }),
    4500 : ({ "find", "��̳��",         "tanzi",              "", "1" }),
    5100 : ({ "find", "����������",     "chang pao",          "", "1" }),
    5200 : ({ "find", "̫������",       "cloth",              "", "1" }),
    6100 : ({ "find", "ӡ��ȹ",         "skirt",              "", "1" }),
    6200 : ({ "find", "����Ͳȹ",       "skirt",              "", "1" }),
    6300 : ({ "find", "ˮȾ��ȹ",       "skirt",              "", "1" }),
    6400 : ({ "find", "�����س�ȹ",     "skirt",              "", "1" }),
    6500 : ({ "find", "����ȹ",         "skirt",              "", "1" }),
    7100 : ({ "find", "����",           "bai pao",            "", "1" }),
    7200 : ({ "find", "����",           "guan pao",           "", "1" }),
    7300 : ({ "find", "���ȹ",         "hong qun",           "", "1" }),
    7400 : ({ "find", "����",         "hua pao",            "", "1" }),
    7500 : ({ "find", "ˮӡ��ȹ",       "hua qun",            "", "1" }),
    7600 : ({ "find", "ϬţƤ��",       "xiniu piyi",         "", "1" }),
    7700 : ({ "find", "��ë",           "niao mao",           "", "1" }),
    8100 : ({ "find", "���۷�",         "yayi cloth",         "", "1" }),
    8200 : ({ "find", "ϬƤ����",       "xipi beixin",        "", "1" }),
    8300 : ({ "find", "ţƤ��",         "niupi yi",           "", "1" }),
    8400 : ({ "find", "��Ƥ����",       "xiongpi duanpao",    "", "1" }),
    8500 : ({ "find", "��Ƥȹ",         "hupi qun",           "", "1" }),
    8600 : ({ "find", "��Ƥ��",         "langpi qun",         "", "1" }),
    8700 : ({ "find", "��ë",           "zhu mao",            "", "1" }),
    8800 : ({ "find", "������",         "dead mouse",         "", "1" }),
    8900 : ({ "find", "����Ƥ",         "xigua pi",           "", "1" }),  
    9000 : ({ "find", "ս��",           "zhan pao",           "", "1" }),
   10000 : ({ "find", "���Ե���",       "bagua pao",          "", "1" }),
   12000 : ({ "find", "�Ʋ�ͷ",         "po butou",           "", "1" }),
   13000 : ({ "find", "�ù�����ǩ",     "used yaqian",        "", "1" }),
   14000 : ({ "find", "��ʯͷ",         "big stone",          "", "1" }),
   15000 : ({ "find", "�ϱ�",           "duan bi",            "", "1" }),
   20000 : ({ "find", "��Ƥȹ",         "wolf skirt",         "", "1" }),
   21000 : ({ "find", "������",         "jinhua pao",         "", "1" }),
   21500 : ({ "find", "�˵�",           "cai dao",            "", "1" }),
   22000 : ({ "find", "��Ƥȹ",         "shoupi qun",         "", "1" }),
   23000 : ({ "find", HIG "�Ž�ȹ" NOR, "palm skirt",         "", "1" }),
   31000 : ({ "find", "���Ƥ",         "heipi pi",           "", "1" }),
   32000 : ({ "find", "����Ƥ",         "zongxiong pi",       "", "1" }),
   33000 : ({ "find", "�౷Ƥ",         "qingbei pi",         "", "1" }),
   34000 : ({ "find", "����Ƥ",         "mengma pi",          "", "1" }),
   41000 : ({ "find", "��ţƤ",         "maoniu pi",          "", "1" }),
   42000 : ({ "find", "ˮţƤ",         "shuiniu pi",         "", "1" }),
   43000 : ({ "find", "Ұ��Ƥ",         "yexiang pi",         "", "1" }),
   44000 : ({ "find", "��¹Ƥ",         "gonglu pi",          "", "1" }),
   45000 : ({ "find", "��Ƥ",           "chai pi",            "", "1" }),
   47000 : ({ "find", "����",           "iron armor",         "", "1" }),
   51000 : ({ "find", "����Ƥ",         "huabao pi",          "", "1" }),
   52000 : ({ "find", "�׻�Ƥ",         "baihu pi",           "", "1" }),
   53000 : ({ "find", "�ڻ�Ƥ",         "heihu pi",           "", "1" }),
   54000 : ({ "find", "��ʨƤ",         "jinshi pi",          "", "1" }),
   55000 : ({ "find", "��ëʨƤ",       "juanmao pi",         "", "1" }),
   56000 : ({ "find", "ɽèƤ",         "shanmao pi",         "", "1" }),
   60000 : ({ "find", "��Ƥ����",       "tiger surcoat",      "", "1" }),
   70000 : ({ "find", "�������",       "mangpao",            "", "1" }),
   71001 : ({ "find", "���޿�",         "cloth",              "", "1" }),
   71002 : ({ "find", "���ް�",         "cloth",              "", "1" }),
   71003 : ({ "find", "�����",         "cloth",              "", "1" }),
   72043 : ({ "find", "ϸ����ȹ",       "skirt",              "", "1" }),
   72044 : ({ "find", "ϸ�г�ȹ",       "skirt",              "", "1" }),
   72111 : ({ "find", "���޶�ȹ",       "skirt",              "", "1" }),
   72244 : ({ "find", "ϸ�б�ȹ",       "skirt",              "", "1" }),
   80047 : ({ "find", "�ϻ�ϸɴսȹ",   "skirt",              "", "1" }),
   80049 : ({ "find", "�ϻ���ɴսȹ",   "skirt",              "", "1" }),
   90000 : ({ "find", "̫������",       "cloth",              "", "1" }),
  120000 : ({ "find", "��ˮ����",       "fancy skirt",        "", "1" }),
  300000 : ({ "find", "��ħ��",         "xiangmo pao",        "", "1" }),
  310000 : ({ "find", "����ս��",       "zhanpao",            "", "1" }),
  320000 : ({ "find", "�ƻ�Ƥ",         "huang hupi",         "", "1" }),
  350000 : ({ "find", "��Ƥ����",       "shoupi pifeng",      "", "1" }),
  550000 : ({ "find", HIY"������"NOR,   "long pao",           "", "1" }),
  700000 : ({ "find", "�������",       "mangpao",            "", "1" }),
  750000 : ({ "find", "�𲼳���",       "cloth",              "", "1" }),
  800000 : ({ "find", HIY "������" NOR, "long pao",           "", "1" }),
 2000000 : ({ "find", HIY"�������"NOR, "tian yi",            "", "1" }),
 2200000 : ({ "find", HIY"��������"NOR, "jinlan jiasha",      "", "1" }),

]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_cloth));
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
  info=quests_cloth[m_keys[i]];
  
  quest=(["quest":"��"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "����ɷ�ȥѰһЩ����\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*40+10]);
  quest+=(["reward_msg":"$NЦ�����������������ˡ�\n"]);
  return quest;
}

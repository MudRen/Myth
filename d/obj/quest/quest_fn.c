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

mapping quests_furniture = ([
      50 : ({ "find", "�˵�",         "blade",              "", "1" }),
     110 : ({ "find", "��̳��",       "tanzi",              "", "1" }),
     120 : ({ "find", "��ƿ",         "youping",            "", "1" }),
     130 : ({ "find", "����",         "bag",                "", "1" }),
     140 : ({ "find", "����",         "fan he",             "", "1" }),
     210 : ({ "find", "��ɨ��",       "broom",              "", "1" }),
     220 : ({ "find", "ѩ����",       "snowglass",          "", "1" }),
     330 : ({ "find", "���",         "ruler",              "", "1" }),
    1100 : ({ "find", "��̺",         "gua tan",            "", "1" }),
    1200 : ({ "find", "����",         "xi hu",              "", "1" }),
    1300 : ({ "find", "����",         "xi wan",             "", "1" }),
    1400 : ({ "find", "��ľб����",   "yi zi",              "", "1" }),
    1500 : ({ "find", "�ο�ľ��",     "zhuo zi",            "", "1" }),
    2000 : ({ "find", "ԡ��",         "yu jin",             "", "1" }),
    3000 : ({ "find", "ˮ��",         "shui guan",          "", "1" }),
    4100 : ({ "find", "�ͺ�«",       "you hulu",           "", "1" }),
    4200 : ({ "find", "����Ͳ",       "qingzhu tong",       "", "1" }),
    5100 : ({ "find", "��¨",         "zhu lou",            "", "1" }),
    5200 : ({ "find", "ˮ�ƹ�",       "jiu guan",           "", "1" }),
    5300 : ({ "find", "����Ͼƺ�",   "jiu hu",             "", "1" }),
    5400 : ({ "find", "�״ɻ���",     "hua pen",            "", "1" }),
    5500 : ({ "find", "��ʯ��ƿ",     "hua ping",           "", "1" }),
    5600 : ({ "find", "�̻�����",     "zhu lan",            "", "1" }),
    5700 : ({ "find", "ϸ����¨",     "zhu lou",            "", "1" }),
    5800 : ({ "find", "��ҩյ",       "yin yaozhan",        "", "1" }),
    5850 : ({ "find", "�ײ�",         "bai bu",             "", "1" }),
    5900 : ({ "find", "����",         "hua bu",             "", "1" }),

    6000 : ({ "find", "�ɻ���",       "deng long",          "", "1" }),
    6100 : ({ "find", "������",       "deng long",          "", "1" }),
    6800 : ({ "find", "�λõ�",       "deng long",          "", "1" }),
    6850 : ({ "find", "�����",       "deng long",          "", "1" }),
    6900 : ({ "find", "�����",       "deng long",          "", "1" }),
    6950 : ({ "find", "�ɺ׵�",       "deng long",          "", "1" }),

    8038 : ({ "find", "�����޽���",   "table",              "", "1" }),

    9000 : ({ "find", "��Ƥ",         "shou pi",            "", "1" }),

   25000 : ({ "find", "��ƿ",         "jingping",           "", "1" }),
   
   30000 : ({ "find", "������",       "mallet",             "", "1" }),
   35000 : ({ "find", HIC"���ϻ"NOR, "camera",             "", "1" }),
   40000 : ({ "find", "һ���Ӳ�",     "zai cao",            "", "1" }),
   45000 : ({ "find", "��������",     "panzi",              "", "1" }),
 1800000 : ({ "find", "�ƽ�ϻ��",     "xiazi",              "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_furniture));
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
  info=quests_furniture[m_keys[i]];
  
  quest=(["quest":"��"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "����ɷ�ȥѰһЩ����\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*40+10]);
  quest+=(["reward_msg":"$NЦ�����������������ˡ�\n"]);
  return quest;
}


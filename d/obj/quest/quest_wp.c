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

mapping quests_weapon = ([
      50 : ({ "find", "�˵�",         "cai dao",            "", "1" }),
     110 : ({ "find", "����",         "hammer",             "", "1" }),
     120 : ({ "find", "ľ��",         "mu dao",             "", "1" }),
     130 : ({ "find", "ľ��",         "mu gun",             "", "1" }),
     140 : ({ "find", "ľ��",         "mu jian",            "", "1" }),
     150 : ({ "find", "ľǹ",         "mu qiang",           "", "1" }),
     160 : ({ "find", "ľ��",         "mu zhang",           "", "1" }),
     170 : ({ "find", "����֦",       "guishuzhi",          "", "1" }),

     210 : ({ "find", "������",       "bintiegun",          "", "1" }),
     220 : ({ "find", "��ü��",       "qimeigun",           "", "1" }),
     230 : ({ "find", "��ɨ��",       "broom",              "", "1" }),
     240 : ({ "find", "ľ��",         "mu bang",            "", "1" }),
     250 : ({ "find", "ľ��",         "fork",               "", "1" }),

     300 : ({ "find", "���ѩ�轣",   "snowsword",          "", "1" }),
     350 : ({ "find", "�Ź������",   "tuotian fork",       "", "1" }),

     500 : ({ "find", "����",         "lumber axe",         "", "1" }),

     700 : ({ "find", "�����",       "mabang",             "", "1" }),
     800 : ({ "find", "����",         "blade",              "", "1" }),
     900 : ({ "find", "��ҩ��",       "yao chu",            "", "1" }),
    2100 : ({ "find", "����",         "blade",              "", "1" }),
    2200 : ({ "find", "��ǹ",         "chang qiang",        "", "1" }),
    2300 : ({ "find", "����",         "sword",              "", "1" }),

    3100 : ({ "find", "���",         "zhu bian",           "", "1" }),
    3200 : ({ "find", "���",         "zhu pa",             "", "1" }),
    3300 : ({ "find", "��ͭ�",       "copper mace",        "", "1" }),
    5000 : ({ "find", "����",         "ji dao",             "", "1" }),
    5500 : ({ "find", "�䵶",         "jie dao",            "", "1" }),
    7000 : ({ "find", "����ذ��",     "silver dagger",      "", "1" }),
    8000 : ({ "find", "�굶",         "ti dao",             "", "1" }),

   10000 : ({ "find", "ɱ�����",     "shawei bang",        "", "1" }),
   15000 : ({ "find", "��師",       "bigaxe",             "", "1" }),

   11000 : ({ "find", "��β��",       "zhiwei jian",        "", "1" }),
   12000 : ({ "find", "������",       "kusong zhang",       "", "1" }),
   13000 : ({ "find", "����ǹ",       "biluo qiang",        "", "1" }),
   14000 : ({ "find", "���̲�",       "huaici cha",         "", "1" }),
   15000 : ({ "find", "��Ҷ��",       "liuye dao",          "", "1" }),
   16000 : ({ "find", "¹Ƥ��",       "lupi bian",          "", "1" }),

   21000 : ({ "find", "���Ƶ�",       "yanyun blade",       "", "1" }),
   21500 : ({ "find", "����",         "tie zhang",          "", "1" }),
   22000 : ({ "find", "�ֲ�",         "gang cha",           "", "1" }),
   22500 : ({ "find", "¹�ǲ�",       "cha",                "", "1" }),
   23000 : ({ "find", "��ǲ�",       "cha",                "", "1" }),
   23500 : ({ "find", "ţ�ǲ�",       "cha",                "", "1" }),
   24000 : ({ "find", "Ϭ�ǲ�",       "cha",                "", "1" }),
   24500 : ({ "find", "����ذ",       "danren bi",          "", "1" }),
   25000 : ({ "find", "��ʯ��",       "qingshi chui",       "", "1" }),
   25500 : ({ "find", "ӥ�츫",       "yingzui fu",         "", "1" }),
   26000 : ({ "find", "�ٽ���",       "baijie lian",        "", "1" }),

   31000 : ({ "find", "�Ž���",       "bajiao bian",        "", "1" }),
   31500 : ({ "find", "����׮",       "yangshu zhuang",     "", "1" }),
   32000 : ({ "find", "������",       "yangshu guai",       "", "1" }),
   32500 : ({ "find", "������",       "yangshu cha",        "", "1" }),
   33000 : ({ "find", "������",       "liutiao bian",       "", "1" }),
   33500 : ({ "find", "ʯ����",       "shichan dao",        "", "1" }),
   34000 : ({ "find", "¹�ǲ�",       "lujiao cha",         "", "1" }),
   34500 : ({ "find", "�̻��",       "cihuai jian",        "", "1" }),
   35000 : ({ "find", "��ӧǹ",       "hongying qiang",     "", "1" }),
   35500 : ({ "find", "���ý�",       "huazhu jian",        "", "1" }),
   36000 : ({ "find", "��Ƥ��",       "bopi bian",          "", "1" }),
   36500 : ({ "find", "��ɽ��",       "kaishan fu",         "", "1" }),
   37000 : ({ "find", "��ʯ��",       "qingsho chui",       "", "1" }),
   37500 : ({ "find", "��ɽ��",       "zhushan pa",         "", "1" }),
   38000 : ({ "find", "������",       "huntie zhang",       "", "1" }),
   38500 : ({ "find", "�򹷹�",       "daguo gun",          "", "1" }),
   39000 : ({ "find", "ţ����",       "niujiao ren",        "", "1" }),

   41000 : ({ "find", "���",         "golden hammer",      "", "1" }),
   41500 : ({ "find", "���䵶",       "chang wan dao",      "", "1" }),
   42000 : ({ "find", "���䵶",       "duan wan dao",       "", "1" }),
   42500 : ({ "find", "�����䵶",     "yueya wan dao",      "", "1" }),
   43000 : ({ "find", "ţ�ǰ�",       "niugu bang",         "", "1" }),
   43500 : ({ "find", "ţͷ��",       "niutou dao",         "", "1" }),
   44000 : ({ "find", "ţ�ǲ�",       "niujiao cha",        "", "1" }),

   51000 : ({ "find", "��",         "jin dao",            "", "1" }),
   51500 : ({ "find", "«����",       "luhua cao",          "", "1" }),
   52000 : ({ "find", "նͷ��",       "zhantou dao",        "", "1" }),
   52500 : ({ "find", "������",       "tie jingji",         "", "1" }),
   53000 : ({ "find", "����",         "tie lian",           "", "1" }),
   53500 : ({ "find", "����צ",       "tie zhua",           "", "1" }),
   54000 : ({ "find", "����צ",       "tie zhua",           "", "1" }),
   54500 : ({ "find", "����",         "tie qiu",            "", "1" }),
   55000 : ({ "find", "������",       "xiangya jian",       "", "1" }),
   55500 : ({ "find", "��ͷ��",       "hutou dao",          "", "1" }),
   56000 : ({ "find", "�����",       "longxu cha",         "", "1" }),
   56500 : ({ "find", "�����",       "zhu liaoya",         "", "1" }),
   57000 : ({ "find", "��β��",       "fengwei bian",       "", "1" }),
   57500 : ({ "find", "ԧ���",       "yuanyang gun",       "", "1" }),
   58000 : ({ "find", "ԧ���",       "yuanyang gun",       "", "1" }),

   62000 : ({ "find", "����",         "fuchen",             "", "1" }),
   63000 : ({ "find", "�߳ݰ�",       "qichi pa",           "", "1" }),
   64000 : ({ "find", "�䵶",         "jie dao",            "", "1" }),
   65000 : ({ "find", "��ͭ��",       "qingtong cha",       "", "1" }),
   66000 : ({ "find", "����",         "fa chui",            "", "1" }),
   67000 : ({ "find", "���ƽ�",       "ziyun jian",         "", "1" }),
   68000 : ({ "find", "�ջ��",       "shaohuo gun",        "", "1" }),

   71000 : ({ "find", "����",         "silver fork",        "", "1" }),
   72000 : ({ "find", "���ǰ�",       "zhuxing pa",         "", "1" }),
   73000 : ({ "find", "˫ͷì",       "shuangtou mao",      "", "1" }),
   74000 : ({ "find", "��",         "ge jian",            "", "1" }),
   75000 : ({ "find", "���µ�",       "xinyue dao",         "", "1" }),

   81000 : ({ "find", "�ڷ��",       "wufeng jian",        "", "1" }),
   82000 : ({ "find", "����",         "zhu zhang",          "", "1" }),
   91000 : ({ "find", "���ݸֲ�",     "sanchi gangcha",     "", "1" }),
   92000 : ({ "find", HIY"��ͭ����"NOR, "huangtong chanzhang", "", "1" }),
  100000 : ({ "find", "С�𹿰�",     "xiao jingu bang",    "", "1" }),
  110000 : ({ "find", "С�ų���",     "xiao jiuchi pa",     "", "1" }),
  120000 : ({ "find", "̫����",     "taiyi zhu dao",      "", "1" }),
  130000 : ({ "find", "С������",     "xiao xiangyao zhang","", "1" }),
  140000 : ({ "find", "������",       "siming chan",        "", "1" }),
  150000 : ({ "find", "������",       "chufei sword",       "", "1" }),
  160000 : ({ "find", "�˱�ͭ��",     "hammer",             "", "1" }),
  200000 : ({ "find", "������",       "moon fork",          "", "1" }),
  210000 : ({ "find", "������",       "xuanhua fu",         "", "1" }),
  220000 : ({ "find", "���ɰ��",   "jindan sha",         "", "1" }),
  300000 : ({ "find", "�����",       "panlong guai",       "", "1" }),
  310000 : ({ "find", "���ǹ",       "diangang qiang",     "", "1" }),

  400000 : ({ "find", "�廨��",       "xiuhua zhen",        "", "1" }),
  410000 : ({ "find", "�˰�÷����",   "meihua hammer",      "", "1" }),
  420000 : ({ "find", "����˫ǹ",     "jade spear",         "", "1" }),
  430000 : ({ "find", "��潣",       "qingfeng sword",     "", "1" }),
  440000 : ({ "find", "�޳���",       "wuchang bang",       "", "1" }),

  500000 : ({ "find", "�ӻ�֦",       "xinghua zhi",        "", "1" }),
  510000 : ({ "find", "������",       "guteng zhang",       "", "1" }),

  600000 : ({ "find", "�ųݶ���",     "ding pa",            "", "1" }),
  610000 : ({ "find", RED"������"NOR, "kunxian suo",        "", "1" }),

  700000 : ({ "find", "����������",   "langya bang",        "", "1" }),
  710000 : ({ "find", YEL"��β��"NOR, "tiger mace",         "", "1" }),

  800000 : ({ "find", "�Ļ���",       "tanghua jian",       "", "1" }),
  810000 : ({ "find", "ʨ�ȹ�",       "shitui gu",          "", "1" }),
  820000 : ({ "find", "���Ǵ�",       "hugu ci",            "", "1" }),
  830000 : ({ "find", "÷��¹��",     "meihualu jiao",      "", "1" }),
  840000 : ({ "find", "ţβ",         "niu wei",            "", "1" }),
  850000 : ({ "find", "��ɽ��",       "kanshan dao",        "", "1" }),

  900000 : ({ "find", "�����",       "jingang zhuo",       "", "1" }),
  910000 : ({ "find", "����ն",       "dragon blade",       "", "1" }),
  920000 : ({ "find", "���ǲ�",       "dragon fork",        "", "1" }),
  930000 : ({ "find", "�����",       "dragon mace",        "", "1" }),
  940000 : ({ "find", "������",       "dragon rake",        "", "1" }),
  950000 : ({ "find", "����ǹ",       "dragon spear",       "", "1" }),
  970000 : ({ "find", "������",       "dragon stick",       "", "1" }),
  980000 : ({ "find", "��Ȫ��",       "dragon sword",       "", "1" }),
  990000 : ({ "find", "������",       "dragon whip",        "", "1" }), 
 1000000 : ({ "find", "�ḫ",         "yue fu",             "", "1" }),
 1100000 : ({ "find", "��",         "da dao",             "", "1" }),
 1200000 : ({ "find", "���",         "da gun",             "", "1" }),
 1300000 : ({ "find", "�Ͻ���",       "huangjin sheng",     "", "1" }),
 1400000 : ({ "find", "�ɰײ����",   "da bao",             "", "1" }),
 1600000 : ({ "find", "�Ͻ���«",   "hu lu",              "", "1" }),
 1700000 : ({ "find", "��֬��ƿ",   "jing ping",          "", "1" }),
 2200000 : ({ "find", "������",       "puti zhang",         "", "1" }),
 2300000 : ({ "find", HIY"�Ż�����"NOR, "nine-ring staff",  "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_weapon));
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
  info=quests_weapon[m_keys[i]];
  
  quest=(["quest":"��"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "����ɷ�ȥѰһЩ����\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*50+10]);
  quest+=(["reward_msg":"$NЦ�����������������ˡ�\n"]);
  return quest;
}

// by snowcat jan 22 1998

#include <ansi.h>
#include "quest.c"

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "����",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "����",   "zai min" ,   "����(silver)", "5" }), 
// 12000   : ({ "kill",  "�׹Ǿ�", "baigu jing", "",             "3" });
 
//��һ�����ţ��ȼ������������ӣ�����׹Ǿ�������������

mapping quests_kill = ([
      10 : ({ "kill", "��",         "xishuai",            "", "1" }),
      20 : ({ "kill", "������",       "rat",                "", "1" }),
      30 : ({ "kill", "Ұ��",         "dog",                "", "1" }),
      40 : ({ "kill", "С��",         "wolf",               "", "1" }),
      50 : ({ "kill", "����",         "gong ji",            "", "1" }),
      60 : ({ "kill", "ɽ��",         "shan ji",            "", "1" }),
     500 : ({ "kill", "СƦ��",       "xiao pizi",          "", "1" }),
    1000 : ({ "kill", "С��å",       "xiao liumang",       "", "1" }),
    2000 : ({ "kill", "����ͷ",       "lao tou",            "", "1" }),
    2500 : ({ "kill", "����",         "wolf",               "", "1" }),
    3000 : ({ "kill", "����",         "da shou",            "", "1" }),
    4000 : ({ "kill", "����ͷĿ",     "bandit leader",      "", "1" }),
    5000 : ({ "kill", "����",         "ma dao",             "", "1" }),

    5100 : ({ "kill", "����ƭ��",     "jianghu pianzi",     "", "1" }),
    5200 : ({ "kill", "����Ů",       "jinchai nu",         "", "1" }),
    5300 : ({ "kill", "����",         "jian shang",         "", "1" }),
    5400 : ({ "kill", "ӹҽ",         "yong yi",            "", "1" }),

    6200 : ({ "kill", "ˮ�߹�",       "shuishe guai",       "", "1" }),
    6300 : ({ "kill", "����",       "jinjing shou",       "", "1" }),

    7100 : ({ "kill", "����",         "hua ren",            "", "1" }),
    7200 : ({ "kill", "��",           "mi",                 "", "1" }),
    7300 : ({ "kill", "��",           "ma",                 "", "1" }),
    7400 : ({ "kill", "¬",           "lu",                 "", "1" }),
    7500 : ({ "kill", "��",           "ban",                "", "1" }),
    7600 : ({ "kill", "��",           "meng",               "", "1" }),
    7700 : ({ "kill", "��",           "la",                 "", "1" }),
    7800 : ({ "kill", "��",           "qing",               "", "1" }),

    8100 : ({ "kill", "����",       "yan shu",            "", "1" }),
    8200 : ({ "kill", "����Ϻ��",     "xia po",             "", "1" }),
    8300 : ({ "kill", "���Ϻ��",     "xia po",             "", "1" }),
    8400 : ({ "kill", "�Ų�����",     "guboer xi",          "", "1" }),
    8500 : ({ "kill", "��������",     "xiboer gu",          "", "1" }),
    8600 : ({ "kill", "������",       "liushu jing",        "", "1" }),

    9000 : ({ "kill", "¹ͷ��",       "yao guai",           "", "1" }),
    9100 : ({ "kill", "��ͷ��",       "yao guai",           "", "1" }),
    9200 : ({ "kill", "��ͷ��",       "yao guai",           "", "1" }),
    9300 : ({ "kill", "��ͷ��",       "yao guai",           "", "1" }),
    9400 : ({ "kill", "��ͷ��",       "yao guai",           "", "1" }),

   10000 : ({ "kill", "����չ",       "xia pengzhan",       "", "1" }),

   11000 : ({ "kill", "屲�����",     "baboer ben",         "", "1" }),
   12000 : ({ "kill", "�������",     "benboer ba",         "", "1" }),
   13000 : ({ "kill", "������",       "lingxu zi",          "", "1" }),

   20100 : ({ "kill", "ɽ��",         "shan yao",           "", "1" }),
   20200 : ({ "kill", "С��",         "xiao yao",           "", "1" }),
   20300 : ({ "kill", "����",         "yao guai",           "", "1" }),
   20400 : ({ "kill", "�ǹ�",         "yao guai",           "", "1" }),
   20500 : ({ "kill", "���",         "yao guai",           "", "1" }),
   20600 : ({ "kill", "����",         "yao guai",           "", "1" }),
   20700 : ({ "kill", "���",         "yao guai",           "", "1" }),
   20800 : ({ "kill", "¹��",         "yao guai",           "", "1" }),
   20900 : ({ "kill", "����",         "yao guai",           "", "1" }),
   21000 : ({ "kill", "������",       "yao jing",           "", "1" }),
   22000 : ({ "kill", "ϸ���侫",     "yao jing",           "", "1" }),
   23000 : ({ "kill", "���þ�",       "yao jing",           "", "1" }),
   24000 : ({ "kill", "���㾫",       "yao jing",           "", "1" }),
   25020 : ({ "kill", "���뾫",       "yao jing",           "", "1" }),

   30100 : ({ "kill", "���",         "yao guai",           "", "1" }),
   30200 : ({ "kill", "����",         "yao guai",           "", "1" }),
   30300 : ({ "kill", "⵹�",         "yao guai",           "", "1" }),
   30400 : ({ "kill", "����",         "yao guai",           "", "1" }),
   30500 : ({ "kill", "����",         "yao guai",           "", "1" }),
   30600 : ({ "kill", "⯹�",         "yao guai",           "", "1" }),
   30700 : ({ "kill", "�ܹ�",         "yao guai",           "", "1" }),
   30800 : ({ "kill", "ţ��",         "yao guai",           "", "1" }),
   30900 : ({ "kill", "����",         "yao guai",           "", "1" }),
   31000 : ({ "kill", "̡��",         "yao guai",           "", "1" }),
   32000 : ({ "kill", "�ù�",         "yao guai",           "", "1" }),
   33000 : ({ "kill", "����",         "yao guai",           "", "1" }),
   34000 : ({ "kill", "����",         "yao guai",           "", "1" }),
   35000 : ({ "kill", "���",         "yao guai",           "", "1" }),
   36000 : ({ "kill", "����",         "yao guai",           "", "1" }),
   37000 : ({ "kill", "����",         "yao guai",           "", "1" }),

   41000 : ({ "kill", "���꾫",       "yao jing",           "", "1" }),
   42000 : ({ "kill", "Ұ����",       "yao jing",           "", "1" }),
   43000 : ({ "kill", "���꾫",       "yao jing",           "", "1" }),
   44000 : ({ "kill", "��⯾�",       "yao jing",           "", "1" }),
   45000 : ({ "kill", "�ʵ���",       "yao jing",           "", "1" }),

   50100 : ({ "kill", "����",         "yao guai",           "", "1" }),
   50200 : ({ "kill", "��ʦ",         "yao guai",           "", "1" }),
   50300 : ({ "kill", "��ͷ",         "yao guai",           "", "1" }),
   50400 : ({ "kill", "��˧",         "yao guai",           "", "1" }),
   50500 : ({ "kill", "��ͷ��",       "yao guai",           "", "1" }),
   50600 : ({ "kill", "̡���",       "yao guai",           "", "1" }),
   50700 : ({ "kill", "¹ͷ��",       "yao guai",           "", "1" }),
   50800 : ({ "kill", "¹ͷ��",       "yao guai",           "", "1" }),
   50900 : ({ "kill", "���ǹ�",       "yao guai",           "", "1" }),
   51000 : ({ "kill", "��⯹�",       "yao guai",           "", "1" }),
   52000 : ({ "kill", "���ù�",       "yao guai",           "", "1" }),
   53000 : ({ "kill", "���߹�",       "yao guai",           "", "1" }),
   54000 : ({ "kill", "������",       "yao guai",           "", "1" }),
   55000 : ({ "kill", "���߹�",       "yao guai",           "", "1" }),

   56000 : ({ "kill", "ɽè��",       "yao guai",           "", "1" }),
   57000 : ({ "kill", "���ǹ�",       "yao guai",           "", "1" }),
   58000 : ({ "kill", "Ұ����",       "yao guai",           "", "1" }),
   59000 : ({ "kill", "���ܹ�",       "yao guai",           "", "1" }),
   60000 : ({ "kill", "������",       "yao guai",           "", "1" }),
   61000 : ({ "kill", "������",       "yao guai",           "", "1" }),
   62000 : ({ "kill", "��Գ��",       "yao guai",           "", "1" }),

   63000 : ({ "kill", "����Ź�",     "diaozuan guguai",    "", "1" }),
   64000 : ({ "kill", "�Źֵ���",     "guguai diaozuan",    "", "1" }),
   65000 : ({ "kill", "«��",         "lu niang",           "", "1" }),
   66000 : ({ "kill", "ʯͷ��",       "shitou jing",        "", "1" }),
   67000 : ({ "kill", "����",         "dragon",             "", "1" }),
   68000 : ({ "kill", "������",       "hudian yao",         "", "1" }),
   69000 : ({ "kill", "������",       "kanmen yao",         "", "1" }),

   70000 : ({ "kill", "�߾�",         "yao jing",           "", "1" }),
   71000 : ({ "kill", "���㾫",       "yao jing",           "", "1" }),
   72000 : ({ "kill", "���㾫",       "yao jing",           "", "1" }),
   73000 : ({ "kill", "���㾫",       "yao jing",           "", "1" }),
   74000 : ({ "kill", "ˮ�ݾ�",       "yao jing",           "", "1" }),
   75000 : ({ "kill", "���Ǿ�",       "yao jing",           "", "1" }),
   76000 : ({ "kill", "ˮ�پ�",       "yao jing",           "", "1" }),
   77000 : ({ "kill", "������",       "yao jing",           "", "1" }),
   78000 : ({ "kill", "�",         "yao jing",           "", "1" }),
   79000 : ({ "kill", "����",         "yao jing",           "", "1" }),

   81000 : ({ "kill", "��Ƥ��",       "shark",              "", "1" }),
   82000 : ({ "kill", "�̱���",       "shark",              "", "1" }),
   83000 : ({ "kill", "˫ͷ��",       "shark",              "", "1" }),
   84000 : ({ "kill", "������",       "shark",              "", "1" }),
   85000 : ({ "kill", "������",       "cloud fog",          "", "1" }),
   86000 : ({ "kill", "������",       "fog cloud",          "", "1" }),
   87000 : ({ "kill", "������ʹ",     "guard",              "", "1" }),

   91000 : ({ "kill", "�ϻ���",       "laohu jing",         "", "1" }),
   92000 : ({ "kill", "�첨��Ц",     "tianboer xiao",      "", "1" }),
   93000 : ({ "kill", "Ц������",     "xiaoboer tian",      "", "1" }),
   94000 : ({ "kill", "��ʥ����",     "wansheng gongzhu",   "", "1" }),
   95000 : ({ "kill", "����",         "mei hou",            "", "1" }),

   96000 : ({ "kill", "����",       "mahuang guai",       "", "1" }),
   97000 : ({ "kill", "����",       "bianfu jing",        "", "1" }),

  101000 : ({ "kill", "�Ž���",       "bajiao guai",        "", "1" }),
  103000 : ({ "kill", "���湫��",     "yumian gongzhu",     "", "1" }),
  104000 : ({ "kill", "ţ������",     "niuer",              "", "1" }),

  110000 : ({ "kill", "ǧ���",       "qianmian guai",      "", "1" }),
  120000 : ({ "kill", "Ů��",         "nu zi",              "", "1" }),
  120100 : ({ "kill", "�ϸ���",       "fu ren",             "", "1" }),
  120200 : ({ "kill", "�Ϲ���",       "gong gong",          "", "1" }),
  120300 : ({ "kill", "Ы�Ӿ�",       "xiezi jing",         "", "1" }),
  130100 : ({ "kill", "����",         "yao jing",           "", "1" }),
  130200 : ({ "kill", "����",         "yao wang",           "", "1" }),
  140000 : ({ "kill", "ˮ�ξ�",       "shuizhi jing",       "", "1" }),
  150000 : ({ "kill", "������",       "lingli chong",       "", "1" }),
  160000 : ({ "kill", "��ϸ��",       "jingxi gui",         "", "1" }),
  170000 : ({ "kill", "��ɽ��",       "bashan hu",          "", "1" }),
  180000 : ({ "kill", "�к���",       "yihai long",         "", "1" }),

  200000 : ({ "kill", "��ʥ����",     "wansheng longwang",  "", "1" }),
  210000 : ({ "kill", "����",         "yu xiang",           "", "1" }),
  220000 : ({ "kill", "����",         "hua yu",             "", "1" }),
  230000 : ({ "kill", "��ü",         "liu mei",            "", "1" }),
  240000 : ({ "kill", "̴��",         "tan kou",            "", "1" }),
  250000 : ({ "kill", "��ͷ",         "chai tou",           "", "1" }),
  260000 : ({ "kill", "����",         "jin lian",           "", "1" }),
  270000 : ({ "kill", "�ȹ",         "jiang qun",          "", "1" }),
  280000 : ({ "kill", "ɽ��",         "shan ji",            "", "1" }),

  310000 : ({ "kill", "��ͷ����",     "jiutou fuma",        "", "1" }),
  320000 : ({ "kill", "��צ����",     "golden dragon",      "", "1" }),
  330000 : ({ "kill", "����",         "guo zhang",          "", "1" }),
  340000 : ({ "kill", "������",       "lao nainai",         "", "1" }),
  350000 : ({ "kill", "����",       "tian shu",           "", "1" }),

  400000 : ({ "kill", "�����",       "yao guai",           "", "1" }),
  410000 : ({ "kill", "�����",       "yao guai",           "", "1" }),
  420000 : ({ "kill", "������",       "yao guai",           "", "1" }),
  430000 : ({ "kill", "������",       "yao guai",           "", "1" }),
  440000 : ({ "kill", "��⡹�",       "yao guai",           "", "1" }),
  450000 : ({ "kill", "��⬹�",       "yao guai",           "", "1" }),
  460000 : ({ "kill", "ʯ⥹�",       "yao guai",           "", "1" }),
  470000 : ({ "kill", "ľ⮹�",       "yao guai",           "", "1" }),
  480000 : ({ "kill", "ˮ⵹�",       "yao guai",           "", "1" }),

  501000 : ({ "kill", "�ʨ",         "yao guai",           "", "1" }),
  502000 : ({ "kill", "ѩʨ",         "yao guai",           "", "1" }),
  503000 : ({ "kill", "��ʨ",         "yao guai",           "", "1" }),
  504000 : ({ "kill", "�Ʊ�",         "yao guai",           "", "1" }),
  505000 : ({ "kill", "ˮ��",         "yao guai",           "", "1" }),
  506000 : ({ "kill", "����",         "yao guai",           "", "1" }),
  507000 : ({ "kill", "ʯ��",         "yao guai",           "", "1" }),
  508000 : ({ "kill", "�ݱ�",         "yao guai",           "", "1" }),
  509000 : ({ "kill", "ɽ��",         "yao guai",           "", "1" }),
  510000 : ({ "kill", "��ʨ",       "yao guai",           "", "1" }),
  520000 : ({ "kill", "����ʨ",       "yao guai",           "", "1" }),
  530000 : ({ "kill", "����ʨ",       "yao guai",           "", "1" }),
  540000 : ({ "kill", "��ë��",       "yao guai",           "", "1" }),
  550000 : ({ "kill", "���滢",       "yao guai",           "", "1" }),
  560000 : ({ "kill", "���߻�",       "yao guai",           "", "1" }),
  570000 : ({ "kill", "������",       "yao guai",           "", "1" }),
  580000 : ({ "kill", "�˽Ż�",       "yao guai",           "", "1" }),
  590000 : ({ "kill", "˫β��",       "yao guai",           "", "1" }),

  610000 : ({ "kill", "���۹�",       "huangpao guai",      "", "1" }),
  620000 : ({ "kill", "���۹�",       "lanpao guai",        "", "1" }),
  630000 : ({ "kill", "���۹�",       "lupao guai",         "", "1" }),
  640000 : ({ "kill", "���۹�",       "qingpao guai",       "", "1" }),
  650000 : ({ "kill", "���۹�",       "zipao guai",         "", "1" }),

  700000 : ({ "kill", "��������",     "beili daxian",       "", "1" }),
  710000 : ({ "kill", "��������",     "chaili daxian",      "", "1" }),
  720000 : ({ "kill", "��������",     "huli daxian",        "", "1" }),
  730000 : ({ "kill", "��������",     "langli daxian",      "", "1" }),
  740000 : ({ "kill", "¹������",     "luli daxian",        "", "1" }),
  750000 : ({ "kill", "��������",     "mali daxian",        "", "1" }),
  760000 : ({ "kill", "��������",     "yangli daxian",      "", "1" }),
  770000 : ({ "kill", "����",       "yu shu",             "", "1" }),

  800000 : ({ "kill", "����ţ��",     "shoumen niujing",    "", "1" }),
  810000 : ({ "kill", "����ţ��",     "yao jing",           "", "1" }),
  820000 : ({ "kill", "��βţ��",     "yao jing",           "", "1" }),
  830000 : ({ "kill", "Ұţ��",       "yao jing",           "", "1" }),
  840000 : ({ "kill", "��ţ��",       "yao jing",           "", "1" }),
  850000 : ({ "kill", "ɽţ��",       "yao jing",           "", "1" }),
  860000 : ({ "kill", "ˮţ��",       "yao jing",           "", "1" }),
  870000 : ({ "kill", "��ţ��",       "yao jing",           "", "1" }),
  880000 : ({ "kill", "ţ��",         "yao jing",           "", "1" }),
  890000 : ({ "kill", "�����ߴ���",   "huaqi dawang",       "", "1" }),

  900000 : ({ "kill", "�ٺ�����",     "pihan dawang",       "", "1" }),
  910000 : ({ "kill", "�������",     "pishu dawang",       "", "1" }),
  920000 : ({ "kill", "�ٳ�����",     "pichen dawang",      "", "1" }),
  930000 : ({ "kill", "���۹�",       "jinling guai",       "", "1" }),

 1000000 : ({ "kill", "��Ǵ���",     "jinjiao dawang",     "", "1" }),
 1100000 : ({ "kill", "���Ǵ���",     "yinjiao dawang",     "", "1" }),
 1200000 : ({ "kill", "���������",   "dujiaosi dawang",    "", "1" }),
 1300000 : ({ "kill", "��ü�Ϸ�",     "huangmei laofo",     "", "1" }),
 1400000 : ({ "kill", "ţħ��",       "niumo wang",         "", "1" }),
 1500000 : ({ "kill", "��ͷʨ",       "jiutou shi",         "", "1" }),
]);


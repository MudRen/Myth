// by snowcat jan 22 1998

#include <ansi.h>
#include <quest.c>

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "����",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "����",   "zai min" ,   "����(silver)", "5" }), 
// 12000   : ({ "kill",  "�׹Ǿ�", "baigu jing", "",             "3" });
 
//��һ�����ţ��ȼ������������ӣ�����׹Ǿ�������������

mapping quests_give = ([
       5 : ({ "give", "Ů��",         "girl",        "",                     "1" }),
      10 : ({ "give", "�к�",         "boy",         "",                     "1" }),
      15 : ({ "give", "СŮ��",       "kid",         "",                     "1" }),
      20 : ({ "give", "С�к�",       "kid",         "",                     "1" }),
      25 : ({ "give", "����",         "kuli",        "",                     "1" }),
      30 : ({ "give", "�����",       "suan xiucai", "",                     "1" }),
      40 : ({ "give", "�ο�",         "youke",       "",                     "1" }),
      45 : ({ "give", "·��",         "luren",       "",                     "1" }),
      50 : ({ "give", "��������",     "yi ren",      "����(silver)",         "1" }),
      55 : ({ "give", "���Ů",       "girl",        "����(silver)",         "1" }),
      60 : ({ "give", "������",       "aqi po",      "",                     "1" }),
      65 : ({ "give", "ũ��",         "farmer",      "",                     "1" }),
      70 : ({ "give", "�Է�",         "qiao fu",     "",                     "1" }),
     100 : ({ "give", "��ף",         "miao zhu",    "�ƽ�(gold)",           "1" }),
     110 : ({ "give", "����",         "woman",       "�ƽ�(gold)",           "1" }),
     121 : ({ "give", "�����",       "xiucai",      "�����־���(book)",     "1" }),
     122 : ({ "give", "Ǯ���",       "xiucai",      "�����־���(book)",     "1" }),
     123 : ({ "give", "�����",       "xiucai",      "�����־���(book)",     "1" }),
     124 : ({ "give", "�����",       "xiucai",      "�����־���(book)",     "1" }),
     125 : ({ "give", "�����",       "xiucai",      "�����־���(book)",     "1" }),
     126 : ({ "give", "�����",       "xiucai",      "�����־���(book)",     "1" }),
     127 : ({ "give", "֣���",       "xiucai",      "�����־���(book)",     "1" }),
     128 : ({ "give", "�����",       "xiucai",      "�����־���(book)",     "1" }),
     130 : ({ "give", "�η�",         "jiaofu",      "����(silver)",         "1" }),
     135 : ({ "give", "�η�ͷ",       "jiaofu tou",  "����(silver)",         "1" }),
     140 : ({ "give", "������",       "suona shou",  "����(silver)",         "1" }),

    1000 : ({ "give", "ѧͯ",         "xue tong",    "�����־���(book)",     "1" }),
    2000 : ({ "give", "Сͯ",         "kid",         "�����־���(book)",     "1" }),
    3000 : ({ "give", "�Կ�",         "chi ke",      "ը����(jitui)",        "1" }),
    4000 : ({ "give", "ũ��Ů",       "nongjia nu",  "����(silver)",         "1" }),
    5000 : ({ "give", "�����",       "shudai zi",   "�����־���(book)",     "1" }),

    6000 : ({ "give", "�ٸ�",         "woman",       "����(silver)",         "1" }),
    7000 : ({ "give", "���긾Ů",     "woman",       "����(silver)",         "1" }),
    8000 : ({ "give", "�ϸ���",       "old woman",   "����(silver)",         "1" }),
    9000 : ({ "give", "�ϸ�",         "lao fu",      "����(silver)",         "1" }),

   10000 : ({ "give", "���",         "yu fu",       "�ֲ�(gang cha)",       "1" }),
   11000 : ({ "give", "�Է�",         "qiao fu",     "��師(bigaxe)",       "1" }),
   12000 : ({ "give", "��Ů",         "fu nu",       "�ۺ����(pink cloth)", "1" }),
   13000 : ({ "give", "��ͷС����",   "shang ren",   "�ƽ�(gold)",           "1" }),
   14000 : ({ "give", "��ؤ",         "qi gai",      "����(silver)",         "1" }),
   15000 : ({ "give", "����",         "yi ren",      "����(silver)",         "1" }),
   16000 : ({ "give", "����",         "che fu",      "����(silver)",         "1" }),
   17000 : ({ "give", "·��",         "luren",       "����(silver)",         "1" }),
   18000 : ({ "give", "������",       "old woman",   "����(silver)",         "1" }),

   21000 : ({ "give", "ҡ��ˮ��",     "yaoling shuike", "����(silver)",         "1" }),
   22000 : ({ "give", "���˸�Ů",     "maicai funu", "���(kuang)",          "1" }),
   23000 : ({ "give", "����ɮ",       "kuxing sen",  "��(fan)",              "1" }),
   24000 : ({ "give", "�ŷ�",         "jiao fu",     "Բ�ڲ�Ь(shoes)",      "1" }),
   25000 : ({ "give", "������",       "dushu ren",   "�����־���(book)",     "1" }),
   26000 : ({ "give", "ŮӶ",         "nu yong",     "����(silver)",         "1" }),
   27000 : ({ "give", "Ů��",         "nu pu",       "����(silver)",         "1" }),
   28000 : ({ "give", "����",         "nan pu",      "����(silver)",         "1" }),
   29000 : ({ "give", "����",         "ji min",      "����(silver)",         "1" }),

   31000 : ({ "give", "����",         "shou zi",     "����(silver)",         "1" }),
   32000 : ({ "give", "�ϳ�����",     "duanchang furen", "����(silver)",         "1" }),

   41000 : ({ "give", "�����",       "he shang",    "����(silver)",         "1" }),
   42000 : ({ "give", "�ݺ���",       "he shang",    "����(silver)",         "1" }),
   43000 : ({ "give", "С����",       "heshang",     "����(silver)",         "1" }),
   44000 : ({ "give", "�Ϻ���",       "heshang",     "����(silver)",         "1" }),
   45000 : ({ "give", "����ɮ",       "shousi seng", "���䵶(duan wan dao))","1" }),
   46000 : ({ "give", "����",         "shu sheng",   "����(silver)",         "1" }),

   52000 : ({ "give", "���Ʒ�",       "tiaodeng fu", "����(silver)",         "1" }),
   55000 : ({ "give", "���Ϳ�",       "songyou ke",  "�ƽ�(gold)",           "1" }),

   62000 : ({ "give", "����",         "tie jiang",   "���(golden hammer)",  "1" }),
   63000 : ({ "give", "���",         "cha ke",      "�̲�(lu cha)",         "1" }),

   71000 : ({ "give", "����",         "cun min",     "����վ���(jingang)",  "1" }),
   72000 : ({ "give", "���",         "xiang ke",    "����վ���(jingang)",  "1" }),
   73000 : ({ "give", "ũ��",         "nong ren",    "����վ���(jingang)",  "1" }),
   74000 : ({ "give", "ũ��",         "nong fu",     "����վ���(jingang)",  "1" }),
   75000 : ({ "give", "����",         "ju min",      "����(silver)",         "1" }),
   76000 : ({ "give", "����",         "shi min",     "����(silver)",         "1" }),

   80001 : ({ "give", "�Զ���",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80002 : ({ "give", "������",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80003 : ({ "give", "�Զ���",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80004 : ({ "give", "������",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80005 : ({ "give", "�Զ���",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80006 : ({ "give", "������",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80007 : ({ "give", "Ǯ����",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80008 : ({ "give", "Ǯ����",       "lie hu",      "��Ƿ�(jingu fen)",    "1" }),
   80009 : ({ "give", "Ǯ����",       "lie hu",      "������(dieda wan)",    "1" }),
   80010 : ({ "give", "Ǯ����",       "lie hu",      "������(dieda wan)",    "1" }),
   80011 : ({ "give", "Ǯ����",       "lie hu",      "������(dieda wan)",    "1" }),
   80012 : ({ "give", "Ǯ����",       "lie hu",      "������(dieda wan)",    "1" }),
   80013 : ({ "give", "�����",       "lie hu",      "������(dieda wan)",    "1" }),
   80014 : ({ "give", "������",       "lie hu",      "������(dieda wan)",    "1" }),
   80015 : ({ "give", "�����",       "lie hu",      "������(dieda wan)",    "1" }),
   80016 : ({ "give", "������",       "lie hu",      "������(dieda wan)",    "1" }),
   80017 : ({ "give", "�����",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),
   80018 : ({ "give", "������",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),
   80019 : ({ "give", "�����",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),
   80020 : ({ "give", "������",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),
   80021 : ({ "give", "�����",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),
   80022 : ({ "give", "������",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),
   80023 : ({ "give", "�����",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),
   80024 : ({ "give", "������",       "lie hu",      "��ҩ(jinchuang yao)", "1" }),

  100000 : ({ "give", "����",         "ban niang",   "�ƽ�(gold)",           "1" }),
  100010 : ({ "give", "����",         "ban niang",   "��ʯ��ָ(zuan jie)",   "1" }),
  100020 : ({ "give", "С��",         "ban niang",   "���ָ(jin jie)",      "1" }),
  100020 : ({ "give", "����",         "ban niang",   "��������(yu pei)",     "1" }),

  110000 : ({ "give", "����",         "pu lao",      "ˮ������(yao pai)",    "1" }),
  120000 : ({ "give", "����",         "bi an",       "ˮ������(yao pai)",    "1" }),
  130000 : ({ "give", "����",         "ya zi",       "ˮ������(yao pai)",    "1" }),
  140000 : ({ "give", "����",         "ba xia",      "ˮ������(yao pai)",    "1" }),
  150000 : ({ "give", "���",         "chi wen",     "ˮ������(yao pai)",    "1" }),
  160000 : ({ "give", "����",         "tao tie",     "ˮ������(yao pai)",    "1" }),
  170000 : ({ "give", "���",         "gong fu",     "ˮ������(yao pai)",    "1" }),
  180000 : ({ "give", "���",         "jin ni",      "ˮ������(yao pai)",    "1" }),
  190000 : ({ "give", "��ͼ",         "shu tu",      "ˮ������(yao pai)",    "1" }),

  200000 : ({ "give", "�ܹ���","cao guojiu",  "��̫���澭��(taiyi zhenjing)","1" }),
  210000 : ({ "give", "������","han xiangzi", "��̫���澭��(taiyi zhenjing)","1" }),
  220000 : ({ "give", "������","han zhongli", "��̫���澭��(taiyi zhenjing)","1" }),
  230000 : ({ "give", "���ɹ�","he xiangu",   "��̫���澭��(taiyi zhenjing)","1" }),
  240000 : ({ "give", "���ɺ�","lan caihe",   "��̫���澭��(taiyi zhenjing)","1" }),
  250000 : ({ "give", "������","tieguai li",  "��̫���澭��(taiyi zhenjing)","1" }),
  260000 : ({ "give", "�Ź���","zhang guolao","��̫���澭��(taiyi zhenjing)","1" }),
  270000 : ({ "give", "������","lu dongbin",  "��̫���澭��(taiyi zhenjing)","1" }),

]);



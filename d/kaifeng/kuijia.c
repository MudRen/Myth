//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���׳�");
  set ("long", @LONG

���ฮ�Ŀ��׳���ѻ��˲��ٸ��ָ����Ŀ��׷��ߣ��������Ǵ��Ĵ�
�ռ���������Щ���׷����ڷ�����ѡ֮�󣬻����������ǽ���������
ת��������󳼴������׳��ı����ǳ��ڡ�

LONG);

  set("exits", ([
        "north" : __DIR__"zhong",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong" :  1,
       "/d/quest/kaifeng/xpo" :  1,
      ]));

  set("no_fight",1);
  setup();
}



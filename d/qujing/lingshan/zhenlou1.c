//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

��¥�������������챦����¥�У�������һ������Ƥ�ﱳ�Ƴ�
�Σ��Թ������¹����Ϣ�������ǵ���ͨ����۱��������
��¥�Ķ�¥��

LONG);

  set("exits", ([
        "east"   : __DIR__"daxiong",
        "up"   : __DIR__"zhenlou2",
      ]));
  set("objects", ([
        __DIR__"npc/baixiong" : 1,
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}


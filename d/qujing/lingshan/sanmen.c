//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���Ž�����������ǽ��̴��ľ��һ�ԣ��������г�𵤶���
һ�ԡ�������Ҹ����ŵ񻨽�𶦡�����ͨ����µĶ����ţ�
����Ϊ��������Ǵ��۱��

LONG);

  set("exits", ([
        "north"   : __DIR__"ermen",
        "south"   : __DIR__"daxiong",
        "west"   : __DIR__"sidian33",
        "east"   : __DIR__"sidian35",
      ]));
  set("objects", ([
        __DIR__"npc/pusa" : 8,
     ]));

  setup();
}


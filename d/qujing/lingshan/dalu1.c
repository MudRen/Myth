//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

��·���ߣ������������ݣ��Űأ����ɡ���Ȼһ��������أ�
��������ͬ����ʱ�ɼ�·�����˻���ͣ��·���޵������Ǳ�Ŀ
�о���

LONG);

  set("exits", ([
        "east"   : __DIR__"dalu2",
        "south"   : __DIR__"shanjiao",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1+random(3),
      ]));
  set("outdoors", __DIR__);

  setup();
}




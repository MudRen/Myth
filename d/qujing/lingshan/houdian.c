//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

���������ȽȽ���������ǽ�����׻������ϱ���һ����ľ��
����������һ��Ժ���ٴ��ɼ�Ժ�д���͸͵����������ҡ��
������һ���޵��š�

LONG);

  set("exits", ([
        "north"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}


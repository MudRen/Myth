//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������Ǻ��ֵܹĳ���������Եľ��Ƿ��ۣ�����������
������ֻ��͵Щ�������ֺú��ܹ֡�
LONG);

  set("exits", ([
        "east"  : __DIR__"in2",
      ]));
  set("objects",([
        __DIR__"npc/yaojing":2,
        __DIR__"obj/fengmi":1,
        ]));
  setup();
}

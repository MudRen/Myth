//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/huanglu3.c

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

����ط���Ľл�������Ȼ���ׯ�ܽ���ȴ�к����ԵĲ��
�Ĵ�����Щ�Ĳݣ�������û��һ�ߵ�������

LONG);
  set("exits", ([
        "south"  : __DIR__"huanglu2",
          ]));
  set("objects",([
        __DIR__"npc/yao":3,
        ]));
  set("outdoors","cz");
  setup();
}

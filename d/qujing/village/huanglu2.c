//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/huanglu.c

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

����ط���Ľл�������Ȼ���ׯ�ܽ���ȴ�к����ԵĲ��
�Ĵ�����Щ�Ĳݣ�������û��һ�ߵ�������

LONG);
  set("exits", ([
        "north"  : __DIR__"huanglu3",
        "south"  : __DIR__"huanglu1",
          ]));
  set("outdoors","cz");
  setup();
}

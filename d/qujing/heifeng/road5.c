//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

������һƬ�����ǵ����֣����߷ǳ��İ���ֻ�ܿ���ǰ�����ڴ�
��һ�����⣬��ʱ������һ����èͷӥ��˻������

LONG);

  set("exits", ([
        "south"  : __DIR__"dongkou",
        "north"  : __DIR__"road4",
      ]));
  set("outdoors","hf");
  setup();

}

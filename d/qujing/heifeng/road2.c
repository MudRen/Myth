//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

·�Ե�ɽ����һȺ�׺�������ˮ��·�ԵĿյ��ϣ�����Գ����������
���������������һ��СϪͨ��Զ����ɽ����

LONG);

  set("exits", ([
        "southwest"  : __DIR__"road3",
        "north"      : __DIR__"road1",
      ]));
  set("outdoors","hf");
  setup();

}

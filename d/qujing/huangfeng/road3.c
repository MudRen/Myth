//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

�����ǰ����һȺ��ȸ�������ŵ��ϵ����ȣ�������û��ע�⵽
��ĵ����������ߵĺܽ�ʱ�����ǲ�һ���ɢ��
LONG);

  set("exits", ([
        "west"  : __DIR__"road4",
        "east"  : __DIR__"road2",
      ]));
  set("outdoors","hfd");
  setup();
}

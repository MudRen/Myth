//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

�𽥣����ɽׯ��������󣬴�ʱ����վ��һ�ò����ľ�£��Ա�
��һλ�����ڳ���������ʱ�Ŀ����㡣
LONG);

  set("exits", ([
        "west"  : __DIR__"shanlu1",
        "east"  : __DIR__"road3",
      ]));
  set("outdoors","hfd");
  set("objects", ([
	__DIR__"npc/old":1,
   ]));
  setup();
}

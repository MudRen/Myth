//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/on.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

�����⣬���������Сɽ���������˺ܶ࣬ɽ¹��Ұ⯣����д���
ʱ���������߷ɱ���������Ȼ����Щ���˺��µĶ������糤�ߣ�
����һ��Ķ���Ҳ���㻢������
LONG);

  set("exits", ([
        "east" : __DIR__"shanlu2",
        "west" : __DIR__"on2",
      ]));
  set("objects", ([
        __DIR__"npc/lu" : 1,
        ]));
  set("outdoors","sc");
  setup();
}

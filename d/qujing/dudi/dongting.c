// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ���տ��Ĵ��������ӵ��м�ȼ��һ�����𣬼���С������Χ
�������ڵس��⡣�������������й���������������һС��
ͨ����ͤ�ӡ�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"sandong",
        "south"   : __DIR__"huating",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 6,
      ]));

  setup();
}




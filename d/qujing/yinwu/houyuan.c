// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��԰");
  set ("long", @LONG

һ������Ĵ�԰�ӣ���һ�������ɴ�͵����ӣ�������һЩ��
�ߵ͵͵Ŀ�����������һЩ������ĸ���Ҷ����Ƥ������֮��
�����

LONG);

  set("exits", ([
        "south"    : __DIR__"bopiting",
      ]));
  set("objects", ([
        __DIR__"npc/qiaozi" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڷ���һ�ѻ��ƻ��Ž��Σ�������˫ʨͷʯ�����裬���Ż�
�������͵ơ��ú��ˮ���������������ơ�������һ�ȵ�ͨ
���Ƥͤ������һƫ�á�

LONG);

  set("exits", ([
        "east"    : __DIR__"bopiting",
        "west"    : __DIR__"pian",
      ]));
  set("objects", ([
        __DIR__"npc/yaowang" : 1,
      ]));
  setup();
}


// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "ʯ��");
  set ("long", @LONG

ɽϪ��һ��ʯ�����Ƽ������߹���ɭ�룬����������ˮͨ��
Ϫ���Ŷ�����һ���޼ʵ���ľ���֣�����������é���ݣ�����
���������֡�

LONG);

  set("exits", ([
        "east"    : __DIR__"qiaolin3",
        "northwest"    : __DIR__"maowu",
      ]));
  set("objects", ([
        __DIR__"npc/girl1"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}


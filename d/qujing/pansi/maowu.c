// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "é��");
  set ("long", @LONG

һ��������һ���é������ǰ��é��ǰ��һ���š�͸�����ſ�
�Կ���������ׯ԰һ�㣬�����ġ������￴��һ��ľͤ�ӡ�é
���ⶫ������һ��ʯ�š�

LONG);

  set("exits", ([
        "west"    : __DIR__"muxiang",
        "southeast"    : __DIR__"shiqiao",
      ]));
  setup();
}


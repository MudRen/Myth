// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "�ٳ�");
  set ("long", @LONG

�ٳ�λ�ڹ���һ�࣬�����а˽���ͤһ����ͤǰ�ٲ��ɻ�����
�дС������ǹ�ǽ��������������ơ��㳡�Ķ��������볯
����ͨ��

LONG);

  set("exits", ([
        "northeast"    : __DIR__"zhaomen",
      ]));
  set("objects", ([
        __DIR__"npc/wenguan"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}


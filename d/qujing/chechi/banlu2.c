// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/banlu2.c

inherit ROOM;

void create ()
{
  set ("short", "ʯ��·");
  set ("long", @LONG

�ϳǵ�С�����������������һ��ʯ��·��·���������Ű�����
�����滨��ݡ�������֦��Ҷ��������죬ǡ��ʮ�����ˡ�

LONG);

  set("exits", ([
        "southdown"    : __DIR__"qiang7d",
        "northup"      : __DIR__"banlu1",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}


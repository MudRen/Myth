// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽͷ");
  set ("long", @LONG

�����ʯ�߳���һ�����ش������¶��ϱ��ǳ�������ɫɭ�֣�
�����Ǿ��ڣ��±���������Ԩ��������ʯ�������ƺ���·���ԣ�
��������Ƚ�ƽ̹Щ��

LONG);

  set("exits", ([
        "southdown"   : __DIR__"shanlu1",
        "northeast"   : __DIR__"shanding",
      ]));
  set("outdoors", __DIR__);

  setup();
}




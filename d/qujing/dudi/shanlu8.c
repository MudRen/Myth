// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

һ��ɽ·����������ɽ���ϣ�ɽ·���Ӳݴ���Ұ�����ޡ��Ӳ�
����¶����ʯ�ң���������������Զɽ������������Զ������
��Ʈɢ��

LONG);

  set("exits", ([
        "east"   : __DIR__"shanlu9",
        "southwest"   : __DIR__"shanlu10",
      ]));
  set("outdoors", __DIR__);

  setup();
}




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
        "northup"   : __DIR__"dudi4",
        "southeast"   : __DIR__"shanlu3",
      ]));
  set("outdoors", __DIR__);

  setup();
}




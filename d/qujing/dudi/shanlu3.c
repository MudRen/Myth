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
        "northwest"   : __DIR__"shanlu1",
        "westdown"   : __DIR__"shanlu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}




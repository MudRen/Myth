// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shanlu2.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

���ڵ�Сɽ����бб������һ����С·�����������������ϡ���
���ʧ�޵�Ե�ʣ�·�濲��͹����ƽ��·���������Ҳݴ�������
ʯ���ᡣ

LONG);

  set("exits", ([
        "westdown"     : __DIR__"shanlu1",
        "southwest"    : __DIR__"shanlu3",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}


// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shanlu4.c

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
        "northdown"    : __DIR__"shanlu3",
        "southeast"    : __DIR__"simen",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}


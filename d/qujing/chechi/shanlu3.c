// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shanlu3.c

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
        "northeast"    : __DIR__"shanlu2",
        "southup"      : __DIR__"shanlu4",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}


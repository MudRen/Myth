// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/shanlu1.c

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
        "northdown"    : __DIR__"qiang1d",
        "eastup"       : __DIR__"shanlu2",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}


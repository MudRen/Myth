// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yelu6.c

inherit ROOM;

void create ()
{
  set ("short", "Ұ·");
  set ("long", @LONG

Ұ·��·ϸ����᫣������ͣ������ԶԶ���Ǵ�Сɽ�ͣ����ݴ�
��һƬʪʪ������ش����������˼��̻�����ɽ·�Ͼ����ģ�
����Ũ�������ɵ�����С�ļӿ첽����

LONG);

  set("exits", ([
        "northeast"  : __DIR__"yelu7",
        "southwest"  : __DIR__"yelu5",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}


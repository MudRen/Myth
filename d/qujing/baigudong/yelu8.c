// room: /d/qujing/baoxiang/yelu8.c move to here
// by smile 12/10/1998

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
        "east"       : __DIR__"wroad",
        "southwest"  : __DIR__"yelu7",
      ]));
  set("outdoors",__DIR__"");

  setup();
}

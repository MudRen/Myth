// room: /d/qujing/baoxiang/yelu6.c move to baigudong by smile 12/08/1998

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
  set("outdoors",__DIR__"");

  setup();
}


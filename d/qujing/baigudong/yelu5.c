// room: /d/qujing/baoxiang/yelu5.c moved to baigudong by smile 12/10/1998

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
        "northeast"  : __DIR__"yelu6",
        "west"       : __DIR__"yelu4",
        "southeast"  : "/d/qujing/baoxiang/yedu",
      ]));
  set("outdoors",__DIR__"");

  setup();
}


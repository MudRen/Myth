// room: /d/qujing/baoxiang/yelu1.c moved to baigudong by smile 12/09/1998

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
        "southeast"  : __DIR__"yelu2",
        "southwest"  : "/d/qujing/pingding/shan11",
      ]));

  set("outdoors",__DIR__"");
  setup();
}


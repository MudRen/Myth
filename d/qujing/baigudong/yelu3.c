// room: /d/qujing/baoxiang/yelu3.c moved to baigudong by smile 12/10/1998

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
        "northwest"  : __DIR__"yelu2",
        "northup"    : "/d/qujing/baoxiang/shan1",
        "southeast"  : "/d/qujing/baoxiang/shanwan2",
      ]));
  set("outdoors",__DIR__"");

  setup();
}


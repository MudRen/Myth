// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yelu3.c

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
        "northup"    : __DIR__"shan1",
        "southeast"  : __DIR__"shanwan2",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}


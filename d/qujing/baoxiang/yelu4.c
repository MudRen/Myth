// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yelu4.c

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
        "west"       : __DIR__"shanwan1",
        "east"       : __DIR__"yelu5",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}


// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yelu1.c

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

  set("outdoors","/d/qujing/baoxiang");
  setup();
}


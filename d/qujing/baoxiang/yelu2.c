// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yelu2.c

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
        "northwest"  : __DIR__"yelu1",
        "southeast"  : __DIR__"yelu3",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave(object who, string dir)
{
  if ((! interactive(who)) && 
      dir=="northwest" &&
      who->query("id")=="huangjia bing")
    return 0;
  return 1;
}

// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/luochi1.c

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�����ٻ���һƬһƬ������ɹ�ð�ɵ�����ء�����ӲӲ�����
���棬�о����µĵ�������������ݡ�·�����У�����бб�س�
��һ�Դ������Ӳݡ�

LONG);

  set("exits", ([
        "southwest"  : __DIR__"shan1",
        "east"       : __DIR__"luochi2",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

void init ()
{
  add_action ("do_down","down");
}

int do_down(string arg)
{
  object who = this_player();

  if (arg)
    return 0;
   
  tell_object (who,"�����һ�ݣ�\n");
  who->move(__DIR__"shana");
  return 1;
}

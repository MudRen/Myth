// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/luochi2.c

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
        "west"       : __DIR__"luochi1",
        "east"       : __DIR__"chaoxing",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int init ()
{
  add_action ("do_down", "down");
}

int do_down(string arg)
{
  object who = this_player();

  if (arg)
    return 0;

  tell_object (who,"�����һ�ݣ�\n");
  who->move(__DIR__"shanb");
  return 1;
}

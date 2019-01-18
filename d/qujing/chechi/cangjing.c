// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/cangjing.c

inherit ROOM;

void create ()
{
  set ("short", "�ؾ�¥");
  set ("long", @LONG

�ؾ�¥���ɫ���㣬�ű���һ���ͭ¯������ð���������̣�
�ź�ǽͷ����һЩͭ�壬���ڷ���һ����ֵ�̴����񡣶���
�����г���ͨ���

LONG);

  set("exits", ([
        "southeast"    : __DIR__"houdian",
      ]));

  set("objects", ([
         "/d/obj/book/daode"    : 1,
      ]));
  setup();
}

void init ()
{
  add_action ("do_spell","spell");
}

int do_spell (string arg)
{
  object who = this_player();
  string suffix;

  if (! arg)
    return 0;

  if (arg == "shugui")
    suffix = "1";
  else if (arg == "shugui1")
    suffix = "1";
  else if (arg == "shugui2")
    suffix = "2";
  else if (arg == "shugui3")
    suffix = "3";
  else if (arg == "shugui4")
    suffix = "4";
  else if (arg == "shugui5")
    suffix = "5";
  else if (arg == "shugui6")
    suffix = "6";
  else if (arg == "shugui7")
    suffix = "7";
  else if (arg == "shugui8")
    suffix = "8";
  else if (arg == "shugui9")
    suffix = "9";
  else
    return 0;

  tell_object (who,"�������ض�������˼������һ��罫����˹�ȥ��\n");
  who->move(__DIR__"miyuan"+suffix);
  return 1;
}

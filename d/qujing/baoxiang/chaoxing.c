// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/chaoxing.c

inherit ROOM;

void create ()
{
  set ("short", "���ǹ�");
  set ("long", @LONG

��Χ����¡���ɽ�£������°��������������״����С��ʯ
�ʰ���ɫ��������ɫ̦޺��������һЩ���˸ߵĹ�ľ�����дִ�
����״ֲ�

LONG);

  set("exits", ([
        "west"       : __DIR__"luochi2",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  set("objects", ([ 
          __DIR__"npc/shanyao" : 6,
       ]));

  setup();
}

int init ()
{
  add_action ("do_sink", "sink");
  add_action ("do_down", "down");
}

int do_sink(string arg)
{
  object who = this_player();

  if (arg)
    return 0;
  message_vision("$N����һ��\n",who);

  who->move(__DIR__"shanc");
  return 1;
}

int do_down(string arg)
{
  object who = this_player();

  if (arg)
    return 0;

  message_vision("$N����һ��\n",who);
  if (random(2))
    who->move(__DIR__"shana");
  else  
    who->move(__DIR__"shanb");
  return 1;
}

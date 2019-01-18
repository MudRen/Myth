// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dongwai.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

ɽ�±���һ���������𶥷Ź⣬�������ڡ���������㣬����Ұ
������Զ�����������ã������������ɾ��������Ǿ���ȥ������
ǰ��һ����ʯ��(shi ban)��

LONG);

  set("exits", ([
        "northwest"      : __DIR__"songlin",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  set("item_desc",([
      "shi ban" : "\n����ɽ���¶�\n\n"
     ]));

  setup();
}

void init ()
{
  add_action("do_break","break");
}

int do_break (string arg)
{
  object me = this_player();

  if (arg != "shi ban")
    return 0;

  message_vision ("$N���һ����ʹ����������ײ�����ʯ�壡\n\n",me);
  if (me->query("force")<300 ||
      me->query("mana")<300)
  {
    me->unconcious();
    me->set("force",0);
    me->set("mana",0);
  }
  else
  {
    me->add("force",-300);
    me->add("mana",-300);
    message_vision ("ɲ�Ǽ�������ѣ�����ͻȻ��ʧ����Ӱ���٣�\n",me);
    this_object()->recreate();
    message_vision ("\n������\n",me);
    message_vision (this_object()->query("long"),me);
    remove_call_out ("precreate");
    call_out ("precreate",10,this_object());
  }
  return 1;
}

void precreate (object me)
{
  tell_room (me,"��¡һ�����죬һ�ж���ԭ�ˣ�\n\n");
  me->create();
}

void recreate ()
{
  set ("short", "���¶���");
  set ("long", @LONG

ʯ�ĸ����ɣ�ɽ��������������غ񣬷����ߡ�����������ǧ
�ã�ǰ���ٲ�������±ڴ���һ��Ѩ���������ƣ�ʯ������
����������

LONG);

  set("exits", ([
        // "northwest"  : __DIR__"songlin",
        "southeast"  : __DIR__"dong",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}


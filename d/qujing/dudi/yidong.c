// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "һ����");
  set ("long", @LONG

һ����Ȼ�γɵ�ʯͷ�ţ����ϵ�ʯ�������������������ŵ���
�߳������ɹְأ�����������һ�ɹ�Ũ�ҵ���������ʹ���е�
ͷ��Ŀѣ��

LONG);

  set("exits", ([
        "out"   : __DIR__"dongkou",
        //"southwest"   : __DIR__"erdong",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 4,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object yao = present ("yao jing", this_object());

  if (yao && 
      living (yao) &&
      dir == "southwest")
    return notify_fail (yao->query("name")+"����������ס�㲻�š�\n");
  return ::valid_leave(who, dir);
}

void init ()
{
  add_action ("do_break", "break");
  add_action ("do_break", "za");
}

int do_break ()
{
  object who = this_player ();
  object weapon = who->query_temp("weapon");

  if (! weapon)
  {
    message_vision ("$N�ಲ��������ȭͷ��ʯ����һ�ң�\n",who);
    message_vision ("�ҵ�һ��$Nֻ���ù�ͷ�������ˣ�\n",who);
    who->unconcious();
  }
  else
  {
    message_vision ("$N�����Ե���߾�$n������һ�ң�\n",who,weapon);
    if (! this_object()->query("exits/southwest"))
      message_vision ("�ҵ�һ���ſ��ˣ�\n",who);
    else
      message_vision ("�ҵ�һ�������Ѿ��򿪵����ϣ�\n",who);
    if (who->query("force") <= 200 ||
        who->query("mana") <= 200)        
      who->unconcious();
    else
    {
      who->add("force",-200);
      who->add("mana",-200);
    }
    this_object()->set("exits/southwest", __DIR__"erdong");
    remove_call_out ("close");
    call_out ("close",60);
  }
  return 1;
}

void close ()
{
  if (this_object()->query("exits/southwest"))
    tell_room (this_object(),"�ҵ�һ�����ֹ����ˣ�\n");
  this_object()->delete("exits/southwest");
}

// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ���ϳ��Ź������٣�·�Ͽ�֦��Ҷ��أ��±߸߸ߵ͵ͳ���
��ľ��ݣ�������һЩ���СС����ʯ���������������ʱ
�ɼ�������Ѩ��

LONG);

  set("exits", ([
        "westdown"   : __DIR__"shanpo5",
        "southeast"   : __DIR__"shanpo8",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  object who = this_player();
      
  if (who && interactive(who))
    call_out ("appearing", 1, who);
}

void appearing (object who)
{
  object where = this_object();
  object jing;

  if (! who ||
        environment(who) != where)
    return;

  if (! present ("tu jing 5", where))
  {
    jing = new (__DIR__"npc/tu");
    jing->move(where);
    message_vision ("·��ವ�һ��$N���˹�����\n",jing);
  }
}




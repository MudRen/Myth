// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/shan5.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

ɽ�ϻ���������ʯ��㣬�β��س���һЩ���ֹ�ľ��·����
ʯ��Χ�Ƶ�������ɽ���У��ػ����ۡ��Ĵ��紵�ݶ����չȻ�����
���˻�Ȼ��֪������

LONG);

  set("exits", ([
        "northwest"  : __DIR__"shan3",
        "south"      : __DIR__"songlin",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

void init ()
{
  object who = this_player();

  if (who && interactive(who))
    call_out ("appearing",3+random(3),who);
}

void appearing (object who)
{
  object where = this_object();
  object guai;

  if (! who ||
      environment(who) != where)
    return;

  if (! present ("zipao guai", where))
  {
    guai = new (__DIR__"npc/zipao");
    guai->move(where);    
    guai->appear();    
    guai->disappear();    
  }
  /*
  if (! present ("qingpao guai", where))
  {
    guai = new (__DIR__"npc/qingpao");
    guai->move(where);    
    guai->appear();    
    guai->disappear();    
  }
  */
  call_out ("no_reappearing",20);
}

void no_reappearing ()
{
  remove_call_out ("appearing");
}

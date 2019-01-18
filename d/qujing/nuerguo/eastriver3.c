// rewritten by snowcat.c 4/4/1997
// room: /d/nuerguo/eastriver3.c

inherit ROOM;

void create ()
{
  set ("short", "��ĸ�Ӷ���");
  set ("long", @LONG

�������ܿ��ǳ���Ӷ԰������񴹱̣�΢¶��é�ݼ��ܡ�
�Ӱ���ߵزȵú�̤ʵ�����������в������������߹�����
��ܿ��ǳ��������ͽ����ˮҲ�����߹�ȥ��

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eastriver2",
]));
  set("outdoors", __DIR__"");

  setup();
}

void init()
{
  add_action("do_cross", "cross");
}

void in_river(object me, object room);

void walk_in()
{
  object room;
  object me;

  me = this_player();

  if (!(room = find_object(__DIR__"river")))
    room = load_object(__DIR__"river");
  if (room = find_object(__DIR__"river"))
  {
    message_vision ("$N����ţ�С�ĵ��߽�ˮ���\n",me);
    in_river(me, room);
  }
}

void in_river(object me, object room)
{
  me->move(room);
  tell_object(me,"\n�߽�������ŷ��ֺ����ȷ�ܿ�\n");
  call_out("in_danger", 15, me);
}

void in_danger(object me, object room)
{
  if(!me) return;
  me->move(room);

  if (me->query("combat_exp")<2000)
  {
    me->move(__DIR__"eastriver3");
    message_vision ("ˮͻȻ���ˣ�$Nƴ����������������Ǹ�����˰���\n",me);
    tell_object(me,"\n�����ĵ��в������졣\n");
    return;
  }

  if (random(3)==0 &&
      me->query("obstacle/nuerguo")==0 &&
      me->query("water") < me->max_food_capacity())
  {
    message_vision ("$N����һ����ˤ�����Ǻ�������ӵĺ�ˮ��\n",me);
    me->set("obstacle/nuerguo","stomachache");
    me->set("water", me->max_water_capacity()+50);
    tell_object(me,"\n���ˣ����˺�ˮҪ���еģ�\n");
    call_out("stomach_pain",1,me);
  }
  else if (random(2)==0)
  {
    message_vision ("$Nһ��û���ȣ�ˤ�����Ǻ�˼���ˮ��\n",me);
    me->set("water", me->max_water_capacity()+50);
  }
  call_out("arrive", 5, me);
}

void stomach_pain(object me)
{
  int m,n;

  if(!me) return;

  if (me->query("obstacle/nuerguo")=="stomachache")
  {
    m = me->query("max_kee") * (70+random(15)) / 100;
    n = me->query("kee");
    if (me->query("eff_kee") > m)
      me->set("eff_kee", m);
    if (n > m)
      me->set("kee", m);
    message_vision ("$N���Ŷ��������˼�����\n",me);
    call_out("stomach_pain", 30, me);
  }
}

void arrive(object me)
{
  me->move(__DIR__"westriver");
  message_vision ("$N������������˰���\n",me);
}

int do_cross(string arg)
{
  if( !arg || arg=="" )
    return 0;

  if( arg=="river" )
  {
    walk_in();
    return 1;
  }
  return 0;
}

void reset()
{
    object room;

    ::reset();
}

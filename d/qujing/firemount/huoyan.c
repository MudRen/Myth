// rewritten by snowcat on 4/11/1997
// room: huoyan

inherit ROOM;

void create ()
{
  set ("short", "����ɽ");
  set ("long", @LONG

�𣬻𣬻𣡣���

������Ӱ˰�����ܴ�ݲ�������˵����̫���Ͼ�������¯����
��������¯ש���ڴ˴�������Ϊ����ɽ����һ�߽�ȥ�ȳ��̻ң���
���ᶫ��������

LONG);

  set("exits", ([
        "westdown" : __DIR__"huoyan",
        "eastdown" : __DIR__"huoyan",
        "northup"  : __DIR__"huoyan",
        "southup"  : __DIR__"huoyan",
      ]));
  set("outdoors", "firemount");
  set("burning_mount",1);
  setup();
}

void init()
{
  add_action("do_all", "");
  add_action("do_fly", "fly");
  add_action("do_extinguish", "extinguish");
  add_action("do_extinguish", "fan");
  add_action("do_extinguish", "shan");
}

int do_fly (string arg)
{
  object me = this_player();

  if (! this_object()->query("burning_mount"))
    return 0;

  message_vision("ֻ��$N����һ�ɣ��ֱ�һ���������صش���������\n", me);
  return 1;
}

void burnt (object me)
{
  if (! me)
    return;

  if (environment(me) != this_object())
  {
    me->set_temp("burnt_in_mount",1);
    return;
  }

  if (! this_object()->query("burning_mount"))
    return;

  if (random(8) == 0)
  {
    message_vision("һ������Ϯ������$N����һ�ף�$N���˳�ȥ��\n",me);
    me->move(__DIR__"shanbian");
    message_vision("$Nð��Ũ�̴�ɽ�Ϲ���������\n",me);
    me->unconcious();
    if (!objectp(me)) return;
    me->set_temp("burnt_in_mount",0);
    me->set_temp("fanned_in_mount",0);
    me->set_temp("fan_times_in_mount",0);
    me->set_temp("fainted_in_mount",1);
    return;
  }
  else if (random(2) == 0)
  {
    object ob;
    object *inv = all_inventory(me);
    if (sizeof(inv) == 0)
      return;
    ob = inv[random(sizeof(inv))];
    if (ob->query("id") != "tie shan")
    {
      if (ob->move(this_object()))
      {
        message_vision("ֻ������һ��$N��$n��ʱ��Ϊ�ҽ���\n",me,ob);
        destruct(ob);
      }
    }
  }
  else 
  {
    switch (random(4))
    {
      case 0:
        { message_vision("$N��ͷ��ð��һ�����̣�\n",me); break; }
      case 1:
        { message_vision("$N�����������죡\n",me); break; }
      case 2:
        { message_vision("$N���������𼸸���ˮ�壡\n",me); break; }
      case 3:
        { message_vision("$N����һ�ɽ�ζ��\n",me); break; }
    }
  }
  if(me->query("kee") > 15)
    me->add("kee",-5-random(10));
  if(me->query("sen") > 15)
    me->add("sen",-5-random(10));
  call_out ("burnt",random(5)+15,me);
}

void get_burnt (object me)
{
  if (!me || me->query_temp("burnt_in_mount"))
    return;

  if (! this_object()->query("burning_mount"))
    return;

  call_out ("burnt",1,me);
}

int do_all ()
{
  object me;
  me = this_player();

  call_out ("get_burnt",random(2)+10,me);
  return 0; // return 0 to invoke normal commands
}

void announce_success (object me)
{
  object princess = new (__DIR__"npc/princess");

  princess->announce_success(me);
  destruct(princess);
}

void success_quest (object me)
{
  object where = this_object();
  message_vision("\nɲ�Ǽ����ذ�����¡¡��������֮��һ�ж�ƽ���ˣ�\n", me);
  message_vision("$N����ס��������������һ��������Ѿ��������ˣ�\n", me);
  where->set ("long", @LONG

����Ѿ����������ˣ��Ĵ���ð��һ˿˿�Ĳ��̡�

������ʱ����Ĵ�����Ӱ˰�����ܴ�ݲ�������˵����̫����
��������¯���ŷ�������¯ש���ڴ˴�������Ϊ����ɽ����һ�߽�
ȥ�ȳ��̻ң������ᶫ��������

����һ�ж���ƽ���ˣ������������̾���ѡ�

LONG);

  where->set("exits", ([
               "northwest" : __DIR__"shanwai",
               "eastdown"  : __DIR__"shanbian",
             ]));
  where->set("burning_mount",0);
  call_out ("announce_success",1,me);
  call_out ("create",1800);
}

void test_result (object me)
{
  if (random(5) == 0 &&
      me->query_temp("fainted_in_mount") &&
      me->query_temp("fan_times_in_mount") >= 4)
  {
    success_quest(me);
    return;
  }
  message_vision("\n��������ɽ�ϵĻ�����ȥһ��Ƭ�����������ӻص��űߡ�\n", me);
}

void can_fan (object me)
{
  me->set_temp("fanned_in_mount",0);
}

int do_extinguish (string arg)
{
  object me = this_player();

  if (wizardp(me) && me->query("env/override"))
  {
    success_quest(me);
    return 1;
  }
  if (! present("tie shan",me))
    return 0;

  if (! this_object()->query("burning_mount"))
  {
    message_vision("����ɽ����û�л��ˣ�$N�������Լ����亹��\n", me);
    return 1;
  }

  call_out ("get_burnt",random(2)+10,me);

  message_vision("ֻ��$Nƴ�������������ֻһ�ȡ�\n", me);
  if (me->query_temp("fanned_in_mount"))
  {
    message_vision("��ϧ�������㣬ʲô�漣��û������\n", me);
    return 1;
  }

  me->set_temp("fanned_in_mount",1);
  me->set_temp("fan_times_in_mount",me->query_temp("fan_times_in_mount")+1);
  message_vision("һ�ɿ��ϯ�ض�����ɽ������ؾ�����ɽ��Ұ�Ļ��棡\n", me);
  call_out ("test_result",1,me);
  call_out ("can_fan",random(2)+3,me);
  return 1;
}


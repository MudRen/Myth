//sgzl

inherit NPC;

void create()
{

  set_name("С����", ({"xiao jin yu", "xiao yu", "fish", "yu"}));
  set("long","һ��С���㣬���ں����������ڵ����š�\n");

  set("title", "��·ʹ��");
  set("age", 2);
  set("race", "Ұ��");

  set_skill("dodge", 60);
  set("combat_exp", 10);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  setup();
}

void init()
{
  object me=this_object();

  ::init();
  remove_call_out("yinlu");
  call_out("yinlu", 10, me);
}

void yinlu (object me)
{
  me->command("west");
  call_out("yinlu1", 10, me);
}

void yinlu1 (object me)
{
  me->command("east");
  call_out("yinlu2", 10, me);
}

void yinlu2 (object me)
{
  me->command("north");
  call_out("yinlu3", 10, me);
}

void yinlu3 (object me)
{
  me->command("east");
  call_out("yinlu4", 10, me);
}

void yinlu4 (object me)
{
  me->command("south");
  call_out("yinlu5", 10, me);
}

void yinlu5 (object me)
{
  me->command("west");
  call_out("yinlu6", 10, me);
}

void yinlu6 (object me)
{
  me->command("south");
  message_vision("С����һ��β�Ͳ�֪�ε�����ȥ�ˡ�\n",me);
  me->move("/d/dntg/donghai/mazee");
}



// Room: /d/jjf/front_yard.c

inherit ROOM;

void create ()
{
  set ("short", "���䳡");
  set ("long", @LONG
�����ĳ�����������ϸϸ�Ļ����������ʺ����䡣�����м���
�ظ��ҽ��������䡣�����һλ�ܼҴ��������ڱ����ֹۿ���
����ʱ����ǰȥָ��һ�������ر��Ϲ��ż�����ɳ��(sandbags)��
��֪��ʲô�ô��������м��ưܵ�С�ݣ��Ŵ��������ˣ��뽫����
�������ķ������롣
LONG);

  set("item_desc", ([ /* sizeof() == 3 */
  "window" : "�Ŵ����������ˣ�ǽ�Ϻ�����Щ���ҵĺۼ���\n",
  "door" : "
�Ŵ����������ˣ�ǽ�Ϻ�����Щ���ҵĺۼ���\n",
  "sandbags" : "
�������ص�ɳ�����������Ŵ��(da)����\n",
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gate",
  "south" : __DIR__"front_yard2",
  "down" : "/d/quest/m_weapon/lianfushi",
  "up" : "/d/quest/m_weapon/lianmaceshi",
  "east" : __DIR__"majuan",
  "southwest" : __DIR__"guest_bedroom",
]));

  set("objects", ([
                   __DIR__"npc/qinfu": 1,
		   __DIR__"npc/xiaotong": 2,
                   ]));

  setup();
}

void init()
{
  add_action("do_hammer", "hammer");
  add_action("do_da", "da");
}

int do_da(string arg)
{
  object me=this_player();
  int unarmedskll=(int)(me->query_skill("unarmed", 1)/2);
  int maxlevel, exp=(int)me->query("combat_exp");
 
  if( !arg || !((arg == "sandbags") || (arg == "ɳ��")))
    return notify_fail("��Ҫ��ʲô��\n");
  if( me->query("kee") < (int)(me->query("max_kee")/5))
    return notify_fail("�ٴ���ȥ��������ģ�\n");
  if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
    return notify_fail("�ñ������ɳ���򻵵ģ�\n");
  if (!((string)me->query("family/family_name")=="������"))
    {
      message_vision("$Nһȭ��ɳ����ȥ������ɳ��һ��������\n", me);
    }
  else
    {
      message_vision("$N�þ�������ɳ����ȥ�����ɳ��ֱ�Ρ�\n", me);
      if (exp*10 <= (unarmedskll*unarmedskll*unarmedskll))
	{
	  me->receive_damage("kee", (int)me->query("max_kee")/10);
	  return notify_fail("��ĵ��в����ߣ����ܴӴ�ɳ����ѧ����֪��\n");
	}
      if (unarmedskll*2<((int)me->query("con")+(int)me->query("str"))/2)
	{
	  me->improve_skill("unarmed", random((int)(me->query("con")+me->query("str"))/2));
	  tell_object(me, "�������һЩ����ȭ�ŷ�������š�\n");
	}
      else
	{
	  tell_object(me, "����ɳ���Ϸ��˰��쾢������ʲôҲû��ѧ����\n");
	}
    }
  me->receive_damage("kee", (int)me->query("max_kee")/10);
  return 1;
}

int do_hammer(string arg)
{       
  object me;
  me=this_player();
  if ( !present("hammer", me) || (arg != "door"))
    return notify_fail("�����ȭͷ��ǽ����ȥ����������������ͦ�ۣ�\n");
  else
    message_vision("$N����󴸣���ǽ����ȥ��\n", me);
  if((int)me->query_temp("mark/����") < 1)
    {
    me->set_temp("mark/����", 1);
  }
  me->add_temp("mark/����", 1);
  me->receive_damage("kee", 40);
  if((int)me->query_temp("mark/����") > 5)
    {
    message_vision("$N��ǽ�ҿ���һ��������æ���˽�ȥ��\n", me);
    me->set_temp("mark/����", 1);
    me->set_temp("mark/��������", 1);
    me->move("/d/jjf/mishi");
    return 1;
  }
  return 1;
}


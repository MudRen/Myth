// Room: /d/jjf/front_yard2.c

inherit ROOM;

void create ()
{
  set ("short", "���䳡");
  set ("long", @LONG
�����ĳ�����������ϸϸ�Ļ����������ʺ����䡣�����м���
�ظ��ҽ��������䡣�����ı����ż���ľ׮(logs)�����������ɸ�
��ɳ��(pits)��������һ���᷿���ظ��ļα�����ȥ��Ϣ�����ض�
���и������ܡ�
LONG);

  set("item_desc", ([ /* sizeof() == 3 */
  "pits" :
"ɳ������Щ�ҽ�����ϰ�Ṧ����Ҳ������(tiao)��ȥ���ԡ�\n",
  "logs" :
"����ľ׮���в��ٱ�������ĺۼ�(da)��\n",
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"keting.c",
  "west" : __DIR__"guest_bedroom",
  "north" : __DIR__"front_yard",
  "east" : __DIR__"jjf_bingqi",
]));
  set("objects", ([
		   __DIR__"npc/guard": 1,
//zhang men������ˣ���û�޸�֮ǰ����cut. by seng@2005-1-26
// 30    "/obj/zhangmen/jjf.c": 1,
		   ]));

  set("out_doors", 1);

  setup();
}

void init()
{
  add_action("do_da", "da");
  add_action("do_tiao", "tiao");
}
int do_da(string arg)
{
  object me=this_player(), weapn;
  string skll;
  int weaponskll, exp=(int)me->query("combat_exp");
 
  if( (!arg) || !((arg == "logs") || (arg == "ľ׮")))
    return notify_fail("��Ҫ��ʲô��\n");
  if( (me->query("kee") < me->query("eff_kee")/5) || (me->query("eff_kee") < me->query("max_kee")/5))
    return notify_fail("���۵ø첲��̧�������ˣ���������Ϣһ����ɣ�\n");
  if(! (me->query_temp("weapon")) && ! (me->query_temp("secondary_weapon")) )
    {
      message_vision("$N��ȭ��ľ׮��ȥ�������ȭͷ�����Ѫ���졣\n", me);
      me->receive_wound("kee", me->query("eff_kee")/10);
      return 1;   
 }
  if(!weapn=me->query_temp("weapon"))
    {
      weapn = me->query_temp("secondary_weapon");
    }
  skll = (string)weapn->query("skill_type");
  weaponskll=(int)me->query_skill(skll,1)/2;

  if (!((string)me->query("family/family_name")=="������"))
    {
      message_vision("$N�������б�����ľ׮��Χ������һ�����\n", me);
    }
  else
    {
      message_vision("$N��ľ׮����������һ·������\n", me);
      if (exp*10 <= (weaponskll*weaponskll*weaponskll))
	{
	  me->receive_damage("kee", (int)me->query("max_kee")/10);
	  return notify_fail("��ĵ��в����ߣ����ܴӴ�ľ׮��ѧ����֪��\n");
	}
      if (weaponskll*2<((int)me->query("con")+(int)me->query("str"))/2)
	{
	  me->improve_skill(skll, random((int)(me->query("con")+me->query("str"))/2));
	  tell_object(me, "�������һЩ�������������š�\n");
	}
      else
	{
	  tell_object(me, "��æ���˰��죬�ֶ�ĥ�����ˣ�����ʲô��ûѧ����\n");
	}
    }
  me->receive_damage("kee", (int)me->query("max_kee")/10);
  return 1;
}

int do_tiao(string arg)
{
  object me=this_player();
  int dodgeskll=(int)me->query_skill("dodge", 1)/2;
  int exp=(int)me->query("combat_exp");
 
  if( (!arg) || !((arg == "pits") || (arg == "ɳ��")))
    return notify_fail("��Ҫ����������\n");
  if( me->query("kee") < (int)(me->query("max_kee")/5))
    return notify_fail("������ȥ�Ű嶼Ҫĥ���ˣ�\n");
  if (!((string)me->query("family/family_name")=="������"))
    {
      message_vision("$N��������ɳ�ӣ�������������ˣ�ֻ��������������\n", me);
    }
  else
    {
      message_vision("$N��������ɳ�ӣ��ַ������˻�����\n", me);
      if (exp*10 <= (dodgeskll*dodgeskll*dodgeskll))
	{
	  me->receive_damage("kee", (int)me->query("max_kee")/10);
	  return notify_fail("��ĵ��в����ߣ����ܴ���ɳ����ѧ����֪��\n");
	}
      if (dodgeskll*2<((int)me->query("con")+(int)me->query("str"))/2)
	{
	  me->improve_skill("dodge", random(40-(int)(me->query("str")+me->query("con"))/2));
	  tell_object(me, "�������һЩ�����Ṧ��������š�\n");
	}
      else
	{
	  tell_object(me, "������Ծ�£����˸���ͷ����������ʲôҲû��ѧ����\n");
	}
    }
  me->receive_damage("kee", (int)me->query("max_kee")/10);
  return 1;
}



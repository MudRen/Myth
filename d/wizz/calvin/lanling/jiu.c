//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

��ò�������������,ֻ������ǰ��Ȼһ��,ԭ�����Ѿ�����
�����֮����.�������"������",�����㿴�˿�"ǧ����(qi
anzi teng)�ƺ���û������ ... ...
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "qianzi teng" : "һ��������Ƶ���ɫ���� �����濪��������С��
��ɢ������������,�����(climb tree)�����ܲ�������ȥ��
",
]));
  set("objects", ([ /* sizeof() == 2 */
             "/u/calvin/npc/jiu" : 2,
           "/d/calvin/obj/qianzi" : 1,
]));

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 3 */
//    "north" : "/d/calvin/lanling/kingziminggong",
]));

  setup();
}
void init()
{
  add_action("do_climb", "climb");
  add_action("do_kan", "kan");
}


int valid_leave(object me, string dir)
{
        object wugang;
    if (me->query("gender") == "����" && dir == "north" ) {
        if(objectp(wugang=present("wu gang", environment(me))) && living(wugang) )

            return notify_fail("������ת����գ����һ�Ѵ�師��ס�����\n����...Ժ����ס��ȫ��Ů�ˣ����ܽ�ȥ���ʲô��\n");
    }
    return ::valid_leave(me, dir);
}

int do_climb(string arg)
{
	object wugang;
  object me=this_player();
 
  if( (!arg) || !((arg == "tree") || (arg == "����")))
    return notify_fail("��ʲô��\n");
  if (me->is_busy()) return notify_fail("��������æ���ء�");
  if( me->query("kee") < (int)(me->query("max_kee")/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*20/100);
    return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
}
  if (!((string)me->query("family/family_name")=="ƽ��")
	 && objectp(wugang=present("wu gang", environment(me))) && living(wugang) )
    {
      message_vision("���������������˼䲢��Ϸˣ֮�����������뿪!\n", me);
    }
  else
    {
      if ((int)me->query_skill("dodge", 1)<200 && (int)me->query_skill("moondance", 1) < 100)
        {
	  message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
          me->improve_skill("dodge", 60-me->query("str"));
          tell_object(me, "�������һЩ�����Ṧ��������š�\n");
        }
      else
        {
          message_vision("$N�����һ�ھ���������,һ�����ʧ���޾����㻨֮���ˡ�\n", me);
           me->move("/d/calvin/lanling/jinghuatai.c");
        }
    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}

int do_kan(string arg)
{
  object me=this_player();
  object ob; 
  object wugang;
  if( (!arg) || !((arg == "tree") || (arg == "ǧ����")))
    return notify_fail("��Ҫ��ʲô��\n");
    if (me->is_busy()) return notify_fail("��������æ���ء�");
   if( !(ob = me->query_temp("weapon"))|| (string)ob->query("skill_type") != "axe")
    return notify_fail("��ȥ�ҰѸ�ͷ�ɣ�\n");
  if( me->query("kee") < (int)(me->query("max_kee")/3))
    return notify_fail("�ٿ���ȥ�ֶ�Ҫĥ���ˣ�\n");
  if (!((string)me->query("family/family_name")=="ƽ��" )&&
	objectp(wugang = present("wugang", environment(me))) && living(wugang))
    {
      message_vision("���������������˼䲢��Ϸˣ֮�����������뿪!\n", me);
    }
  else
    {
      message_vision("$N��ǧ����ʹ�������˼��£�\n", me);
      if ((int)me->query_skill("unarmed", 1)< 50 )
        {
          me->improve_skill("unarmed", me->query("str"));
          tell_object(me, "�۵ø������������������һЩ�˾�ʹ����������š�\n");
        }
      else {
	tell_object(me, "�����ſ��˼��£�������Ϊʲô���˻�������ɵ�¡�\n"); 
	}

    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}

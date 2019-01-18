//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

�����ǻʹ��ĺ�Ժ - "����԰",�����ļ�����,���������۵ľ���
��԰�м���ǿ�"ǧ����(qianzi teng)",����������,һ�ۿ�����
��.��˵����������������,����û��һ��ͷ�����,��������Ҳ��
�˺ö���,������Ҳ������������ȥ,��˵����õ�������ϵ�һ
�����ﲢ�����ʵ۵Ļ����Եõ��ʹ�,�����ʹ��(climb)���� ...
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "qianzi teng" : "һ��������Ƶ���ɫ���� �����濪��������С��
��ɢ������������,�����(climb tree)�����ܲ�������ȥ��
",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/d/calvin/lanling/npc/shouhu" : 1,
  "/d/calvin/npc/gonggong" : 1,
]));

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 3 */
   "north" : "/d/calvin/lanling/entrance",
//   "east" : "/d/calvin/lanling/midao",
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
        object wuyou;
//    if ( !wizardp(me) && dir == "south" && dir == "south") {
    if ( dir == "east" && dir == "south") {
        if(objectp(wuyou=present("wu you", environment(me))) && living(wuyou) )

            return notify_fail("����԰ͻȻ������գ����һ�Ѵ�師��ס��,���ܽ�ȥ���ʲô��\n");
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
      message_vision("�ػ����������˼䲢��Ϸˣ֮�����������뿪!\n", me);
    }
  else
    {
      if ((int)me->query_skill("dodge", 1)<40 && (int)me->query_skill("moondance", 1) < 80)
        {
	  message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
          me->improve_skill("dodge", 40-me->query("str"));
          tell_object(me, "�������һЩ�����Ṧ��������š�\n");
        }
      else
        {
          message_vision("$N�����һ�ھ���������,һ�����ʧ���޾����㻨֮���ˡ�\n", me);
                 me->move("/d/calvin/lanling/yi.c");
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
      message_vision("�ػ����������˼䲢��Ϸˣ֮�����������뿪!\n", me);
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

//int valid_leave(object me, string dir)
//{
//        object a;
//   if (dir == "climb" ) {
//                if(objectp(a=present("guard", environment(me))) &&
//living(a) )
//        return notify_fail("������ס��˵���������켫��Σ�գ����˲�Ҫ���ˣ����ǲ�Ҫ��ȥΪ�á�\n");
//        }   
//        return ::valid_leave(me, dir);
//}

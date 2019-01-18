// Room: /u/mimi/zhuziguo/westroom  snowcat moved to /d/qujing/wuji

inherit ROOM;

nosave int DP_DAWN = 0;
nosave int DP_SUNRISE = 1;
nosave int DP_MORNING = 2;
nosave int DP_NOON = 3;
nosave int DP_AFTERNOON = 4;
nosave int DP_EVENING = 5;
nosave int DP_NIGHT = 6;
nosave int DP_MIDNIGHT = 7;

// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

nosave mapping *day_phase = NATURE_D->query_day_phase();

int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time()*60);
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
	if (t>=day_phase[i]["length"])
	    t -= (int)day_phase[i]["length"];
	else
	    break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}

void create ()
{
  set ("short", "���᷿");
  set ("long", @LONG

�˼����������ֵ��������������ҹ���ֹ������Ѱ�ȥ�𴦡���
�г������ǵ��š���������ϰ����˾��飬���ϵİ�����һ����¯
ȴ����þ�û�������ˡ�

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"zheng",
  ]));
  set("sleep_room",1);

  setup();
}

void init()
{
  add_action ("do_sleep","sleep");
}

int do_sleep (string arg)
{
  object who = this_player();
  int phase = get_current_day_phase();

  if (random(5))
    return 0;
  if (present("ghost guo wang"))
    return 0;
  if (who->query("combat_exp")<50000)
    return 0;
//  if (phase > 0 && phase < 5)
//    return 0;

  message_vision ("$N����������˯�ţ��������е�����������\n",who);
  remove_call_out ("create_king");
  call_out ("create_king",2+random(10));
  return 1; 
}

int create_king() 
{
  object  king;

  if(!present("ghost guo wang"))
  {
    king = new("/d/qujing/wuji/npc/king.c");
    king->move("/d/qujing/wuji/westroom.c");
  }

  return 1;
}

void set_given()
{
  object me = this_object();

  me->set("has_given",1);
  remove_call_out("reset_given");
  call_out("reset_given",900);
}

void reset_given ()
{
  object me = this_object();

  me->set("has_given",0);
}

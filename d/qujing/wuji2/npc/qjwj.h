// ȡ����-�ڼ�ģ��


static int DP_DAWN = 0;
static int DP_SUNRISE = 1;
static int DP_MORNING = 2;
static int DP_NOON = 3;
static int DP_AFTERNOON = 4;
static int DP_EVENING = 5;
static int DP_NIGHT = 6;
static int DP_MIDNIGHT = 7;

// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

static mapping *day_phase = NATURE_D->query_day_phase();

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


int wakeup1 (object me,object where)
{
  object who = this_player();
  int phase = get_current_day_phase();

  if (random(5))
    {
    wakeup(me,where);
    return 0;
    }
  if (phase > 0 && phase < 5)
    {wakeup(me,where);
    return 0;
   }
  me->enable_player();
  while( environment(me)->is_character() )
	me->move(environment(environment(me)));
  me->set_temp("block_msg/all", 0);
  message_vision ("$N���һ�������˹�������æ�У�ͽ�ܣ�ͽ�ܣ�\n",me);
  set("inquiry/meng", : (: to_meng :) );
  set("inquiry/��", : (: to_meng :) );

  return 1; 
}

int to_meng()
  {
  object me=this_object();
  object where=environment(me);

  message_vision("ȡ����˵��:�����μ��ڼ�����Ҫ�Ҿ����������¸�"
 		+"��������Ϊ֤����\n",me);
  if (where->query("short")!="���᷿") return 1;

  set("inquiry/��������", "�Ѿ������ˣ��Ĵ����Ұ�" );
  where->set("leave_gui",1);
  return 1;
  }





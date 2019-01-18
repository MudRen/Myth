
//inherit ROOM;
#include <ansi.h>

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

int is_drunk(object me) {
  int limit = me->query("con")*6+(int)me->query("max_force")/50;
  int duration=me->query_condition("drunk");
  if  (duration > limit/10 ) return 1;
  return 0;
}

void init()
{
  add_action ("do_sleep","sleep");
}

int do_sleep (string arg)
{
  object me = this_player();
  int phase = get_current_day_phase();

  if (me->query("combat_exp")<50000) return 0;
//  if (phase > 0 && phase < 5) {tell_object(me,"������˯ʲô����\n");return 1;}
  if (!is_drunk(me)) {tell_object(me,"�㾫��ʮ�㣬����Ҫ˯����\n");return 1;}
  if (me->query("dntg/hell")=="done") return 0;
//  if(!me->query("HellZhenPass")) return 0
  if (me->query_temp("dntg_hell/next")) return 0;

  message_vision ("$N�ȵ��������������������ű�����֮�£���ʱ��˯���ˡ�\n",me);
  remove_call_out ("go_hell");
  call_out ("go_hell",2+random(5),me);
  return 1; 
}

void go_hell(object me) {
  object env;
  object hei,bai;
  object piwen;
  string *wang=({"qingguang","songdi","chujiang","chuguan","pingdeng",
                 "dushi","taishan","lunzhuan","biancheng","yanluo",
               });

  mapping name=(["qingguang":"�ع���","songdi":"�ε���","chujiang":"������",
    "chuguan":"������","pingdeng":"ƽ����","dushi":"������","taishan":"̩ɽ��",
    "lunzhuan":"��ת��","biancheng":"�����","yanluo":"������" ]);

  string wang1=wang[random(10)];
  me->set_temp("dntg_hell/next",wang1);
  
  tell_object(me,HIB"\n˯���к����������˹����������ȵ�����"+me->query("name")+
               "���������Ѿ�����ȷ�ڤ��֮�����������㡣��\n"
                +"˵�ղ��ݷ�˵���ø��������㾱��һ�ף����˾��ߡ�\n\n"NOR);
  me->move("/d/death/new-zhaopo");
  env=environment(me);
  if (!bai=present("bai wuchang",env)) {
     bai=new("/d/death/npc/baiwuchang");
     bai->move(env);
  }
  if (!hei=present("hei wuchang",env)) {
     hei=new("/d/death/npc/heiwuchang");
     hei->move(env);
  }

  piwen=new("/d/dntg/hell/piwen");
  if (random(2)) piwen->move(hei);
   else piwen->move(bai);
  piwen->set("long","    ��"+me->query("name")+
             "�����Ѿ�������ڰ��޳�������ǹ��ù鰸��\n\n"+
             "                            "+name[wang1]+"  ��\n\n\n");

  piwen->set("target",me->query("name"));
}

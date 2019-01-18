//Cracked by Roath

#include <ansi.h>

inherit NPC;

/*
static int DP_DAWN = 0;
static int DP_SUNRISE = 1;
static int DP_MORNING = 2;
static int DP_NOON = 3;
static int DP_AFTERNOON = 4;
static int DP_EVENING = 5;
static int DP_NIGHT = 6;
static int DP_MIDNIGHT = 7;
*/
// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

static mapping *day_phase = NATURE_D->query_day_phase();

string seashore="/d/changan/eastseashore";
string beach="/d/changan/beach";

void flyaway();

/*
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

*/
void create() {
  set_name("����",({"jing wei","wei","bird"}));
  set("long","һֻ�ɰ���СС�񣬰�๳��㣬ɫ�ʰ�쵣��ഫ���׵۵�СŮ����\n");
  set("gender","Ů��");
  set("age",5);
  set("per",999);
  set("str",30+random(10));
  set("cor",40);
  set("cps",30);
  set("max_sen",400);
  set("sen",400);
  set("max_kee",400);
  set("kee",400);

  set("combat_exp", 3000);
  set("daoxing",3000);
  set_skill("unarmed", 10);
  set_skill("baihua-zhang", 10);
  map_skill("unarmed", "baihua-zhang");
  set_skill("dodge", 20);
  
  set("limbs", ({
               "ͷ��", "����", "�ؿ�", "����", "β��","๲�",
               "���", "�ҽ�", "���", "�ҳ�",}) );

  setup();
/*
  set("chat_msg", ({
            (: flyaway :),
             
        }) );
  set("chat_chance",30);
*/
  set("inquiry", ([
     "name" : "�����׵۵�Ů������Ů�ޣ��ڶ�����Ӿʱ�����ˣ��ͻ������ڵ����ӡ�",
     "here" :"������������ҵĶ���(sea)����һ��Ҫ������(fill)ƽ��",
     "�" : "��Ǽ���Σ�յ��£���Ҫ�Ǿ��ñ��칻�ˣ�������(sui)��һ��ȥ��",
  ]) );
  call_out("flyaway",10+random(10));

}

void flyaway() {
  object *all;
   string dest;
  int phase = NATURE_D->query_current_day_phase();
   object me=this_object();
//   command("say hi.");

   call_out("flyaway",10+random(10));
  if (!living(me)) return;
  if (!environment()) return;
  all=all_inventory(environment(me));
   if (environment()->query("short")=="����֮��") {
     if (random(2)) {
         message_vision("$N�ӵ��ϵ���һЩʯ�顣\n",me);
         return;
     }
     dest=beach;
   } else if (environment()->query("short")=="������̲") {
       if (random(2)) {
          message_vision("$N���������ŵ�ʯ��Ͷ�뺣�С�\n",me);
          return;
       }
       dest=seashore;
   } else {
//     command("say where am i?");
     return;
   }
   message_vision("$N���ų������ˡ�\n",me);
   me->move(dest);
   message_vision("$N���˹�����\n",me);
   if (!all) return;
   if (phase<6) return;
   for (int i=0;i<sizeof(all);i++)
     if (userp(all[i]) && all[i]->query_temp("follow_jingwei")) {
        all[i]->move(dest);
        all[i]->delete_temp("follow_jingwei");
     }
}

void init() {
   add_action("do_gen","sui");
}

int do_gen(string arg) {
  int phase = NATURE_D->query_current_day_phase();
   object me=this_player();
   object jignwei=this_object();

  if (!arg && arg!="jing wei" && arg!="bird" && arg!="wei")
    return notify_fail("��Ҫ��˭��\n");
  if (me->query_temp("follow_jingwei"))
    return notify_fail("���Ѿ��ڸ��ž����ˡ�\n"); 
  if (phase<6) 
    return notify_fail("��������˵������������̫���ˣ��������ٴ���ȥ�ɡ���\n");

  me->set_temp("follow_jingwei",1);
  message_vision("$N�������澫��һ��ȥ���\n",me);
  return 1;
}

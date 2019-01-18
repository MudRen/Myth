
inherit NPC;

#include <obstacle.h>
#include <ansi.h>

#define DEBUG 0

#define LEVEL_NONE 0
#define LEVEL_ASKED 1

string *list=({"yg-qiankun","yg-jianmang","yg-jianzhang","yg-zxzx",
                "yg-ba","yg-jldl",
        });
int reward_player ();
int recover_death ();

void create()
{
  set_name("������", ({ "rulai fo", "rulai", "fo" }));
  set("title", "������Ӱ�٤��");
  set("long", "��ȴ���ɽ������ɲ������Ӱ�٤��������ү��\n");
  set("gender", "����");
  set("age", 10000);
  set("attitude", "peaceful");
  set("rank_info/self", "ƶɮ");
  set("rank_info/respect", "����үү");
  //set("class", "bonze");
  set("str",100);
  set("per",100);
  set("max_kee", 10000);
  set("max_gin", 10000);
  set("max_sen", 10000);
  set("force", 10000);
  set("max_force", 10000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);
  set("combat_exp", 4000000);
  set("daoxing", 10000000);

  set_skill("literate", 300);
  set_skill("spells", 300);
  set_skill("buddhism", 300);
  set_skill("unarmed", 300);
  set_skill("jienan-zhi", 300);
  set_skill("dodge", 300);
  set_skill("lotusmove", 300);
  set_skill("parry", 300);
  set_skill("force", 300);
  set_skill("lotusforce", 300);
  set_skill("staff", 300);
  set_skill("lunhui-zhang", 300);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );
  set("inquiry", ([
    "die" : (: recover_death :),
    "death" : (: recover_death :),
    "recover" : (: recover_death :),
    "��������" : (: recover_death :),
    "����" : (: recover_death :),
    "��" : (: recover_death :),
    "��" : (: recover_death :),
    "qujing" : (: reward_player :),
    "obstacle" : (: reward_player :),
    "obstacles" : (: reward_player :),
    "ȡ��" : (: reward_player :),
    "��" : (: reward_player :),
  ]) );

  set("my_level",LEVEL_NONE);
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

void init ()
{
  add_action("do_back", "back");
  add_action("do_task", "task");
  add_action("do_cancel", "cancel");
}

void announce (object me, string str)
{
  if (DEBUG)
  { 
    object snowcat = find_player ("snowcat");
    if (snowcat && wizardp(snowcat))
      tell_object (snowcat,"�� "+str+"\n");
  }
  else
  {
    CHANNEL_D->do_channel(me,"chat",str);
  }
}

int recover_death()
{
  object me = this_object();
  object who = this_player();

  if (who->query("obstacle/mud_age") > who->query("death/mud_age"))
  {
    message_vision ("$N��$nҡ��ҡͷ���Ϸ�δ����ѸҲ��\n",me,who);
    return 1;
  }
  if (!who->query("death"))
  {
    message_vision ("$N��$nҡ��ҡͷ���Ϸ�δ����ѸҲ��\n",me,who);
    return 1;
  }

  if (! who->query("obstacle/reward"))
  {
    message_vision ("$N��$nҡ��ҡͷ������ȥ������ذɡ�\n",me,who);
    return 1;
  }
  if (who->query("obstacle/rebirth") >= 3)
  {
    message_vision ("$N��$nҡ��ҡͷ��������������ë���þ�Ҳ��\n",me,who);
    return 1;
  }
  who->add("obstacle/rebirth",1);
  message_vision ("\n$N�γ�һ��������ë������һ�����\n",me);
  message_vision ("\n$N�پ�������תǬ�����ã�ɲ�Ǽ����ס���������\n",who);
  if (who->query("death/combat_exp_loss"))
  {
    tell_object (who,"��ͻȻ���������ѧȫ���ָ��ˣ�\n");
    who->add("combat_exp", (int)who->query("death/combat_exp_loss"));
  }
  if (who->query("death/dx_loss"))
  {
    tell_object (who,"��ͻȻ������ĵ���ȫ���ָ��ˣ�\n");
    who->add("daoxing", (int)who->query("death/dx_loss"));
  }
  if (who->query("death/mud_age"))
  {
    tell_object (who,"��ͻȻ�������Ǳ��ȫ���ָ��ˣ�\n");
    who->add("potential", (int)who->query("potential")-who->query("learned_points"));
  }
  if (who->query("death/skill_loss"))
  {
    tell_object (who,"��ͻȻ��������书ȫ���ָ��ˣ�\n");
    who->skill_death_recover();
  }
log_file("RECOVER","["+ctime(time())+"] "+sprintf("%s(%s)ʹ���˾�����ë.\n"
, who->query("name"),who->query("id")));
  who->delete("death");
  who->save();
  return 1;

}

void do_reward (object who)
{
  object me = this_object();
  int size1 = sizeof(obstacles);
  int size2;
  string *strs = values(obstacles);
  mapping skills = who->query_skills();
  int i;

  if (! interactive (who))
    return;

  if (who->query("obstacle/reward"))
    return;

  if (who->query_temp("no_move"))
    return;

  if (who->query("obstacle/number") < size1)
    return;

  size2 = sizeof(skills);

  message_vision ("��������ϼ���ƽ�������$N���������������һ��ݵ��ڵأ�\n",
                  who);
  message_vision ("\n$N��$n˵��"+RANK_D->query_respect(who)+
                  "һ·�����������ѣ����������ྡ����Ҳ��\n",me,who);
  i = (size1+size2+2)*3;
  who->start_busy(i,i);
  who->set_temp("no_move",1);

  strs = (string *)sort_array (strs, 1);
  for (i = 0; i < size1; i++)
  {
    call_out("rewarding1",(i+1)*3,me,who,strs[i]);
  }
  call_out("rewarded1",(size1+1)*3,me,who);
  strs = keys(skills);
  for (i = 0; i < size2; i++)
  {
    call_out("rewarding2",(size1+i+2)*3,me,who,strs[i]);
  }
  call_out("rewarded2",(size1+size2+2)*3,size2,me,who);
}

void rewarding1 (object me, object who, string str)
{
  int i = 600+random(who->query("kar")*30);

  who->add("obstacle/reward",i);
  who->add("potential",i);
  message_vision ("\n$N˵����"+str+"һ�أ���$n"+chinese_number(i)+
                  "��Ǳ�ܣ�\n",me,who);
  tell_object(who,"���Ǳ��������"+chinese_number(i)+"�㣡\n");
}

void rewarded1 (object me, object who)
{
  int i = who->query("obstacle/reward");

  remove_call_out("rewarding1");
  message_vision ("\n$Nһ��ͷ������"+chinese_number(i)+"��Ǳ�ܣ�\n",me);
  announce (me,who->query("name")+"����ȡ��������������"+
            chinese_number(i)+"��Ǳ�ܣ�\n");
}

void rewarding2 (object me, object who, string str)
{
  int i = who->query_skill(str,1);
  string name = to_chinese(str);

  who->set_skill(str,i+1);
  message_vision ("\n$N˵��������һ��"+name+"��\n",me,who);
  tell_object(who,"���"+name+"������һ����\n");
}

void rewarded2 (int size, object me, object who)
{
  remove_call_out("rewarding2");
  message_vision ("\n$Nһ��ͷ������"+chinese_number(size)+"�����ܣ�\n",me);
  announce (me,who->query("name")+"����ȡ����������������"+
            chinese_number(size)+"�����ܣ�\n");
  call_out("informing",1,me,who);
}

void informing (object me, object who)
{
  who->interrupt_me();
  who->set_temp("no_move",0);
  who->save();
  me->set("my_level",LEVEL_NONE);
  me->delete_temp("invite");
  message_vision ("\n$N��$n˵��������ȥ����ȡ�澭һ����\n",me,who);
  message_vision ("\n$N�ֲ�������պ����в��⣬�������۱��������������Ρ�\n",
                  me);
}

int reward_player ()
{
  object me = this_object();
  object who = this_player();
  object *all, *list;
  int size1 = sizeof(obstacles);
  int i, j;

  if (me->query("my_level") == LEVEL_ASKED)
  {
    message_vision ("$N��$nҡͷ˵�����Ϸ���æ��\n",me,who);
    return 1;
  }

  if (who->query("obstacle/reward"))
  {
    message_vision ("$N��$n˵�����㲻���Ѿ���������\n",me,who);
    return 1;
  }

  if (who->query_temp("no_move"))
  {
    message_vision ("$N��$nҡҡͷ��\n",me,who);
    return 1;
  }

  if (who->query("obstacle/number") < size1)
  {
    message_vision ("$N��$nҡͷ˵��������δ�����ѹء�\n",me,who);
    return 1;
  }

  if (me->query("last_player") != who)
  {
    me->set("last_player",who);
    me->set_temp("invite","public");
    announce (me,who->query("name")+"��Զ����ǰ��ȡ�澭��");
    announce (me,"��λ������Ը����ʹaccept rulai fo��ɣ�\n");
    remove_call_out ("inviting");
    call_out ("inviting",1,me);
    return 1;
  }

  all = users();
  i = sizeof(all);
  list = all_inventory(environment(me));
  j = sizeof(filter_array(list, (:userp:))) - 1;

  if ((i/4-j) > 0)
  {
    message_vision ("$N��$nҡҡͷ�����μ�����"+chinese_number(i)+"λ��ң�"
                    "�˴�������λ�����������ɷ�����"+chinese_number(i/4-j)+
                    "λ����ǰ������\n",me,who);
    if (! DEBUG)                 
      return 1;
  }
  announce (me,"���μ�����ȡ�澭����"+who->query("name")+"���۱������\n");

  me->set("my_level",LEVEL_ASKED);
  do_reward (who);
  return 1;
}

void inviting (object me)
{
  int i;
  object *list;

  if (! me->query_temp("invite"))
    return;
  
  remove_call_out ("inviting");
  call_out ("inviting",4+random(4),me);

  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (environment(list[i])->query("unit")) // not a room
      continue;
    if (list[i]->is_fighting())
      continue;
    if (list[i]->is_busy())
      continue;
    if (list[i]->query_temp("no_move"))
      continue;
    if (list[i]->is_ghost()) // Checking ghost
      continue;
    if (!living(list[i]))
      continue;
    if ((string)list[i]->query_temp("accept")!=me->query("id"))
      continue;

    list[i]->set_temp("accept",0);
    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    message_vision("$N������˼����Զ������֡���\n",me);
    list[i]->set_temp("accept",0);
    list[i]->set_temp("lingshan/from",there);
    message_vision("һ������Ʈ�����������һֻ�޴�ķ��ֽ�$N����������ʧ����ա�\n",list[i]);
    list[i]->move(here);
    message_vision("����$N����һ���ƣ�$n���ȵ����������ڵ��ϡ�\n",me,list[i]);
    break;
  }
}

int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("lingshan/from");

  message_vision("$N����$n��$N�ط���\n",who,me);
  //if (!there)
  //  there = "/d/city/kezhan";
  there = "/d/city/kezhan";

  who->set_temp("accept",0);
  message_vision("$N��������������$n��Զ����ȥ����\n",me,who);
  who->move(there);
  message_vision("�����������һֻ�޴�ķ�������һ����ֻ��$N��������������\n",who);

  
  return 1;
}

void die()
{
  if (environment())
    message("sound", "\n\n��������һ��ͷ�����ޱߣ�\n\n", environment());

  set("eff_kee", 10000);
  set("eff_gin", 10000);
  set("eff_sen", 10000);
  set("kee", 10000);
  set("gin", 10000);
  set("sen", 10000);
  set("force", 10000);
  set("mana", 10000);
}

void unconcious()
{
  die ();
}


int do_task()
{
        object me = this_player();
        object guai;
        int level,i;
        int tt;
        int size1 = sizeof(obstacles);
        string kind,where,msg;
        if( (tt=(int)me->query("rulaitask/job_start")) &&
		me->query("rulaitaskjob/done")) {
 // job done
	    if(tt<=time() &&
                    time()<tt+360) {
		message_vision("$N��ָһ�㣬��ħ�ѽ���,�㻹�Ǿ�������ĥ��������\n",
			this_object(), me);
		return 1;
	    }
	   
	}
	me->delete("rulaitask/job_start");
        me->command("say ���ʷ��棬�����������Ϊ����");
        
        if (me->query("obstacle/number") < size1)
             {message_vision(CYN"\n������˵��������δȡ���澭���ó�����������ܽ�ħ���֡�\n"NOR,me);
              return 1;
             }
        if( me->query("rulaitask/get") )
             {message_vision(CYN"\n������˵�����Ҳ����Ѿ������������𣬿����̡�\n"NOR,me);
              return 1;
             }
        
        if( me->query("rulaitask/fail") )
             {message_vision(CYN"\n������˵�������ȵ����������������������У�����������ɡ�\n"NOR,me);
              return 1;
             }
        
        if( me->query("rulaitask/accomplish") )
             {message_vision(CYN"\n������˵����������ħ��Ȼ��Ҫ��Ҳǧ��Ҫ������������У�����
�����׻����������ħ���ģ������ȥ�����úò���ղŵ�ս��ȥ�ɡ�\n"NOR,me);
              return 1;
             }
             
        //ȷ������ȼ�
        level = random(10);
        if (level<5) level=1;
        else if (level<8) level=2;
        else level=3;
        
        //ȷ����������
        i = random(4);
        if (i==0) kind="ɱ";
        else if (i==1) kind="��";
        else if (i==2) kind="��";
        else kind="Ȱ";
        
        me->set("rulaitask/get",1);
        me->set("rulaitask/level",level);
        me->set("rulaitask/kind",kind);
        me->delete("rulaitaskjob/done");
        guai = new("/d/wizz/stey/"+list[random(sizeof(list))]);
        where=guai->invocation(me, level);
        switch (kind)
          {
                case "ɱ": {message_vision(CYN"\n������˵����������һ��"+where+"������û���˹�
�Ѿ���ɱ�˲����޹��������ӯ�ˣ������ȥ���������ɡ�\n"NOR,me); break;}
                case "��": {message_vision(CYN"\n������˵����������һ��"+where+"������û���˹���δ��
����ӯ�������ѵ㻯�������ȥ�������ܻ������������Ե㻯����\n"NOR,me); break;}
                case "��": {message_vision(CYN"\n������˵����������һ��"+where+"������û���˹ָոյ�����ɽ
��δΪ�񣬵��ǳ����¶��ݣ���ֻ��ݺݽ�ѵ��һ�أ����Ͳ���Ϊ���ˡ�\n"NOR,me); break;}
                case "Ȱ": message_vision(CYN"\n������˵����������һ��"+where+"������û����
�ֱ��Բ�����ֻ��δ�ܳ����Խ������ȥ�㻯���ɡ�\n"NOR,me);
          }
        me->set("rulaitask/guai",guai);
        me->set("rulaitask/where",where);
        me->set("rulaitask/start_time",time());
        me->set("rulaitask/job_start",time());
        msg = me->name()+"�ӵ�һ���Ѷ�"+chinese_number(level)+"��"+kind+"������";
        MONITOR_D->report_system_msg (msg);
        return 1;
}        

int do_cancel()
{
        object me = this_player();
        int tt;
          if (!me->query("rulaitask/get"))
             {tell_object(me,"��û����������\n"); return 1;}
        if ( (tt=(int)me->query("rulaitask/job_start"))){
        if(tt<=time() &&
                    time()<tt+600) {
		message_vision("$N˵����ʱ��δ�������ɷ����������ӷ�\n",
			this_object(), me);
		return 1;
	    }
        else{
      
            
        me->command("say ���������ӿ�������Ϊ����");
        message_vision(CYN"\n������˵�����ðɣ���������ȥ�շ��˹֣��㵽�����úò���ȥ�ɡ�\n"NOR,me);
        me->set("rulaitask/fail",1);
        me->delete("rulaitask/get");
        me->delete("rulaitask/job_start");
        
        return 1;
        }
        }
}       

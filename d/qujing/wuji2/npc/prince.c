#include <ansi.h>

inherit NPC;

void create()
{
  set_name("̫��", ({"tai zi", "zi", "prince"}));
  set ("long", "�ڼ�������̫�ӣ�����֮���ٳ���������������Ϊ�֡�\n");
  set("title", "�ڼ���");
  set("gender", "����");
  set("age", 20);
  set("combat_exp", 300000);
  set_skill("blade", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("unarmed", 90);
  set_skill("force", 90);
  set_skill("changquan", 90);
  set_skill("wuhu-blade", 90);
  set_skill("lengquan-force", 90);
  set_skill("yanxing-steps", 90);
  map_skill("blade", "wuhu-blade");
  map_skill("unarmed", "changquan");
  map_skill("dodge", "yanxing-steps");
  map_skill("parry", "wuhu-blade");
  set("max_sen", 400);
  set("max_kee", 700);
  set("max_force", 800);
  set("force", 1000);
  set("force_factor", 45);
  set("idle",1);		//ƽ�����Ƿ���״̬
  setup();
 
  carry_object("/d/obj/weapon/blade/jindao")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
          if( query("idle")>0) 
   	    {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
 	    }
        }
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "yu gui")
    return 0;
  message_vision ("ֻ����$N��ɫһ�䣬�����е���"+
                  "�����ˣ�����������ʱ���������У���\n",me);

  return 1;
}

/*
void refuse_it (object me, object who, object ob)
{
  message_vision ("$N����$n��ɫһ�䣬�����е���"+
                  "�����ˣ�����������ʱ���������У���\n",me,ob);
  message_vision ("$Nŭ����ڣ����һ��Ҫɱ��$n��\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
  destruct (ob);
}

void accept_it (object me, object who, object ob)
{
  message_vision ("$N����$n��ɫһ�䣬����ס�е���"+
                  "�����ˣ�������������Ҳ����\n",me,ob);  
  message_vision ("$N������¡�\n",me);
  call_out ("give_jing",2,me,who);
  destruct (ob);
}

void give_jing (object me, object who)
{
  object ob = new ("/d/qujing/wuji/obj/jing");
  message_vision ("\n$N��$n˵���������ˣ����������һ������Ц�ɣ���\n",me,who);   message_vision ("\n˵��$Nȡ��һϻ�ӣ��ó�һСƿ����\n",me,who);  
  ob->move(me);
  me->command_function("give "+who->query("id")+" jing");
}
*/

void greeting(object ob)
{
   object me=this_object();
   mixed name;

   if( !ob || !visible(ob) || environment(ob) != environment() ) return;
   if( ob->query("obstacle/qujing")!="ren")return ;
   if( me->query("idle")==2)
     {
     command_function("say ʦ��˵�ļ���,����Ⱦ��Ҹ�����,"
		+"���Ѿ����ǿ��غ�԰�Ĺ�Ů˵����\n"); 
     ob->set_temp("obstacle/have_saied",1);     
     set("idle",0);
     return ;
     }       

   if( ob->query_temp("obstacle/have_gui")!=1)return ;
	//���������ȡ���˲ſ��Լ�̫��	
   name=ob->query_temp("apply/name");
   if (sizeof(name)==0)return ;
   if( name[0]!="ɽ��")return ;
   
   switch( random(3) ) 
     {  
     case 0:
       message_vision(RED "$N��Ȼ�μ�ŭ��,һֻ��ֱ��$n���˹���\n" NOR,me,ob);
       if (ob->query_skill("dodge")<20)
         {
	 if (random(20)>ob->query_skill("dodge"))
           {
           message_vision("ֻ��$N��������ȥ��\n",ob);
           ob->die();		//�������ǲ���̫�п���Щ
	   return ; 
           }
         }
       me->command_function("follow "+ob->query("id"));
       me->set_leader(ob);
       set("idle",0);   
       break;
     }
}


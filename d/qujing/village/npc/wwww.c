//Cracked by Roath
int qujing();

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("����", ({ "woman", "fu ren"}));
   set("gender", "Ů��" );
   set("age", 45);
   set("per",40);
   set("long","һλ��ʩ֬��������������������ŵ�������\n");
   set("combat_exp", 600+random(400));
   set("daoxing", 600+random(400));
   set("attitude", "friendly");
   set_skill("dodge", 10);
   set_skill("unarmed", 10);
   setup();
   carry_object("/d/qujing/dudi/obj/cloth")->wear();
   add_money("silver", 3+random(20));
}

void init()
{
        object ob = this_player();
        add_action("do_yes","yes");
	remove_call_out("checking");
        call_out("checking",1,ob);
}

void checking(object ob)
{	object me = this_object();
        if( ob->query("obstacle/village") == "done" )
                return;
        if( !ob->query("obstacle/liusha") )
                return;

        if( ob->query_temp("yao_killed") <3 
          && ob->query_temp("seen") )
                {
	message_vision(CYN"$N��$n���İ������ȥ����ɱ����Щ���ְɡ�����\n"NOR,me,ob);
        return;
                }
        if( ob->query_temp("yao_killed") 
        && ! ob->query_temp("cao_given") )
          {
        message_vision(CYN"$N��$n˵������λ"+RANK_D->query_respect(ob)+"�ܷ��ٰ���ȥѰ��"+RED"��Ҷ��֥��"NOR+CYN"��\n"NOR,me,ob);
        return;
          }
        message_vision(CYN"$N����$n˵������˵��λ"+RANK_D->query_respect(ob)+"��ȥ����ȡ�澭�ģ��ܷ�(yes)���æ�أ�\n"NOR,me,ob);
        
        ob->set_temp("womenask","yes");
        return;
}
int do_yes()
{	object ob=this_object();
	object me=this_player();
	if( me->query_temp("womenask")=="yes")
	{
	message_vision(CYN"$N����$n���ͷ����ԸΪЧ�͡�\n"NOR,me,ob);
	call_out("give_task",1+random(2),me,ob);
	return 1;
	}
	return 0;
}
	
int give_task(object me,object ob)
{
	tell_object(me,CYN"���˶���˵�������Ǽұ�����Щ���������ң���֪���ܷ����ɱ�����ǰ���\n"NOR);
	me->delete_temp("womenask");
	me->set_temp("seen",1);
	return 1;
}


int accept_object(object who,object ob)
{
      

         if( ob->name() == RED "��Ҷ��֥��" NOR )
                {
                if( !who->query_temp("yao_killed") )
                  {
                command("say �㻹����ȥ����ɱ����Щ���ְɡ�����");
                return 0;
                  }
                command("smile");
                command("nod");
                who->set_temp("cao_given",1);
                this_object()->set_name("��ɽ��ĸ",({"lishan laomu","lao mu"}));
                call_out("pass",1,this_player());
                return 1;
                }
        return 0;
}

void pass(object ob)
{
  int i;
 if( ! ob->query_temp("yao_killed") )
     return;
  if(! ob->query("obstacle/liusha") )
  return;
 if (ob->query("combat_exp") < 10000)
    return;
  if (ob->query("obstacle/village") == "done")
    return;
  i = random(500);
  ob->add("obstacle/number",1);
  ob->set("obstacle/village","done");
       ob->add("daoxing",i+2000);
  command("chat "+ob->query("name")+"��ס�����������Ŀ��飡");
  message("channel:chat",HIY"������ն������������(guanyin pusa)��"+ob->name()+"��������ȡ��[1;37m�ڰ˹أ�\n"NOR,users());
  tell_object (ob,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  ob->delete("seen");
  ob->save();
  destruct(this_object());
  return;
}

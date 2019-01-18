//added job by wuyou

#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();

void create()
{
        set_name("����̫", ({"er yitai", "yitai"}));
        set("age", 22);
        set("gender", "Ů��");
        set("long",
"Ҧ�ҵĶ���̫̫�����㿴�����������˸����ۣ�\n");
        set("attitude", "friendly");
        set("per", 22);
        set("combat_exp", 1000);
        set("shen_type", 1);
        set_skill("unarmed", 10);
        set_skill("dodge", 40);
        set("inquiry", ([
                "����" : (: do_gongzuo :),
        ]) );
        setup();

        carry_object("/d/obj/cloth/nichang")->wear();
        carry_object("/d/obj/cloth/yuanxiang")->wear();

}

void init()
{
      ::init();
   add_action("do_fight", "fight");
   add_action("do_kill", "kill");
}

int do_fight(string arg)
{
   object who = this_player();
   object me = this_object();
    if (arg && present(arg,environment(who))==me)
    {
      message_vision("$N���������ܣ�������̫���к���,����$N���֡�\n",who,me);
     return 1;
   }
   return 0;
}

int do_kill(string arg)
{
     object who = this_player();
    object me = this_object();

    if (arg && present(arg,environment(who))==me)
  {
    message_vision("$N��������ɱ������̫������̫Ц��Ц,û��$Nһ���ʶ��\n",who,me);
    return 1;
   }
return 0;
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        if (me->query("combat_exp")>=150000)
        {
               command("say ����书���Ҷ����������ǻ�Ҫ���ˣ�����С�²���������ܡ�\n");
               return 1;
         }
        if( me->query_temp("newbiejob/yunbu")>0)
        {
                tell_object(me,"��ȥ�Ѳ�ƥ�ٺú󽻸��Ұɡ�\n");
                return 1;
        }  
        message_vision(CYN"����̫��$N˵���������ٺõĲ�ƥ�������ˣ���͵�����Ŀⷿ��ȥ��Щ������\n"NOR,me); 
        me->set_temp("newbiejob/yunbu", 1);
        return 1;   
}

int accept_object(object me, object ob)
{
        object ob1;
        if (strsrch(ob->query("name"), "�ٺõĲ�") < 0) 
        {
            command("say ������������������ٺõĲ���\n");
        }
        else if (me->query_temp("newbiejob/yunbu")<1)
        {
            command("say ��û�н�������ٲ�ѽ��\n");
        }
        else
        {
            message_vision(CYN"����̫��$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me);
            message_vision(CYN"����̫�ݸ�$NһЩ���ӡ�\n"NOR,me);  
                me->delete_temp("newbiejob/yunbu");
                me->add("combat_exp",20+random(20));
                me->add("potential",10+random(10));
                me->start_busy(3+random(2));
                ob1=new("/obj/money/silver");
                ob1->set_amount(10 + random(5));  
                ob1->move(me); 
                call_out("destroying", 1, this_object(), ob);
                return 1;
        }
        return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}




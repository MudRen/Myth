// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("�ն�÷˹", ({"homeis", "shi nu"}));
        set("long", "��˵�еĴ�����ն�÷˹���ػ���Ů����\n");
        set("gender","����");
        set("title", "��������");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "�ն�÷˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("shinu", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shinu");
        map_skill("dodge","balei");
        set("max_force", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 1200);
        set("max_gin", 1200);
        set("max_sen", 1200);

        setup();
        carry_object(__DIR__"obj/su_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}

void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               


     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIG"$N��������һ�ӣ�һ�����Х����\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIG"$N���紵�Ĺ��ڵ��ϣ����ް��������\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIG"$N�ڷ�����ת�ţ������������������ս��\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$Nһ���������죬һ����������$n��\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N���������˸����ţ�ֱ���ͷƤ���飡\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIC"$N��Ϳ���������ķ�������һ�����㿪�ˡ�\n"NOR,me);
        }
        break;
    }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}

void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/shizi")=="done") && (ob&&ob->query("12gong/shinu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�����޴�˵������(fo tuo):"+ob->name()+
        "�����˵���������Ů������ƽ�սʿ������\n"NOR,users());
        ob->set("12gong/shinu","done");
        ob->add("12gong/number",1);
        ob->add("daoxing", 10000);
        tell_object(ob,"��Ӯ����ʮ�����");

        }
       ::die();
}

int do_none()
{
        object me = this_object();

        message_vision("$N��Цһ�������Ҵ�������ǰ��������ʲô������\n",me);
        return 1;
}

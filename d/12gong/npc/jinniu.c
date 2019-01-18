// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("ФȮ����", ({"xiaogou jun"}));
        set("long", "��˵�е�ʮ��������Ȯ���ػ�������\n");
        set("gender","Ů��");
        set("title", "��Ȯ��");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",1000000);
          set("daoxing",2800000);
        set("chat_chance",20);
        set("chat_msg", ({
                "ФȮ����˵������֪��ʱ�ܸϵ��������\n"   
        }));
        set_skill("dodge", 210);
        set("attitude", "friendly");
        set_skill("force", 210);
        set_skill("parry", 210);
        set_skill("unarmed", 210);
        set_skill("sword", 210);
        set_skill("westsword",210);
        set_skill("boxing",210);
        set_skill("balei",210);
        set_skill("spells",210);
        set_skill("jinniu", 210);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 2500);
        set("force", 5000);
        set("max_mana",2500);
        set("mana",5000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 1200);
        set("max_gin", 1200);
        set("max_sen", 1200);

        setup();
        carry_object(__DIR__"obj/jn_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
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
        message_vision(YEL"$N�ӻ����䣬������$n��������\n",ob,me);


       if(random(3)==0)
                {
              message_vision(YEL"$N�������Ļ�����û��˫�ۣ�\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(YEL"$NҲ������ͣ��ѷ����Ļ����׷״����ڵأ�\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N�����дʣ�һֻ�Թ���$n������\n",ob,me);

                if(random(3)==0)

                {
              message_vision(YEL"$N���Թ��ļ���ҧ�˸��������\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        }
        break;

        case 2:
        {

        message_vision(HIR"$N��$nֱ���ȥ��\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N��������ܣ�����ӭ����ȥ��\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N��׼���򣬶㿪��$n��˺ҧ��\n"NOR,me,ob);
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

        if((ob&&ob->query("12gong/baiyang")=="done") && (ob&&ob->query("12gong/jinniu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�����޴�˵������(fo tuo):"+ob->name()+
        "�����˵ڶ������Ƶ�����!\n"NOR,users());
        ob->set("12gong/jinniu","done");
        ob->add("12gong/number",1);
         ob->add("daoxing", 10000);
        tell_object(ob,"��Ӯ����ʮ�����");

        }
       ::die();
}

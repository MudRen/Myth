inherit NPC;
#include "star.h"
 
void create()
{
        set_name("ͯ��", ({"tong hu", "tian chen"}));
        set("long", "��˵����®ɽ���Ϸ徲��0243����й������\n");
        set("gender","����");
        set("title", "����ʥ��");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",4000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "ͯ��˵����ֻ���й�������õĹ���\n",
        }));
        set_skill("dodge", 380);
        set("attitude", "friendly");
        set_skill("force", 380);
        set_skill("parry", 380);
        set_skill("unarmed", 380);
        set_skill("staff", 380);
        set_skill("lunhui-zhang",380);
        set_skill("jienan-zhi",380);
        set_skill("lotusmove",380);
        set_skill("spells",380);
        set_skill("buddhism", 380);
        map_skill("staff","lunhui-zhnag");
        map_skill("unarmed","jienan-zhi");
        map_skill("spells","buddhism");
        map_skill("dodge","lotusmove");
        set("max_force", 6500);
        set("force", 13000);
        set("max_mana",7000);
        set("mana",14000);
        set("mana_factor",260);
        set("force_factor", 230);
        set("max_kee", 5500);
        set("max_gin", 5500);
        set("max_sen", 5500);

        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
        carry_object("/d/obj/weapon/staff/tc_staff")->wield();
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

     switch(random(5))
     {        
        case 0:
        {
        message_vision(HIC"$N��һ����®ɽ�����ԡ�һ�������Ծ������ֱ��$n��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"$N�������ڿ��ж��÷��˼�ʮ����ͷ��\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else        message_vision(HIG"$N���ͼ�ת����֪�����˶���Ȧ�Ŷ�������Ĺ�����\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N�ߺ�һ������®ɽ�����ԡ���һ�������Խ��׶�����β����$nɨȥ��\n",ob,me);

        if(random(2)==0)
                {
              message_vision(GRN"$N��������β��˦�˸����ţ�$N��ʱ��ð���ǣ�\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIY"$N�þ�ȫ������������������������β������$N�Ľŵװ�ɨ����\n"NOR,me);
        } 
        break;

        case 2:
        {

        message_vision(HIR"$N�ߺ�һ������®ɽ�����ԡ�������ֻ������$n�������\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIR"$N��һ����һ����������ֻ�����ڿ���ϷŪ�ţ�\n"NOR,me);
              me->add("eff_kee",-3*query("max_kee")/10);
              me->add("eff_sen",-3*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N��׼�˾���֮��Ŀ�϶����ת��ת������ǿ���ѣ�\n"NOR,me,ob);
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

        if(ob&&ob->query("12gong/shinu")=="done")
        {
        ob->start_busy(3);
        message("chat",HIY+"�����޴�˵������(fo tuo):"+ob->name()+
        "�����˵��߹�����ӹ�!\n"NOR,users());
        ob->set("12gong/tiancheng","done");
        ob->add("12gong/number",1);

        }
       ::die();
}

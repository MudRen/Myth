// ����̨�ػ��� �켫 by Calvin
 
inherit NPC;
#include <ansi.h>
#include "star.h"
inherit F_MASTER;
 
void create()
{
        set_name(HIW"�켫"NOR, ({"tian ji", "shouhu shen","shen","tianshen","ji","tianji"}));
        set("title",HIW"����̨�ػ���"NOR);
        set("long", "��˵���̹ŵĵ�Ѫ�������ֻؾ���֮��,��������\n");
        set("gender","����");
        set("age",37);
        set("con",40);
        set("attitude", "aggressive");
        set("per",30);
        set("str",43);
        set("int",54);
        set("combat_exp",10000000);
        set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "�켫˵��:��˭��˽������̨,С������������\n"   
        }));
        set("max_force", 12000);
        set("force", 12000);
        set("max_mana",8000);
        set("mana",8000);
        set("mana_factor",300);
        set("force_factor", 300);
        set("max_gin", 1500);
        set("max_kee", 1500);
        set("max_sen", 1500);

        setup();
          carry_object("/d/9ct/zb/yjl")->wear();
              add_money("silver", 30); 
           carry_object("/d/9ct/zb/lingzhu")->wear();
           carry_object("/d/9ct/zb/baowu");
// carry_object("/d/9ct/obj/cao");
}
void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("$N��Цһ��������$N������ˣʲô������\n",me);
        return 1;
} 
void check()
{
        object ob=this_object();
        object ghost;
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
        message_vision(HIY"$N��ָ$n��$N��ָ��ͻȻ����һ���׹⣡\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"�׹�֮��$N�е������ޱȵ���ʹ��\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
          }
        else
        message_vision(HIW"$N���޾�ɫ��һ��ת���㿪�˰׹⡣\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$Nһ�����ڣ�һֻ�������$n��ȥ��\n",ob,me);

        if(random(2)==0)
                {
message_vision(HIM"$N�������һ��ҧ����Ҫ����\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIG"$N����������ϸһ����ԭ��ֻ�ǻ���\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIW"$N˫�ֺ�ʮ������˫�ۣ�$n��ʱ�Ի�������\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIM"$N�о�������������ӽ��±����ߣ�\n"NOR,me);
              me->add("eff_kee",-3*query("max_kee")/10);
              me->add("eff_sen",-3*query("max_sen")/10);
                }
        else
        message_vision(HIG"$Nվ�ȽŸ��������ںʹ�ز�����\n"NOR,me);
        }
        break;
                    

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}


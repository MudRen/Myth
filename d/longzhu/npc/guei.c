// ������ by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIW"������"NOR, ({"gui xianren","gui","xianren","shen","ren"}));
        set("title", HIG"���ɵ�"HIC"����");
        set("gender", "����" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","��������һ����ɫ����,ɱ�������ء�\n");

        set("attitude", "aggressive");

  set("combat_exp", 10000000);
  set("daoxing", 100000000);

  set_skill("literate", 300);
  set_skill("unarmed", 300);
  set_skill("force", 300);
  set_skill("lengquan-force", 300);
        set_skill("dengxian-dafa", 300);
     set_skill("gouhunshu", 300);
//  set_skill("meihua", 300);
  set_skill("whip", 300);
  set_skill("bawang-qiang", 300);
  set_skill("axe", 300);
  set_skill("dodge", 300);
  set_skill("parry", 300);
  set_skill("sanban-axe", 300);
  set_skill("bawang-qiang", 300);
  set_skill("spells", 300);
  set_skill("baguazhou", 300);
  set_skill("spear", 300);
  set_skill("yanxing-steps", 300);
  map_skill("force", "lengquan-force");
  map_skill("spells", "gouhunshu");
        map_skill("spells", "dengxian-dafa");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");
  map_skill("whip", "bawang-qiang");

  set("max_sen", 10000);
  set("max_kee", 10000);
  set("force", 12000); 
  set("max_force", 12000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               (: perform_action, "spear.meihua" :),
                (: perform_action, "axe.sanban" :),
                (: perform_action, "axe.kai" :),
                (: exert_function, "jingxin" :),
                (: cast_spell, "gouhun" :),
                (: cast_spell, "inferno" :),
//                (: cast_spell, "tuntian" :),
//                (: cast_spell, "jieti" :),
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  setup();
        carry_object("/d/quest/longzhu/obj/1");
        carry_object("/d/quest/longzhu/weapon/spear")->wield();
//  carry_object("/d/longzhu/armor/gueijia")->wear();
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="1" || inv[i]->query("id")=="bai longzhu")
                {
                   inv[i]->move(me);
                   message_vision("$N����һö����ɫ�����ӣ�$n��æһ��ץ�����\n",this_object(),me);
            message("channel:rumor",HIG+"��"HIW"���鴫˵"HIG"��"HIC"�����"HIW"��"+me->query("name")+"�ڰ����������Ĺ��ɵ��ϵõ��˰����顣\n"+NOR,users());
         }
        }
  }
 ::die();
}


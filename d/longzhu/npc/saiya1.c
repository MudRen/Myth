// �������� by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({"sai ya","sai","ya"}));
        set("gender", "����" );
        set("age", 16);
set("long","����һλδ֪���ࡣ\n");
       set("max_kee", 10000);
       set("max_gin", 1000);
       set("max_sen", 10000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 1000);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 1000);
       set("daoxing", 100000000);
       set("combat_exp", 100000000);

        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set_skill("spells", 1000);  
        setup();
        carry_object("/d/quest/longzhu/obj/6");
        carry_object("/d/quest/longzhu/armor/skirt")->wear();
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
                if (inv[i]->query("id")=="6" || inv[i]->query("id")=="qing longzhu")
                {
                   inv[i]->move(me);

                   message_vision("$N����һö����ɫ�����ӣ�$n��æһ��ץ�����\n",this_object(),me);
            message("channel:rumor",HIG+"��"HIW"���鴫˵"HIG"��"HIC"�����"HIW"����˵"+me->query("name")+"���������򸽽��õ���"HIG"������"HIW"��\n"+NOR,users());
         }
        }
  }
 ::die();
}


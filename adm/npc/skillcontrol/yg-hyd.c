//stey
inherit NPC;
#include <command.h>

void create() { seteuid(getuid());}




void set_skills(int level,object me)
{

         int i = 50;
         object weapon;

        me->create_family("���ƶ�", 2, "����");
        me->set_skill("unarmed", level+random(i));
        me->set_skill("dodge", level+random(i));
        me->set_skill("parry", level+random(i));
        me->set_skill("force", level+random(i));
        me->set_skill("spells", level+random(i));

        me->set_skill("spear", level+random(i));
        me->set_skill("huoyun-qiang", level+random(i));
        me->set_skill("moyun-shou",level+random(i));
        me->set_skill("moshenbu",level+random(i));
        me->set_skill("huomoforce", level+random(i));
        me->set_skill("pingtian-dafa", level+random(i));
        me->set_skill("dali-bang", level+random(i));
        me->set_skill("stick", level+random(i));

        me->map_skill("force", "huomoforce");
        me->map_skill("spear", "huoyun-qiang");
        me->map_skill("stick","dali-bang");
        me->map_skill("parry", "dali-bang");
        me->map_skill("spells", "pingtian-dafa");
        me->map_skill("dodge", "moshenbu");
        me->map_skill("unarmed", "moyun-shou");

        me->set("chat_chance_combat", 10);
        me->set("chat_msg_combat", ({
        (: cast_spell, "sanmei" :),
        (: perform_action,"spear", "huohun" :),
        (: perform_action,"spear", "lihuo" :),
        (: perform_action,"unarmed", "zhangxinlei" :),
        }) );

        weapon=new("/d/obj/weapon/spear/jinqiang");
        weapon->move(me);
        me->command("wield all");
        me->carry_object("/d/obj/armor/jinjia.c")->wear();
}



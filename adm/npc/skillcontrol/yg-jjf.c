//stey
inherit NPC;
#include <command.h>

void create() { seteuid(getuid());}




void set_skills(int level,object me)
{

         int i = 50;
         object weapon;

        me->create_family("������", 2, "����");
        me->set_skill("unarmed", level+random(i));
        me->set_skill("dodge", level+random(i));
        me->set_skill("parry", level+random(i));
        me->set_skill("force", level+random(i));
        me->set_skill("spells", level+random(i));

        me->set_skill("spear", level+random(i));
        me->set_skill("bawang-qiang", level+random(i));
        me->set_skill("axe",level+random(i));
        me->set_skill("sanban-axe",level+random(i));
        me->set_skill("yanxing-steps",level+random(i));
        me->set_skill("changquan", level+random(i));
        me->set_skill("lengquan-force", level+random(i));
        me->set_skill("baguazhou", level+random(i));

        me->map_skill("force", "lengquan-force");
        me->map_skill("axe", "sanban-axe");
        me->map_skill("spear","bawang-qiang");
        me->map_skill("parry", "bawang-qiang");
        me->map_skill("spells", "baguazhou");
        me->map_skill("dodge", "yanxing-steps");
        me->map_skill("unarmed", "changquan");

        me->set("chat_chance_combat", 20);
        me->set("chat_msg_combat", ({
        (: exert_function, "powerup" :),
        (: perform_action,"axe", "sanban" :),
        (: perform_action,"axe", "kai" :),
        (: perform_action,"unarmed", "zhiqi" :),
        }) );

        weapon=new("/d/obj/weapon/axe/huafu");
        weapon->move(me);

        me->command("wield all");
        me->carry_object("/d/obj/armor/jinjia.c")->wear();
}


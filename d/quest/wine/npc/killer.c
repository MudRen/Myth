#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
#include "killer.h"
int do_back(object me);

void create()
{
        set_name("�ӱ�", ({ "tao bing","bing"}));
        set("gender", "����");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("long", "һ����������ļһ\n");
        set("combat_exp", 8300000 + random(1000000)); 
        set("daoxing", 8300000 + random(1000000)); 
        set("attitude", "friendly");
        set_skill("force", 500);
        set_skill("spear", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("unarmed", 500);
        set_skill("changquan", 500);
        set_skill("bawang-qiang", 500); 
        set_skill("spells", 500);
        set_skill("yanxing-steps", 500);
        set_skill("lengquan-force", 500);
        set_skill("baguazhou", 500);
        map_skill("dodge", "yanxing-steps");
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("spells", "baguazhou");
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        set("chat_chance", 40);
            set("chat_msg", ({
                    (: random_move :)
                }));
        set("max_kee", 4500); 
        set("kee", 4500); 
        set("max_sen", 4000); 
        set("sen", 4000); 
        set("force", 7000); 
        set("max_force", 7000);
        set("mana", 7000); 
        set("max_mana", 7000); 
        set("force_factor", 300);
       set("mana_factor", 300);
                setup();
        carry_object("/d/obj/weapon/spear/jinqiang")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}

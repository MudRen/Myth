#include <ansi.h>
inherit NPC;
int do_copy(object me,int flag);
int do_back(object me);
#include "killer.h"

void create()
{
        set_name("�ӱ�", ({ "tao bing","bing"}));
        set("gender", "Ů��");
        set("age", 36);
        set("attitude", "peaceful");
        set("str", 28);
        set("int", 20);
        set("con", 25);
        
        set("max_kee", 3500);
       set("kee", 3500);
        set("max_sen", 3500);
       set("sen", 3500);
        set("force", 4800);
        set("max_force", 4800);
       set("mana", 4800);
       set("max_mana", 4800);
        set("force_factor", 100);
       set("mana_factor", 100);
        set("combat_exp", 7000000); 
       set("daoxing", 7000000); 
       create_family("�¹�", 2, "��Ů");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword","hanyue" :),
         })); 
        set("chat_chance", 50);  
        set("chat_msg", ({
                    (: random_move :)
                }));
         set_skill("force", 400);
         set_skill("moonforce", 440);
         set_skill("dodge", 320 + random(30)); 
        set_skill("moondance", 340);
        set_skill("unarmed", 320 + random(30));
        set_skill("baihua-zhang", 320 + random(30));
        set_skill("parry", 440);
        set_skill("literate", 280);
        set_skill("sword", 380);
        set_skill("snowsword", 400);
        set_skill("spells", 380);
        set_skill("moonshentong", 380);
        map_skill("force", "moonforce");
        map_skill("dodge", "moondance");
        map_skill("unarmed", "baihua-zhang");
         map_skill("parry", "snowsword");
        map_skill("spells", "moonshentong");
        map_skill("sword", "snowsword");
 
        setup(); 
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/shoes")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

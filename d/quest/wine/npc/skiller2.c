#include <ansi.h>
inherit NPC;
int do_copy(object me,int flag);
int do_back(object me);
#include "killer.h"

void create()
{
        set_name("�ӱ�", ({ "tao bing","bing"}));
        set("gender", "����");
        set("age", 56);
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 20);
      set("con", 35);   
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 3000);
        set("max_force", 3000);
       set("mana", 3000);
       set("max_mana", 3000);
        set("force_factor", 120);
       set("mana_factor", 120);
        set("combat_exp", 6000000); 
       set("daoxing", 6000000); 
       create_family("��������", 3, "��ͽ");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed","sheshen" :),
         })); 
        set("chat_chance", 50);  
        set("chat_msg", ({
                    (: random_move :)
                }));
         set_skill("force", 380);
         set_skill("dragonforce", 380);
         set_skill("dodge", 380);
         set_skill("dragonstep", 380);
         set_skill("unarmed", 380);
         set_skill("dragonfight", 350);
         set_skill("parry", 370);
         set_skill("literate", 150);
         set_skill("spells", 370);
         set_skill("seashentong", 350);
    
        map_skill("force", "dragonforce");
        map_skill("dodge", "dragonstep");
        map_skill("unarmed", "dragonfight");
        map_skill("spells", "seashentong"); 
        setup(); 
        carry_object("/d/obj/cloth/linen")->wear();
}

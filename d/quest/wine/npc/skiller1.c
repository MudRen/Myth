#include <ansi.h> 
inherit NPC;
int do_copy(object me,int flag);
int do_back(object me);
#include "killer.h"

void create()
{
        set_name("�ӱ�", ({ "tao bing","bing"}));
        set("gender", "����");
        set("age", 66);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 25); 
        set("max_kee", 3500);
       set("kee", 3500);
        set("max_sen", 3500);
       set("sen", 3500);
        set("force", 4500);
        set("max_force", 4500);
       set("mana", 4500);
       set("max_mana", 4500);
       set("force_factor", 100);
       set("mana_factor", 100);
        set("combat_exp", 5000000);
       set("daoxing", 5000000);
        create_family("��ׯ��", 2, "��ʿ");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword","jianmang" :),
                (: perform_action, "sword","jianzhang" :),
         }));
        set("chat_chance", 50);  
        set("chat_msg", ({
                    (: random_move :)
                }));
         set_skill("force", 380);
         set_skill("wuxing-quan", 300);
         set_skill("dodge", 280);
         set_skill("sanqing-jian", 380);
         set_skill("parry", 380);
        set_skill("baguazhen", 280);
        set_skill("spells", 300);
        set_skill("zhenyuan-force", 380);
        set_skill("literate", 200);
        set_skill("sword", 300);
        set_skill("unarmed", 290);
        set_skill("taiyi", 300);

        map_skill("force", "zhenyuan-force");
        map_skill("dodge", "baguazhen");
        map_skill("unarmed", "wuxing-quan");
        map_skill("sword", "sanqing-jian");
        map_skill("parry", "sanqing-jian");
        map_skill("spells", "taiyi");

        setup(); 
        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield(); 
}

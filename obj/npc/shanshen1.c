//��[����֮��[ɽ��
//Created by wuyou@sk_sjsj
//2003-8-13
 
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIC"����ɽ��"NOR, ({"shan shen", "shen"}));
        set("age", 300);
        set("long", "�|�[̩ɽ֮ɽ��\n");
        set("str", 100);
        set("cor", 40);
        set("con", 40);
        set("cps", 40);
        set("spi", 40);
        set("int", 40);
        set_temp("apply/damage", 150);
        set_temp("apply/armor", 800);
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 200);
        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 200);
        set_skill("unarmed", 350+random(50));
        set_skill("parry", 350+random(50));
        set_skill("wuyue-spear", 350+random(50));
        set_skill("dodge", 350+random(50));
        set_skill("spear", 350+random(50));
        set_skill("moshenbu", 350);
        map_skill("spear", "wuyue-spear");
        map_skill("parry", "wuyue-spear");
        map_skill("dodge", "moshenbu");
        
        set("combat_exp", 15000000);
        set_weight(500000);
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/obj/weapon/spear/huaji2")->wield();
        
        
        
}


